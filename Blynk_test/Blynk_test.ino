/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk lets you create beautiful drag-and-drop visual interfaces
  for your projects in 5 minutes. And it works with almost every
  hardware out there.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  You’ll need:
   - Blynk App (download from AppStore or Google Play)
   - Arduino UNO or similar microcontroller board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************

 Let’s turn ON your LED with Blynk!
 In this example we'll use Arduino UNO + Ethernet Shield

 5 Steps guide:

  1. Connect LED to Pin 9
  ( http://arduino.cc/en/uploads/Tutorial/simplefade_bb.png )

 In the Blynk App:
  2. Create New Project
  3. Email yourself Auth Token. You can do it later at any time
  4. Add a Button Widget. Select Pin D9 in Widget's Settings
  5. Press Play icon. Enjoy Blynking!

  You can find a QR code for easy setup of this project here:
  https://github.com/blynkkk/blynk-library/tree/master/examples/GettingStarted/BlynkBlink

 *************************************************************/

#define BLYNK_PRINT Serial // Enables Serial Monitor

// Following includes are for Arduino Ethernet Shield (W5100)
// If you're using another shield, see Boards_* examples
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "f232e41a757945378ec2dff5e9e106bf";
char ssid[] = "UPC2D87C5A";
char pass[] = "Ha7twFejvahm";

/*char ssid[] = "LenovoA5000";
char pass[] = "ac45catamaran";*/

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, millis() / 10);
}

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, pass);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  
  
  Blynk.config(auth);  // in place of Blynk.begin(auth, ssid, pass);
  Blynk.connect(3333);  // timeout set to 10 seconds and then continue without Blynk
  while (Blynk.connect() == false) {
    // Wait until connected
  }
  Serial.println("Connected to Blynk server");
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  // All the Blynk Magic happens here...
  Blynk.run();
  timer.run(); // Initiates BlynkTimer

  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

