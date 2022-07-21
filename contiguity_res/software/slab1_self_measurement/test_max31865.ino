#include <Adafruit_MAX31865.h>
#include <SD.h>
#include <SPI.h>

// l-list files
// d dump file x (monk+number)
// r reset and try open from scratch all

// plot with gnuplot: find more software for png etc. just to test
// plot "/root/test2" with lines

// CLK=13, DO-MISO=12, DI=MOSI=11, CS=10

//Adafruit_MAX31865 max = Adafruit_MAX31865(8); // CS for maxim is on pin 3
// Use software SPI: CS, DI, DO, CLK
// Adafruit_MAX31865::Adafruit_MAX31865(int8_t spi_cs, int8_t spi_mosi, int8_t spi_miso, int8_t spi_clk) {
Adafruit_MAX31865 max = Adafruit_MAX31865(3, 4, 5, 6);

void(* resetFunc) (void) = 0;

// use hardware SPI, just pass in the CS pin
//Adafruit_MAX31865 max = Adafruit_MAX31865(10);

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

// for SD card:

int chipSelect = 10; // CS=chip select pin for the MicroSD Card Adapter
File file; // file object that is used to read and write data
//char filename[7]="monk00";
int nott=0;

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
  pinMode(8, OUTPUT); // chip select pin must be set to OUTPUT mode
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);     // change this to 53 on a mega

  pinMode(13, OUTPUT); // led on pin 13
  
  SPI.begin();
  SPI.setDataMode(SPI_MODE1);  

  Serial.println(" l: list files d: dump file x (monk+number) r: reset all");
  
  max.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  delay(500);

    pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  //  SPI.begin();
    SPI.setDataMode(SPI_MODE0);  
    if (!SD.begin()) { // Initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }
    else {// flash twice on success)
	  digitalWrite(13, HIGH);
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

void loop() {
  static int reading=0;
  //  if (file) {
  //       uint16_t rtd = max.readRTD();
    //  uint16_t lighter;
  
  //  Serial.print("RTD value: "); Serial.println(rtd);
  //      float ratio = rtd;
  //      ratio /= 32768;
  //    Serial.print("Ratio = "); Serial.println(ratio,8);
  //    Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  //    Serial.print("Temperature = "); Serial.println(max.temperature(RNOMINAL, RREF));
    //  lighter=analogRead(0);
  //  Serial.print(lighter);
  //  Serial.print(", ");
  //  SPI.setDataMode(SPI_MODE1);  
  //  Serial.println(max.temperature(RNOMINAL, RREF));

  // concat lighter and temperature
  //  file.print(lighter);
  //    file.print(",");
  SPI.setDataMode(SPI_MODE0);
  file.println(max.temperature(RNOMINAL, RREF)); // write number to file
  file.flush();
  
  delay(1000); // or we save power here but then need to close sd and re-open...
  // TODO: read serial for 2 commands: l-list files
  // d dump file x (monk+number)
  /// rest is just handlings
  
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
      reading=0;
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
