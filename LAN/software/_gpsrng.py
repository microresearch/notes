# modified for latest gpslogger with rng (arduino based - see new_gpslogger)

from pylab import *
import csv, os, Gnuplot, Gnuplot.funcutils

g = Gnuplot.Gnuplot(debug=1)

NMI = 1852.0
D2R = pi/180.0

#data = sys.argv[1]
#title = sys.argv[2]

def read_csv_file(filename):
    data = []
    for row in csv.reader(open(filename)):
        data.append(row)
    return data

def process_gps_data(data):
    latitude    = []
    longitude   = []
    rngg   = []
    for row in data:
        latitude.append(float(row[0]))
        longitude.append(float(row[1]))
        rngg.append(float(row[2]))

        
    return (array(latitude), array(longitude), array(rngg))


y=read_csv_file('samples/140055.txt')


(lat, long, rngg) = process_gps_data(y)

# translate spherical coordinates to Cartesian ??
py = (lat-min(lat))*NMI*60.0
px = (long-min(long))*NMI*60.0*cos(D2R*lat)

newy=[]
for x,yz,z in zip(px,py,rngg):
    newy.append((x,yz,z))
    
minty=min(rngg)
maxxy=max(rngg)

for index, item in enumerate(rngg):
    if item==minty:
        lower=index
    if item==maxxy:
        max=index
        

print "low entropy sites -: ", 
print lat[lower], long[lower] 
print "\nlow entropy sites +: ", 
print lat[max], long[max] 

    
g('set parametric')
g('set style data line')
g('set surface')
g('unset key')
g('unset contour')
#g('set dgrid3d 80,80,30')
g('set dgrid3d 80,80,30')
g('set xlabel "metres WE"') 
g('set ylabel "metres NS"') 
#g('set label "signal intensity" at -100,0,100') 
g('set view 60,20')
g.title("Berlin test HF intensity")
#g('set term png size 14043,9933') # A0
g('set term png size 1024,768') # example
g('set style lines 1')
g('set output "/root/NOWprojects/LAN/software/samples/test710.png"')

#g.splot(Gnuplot.Data(newy, using=(1,2,3), with='lines'),Gnuplot.Data(newy, using=(1,2,4), with='lines'))

#g.splot(Gnuplot.Data(newy, using=(1,2,3)),Gnuplot.Data(newy, using=(1,2,4))) 

g.splot(Gnuplot.Data(newy, using=(1,2,3)))

#g.splot(Gnuplot.Data(newy, using=(1,2,3)))

#print newy

# how to find LONG. LAT of max and min entropy????
