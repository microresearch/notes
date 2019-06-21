/* heatsick:

- for SIR with out on pd6

 */

#define F_CPU 16000000UL 

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

typedef int u16;
typedef unsigned char u8;

#define BV(bit) (1<<(bit)) // Byte Value => converts bit into a byte value. One at bit location.
#define cbi(reg, bit) reg &= ~(BV(bit)) // Clears the corresponding bit in register reg
#define sbi(reg, bit) reg |= (BV(bit))              // Sets the corresponding bit in register reg
#define HEX__(n) 0x##n##UL

#define FS    64000                        // sample rate


unsigned long *addr_ptr=(unsigned long *)0x00800000;
int counter=0;
uint8_t *hash;

#define HASH_LENGTH 32
#define BLOCK_LENGTH 64

union Buffer {
  uint8_t b[BLOCK_LENGTH];
  uint32_t w[BLOCK_LENGTH / 4];
};

union State {
  uint8_t b[HASH_LENGTH];
  uint32_t w[HASH_LENGTH / 4];
};

State state;
Buffer buffer;


void init(void);
void initHmac(const uint8_t *key, size_t keyLength);
void initHmac_EEPROM(const uint8_t *key, size_t keyLength);

// Reset to initial state, but preserve key material.
void reset(void);

uint8_t* result(void);
uint8_t* resultHmac(void);
void write(uint8_t);
void hashBlock();
void padBlock();
void push(uint8_t data);

uint32_t byteCount;

uint8_t keyBuffer[BLOCK_LENGTH];
uint8_t innerHash[HASH_LENGTH];

uint8_t bufferOffset;

/*
uint8_t  sine_wave[256] = {
  0x80, 0x83, 0x86, 0x89, 0x8C, 0x90, 0x93, 0x96,
  0x99, 0x9C, 0x9F, 0xA2, 0xA5, 0xA8, 0xAB, 0xAE,
  0xB1, 0xB3, 0xB6, 0xB9, 0xBC, 0xBF, 0xC1, 0xC4,
  0xC7, 0xC9, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD8,
  0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6, 0xE8,
  0xEA, 0xEB, 0xED, 0xEF, 0xF0, 0xF1, 0xF3, 0xF4,
  0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC,
  0xFD, 0xFD, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD,
  0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xF9, 0xF8, 0xF6,
  0xF5, 0xF4, 0xF3, 0xF1, 0xF0, 0xEF, 0xED, 0xEB,
  0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE, 0xDC,
  0xDA, 0xD8, 0xD5, 0xD3, 0xD1, 0xCE, 0xCC, 0xC9,
  0xC7, 0xC4, 0xC1, 0xBF, 0xBC, 0xB9, 0xB6, 0xB3,
  0xB1, 0xAE, 0xAB, 0xA8, 0xA5, 0xA2, 0x9F, 0x9C,
  0x99, 0x96, 0x93, 0x90, 0x8C, 0x89, 0x86, 0x83,
  0x80, 0x7D, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x6A,
  0x67, 0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x52,
  0x4F, 0x4D, 0x4A, 0x47, 0x44, 0x41, 0x3F, 0x3C,
  0x39, 0x37, 0x34, 0x32, 0x2F, 0x2D, 0x2B, 0x28,
  0x26, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x18,
  0x16, 0x15, 0x13, 0x11, 0x10, 0x0F, 0x0D, 0x0C,
  0x0B, 0x0A, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04,
  0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03,
  0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x0A,
  0x0B, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x13, 0x15,
  0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24,
  0x26, 0x28, 0x2B, 0x2D, 0x2F, 0x32, 0x34, 0x37,
  0x39, 0x3C, 0x3F, 0x41, 0x44, 0x47, 0x4A, 0x4D,
  0x4F, 0x52, 0x55, 0x58, 0x5B, 0x5E, 0x61, 0x64,
  0x67, 0x6A, 0x6D, 0x70, 0x74, 0x77, 0x7A, 0x7D
};
*/

u8 bitcount=0;
u8 byyte=0;


ISR(TIMER1_COMPA_vect) {

    // try accumulate bits so each memory is a bit...
  /*
  if (counter==1024) counter=0; // was 1024
  u8 c=*(addr_ptr+counter++);
  if (c>127) PORTD=1; else PORTD=0;
  */
  if (counter==17) counter=0; // was 1024
  u8 c=hash[counter++];
  if (c>127) PORTD=255; else PORTD=0; // PD6
  
    
  /*
  if (c<127) byyte+=(1<<(bitcount));
  bitcount++;
  if (bitcount==8){
    OCR0A=byyte;
    byyte=0;
    bitcount=0;
  }
  */
  
  //  OCR0A=*(addr_ptr+counter++);
  sei();
}


//int xx[1024];
int x;


//void init(void) {
void inisetup() {
  
   DDRD=0xff; // 6 as out and 1 too!
   cli();//stop interrupts
   //   TCCR0A=(1<<COM0A1) | (1<<WGM01) | (1<<WGM00); // fast PWM
   //      TCCR0A=(1<<WGM01) | (1<<WGM00); // fast PWM
   //   TCCR0B=(1<<CS00);// no prescaling WAS ---> | (1<<CS01);  // divide by 64 for 1KHz

   // Timer 1 set up as a 8000Hz sample interrupt
   TCCR1A = 0;
   TCCR1B = _BV(WGM12) | _BV(CS10);
   TCNT1 = 0;
   OCR1A = F_CPU / FS;
   TIMSK1 = _BV(OCIE1A);


   /*  for (x=0;x<1024;x++){
      xx[x]=x;//rand()%255;
      }*/



    sei();

}

const uint32_t SHA256_K[] PROGMEM = {
  0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
  0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
  0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
  0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
  0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
  0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
  0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
  0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

const uint8_t SHA256_INIT_STATE[] PROGMEM = {
  0x67,0xe6,0x09,0x6a, // H0
  0x85,0xae,0x67,0xbb, // H1
  0x72,0xf3,0x6e,0x3c, // H2
  0x3a,0xf5,0x4f,0xa5, // H3
  0x7f,0x52,0x0e,0x51, // H4
  0x8c,0x68,0x05,0x9b, // H5
  0xab,0xd9,0x83,0x1f, // H6
  0x19,0xcd,0xe0,0x5b  // H7
};

#define ror32(num, bits) ((num << (32 - bits)) | (num >> bits))

void init(void) {
  memcpy_P(state.b, SHA256_INIT_STATE, 32);
  byteCount = 0;
  bufferOffset = 0;
}

void hashBlock() {
  uint8_t i;
  uint32_t a,b,c,d,e,f,g,h,t1,t2;

  a=state.w[0];
  b=state.w[1];
  c=state.w[2];
  d=state.w[3];
  e=state.w[4];
  f=state.w[5];
  g=state.w[6];
  h=state.w[7];

  for (i=0; i<64; i++) {
    if (i>=16) {
      t1 = buffer.w[i&15] + buffer.w[(i-7)&15];
      t2 = buffer.w[(i-2)&15];
      t1 += ror32(t2,17) ^ ror32(t2,19) ^ (t2>>10);
      t2 = buffer.w[(i-15)&15];
      t1 += ror32(t2,7) ^ ror32(t2,18) ^ (t2>>3);
      buffer.w[i&15] = t1;
    }
    t1 = h;
    t1 += ror32(e,6) ^ ror32(e,11) ^ ror32(e,25); // ∑1(e)
    t1 += g ^ (e & (g ^ f)); // Ch(e,f,g)
    t1 += pgm_read_dword(SHA256_K + i); // Ki
    t1 += buffer.w[i&15]; // Wi
    t2 = ror32(a,2) ^ ror32(a,13) ^ ror32(a,22); // ∑0(a)
    t2 += ((b & c) | (a & (b | c))); // Maj(a,b,c)
    h=g; g=f; f=e; e=d+t1; d=c; c=b; b=a; a=t1+t2;
  }
  state.w[0] += a;
  state.w[1] += b;
  state.w[2] += c;
  state.w[3] += d;
  state.w[4] += e;
  state.w[5] += f;
  state.w[6] += g;
  state.w[7] += h;
}

void push(uint8_t data) {
  buffer.b[bufferOffset ^ 3] = data;
  bufferOffset++;
  if (bufferOffset == BLOCK_LENGTH) {
    hashBlock();
    bufferOffset = 0;
  }
}

void write(uint8_t data) {
  ++byteCount;
  push(data);
  //  return 1;
}

void padBlock() {
  // Implement SHA-256 padding (fips180-2 §5.1.1)

  // Pad with 0x80 followed by 0x00 until the end of the block
  push(0x80);
  while (bufferOffset != 56) push(0x00);

  // Append length in the last 8 bytes. We're only using 32 bit lengths, but
  // SHA-2 supports 64 bit lengths so zero pad the top bits
  push(0);
  push(0);
  push(0);
  push(byteCount >> 29);
  push(byteCount >> 21);
  push(byteCount >> 13);
  push(byteCount >> 5);
  push(byteCount << 3);
}

uint8_t* result(void) {
  // Pad to complete the last block
  uint8_t i;
  padBlock();

  // Swap byte order back
  for (i = 0; i < 8; i++) {
    uint32_t a,b;
    a=state.w[i];
    b=a<<24;
    b|=(a<<8) & 0x00ff0000;
    b|=(a>>8) & 0x0000ff00;
    b|=a>>24;
    state.w[i]=b;
  }

  // Return pointer to hash
  return state.b;
}

#define HMAC_IPAD 0x36
#define HMAC_OPAD 0x5c

void initHmac(const uint8_t *key, size_t keyLength) {
  memset(keyBuffer, 0, BLOCK_LENGTH);
  if (keyLength > BLOCK_LENGTH) {
    // Hash long keys
    init();
    for (;keyLength--;) write(*key++);
    memcpy(keyBuffer, result(), HASH_LENGTH);
  } else {
    // Block length keys are used as is
    memcpy(keyBuffer, key, keyLength);
  }
  reset();
}

void initHmac_EEPROM(const uint8_t *key, size_t keyLength) {
  memset(keyBuffer, 0, BLOCK_LENGTH);
  if (keyLength > BLOCK_LENGTH) {
    // Hash long keys
    init();
    for (;keyLength--;) write(eeprom_read_byte(key++));
    memcpy(keyBuffer, result(), HASH_LENGTH);
  } else {
    // Block length keys are used as is
    eeprom_read_block(keyBuffer, key, keyLength);
  }
  reset();
}

uint8_t* resultHmac(void) {
  uint8_t i;
  // Complete inner hash
  memcpy(innerHash, result(), HASH_LENGTH);
  // Calculate outer hash
  init();
  for (i = 0; i < BLOCK_LENGTH; i++) write(keyBuffer[i] ^ HMAC_OPAD);
  for (i = 0; i < HASH_LENGTH; i++) write(innerHash[i]);
  return result();
}

void reset(void) {
  // Start inner hash
  uint8_t i;
  init();
  for (i = 0; i < BLOCK_LENGTH; i++) {
    write(keyBuffer[i] ^ HMAC_IPAD);
  }
}


//int main(void) {
  //    init();
int main() {
  u8 cc;
  inisetup();
  const char *c="testing123456789";
  //  Sha256.print("This is a message to hash");

  /*
size_t Print::print(const __FlashStringHelper *ifsh)
{
  PGM_P p = reinterpret_cast<PGM_P>(ifsh);
  size_t n = 0;
  while (1) {
    unsigned char c = pgm_read_byte(p++);
    if (c == 0) break;
    if (write(c)) n++;
    else break;
  }
  return n;
}
  */

     while(1){
       init();

     for (x=0;x<16;x++){
       cc=c[x];
       //cc=rand()%255;
       write(cc);
     }
     
     hash = result();
     }
     /*
   for (x=0;x<1024;x++){
     xx[x]^=1;//rand()%255;
	    }
     */
     
  //    while (1);
  //  for (x=0;x<1024;x++){
  //    xx[x]=xx[x]+1;
  //  }
     return 1;
     
}
