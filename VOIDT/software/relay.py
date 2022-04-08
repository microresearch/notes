import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM) # GPIO Numbers instead of board numbers
 
RELAIS_1_GPIO = 17
GPIO.setup(RELAIS_1_GPIO, GPIO.OUT) # GPIO Assign mode

GPIO.output(RELAIS_1_GPIO, GPIO.LOW) # off
time.sleep(1)

# test different timings!

while True:
    delb=input("DELAY!")
    
    GPIO.output(RELAIS_1_GPIO, GPIO.HIGH) # on RELEASE
    time.sleep(delb) # nanosleep is only in c code
    GPIO.output(RELAIS_1_GPIO, GPIO.LOW) # off
    #time.sleep(2)

