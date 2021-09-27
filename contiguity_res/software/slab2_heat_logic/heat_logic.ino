/* 

HEAT LOGIC:

// l-list files
// d dump file x (monk+number)
// r reset and try open from scratch all

// plot with gnuplot: find more software for png etc. just to test
// plot "/root/test2" with lines

// CLK=13, DO-MISO=12, DI=MOSI=11, CS=10, heat on pin 6

TODO:
- DS1820 x2 DONE
- SD card (need to find extra working SD) DONE
- heating circuit tests/PWM DONE

TESTING battery...

- what logic could be:

average x, y for x seconds - next x seconds if is below is a 0, above is a 1

- logic and averages etc///
- test all
- write 3 values and logics to SD

- USB re-wire and test 

- how we set threshold for 1 or 0: average temp for x seconds, next x
  seconds and compare higher/lower on each (but this makes it all a
  matter of timing)

or always record average and make a guess...


// TODO:  temperature with 2x ds1820, arduino uno
// add latest SD code from 


*/

#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SD.h>
#include <SPI.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void(* resetFunc) (void) = 0;

// for SD card:
int chipSelect = 10; // CS=chip select pin for the MicroSD Card Adapter
File file; // file object that is used to read and write data

char line[10];
char buf[80];
char filename[12]="monk";
char filenamen[12]="";

int printDirectory(File dir, int numTabs) {
  int numfiles=0;
  dir.seek(0); /////// Add seek ///////////////////
  while(true) {
          File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       Serial.println("**nomorefiles**");
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     numfiles++;
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }     
     entry.close();
   }
  return numfiles;
}

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
		  //  Serial.print(readch);
                    buffer[pos++] = readch;
                    buffer[pos] = 0;
                }
        }
    }
    return 0;
}

unsigned char charrr[8];
File root;

void setup() {

  Serial.begin(115200);
  sensors.begin();

  //    pinMode(A0, OUTPUT); 
  //  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); // CS pin for SD card 

  pinMode(6, OUTPUT); // heat on pin 6
  
  SPI.begin();
  //  SPI.setDataMode(SPI_MODE1);  

  Serial.println(" l: list files d: dump file x (monk+number) r: reset all");
  
  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  //  SPI.begin();
  //    SPI.setDataMode(SPI_MODE0);  
    if (!SD.begin()) { // Initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }
    else {// flash twice on success)
	  digitalWrite(7, HIGH);
	  delay(300);
	  digitalWrite(7, LOW);
	  delay(600);
	  digitalWrite(7, HIGH);
	  delay(300);
	  digitalWrite(7, LOW);
	  }
  
  // xx
    root = SD.open("/");
    int numfiles=printDirectory(root, 0);
    numfiles++;
    itoa(numfiles,charrr,10);
    strcpy(filenamen,filename);
    strcat(filenamen, charrr);
    if(!SD.exists(filenamen)){
      file = SD.open(filenamen, FILE_WRITE); // open "file.txt" to write data
    }
    Serial.print("Opened filename: "); 
    Serial.println(filenamen);
    delay(1000);  
}

void commandline(){
{
 if (readline(Serial.read(), buf, 80) > 0) {

      if (!strcmp(buf, "r")) { // reset all
     resetFunc();
     }
   
   if (!strcmp(buf, "d")) { // dump file
     //     reading=1;
     //   if (reading==1) {
     // close last file
     file.close();
     // get integer and dump that file monkxx
     // buf is with number
     // make new filenamen with number
     int num=Serial.parseInt();
     itoa(num,charrr,10);
     strcpy(filenamen,filename);
     strcat(filenamen, charrr);
     Serial.print("Opening filename: "); 
     Serial.println(filenamen);

     file = SD.open(filenamen, FILE_READ); 
     delay(1000);
     if (file){
       Serial.print("Opened filename: "); 
       Serial.println(filenamen);
     }
     else
       {
       Serial.println("FAILED");
       }
  
  if (file) {
    while (file.available()) {
      Serial.write(file.read());
    }
    //  }
  
     file.close();
     delay(500);
     // open new file to write data to
    root = SD.open("/");
    int numfiles=printDirectory(root, 0);
    numfiles++;
    itoa(numfiles,charrr,10);
    strcpy(filenamen,filename);
    strcat(filenamen, charrr);
    if(!SD.exists(filenamen)){
      file = SD.open(filenamen, FILE_WRITE); // open "file.txt" to write data
    }
    Serial.print("Opened filename: "); 
    Serial.println(filenamen);
    delay(1000);
    //      reading=0;
   }


   }

   if (!strcmp(buf, "l")) {
     //      Serial.println("l");
     file.close();
     delay(500);
     // print the list the files
     root = SD.open("/");
    int numfiles=printDirectory(root, 0);
    numfiles++;
    itoa(numfiles,charrr,10);
    strcpy(filenamen,filename);
    strcat(filenamen, charrr);
    if(!SD.exists(filenamen)){
      file = SD.open(filenamen, FILE_WRITE); // open "file.txt" to write data
    }
    Serial.print("Opened filename: "); 
    Serial.println(filenamen);
    delay(1000);
   }
 }
}
}


void loop() {
  static int toggle=0, x=0;
  float av1, av2, avv1, avv2;
  int logic1, logic2, outcome;
  delay(1);  // give some delay for SD card and RTC to be low before processor sleeps to avoid it being stuck
  
  sensors.begin(); // as before it didn;t work
  av1=0; av2=0;avv1=0;avv2=0;

  // DO OUR STUFF and put serial ops in here somewhere
  
  for (x=0;x<10;x++){    // stage 1: average each of temps for x seconds
    sensors.requestTemperatures(); 
    float temper=sensors.getTempCByIndex(0);
    float temperr=sensors.getTempCByIndex(1);   
    av1+=temper;
    av2+=temperr;
    //    delay(50);
    commandline();
  }
  av1=av1/10.0;
  av2=av2/10.0;
  
  for (x=0;x<10;x++){    // stage 2: average each of temps for x seconds
    sensors.requestTemperatures(); 
    float temper=sensors.getTempCByIndex(0); // or is much slower than we imagine
    float temperr=sensors.getTempCByIndex(1);   
    avv1+=temper;
    avv2+=temperr;
    //    delay(50);
    commandline();
  }
  avv1=avv1/10.0;
  avv2=avv2/10.0;

  // logic for each and output to heat for x seconds
  if (avv1>av1) logic1=1;
  else logic1=0;

  if (avv2>av2) logic2=1;
  else logic2=0;
  outcome=logic1^logic2;
  
  if (outcome) {
    analogWrite(6,255);
    Serial.println("1-HEAT");
  }
  else {
    analogWrite(6,0);
    Serial.println("0-NO");
  }

  //  for (x=0;x<100;x++){  
  //    delay(500);
  //  commandline();
  //  }
  
  // record to SD states (eg. 0 0 1), and average temps
  
  file.print(av1); 
  file.print(", "); 
  file.print(avv1);
  file.print(", "); 
  file.print(av2); 
  file.print(", "); 
  file.print(avv2);
  file.print(", "); 
  file.print(logic1); 
  file.print(", "); 
  file.print(logic2);
  file.print(", "); 
  file.print(outcome);
  file.println();
  file.flush();
}