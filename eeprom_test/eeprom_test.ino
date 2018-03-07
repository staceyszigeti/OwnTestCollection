/*
 * EEPROM Write
 *
 * Stores values read from analog input 0 into the EEPROM.
 * These values will stay in the EEPROM when the board is
 * turned off and may be retrieved later by another sketch.
 */

#include <EEPROM.h>

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int addr = 0;

void setup()
{
  Serial.begin(9600);
  EEPROM.begin(512);
}

void loop()
{
  eepromWrite(1, 1);

  /*delay(2000);

  Serial.println(eepromRead(11));*/

  delay(2000);
}

boolean eepromWrite(byte addr, byte val) {
  
  EEPROM.write(addr, val);

  if (EEPROM.commit()) {
    return HIGH;
  } else {
    return LOW;
  };
  
};

int eepromRead(byte addr) {
  
  if (EEPROM.read(addr)) {
    return EEPROM.read(addr);
  } else {
    return -1;
  };
  
  /*byte value = EEPROM.read(addr);

  return value;*/
  
  
};
