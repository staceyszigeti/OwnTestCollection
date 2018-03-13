
#include <SPI.h>
#include <SD.h>

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = D0;

String dataString = "$F;0000-00-00;00:00:00;00.0;000;x;0.000001;x;0.000001;00;0000;0000>000;00.0;x;0;00;00.0;00.0;000;0<";

void setup()
{
  Serial.begin(9600);
  InitSD();
}


void loop(void) {
 //Serial.println(SDFreeSize());
 int s = millis();
 
 Serial.println(SDCardWrite("asd123.log", 101));
 
 Serial.println(millis()-s);

}
