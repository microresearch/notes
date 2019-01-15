import numpy as np
from PIL import Image
from scapy.all import *

sniffed = sniff()[0]
print sniffed
