
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

void setup() {
  Serial.begin(115200);
  max.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary

  pinMode(8, OUTPUT); // chip select pin must be set to OUTPUT mode
  pinMode(9, OUTPUT);
  }

void loop() {
  int serIn;
  uint16_t rtd = max.readRTD();  
  float ratio = rtd;
  float tempdif;
  static float lasttemp;
  float temper=max.temperature(RNOMINAL, RREF);
  ratio /= 32768;
  // if we want to do scaling and write to the FET?
  // scale between say 20-80 degrees = 70 to 0-255
  uint16_t scaled=(int)((temper-20.0)*6.0);
  if (scaled>255) scaled=255;
  //    Serial.println(scaled);
  //  analogWrite(9,scaled);
  //    while (Serial.available()>0) {
  //      serIn=Serial.read();
      //      Serial.println(serIn);
      //      if (serIn==79) Serial.println(int(temper*100)); // printed *100 and rounded for pi
  //    }
  tempdif=abs(temper-lasttemp);
  lasttemp=temper;
  Serial.println(temper);

  //    Serial.write(int(tempdif*100)); // printed *100 and rounded for pi - was println
  //    Serial.println(int(tempdif*100)); // printed *100 and rounded for pi - was println
}
