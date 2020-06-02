/* we are editing externally
 */

#include <ICEClass.h>
#include "/root/notes_and_projectsNOW/FPGA/doppler_test/doppler_test.h"
ICEClass ice40;

void setup() {

  ice40.upload(doppler_test_bin,sizeof(doppler_test_bin)); // Upload BitStream Firmware to FPGA -> see variant.h
  //  ice40.upload(); // Upload BitStream Firmware to FPGA -> see variant.h
  ice40.initSPI();  // start SPI runtime Link to FPGA
}

void loop() {
  static uint16_t x = 0, val;
  val = analogRead(0);
  val*=2;
  ice40.sendSPI16(val);
  delay(50);
}
