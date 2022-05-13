# for more recent NLTK which doesn't have bm=NgramModel(2,cry) # bigram model
# this one is working!

# http://www.nltk.org/api/nltk.lm.html#module-nltk.lm

from nltk import *
from time import sleep
import math
import random
import time
import serial
import codecs
import os
import subprocess as sp
from nltk.lm import MLE
from nltk.util import bigrams
from nltk.lm.preprocessing import padded_everygram_pipeline
import unicodedata

def convert_accents(text):
    return unicodedata.normalize('NFKD', text).encode('ascii', 'ignore')


f = codecs.open("zosimos","r","utf-8")
#f = codecs.open("/root/projects/archived/worms_txt/zosimos","r","utf-8")
#f = codecs.open("/root/projects/archived/worms_txt/short")
cry = f.read()
#cry=[y.lower() for y in cry]
#cry=[convert_accents(word) for word in cry]

uf=FreqDist(l for l in cry)
up=DictionaryProbDist(uf,normalize=True)
#bm=NgramModel(2,cry) # bigram model
#lm.fit(cry, vocab)

#print list(bigrams(text[0]))
#print list(bigrams(cry))

# what we need from text is:  a text that is a list of sentences, where each sentence is a list of strings.
# eg. text = [['a', 'b', 'c'], ['a', 'c', 'd', 'c', 'e', 'f']]

sentt=[]
 
for sent in sent_tokenize(cry):
    letterss=[]
    #sentt.append(sent)
    for letters in sent:
        letterss.append(letters)
    sentt.append(letterss)
    
#print sentt
#cryyy = list(cryy)

#print cryy

train, vocab = padded_everygram_pipeline(2, sentt)
lm = MLE(2)
lm.fit(train, vocab)
#print lm.vocab 

#for prob?
#print lm.score("a",list("b"))

uf=FreqDist(l for l in cry)
up=DictionaryProbDist(uf,normalize=True)
#print uf
#bm=NgramModel(2,cry) # bigram model

#print lm.generate(5, text_seed=['c'], random_seed=3))

def genereate(dct,model,letter,n):
    probb=[]
    result=''
    total=''
    line=''
    for x in range(n):
        for l in dct.samples():
            prob=model.logscore(l,tuple(letter))
#            print prob, letter, l
            probb.append((prob,l))
        probb.sort()
        probb.reverse()
        #        print probb
        line = ser.read(1)
#        line = random.randint(0,32)
#        line=1
        try:
            nummm = int(ord(line)/3) # how much to divide?
#            nummm = int(line/3)
        except:
            nummm = 1
        if nummm>=len(probb):
            nummm=len(probb)-1;        
        letter=probb[random.randint(0,nummm)][1]
        result=result+letter
        probb=[]
        if letter=="\n":
            return result[0:-1]
    return result[0:-1]

inpt=time.time()
ser = serial.Serial('/dev/ttyACM3', 9600, timeout=1)
seedletter='e'

fullon=[]
count=0

#pr=lm.generate(2000) # this seems to work with our model but not our generate which lacks spaces for one thing
#print ''.join(pr)
for x in range(1000000):
    x=genereate(up,lm,seedletter,149) # max length of line
    print(x)

# while True: # question of timings
#     # how to convert to slow scan->
#     # screen array - add next line -length=149
#     x=genereate(up,lm,seedletter,149) # max length of line
#     fullon.append(x)
#     # refresh
#     tmp = sp.call('clear',shell=True)
#     time.sleep(0.1)
#     for fills in fullon:
#         print fills #slowly print line by line?
#         time.sleep(0.1) 
       
#     count+=1 
#     # is full then start from zero adding
#     if count==50: # how many lines
#         count=0
#         fullon=[]
#     #print x
#     time.sleep(1)


