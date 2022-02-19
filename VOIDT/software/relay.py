import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM) # GPIO Numbers instead of board numbers
 
RELAIS_1_GPIO = 17
GPIO.setup(RELAIS_1_GPIO, GPIO.OUT) # GPIO Assign mode

GPIO.output(RELAIS_1_GPIO, GPIO.LOW) # out
time.sleep(1)
GPIO.output(RELAIS_1_GPIO, GPIO.HIGH) # on
time.sleep(1)
GPIO.output(RELAIS_1_GPIO, GPIO.LOW) # out
time.sleep(1)
GPIO.output(RELAIS_1_GPIO, GPIO.HIGH) # on
