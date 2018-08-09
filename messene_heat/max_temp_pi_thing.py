#!/usr/bin/python

# read in csv file monkxy and try to match the ranged temperatures or values in that file to cpu temp
# cpu temp is measured by arduino and max31865 to avoid taxing the cpu
# but we keep max code here for reference

# UNTESTED
# we may need to overclock pi to reach high temps

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
import RPi.GPIO as GPIO
from subprocess import Popen, PIPE
import subprocess
#import numpy

FANPIN = 2

class max31865(object):
	"""Reading Temperature from the MAX31865 with GPIO using 
	   the Raspberry Pi.  Any pins can be used.
	   Numpy can be used to completely solve the Callendar-Van Dusen equation 
	   but it slows the temp reading down.  I commented it out in the code.  
	   Both the quadratic formula using Callendar-Van Dusen equation (ignoring the
	   3rd and 4th degree parts of the polynomial) and the straight line approx.
	   temperature is calculated with the quadratic formula one being the most accurate.
	"""
	def __init__(self, csPin = 8, misoPin = 9, mosiPin = 10, clkPin = 11):
		self.csPin = csPin
		self.misoPin = misoPin
		self.mosiPin = mosiPin
		self.clkPin = clkPin
		self.setupGPIO()
		
	def setupGPIO(self):
		GPIO.setwarnings(False)
		GPIO.setmode(GPIO.BCM)
		GPIO.setup(self.csPin, GPIO.OUT)
		GPIO.setup(self.misoPin, GPIO.IN)
		GPIO.setup(self.mosiPin, GPIO.OUT)
		GPIO.setup(self.clkPin, GPIO.OUT)

		GPIO.output(self.csPin, GPIO.HIGH)
		GPIO.output(self.clkPin, GPIO.LOW)
		GPIO.output(self.mosiPin, GPIO.LOW)

	def readTemp(self):
		#
		# b10000000 = 0x80
		# 0x8x to specify 'write register value'
		# 0xx0 to specify 'configuration register'
		#
		# 0b10110010 = 0xB2
		# Config Register
		# ---------------
		# bit 7: Vbias -> 1 (ON)
		# bit 6: Conversion Mode -> 0 (MANUAL)
		# bit5: 1-shot ->1 (ON)
		# bit4: 3-wire select -> 1 (3 wire config)
		# bits 3-2: fault detection cycle -> 0 (none)
		# bit 1: fault status clear -> 1 (clear any fault)
		# bit 0: 50/60 Hz filter select -> 0 (60Hz)
		#
		# 0b11010010 or 0xD2 for continuous auto conversion 
		# at 60Hz (faster conversion)
		#

		#one shot
		self.writeRegister(0, 0xa2) # was b2

		# conversion time is less than 100ms
		time.sleep(.065) #give it 100ms for conversion - reduced

		# read all registers
		out = self.readRegisters(0,8)

		conf_reg = out[0]
		print "config register byte: %x" % conf_reg

		[rtd_msb, rtd_lsb] = [out[1], out[2]]
		rtd_ADC_Code = (( rtd_msb << 8 ) | rtd_lsb ) >> 1
			
		temp_C = self.calcPT100Temp(rtd_ADC_Code)

		[hft_msb, hft_lsb] = [out[3], out[4]]
		hft = (( hft_msb << 8 ) | hft_lsb ) >> 1
		print "high fault threshold: %d" % hft

		[lft_msb, lft_lsb] = [out[5], out[6]]
		lft = (( lft_msb << 8 ) | lft_lsb ) >> 1
		print "low fault threshold: %d" % lft

		status = out[7]
		#
		# 10 Mohm resistor is on breakout board to help
		# detect cable faults
		# bit 7: RTD High Threshold / cable fault open 
		# bit 6: RTD Low Threshold / cable fault short
		# bit 5: REFIN- > 0.85 x VBias -> must be requested
		# bit 4: REFIN- < 0.85 x VBias (FORCE- open) -> must be requested
		# bit 3: RTDIN- < 0.85 x VBias (FORCE- open) -> must be requested
		# bit 2: Overvoltage / undervoltage fault
		# bits 1,0 don't care	
		#print "Status byte: %x" % status

		if ((status & 0x80) == 1):
			raise FaultError("High threshold limit (Cable fault/open)")
		if ((status & 0x40) == 1):
			raise FaultError("Low threshold limit (Cable fault/short)")
		if ((status & 0x04) == 1):
			raise FaultError("Overvoltage or Undervoltage Error") 
		
	def writeRegister(self, regNum, dataByte):
		GPIO.output(self.csPin, GPIO.LOW)
		
		# 0x8x to specify 'write register value'
		addressByte = 0x80 | regNum;
		
		# first byte is address byte
		self.sendByte(addressByte)
		# the rest are data bytes
		self.sendByte(dataByte)

		GPIO.output(self.csPin, GPIO.HIGH)
		
	def readRegisters(self, regNumStart, numRegisters):
		out = []
		GPIO.output(self.csPin, GPIO.LOW)
		
		# 0x to specify 'read register value'
		self.sendByte(regNumStart)
		
		for byte in range(numRegisters):	
			data = self.recvByte()
			out.append(data)

		GPIO.output(self.csPin, GPIO.HIGH)
		return out

	def sendByte(self,byte):
		for bit in range(8):
			GPIO.output(self.clkPin, GPIO.HIGH)
			if (byte & 0x80):
				GPIO.output(self.mosiPin, GPIO.HIGH)
			else:
				GPIO.output(self.mosiPin, GPIO.LOW)
			byte <<= 1
			GPIO.output(self.clkPin, GPIO.LOW)

	def recvByte(self):
		byte = 0x00
		for bit in range(8):
			GPIO.output(self.clkPin, GPIO.HIGH)
			byte <<= 1
			if GPIO.input(self.misoPin):
				byte |= 0x1
			GPIO.output(self.clkPin, GPIO.LOW)
		return byte	
	
	def calcPT100Temp(self, RTD_ADC_Code):
		R_REF = 400.0 # Reference Resistor
		Res0 = 100.0; # Resistance at 0 degC for 400ohm R_Ref
		a = .00390830
		b = -.000000577500
                Res_RTD = (RTD_ADC_Code * R_REF) / 32768.0 # PT100 Resistance
		temp_C = -(a*Res0) + math.sqrt(a*a*Res0*Res0 - 4*(b*Res0)*(Res0 - Res_RTD))
		temp_C = temp_C / (2*(b*Res0))
		return temp_C

# try from adafruit as we get funky values from the above

	def calcPT100Temp(self, RTD_ADC_Code):
                RTD_A=3.9083e-3
                RTD_B=-5.775e-7
                refResistor=100.0
                Rt = Res_RTD
                Rt /= 32768.0
                Rt *= refResistor
                Z1 = -RTD_A
                Z2 = RTD_A * RTD_A - (4 * RTD_B)
                Z3 = (4 * RTD_B) / RTDnominal
                Z4 = 2 * RTD_B

                temp_C = Z2 + (Z3 * Rt)
                temp_C = (math.sqrt(temp) + Z1) / Z4;
                
                
class FaultError(Exception):
	pass

def stress_cpu(num_cpus, time):
    subprocess.check_call(
        ["stress", "--cpu", str(num_cpus), "--timeout", "{}s".format(time)]
    )
    return

def coolit():
        # run the fan controlled by pin xx
        GPIO.output(FANPIN, GPIO.LOW)
        time.sleep(1)
        
def get_cpu_temperature():
        """get cpu temperature using vcgencmd"""
        process = Popen(['vcgencmd', 'measure_temp'], stdout=PIPE)
        output, _error = process.communicate()
        return float(output[output.index('=') + 1:output.rindex("'")])
        
if __name__ == "__main__":

        
        #	import max31865
        realtemp=100
        desiredtemp=1000
        lowest=20000
	csPin = 8
	misoPin = 9
	mosiPin = 10
	clkPin = 11
        #	max = max31865.max31865(csPin,misoPin,mosiPin,clkPin)
        arduinoSerial = serial.Serial('/dev/ttyACM0',115200)

        # set up fan on pin 3 / GPIO 2
        GPIO.setwarnings(False)
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(FANPIN, GPIO.OUT)
        # file to write temps
        ffff = open('temp_follower', 'w')
        
        # read temperatures from logfile/csv
        scaler=[]

        with open('monkxy') as f:
                reader = csv.reader(f)
                for row in reader:
                        scaler.append(int(row[1])) # first row to test...
 
        # and we should also turn the fan on for this period and measurement
        print "Waiting 10 seconds to reach stable temp"
        coolit()
        time.sleep(10) # to reach usual temp maybe
        x=0
        while (x<100): # read 100 values
                arduinoSerial.write("O")
                time.sleep(0.1)
                if(arduinoSerial.inWaiting()>0):
                        myData = arduinoSerial.readline() # temp will be *100 so int - how much accuracy?
                        try:
                                int(myData)
                                print int(myData)
                                if int(myData)<lowest and x>0:
                                        lowest=int(myData)                                                        
                                x+=1
                        except:
                                print "xx"
                                        
        # start with lowest temperature - this will be our zero
        print "Lowest: ", lowest
        
        # how hot can we go? we need to measure this beforehand...
        # so our range is 0->let's say 80
        maxed=8000
        ourscaler=(maxed-lowest)/255
        countd=0
        
        for temps in scaler: # show how many values we have read so far
	        # tempC = max.readTemp()
                # print tempC
                desiredtemp=temps*ourscaler
                # read value from array representing temperature adjusted/scaled from 0->255
                # adjust this to our new scale and get desired temperature
                while (abs(desiredtemp-realtemp)>4):
                        # we need to request from arduino
                        arduinoSerial.write("O")
                        time.sleep(0.1)
                        if(arduinoSerial.inWaiting()>0):
                                myData = arduinoSerial.readline()
                                try:
                                        if int(myData)>1000:
                                                realtemp=int(myData)-lowest
                                                # also get cpu temp to compare...
                                                cputemp=get_cpu_temperature()
                                                print "cpu", cputemp, "temp", int(myData), "realtemp", realtemp, "desired", desiredtemp;
                                                # record int(mydata)/100 to file
                                                ffff.write(str(float(myData)/100.0) + '\n')
                                                # are we there - if we are too high turn on fan, if too low run sqrt
                                                if (desiredtemp<realtemp):
                                                        #coolit() # add delay of 1 too coolit
                                                        if (abs(desiredtemp-realtemp)<16):
                                                                GPIO.output(FANPIN, GPIO.HIGH)
                                                                stress_cpu(3, time=1)
                                                        else:
                                                                time.sleep(1)
                                                elif (desiredtemp>realtemp):
                                                        GPIO.output(FANPIN, GPIO.HIGH)
                                                        if (abs(desiredtemp-realtemp)<16):
                                                                stress_cpu(3, time=1)
                                                        else:
                                                                stress_cpu(4, time=1)
                                except:
                                        print "error state"
                print "HIT:", desiredtemp, "Count:", countd
                countd+=1
                # just realized that we run sqrt/temp calc will change temperature anyways in feedback loop
                # so we need to outsource to arduino and get from serial!
                # but we could use for feedback temperature // output also on serial > FET/arduino
                # sqrt thing - not so successful
                # for x in range(10000):
                #         tobe=random.random()
                #         tobee=random.random()
                #         xx=math.sqrt(tobe**tobee)


                
        GPIO.cleanup()
