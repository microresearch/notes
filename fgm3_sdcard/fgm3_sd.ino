//FGM3 to sd card: fgm3 from bottom left to right: 5V, O/P, GND, f/b?

#include <SD.h>
#include "/usr/lib/avr/include/avr/io.h"
#define SAMPLE_DELAY 5 // number of seconds between samples
#define SAMPLE_DURATION 5 // number of seconds to sample for.
volatile int mult=0;
static uint32_t timer=0;

ISR(TIMER1_COMPA_vect) {
 //Interrrupt service routine for clock counter - each time it reaches 65k, reset and increase mult
 //mult*65k is then added to the count at the end in GetData()
 if (TIFR1 & 1) { // if Timer/Counter 1 overflow flag
   mult++; // count number of Counter1 overflows
   TIFR1 =(1<<TOV1); // clear Timer/Counter 1 overflow flag
  }
  } 

float GetData(){
   unsigned long count;
 unsigned long Frequency;
 
  mult=0;
  TCCR1A=0; // reset timer/counter control register A
 TIMSK1 |=(1<<OCIE1A); //enable interrupt service routine

 //start counting
 bitSet(TCCR1B ,CS12); // Counter Clock source is WHAT PIN?increment timer 1 on T1 Pin falling edge - pin 5?
  bitSet(TCCR1B ,CS11); // Clock on rising edge
  delay(SAMPLE_DURATION*1000); //wait for sample duration and count the clicks
  //stop counting
 TCCR1B = 0;
 count = TCNT1;
  TCNT1 = 0;
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

// plot with gnuplot: find more software for png etc. just to test

// plot "/root/test2" with lines

// sd card logger

// use hardware SPI, just pass in the CS pin

// for SD card:

int chipSelect = 9; // CS=chip select pin for the MicroSD Card Adapter
File file; // file object that is used to read and write data
char filename[7]="monk00";
int nott=0;

void setup() {
  Serial.begin(115200);
  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  
  if (!SD.begin(chipSelect)) { // Initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }

  // increment name of file

      strcpy(filename, "monk00");  filename[6]='\0';
    // open new file
      ////
      while(nott==0){

      for (filename[4] = '0'; filename[4] <= '9'; filename[4]++) {
	for (filename[5] = '0'; filename[5] <= '9'; filename[5]++) {
	  if(!SD.exists(filename)){
	    file = SD.open(filename, FILE_WRITE); // open "file.txt" to write data
	    nott=1;
	    break;
	  }
	  //	else file.close();
	if (nott==1) break;
	}
	if (nott==1) break;
      }
	}
      delay(2000);

      Serial.print("Opened filename: "); 
      Serial.println(filename);
}



void loop() {

  if (file) {

    if (millis() > timer) {
   timer = millis() + (SAMPLE_DELAY*1000); //only run every 5 seconds or whatever
   float FGMreading;
   FGMreading = GetData();
   //   Serial.print("FGM Reading. Period = ");
   //..   Serial.print(FGMreading,5);
   //   Serial.println(" microseconds");
   file.println(FGMreading); // write number to file
   file.flush();
  }
  
  }
}
