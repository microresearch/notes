/*

https://github.com/markfickett/gpslogger/blob/master/gpslogger.ino

https://github.com/mikalhart/TinyGPS

or neogps library....

TODO: to test/fixed up for our GPS/ SD pins, sd write worksDONE, test
later with new GPS-DONE, new library to try=neogps, not accurate so
test outside TODO

FINAL:

Log peak power in 1s period AD8313, coil and bare antenna, average
power of these, FGM3 difference in freq (or we use flip flop so just one count)

and log with 1 second GPS position!

- First tests: test sd shield logs (serial out too)DONE, test gps with ublox 8 (software serial), now with NEO-6M

loop: sample for 2 seconds, write SD for last location GPS fixed to! CHECK FGM stuff how we sample that...

OR:

wait for GPS, then do all our averages, reset and write to SD!

// REFS:

GPS: https://www.reichelt.de/gnss-gps-engine-module-u-blox-8-ttl-navilock-62571-p152514.html? 

new gps from ebay is: NEO-6M GY-GPS6MV2 

neogps library: https://github.com/SlashDevin/NeoGPS

 */

#include <SoftwareSerial.h>
#include <SdFat.h>
#include <TinyGPS.h>

#define SAMPLE_INTERVAL_MS 1000

#define PIN_STATUS_LED 13

#define PIN_RX_FROM_GPS 5 // THIs is TX on board
#define PIN_TX_TO_GPS 3 // ignore this one
#define PIN_SD_CHIP_SELECT 4

#define DEFAULT_GPS_BAUD 9600 // what is baud of ours? should be 9600 - new gps is also 9600
#define GPS_BAUD 9600

// Seek to fileSize + this position before writing track points.
#define SEEK_TRKPT_BACKWARDS -24
#define GPX_EPILOGUE "\t</trkseg></trk>\n</gpx>\n"
#define LATLON_PREC 6

#define sbi(var, mask)   ((var) |= (uint8_t)(1 << mask))
#define cbi(var, mask)   ((var) &= (uint8_t)~(1 << mask))

TinyGPS gps;
SoftwareSerial nss(PIN_RX_FROM_GPS, PIN_TX_TO_GPS);

SdFat sd;
SdFile gpxFile;
int randomm;

// General-purpose text buffer used in formatting.
char buf[32];

struct GpsSample {
  float lat_deg,
        lon_deg;
  float altitude_m;

  int satellites;
  int hdop_hundredths;

  // How many ms, according to millis(), since the last position data was read
  // from the GPS.
  unsigned long fix_age_ms;

  float speed_mps;
  float course_deg;

  // How many ms, according to millis(), since the last datetime data was read
  // from the GPS.
  unsigned long datetime_fix_age_ms;

  int year;
  byte month,
       day,
       hour,
       minute,
       second,
       hundredths;
};
// The latest sample read from the GPS.
struct GpsSample sample;

static void readFromGpsUntilSampleTime();
static void fillGpsSample(TinyGPS &gps);
static bool readFromGpsSerial();
static void openTimestampedFile(const char *shortSuffix, SdFile &file);

void setupadc(void){

  cbi(ADMUX, REFS1);
  sbi(ADMUX, REFS0);
  sbi(ADMUX, ADLAR);
  ADMUX = (ADMUX & (unsigned int) 0xf0) | (0x00 & (unsigned int) 0x0f); // was 0x03 but we want ADC3 - on older board is 0x03 otherwise 0x02 - we want 00


  // set a2d prescale factor to 128
  // 16 MHz / 128 = 125 KHz, inside the desired 50-200 KHz range.
  // XXX: this will not work properly for other clock speeds, and
  // this code should use F_CPU to determine the prescale factor.
    sbi(ADCSRA, ADPS2);
  //    sbi(ADCSRA, ADPS0);

  // enable a2d conversions
  sbi(ADCSRA, ADEN);
	
}


void setUpSd() {
  /*  if (PIN_SD_CHIP_SELECT != PIN_SPI_CHIP_SELECT_REQUIRED) {
      pinMode(PIN_SPI_CHIP_SELECT_REQUIRED, OUTPUT);
  }

  if (!sd.begin(PIN_SD_CHIP_SELECT, SPI_QUARTER_SPEED)) {
    sd.initErrorHalt();
    }*/

  if(!sd.init(SPI_FULL_SPEED, PIN_SD_CHIP_SELECT))  // initialize SD card on the SPI bus - very important - was HALF_SPEED
  {
    delay(10);
    //    SDcardError();
  Serial.println("SDerror");
  }

}

/**
 * Redoes GPS configuration, assuming it has factory-default settings.
 *
 * Although this should only have to be done once, the GPS module sometimes
 * drops these customizations (possibly due to power brown-out).
 */
void resetGpsConfig() {
  digitalWrite(PIN_STATUS_LED, HIGH);
  nss.begin(DEFAULT_GPS_BAUD);
  nss.println("$PMTK314,0,5,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0*28");
  nss.println("$PMTK251,14400*29");
  nss.flush();
  nss.end();
  digitalWrite(PIN_STATUS_LED, LOW);

  nss.begin(GPS_BAUD);
}

void getFirstGpsSample() {
    nss.begin(GPS_BAUD);

  while (true) {
    readFromGpsUntilSampleTime();
    fillGpsSample(gps);
    if (sample.fix_age_ms == TinyGPS::GPS_INVALID_AGE) {
      Serial.println(F("Waiting for location fix."));
    } else if (sample.fix_age_ms == TinyGPS::GPS_INVALID_AGE) {
      Serial.println(F("Waiting for datetime fix."));
    } else {
      Serial.println(F("Got GPS fix."));
      break;
    }
  }
}

static void readFromGpsUntilSampleTime() {
  unsigned long start = millis();
  // Process a sample from the GPS every second.
  while (millis() - start < SAMPLE_INTERVAL_MS) {
    readFromGpsSerial();
  }
}

static bool readFromGpsSerial() {
  while (nss.available()) {
    //gps.encode(nss.read());

    char c = nss.read();
    // see what is HAPPENING TODO!
    //    Serial.write(c);
    gps.encode(c);
  }
}

static void startFilesOnSdNoSync() {
  // directory
  sprintf(
      buf,
      "%02d%02d%02d",
      sample.year,
      sample.month,
      sample.day);
  if (!sd.exists(buf)) {
    if (!sd.mkdir(buf)) {
      sd.errorHalt("Creating log directory for today failed.");
    }
  }

  // SdFat will silently die if given a filename longer than "8.3"
  // (8 characters, a dot, and 3 file-extension characters).

  // GPX log
  openTimestampedFile(".txt", gpxFile);
  /*  gpxFile.print(F(
    "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    "<gpx version=\"1.0\">\n"
    "\t<trk><trkseg>\n"));
  gpxFile.print(F(GPX_EPILOGUE));
  */
}

static void testopenSDfile(SdFile &file) {
  sprintf(
      buf,
      "testfile");
  Serial.print(F("Starting file "));
  Serial.println(buf);
  if (sd.exists(buf)) {
    Serial.println(F("warning: already exists, overwriting."));
  }
  if (!file.open(buf, O_CREAT | O_WRITE)) {
    sd.errorHalt();
  }
}

static void openTimestampedFile(const char *shortSuffix, SdFile &file) {
  sprintf(
      buf,
      "%02d%02d%02d/%02d%02d%02d%s",
      sample.year,
      sample.month,
      sample.day,
      sample.hour,
      sample.minute,
      sample.second,
      shortSuffix);
  Serial.print(F("Starting file "));
  Serial.println(buf);
  if (sd.exists(buf)) {
    Serial.println(F("warning: already exists, overwriting."));
  }
  if (!file.open(buf, O_CREAT | O_WRITE)) {
    sd.errorHalt();
  }
}

static void writeFloat(float v, SdFile &file, int precision) {
  obufstream ob(buf, sizeof(buf));
  ob << setprecision(precision) << v;
  file.print(buf);
}

static void writeFormattedSampleDatetime(SdFile &file) {
  sprintf(
      buf,
      "%04d-%02d-%02dT%02d:%02d:%02d.%03dZ",
      sample.year,
      sample.month,
      sample.day,
      sample.hour,
      sample.minute,
      sample.second,
      sample.hundredths);
  file.print(buf);
}

static void testwritesd(){
  sample.lat_deg=98.012f;
  gpxFile.print(F("lat=\""));
  writeFloat(sample.lat_deg, gpxFile, LATLON_PREC);
  gpxFile.print(F("\n"));

  //    digitalWrite(PIN_STATUS_LED, HIGH);
    if (!gpxFile.sync() || gpxFile.getWriteError()) {
      Serial.println(F("SD sync/write error."));
    }
    //    digitalWrite(PIN_STATUS_LED, LOW);
}

static void writeGpxSampleToSd() {
  /*  gpxFile.seekSet(gpxFile.fileSize() + SEEK_TRKPT_BACKWARDS);
  gpxFile.print(F("\t\t<trkpt "));

  gpxFile.print(F("lat=\""));
  writeFloat(sample.lat_deg, gpxFile, LATLON_PREC);
  gpxFile.print(F("\" lon=\""));
  writeFloat(sample.lon_deg, gpxFile, LATLON_PREC);
  gpxFile.print(F("\">"));
  getVoltageMaybeExit();

  gpxFile.print(F("<time>"));
  writeFormattedSampleDatetime(gpxFile);
  gpxFile.print(F("</time>"));

  if (sample.altitude_m != TinyGPS::GPS_INVALID_F_ALTITUDE) {
    gpxFile.print(F("<ele>")); // meters
    writeFloat(sample.altitude_m, gpxFile, 2 );
    gpxFile.print(F("</ele>"));
  }

  if (sample.speed_mps != TinyGPS::GPS_INVALID_F_SPEED) {
    gpxFile.print(F("<speed>"));
    writeFloat(sample.speed_mps, gpxFile, 1);
    gpxFile.print(F("</speed>"));
  }
  if (sample.course_deg != TinyGPS::GPS_INVALID_F_ANGLE) {
    gpxFile.print(F("<course>"));
    writeFloat(sample.course_deg, gpxFile, 1);
    gpxFile.print(F("</course>"));
  }

  if (sample.satellites != TinyGPS::GPS_INVALID_SATELLITES) {
    gpxFile.print(F("<sat>"));
    gpxFile.print(sample.satellites);
    gpxFile.print(F("</sat>"));
  }
  if (sample.hdop_hundredths != TinyGPS::GPS_INVALID_HDOP) {
    gpxFile.print(F("<hdop>"));
    writeFloat(sample.hdop_hundredths / 100.0, gpxFile, 2);
    gpxFile.print(F("</hdop>"));
  }

  gpxFile.print(F("</trkpt>\n"));

  gpxFile.print(F(GPX_EPILOGUE));

*/

  //  gpxFile.print(F("lat=\""));
  writeFloat(sample.lat_deg, gpxFile, LATLON_PREC);
  gpxFile.print(F(", "));
  writeFloat(sample.lon_deg, gpxFile, LATLON_PREC);
  gpxFile.print(F(", "));

  sprintf(
      buf,
      "%02d",randomm);
  gpxFile.print(buf);

  gpxFile.print(F(", "));
  writeFormattedSampleDatetime(gpxFile);
  gpxFile.print(F("\n"));

  Serial.println(F("writing"));
  
  digitalWrite(PIN_STATUS_LED, HIGH);
  if (!gpxFile.sync() || gpxFile.getWriteError()) {
    Serial.println(F("SD sync/write error."));
  }
  digitalWrite(PIN_STATUS_LED, LOW);
}

static void fillGpsSample(TinyGPS &gps) {
  gps.f_get_position(
      &sample.lat_deg,
      &sample.lon_deg,
      &sample.fix_age_ms);
  sample.altitude_m = gps.f_altitude();

  sample.satellites = gps.satellites();
  sample.hdop_hundredths = gps.hdop();

  sample.course_deg = gps.f_course();
  sample.speed_mps = gps.f_speed_mps();

  gps.crack_datetime(
      &sample.year,
      &sample.month,
      &sample.day,
      &sample.hour,
      &sample.minute,
      &sample.second,
      &sample.hundredths,
      &sample.datetime_fix_age_ms);
}

void setup() {
  pinMode(PIN_STATUS_LED, OUTPUT);
  digitalWrite(PIN_STATUS_LED, HIGH);
  Serial.begin(115200);
    setupadc(); // 
  
  
  setUpSd();
  getFirstGpsSample();
  startFilesOnSdNoSync(); //???
  
  
  digitalWrite(PIN_STATUS_LED, LOW);
}

void loop() {
  int y, accum, x, www, c, xx=0;
  /* WAS:  readFromGpsUntilSampleTime();
  fillGpsSample(gps);
  if (sample.fix_age_ms <= SAMPLE_INTERVAL_MS) {
    writeGpxSampleToSd();
    }*/
  digitalWrite(PIN_STATUS_LED, HIGH);
  
  writeGpxSampleToSd();
  
  // do our random thing which takes 200x 16ms = 3.2s but looks like 3.7s
  accum=0;
// how long does this take?
  unsigned long start = millis();
  for (y=0;y<200;y++){

    for (x=0;x<166;x++){
      //      www = analogRead(0); // takes 0.1 ms so 166 is 16ms
      sbi(ADCSRA, ADSC);
      while (bit_is_set(ADCSRA, ADSC));
      www = ADCH;
      if (www&0x01) xx++;
    }
    accum+=(xx&0x01);
    xx=0;
  }

	randomm=accum;
	//  delay(1000);
	/*		Serial.print(randomm);
		Serial.print(" ,");
		Serial.println(millis()-start);*/
  digitalWrite(PIN_STATUS_LED, LOW);
  // say 2 second sampling 8313, antenna, FGM then gps read, write sd, then reset FGM counters!

}
