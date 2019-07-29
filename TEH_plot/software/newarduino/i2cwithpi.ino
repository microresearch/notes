/*

- TODO: 

- which way is left and which is right? - matters for zero position left - as is should be fine!
- timing for stepper left and right - always do small movement so can register hit
- how many rights and left we do to move 6cm say?
- timing for pumps drip/drop - nearly DONE - maybe a few tweaks
- check end of switches DONE
[- where is the middle for 2m?] UNUSED

 */

#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;
int darkness = 0;

// for stepper

//int cyclemb=7;
int inputleft=6; // stepper switch
int inputright=7; // stepper switch
int motoren=8;
int step=2;
int dirr=3;
int whereweare=0, lefthit=0, righthit=0;

// for pumps. FET on 9 and 10/11 - two pumps for dark, one for light
int darkone=10;
int darktwo=11;
int light=9;

// callback for received data
void receiveData(int byteCount){
while(Wire.available()) {
darkness = Wire.read();
}
}

void sendData() {
  byte output[] = {0x01};  // This is just some sample data for testing
  Wire.write(output, 1);
}

void setup() {
pinMode(13, OUTPUT);
Serial.begin(9600); // start serial for output
// initialize i2c as slave
Wire.begin(SLAVE_ADDRESS);
// define callbacks for i2c communication
Wire.onReceive(receiveData);
Wire.onRequest(sendData);

 // stepper board old school
 pinMode(inputleft, INPUT_PULLUP);
 pinMode(inputright, INPUT_PULLUP);
 pinMode(dirr, OUTPUT);   
 pinMode(step, OUTPUT); 
 pinMode(motoren, OUTPUT); 

 // pumps

 pinMode(darkone, OUTPUT); 
 pinMode(darktwo, OUTPUT); 
 pinMode(light, OUTPUT); 
}

void do_zero(){
  // for stepper - move left till we register HIT!
  int havewehit=1;
  while (havewehit!=0){
    digitalWrite(motoren,HIGH); // enable
    digitalWrite(dirr,LOW); // is left
    digitalWrite(step,HIGH);
    delay(1);
    digitalWrite(step,LOW);
    delay(2); // slowed down
    havewehit=digitalRead(inputleft); // pulled up to 1
    //        Serial.println(havewehit);
  }
  whereweare=0;
}

void do_far_right(){
  // for stepper - move left till we register HIT!
  int havewehit=1;
  while (havewehit!=0){
    digitalWrite(motoren,HIGH); // enable
    digitalWrite(dirr,HIGH); // is right
    digitalWrite(step,HIGH);
    delay(2);
    digitalWrite(step,LOW);
    delay(100); // slowed down
    digitalWrite(motoren,LOW); // disable
    havewehit=digitalRead(inputright); // pulled up to 1
    //        Serial.println(havewehit);
  }
  whereweare=0;
}


void do_left(){

  // keep track of where we are!
  if (digitalRead(inputleft)==0) // pulled up
    {
      whereweare=0;
      lefthit=1;
    }
  else {
    lefthit=0;
    digitalWrite(motoren,HIGH); // enable
    digitalWrite(dirr,LOW); // is left
    digitalWrite(step,HIGH);
    delay(2); // small movement and wrap this in main code
    digitalWrite(step,LOW);
    //    digitalWrite(motoren,LOW); // disable
    whereweare-=1;
}
  //  Serial.println(whereweare);
}


void do_right(){ // hit on other switch?
  if (digitalRead(inputright)==0) // pulled up
    {
      righthit=1;
    }
  else
    {
      righthit=0;
      digitalWrite(motoren,HIGH); // enable
  digitalWrite(dirr,HIGH); // is right
  digitalWrite(step,HIGH);
  delay(2); // re-test for say 6cm movement
  digitalWrite(step,LOW);
  //    digitalWrite(motoren,LOW); // disable
  whereweare+=1;
    }
  //  Serial.println(whereweare);
}


void do_write(){
// in this case just flash the LED-
digitalWrite(LED_BUILTIN, HIGH);   
  delay(100);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(100);                    
}

void do_pump_dark(){
  // for certain time???
  digitalWrite(darkone, HIGH);   // there are now two pumps for the mixture
  digitalWrite(darktwo, HIGH);   
  delay(16);                      
  digitalWrite(darkone, LOW);
  digitalWrite(darktwo, LOW);   
  //  delay(1000);                    
}

void do_pump_light(){
  // for certain time???
  digitalWrite(light, HIGH);   
  delay(16);                      
  digitalWrite(light, LOW);   
  //  delay(1000);                    
}


void loop() {
  int x;
  uint8_t c;
      digitalWrite(motoren,LOW); // disable

  if(Serial.available()){
    c = Serial.read();
    
    switch(c){
    case 'H': // query the HIT
      if (righthit==1){
	righthit=0;
	Serial.print("R");
	Serial.print("\n");
      }
      else if (lefthit==1){
	lefthit=0;
	Serial.print("L");
	Serial.print("\n");
      }
      else {
	Serial.print("N");
	Serial.print("\n");
      }
      break;      
    case 'Q':
      Serial.print(darkness);
      Serial.print("\n");
      break;
    case 'P': // far left
      do_zero();
      digitalWrite(motoren,LOW); // disable
      break;
    case 'W': // write
      do_pump_dark();
      do_write();
      break;
    case 'E':
      do_pump_light();
      do_write();
      break;
    case 'L':
      for (x=0;x<230;x++){
      do_left(); // how many of these to move say 5 or 6cm?
      }
      digitalWrite(motoren,LOW); // disable
      break;
    case 'R':
      for (x=0;x<230;x++){
      do_right(); // how many of these to move say 5 or 6cm?
      }
      digitalWrite(motoren,LOW); // disable
      break;
      //    case 'M':
      //      do_middle();
      //      break;
    case 'F': //flow the dark pump
      for (x=0;x<100;x++){
      do_pump_dark();
      }
      break;
    case '1': // 1st pump of dark
      for (x=0;x<100;x++){
  digitalWrite(darkone, HIGH);   // there are now two pumps for the mixture
  delay(10);                      
  digitalWrite(darkone, LOW);   
      }
      break;      
    case '2': // 2nd pump of dark
      for (x=0;x<100;x++){
  digitalWrite(darktwo, HIGH);   
  delay(10);                      
  digitalWrite(darktwo, LOW);   
      }
      break;      

    case 'G': //flow the light pump
      for (x=0;x<100;x++){
      do_pump_light();
      }
      break;
    case 'T':
      do_far_right();
      digitalWrite(motoren,LOW); // disable
      break;
    }
  }

  // TEST CODE!
  
  //  Serial.print("darkness: ");
  //  Serial.print(darkness);
  //  Serial.print("\r\n");
  // darkness=1;
  //  delay(1000);
}


