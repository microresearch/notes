import numpy as np
from PIL import Image

f = open("packetdump", "rb")  # reopen the file
data=f.read()
#for x in range(0,1024):
x=570
y=1070
img = Image.frombuffer('L', (512+x,y), data)
filename="test"+str(x)+".png"
    
img.save(filename)
