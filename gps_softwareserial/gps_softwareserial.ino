#include <SoftwareSerial.h>
SoftwareSerial ss(D3, D2); //wemosnál a nexus syerverrel

void setup()
{
  Serial.begin(9600);
  ss.begin(4800);
}

void loop()
{
  
while (ss.available() > 0)
      Serial.write(ss.read());

}

