import struct
#import matplotlib.pyplot as plt
import numpy as np
#from scipy import signal
import sounddevice as sd
from scipy.signal import butter, lfilter

def butter_bandpass(lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype='band')
    return b, a    

def butter_bandpass_filter(data, lowcut, highcut, fs, order=5):
    b, a = butter_bandpass(lowcut, highcut, fs, order=order)
    y = lfilter(b, a, data)
    return y

#let fs = 250
#let order = 5
INTERVAL = 1
CHANNELS = 1
RATE = 48000
CHUNK = int(RATE * INTERVAL)
CHUNK=48000

sd.default.samplerate = RATE
sd.default.device = 3 # this is the mic
while True:
    data = sd.rec(int(INTERVAL * RATE), samplerate=RATE, channels=1, )
    sd.wait()
    #    y = np.frombuffer(data, dtype='b')
    y=data
    oneD_array_of_amps_of_fiveHz_component = butter_bandpass_filter(y, 15000, 20000, 48000, 5)
    #calculate energy like this
    energy_of_fiveHz_comp = sum([x*2 for x in oneD_array_of_amps_of_fiveHz_component])
    #    print(int(1000.0*energy_of_fiveHz_comp))
