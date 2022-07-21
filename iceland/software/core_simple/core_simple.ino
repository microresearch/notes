// now with 10 ohm bypass seems to work fine - not anymore now???
// 001 is flip/flip/no flip

// 21/7/2021
/*
testing with scope:
- can see flips on scope but timing is a bit odd of reading pulses
- operates with bypassed resistors (q of cores)...

- direction of cores x against y makes difference
- now we read 011 which doesn't make sense

- we checked scope and pulse comes a bit later so adjusted timing to:

  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t"); 
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\t");

and we have 001 and seems to work (010=write/write/read = flip, no flip, flip)

 */

/*

Once I put all the pieces together, I engaged the Arduino's Serial Monitor window (set the baud rate to 19200), and the console began to repeatedly display the string "RD: 001" which shows that the first two pulses flipped the core and the third pulse did not, which is how the circuit should work.  Success!

https://sites.google.com/site/wayneholder/one-bit-ferrite-core-memory

 */

#define  PULSE  6 
#define  DELAY  10

#define  EN    0x04 // en x0/y0 D2
#define  SYNC  0x80 // unused
#define  WR    0x28 // D3 and D5
#define  RD    0x50 // D4 and D6

void setup() {
  Serial.begin(19200);
  DDRD = DDRD | 0xFC;  // D2-D7 are outputs
  DDRB = DDRB | 0xFE;  // D8 is input
}

void sDelay (byte cnt) {
  for (byte ii = 0; ii < cnt; ii++) {
    __asm__ ("nop\n\t");    // NOP delays 62.5 ns
    __asm__ ("nop\n\t");
  }
}

byte pulse (byte lines) {
  PORTD = (lines + EN);
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t"); 
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\t");
  // now above timing we have 001
  //   __asm__ ("nop\n\t");
  
    //    delay(2000); // testu

  // sample sense amp output after ~1,200 ns delay - above is how we had it before...
  byte smpl = PINB & 0x01;
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");  // 
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");  // 
    PORTD = 0x00;
    sDelay(DELAY);
  return smpl;
}

void loop() {
  byte test = 0;
  Serial.println("RD: ");
  test = pulse(WR + SYNC);
  Serial.print(test, DEC);
  test = pulse(RD); 
  Serial.print(test, DEC);
  test = pulse(RD);
  Serial.print(test, DEC);
    delay(1000);
 
}