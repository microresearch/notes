#!/usr/bin/python
'''
Taking constellation, star plotting from T.E.H just as a starting point for further investigations...

'''

from datetime import datetime, timedelta
from math import sin, cos, pi, asin, radians as rad, degrees as deg  
import numpy as np
from time import sleep
from operator import mod
import ephem
import subprocess as sp


g = ephem.Observer()  
g.name='DISS'  
#g.lat='53.469616'  #Holden Gallery
#g.long='-2.238067'
g.lat='52.52' # BERLIN!
g.long='13.45'
g.horizon=0
g.elevation=43

sun = ephem.Sun()
moon = ephem.Moon()  
reg= ephem.star("Regulus")
corvus= ephem.star("Gienah Corvi")
degrees_per_radian = 180.0 / pi

        # planet calculations and plots

while(1):
    tmp = sp.call('clear',shell=True)
    g.date = datetime.utcnow()# 
    reg.compute(g)
    print "REGULUS: az/alt",
    print ephem.localtime(g.date), deg(reg.az),deg(reg.alt)

    corvus.compute(g)
    print "CORVUS - Gienah Corvi: az/alt",
    print ephem.localtime(g.date), deg(corvus.az),deg(corvus.alt) # wrong localtime is set here on laptop - IGNORE!

    # plot the planets...
    # we have altitude and azimuth - horizon [------------------------] where to where? orient to 0 north in PDS
    # say 80 lines across for azimuth = round 360/80=/4.5 but we just want 180 = /9
    # say 10 lines for altitude (range 0to90) = /2.25

    # REGULUS - check/TEST!
    print
    print "REGULUS position: az/alt"
    # degrees is starting at 304 [wrap 360] to 124 (180
    # for back wall - for front window we do 120 to 300 say

    # change this for generic instance here - say start at 0 degrees and plot full 360
    # Az 0 is north
    
    degg=deg(reg.az)
    xcoord=int(degg)

    if deg(reg.alt)>0.0: 
        ycoord=np.ceil(deg(reg.alt)/9.0)
    else: 
        ycoord=-1 # below horizon

    print xcoord,ycoord

    
    for y in range(10):
        print"|",
        if (10-ycoord)==y and xcoord>0:
            for x in range(xcoord/2):
                print "",
            print "O"
        else:
            print
    print"N---------------------------------------------E--------------------------------------------S-------------------------------------------W---------------------------------------------"
    print
    print "CORVUS - Gienah Corvi position: az/alt"
    # same as above
    degg=deg(corvus.az)
    xcoord=int(degg)
    
    if deg(corvus.alt)>0.0: 
        ycoord=np.ceil(deg(corvus.alt)/9.0)
    else: 
        ycoord=-1 # below horizon
    print xcoord,ycoord

    for y in range(10):
        print"|",
        if (10-ycoord)==y:
            if xcoord>0:
                for x in range(xcoord/2):
                    print "",
                print "O"
        else:
            print
    print"N---------------------------------------------E--------------------------------------------S-------------------------------------------W---------------------------------------------"
    print

    # Planet-light HOW? 
    # this was code for cdrom tray as obscuring light! which could also be re-used

    # if is above horizon in our 180 degrees then move according to...
    # arduino commands: move up/darken =N, down/lighten=n, zero=Z
    # note that DOWN is more LIGHT

    # test code with the sun!
    sun.compute(g)
    moon.compute(g)

    # divide degrees of corvus to extent which is 170 - extent is depending ON VOLTAGE!
    # this is position we need to get to (inverted) 170-cdrompos
    # if we run to zero then do this as explicit Z
    # TODO: was corvus
    if deg(sun.alt)>0.0: 
        wherepos=200-(np.ceil(deg(sun.alt)*6.0)) # 30 degrees and we 200 incs
    else:
        wherepos=200

    # go there
    print "SUN alt:", deg(sun.alt), 
    print "MOON alt:", deg(moon.alt) 
#    wherepos=200

    # if wherepos==0:
    #     ser.write("Z")
    #     cdrompos=0

    # while wherepos>cdrompos:
    #     ser.write("N")
    #     cdrompos+=1

    # while wherepos<cdrompos:
    #     ser.write("n")
    #     cdrompos-=1
    sleep(2)

