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


    data = String(awa.value()) + "," + String(aws.value()) + "," + String(windRef.value());


    while (ss.available() > 0)
    nexus.encode(ss.read());

    
}

void doSomething()
{


    Serial.println(data);

}
