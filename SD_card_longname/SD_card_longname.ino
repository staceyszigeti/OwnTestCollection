
// Program to compare the size of SdFat with the SD.h library.
// Select the test library by commenting out one of the following two lines.
// #include <SD.h>
#include <SdFat.h>

// SD chip select pin.
const uint8_t SD_CS_PIN = D0;

SdFat SD;
SdFile file;
String dest = "20190110-2323";
char Str4[ ] = "20190122-2337";
char datalog[88] = "$0;0000-00-00;00:00:00.000;00.0;000;+;0.000001;+;0.000001;000.0;000.0;000.0;00;00.0;000";

void setup() {
  Serial.begin(9600);
  while (!Serial) {}  // wait for Leonardo

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("begin failed");
    return;
  };
  
  file.open(Str4, O_RDWR | O_CREAT);

  
  file.println(String(datalog));
  file.close();
  Serial.println("Done");
 
  //dataString = "$"+sGps3DFix+";"+sGpsDate+";"+sGpsTime+";"+sGpsSOG+";"+sGpsCOG+";N;"+sGpsLat+";E;"+sGpsLon+";"+sPitch+";"+sRoll+";0000>"+sAccX+";"+sAccY+";"+sGpsFixQuality+";"+sGpsSatNum+";"+sGpsHDOP+";"+String(cycleTime)+">";

}
//------------------------------------------------------------------------------
void loop() {}
