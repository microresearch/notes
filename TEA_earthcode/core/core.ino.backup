/*

TODO:

- re-check all pin assigns and logic-DONE
- re-test muon - 1 on Y never fires = 7th on top now but doesn't seem to have a problem with connections or?

- is it firing or - reversed connector on arduino and same problem on 6 so is likely tube//no change on replacement...
- fixed with new 74HC14! DONE

 ////WED 13/9 PM: muon all workings

- test cores with new code - basics of read and write:

no luck - 5v we have, logic PWR we have, sense is connected DONE - timing might need some tweaks

- put new core code in interrupt and finalise all - problems - retested muon code all good
- do core simulationDONE

- scanning of cores and serial outDONE

/////

- read and write single core function 

- parse incoming data for muon events

- flip bit of single core of x,y

- scan x, y status every x seconds and output this data via serial to PI

The test code shown below writes a repeating set of three pulses that
flip the core to the "1" state, then to the "0" state, then to the "0"
state again (which leaves the core in the "0" state for the next
series of pulses.)  To write a "1" to the core, the code sets D3 and
D5 high, D4 and D6 low and then pulses D2 for about 2 microseconds.
To write a "0" the code sets D3 and D5 low, D4 and D6 high and again
pulses D2.  Actually, the designation of one state, or the other as
the "1", or the "0" state is completely arbitrary.  The important idea
is that you select one state as the "1" state so you can test for
cores set to this state by forcing them to the opposite state and
watching for the kickback pulse.  It you see the pulse the bit was in
the "1" state.  if not, it was already in the "0" state.

so WR is HIX0 and HIY0 high - D3 and D5 on PORTD -> arduino Digital 0-7
RD is LOX0 and LOY0 high - D4 and D6 on PORTD

this is for test code: sense is on PORTB 8-13 - so pin 8

*/

// core mappings :https://lynx2015.files.wordpress.com/2015/08/arduino-mega-pinout-diagram.png
// port mappings
// with 0=A,1=B,2=C,3=D,4=E,5=G,6=H,7=L

//ENABLES: left hand - top to bottom X0-X7 Y0-Y7
byte enable_pins_x[8]={4,5,5,3, 3,4,5,6}; // E,E,G,E, H,H,H,H // digital pins 2-9
byte enable_port_x[8]={4,4,5,4, 6,6,6,6};
byte enable_pins_y[8]={4,5,6,7, 0,1,2,3}; // B,B,B,B, D,D,D,D // digital pins 10,11,12,13 comm 21,20,19,18
byte enable_port_y[8]={1,1,1,1, 3,3,3,3}; // checked!

// sense will be: say 14 = PJ1

// Arduino end double row connector - working from top left down:
// X: middle left to right HIX7-HIX0 LOX7-LOX0 - so reverse order of theseDONE
byte hi_x_pins[8]= {1,3,5,7,6,4,2,0};  // A,A,A,A, C,C,C,C // middle left to right HIX7-HIX0 on core board. top left on arduino - REV
byte hi_x_port[8]= {2,2,2,2, 0,0,0,0};//rev

byte low_x_pins[8]={1,3,1,3,5,7,1,7}; // D,G,L,L, L,L,B,B// LOX7-LOX0 rev
byte low_x_port[8]={1,1,7,7,7,7,5,3}; // checked! rev

//Y: lower left to right HIY7-HIY0 LOY7-LOY0
byte hi_y_pins[8]= {0,2,4,6,7,5,3,1}; // rev A,A,A,A, C,C,C,C// lower left to right HIY7-HIY0. top right down on arduino
byte hi_y_port[8]= {2,2,2,2, 0,0,0,0}; // rev

byte low_y_pins[8]={0,2,0,2,4,6,0,2}; // rev G,G,L,L, L,L,B,B // LOY7-LOY0
byte low_y_port[8]={1,1,7,7,7,7,5,5}; // rev checked



//#define  PULSE  6 
#define  DELAY  10

// this was pin testing code

//#define  EN    0x4 // here EN is on D2 (just one EN shared for the one bit example)
#define  EN    0x84 // put enable on d2 and d7
//#define  SYNC  0x80 // was for scope
#define  WR    0x28 // WR is D3 and D5 high
#define  RD    0x50 // RD is D4 and D6 high 

volatile unsigned char pulsed, xco, yco, xcc,ycc;
volatile byte cores[8][8]={0};

    void sDelay (byte cnt) {
      for (byte ii = 0; ii < cnt; ii++) {
        __asm__ ("nop\n\t");    // NOP delays 62.5 ns
        __asm__ ("nop\n\t");
      }
    }


inline byte pulserl(byte x, byte y){
  byte a,b,c,d;  
  c=1<<low_x_pins[x];
  d=1<<low_y_pins[y];
  switch(low_x_port[x]) {
    case 1:
      PORTB=c;
      break;
    case 3:
      PORTD=c;
      break;
    case 5:
      PORTG=c;
      break;
    case 7:
      PORTL=c;
    }

    switch(low_y_port[y]) {
    case 1:
      PORTB|=d;
      break;
    case 5:
      PORTG|=d;
      break;
    case 7:
      PORTL|=d;
    }     
  a=1<<enable_pins_x[x];
  b=1<<enable_pins_y[y];

  //  if (enable_port_x[x]==4)     PORTE=a;
  //  else if (enable_port_x[x]==5) PORTG|=a;
  //  else PORTH=a;

  if (enable_port_y[y]==1 && enable_port_x[x]==4)     {
    PORTB|=b; PORTE=a;
  }
  else if (enable_port_y[y]==1 && enable_port_x[x]==5)     {
    PORTB|=b; PORTG|=a;
  }
  else if (enable_port_y[y]==1 && enable_port_x[x]==6)     {
    PORTB|=b; PORTH=a;
  }
  else if (enable_port_y[y]==3 && enable_port_x[x]==4)     {
    PORTD|=b; PORTE=a;
  }
  else if (enable_port_y[y]==3 && enable_port_x[x]==5)     {
    PORTD|=b; PORTG|=a;
  }
  else if (enable_port_y[y]==3 && enable_port_x[x]==6)     {
    PORTD|=b; PORTH=a;
  }
    
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  //  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\t");
  //  __asm__ ("nop\n\t");
    

  // sample sense amp output after ~1,200 ns delay
  byte smpl = PINJ & 0x02; // sense is on 14 = PJ1 - checked 
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");  // 
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");  //
  
  // clear enables - all ports?
  PORTB=0; PORTD=0; PORTG=0; PORTH=0; PORTL=0; PORTE=0; 
  sDelay(DELAY);
    return smpl>>1;
}
  
  // set enable on for x and for y
// with 0=A,1=B,2=C,3=D,4=E,5=G,6=H,7=L

//byte enable_port_x[8]={4,4,5,4, 6,6,6,6};
//byte enable_port_y[8]={1,1,1,1, 3,3,3,3}; // checked!

  

inline byte pulserh(byte x, byte y){
  byte a,b,c,d;  
  c=1<<hi_x_pins[x];
  d=1<<hi_y_pins[y];
  
  if (hi_x_port[x]==0)      PORTA=c;
  else PORTC=c;

  if (hi_y_port[y]==0)      PORTA|=d;
    else PORTC|=d;

    a=1<<enable_pins_x[x];
    b=1<<enable_pins_y[y];

  if (enable_port_y[y]==1 && enable_port_x[x]==4)     {
    PORTB=b; PORTE=a;
  }
  else if (enable_port_y[y]==1 && enable_port_x[x]==5)     {
    PORTB=b; PORTG=a;
  }
  else if (enable_port_y[y]==1 && enable_port_x[x]==6)     {
    PORTB=b; PORTH=a;
  }
  else if (enable_port_y[y]==3 && enable_port_x[x]==4)     {
    PORTD=b; PORTE=a;
  }
  else if (enable_port_y[y]==3 && enable_port_x[x]==5)     {
    PORTD=b; PORTG=a;
  }
  else if (enable_port_y[y]==3 && enable_port_x[x]==6)     {
    PORTD=b; PORTH=a;
  }

  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
  //  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
    __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\t");

  //  __asm__ ("nop\n\tnop\n\t");
  //  __asm__ ("nop\n\t");

  
  // sample sense amp output after ~1,200 ns delay
  byte smpl = PINJ & 0x02; // sense is on 14 = PJ1 - checked 
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");  // 
  __asm__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");  //
  
  // clear enables - all ports?
  PORTA=0; PORTB=0; PORTC=0; PORTD=0; PORTE=0; PORTG=0; PORTH=0;
  sDelay(DELAY);
    return smpl>>1;
}

void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

#define MAXED 10

ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here - also for PORTK
 {
      byte posx, posy=0;
      byte x, y;
   // xcc and ycc and pulsed are the goals
      //      x=255-PINK; // 255 is all pins doing nothing = 5v high... now all drop...
      //      x=255-PINK;
   xco=PINK;yco=PINF;
   // test muon code 
      if (xco!=255 && yco!=255 && pulsed!=1){
     xcc=255-xco;
     ycc=255-yco;
     pulsed=1;
     }

   // XXXXXX___________>>>>                   simulated core code
   /*
 if (xco!=255 && yco!=255){
     x=255-xco;y=255-yco;
     // figure out which core we want
     // if pulsed then decode address from bits in x and y
     // eg. 0100 0000 and we want 1 1=0, 2=1, 3=2
	byte count = 0;
	while (x)
	  {
	    x = x >> 1;
	    ++count;
	  }
	posx=count;

	count=0;
	while (y)
	  {
	    y = y >> 1;
	    ++count;
	  }
	posy=count;
	//      pulsed=0;
      posx-=1; posy-=1;
      // then flip that bit - pulseh, pulsel
      // sense output and flip it so do write again if there is no sense out
      // if we write 1 and was a 0 then we sense flip =0 so we don't flip
      // if we write 1 and was a 1 then we sense no flip so then we need to flip it - write a 0
      cores[posx][posy]^=1; // flips
      }
   */   

   //??????????????????????????????????????????????????????????    full core code
      /*   
       if (xco!=255 && yco!=255){
     x=255-xco;y=255-yco;
     // figure out which core we want
     // if pulsed then decode address from bits in x and y
     // eg. 0100 0000 and we want 1 1=0, 2=1, 3=2
	byte count = 0;
	while (x)
	  {
	    x = x >> 1;
	    ++count;
	  }
	posx=count;

	count=0;
	while (y)
	  {
	    y = y >> 1;
	    ++count;
	  }
	posy=count;
	//      pulsed=0;
      posx-=1; posy-=1;
      // then flip that bit - pulseh, pulsel
      // sense output and flip it so do write again if there is no sense out
      // if we write 1 and was a 0 then we sense flip =0 so we don't flip
      // if we write 1 and was a 1 then we sense no flip so then we need to flip it - write a 0

      if (pulserh(posx,posy)==1) { // it didn't flip so it was a 1 and now needs to be a zero

	pulserl(posx,posy); // a flip is a 0 - so no flip then flip
	}
	}*/
 }

void setup() {
  Serial.begin(9600);
  //  DDRD = DDRD | 0xFC;  // D2-D7 are outputs - so far these just for testings
  //  DDRB = DDRB | 0xFE;  // D8 is input = b0

  // inputs for muon = no pullups
  DDRF = 0;
  DDRK = 0;

  // input for SENSE PJ1
  DDRJ= 0;
  
  // all outputs for core enables, hi/lo x and hi/lo y -
  // and set these to 0
  // with 0=A,1=B,2=C,3=D,4=E,5=G,6=H,7=L
  DDRA=255; PORTA=0;
  DDRB=255; PORTB=0;
  DDRC=255; PORTC=0;
  DDRD=255; PORTD=0;
  DDRE=254; PORTE=0; // this works for serial
  DDRG=255; PORTG=0;
  DDRH=255; PORTH=0;
  DDRL=255; PORTL=0;

  // zero all cores
  byte corex,corey;
        for (corey=0;corey<8;corey++){
      for (corex=0;corex<8;corex++){
	  pulserl(corex,corey); 
	  delay(10);
      }
	}
  
  pciSetup(A8); // portk inputs - make sure these are the ones on top of pyramid A8->
  pciSetup(A9);
  pciSetup(A10);
  pciSetup(A11);
  pciSetup(A12);
  pciSetup(A13);
  pciSetup(A14);
  pciSetup(A15);

  

  
}

    void loop() {
      //      static byte counter=0;
      // muon test code - now adapt for flipping
      
      byte x,y, posx, posy, yyy;
      if (pulsed==1 && xcc>0 && ycc>0){
	noInterrupts();
	x=xcc;y=ycc;
	interrupts();
      // if pulsed then decode address from bits in xco and yco
      // eg. 0100 0000 and we want 1 1=0, 2=1, 3=2
	byte count = 0;
	while (x)
	  {
	    x = x >> 1;
        ++count;
	  }
	posx=count;

	count=0;
	while (y)
	  {
	    y = y >> 1;
	    ++count;
	  }
	posy=count;
      pulsed=0;
      posx-=1; posy-=1;

      // test core code
      yyy=pulserh(posx,posy);
      if (yyy==1) { // it didn't flip so it was a 1 and now needs to be a zero
      	pulserl(posx,posy); // a flip is a 0 - so no flip then flip
      }

      // test code to print where muon is x and y            - JAMIE SERIAL DONE!

            
       Serial.print("A");
       Serial.println(posx);

       Serial.print("B");
       Serial.println(posy);

       Serial.print("C");
       Serial.println(yyy^1);


      
      /*      Serial.print(posx);
      Serial.print(":");
      Serial.print(posy);
      Serial.print(":");
      Serial.print(yyy^1);
      Serial.println("");*/
      
      }
      

      // XXXXXXXXXXXXXXXXXXXXXXXX                simulated core code
      /*      byte corex=0, corey=0, xyz;
      for (corex=0;corex<8;corex++){
      	for (corey=0;corey<8;corey++){
	  noInterrupts();
	  Serial.print(cores[corex][corey]);
	  interrupts();
	  delay(100);
	}
      }
      Serial.println("");
      delay(500);
      */
            
      // - scan full x and y every x seconds and output this data via serial to PI
      // X??????????????????????????????????????   code for cores
      /*
      byte corex=0, corey=0, xyz;
      //      counter++;
      //      if (counter==8){
      for (corey=0;corey<8;corey++){
      for (corex=0;corex<8;corex++){

	//	  noInterrupts();
	  xyz=pulserl(corex,corey); //  0=flip
	  //	  interrupts();

	  // if it was a 0 then no flip so it was a 0
	  if (xyz==1) Serial.print("0");// println! // no flip
	  else {
	    // if it was a 0 then flipped so it was a 1 and we need to flip back
	    Serial.print("1");

	    //	    noInterrupts();
	    pulserh(corex,corey);// println!
	    //	    interrupts();
	    delay(10);
	  }
	  delay(10);
          }
      }
      Serial.println("");
      */
      //      delay(500);
      //      counter=0;
      //    }

            // test code for cores - which works fine almost!
            byte corex=0, corey=0;
      //      for (corex=0;corex<8;corex++){
      //      	for (corey=0;corey<8;corey++){
	    /*      corex=rand()%8;
      corey=rand()%8;
      Serial.print(corex);
      Serial.print(":");
      Serial.print(corey);
      Serial.print(":  ");
	
      byte xyz=pulserh(corex,corey); 
      //byte xyz=pulserhigh();// flip to 1=flip to give 001 which is what gives so this works
      Serial.print(xyz);
      Serial.print(":");
      xyz=pulserl(corex,corey); // flip to 0=flip
      //      xyz=pulserlow();
      Serial.print(xyz);
      Serial.print(":");
      xyz=pulserl(corex,corey); // flip to 0=no flip
      //      xyz=pulserlow();
      Serial.print(xyz);
      Serial.println("");
      delay(100);*/
      //          }
      //        }
     


    }