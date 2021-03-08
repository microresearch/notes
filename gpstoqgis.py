#! /usr/bin/env python
"""
Converts our GPS logfiles to something we can read into qgis.
"""
from numpy import array, pi, cos
import csv
import os
import sys
import Gnuplot
import Gnuplot.funcutils
from optparse import OptionParser


def readcsvfile(filename):
    """
    returns values from csv as a list

    NB using 'with - as' idiom with file objects makes sure they are
    closed after use

    filename = path to csv file
    data = data from file as list
    """
    data = []
    f=open(filename)
    
    reader = csv.reader(f)
    for row in reader:
        data.append(row)
    return data


def processgpsdata(data):
    """
    process the gps data
    """
    latitude = []
    longitude = []
    intensity = []
    intensitylow = []

    # redo for DMS
    
    for row in data:
        latitude.append(float(row[0][0:2]) + \
                        float(row[0][2:]) / 60.0)
        longitude.append((float(row[1][0:3]) + \
                          float(row[1][3:]) / 60.0))
        intensity.append(float(row[2]))
        intensitylow.append(float(row[3]))

    return (array(latitude),
            array(longitude),
            array(intensity),
            array(intensitylow))


def makenewfilename(filename, suffix='.converted'):
    """
    strip extension from input file and make new file with same name

    default value for suffix is .png
    """
    return os.path.join(os.path.splitext(filename)[0]) + suffix


def main():
    """
    parses command line arguments
    calls functions
    processes output
    """
    usage = "usage: %prog [optional title] path/to/data/file"
    parser = OptionParser(usage, version="%prog 0.1")
    parser.add_option("-t",
                      "--title",
                      dest="title",
                      default=None,
                      help="Add a title to the plot. Default is None")
    options, args = parser.parse_args()
    if len(args) != 1:
        parser.error("""

Please specify a path to the data file
e.g. gpsprocess.py /root/projects/detection/logs/scryturmcut
""")
    filepath = args[0]
    settitle = options.title
    outputfile = makenewfilename(filepath)

    oo=open(outputfile,"w")

    y = readcsvfile(filepath)
    (lat, lon, intensity, intensitylow) = processgpsdata(y) # add/subtract more values

    
    for x, yz, z, zz in zip(lat, lon, intensity, intensitylow):
        # write to file comma seperated
        # for moment write
        string="-"+str(yz)+ ","+str(x)+","+str(z)+","+str(zz)+"\n" #csv
        # as vector layer?
        oo.write(string)

    oo.close
        
if __name__ == '__main__':
    sys.exit(main())
