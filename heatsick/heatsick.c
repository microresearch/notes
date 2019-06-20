/* heatsick:

- playback of all memory/registers while AVR (on SIR board) is subjected to heat in 5s steps.
- 0x0000->0x08FF

but for gcc:
the variable would have to be within the range from 0x00800000 and 0x008003FF. 1kb ram

- and while we do some encryption/decruption operation

- so playback runs in interrupt

 */

#define F_CPU 16000000UL 

#include <stdio.h>
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

unsigned long *addr_ptr=(long *)0x00800000;
int counter=0;

ISR(TIMER1_OVF_vect) {
  //    OCR1A = pcm_samples[sample++];
  if (counter==1024) counter=0;
  OCR0A=*(addr_ptr+counter++);
}

void init(void) {
  // for erd sire
  
   DDRD=0x40; // 6 as out
   cli();//stop interrupts
   TCCR0A=(1<<COM0A1) | (1<<WGM01) | (1<<WGM00); // fast PWM
   TCCR0B=(1<<CS00);// no prescaling WAS ---> | (1<<CS01);  // divide by 64 for 1KHz

  

    TIMSK1 = (1<<TOIE1); // Interrupt on overflow
    // Timer ticks at 1us, samples every 125us, so overflow every 125us
    ICR1 = 0x7D; // Overflow at 125
    sei();
}

int main(void) {
    init();
    while (1);
}
