# convert data to audio file

import numpy as np
from scipy.io.wavfile import write

filename="testxxx_temp"
data = np.loadtxt(filename, delimiter=",")
#print data
#data = np.random.uniform(-1,1,44100) # 44100 random samples between -1 and 1
#scaled = np.int16(data/np.max(np.abs(data)) * 32767)
write('test.wav', 44100, data)
