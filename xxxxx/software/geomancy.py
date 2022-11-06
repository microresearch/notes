## basic geomancy from TEH/ouroboric to expand for use in caput draconis/aka. heavens\
# 
# in previous we had 0 and 1 reversed: so now 1 dot/odd whould be 1=active and 2 dots/even should be 0=passive
# and we add them with an XOR (not with !XOR)

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

# fix for 2 dots=0, 1 dot=1

# dict for figures
figdict={'1101': ['Puer','Mars','Fire','Aries','+','Boy, yellow, beardless'], '1010': ['Amissio','Venus','Earth','Taurus','-','Loss, comprehended without'], '0010': ['Albus','Mercury','Air','Gemini','-','White, fair'], '0000': ['Populus','Moon','Water','Cancer','-','People, congregation'], '0011': ['Fortuna Major','Sun','Fire','Leo','+','Greater fortune, greater aid,safeguard entering'], '0110': ['Conjunctio','Mercury','Earth','Virgo','+','Conjunction, assembling'], '1011': ['Puella','Venus','Air','Libra','+','A girl, beautiful'], '0100': ['Rubeus','Mars','Water','Scorpio','-','Red, reddish'], '0101': ['Acquisitio','Jupiter','Fire','Sagitarrius','+','Obtaining, comprehending without'], '1001': ['Carcer','Saturn','Earth','Capricorn','+','A prison, bound'], '0001': ['Tristitia','Saturn','Air','Aquarius','-','Sadness, damned, cross'], '1000': ['Laetitia','Jupiter','Water','Pisces','-','Joy, laughing, healthy, bearded'], '1110': ['Cauda Draconis','Saturn & Mars','Fire','Scorpio','-','The threshold lower, or going out'], '0111': ['Caput Draconis',' Jupiter & Venus','Earth','Capricorn','+','The Head, the threshold entering, the upper threshold'], '1100': ['Fortuna Minor','Sun','Fire','Leo','-','Lesser Fortune, lesser aid, safeguard going out'], '1111': ['Via','Moon','Water','Cancer','+','Way, journey']}

roman=['0','I','II','III','IV','V','VI','VII','VIII','IX','X','XI','XII','XIII','XIV','XV','XVI']

#mapped to Crowley
crowley=['0','X','I','IV','VII','XI','II','V','VIII','XII','III','VI','IX','XIII','XIV','XV','XVI']

def inttodot(integer):
    """
    Convert an integer to divination dots, two dots if the integer
    is even, one if odd, two if zero

    Takes an integer argument, returns a string of two dotchars or
    one

    """
    dotchar = "*"
    if integer % 2 == 0:
        dot = dotchar * 2
    else:
        dot = dotchar + " "  # The addition of a space helps the
                             # final diagram line up

    return dot

def oddoreven(integer):
    if integer % 2 == 0:
        dot = 0
    else:
        dot = 1
    return dot
    
def domothers():
    """ Append binary representation 0 as O/odd, 1 as OO/even - now reversed
    """
    motherlist=[]
    for x in range(4): 
        binrep=[]
        for body in range(4): 
            binrep.append(oddoreven(darknn[(x*4)+body]))
        motherlist.append(binrep)
#    print motherlist
    return motherlist

def dodaughters(motherlist):
    daughterlist=[]
    body=zip(*motherlist)
    for parts in body:
        daughterlist.append(parts)
    return daughterlist

def madd(x,y):
    return int(x ^ y) # was NOT as we had it reversed   

def donephews(mlist,dlist):
    nlist=[]
    nlist.append([madd(mlist[0][0],mlist[1][0]),madd(mlist[0][1],mlist[1][1]),madd(mlist[0][2],mlist[1][2]),madd(mlist[0][3],mlist[1][3])])
    nlist.append([madd(mlist[2][0],mlist[3][0]),madd(mlist[2][1],mlist[3][1]),madd(mlist[2][2],mlist[3][2]),madd(mlist[2][3],mlist[3][3])])
    nlist.append([madd(dlist[0][0],dlist[1][0]),madd(dlist[0][1],dlist[1][1]),madd(dlist[0][2],dlist[1][2]),madd(dlist[0][3],dlist[1][3])])
    nlist.append([madd(dlist[2][0],dlist[3][0]),madd(dlist[2][1],dlist[3][1]),madd(dlist[2][2],dlist[3][2]),madd(dlist[2][3],dlist[3][3])])
    return nlist

def dowitnesses(nlist):
    wlist=[]
    wlist.append([madd(nlist[0][0],nlist[1][0]),madd(nlist[0][1],nlist[1][1]),madd(nlist[0][2],nlist[1][2]),madd(nlist[0][3],nlist[1][3])])
    wlist.append([madd(nlist[2][0],nlist[3][0]),madd(nlist[2][1],nlist[3][1]),madd(nlist[2][2],nlist[3][2]),madd(nlist[2][3],nlist[3][3])])
    return wlist

def dojudge(wlist):
    jlist=[]
    jlist.append([madd(wlist[0][0],wlist[1][0]),madd(wlist[0][1],wlist[1][1]),madd(wlist[0][2],wlist[1][2]),madd(wlist[0][3],wlist[1][3])])
    return jlist

def dorec(jlist,mlist):
    rlist=[]
    rlist.append([madd(mlist[0][0],jlist[0][0]),madd(mlist[0][1],jlist[0][1]),madd(mlist[0][2],jlist[0][2]),madd(mlist[0][3],jlist[0][3])])
    return rlist

def drawit(listere):
    """ run thru list and print whole list line by line"""
    # must reverse listy
    listy=list(listere)
    listy.reverse()
    body=zip(*listy)
    for parts in body:
        for part in parts:
            if part==0:
                print "        O O   ",
            else:
                print "         O    ",
        print

numeral=0

def drawfig(body):
    for part in body:
        if part==0:
            print "        O O   ",
        else:
            print "         O    ",
        print

def drawfig2(body):
    for x in range(4):
        if body[x]=="0":
            print "        O O   ",
        else:
            print "         O    ",
        print
        

def lookfig(figure):
    # convert list to string
    key=''.join(str(e) for e in figure)
#    return (' '.join((roman[numeral]+". GD:",crowley[numeral]+".",figdict[key][0],figdict[key][2],figdict[key][5])))
    return (' '.join((figdict[key][0],": ",figdict[key][2],figdict[key][5],figdict[key][4])))

darknn=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
count=0
ready=1
darkness=0

# 16 values for darkness - was from dark/light of previous code..
for x in range(16): 
    darknn[x]=random.randint(0,256)

for x in range(16):
#chosen=next(iter(figdict))
    chosen = list(figdict.keys())[x]
    print lookfig(chosen)
    print chosen
    drawfig2(chosen)
    print

# test now adding of figures

mlist=domothers()
dlist=dodaughters(mlist)
nlist=donephews(mlist, dlist)
print mlist
print dlist
print nlist
#print "House = VIII. Death/Mortis - The House of Slaughter and Death: Heaviness, sadness, enemies, long torments, imprisonment, and the quality of death."
#print
# take the fourth daughter and explain/display this
#chosen=dlist[3] # check: for crowley 4th daughter is in 8th house
#print chosen
#print lookfig(chosen) # TODO: clean up a bit but works
#drawfig(chosen)
