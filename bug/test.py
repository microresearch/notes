import numpy as np
import sounddevice as sd

sd.default.samplerate = 44100

time = 2.0
frequency = 440

# # Generate time of samples between 0 and two seconds
# samples = np.arange(44100 * time) / 44100.0
# # Recall that a sinusoidal wave of frequency f has formula w(t) = A*sin(2*pi*f*t)
# wave = 10000 * np.sin(2 * np.pi * frequency * samples)
# # Convert it to wav format (16 bits)
# wav_wave = np.array(wave, dtype=np.int16)

# sd.play(wav_wave, blocking=True)

#duration = 10.5  # seconds
#myrecording = sd.rec(int(duration * fs), samplerate=fs, channels=2)#

fs=44100
myarray = np.zeros((1024,1))
sd.default.samplerate = fs
sd.default.channels = 1
sd.default.device = 3 # this is the one

#The number of output channels is obtained from myarray, but the number of input channels still has to be specified.

#Again, default values can be used:
while True:
    data = sd.rec(int(44100), channels=1)
    sd.wait()
    myrecording = sd.play(data, fs)
    sd.wait()
