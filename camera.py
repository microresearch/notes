from picamera import PiCamera
from time import sleep
from fractions import Fraction

camera = PiCamera(resolution=(1280, 720), framerate=Fraction(1, 6), sensor_mode=3)
camera.shutter_speed = 6000000
camera.iso = 800
sleep(60)
camera.exposure_mode = 'off'

try:
    for filename in camera.capture_continuous('/home/pi/augury/test/img{counter:03d}.jpg'):
        print('Captured %s' % filename)
        sleep(60) # wait 1 minute
        camera.exposure_mode = 'off'
finally:
    camera.close()
