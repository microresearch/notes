#include <Adafruit_MAX31865.h>
#include <SD.h>
#include <SPI.h>

// TODO: read serial for 2 commands: l-list files
// d dump file x (monk+number)


// plot with gnuplot: find more software for png etc. just to test
// plot "/root/test2" with lines

// CLK=13, DO-MISO=12, DI=MOSI=11, CS=8

//Adafruit_MAX31865 max = Adafruit_MAX31865(8); // CS for maxim is on pin 8
// Use software SPI: CS, DI, DO, CLK
// Adafruit_MAX31865::Adafruit_MAX31865(int8_t spi_cs, int8_t spi_mosi, int8_t spi_miso, int8_t spi_clk) {
Adafruit_MAX31865 max = Adafruit_MAX31865(3, 4, 5, 6);


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
char filename[7]="monk00";
int nott=0;

char line[10];
char buf[80];
char filenamen[7]="monk";

void printDirectory(File dir, int numTabs) {
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

void setup() {
  Serial.begin(115200);
  pinMode(8, OUTPUT); // chip select pin must be set to OUTPUT mode
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);     // change this to 53 on a mega

  pinMode(7, OUTPUT); // led on pin 7
  
  SPI.begin();
  SPI.setDataMode(SPI_MODE1);  

  max.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  delay(500);

    pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  //  SPI.begin();
    SPI.setDataMode(SPI_MODE0);  
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
  
  // increment name of file

      strcpy(filename, "monk00");  filename[6]='\0';
    // open new file
      ////
      nott=0;
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
  static int reading=0;
  File root;
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
  SPI.setDataMode(SPI_MODE1);  
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

  
 if (readline(Serial.read(), buf, 80) > 0) {

   if (reading==1) {
     // close last file
     file.close();
     // get integer and dump that file monkxx
     // buf is with number
     // make new filenamen with number
     strcat(filenamen, buf);
     file = SD.open(filenamen, FILE_READ); 
     delay(1000);
     if (file){
       Serial.print("Opened filename: "); 
       Serial.println(filenamen);
     }
  
  if (file) {
    while (file.available()) {
      Serial.write(file.read());
    }
  }
  
     file.close();
     // open new file to write data to
      strcpy(filename, "monk00");  filename[6]='\0';
    // open new file
      ////
            nott=0;
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
     reading=0;
   }

   if (!strcmp(buf, "d")) { // dump file
     reading=1;
   }

   if (!strcmp(buf, "l")) {
     //      Serial.println("l");
     file.close();
     // print the list the files
     root = SD.open("/");
     printDirectory(root, 0);
     // open new file to write data to
      strcpy(filename, "monk00");  filename[6]='\0';
    // open new file
      ////
      nott=0;
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
 }
}
