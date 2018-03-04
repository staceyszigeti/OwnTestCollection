#include <SoftwareSerial.h>
static const int RXPin = 4, TXPin = 5;
SoftwareSerial ss(RXPin, TXPin);

String readString;

void setup()
{
  Serial.begin(9600);
  ss.begin(9600);

  Serial.print("$PMTK251,38400*27\r\n");

  delay(100);
 
  Serial.begin(38400);
  ss.begin(38400);

  Serial.print("$PMTK313,1*2E\r\n");  
  Serial.print("$PMTK301,1*2D\r\n");
  Serial.print("$PMTK220,100*2F\r\n");
  Serial.print("$PMTK314,1,1,1,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0*2C\r\n");
}

void loop()
{
  
while (Serial.available() > 0)
      Serial.write(Serial.read());

}

