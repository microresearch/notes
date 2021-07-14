#include <Adafruit_MAX31865.h>

// CLK=13, DO-MISO=12, DI=MOSI=11, CS=8
// use hardware SPI, just pass in the CS pin

// tested with 3x MAX31865, and with relay board
// Pins 4, 5, 6, and 7 control relays 4, 3, 2, and 1 respectively.
// commands: read temp1, temp2, temp3 // relay1, relay2 - on/off // output value on pwm1, pwm2 (analogwrite - pins 3 and 10)

// commands: T, U, V to show temperature
// W to write integer to analogwrite pin 3, E to write pin 10
// Z, X: on off relay1 pin 7:
// A, S: on off relay2 pin 6:



Adafruit_MAX31865 max = Adafruit_MAX31865(8);
Adafruit_MAX31865 max2 = Adafruit_MAX31865(9);
Adafruit_MAX31865 max3 = Adafruit_MAX31865(2);

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

char buf[80];

int readline(int readch, char *buffer, int len) {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
        switch (readch) {
            case '\r': // Ignore CR
                rpos = pos;
                pos = 0;  // Reset position index ready for next time
                return rpos;
		//                break;
            case '\n': // Return on new-line
	      //Serial.print(readch);
                rpos = pos;
                pos = 0;  // Reset position index ready for next time
                return rpos;
            default:
                if (pos < len-1) {
		  //		  Serial.print(readch);
                    buffer[pos++] = readch;
                    buffer[pos] = 0;
                }
        }
    }
    return 0;
}

void setup() {
  Serial.begin(115200);
  max.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  max2.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  max3.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary

  pinMode(6, OUTPUT);  // relays
  pinMode(7, OUTPUT);

  pinMode(3, OUTPUT);  // analogue output
  pinMode(10, OUTPUT);
   
  pinMode(8, OUTPUT); // chip select pin must be set to OUTPUT mode
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);

  analogWrite(3,0); // start at zero
  analogWrite(10,0); // start at zero
  digitalWrite(6,LOW); 
  digitalWrite(7,LOW); 

}

void loop() {
  static int reading, readingg;
 
 if (readline(Serial.read(), buf, 80) > 0) {

   if (reading==1) {
     // get integer and write to anlog
   int anlog=atoi(buf);
   Serial.print("Out1: ");
   Serial.println(anlog);
   if (anlog>255) anlog=255;
   analogWrite(3,anlog); // what pins to use for analogwrite?   
   reading=0;
 }

      if (readingg==1) {
     // get integer and write to anlog
   int anlog=atoi(buf);
   Serial.print("Out2: ");
   Serial.println(anlog);
   if (anlog>255) anlog=255;
   analogWrite(10,anlog); // what pins to use for analogwrite?   
   readingg=0;
 }
   

      if (!strcmp(buf, "z")) {
	digitalWrite(7,HIGH); 
      }

      if (!strcmp(buf, "x")) {
	digitalWrite(7,LOW); 
      }

      if (!strcmp(buf, "a")) {
	digitalWrite(6,HIGH); 
      }

      if (!strcmp(buf, "s")) {
	digitalWrite(6,LOW); 
      }

      
      
   if (!strcmp(buf, "t")) {
     float temper=max.temperature(RNOMINAL, RREF);
     Serial.println(temper); // this is temperature
   }

   if (!strcmp(buf, "u")) {
     float temper=max2.temperature(RNOMINAL, RREF);
     Serial.println(temper); // this is temperature
   }

   if (!strcmp(buf, "v")) {
     float temper=max3.temperature(RNOMINAL, RREF);
     Serial.println(temper); // this is temperature
   }

   
   if (!strcmp(buf, "w")) {
     reading=1;
   }

   if (!strcmp(buf, "e")) {
     readingg=1;
   }


   // commands

   
 } // readlie
}
