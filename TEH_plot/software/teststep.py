import sys
import argparse
from pprint import pprint
import time
from time import sleep
import os
import serial

# where is arduino on serial?  pass as argument
parser = argparse.ArgumentParser(description="serial")
# add expected arguments
parser.add_argument('--port', dest='port', required=True)
args = parser.parse_args()
ser = serial.Serial(args.port, 9600,    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
timeout=1)
sleep(3)
commando="o"

while(1):
    ser.flushOutput()
    ser.flushInput()
#        print "H: hit? Q: darkness? P: far left T: far right W: write E: erase L: left R: right M: middle F: flow the dpumps G: flow the lpump 1: dark1 2: dark2"

    ser.write("P") # far left
    sleep(10)
    for x in range(34):
        ser.write("R") # right
        sleep(2)
        
