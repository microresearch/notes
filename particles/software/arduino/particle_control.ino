#include <Adafruit_MAX31865.h>

// measure temp for pi/serial and also do pwm pin 9 for smoking in ramge 20-80 odd degrees

// we could also do temp feedback!

// CLK=13, DO-MISO=12, DI=MOSI=11, CS=8

// use hardware SPI, just pass in the CS pin
Adafruit_MAX31865 max = Adafruit_MAX31865(8);

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

  pinMode(8, OUTPUT); // chip select pin must be set to OUTPUT mode
  pinMode(9, OUTPUT);
  analogWrite(9,0); // start at zero

}

void loop() {
  static int reading;
  float tempdif;
  static float lasttemp;

  // if we want to do scaling and write to the FET?
  // scale between say 20-80 degrees = 70 to 0-255
  //  uint16_t scaled=(int)((temper-20.0)*6.0);
  //  if (scaled>255) scaled=255;
  //    Serial.println(scaled);
  //  analogWrite(9,scaled);
  //      while (Serial.available()>0) {
  //        serIn=Serial.read();
  //            Serial.println(serIn);
      //      if (serIn==79) Serial.println(int(temper*100)); // printed *100 and rounded for pi
  //    }
  //  tempdif=abs(temper-lasttemp);
  //  lasttemp=temper;
  //  Serial.println(temper); // this is temperature
  //    Serial.write(int(tempdif*100)); // printed *100 and rounded for pi - was println
  //    Serial.println(int(tempdif*100)); // printed *100 and rounded for pi - was println
  
 if (readline(Serial.read(), buf, 80) > 0) {
   //        Serial.print("You entered: >");
   //        Serial.print(buf);
   //        Serial.println("<");
   if (reading==1) {
     // get integer and write to anlog
   int anlog=atoi(buf);
   Serial.print("Heating: ");
   Serial.println(anlog);
  //    Serial.println(scaled);
   if (anlog>255) anlog=255;
   analogWrite(9,anlog);
   
   reading=0;
 }

   // commands: T to show temperature
   //   W to write integer to analogwrite:

   if (!strcmp(buf, "t")) {
     //     uint16_t rtd = max.readRTD();  //not needed
     //     float ratio = rtd;
     float temper=max.temperature(RNOMINAL, RREF);
     //     ratio /= 32768;

     Serial.println(temper); // this is temperature

   }
   if (!strcmp(buf, "w")) {
     reading=1;
     //     Serial.println(reading);
   }
 }
}
