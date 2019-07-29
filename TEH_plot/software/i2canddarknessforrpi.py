import smbus
import time
import picamera
import numpy as np

# i2c setup

# for RPI version 1, use bus = smbus.SMBus(0)
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04
gpio.setmode(gpio.BCM) # added?

def writeNumber(value):
    bus.write_byte(address, value)
# bus.write_byte_data(address, 0, value)
    return -1


width = 64
height = 64
fwidth = (width + 31) // 32 * 32 # all the same - rounds it!
fheight = (height + 15) // 16 * 16
# Capture the image in YUV format
with picamera.PiCamera() as camera:
    camera.resolution = (width, height)
    while(1):
        stream = open('image.data', 'w+b')
        camera.start_preview()
#    time.sleep(2)
        camera.capture(stream, 'yuv')
# Rewind the stream for reading
        stream.seek(0)
# Calculate the actual image size in the stream (accounting for rounding
# of the resolution)
# Load the Y (luminance) data from the stream
        Y = np.fromfile(stream, dtype=np.uint8, count=fwidth*fheight)
        total=0;
        for xx in Y:
            total += xx
        total=total/4096
        print "DARKNESS", total
        # send darkness to i2c/arduino
        writeNumber(total)
