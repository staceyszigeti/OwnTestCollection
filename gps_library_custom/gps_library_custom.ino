 #include <TinyGPS++.h>

//--GPS dekralálás----------------------------
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

long previousMillis = 0;

TinyGPSPlus gps;

TinyGPSCustom gpsTime(gps,        "GPRMC", 1);
TinyGPSCustom gpsStatus(gps,      "GPRMC", 2);  // Active o. Void
TinyGPSCustom gpsLat(gps,         "GPRMC", 3 );
TinyGPSCustom gpsLon(gps,         "GPRMC", 5);
TinyGPSCustom gpsDate(gps,        "GPRMC", 9);

TinyGPSCustom gps3DFix(gps,       "GPGSA", 2); // 1 = no fix, 2 = 2D fix, 3 = 3D fix

TinyGPSCustom gpsFixQuality(gps,  "GPGGA", 6); // 0 = invalid, 1 = GPS fix (SPS), 2 = DGPS fix, 3 = PPS fix, 4 = Real Time Kinematic, 5 = Float RTK, 6 = estimated (dead reckoning), 7 = Manual input mode, 8 = Simulation mode
TinyGPSCustom gpsSatNum(gps,      "GPGGA", 7);
TinyGPSCustom gpsHDOP(gps,        "GPGGA", 8 );

TinyGPSCustom gpsCOG(gps,         "GPVTG", 1);
TinyGPSCustom gpsSOG(gps,         "GPVTG", 5);

void setup()
{
  Serial.begin(9600);
}

void loop() 
{

  //Serial.println(fbGPSEncode(1000));
  fbGPSEncode(1000);

}


