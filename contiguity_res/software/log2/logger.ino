// logger for temperature with ds1820, arduino uno and sd

/* REFS:

https://github.com/OSBSS/TRH/blob/master/TRH.ino

http://www.osbss.com/tutorials/temperature-relative-humidity/

https://maker.pro/arduino/tutorial/how-to-make-an-arduino-sd-card-data-logger-for-temperature-sensor-data

https://learn.adafruit.com/low-power-wifi-datalogging/power-down-sleep

https://thecavepearlproject.org/how-to-build-an-arduino-data-logger/

https://thecavepearlproject.org/2017/05/21/switching-off-sd-cards-for-low-power-data-logging/

https://forum.arduino.cc/index.php?topic=149504.0

http://forum.arduino.cc/index.php?topic=109062.0

https://forum.arduino.cc/index.php?topic=460850.0

https://github.com/mharizanov/new_Funky/blob/master/examples/Funky_DS18B20_plus_powersave/Funky_DS18B20_plus_powersave.ino

https://thecavepearlproject.org/2014/03/12/using-a-ds18b20-temp-sensor-without-a-dedicated-library/

http://www.semifluid.com/2012/09/10/arduino-fio-ds18b20-temperature-logge/

 */

#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>

char filename[15] = "log.csv";
int SDcsPin = 9; // pin 9 is CS pin for MicroSD breakout
SdFat sd; 		// declare object for SdFat class
SdFile file; // declare object for SdFile class

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup() {

  pinMode(SDcsPin, OUTPUT);

  Serial.begin(115200);
  sensors.begin();

    if (!sd.begin(SDcsPin, SD_SCK_MHZ(50))) {
      sd.initErrorHalt();
    }

    if (!file.open(filename, O_WRONLY | O_CREAT | O_EXCL)) {
            Serial.println("file.open");
  }
    
}

void loop() {

  delay(1);  // give some delay for SD card and RTC to be low before processor sleeps to avoid it being stuck
  
  // DO OUR STUFF
  sensors.begin(); // as before it didn;t work

  sensors.requestTemperatures(); // Send the command to get temperatures
  float temper=sensors.getTempCByIndex(0); 
  Serial.println(temper);
  file.print(temper);
  file.println();

  if (!file.sync() || file.getWriteError()) {
    Serial.println("write error");
  }
  
  delay(1000);
  }
