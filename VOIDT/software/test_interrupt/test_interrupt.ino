/*
options: update location in main loop (if that works for heatmap
clusters?), signal write from interrupt->main (turn off interrupt in
write, can write old GPS pos if not updated)

towards new code

 */

//const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
unsigned long last_time= 0L;
unsigned long this_time= 0L;


#define SerialMonitor Serial


void setup() {
  //  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), cosmic, RISING);
  SerialMonitor.begin(9600);
  SerialMonitor.println("Starts.");
}

void loop() {
  //  digitalWrite(ledPin, state);
  if (state==1){
    noInterrupts();
    state=0;
    // log time from last hit to this one - seems to work just need to add GPS business...
    SerialMonitor.println(this_time-last_time);    
    interrupts();
  }
}

void cosmic() {
    last_time=this_time;  
  this_time=millis();
    state = 1;  
}
