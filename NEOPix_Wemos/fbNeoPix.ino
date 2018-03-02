void fbNeoPix(String wait, String color, unsigned int brightness){
    unsigned int c1 = 0;
    unsigned int c2 = 0;
    unsigned int c3 = 0;
    unsigned int iWait = 0;

    if (wait == "SLOW") {
      iWait = 1500;
    };

    if (wait == "MEDIUM") {
      iWait = 750;
    };

    if (wait == "FAST") {
      iWait = 300;
    };

    if (color == "RED") {
      c1 = 255;
      c2 = 0;
      c3 = 0;
    };

    if (color == "GREEN") {
      c1 = 0;
      c2 = 255;
      c3 = 0;
    };

    if (color == "BLUE") {
      c1 = 0;
      c2 = 0;
      c3 = 255;
    };

    if (color == "YELLOW") {
      c1 = 255;
      c2 = 255;
      c3 = 0;
    };

    if (color == "ORANGE") {
      c1 = 255;
      c2 = 133;
      c3 = 25;
    };
    
    unsigned long currentMillis = millis();
    interval = iWait;

    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (ledState == LOW) {
      pixels.setBrightness(brightness); // 0-255
      pixels.setPixelColor(0, pixels.Color(c1,c2,c3)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      ledState = HIGH;
    } else {
      pixels.setPixelColor(0, pixels.Color(0,0,0)); // Moderately bright green color.
      pixels.setBrightness(0); // 0-255
      pixels.show(); // This sends the updated pixel color to the hardware.
      ledState = LOW;
    }

  }

};

void fbNeoPixStatus(int Status){
    unsigned int c1 = 0;
    unsigned int c2 = 0;
    unsigned int c3 = 0;
    unsigned int iWait = 0;
    unsigned int brightness = 75;

    switch (Status) {
    //Init fail
    case 0:
       pixels.setBrightness(brightness); // 0-255
       pixels.setPixelColor(0, pixels.Color(255,0,0)); // Moderately bright green color.
       pixels.show(); // This sends the updated pixel color to the hardware.
      break;
    //SD card not present
    case 10:
       c1 = 255;
       c2 = 0;
       c3 = 0;
       iWait = 300;
      break;
    //SD card full
    case 20:
       c1 = 255;
       c2 = 0;
       c3 = 0;
       iWait = 750;
      break;
    //Standby      
    case 30:
       c1 = 255;
       c2 = 255;
       c3 = 0;
       iWait = 750;
      break;
    //Standby (GPS has fix)
    case 40:
       c1 = 0;
       c2 = 0;
       c3 = 250;
       iWait = 750;
      break;
    //Logging
    case 50:
       c1 = 0;
       c2 = 255;
       c3 = 0;
       iWait = 1500;
      break;
    //Battery medium (while logging)
    case 510:
       c1 = 255;
       c2 = 133;
       c3 = 25;
       iWait = 750;
      break;
    //Battery low (while logging)
    case 520:
       c1 = 255;
       c2 = 133;
       c3 = 25;
       iWait = 300;
      break;      
    };

    unsigned long currentMillis = millis();
    interval = iWait;

    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

      if (ledState == LOW) {
        pixels.setBrightness(brightness); // 0-255
        pixels.setPixelColor(0, pixels.Color(c1,c2,c3)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
        ledState = HIGH;
      } else {
        pixels.setPixelColor(0, pixels.Color(0,0,0)); // Moderately bright green color.
        pixels.setBrightness(0); // 0-255
        pixels.show(); // This sends the updated pixel color to the hardware.
        ledState = LOW;
      };

    };

};
