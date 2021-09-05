#!/usr/bin/python
'''Example of using pyKML to visualize ephemeris data

https://github.com/shabble/pykml/blob/master/src/examples/misc/pyephem/pyephem_example.py

- used now for sunrise / solstices  with qgis and csv

- retest

This example demonstrates how pyKML can be used visualize geospatial data 
generated by another Python library, PyEphem (http://rhodesmill.org/pyephem/).

also see: https://chrisramsay.co.uk/posts/2017/03/fun-with-the-sun-and-pyephem/

Example usage:
python pyephem_example.py > test.kml

not kml any longer

///////////////////////////FROM mapping.org how to import in qgis

Add delimited text layers:

eg. list of German nuclear power stations: germany_nuclear_sites.csv

** linestrings

eg. tld_europe_leys_linestrings_trimmedforcloseness

0|LINESTRING(12.583 55.667,-3.683 40.4,6.13 49.612)

1|LINESTRING(24.934 60.176,24.1 56.95,24.728 59.434)


Add delimited text layers

Custom delimiter: | 

Geometry definition: WKT Well Known Text

Geometry Field; LINESTRING blah

WGS84


'''

from datetime import datetime, timedelta
from math import pi, degrees, radians
from operator import mod
import ephem

# year = 2017
# month = 6
# day = 21
# longitude = -1.826165 # [degrees] - keep to stonehenge just to check and see...
# latitude = 51.178848  # [degrees]
elevation = 101.5     # elevation above sea level [meters]

# now try with one of our power stations

# KRB Unit B, Gundremmingen - shift so better placed
#longitude = 10.402379
#latitude= 48.515120

# For Messene location of Temple of Asclepius
#longitude = 21.92050694
#latitude= 37.17559276

# try for location of monastery in Klosterstrasse = make more precise: 13.41293,52.51854
longitude=13.41285
latitude=52.51854

height = 2            # height of observer [meters] - whether we use height?
timezone_offset = 3   # time offset from UTC time [hours] - 3 for Greece - we don't use this
label_distance = 100  # distance along ephemeris vector [meters]

obs = ephem.Observer()
obs.long, obs.lat = str(longitude), str(latitude) 
obs.elev = elevation + height
sun = ephem.Sun()

def adjust_heading_degrees(alpha):
    '''add the heading angle to make it between -180 and 180 degrees'''
    return mod(alpha+180,360)-180

def normalize_vector(x,y,z):
    '''return a unit normal vector'''
    length = (x**2+y**2+z**2)**0.5
    return x/length, y/length, z/length

def calculate_geographic_offset(azimuth_angle,altitude_angle, distance):
    '''determine the displacement in terms of latitude, longitude, and altitude'''
    from math import sin, cos, tan, atan2

    R = 6371009  # radius of earth in meters
    dx,dy,dz = normalize_vector(
        sin(azimuth_angle),
        cos(azimuth_angle),
        tan(altitude_angle),
    )
    alpha = atan2(dy,dx)   # horizontal angle [radians]
    D_horiz = distance*(dx**2+dy**2)**0.5  # horizontal length [meters]
    delta_lat_rad = D_horiz*sin(alpha)/R  # latitude offset [radians]
    delta_lon_rad = D_horiz*cos(alpha)/(R*cos(radians(latitude))) # longitude offset [radians]
    delta_alt = distance*dz  # altitude offset [meters]
    return delta_lat_rad, delta_lon_rad, delta_alt

lt = ephem.now()
#print(lt)

obs.date=lt
sun.compute(obs)
suntime=lt
delta_lat_rad, delta_lon_rad, delta_alt = calculate_geographic_offset(
    azimuth_angle=radians(adjust_heading_degrees(degrees(sun.az.real))),
    altitude_angle=sun.alt.real,
    distance=label_distance,
    )
lon = longitude + degrees(delta_lon_rad)
lat = latitude + degrees(delta_lat_rad)
alt = height + delta_alt
#print str(ephem.localtime(sunrise))+"|LINESTRING("+str(longitude)+" "+str(latitude)+","+str(lon)+" "+str(lat)+")" # notes this is OUR localtime in GERMANY
suntime=ephem.Date(suntime + 2 * ephem.hour)
print str(suntime)+"|LINESTRING("+str(longitude)+" "+str(latitude)+","+str(lon)+" "+str(lat)+")" # notes this is OUR localtime in GERMANY - THIS ONE TO USE!

#and for 1575 now
obs.date= ephem.Date('1575/08/31 14:48:45.12')
sun.compute(obs)
suntime=ephem.Date('1575/08/31 14:48:45.12')
delta_lat_rad, delta_lon_rad, delta_alt = calculate_geographic_offset(
    azimuth_angle=radians(adjust_heading_degrees(degrees(sun.az.real))),
    altitude_angle=sun.alt.real,
    distance=label_distance,
    )
lon = longitude + degrees(delta_lon_rad)
lat = latitude + degrees(delta_lat_rad)
alt = height + delta_alt
#print str(ephem.localtime(sunrise))+"|LINESTRING("+str(longitude)+" "+str(latitude)+","+str(lon)+" "+str(lat)+")" # notes this is OUR localtime in GERMANY
suntime=ephem.Date(suntime + 2 * ephem.hour)
print str(suntime)+"|LINESTRING("+str(longitude)+" "+str(latitude)+","+str(lon)+" "+str(lat)+")" # notes this is OUR localtime in GERMANY - THIS ONE TO USE!

