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
  

    while (ss.available() > 0)
    nexus.encode(ss.read());
  
/*while (ss.available() > 0)
      Serial.write(ss.read());*/

}

void doSomething()
{
  if (HIGH) {
    data = String(awa.value()) + "," + String(aws.value()) + "," + String(windRef.value());
  };
  
    /*Serial.print(F(" AWA=")); Serial.print(awa.value()); 
    Serial.print(F(" AWS=")); Serial.print(aws.value()); 
    Serial.print(F(" AWA1=")); Serial.print(aw1.value()); 
    Serial.print(F(" AWS2=")); Serial.print(aw2.value()); 
    Serial.print(F(" AWA3=")); Serial.print(aw3.value()); 
    Serial.print(F(" AWS4=")); Serial.print(aw4.value()); 
    Serial.print(F(" AWS5=")); Serial.println(aw5.value()); */

    Serial.println(data);

}
