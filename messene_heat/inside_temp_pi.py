#!/usr/bin/python

# read in csv file monkxy and try to match the ranged temperatures or values in that file to cpu temp

# in this case we use reported cpu temp...

# we may need to overclock pi to reach high temps - NOTES:

# fan on pin 3 = GPIO pin 2

#The MIT License (MIT)
#
#Copyright (c) 2015 Stephen P. Smith
#
#Permission is hereby granted, free of charge, to any person obtaining a copy
#of this software and associated documentation files (the "Software"), to deal
#in the Software without restriction, including without limitation the rights
#to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#copies of the Software, and to permit persons to whom the Software is
#furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all
#copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#SOFTWARE.

import time, math, csv, serial, random
from subprocess import Popen, PIPE
import subprocess
#import numpy

def stress_cpu(num_cpus, time):
    subprocess.check_call(
        ["stress", "--cpu", str(num_cpus), "--timeout", "{}s".format(time)]
    )
    return

def coolit():
        time.sleep(1)
        
def get_cpu_temperature():
        """get cpu temperature using vcgencmd"""
        process = Popen(['vcgencmd', 'measure_temp'], stdout=PIPE)
        output, _error = process.communicate()
        return float(output[output.index('=') + 1:output.rindex("'")])
        
if __name__ == "__main__":

        realtemp=100
        desiredtemp=1000
        lowest=20000

        # file to write temps
        ffff = open('temp_follower_cpu', 'w')
        
        # read temperatures from logfile/csv
        scaler=[]

        with open('monkxy') as f:
                reader = csv.reader(f)
                for row in reader:
                        scaler.append(int(row[1])) # first row to test...
 
        # and we should also turn the fan on for this period and measurement
        print "Waiting 10 seconds to reach stable temp"
        #        time.sleep(10) # to reach usual temp maybe
        x=0
        while (x<100): # read 100 values
                time.sleep(0.1)
                tt=get_cpu_temperature()
                myData=tt*10
                print tt,myData
                if int(myData)<lowest and x>0:
                        lowest=int(myData)                                                        
                x+=1
                                        
        # start with lowest temperature - this will be our zero
        print "Lowest: ", lowest
        
        # how hot can we go? we need to measure this beforehand...
        # so our range is 0->let's say 80
        maxed=800
        ourscaler=(maxed-lowest)/255.0
        print "scaled", ourscaler
        countd=0
        
        for temps in scaler: # show how many values we have read so far
	        # tempC = max.readTemp()
                # print tempC
                desiredtemp=temps*ourscaler
                # read value from array representing temperature adjusted/scaled from 0->255
                # adjust this to our new scale and get desired temperature
                while (abs(desiredtemp-realtemp)>4):
                        myData=get_cpu_temperature()*10
                        realtemp=int(myData)-lowest
                        # also get cpu temp to compare...
                        cputemp=get_cpu_temperature()
                        print "cpu", cputemp, "temp", int(myData), "realtemp", realtemp, "des", temps, "desired", desiredtemp;
                        # record int(mydata)/100 to file
                        ffff.write(str(float(myData)/10.0) + '\n')
                        # are we there - if we are too high turn on fan, if too low run sqrt
                        if (desiredtemp<realtemp):
                                time.sleep(1)
                        elif (desiredtemp>realtemp):
                                if (abs(desiredtemp-realtemp)>32):
                                        stress_cpu(8, time=1)
                                elif (abs(desiredtemp-realtemp)<16):
                                        stress_cpu(3, time=1)
                                else:
                                        stress_cpu(6, time=1)
                print "HIT:", desiredtemp, "Count:", countd
                countd+=1
