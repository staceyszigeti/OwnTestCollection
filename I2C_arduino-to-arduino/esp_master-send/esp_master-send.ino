#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C

int x = 3;

void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  
  // put your setup code here, to run once:
  Wire.begin(10);               // join i2c bus (address optional for master)
  };

}

void loop() {
  // put your main code here, to run repeatedly:

    /*Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! 
    Serial.println(" m");

    Serial.println();*/
  
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(x);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    
    delay(1000);

}
