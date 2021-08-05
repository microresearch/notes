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
    entropy   = []
    muon          = []
    gsr         = []
    temp        = []
    for row in data:
        latitude.append(float(row[0][0:2]) + \
                            float(row[0][2:])/60.0)
        longitude.append((float(row[1][0:3]) + \
                              float(row[1][3:])/60.0))
        entropy.append(float(row[2]))
        muon.append(float(row[3])+100) # mult to scale to approx same as rng

        
    return (array(latitude), array(longitude), array(entropy), array(muon))


#y=read_csv_file('/root/collect2012-3/copenhagen/21stlog')
y=read_csv_file('/root/projects/bordeaux/submarine21052017')

(lat, long, entropy,muon) = process_gps_data(y)
# translate spherical coordinates to Cartesian
py = (lat-min(lat))*NMI*60.0
px = (long-min(long))*NMI*60.0*cos(D2R*lat)
#newintensity=intensity-min(intensity)

#pack px, py, intensity and gsr into newy
newy=[]
for x,yz,z,zz in zip(px,py,entropy,muon):
    newy.append((x,yz,z,zz))

minty=min(entropy)
maxxy=max(entropy)

for index, item in enumerate(entropy):
    if item==minty:
        lower=index
    if item==maxxy:
        maxx=index
        
print "low entropy site -: ", 
print lat[lower], long[lower] 
print "low entropy site +: ", 
print lat[maxx], long[maxx] 

minty=min(muon)
maxxy=max(muon)

for index, item in enumerate(muon):
    if item==minty:
        lower=index
    if item==maxxy:
        max=index
        
print "min muon site -: ", 
print lat[lower], long[lower] 
print "max muon site +: ", 
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
g.title("bordeaux 21052017 RNG//Muon")
#g('set term png size 14043,9933') # A0
g('set term png size 1024,768') # example
g('set style lines 1')
g('set output "/root/projects/bordeaux/submarine21052017.png"')

#g.splot(Gnuplot.Data(newy, using=(1,2,3), with='lines'),Gnuplot.Data(newy, using=(1,2,4), with='lines'))

g.splot(Gnuplot.Data(newy, using=(1,2,3)),Gnuplot.Data(newy, using=(1,2,4))) 

#g.splot(Gnuplot.Data(newy, using=(1,2,4), with='lines'))

#g.splot(Gnuplot.Data(newy, using=(1,2,3)))

#print newy

# how to find LONG. LAT of max and min entropy????
