// logger for temperature with ds1820, arduino micro, microsd card breakout and RTC DS3231

// TODO: basic programming tests for micro/mkarduinoDONE, new SD library-PARTLY TESTED, DS1820-DONE,

// note: sd adapter needs 5v vcc so solder up bare header/adapter finally

// RTC connection and timestamp (comma seperated),DONE more or less

// power saving and rtc interrupt, test sd writing and all

// switch SD card and ds1820 off and on with NPN - configuration? do we need to reinit anything?

// ------> finally take out LEDs, add own LED, fix SD card thing and measure current - then make solid all conns...

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

 */

#include <Wire.h>
#include <PowerSaver.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>
#include <DS3232RTC.h>

// for sd card

char filename[15] = "log.csv";
int SDcsPin = 9; // pin 9 is CS pin for MicroSD breakout
SdFat sd; 		// declare object for SdFat class
SdFile file; // declare object for SdFile class
PowerSaver chip; 

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
DS3232RTC RTC;      // instantiate an RTC object

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

ISR(PCINT0_vect)  // Interrupt Vector Routine to be executed when pin 8 receives an interrupt.
{
  //PORTB ^= (1<<PORTB1);
  asm("nop");
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SDcsPin, OUTPUT);

 Serial.begin(9600);
 // Serial.println("Dallas Temperature IC:");
 sensors.begin();
 /*
  time_t t;
 
 tmElements_t tm;
 tm.Hour = 16;             //set the tm structure to 23h31m30s on 13Feb2009
 tm.Minute = 47;
 tm.Second = 0;
 tm.Day = 27;
 tm.Month = 12;
 tm.Year = 2018 - 1970;    //tmElements_t.Year is the offset from 1970
 RTC.write(tm);
 */

 

 setSyncProvider(RTC.get); // the function to get the time from the RTC
 
 if(timeStatus() != timeSet)
        Serial.println("Unable to sync with the RTC");
    else
      Serial.println("RTC has set the system time");
 
// t = makeTime(tm);
// RTC.set(t);        // use the time_t value to ensure correct weekday is set
// setTime(t);
 
 // sd card stuff
 
  if(!sd.init(SPI_HALF_SPEED, SDcsPin))  // initialize SD card on the SPI bus - very important
  {
    delay(10);
    //    SDcardError();
  Serial.println("SDerror");
  }
  else
  {
    delay(10);
    file.open(filename, O_CREAT | O_APPEND | O_WRITE);  // open file in write mode and append data to the end of file
    delay(1);
    file.println();
    file.print("Date/Time,Temp(C)");    // Print header to file
    file.println();
    file.close();    // close file - very important
                     // give some delay by blinking status LED to wait for the file to properly close
    digitalWrite(LED_BUILTIN, HIGH);
    delay(10);
    digitalWrite(LED_BUILTIN, LOW);
}

  // RTC.alarm2set(dayStart, hourStart, minStart);  // Configure begin time
  //  RTC.alarmFlagClear();  // clear alarm flag

  RTC.setAlarm(ALM2_EVERY_MINUTE, 0, 0, 0, 0);
    // clear the alarm flag
  RTC.alarm(ALARM_2);
  
  RTC.squareWave(SQWAVE_NONE);
    // enable interrupt output for Alarm 1
  RTC.alarmInterrupt(ALARM_2, true);
  
chip.sleepInterruptSetup(); // setup sleep function & pin change interrupts on the ATmega328p. Power-down mode is used here
  
}

void printDigits(int digits)
{
    // utility function for digital clock display: prints preceding colon and leading 0
    file.print(':');
    if(digits < 10)
        file.print('0');
    file.print(digits);
}

void digitalClockDisplay()
{
    // digital clock display of the time
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
    Serial.print(' ');
    Serial.print(day());
    Serial.print(' ');
    Serial.print(month());
    Serial.print(' ');
    Serial.print(year());
    Serial.println();
}


void loop() {
  digitalWrite(LED_BUILTIN, LOW); 

  //  digitalWrite(POWA, LOW);  // turn off microSD card to save power
  delay(1);  // give some delay for SD card and RTC to be low before processor sleeps to avoid it being stuck
  
  chip.turnOffADC();    // turn off ADC to save power
  chip.turnOffSPI();  // turn off SPI bus to save power
  //chip.turnOffWDT();  // turn off WatchDog Timer to save power (does not work for Pro Mini - only works for Uno)
  chip.turnOffBOD();    // turn off Brown-out detection to save power
  
  chip.goodNight();    // put processor in extreme power down mode - GOODNIGHT!
                       // this function saves previous states of analog pins and sets them to LOW INPUTS
                       // average current draw on Mini Pro should now be around 0.195 mA (with both onboard LEDs taken out)
                       // Processor will only wake up with an interrupt generated from the RTC, which occurs every logging interval
  
  // code will resume from here once the processor wakes up =============== //
  chip.turnOnADC();    // enable ADC after processor wakes up
  chip.turnOnSPI();   // turn on SPI bus once the processor wakes up
  delay(1);    // important delay to ensure SPI bus is properly activated
  
  //  RTC.alarmFlagClear(); // clear alarm flag
  RTC.alarm(ALARM_2);

  /////////////////////////

  
  // DO OUR STUFF

  sensors.requestTemperatures(); // Send the command to get temperatures
  float temperature=sensors.getTempCByIndex(0); 

  

  //  pinMode(POWA, OUTPUT); 
  //  digitalWrite(POWA, HIGH);  // turn on SD card power
  //delay(1); // give delay to let the SD card and SHT15 get full powa
  pinMode(SDcsPin, OUTPUT);

  if(!sd.init(SPI_FULL_SPEED, SDcsPin))    // very important - reinitialize SD card on the SPI bus
  {
    delay(10);
    //  SDcardError();
  }
  else
  {
    delay(10);
    file.open(filename, O_WRITE | O_AT_END);  // open file in write mode
    delay(1);
    
    SPCR = 0;  // reset SPI control register
    file.print(hour());
    printDigits(minute());
    printDigits(second());
    file.print(' ');
    file.print(day());
    file.print(' ');
    file.print(month());
    file.print(' ');
    file.print(year());
    file.print(", ");
    
    //    file.print(time); // figure out the time stamp
    //    file.print(",");
    file.print(temperature, 2);  // print temperature upto 2 decimal places
    file.println();
    //    PrintFileTimeStamp();
    file.close(); 
  }
  /*  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(100);                       
  digitalWrite(LED_BUILTIN, LOW); 
  delay(100);                    
  */


  
  /////////////////////////
  
  //  RTC.setNextAlarm();      //set next alarm before sleeping
  RTC.setAlarm(ALM2_EVERY_MINUTE, 0, 0, 0, 0);
  RTC.alarm(ALARM_2);
  RTC.squareWave(SQWAVE_NONE);
  RTC.alarmInterrupt(ALARM_2, true);


  delay(1);

  
  /*
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  Serial.print("Temperature for the device 1 (index 0) is: ");
  Serial.println(sensors.getTempCByIndex(0)); 
  */
  //digitalClockDisplay();
  //delay(1000); 
  
  /*
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(1000);                       
  digitalWrite(LED_BUILTIN, LOW); 
  delay(1000);                    
  */  
  }
