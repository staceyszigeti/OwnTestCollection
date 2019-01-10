
// Program to compare the size of SdFat with the SD.h library.
// Select the test library by commenting out one of the following two lines.
// #include <SD.h>
#include <SdFat.h>

// SD chip select pin.
const uint8_t SD_CS_PIN = D0;

SdFat SD;
SdFile file;
String dest = "20190110-2323";
char Str4[ ] = "arduini.txt";

void setup() {
  Serial.begin(9600);
  while (!Serial) {}  // wait for Leonardo

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("begin failed");
    return;
  };
  
  
  file.open(Str4, O_RDWR | O_CREAT);

  
  file.println("Hello");
  file.close();
  Serial.println("Done");
}
//------------------------------------------------------------------------------
void loop() {}
