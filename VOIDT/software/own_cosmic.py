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
    GPIO.output(RELAIS_1_GPIO, GPIO.LOW) # on
    time.sleep(0.5) # test
    GPIO.output(RELAIS_1_GPIO, GPIO.HIGH) # off

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

try:
        while True:
                data = ComPort.readline()    # Wait and read data
                counter=counter+1
                if counter>10:
                        thread = threading.Thread(target=relay)
                        thread.start()
                        file.write(str(datetime.now())+" "+data)    
                        print(str(datetime.now())+" "+data)
finally:    
        ComPort.close()     
        file.close()  
