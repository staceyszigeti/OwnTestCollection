boolean Button(uint8_t hold_time) {

  /*-----Szükséges globális változók:---------------
  boolean   previousButtonState = LOW;
  uint32_t  millis_held;                // How long the button was held (milliseconds)
  uint8_t   secs_held;                  // How long the button was held (seconds)
  uint8_t   prev_secs_held;             // How long the button was held in the previous check
  uint32_t  firstTime;                  // how long since the button was first pressed 
  boolean   output =              LOW;
  boolean   toogleVariable =      LOW;
  //------------------------------------------------
  Az alábbi sort, a Loop() első sorába kell rakni:
  
  currentButtonState = digitalRead(inPin);
  //------------------------------------------------*/
  

  if (currentButtonState == HIGH && previousButtonState == LOW && (millis() - firstTime) > 200) {
    firstTime = millis();
  }

  millis_held = (millis() - firstTime);
  secs_held = millis_held / 1000;

  if (millis_held > 50) {

    if (currentButtonState == LOW && secs_held > prev_secs_held) {
      secs_held =0;
      prev_secs_held = 0;
    };

    if (currentButtonState == HIGH) {

      if (secs_held >= hold_time && toogleVariable == LOW) {
        output = !output;
        toogleVariable = HIGH;
      };

      if (secs_held < hold_time && toogleVariable == HIGH) {
        output = !output;
        toogleVariable = LOW;
        secs_held =0;
        prev_secs_held = 0;
      };
    };
  };

  previousButtonState = currentButtonState;
  prev_secs_held = secs_held;
  return output;
};

void ledBlink(boolean enable, uint16_t lengthms, uint8_t pinnum){

  /*-----Szükséges globális változók:---------------
  boolean         ledState =                 LOW; 
  uint32_t        previousMillisLedTimer =   1;
  uint32_t        currentMillisLedTimer =    1;
  const uint16_t  intervalLedTimer =         1000;
  //------------------------------------------------
  Az alábbi sort, a Loop() első sorába kell rakni:
  
  currentMillisLedTimer = millis();
  //------------------------------------------------*/

  if (enable == HIGH) {
    if (currentMillisLedTimer - previousMillisLedTimer >= lengthms) {
      previousMillisLedTimer = currentMillisLedTimer;
  
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      };
    };
  } else {
    previousMillisLedTimer = currentMillisLedTimer;
    ledState = HIGH;
  };
  
  digitalWrite(pinnum, ledState);
};
