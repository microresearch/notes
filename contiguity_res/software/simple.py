import ephem
import datetime
from math import degrees as deg

format = "%Y-%m-%d %H:%M"


home = ephem.Observer()
home.lat, home.lon = '52.52','13.4050'
home.pressure=0
home.date = datetime.datetime.utcnow()

#print home.date

sun, moon = ephem.Sun(), ephem.Moon()

sun.compute(home)
#print sun.alt, sun.az

moon.compute(home)
moon_azimuth  = round(deg(float(moon.az)),1)
moon_altitude = round(deg(float(moon.alt)),1)
moon_illum = round(moon.phase,1)
moonrise = ephem.localtime(home.next_rising(moon)).strftime(format)
moonset  = ephem.localtime(home.next_setting(moon)).strftime(format)
full_moon = ephem.localtime(ephem.next_full_moon(home.date)).strftime(format)

home.date=home.next_setting(moon)
moon.compute(home)

# plot moonset from NESW

degg=deg(moon.az)
xcoord=int(degg)

print "MOONSET",
print moonset
    
for x in range(xcoord/2):
    print "",
print "O"
print
print"N---------------------------------------------E--------------------------------------------S-------------------------------------------W---------------------------------------------"
print

print "az:\t%s" % (moon.az)

#solstice

print "next sol", ephem.next_solstice("2023")

home.date=ephem.next_solstice("2023")
moon.compute(home)

home.date=moon.set_time
moon.compute(home)

degg=deg(moon.az)
xcoord=int(degg)

print "MOONSET",
print moon.set_time
    
for x in range(xcoord/2):
    print "",
print "O"
print
print"N---------------------------------------------E--------------------------------------------S-------------------------------------------W---------------------------------------------"
print

print "az:\t%s" % (moon.az)
