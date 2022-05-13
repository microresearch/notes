uint8_t earthcode[1024]; // we only have 2kb ram so we can't have 4096

/*
Refs for ROM and pinouts:

http://searle.hostei.com/grant/zx80/zx80.html

NAME - ARDUINO PIN

CS1  12
D0-7   0-7

VSS    GND

straight mapping  

bring out A0, 5V and GND - 3 wires for earthboot

earthcode from top:

SDA, SCL, 620_OUT->ADC, GND, VDDA (for 620 -3.3V or 5V depending on platform), 5V

 */


static __inline__ void      /* exactly 4 cycles/loop, max 2**8 loops */
_delay_loop_1_x( uint8_t __n )
{                                               /* cycles per loop      */
    __asm__ volatile (                          /* __n..one        zero */
        "1: dec  %0"   "\n\t"                   /*    1             1   */
        "   breq 2f"   "\n\t"                   /*    1             2   */
        "2: brne 1b"   "\n\t"                   /*    2             1   */
        : "=r" (__n)                            /*  -----         ----- */
        : "0" (__n)                             /*    4             4   */
    );
}



void setup()  { 

  pinMode(12, INPUT_PULLUP); // CS1 on ROM
  pinMode(13, INPUT_PULLUP); // CS2 on ROM - we don't seem to use
  pinMode(A0, INPUT);

  //    DDRD = B11111111;  
  //pinMode(2, OUTPUT);

  //  uint16_t x;
  //    for (x=0;x<1024;x++){
  //            earthcode[x] = analogRead(A0)&0xff;
      //      earthcode[x] = rand()%0xff;

  int x;
  while (x<1024){
  if (!(PINB & 0x10)) { // pin 12 which is on PORTB - CS on ROM
    DDRD = B11111111;  
    PORTD=(analogRead(A0)*rand()%255)&0xff;
    
      // turn off bus - 500  ns? - value of 2 or 3 seems to work
    _delay_loop_1_x(3);
    DDRD = B00000000;  
    PORTD=0x00;
    x++;
    }
  }
}

void loop()  { 
  int x;
  x=0;
  if (!(PINB & 0x10)) { // pin 12 which is on PORTB - CS on ROM
    DDRD = B11111111;  
    //    PORTD=analogRead(A0)&0xff;
    //        PORTD=rand()%255;
        PORTD=(analogRead(A0)*rand()%255)&0xff;
      // turn off bus - 500  ns? - value of 2 or 3 seems to work
    _delay_loop_1_x(3);
    DDRD = B00000000;  
    PORTD=0x00;
    if (x==1024) x=0;  
    }

  //    for (x=0;x<1024;x++){
  //            earthcode[x] = analogRead(A0)&0xff;
      //      earthcode[x] = rand()%0xff;
  }

  
  // test for scope
  /*  DDRD=B11111111;
  PORTD=255;
  _delay_loop_1_x(2); // this gives us 500nS
  //  delayMicroseconds(10);
  //  _delay_loop_1_x(1);
  //  DDRD = B00000000;  
  PORTD=0;
  delayMicroseconds(10);*/

