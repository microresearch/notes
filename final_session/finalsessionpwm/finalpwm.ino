// test template

#include <Wire.h>

byte p1=3;
byte p2=11;
byte p3=10;
byte p4=9;


void setup() {
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);

  Serial.begin(9600); // start serial for output
}

void loop() {
  byte v1,v2,v3,v4;
  // read adc - maybe more scaling
  v1=analogRead(A0)>>2; 
  v2=analogRead(A1)>>2; 
  v3=analogRead(A2)>>2; 
  v4=analogRead(A3)>>2; 
  //  Serial.print(v2);        
  //  Serial.print(" ");        
  //  Serial.println(v3);        
  
  // output pwm
  analogWrite(p1, v1);
  analogWrite(p2, v2);
  analogWrite(p3, v3);
  analogWrite(p4, v4);
  // any delay that we might need?
  // delay(wait);

}
