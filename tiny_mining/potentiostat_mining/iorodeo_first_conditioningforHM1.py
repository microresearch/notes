import scipy
from potentiostat import Potentiostat
import matplotlib.pyplot as plt

# Pre-conditioning for ItalSens HM1 - this is the first one which is run once

print("Pre-conditioning for ItalSens HM1 - this is the first one which is run once")

port = '/dev/ttyACM3'    # Serial port for potentiostat device
datafile = 'data_veryfirstconditioning.txt'    # Name of output data file

# 1] Conditioning and deposition

test_name = 'constant'   # Name of test to run - constant volate voltammetery
curr_range = '100uA'     # Name of current range for test [-10uA, +10uA]
sample_rate = 100.0      # Rate (samples/sec) at which to collect samples 

test_param = { 
        'quietValue' : -0.18,        # Output voltage during quiet peroid
        'quietTime'  : 30000,       # Duration of quiet period (ms) 30 seconds
        'value'      : -1.1,        # Output volatage (V) durring constant voltage test
        'duration'   : 300000,       # Duration of constant voltage test (ms) 300 seconds
        }

# Create Device object and set sample rate, current range and test parameters
dev = Potentiostat(port)             
dev.set_sample_rate(sample_rate)   
dev.set_curr_range(curr_range)     
dev.set_param(test_name,test_param)

# Run cyclic voltammetry test
t,volt,curr = dev.run_test(test_name,display='pbar',filename=datafile)

# 2] Equalisation and SWV

datafile = 'data_veryfirstSWV.txt'    # Name of output data file

test_name = 'squareWave'    # The name of the test to run
curr_range = '100uA'         # The name of the current range [-100uA, +100uA]
sample_rate = 15.0          # The number of samples/second to collect - was 10, now 15???

# Create dictionary of waveform parameters squarewave annodic stripping
test_param = {
        'quietValue' : -1.1, # this is the eq value of 10 seconds
        'quietTime'  :  10000,
        'amplitude'  :  0.025,
        'startValue' : -1.1,
        'finalValue' : -0.15,
        'stepValue'  :  0.005,
        'window'     :  0.2,
        }

# Set current range, sample rate and test parameters
dev.set_curr_range(curr_range)   
dev.set_sample_rate(sample_rate)
dev.set_param(test_name,test_param)

# Run cyclic voltammetry test
t,volt,curr = dev.run_test(test_name,display='pbar',filename=datafile)

# Convert values to scipy arrays
t = scipy.array(t)
volt = scipy.array(volt)
curr = scipy.array(curr)

# Remove values during quiet time
ind = t > test_param['quietTime']*1.0e-3
t, volt, curr  = t[ind], volt[ind], curr[ind]
t = t - t[0]

# plot results using matplotlib
plt.figure(1)
plt.subplot(211)
plt.plot(t,volt)
plt.ylabel('potential (V)')
plt.grid('on')

plt.subplot(212)
plt.plot(t,curr)
plt.ylabel('current (uA)')
plt.xlabel('time (sec)')
ymin = min(curr.min(), 0)
ymax = max(curr.max(), 0)
dy = ymax - ymin
ymax += 0.1*dy
ymin -= 0.1*dy
plt.ylim(ymin, ymax)
plt.grid('on')

plt.figure(2)
plt.plot(volt,curr)
plt.xlabel('potential (V)')
plt.ylabel('current (uA)')
plt.ylim(ymin, ymax)
plt.grid('on')

plt.show()


# plot this
