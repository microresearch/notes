# to process files from oracle sites which miss the GPS data as random walks

# eg. /root/NOWprojects/oracles/20190614/112521.TXT

# - take first gps data as start point and write to QGIS csv file - which waqy are we facing? say north
# - read in csv value for RNG
# - if it is <100 we go left x metres, else go right (x metres based on abs from 100 of toss?)
# - change long/lat accordingly based on our direction . newlat, newlong. write to file

# Length in meters of 1 of latitude = always 111.32 km
# Length in meters of 1 of longitude = 40075 km * cos( latitude ) / 360

# but what is our 40.847671, 14.052652 format = fraction of 60 degrees

# test for lat - add 111m = 0.001 of a degree * 1.6666667 = 0.0016666667 + 40.847671 = 40.849338 = looks OK

# more accurate 1m= 0.00008983111*1.6666667= 0.00001497185

# for long - calculate one degree then divide and re-mult

# ///// read csv first value, open outfile

# todo: test this

from pylab import *
import csv, os

def read_csv_file(filename):
    data = []
    for row in csv.reader(open(filename)):
        data.append(row)
    return data

heading=0 # NESw 0123
filet="/root/notes_and_projectsNOW/oracles/20190614/112521.TXT"
data=read_csv_file(filet)
outfile=filet+".walked"
oo=open(outfile,"w")

runninglat=float(data[0][0])
runninglong=float(data[0][1])
count=0

oo.write(str(runninglat) + ", " + str(runninglong) + "\n")

for rows in data:
    # deal with our RNG stuff
    rngg=float(rows[2])
    dir=100-rngg
    if dir>0:
        heading+=1
    else:
        heading-=1
    if heading==4:
        heading=0
    if heading==-1:
        heading=3
    metres=abs(dir)
    #    print metres, heading
    # calc lat, long based on heading
    if heading==0: # North so subtract from lat
        runninglat-=metres*0.00001497185
    if heading==2: # South so add to lat
        runninglat+=metres*0.00001497185
    if heading==1: # East so add to long
        onedeginmeters=40075000 * cos( runninglat ) / 360
        soonemeter=1/onedeginmeters
        runninglong+=soonemeter*metres*1.6666667
    if heading==3: # West so subtract from long
        onedeginmeters=40075000 * cos( runninglat ) / 360
        soonemeter=1/onedeginmeters
        runninglong-=soonemeter*metres*1.6666667
    oo.write(str(runninglat) + ", " + str(runninglong) + ", " + str(count) + "\n")
    count+=1
        
oo.close
