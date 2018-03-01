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
    fbNeoPixStatus(1);
    Serial.println("1");
  };
  if (millis() > 5000 && millis() < 10000) {
    fbNeoPixStatus(2);
    Serial.println("2");
  };
  if (millis() > 10000 && millis() < 15000) {
    fbNeoPixStatus(3);
    Serial.println("3");
  };
  if (millis() > 15000 && millis() < 20000) {
    fbNeoPixStatus(4);
    Serial.println("4");
  };
  if (millis() > 20000 && millis() < 25000) {
    fbNeoPixStatus(5);
    Serial.println("5");
  };
  if (millis() > 25000 && millis() < 30000) {
    fbNeoPixStatus(51);
    Serial.println("51");
  };
  if (millis() > 30000 && millis() < 35000) {
    fbNeoPixStatus(52);
    Serial.println("52");
  };

}
