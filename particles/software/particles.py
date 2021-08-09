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

# add in extra commands!

# // commands: T, U, V to show temperature
# // W to write integer to analogwrite pin 3, E to write pin 10
# // Z, X: on off relay1 pin 7:
# // A, S: on off relay2 pin 6:

def relay1on():
        ser.flushOutput()
        ser.flushInput()
        ser.write("z\n") 

def relay1off():
        ser.flushOutput()
        ser.flushInput()
        ser.write("x\n") 

def relay2on():
        ser.flushOutput()
        ser.flushInput()
        ser.write("a\n") 

def relay2off():
        ser.flushOutput()
        ser.flushInput()
        ser.write("s\n") 
        
def pwm1(heaty):
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
            
def pwm2(heaty):
        ser.flushOutput()
        ser.flushInput()
        ser.write("e\n") # heat
        ser.write(str(heaty)+"\n")
        try:
            line = ser.readline()
            print line
        except KeyboardInterrupt:
            print('exiting')
            exit()
            
def gettemp1():
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

def gettemp2():
    ser.flushOutput()
    ser.flushInput()
    ser.write("u\n") # temperature
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

def gettemp3():
    ser.flushOutput()
    ser.flushInput()
    ser.write("v\n") # temperature
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

while(1):
    #    for x in range(255): 
    #    heater(x)

    xx=gettemp()
    print(xx)
    ht=int(xx*10)
    pwm1(ht)
