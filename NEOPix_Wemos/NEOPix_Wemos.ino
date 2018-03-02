// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>

#define PIN            D8
#define NUMPIXELS      1
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);




//fbNeoPix parameters
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned int interval = 1000;           // interval at which to blink (milliseconds)
boolean ledState = LOW;

void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
}

void loop() {

  //fbNeoPix("SLOW","ORANGE",50);

  if (millis() < 0) {
    fbNeoPixStatus(0);
    Serial.println("0");
  };
  if (millis() > 2500 && millis() < 5000) {
    fbNeoPixStatus(10);
    Serial.println("10");
  };
  if (millis() > 5000 && millis() < 10000) {
    fbNeoPixStatus(20);
    Serial.println("20");
  };
  if (millis() > 10000 && millis() < 15000) {
    fbNeoPixStatus(30);
    Serial.println("30");
  };
  if (millis() > 15000 && millis() < 20000) {
    fbNeoPixStatus(40);
    Serial.println("40");
  };
  if (millis() > 20000 && millis() < 25000) {
    fbNeoPixStatus(50);
    Serial.println("50");
  };
  if (millis() > 25000 && millis() < 30000) {
    fbNeoPixStatus(510);
    Serial.println("510");
  };
  if (millis() > 30000 && millis() < 35000) {
    fbNeoPixStatus(520);
    Serial.println("520");
  };

}
