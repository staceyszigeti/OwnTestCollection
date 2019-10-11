#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

int x = 3;

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  
  // put your setup code here, to run once:
  Wire.begin(10);               // join i2c bus (address optional for master)
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
}

void loop() {
  // put your main code here, to run repeatedly:

}
