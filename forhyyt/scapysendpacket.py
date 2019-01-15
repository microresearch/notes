# tcpdump -s 0 -w -
# or
# tcpdump -s 0 -e "icmp[icmptype] == 8" -w - > packetdump # just ICMP echo request == 0 for the reply

import numpy as np
import time
from PIL import Image
from scapy.all import *

f = open("test5.bmp", "rb")  # reopen the file
data=f.read()
testdata=""
xx=1024
first=0

# while we have data 
for i in range(0, len(data), xx):
    pp=IP(dst="192.168.1.1")/ICMP()/(str(data[i:i + xx]))
    print i, len(pp)
    if first==0:
        first=len(pp)
    send(pp)
    #    print pp
    #    time.sleep(1)
    testdata+= str(pp)
#pp=IP(dst="192.168.1.1")/ICMP()/str(data)
img = Image.frombuffer('L', (first,800), testdata)
img.save("testdata.png")


