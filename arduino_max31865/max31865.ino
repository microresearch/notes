#include <Adafruit_MAX31865.h>

// Use software SPI: CS, DI, DO, CLK

//Adafruit_MAX31865 max = Adafruit_MAX31865(42, 44, 46, 48);

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
  }

void loop() {
  uint16_t rtd = max.readRTD();  
  float ratio = rtd;
  ratio /= 32768;
  Serial.println(max.temperature(RNOMINAL, RREF));
  }
