boolean fbGPSEncode(unsigned int interval) {
   
    unsigned long currentMillis = millis();
    
  if (currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis;

    sGpsDate = gpsDate.value();
    sGpsDate = sGpsDate.substring(4,6) + sGpsDate.substring(2,4) + sGpsDate.substring(0,2);
    sGpsTime = gpsTime.value();
    sGpsLat = String(gps.location.lat(),6);
    sGpsLon = String(gps.location.lng(),6);
    sGpsStatus = gpsStatus.value();
    sGps3DFix = gps3DFix.value();
    sGpsFixQuality = gpsFixQuality.value();
    sGpsSatNum = gpsSatNum.value();
    sGpsHDOP = gpsHDOP.value();
    sGpsCOG = gpsCOG.value();
    sGpsSOG = gpsSOG.value();  


    Serial.print(F(" Date=")); Serial.println(sGpsDate); //Date=040318
    Serial.print(F(" Time=")); Serial.println(sGpsTime); //Time=130257.000
    Serial.print(F(" Lat=")); Serial.println(sGpsLat); //Lat=4728.7030
    Serial.print(F(" Lon=")); Serial.println(sGpsLon); //Lon=01904.1980

    Serial.print(F(" Status=")); Serial.println(sGpsStatus); //A
    Serial.print(F(" 3DFix=")); Serial.println(sGps3DFix); //3DFix=3
    Serial.print(F(" FixQuality=")); Serial.println(sGpsFixQuality); // FixQuality=2
    Serial.print(F(" #SAT=")); Serial.println(sGpsSatNum); // #SAT=08
    Serial.print(F(" HDOP=")); Serial.println(sGpsHDOP); // HDOP=1.10

    Serial.print(F(" COG=")); Serial.println(sGpsCOG); //  COG=25.25
    Serial.print(F(" SOG=")); Serial.println(sGpsSOG); // SOG=0.34

    Serial.print(F("#Char ")); Serial.println(gps.charsProcessed());
    Serial.print(F("#Fix ")); Serial.println(gps.sentencesWithFix());
    Serial.print(F("#Fail ")); Serial.println(sGpsFailCheksum);

    Serial.println("-GPS start----------------------------------------------------------");

    /*Serial.println(gps.location.lat(), 6); // Latitude in degrees (double); 47.478382
    Serial.println(gps.location.lng(), 6); // Longitude in degrees (double); 19.069967
    Serial.println(gps.location.rawLat().negative ? "-" : "+"); // +
    Serial.println(gps.location.rawLng().negative ? "-" : "+"); // +
    Serial.println(gps.date.value()); // Raw date in DDMMYY format (u32); 40318
    Serial.println(gps.date.year()); // Year (2000+) (u16); 2018
    Serial.println(gps.date.month()); // Month (1-12) (u8); 3
    Serial.println(gps.date.day()); // Day (1-31) (u8); 4
    Serial.println(gps.time.value()); // Raw time in HHMMSSCC format (u32); 13025700
    Serial.println(gps.time.hour()); // Hour (0-23) (u8); 13
    Serial.println(gps.time.minute()); // Minute (0-59) (u8); 2
    Serial.println(gps.time.second()); // Second (0-59) (u8); 57
    Serial.println(gps.time.centisecond()); // 100ths of a second (0-99) (u8); 0
    Serial.println(gps.speed.knots()); // Speed in knots (double); 0.28
    Serial.println(gps.course.deg()); // Course in degrees (double); 56.65
    Serial.println(gps.satellites.value()); // Number of satellites in use (u32); 8 
    Serial.println(gps.hdop.value()); // Horizontal Dim. of Precision (100ths-i32); 110*/

    Serial.println("-----------------------------------------------------------");

    /*Serial.print(F(" Date=")); Serial.println(gpsDate.value()); //Date=040318
    Serial.print(F(" Time=")); Serial.println(gpsTime.value()); //Time=130257.000
    Serial.print(F(" Lat=")); Serial.println(gpsLat.value()); //Lat=4728.7030
    Serial.print(F(" Lon=")); Serial.println(gpsLon.value()); //Lon=01904.1980

    Serial.print(F(" Status=")); Serial.println(gpsStatus.value()); //A
    Serial.print(F(" 3DFix=")); Serial.println(gps3DFix.value()); //3DFix=3
    Serial.print(F(" FixQuality=")); Serial.println(gpsFixQuality.value()); // FixQuality=2
    Serial.print(F(" #SAT=")); Serial.println(gpsSatNum.value()); // #SAT=08
    Serial.print(F(" HDOP=")); Serial.println(gpsHDOP.value()); // HDOP=1.10

    Serial.print(F(" COG=")); Serial.println(gpsCOG.value()); //  COG=25.25
    Serial.print(F(" SOG=")); Serial.println(gpsSOG.value()); // SOG=0.34

    Serial.print(F("#Char ")); Serial.println(gps.charsProcessed());
    Serial.print(F("#Fix ")); Serial.println(gps.sentencesWithFix());
    Serial.print(F("#Fail ")); Serial.println(gps.failedChecksum());*/

    Serial.println("-GPS vege----------------------------------------------------------");
  };

  sGpsFailCheksum = gps.failedChecksum();

  while (Serial.available() > 0)
  {
    gps.encode(Serial.read());
  };

  if ((sGpsStatus == "V") || (millis() < 2500))
  {
    return LOW;
  };
  
    return HIGH;
};

