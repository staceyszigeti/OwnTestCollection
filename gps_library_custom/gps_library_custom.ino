 #include <TinyGPS++.h>
/*
   This sample code demonstrates the normal use of a TinyGPS++ (TinyGPSPlus) object.
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/
long previousMillis = 0;
long interval = 3000;

// The TinyGPS++ object
TinyGPSPlus gps;

TinyGPSCustom gpsDate(gps, "GPRMC", 9);
TinyGPSCustom gpsTime(gps, "GPRMC", 1);
TinyGPSCustom gpsLat(gps, "GPRMC", 3);
TinyGPSCustom gpsLon(gps, "GPRMC", 5);

/*

    Serial.print(F(" PDOP=")); Serial.print(pdop.value()); 
    Serial.print(F(" HDOP=")); Serial.print(hdop.value()); 
    Serial.print(F(" VDOP=")); Serial.print(vdop.value());
 
 */

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Sats HDOP  Latitude   Longitude   Fix  Date       Time     Date Alt    Course Speed Card  Distance Course Card  Chars Sentences Checksum"));
  Serial.println(F("           (deg)      (deg)       Age                      Age  (m)    --- from GPS ----  ---- to London  ----  RX    RX        Fail"));
  Serial.println(F("----------------------------------------------------------------------------------------------------------------------------------------"));
}

void loop() 
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis;
    Serial.print(F(" Date=")); Serial.print(gpsDate.value()); 
    Serial.print(F(" Time=")); Serial.print(gpsTime.value()); 
    Serial.print(F(" Lat=")); Serial.print(gpsLat.value());
    Serial.print(F(" Lon=")); Serial.println(gpsLon.value());
  }

  while (Serial.available() > 0)
    gps.encode(Serial.read());
}


