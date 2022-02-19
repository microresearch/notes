# starting from first cosmic watch import_signal.py
# record to time/date file in /home/pi
# flash/toggle led on each hit

# for pi//testings:  scp own_cosmic.py pi@192.168.1.24:/home/pi

# further test with relay

import serial 
import time
import glob
import sys
import signal
import os
import RPi.GPIO as GPIO
import threading

from datetime import datetime
from multiprocessing import Process
def signal_handler(signal, frame):
        print('You pressed Ctrl+C!')
        ComPort.close()     
        file.close() 
        sys.exit(0)

def relay():
    GPIO.output(RELAIS_1_GPIO, GPIO.HIGH) # on
    time.sleep(0.5) # test with half second on
    GPIO.output(RELAIS_1_GPIO, GPIO.LOW) # off

os.system('echo none > /sys/class/leds/led0/trigger')

def brightness_on():
    os.system("echo 1 > /sys/class/leds/led0/brightness")

def brightness_off():
    os.system("echo 0 > /sys/class/leds/led0/brightness")

GPIO.setmode(GPIO.BCM) # GPIO Numbers instead of board numbers
RELAIS_1_GPIO = 17 # pin 11 = GPIO17
GPIO.setup(RELAIS_1_GPIO, GPIO.OUT) # GPIO Assign mode

timestr = time.strftime("%Y%m%d-%H%M%S")
fname = "/home/pi/"+timestr+".txt"
id = "xxxxx"
print("Taking data ...")
print("Press ctl+c to terminate process")

signal.signal(signal.SIGINT, signal_handler)
ComPort = serial.Serial('/dev/ttyUSB0') 

ComPort.baudrate = 9600          # set Baud rate
ComPort.bytesize = 8             # Number of data bits = 8
ComPort.parity   = 'N'           # No parity
ComPort.stopbits = 1    

file = open(fname, "w",0)

counter = 0

tog=0; cycler=0;

while True:
    data = ComPort.readline()    # Wait and read data
    # toggle green led / do relay maybe...
    # if another ray hits whilst is still open then stays open
    # how to start relay as blocks now with readline and we want to time relay - threading...
    thread = threading.Thread(target=relay)
    thread.start()
    
    tog=tog^1
    if tog==1:
        brightness_on()
    else:
        brightness_off()
    file.write(str(datetime.now())+" "+data)    
ComPort.close()     
file.close()  
