// read in temperature which has been remapped to 0-255 from sd card: monkxy
// write this to pwm pin 9 for FET and delay xxx
// this is recreation of lost version used in Messene/Tuned City

// reads three values from csv on sd card monkxy ...

// ref: https://forum.arduino.cc/index.php?topic=231631.0

//  minicom -D /dev/ttyACM0 -b 9600   

// SPI/SD UNO: CS is pin 8 defined here, SCK-13, MOSI-11, MISO-12

// // what is timing/do we need delay?

#include <Wire.h>
#include <SD.h>

File file; 
char filename[7]="monkxy";

unsigned long time;

void setup() {
  //  pinMode(13, OUTPUT);
  Serial.begin(9600); 
  //  pinMode(inputleft, INPUT_PULLUP);

  int chipSelect = 8; // CS=chip select pin for the MicroSD Card Adapter
  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  
  if (!SD.begin(chipSelect)) { // Initialize SD card
    Serial.println("Could not initialize SD card."); 
  }

}

bool readLine(File &f, char* line, size_t maxLen) {
  for (size_t n = 0; n < maxLen; n++) {
    int c = f.read();
    if ( c < 0 && n == 0) return false;  // EOF
    if (c < 0 || c == '\n') {
      line[n] = 0;
      return true;
    }
    line[n] = c;
  }
  return false; // line too long
}

bool readVals(int* v1, int*v2, int* v3) {
  char line[40], *ptr, *str;
  if (!readLine(file, line, sizeof(line))) {
    return false;  // EOF or too long
  }
  *v1 = strtol(line, &ptr, 10);
  if (ptr == line) return false;  // bad number if equal
  while (*ptr) {
    if (*ptr++ == ',') break;
  }
  *v2 = strtol(ptr, &str, 10); // for two values
  if (ptr == line) return false;  // bad number if equal
  while (*ptr) {
    if (*ptr++ == ',') break;
  }
  *v3 = strtol(ptr, &str, 10); // for three values  
  return str != ptr;  // true if number found
}

void loop() {
  unsigned int x, y, temper, count=0;

  file = SD.open(filename, FILE_READ); 
  delay(2000);
  time = millis();
  Serial.println(time/1000);
  if (file){
    Serial.print("Opened filename: "); 
    Serial.println(filename);
  }
  
  // read in one line from file and out as analogWrite
  while (readVals(&temper, &x, &y)) {
    analogWrite(9,x);
    //    count++;
  //  Serial.println(x);
    delay(100);
  }
  file.close();
  time = millis();
  Serial.println(time/1000);
  Serial.println(count);
}
