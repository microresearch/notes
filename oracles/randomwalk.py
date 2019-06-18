# to process files from oracle sites which miss the GPS data as random walks

# eg. /root/NOWprojects/oracles/20190614/112521.TXT

# - take first gps data as start point and write to QGIS csv file - which waqy are we facing? say north
# - read in csv value for RNG
# - if it is <100 we go left x metres, else go right (x metres based on abs from 100 of toss?)
# - change long/lat accordingly based on our direction . newlat, newlong. write to file

# Length in meters of 1° of latitude = always 111.32 km
# Length in meters of 1° of longitude = 40075 km * cos( latitude ) / 360

# but what is our 40.847671, 14.052652 format = fraction of 60 degrees

# test for lat - add 111m = 0.001 of a degree * 1.6666667 = 0.0016666667 + 40.847671 = 40.849338 = looks OK

# more accurate 1m= 0.00008983111*1.6666667= 0.00001497185

# for long - calculate one degree then divide and re-mult
