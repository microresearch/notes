# start with simple control of heat - testingsDONE
# next test reading temperature

import sys
import argparse
from pprint import pprint
import numpy as np
import ephem
import datetime
import random
from math import sin, cos, pi, asin, radians as rad,degrees as deg  
import time
from time import sleep
import os
import logging
import serial
import subprocess as sp

# where is arduino on serial?  pass as argument
parser = argparse.ArgumentParser(description="serial")
# add expected arguments
parser.add_argument('--port', dest='port', required=True)
args = parser.parse_args()
ser = serial.Serial(args.port, 115200,    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
timeout=1)

sleep(2)

def heater(heaty):
        ser.flushOutput()
        ser.flushInput()
        ser.write("w\n") # heat
        ser.write(str(heaty)+"\n")
        try:
            line = ser.readline()
            print line
        except KeyboardInterrupt:
            print('exiting')
            exit()

def gettemp():
    ser.flushOutput()
    ser.flushInput()
    ser.write("t\n") # temperature
    try:
        line = ser.readline()
        #print line
        xx=float(line)
        #        print(xx)
        # next step read into a variable and test scaled heat write
    except KeyboardInterrupt:
        print('exiting')
        exit()
    return xx

# commands: t read temp -> float, w newline and value(<255) newline to set heat
while(1):
    #    for x in range(255): 
    #    heater(x)

    xx=gettemp()
    print(xx)
    ht=int(xx*10)
    heater(ht)
