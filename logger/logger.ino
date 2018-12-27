// logger for temperature with ds1820, arduino micro, microsd card breakout and RTC DS3231

// TODO: basic programming tests for micro/mkarduinoDONE, new SD library-PARTLY TESTED, DS1820-DONE,

// note: sd adapter needs 5v vcc so solder up bare header/adapter finally

// RTC connection and timestamp (comma seperated),DONE more or less

// power saving and rtc interrupt, test sd writing and all - DONE

// switch SD card and ds1820 off and on with NPN - configuration? do we need to reinit anything?DONE-just SD

// ------> finally take out all LEDs, add own LED-DONE, fix SD card thing and measure current - make solid all conns...

///// -> so far we can't switch off ds1820 - draw=very low though in standby so we leave for now...


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
#include <PowerSaver.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SdFat.h>
#include <DS3232RTC.h>

#define POWA 4    // pin 4 supplies power to microSD card breakout and DS1820
#define LED 7 // pin 7 controls LED

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

  pinMode(POWA, OUTPUT);  // set output pins
  pinMode(LED, OUTPUT);
  pinMode(SDcsPin, OUTPUT);

  // Serial.begin(9600);
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

 digitalWrite(POWA, HIGH);    // turn on SD card
 delay(1); // give some delay to ensure RTC and
 
  if(!sd.init(SPI_FULL_SPEED, SDcsPin))  // initialize SD card on the SPI bus - very important - was HALF_SPEED
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

    digitalWrite(LED, HIGH);
    delay(10);
    digitalWrite(LED, LOW);
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

#
void loop() {

  digitalWrite(POWA, LOW);  // turn off microSD card to save power
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
  sensors.begin(); // as before it didn;t work

  sensors.requestTemperatures(); // Send the command to get temperatures
  float temperature=sensors.getTempCByIndex(0); 

  

  pinMode(POWA, OUTPUT); 
  digitalWrite(POWA, HIGH);  // turn on SD card power
  delay(1); // give delay to let the SD card and SHT15 get full powa
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
    setSyncProvider(RTC.get); // the function to get the time from the RTC
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
    digitalWrite(LED, HIGH);
    delay(10);
    digitalWrite(LED, LOW);
    
  }
  
  /////////////////////////
  
  //  RTC.setNextAlarm();      //set next alarm before sleeping
  RTC.setAlarm(ALM2_EVERY_MINUTE, 0, 0, 0, 0);
  RTC.alarm(ALARM_2);
  RTC.squareWave(SQWAVE_NONE);
  RTC.alarmInterrupt(ALARM_2, true);


  delay(1);
  }
