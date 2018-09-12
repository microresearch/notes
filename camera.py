from picamera import PiCamera
from time import sleep
from fractions import Fraction

# Force sensor mode 3 (the long exposure mode), set
# the framerate to 1/6fps, the shutter speed to 6s,
# and ISO to 800 (for maximum gain)
camera = PiCamera(resolution=(1280, 720), framerate=Fraction(1, 6), sensor_mode=3)
camera.shutter_speed = 6000000
camera.iso = 800
# Give the camera a good long time to set gains and
# measure AWB (you may wish to use fixed AWB instead)

sleep(60)
camera.exposure_mode = 'off'

try:
    for filename in camera.capture_continuous('/home/pi/augury/test/img{counter:03d}.jpg'):
        print('Captured %s' % filename)
        sleep(60) # wait 1 minute
        camera.exposure_mode = 'off'
finally:
    camera.close()
