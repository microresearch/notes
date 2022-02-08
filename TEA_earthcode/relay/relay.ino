// Pins 4, 5, 6, and 7 control relays 4, 3, 2, and 1 respectively.

int earthboot = 4;
int hepa = 5;
int fog1 = 6;
int fog2 = 7;

// 4 is earthboot
// 3 is HEPA fan
// 2 is fogger1
// 1 is fogger2


unsigned long minutes = 60000;

void setup() {
  
  pinMode(fog1, OUTPUT); 
  pinMode(fog2, OUTPUT);
  pinMode(hepa, OUTPUT);
  pinMode(earthboot, OUTPUT); // not used
}

void loop() {
  int x, y, xx, yy;

  //  digitalWrite(fog1,HIGH); // both on for testing
  //  digitalWrite(fog2,HIGH); 

  
  // timing for HEPA ? or we leave HEPA fan off always...
  
  // both foggers on: - on for 10 minutes every hour
  digitalWrite(fog1,HIGH); 
  digitalWrite(fog2,HIGH); 
  
  for (xx=0; xx<5; xx++){
  // earthboot device reboot every 2 minutes
  digitalWrite(earthboot,HIGH); // on two minutes - NO is ON! but is 1 seconds x 120 = 2 minutes
  for (x=0;x<120;x++)  delay(1000);
 digitalWrite(earthboot,LOW); 
 delay(1000); // reboot
  }//5 so 10 minutes

  // both foggers off for 60-10=50 minutes
  
  digitalWrite(fog1,LOW); 
  digitalWrite(fog2,LOW); 

  for (xx=0; xx<25;xx++){
  // earthboot device reboot every 2 minutes
  digitalWrite(earthboot,HIGH); // on two minutes - NO is ON!
  for (x=0;x<120;x++)  delay(1000);
 digitalWrite(earthboot,LOW); 
 delay(1000); // reboot
  }//25 so 50 minutes
    
  }//loopy