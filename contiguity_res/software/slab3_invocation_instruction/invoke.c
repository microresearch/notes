/*
 * enstix.c
 * (c) 2015 flabbergast
 *  main firmware logic
 */

#include "LufaLayer.h"
//#include "SerialHelpers.h"
#include "invoke.h"
//#include <avr/time.h>
//#include "crypto/crypto.h"
//#include "crypto/sha256.h"

//#include "sd_raw/sd_raw.h"

//#include "apipage.h"

#include <avr/eeprom.h>
//#include "eeprom_contents.c"

#include <string.h>

#include "RTC.h"


/*************************************************************************
 * ----------------------- Global variables -----------------------------*
 *************************************************************************/

#define HASH_ITERATIONS 1000

/*  Encryption related: used both in main() and disk read/write callbacks. */
#define PASSPHRASE_MAX_LEN 100
char passphrase[PASSPHRASE_MAX_LEN];
char temp_buf[PASSPHRASE_MAX_LEN];
uint8_t pp_hash[32];
uint8_t pp_hash_hash[32];
uint8_t key[16];
#if defined(__AVR_ATxmega128A3U__) || defined(__AVR_ATxmega128A4U__)
uint8_t lastsubkey[16]; // hardware AES module needs a different key for decryption
#endif
uint8_t key_hash[32];
uint8_t iv[16];
#if defined(USE_SDCARD)
uint8_t sd_exists = 0;
struct sd_raw_info sd_card_info;
#endif

/*************************************************************************
 * ----------------------- Helper functions -----------------------------*
 *************************************************************************/
void print_help(void);
void print_header(void);
#if defined(USE_SDCARD)
void print_sd_card_info(void);
#endif
void compute_iv_for_sector(uint32_t sectorNumber);
void compute_many_hashes(const void *source, uint8_t count, uint8_t *hash);

#if defined(__AVR_ATxmega128A3U__) || defined(__AVR_ATxmega128A4U__)
#define DISABLE_JTAG CPU_CCP = CCP_IOREG_gc; MCU.MCUCR = MCU_JTAGD_bm
void setClockTo32MHz(void);
void setClockTo32MHz() {
    CCP = CCP_IOREG_gc;              // disable register security for oscillator update
    OSC.CTRL = OSC_RC32MEN_bm;       // enable 32MHz oscillator
    while(!(OSC.STATUS & OSC_RC32MRDY_bm)); // wait for oscillator to be ready
    CCP = CCP_IOREG_gc;              // disable register security for clock update
    CLK.CTRL = CLK_SCLKSEL_RC32M_gc; // switch to 32MHz clock
}
#endif

/*************************************************************************
 * ------------------------- Main Program -------------------------------*
 *************************************************************************/

int main(void)
{
  /* Variables */
  bool button_press_registered = false;
  uint32_t button_press_length = 0;

  
  // should set the disk size soon
  disk_size_GLOBAL = VIRTUALFAT_DISK_BLOCKS;

  bool dtr,prev_dtr = false;

  /* disable JTAG on XMEGAs */
#if defined(__AVR_ATxmega128A3U__)
    DISABLE_JTAG;
#endif
#if defined(__AVR_ATxmega128A4U__)
    setClockTo32MHz();
#endif

  /* Initialisation */
  init();

  TWI_Init(TWI_BIT_PRESCALE_4, TWI_BITLENGTH_FROM_FREQ(4, 50000));
  RTC_Init();

  
#if defined(USE_SDCARD)
  if( sd_raw_init() && sd_raw_get_info(&sd_card_info) ) {
    sd_exists = 1;
  }
#endif

  /* read the eeprom data into SRAM */
  //  eeprom_read_block((void*)key, (const void*)aes_key_encrypted, 16); // it's still encrypted at this point

  /* Must throw away unused bytes from the host, or it will lock up while waiting for the device */
  //  usb_serial_flush_input();

  /* Main loop.*/
  for (;;)
  {

    /* need to run this relatively often to keep the USB connection alive */
    usb_tasks();
  }
}

/*************************************************************************
 * ------------------- CALLBACKS to be implemented ----------------------*
 *************************************************************************/

/* Compute some constants */
#define DISK_AREA_BEGIN_PAGE              (DISK_AREA_BEGIN_BYTE/BOOT_SECTION_PAGE_SIZE)
#ifndef PROGMEM_PAGECOUNT
  #define PROGMEM_PAGECOUNT               (PROGMEM_SIZE/BOOT_SECTION_PAGE_SIZE)
#endif
#define MEM_PAGES_PER_DISK_BLOCK          (DISK_BLOCK_SIZE/BOOT_SECTION_PAGE_SIZE)
// this should be 1 on atxmega128a3u

int16_t CALLBACK_disk_readSector(uint8_t out_sectordata[DISK_BLOCK_SIZE], const uint32_t sectorNumber) {
  /* compute iv */
  compute_iv_for_sector(sectorNumber);

#if defined(USE_SDCARD)
  if(sd_exists) {
    sd_raw_read_block(sectorNumber, out_sectordata);
  } else {
    return 0;
  }
#else
  #if (defined(__AVR_ATxmega128A3U__))
  /* read the data */
  memcpy_PF(out_sectordata, (uint_farptr_t)DISK_AREA_BEGIN_BYTE+(uint_farptr_t)(sectorNumber*DISK_BLOCK_SIZE), DISK_BLOCK_SIZE);
  //flash_readpage(out_sectordata, DISK_AREA_BEGIN_PAGE+sectorNumber);
  #else // need to do something else if not on x128a3u
  memset(&out_sectordata[0], ~(sectorNumber & 0xff), DISK_BLOCK_SIZE);
  #endif
#endif

  /* decrypt */
#if defined(__AVR_ATxmega128A3U__) || defined(__AVR_ATxmega128A4U__)
    // hardware AES module needs a different key for decryption
  //    aes128_cbc_dec(lastsubkey, iv, out_sectordata, DISK_BLOCK_SIZE);
#else
    //    aes128_cbc_dec(key, iv, out_sectordata, DISK_BLOCK_SIZE);
#endif

  return DISK_BLOCK_SIZE;
}

int16_t CALLBACK_disk_writeSector(uint8_t in_sectordata[DISK_BLOCK_SIZE], const uint32_t sectorNumber) {
  /* compute iv */
  compute_iv_for_sector(sectorNumber);

  /* encrypt the data */
  //  aes128_cbc_enc(key, iv, in_sectordata, DISK_BLOCK_SIZE);

#if defined(USE_SDCARD)
  if(sd_exists) {
    sd_raw_write_block(sectorNumber, in_sectordata);
  } else {
    return 0;
  }
#else
  #if (defined(__AVR_ATxmega128A3U__)) // this can only happen on x128a3u
  if(__checkmagic()==0) { // do not run the code if not on Stephan Baerwolf's hardware/bootloader
    return 0;
  }
  /* write the data to flash */
  // figure out how many memory pages we need to write
  uint_farptr_t write_to_page = DISK_AREA_BEGIN_PAGE + (sectorNumber * MEM_PAGES_PER_DISK_BLOCK);
  // check that we're not going into the bootloader area
  if(write_to_page+MEM_PAGES_PER_DISK_BLOCK <= PROGMEM_PAGECOUNT-__reportBLSpagesize())
    for(uint8_t i=0; i<MEM_PAGES_PER_DISK_BLOCK; i++)
      flash_writepage(in_sectordata+(BOOT_SECTION_PAGE_SIZE*i), write_to_page+i);
  #else
  return 0;
  #endif
#endif

  return DISK_BLOCK_SIZE;
}

/*************************************************************************
 * ----------------- Helper functions implementation --------------------*
 *************************************************************************/

// uses global variables: iv, key_hash. Assumes key_hash has the hash of the key in it :)
void compute_iv_for_sector(uint32_t sectorNumber) {
  /* compute iv for the sector */
  // prepare for encrypting sector number (endianness matters!)
  memset(iv, 0, 16);
  memcpy(iv, (const void*)&sectorNumber, sizeof(uint32_t));
  // encrypt the sn with aes128, the key being the hash of the main key
  //  aes128_enc_single(key_hash, iv);
}

void print_help(void) {
  usb_serial_writeln_P(PSTR("-> Help: [i]nfo | [r]o/rw | enter [p]assphrase | [c]hange passphrase"));
}

void print_header(void) {
  usb_serial_writeln_P(FIRMWARE_VERSION);
}

void compute_many_hashes(const void *source, uint8_t count, uint8_t *hash) {
  uint8_t temp_hash[32];
  uint8_t *cur_src;
  uint8_t *cur_dst;
  uint8_t *swap_ptr;

  //  sha256((sha256_hash_t *)hash, source, 8*count);
  cur_src = hash;
  cur_dst = temp_hash;
  for(uint16_t j=1; j<HASH_ITERATIONS; j++) { // going to repeatedly hash
    //    sha256((sha256_hash_t *)cur_dst, (const void*)cur_src, 8*32);
    swap_ptr = cur_src; cur_src = cur_dst; cur_dst = swap_ptr; // switch src/dest (pp_hash vs temp_hash)
  }
  if( HASH_ITERATIONS % 2 == 0 )
    memcpy(hash, temp_hash, 32);
}

#if defined(USE_SDCARD)
void print_sd_card_info() {
  usb_serial_write_P(PSTR("manuf:    0x")); hexprint(&sd_card_info.manufacturer,1);
  usb_serial_write_P(PSTR("oem:      ")); usb_serial_writeln((char*) sd_card_info.oem);
  usb_serial_write_P(PSTR("product:  ")); usb_serial_writeln((char*) sd_card_info.product);
  usb_serial_write_P(PSTR("revis:    ")); hexprint(&sd_card_info.revision,1);
  usb_serial_write_P(PSTR("serial:   0x")); hexprint((uint8_t*)(&sd_card_info.serial),1);
  usb_serial_write_P(PSTR("date mfd: ")); usb_serial_write_dec8(sd_card_info.manufacturing_month);
                                          usb_serial_putchar('/');
                                          usb_serial_writeln_dec8(sd_card_info.manufacturing_year);
  usb_serial_write_P(PSTR("size:     ")); usb_serial_write_dec32(sd_card_info.capacity / 1024 / 1024);
                                          usb_serial_writeln_P(PSTR("MB"));
  usb_serial_write_P(PSTR("content:  ")); (sd_card_info.flag_copy ?
                                           usb_serial_writeln_P(PSTR("original")) :
                                           usb_serial_writeln_P(PSTR("copy")));
  usb_serial_write_P(PSTR("writable: ")); (sd_card_info.flag_write_protect ?
                                           usb_serial_write_P(PSTR("no")) :
                                           usb_serial_write_P(PSTR("yes")) );
  usb_serial_write_P(PSTR(" temp: ")); (sd_card_info.flag_write_protect_temp ?
                                        usb_serial_writeln_P(PSTR("no")) :
                                        usb_serial_writeln_P(PSTR("yes")) );
}
#endif
