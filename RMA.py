#!/usr/bin/env python2.7

# black hole plots a la ouroboric.py
# data from USRP in what form? what do we need to run to get say FFT data in a very simple format we can then parse?

### /usr/lib/uhd/examples/rx_ascii_art_dft --freq 1420e6 --rate 5e5 --gain 60 --bw 5e5 --ref-lvl -90

from datetime import date, datetime
from math import sin, cos, pi, asin, radians as rad,degrees as deg  
import ephem
import subprocess as sp
import time
from time import sleep
import numpy as np

mylocation = ephem.Observer()
mylocation.lat, mylocation.lon = '45.791196', '15.975645' # This is the location of the zagreb gallery!!! POGON Jedinstvo 45.791196, 15.975645

min_alt = ephem.degrees('10:00')

milkyway_visual = ephem.readdb("Milky Way Visual Center,f|M|F7,18:55:03.06,-30:28:42.30,3.00,2000")
milkyway_sagastar = ephem.readdb("Milky Way Black Hole (Sgr A*),f|M|F7,17:45:40.0409,-29:00:28.118,25.00,2000") # https://en.wikipedia.org/wiki/Sagittarius_A*
#milk = milkyway_sagastar
milk = milkyway_sagastar
sun = ephem.Sun()
moon = ephem.Moon()

while(1):
    tmp = sp.call('clear',shell=True) # clear screen

    print "                          Radio Mycelium Array(RMA)"
    print "                          +++++++++++++++++++++++++"
    print
    print "RMA: Symbiotic ur-networks of silent fungal and root chatter and earth vibration, named chemical\ngradients tasted by rooty and human tongues fruit forest-wide in fairy rings, rising up in form\nand outgrowing Jodrell bank and Arecibo, outclassing them unknown in bringing down the stars to earth."
    #    print time
    print

    mylocation.date = datetime.utcnow()# 
    milk.compute(mylocation)
    print "Milky Way Black Hole (Sgr A*):",
    print ephem.localtime(mylocation.date), deg(milk.az),deg(milk.alt)

    print
    print "ASTRA position: az/alt"
    # degrees is starting at 304 [wrap 360] to 124 (180
    # for back wall - for front window we do 120 to 300 say
    # !!!!we would need to figure this out from Zagreb gallery!!!
    # so facing North which is back wall...
    # NESW - so start in west and go to east = 180degrees from 270 to 90

    degg=deg(milk.az)
    if degg>90 and degg<270: # upto 300 - 180
        xcoord=int((degg-90)/2.25)
    else:
        xcoord=-1

    if deg(milk.alt)>0.0: 
        ycoord=np.ceil(deg(milk.alt)/9.0)
    else: 
        ycoord=-1 # below horizon
#    print xcoord,ycoord

    for y in range(10):
        print"|",
        if (10-ycoord)==y:
            if xcoord>0:
                for x in range(xcoord):
                    print "",
                print "*"
        else:
            print
    print"--------------------------------------------------------------------------------"
    print
    sleep(1)
