// abstracted out from ino
// we just want ecliptic longitude from time/date

/* 
TODO: 

- track moon for date and co-ordinates of kloster site in Berlin: 

longitude=13.41285
latitude=52.51854

// Example call to this function for 2014/01/04 1709Z: 
//   moon2(2014,1,4,17+9/60.,-106.625,52.104168,
//       &RA, &Dec, &topRA, &topDec, &LST, &HA, &Az, &El, &dist);

- we want ecliptic longitude so we can use sign of zodiac

zodiac = 'AR TA GE CN LE VI LI SC SG CP AQ PI'.split()

as array... to print /30 degrees

*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
//const char *zodiac[12] = {"AR", "TA", "GE", "CN", "LE", "VI", "LI", "SC", "SG", "CP", "AQ", "PI"};

// Translated from the WSJT Fortran code by Pete VE5VA
// Example call to this function for 2014/01/04 1709Z: 
//   moon2(2014,1,4,17+9/60.,-106.625,52.104168,
//       &RA, &Dec, &topRA, &topDec, &LST, &HA, &Az, &El, &dist);

// now to return lonecel

double moon2(int y,int m,int Day,
        double UT,
        double lon,double lat)
{
  // The strange position of some of the semicolons is because some
  // of this was translated using a TCL script that I wrote - it isn't
  // too smart but it saved some typing
  int tmp;
  double NN                           ;//Longitude of ascending node
  double i                            ;//Inclination to the ecliptic
  double w                            ;//Argument of perigee
  double a                            ;//Semi-major axis
  double e                            ;//Eccentricity
  double MM                           ;//Mean anomaly

  double v                            ;//True anomaly
  double EE                           ;//Eccentric anomaly
  double ecl                          ;//Obliquity of the ecliptic

  double d                            ;//Ephemeris time argument in days
  double r                            ;//Distance to sun, AU
  double xv,yv                        ;//x and y coords in ecliptic
  double lonecl,latecl                ;//Ecliptic long and lat of moon
  double xg,yg,zg                     ;//Ecliptic rectangular coords
  double Ms                           ;//Mean anomaly of sun
  double ws                           ;//Argument of perihelion of sun
  double Ls                           ;//Mean longitude of sun (Ns=0)
  double Lm                           ;//Mean longitude of moon
  double DD                           ;//Mean elongation of moon
  double FF                           ;//Argument of latitude for moon
  double xe,ye,ze                     ;//Equatorial geocentric coords of moon
  double mpar                         ;//Parallax of moon (r_E / d)
  //  double gclat                        ;//Geocentric latitude
  //  double rho                          ;//Earth radius factor
  //  double GMST0; //,LST,HA;
  double g;
  double rad = 57.2957795131,twopi = 6.283185307,pi,pio2;

  //Note the use of 'L' to force 32-bit integer arithmetic here. 
  d=367L*y - 7L*(y+(m+9L)/12L)/4L + 275L*m/9L + Day - 730530L + UT/24.;
  ecl = 23.4393 - 3.563e-7 * d;

  //  Orbital elements for Moon:
  NN = 125.1228 - 0.0529538083 * d;
  i = 5.1454;
  w = fmod(318.0634 + 0.1643573223 * d + 360000.,360.);
  a = 60.2666;
  e = 0.054900;
  MM = fmod(115.3654 + 13.0649929509 * d + 360000.,360.);

  EE = MM + e*rad*sin(MM/rad) * (1. + e*cos(MM/rad));
  EE = EE - (EE - e*rad*sin(EE/rad)-MM) / (1. - e*cos(EE/rad));
  EE = EE - (EE - e*rad*sin(EE/rad)-MM) / (1. - e*cos(EE/rad));

  xv = a * (cos(EE/rad) - e);
  yv = a * (sqrt(1.-e*e) * sin(EE/rad));

  v = fmod(rad*atan2(yv,xv)+720.,360.);
  r = sqrt(xv*xv + yv*yv); // do we use this?

  //  Get geocentric position in ecliptic rectangular coordinates:

  xg = r * (cos(NN/rad)*cos((v+w)/rad) - sin(NN/rad)*sin((v+w)/rad)*cos(i/rad));
  yg = r * (sin(NN/rad)*cos((v+w)/rad) + cos(NN/rad)*sin((v+w)/rad)*cos(i/rad));
  zg = r * (sin((v+w)/rad)*sin(i/rad));

  //  Ecliptic longitude and latitude of moon:
  lonecl = fmod(rad*atan2(yg/rad,xg/rad)+720.,360.);

  latecl = rad * atan2(zg/rad,sqrt(xg*xg + yg*yg)/rad);

  //  Now include orbital perturbations:
  Ms = fmod(356.0470 + 0.9856002585 * d + 3600000.,360.);
  ws = 282.9404 + 4.70935e-5*d;
  Ls = fmod(Ms + ws + 720.,360.);
  Lm = fmod(MM + w + NN+720.,360.);
  DD = fmod(Lm - Ls + 360.,360.);
  FF = fmod(Lm - NN + 360.,360.);

  lonecl = lonecl
       -1.274 * sin((MM-2.*DD)/rad)
       +0.658 * sin(2.*DD/rad)
       -0.186 * sin(Ms/rad)
       -0.059 * sin((2.*MM-2.*DD)/rad)
       -0.057 * sin((MM-2.*DD+Ms)/rad)
       +0.053 * sin((MM+2.*DD)/rad)
       +0.046 * sin((2.*DD-Ms)/rad)
       +0.041 * sin((MM-Ms)/rad)
       -0.035 * sin(DD/rad)
       -0.031 * sin((MM+Ms)/rad)
       -0.015 * sin((2.*FF-2.*DD)/rad)
       +0.011 * sin((MM-4.*DD)/rad);
  return lonecl;
}

void main(){
double ecl=  moon2(2021, 9, 16, 12+00/60., 12.41285, 52.51854);
 printf("%d\n", (int)ecl);

}
