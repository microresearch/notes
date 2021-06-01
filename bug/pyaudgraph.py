#import pyaudio
import struct
import matplotlib.pyplot as plt
import numpy as np
from scipy import signal
import sounddevice as sd

#mic = pyaudio.PyAudio()

INTERVAL = 1

#FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 48000
CHUNK = int(RATE * INTERVAL)

sd.default.samplerate = RATE
sd.default.device = 3 # this is the mic

#stream = mic.open(format=FORMAT, channels=CHANNELS, rate=RATE, input=True, output=True, frames_per_buffer=CHUNK, input_device_index=1)

plt.ylabel('Frequency [Hz]')
plt.xlabel('Time [sec]')

#while True:
    #data = stream.read(CHUNK, exception_on_overflow=False)
data = sd.rec(int(INTERVAL * RATE), samplerate=RATE, channels=1, )
sd.wait()
data = np.frombuffer(data, dtype='b')
    #    print(data)
f, t, Sxx = signal.spectrogram(data, fs=CHUNK, window=signal.get_window('hann',300))
    #print(f,t,Sxx)
dBS = 10 * np.log10(Sxx)
    #plt.clf()
    #plt.pcolormesh(t, f, dBS)
    #plt.pause(0.001)

print(dBS[0])

#stream.stop_stream()
#stream.close()
#mic.terminate()
