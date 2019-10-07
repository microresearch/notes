# now tells us sites of low entropy!

from pylab import *
import csv, os, Gnuplot, Gnuplot.funcutils

g = Gnuplot.Gnuplot(debug=1)

NMI = 1852.0
D2R = pi/180.0

#data = sys.argv[1]
#title = sys.argv[2]

def calc_limit_high_005(range):
        var = (1.96 / 2) * math.sqrt(range)
        limit_high = range/2 + var
        return limit_high

def read_csv_file(filename):
    data = []
    for row in csv.reader(open(filename)):
        data.append(row)
    return data

def process_gps_data(data):
    latitude    = []
    longitude   = []
    RNG          = []
    ppp         = []
    cnt=1
    rngcum=0
    for row in data:
        latitude.append(float(row[0][0:2]) + \
                            float(row[0][2:])/60.0)
        longitude.append((float(row[1][0:3]) + \
                              float(row[1][3:])/60.0))
        rngcum+=(100-float(row[2]))
        RNG.append(rngcum)
	ppp.append((calc_limit_high_005(cnt*200))-(cnt*100))
# now tells us sites of low entropy!

from pylab import *
import csv, os, Gnuplot, Gnuplot.funcutils

g = Gnuplot.Gnuplot(debug=1)

NMI = 1852.0
D2R = pi/180.0

#data = sys.argv[1]
#title = sys.argv[2]

def calc_limit_high_005(range):
        var = (1.96 / 2) * math.sqrt(range)
        limit_high = range/2 + var
        return limit_high

def read_csv_file(filename):
    data = []
    for row in csv.reader(open(filename)):
        data.append(row)
    return data

def process_gps_data(data):
    latitude    = []
    longitude   = []
    RNG          = []
    ppp         = []
    cnt=1
    rngcum=0
    for row in data:
        latitude.append(float(row[0][0:2]) + \
                            float(row[0][2:])/60.0)
        longitude.append((float(row[1][0:3]) + \
                              float(row[1][3:])/60.0))
        rngcum+=(float(row[2])-100)
        RNG.append(rngcum)
	ppp.append((calc_limit_high_005(cnt*200))-(cnt*100))
#	ppp.append((cnt*100)-(calc_limit_high_005(cnt*200)))
        cnt+=1
#	print rngcum, (cnt*100)-(calc_limit_high_005(cnt*200))

    return (array(latitude), array(longitude), \
                array(RNG),array(ppp))

#y=read_csv_file('/root/collect2012-3/copenhagen/21stlog')
y=read_csv_file('/root/projects/bordeaux/submarine21052017')
(lat, long, RNG, ppp) = process_gps_data(y)


minty=min(RNG)
maxxy=max(RNG)

for index, item in enumerate(RNG):
    if item==minty:
        lower=index
    if item==maxxy:
        max=index
        
print "low entropy sites -: ", 
print lat[lower], long[lower] 
print "\nlow entropy sites +: ", 
print lat[max], long[max] 

# translate spherical coordinates to Cartesian
py = (lat-min(lat))*NMI*60.0
px = (long-min(long))*NMI*60.0*cos(D2R*lat)
#newintensity=intensity-min(intensity)

#pack px, py, intensity and gsr into newy
newy=[]
cummd=0
for x,yz,zz,pppp in zip(px,py,RNG,ppp):
    newy.append((x,yz,zz,pppp))

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
#g.title("21th November 2013 cumulative RNG Copenhagen")
g.title("bordeaux 21052017 cumulative RNG/deviation")
g('set term png size 14043,9933') # A0
g('set term png size 1024,768') # example
#g('set output "/root/collect2012-3/copenhagen/21stcumlog.png')
g('set output "/root/projects/bordeaux/images/subcum.png"')
g('set style lines 1')

g.splot(Gnuplot.Data(newy, using=(1,2,3)),Gnuplot.Data(newy, using=(1,2,4))) 

#g.splot(Gnuplot.Data(newy, using=(1,2,3), with='lines'))
