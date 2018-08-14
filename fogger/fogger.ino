// test template

#include <Wire.h>

int fogger=8;

void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600); // start serial for output
  //  pinMode(inputleft, INPUT_PULLUP);

    // test relay 3x on /off
  digitalWrite(8,LOW); // this is on!
  delay(1000);
  digitalWrite(8,HIGH); // this is off
  delay(1000);
  digitalWrite(8,LOW); // this is on!
  delay(1000);
  digitalWrite(8,HIGH); // this is off
  delay(1000);
  digitalWrite(8,LOW); // this is on!
  delay(1000);
  digitalWrite(8,HIGH); // this is off
  delay(1000);

}

void loop() {
  int x;
  uint8_t c;
  long wait;
  // then stay on for 2 minutes=2x60x1000= 120,000
  digitalWrite(8,LOW); // this is on!
  wait=120000;
  delay(wait);
  digitalWrite(8,HIGH); // this is off

  // the wait one hour = 60x60*1000=3600000
  wait=3600000;
  delay(wait);
  
  
  }
