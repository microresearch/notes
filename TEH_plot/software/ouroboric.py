# Geomantic ouroboric Python software runs // pair with arduino i2cwithpi

# slow down everything

# python ouroboric.py --port /dev/ttyUSB0

# This should be latest one from Zagreb Dec 2019: size=21478

# // CHANGES for Manchester, Holden Gallery...

# check if TM repeatedly hits the end in which case we need to
# re-start... (we would need to signal this fact from the arduino
# where it hits one switch)

# more calibration/care for light and dark settings?

# ///////////////////////////////////////////////////////////////////////////////////////////////

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

# dict for figures
figdict={'0010': ['Puer','Mars','Fire','Aries','+','Boy, yellow, beardless'], '0101': ['Amissio','Venus','Earth','Taurus','-','Loss, comprehended without'], '1101': ['Albus','Mercury','Air','Gemini','-','White, fair'], '1111': ['Populus','Moon','Water','Cancer','-','People, congregation'], '1100': ['Fortuna Major','Sun','Fire','Leo','+','Greater fortune, greater aid,safeguard entering'], '1001': ['Conjunctio','Mercury','Earth','Virgo','+','Conjunction, assembling'], '0100': ['Puella','Venus','Air','Libra','+','A girl, beautiful'], '1011': ['Rubeus','Mars','Water','Scorpio','-','Red, reddish'], '1010': ['Acquisitio','Jupiter','Fire','Sagitarrius','+','Obtaining, comprehending without'], '0110': ['Carcer','Saturn','Earth','Capricorn','+','A prison, bound'], '1110': ['Tristitia','Saturn','Air','Aquarius','-','Sadness, damned, cross'], '0111': ['Laetitia','Jupiter','Water','Pisces','-','Joy, laughing, healthy, bearded'], '0001': ['Cauda Draconis','Saturn & Mars','Fire','Scorpio','-','The threshold lower, or going out'], '1000': ['Caput Draconis',' Jupiter & Venus','Earth','Capricorn','+','The Head, the threshold entering, the upper threshold'], '0011': ['Fortuna Minor','Sun','Fire','Leo','-','Lesser Fortune, lesser aid, safeguard going out'], '0000': ['Via','Moon','Water','Cancer','+','Way, journey']}

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
        dot = 1
    else:
        dot = 0
    return dot
    
def domothers():
    """ Append binary representation 0 as O/odd, 1 as OO/even
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
    return int(not(x ^ y))    

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
            if part==1:
                print "        O O   ",
            else:
                print "         O    ",
        print

numeral=0

def drawfig(body):
    for part in body:
        if part==1:
            print "        O O   ",
        else:
            print "         O    ",
        print


def lookfig(figure):
    # convert list to string
    key=''.join(str(e) for e in figure)
#    return (' '.join((roman[numeral]+". GD:",crowley[numeral]+".",figdict[key][0],figdict[key][2],figdict[key][5])))
    return (' '.join((figdict[key][0],": ",figdict[key][2],figdict[key][5],figdict[key][4])))


# list quotations
alchquotes = [
"Two Stars are given by the Gods to man to lead him to great wisdom. Gaze steadily upon them, follow their lights, and you will find in them the secret of knowledge.",
"Let the waters above the heavens fall\nand the earth will yield its fruit",
"A serpent and a toad coming up above the earth, a flying eagle",
"Serpents et Bufo gradiens super terram, Aquila volans",
"The red man here to his white wyfe,\nYs maryed with the spryte of life",
"Prima Materia Anima Corpus",
"A King on the left side and a Queen on the right standing in an open landscape.",
"The King holds a sceptre in his right hand and the Queen holds a three-blossomed flower in her right hand and a peacock feather fan in her left.",
"In front of the King a wolf or jumps over a triangular crucible placed on a basin of fire.",
"In front of the Queen, an old man with a scythe and crippled leg (a Saturn figure) steps across a fire on which a vessel (Cupel) is being heated.",
"There is one stone, one medicine, one vessel, one method, one disposition.",
"In our water all modes of things are brought about...\nIn the said water they are made as in an artificial vessel, which is a mighty secret.",
"The eagle flying through the air and the toad crawling on the ground are the magistry.",
"Join together an earthly toad and a flying eagle; you see the magesterium in our art.",
"To make the body spiritual, to make the spirit corporeal and consubstantial and fixed with the body; and to cleanse the filthie originall.",
"Let my friend know that no impure or spotted things are useful for our purpose.",
"Refuse the air below the earth rises\nand the sky will not withold its decay.",
"I tell you that they have reinvented geology in order to impose a new idea of god.",
"A contrary element, namely earth, whereon alone it moves by slow steps, and does not trust itself to another element.",
"Its head is very heavy and gazes at the earth\nit is firm and solid\nUpon it as a foundation the Golden House is to be built.",
"There are three diagrams or emblems.",
"When I had emptied to the dregs the cup of human suffering, I was led to consider the wretchedness of this world, and the fearful consequences of our first parents' disobedience.",
"EVERYTHING in existence necessarily has a body. The mode and manner may be understood as being like a smoky spirit, which indeed has substance, but is not a body, nor is it tangible.",
"SUN, CISCO, DELL, PENTIUM-4, DDR-4, SATA, SCSI, DIGITAL, PDP, ASTRATA, GLENCORE",
"LAIR, shrine, knife, circle, lighter, fire, beer, SUN microsystems, tunnel, stain, keyboard, AMD-Acid Mine Drainage.",
"Cracked snow white as a binary one or zero against the darkness.",
"Death may come before earth and love.",
"No more fruit, no more trees, no more vegetables, no more plants pharmaceutical or otherwise and consequently no more food.",
"The Rite of the Black Sun.",
"Spiritus, Anima, Corpus.",
"The true antimony of the philosophers lies in the deep sea, that the son of the king may lurk submerged.",
"We will suppose that the computer works in such a dissolutory manner that he never does more than one step at a sitting.",
"Visit the interior of the earth, and by rectifying (correcting or purifying) what you find there, you will discover the hidden stone.",
"... a Turing machine M could be constructed that would respond to a set of quintuples on its tape by printing | if and only if the machine defined by that set of quintuples never prints | when started with its own set of quintuples. Now, what happens when M is started with its own set of quintuples on its tape?",
"Of the black earth, wherein the seven planets took root.",
"The deep is its clothing, above it shall stand water, air, fire, and the birds of the air shall dwell therein, watering it from the upper elements, that it may be filled with the fruit of their works, because in the centre of the earth the seven planets took root, and left their virtues there, wherefore in the earth is water germinating divers kinds of colours and fruits and producing bread and wine that cheereth the heart of man.",
"When thou hast water from earth, air from water, fire from air, earth from fire, then thou fully and perefectly possess our art.",
"... and the earth hath been polluted and defiled in my works; for there was darkness over it, because I stick fast in the mire of the deep and my sustance is not disclosed.",
"... that the element of earth is not earth only, but a grape as well, that the element of water is not water only, but a mineral as well.", 
"This man of copper whom you have seen is the sacrificial priest and the sacrifice and he who vomited out his own flesh. To him was given authority over the water and over those men in mortification.",
"by such a dissolution and sublimation, the spirit is converted into a body and the body into a spirit.",
"One serpent holds in his mouth the tail of the other, to show that they are indissolubly conjoined by community of birth and destiny, and that our art is accomplished by the joint working of this mercurial sulphur, and the sulphurous mercury.",
"Take the flying bird and drown it flying, and divide it and separate it from its pollutions. Draw it forth and repel it from itself.",
"The earth is cold and dry, cold and moist, warm and dry, warm and moist. This is how matters stand. Whatever thing which is warm and dry grows out of the earth, grows out of that which in the earth is warm and dry. Whatever is or is produced cold and moist, is produced from that in the earth which is of a similar nature.",

]

darknn=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
count=0
ready=1
darkness=0
temperature=1.0
turing_states=["write 0", "write 1", "read 0", "read 1"]
data=""
# where is arduino on serial?  pass as argument
parser = argparse.ArgumentParser(description="serial")
# add expected arguments
parser.add_argument('--port', dest='port', required=True)
args = parser.parse_args()
ser = serial.Serial(args.port, 9600,    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
timeout=1)

g = ephem.Observer()  
g.name='DISS'  
g.lat='53.469616'  #Holden Gallery
g.long='-2.238067'
g.horizon=0
g.elevation=43

# init geomantics/ephem
sun = ephem.Sun()
moon = ephem.Moon()  
reg= ephem.star("Regulus")
corvus= ephem.star("Gienah Corvi")
degrees_per_radian = 180.0 / pi
threshold=99

# so we have 3 states...
# symbol, dir, state = t = prog[state][symbol] # lookup instruction

# state is 0 or 1, dir is +1 or -1, next state is 0, 1 or 2

# generate random program



prog = [[(1, +1, 1), (1, +1, 0)],           # state 0
        [(0, -1, 2), (1, +1, 1)],           # state 1
        [(0, +1, 2), (0, +1, 9)]]           # state 2
tape = [1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0]                  # The data tape
head = 0                                    # head position on tape
state = 0                                   # instruction pointer
count = 0

def calibrate():
    
    global threshold
    white=0
    black=0

    # TODO: new calibration code
    #//// read the first sets of black and white squares to get difference
    ser.flushOutput()
    ser.flushInput()

    ser.write("P") # start
    
    # first is w/b/w/b/w

    # maybe wait until we get data which is not 0 so now pi is running then get rest of data...

    #- add delay at start of calibration and throw away first measurement (also always measure darkness twice and discard???this means what???)
    sleep(5)

    # do this twice - we start on white!!!
    
    while (white==0):
        sleep(1)
        ser.flushOutput()
        ser.flushInput()
        ser.write("Q\n") # white1
        sleep(.1)
        try:
            line = ser.readline()
            data = [val for val in line.split()]
            #            print data
        except KeyboardInterrupt:
            print('exiting')
        if len(data)>0:
            try:
                white=int(data[0]) 
            except:
                white=0

    while (white==0):
        sleep(1)
        ser.flushOutput()
        ser.flushInput()
        ser.write("Q\n") # white1
        sleep(.1)
        try:
            line = ser.readline()
            data = [val for val in line.split()]
            #            print data
        except KeyboardInterrupt:
            print('exiting')
        if len(data)>0:
            try:
                white=int(data[0]) 
            except:
                white=0
                
    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(10)
    ser.write("Q\n") # black2
    sleep(.1)
    try:
        line = ser.readline()
        data = [val for val in line.split()]
        #        print data
    except KeyboardInterrupt:
        print('exiting')
    if len(data)>0:
        try:
            black=int(data[0]) 
        except:
            black+=20

    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(10)
    ser.write("Q\n") # white3
    sleep(.1)
    try:
        line = ser.readline()
        data = [val for val in line.split()]
        #        print data
    except KeyboardInterrupt:
        print('exiting')
    if len(data)>0:
        try:
            white+=int(data[0]) 
        except:
            white+=100

    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(10)
    ser.write("Q\n") # black4
    sleep(.1)
    try:
        line = ser.readline()
        data = [val for val in line.split()]
        #        print data
    except KeyboardInterrupt:
        print('exiting')
    if len(data)>0:
        try:
            black+=int(data[0]) 
        except:
            black+=20

    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(10)
    ser.write("Q\n") # white5
    sleep(.1)
    try:
        line = ser.readline()
        data = [val for val in line.split()]
        #        print data
    except KeyboardInterrupt:
        print('exiting')
    if len(data)>0:
        try:
            white+=int(data[0]) 
        except:
            white+=100
            
    white=white/3
    black=black/2
    threshold=(abs(white-black)+black) # we just want first calibration
#    threshold=99
    print "calibration:", threshold
    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(2)

def gopastit():
    ser.flushOutput()
    ser.flushInput()

    ser.write("P") # start


    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(3)
    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(3)
    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(3)
    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(3)
    ser.write("R")
    ser.flushOutput()
    ser.flushInput()
    sleep(3)

def resettm():
    print "RESET TAPE"
    global tape
    tape = [1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0]                  # The data tape
    # for cc in range(23):
    #     tape[cc]=random.randint(0,1)
    global head
    head = 0                                    # head position on tape
    global state
    state = 0                                   # instruction pointer
    global counterr
    counterr = 0
    calibrate()
#    gopastit()
    # write tape 
    for things in tape:
        if things==0:
        # write zero
            ser.write("E")
            sleep(6)
            ser.write("R") # move right - we don't need to check
            sleep(3)
        else:
            ser.write("W")
            sleep(6)
            ser.write("R") # move right - we don't need to check
            sleep(3)
    calibrate() # return to post-calibrate position
            #    gopastit()
    # we add new random program feature
    
    # for bb in range(3):
    #     x=random.randint(0,1)
    #     y=random.randint(0,1)
    #     if y==0:
    #         y=-1
    #     else:
    #         y=1
    #     z=random.randint(0,2)
    #     prog[bb][0]=(x,y,z)
    #     x=random.randint(0,1)
    #     y=random.randint(0,1)
    #     if y==0:
    #         y=-1
    #     else:
    #         y=1
    #     z=random.randint(0,2)
    #     prog[bb][1]=(x,y,z)
    
# //////

sleep(3)
#calibrate()
resettm()
#calibrate() # test our calibrate which is already in resettm
#ser.close()
#exit()

while(1):
    # request data
    ser.flushOutput()
    ser.flushInput()
    ser.write("Q")
    sleep(.1)
    try:
        line = ser.readline()
        data = [val for val in line.split()]
#        ser.flushInput()
    except KeyboardInterrupt:
        print('exiting')

    # if data is longer than 1
    if len(data)>0:
#        if isinstance(data[0],int):
        try:
            darkness=int(data[0]) # darkness
        except:
            darkness=0
#        if isinstance(data[1],float):
#            temperature=data[1]/10.0 # temperature
        # record 16 darkness values for geomancy
        darknn[count]=darkness
        count+=1
        if count==16:
            count=0
            ready=1

    # test code
#    darkness=random.randint(0,512)
#    darknn[count]=darkness
#    count+=1
#    if count==16:
#        count=0
 #       ready=1

    tmp = sp.call('clear',shell=True)

    print "                          TEST EXECUTION HOST"
    print "                          +++++++++++++++++++"
    print "Decoding ancient alchemical texts and emblems as (literal) instructions for the construction, execution and maintenance of a contemporary, geomantic and necessarily ouroboric live processor."
    #    print time
    print
    print random.choice(alchquotes) # or this choice is dependent of darkness!

    # print registers - 
    print "     Digester temperature: disconnected Darkness: %d Threshold: %d" %(darkness, threshold)

    print "     Turing Machine Status:"

# ////////////////////////////////////////////////////////////////////////////////
    
    # run TM:
    # counterr +=1
    
    # if counterr==23:
    #     #        head=0 # do we not need to zero whole thing or go past calibration?????
    #     #        state=0
    #     counterr=0
    #     resettm()
    if state==9:
        head=0
        state=0
        # do rewind or not - keep going and see what happens
        #        resettm()
    
    #    print "Program "
    # print prog
        
    #    symbol = tape[head]                         # read current tape symbol - read dark or light
    if darkness<threshold: # low is DARK!
        symbol=1
    else:
        symbol=0
    print "Symbol: ",
    print (symbol)
        
    #    symbol=random.randint(0,1)
    symbol, dir, state = t = prog[state][symbol] # lookup instruction
    #    print "        ",
    print "Tape: "
    print(tape)
    #print "        ",
    if head<0:
        head=0
    if head>=len(tape):
        tape.append(symbol) ## don't think we need to move right
    else:
        tape[head] = symbol                         # write new symbol on tape - write dark or light
    print(' ' * (head * 3 + 1)+ '^  ' + str(t)) # display progress
    if symbol==0:
        # write zero
        ser.write("E")
        print "... writes zero"
    else:
        ser.write("W")
        print "... writes one"
    head = head + dir                           # move tape head 

    # test code with the sun!
    g.date = datetime.datetime.utcnow()# 
    sun.compute(g)
    moon.compute(g)


    # go there
    print "SUN:", deg(sun.alt), 
    print "MOON:", deg(moon.alt) 

    # run geomantics
    # house = VIII. Death/Mortis - The House of Slaughter and Death: Heaviness, sadness, enemies, long torments, imprisonment, and the quality of death.
    # this would be the 4th daughter
    if ready==1:
        mlist=domothers()
        dlist=dodaughters(mlist)
        ready=0
    print "House = VIII. Death/Mortis - The House of Slaughter and Death: Heaviness, sadness, enemies, long torments, imprisonment, and the quality of death."
    # take the fourth daughter and explain/display this
    chosen=dlist[3]
    print lookfig(chosen) # TODO: clean up a bit but works
    drawfig(chosen)
    sleep(12)
    if dir==1:
        ser.write("R")
    else:
        ser.write("L")

    # NEW: receive whereweare data from arduino and act on this for head
    # if we hit left or right then do reset
    ser.flushOutput()
    ser.flushInput()
    ser.write("H")
    sleep(.1)
    try:
        line = ser.readline()
        data = [val for val in line.split()]
    except KeyboardInterrupt:
        print('exiting')

    # if data is longer than 1
    if len(data)>0:
        if data[0]=='R' or data[0]=='L':
            resettm()
            


ser.close()
