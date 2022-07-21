//#include "avr\io.h"
#define SAMPLE_DELAY 5 // number of seconds between samples
#define SAMPLE_DURATION 5 // number of seconds to sample for.
volatile int mult=0;
static uint32_t timer=0;
float GetData();

void setup()
{
 Serial.begin(57600);
 delay(1000);
 Serial.println("Hello world");
}


void loop()
{
  if (millis() > timer) {
   timer = millis() + (SAMPLE_DELAY*1000); //only run every 5 seconds or whatever
   float FGMreading;
   FGMreading = GetData();
   Serial.print("FGM Reading. Period = ");
   Serial.print(FGMreading,5);
   Serial.println(" microseconds");
  }
}

ISR(TIMER5_COMPA_vect) {
 //Interrrupt service routine for clock counter - each time it reaches 65k, reset and increase mult
 //mult*65k is then added to the count at the end in GetData()
 if (TIFR5 & 1) { // if Timer/Counter 1 overflow flag
   mult++; // count number of Counter1 overflows
   TIFR5 =(1<<TOV5); // clear Timer/Counter 1 overflow flag
  }
}

float GetData(void){
unsigned long count;
unsigned long Frequency;

mult=0;
TCCR5A=0; // reset timer/counter control register A
TIMSK5 |=(1<<OCIE5A); //enable interrupt service routine

 //start counting
 bitSet(TCCR5B ,CS12); // Counter Clock source is external pin 47 of mega 2560
  bitSet(TCCR5B ,CS11); // Clock on rising edge
  delay(SAMPLE_DURATION*1000); //wait for sample duration and count the clicks
  //stop counting
 TCCR5B = 0;
 count = TCNT5;
  TCNT5 = 0;

 count+=0x10000 * mult; // the counter is 16 bit, so total count is count + mult*65k
 Frequency = count/SAMPLE_DURATION; //frequency in Hz

  unsigned long long oneSecond = 1000;
  oneSecond*=1000;
 oneSecond*=1000;
  oneSecond*=100;
  unsigned long long Period;
 Period = oneSecond / (unsigned long long) Frequency;

  float usPeriod;
 usPeriod = float (Period) / 100000;

 return usPeriod;
}
