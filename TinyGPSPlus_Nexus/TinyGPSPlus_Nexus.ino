#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include "Timer.h"
SoftwareSerial ss(D3, D4); //wemosnál a nexus syerverrel

Timer t;

TinyGPSPlus nexus;
TinyGPSCustom awa(nexus, "IIMWV", 1); // Wind Direction
TinyGPSCustom windRef(nexus, "IIMWV", 2); // Direction Reference
TinyGPSCustom aws(nexus, "IIMWV", 3); // Wind Speed
TinyGPSCustom windUnit(nexus, "IIMWV", 4); // Speed Units
TinyGPSCustom windStatus(nexus, "IIMWV", 5); // Sensor Status

TinyGPSCustom gpsTime(nexus,        "GPRMC", 1);
TinyGPSCustom gpsStatus(nexus,      "GPRMC", 2);  // Active o. Void
TinyGPSCustom gpsLat(nexus,         "GPRMC", 3);
TinyGPSCustom gpsLon(nexus,         "GPRMC", 5);
TinyGPSCustom gpsDate(nexus,        "GPRMC", 9);

TinyGPSCustom gps3DFix(nexus,       "GPGSA", 2); // 1 = no fix, 2 = 2D fix, 3 = 3D fix

TinyGPSCustom gpsFixQuality(nexus,  "GPGGA", 6); // 0 = invalid, 1 = GPS fix (SPS), 2 = DGPS fix, 3 = PPS fix, 4 = Real Time Kinematic, 5 = Float RTK, 6 = estimated (dead reckoning), 7 = Manual input mode, 8 = Simulation mode
TinyGPSCustom gpsSatNum(nexus,      "GPGGA", 7);
TinyGPSCustom gpsHDOP(nexus,        "GPGGA", 8 );

TinyGPSCustom gpsCOG(nexus,         "GPVTG", 1);
TinyGPSCustom gpsSOG(nexus,         "GPVTG", 5);

String sGpsDate = "";
String sGpsTime = "";
String sGpsLat = "";
String sGpsLon = "";
String sGpsStatus = "";
String sGps3DFix = "";
String sGpsFixQuality = "";
String sGpsSatNum = "";
String sGpsHDOP = "";
String sGpsCOG = "";
String sGpsSOG = "";
String sGpsFailCheksum = "";


String data = "";

void setup()
{
  Serial.begin(9600);
  ss.begin(4800);
  int tickEvent = t.every(2000, doSomething);
}

void loop()
{
      t.update();

    sGpsTime = nexus.time.value();
    sGpsDate = nexus.date.value();
    sGpsCOG = String(nexus.course.deg());
    sGpsSOG = String(nexus.speed.value()); 
    
    data = sGpsDate + "," + sGpsTime + "," + sGpsLat + "," + sGpsLon + "," + String(awa.value()) + "," + String(aws.value()) + "," + String(windRef.value());


    while (ss.available() > 0)
    nexus.encode(ss.read());

    
}

void doSomething()
{


    Serial.println(data);

}
