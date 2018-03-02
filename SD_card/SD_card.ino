
#include <SPI.h>
#include <SD.h>

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = D0;

void setup()
{
  Serial.begin(9600);
  InitSD();
}


void loop(void) {
 Serial.println(SDFreeSize());
 delay(2000);

}
