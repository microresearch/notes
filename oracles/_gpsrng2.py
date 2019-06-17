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
    intensity   = []
    lf          = []
    gsr         = []
    temp        = []
    for row in data:
        latitude.append(float(row[0][0:2]) + \
                            float(row[0][2:])/60.0)
        longitude.append((float(row[1][0:3]) + \
                              float(row[1][3:])/60.0))
        print(float(row[1][3:])/60.0)
        intensity.append(float(row[2]))
        #        lf.append(float(row[3]))
        #        print longitude

    return (array(latitude), array(longitude), array(intensity))#, array(lf))

y=read_csv_file('/root/projects/bordeaux/submarine21052017')

(lat, long, intensity) = process_gps_data(y)

# what is lat, long for min/max intensity?

minty=min(intensity)
maxxy=max(intensity)

for index, item in enumerate(intensity):
    if item==minty:
        lower=index
    if item==maxxy:
        max=index
        

print "low entropy sites -: ", 
print lat[lower], long[lower] 
print "\nlow entropy sites +: ", 
print lat[max], long[max] 
