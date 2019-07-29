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
    # list of commands

    print "H: hit? Q: darkness? P: far left T: far right W: write E: erase L: left R: right M: middle F: flow the dpumps G: flow the lpump 1: dark1 2: dark2"
    
    # read keyboard, send command letter, recieve and print response
    commando = raw_input("Command? ")
    ser.flushOutput()
    ser.flushInput()
    ser.write(commando)
    sleep(.1)
    try:
        line = ser.readline()
        data = [val for val in line.split()]
    except KeyboardInterrupt:
        print('exiting')

    # if data is longer than 1
    if len(data)>0:
        print "RESPONSE: ",
        print data
        if data[0]=='R' or data[0]=='L':
            print "RESET"
