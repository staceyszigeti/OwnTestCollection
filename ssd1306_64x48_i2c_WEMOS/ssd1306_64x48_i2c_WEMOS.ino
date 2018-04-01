/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 64x48 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// SCL GPIO5
// SDA GPIO4
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 48)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
  // init done

  // Show image buffer on the display hardware.k
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  drawBitMap(1,16);
  display.display();
  delay(2000);

  // text display tests
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.println("N");
  display.setCursor(8,0);
  display.println("47.505198");

  display.setCursor(0,8);
  display.println("E");
  display.setCursor(8,8);
  display.println("19.066825");
  
  display.setCursor(0,16);
  display.println("BSP:");
  display.setCursor(34,16);
  display.println("xxx.x");
  
  display.setCursor(0,24);
  display.println("Status:");
  display.setCursor(52,24);
  display.println("40");
  
  display.setCursor(0,32);
  display.println("Pitch:");
  display.setCursor(34,32);
  display.println("xxx.x");
  
  display.setCursor(0,40);
  display.println("Roll:");
  display.setCursor(34,40);
  display.println("xxx.x");
  
  display.display();
  
}


void loop() {



}

const unsigned char PROGMEM fly [] = {
  // size is 64 x 25 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
0x18, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x10, 0x00, 0xC0, 0x00, 0x40, 0x00, 0x00, 0x00,
0x10, 0x00, 0xE0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x10, 0x01, 0xF0, 0x38, 0x79, 0x79, 0x79, 0x78,
0x10, 0x03, 0xF8, 0x40, 0x41, 0x81, 0x81, 0x80, 0x10, 0x03, 0xF8, 0x40, 0x41, 0x01, 0x01, 0x00,
0x10, 0x07, 0xFC, 0x20, 0x41, 0x01, 0x01, 0x00, 0x10, 0x0F, 0xFC, 0x18, 0x41, 0x01, 0x01, 0x00,
0x10, 0x0F, 0xFC, 0x0C, 0x41, 0x01, 0x01, 0x00, 0x1E, 0x1C, 0x7C, 0x02, 0x41, 0x01, 0x01, 0x00,
0x10, 0x00, 0x00, 0x02, 0x41, 0x01, 0x01, 0x00, 0x10, 0x3F, 0xE0, 0x02, 0x41, 0x01, 0x01, 0x00,
0x10, 0x00, 0x18, 0xC4, 0x21, 0x01, 0x01, 0x00, 0x00, 0x0E, 0x00, 0x78, 0x18, 0x00, 0x00, 0x00,
0x00, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xF8, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x80, 0x00, 
};

void drawBitMap(int x, int y)
{
  display.drawBitmap(x, y,  fly, 64, 25, 1);
  
}


void testscrolltext(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("scroll");
  display.display();
  delay(1);

  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}
