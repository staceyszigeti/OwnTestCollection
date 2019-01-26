int inPin = D0;  // the pin number for input (for me a push button)
int ledPin = D4; 

int current;         // Current state of the button
                     // (LOW is pressed b/c i'm using the pullup resistors)
long millis_held;    // How long the button was held (milliseconds)
long secs_held;      // How long the button was held (seconds)
long prev_secs_held; // How long the button was held in the previous check
byte previous = LOW;
unsigned long firstTime; // how long since the button was first pressed 


#define LED_PIN           D4
//LED-timer
int ledState = LOW; 
uint32_t previousMillisLedTimer = 1;
uint32_t currentMillisLedTimer = 1;
const uint16_t intervalLedTimer = 1000;

void setup() {
  Serial.begin(38400);         // Use serial for debugging
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT_PULLUP);
  //digitalWrite(inPin, LOW);  // Turn on 20k pullup resistors to simplify switch input
  digitalWrite(LED_PIN, HIGH); //Nem világít (SBU21)
}

void loop() {
  current = digitalRead(inPin);

  // if the button state changes to pressed, remember the start time 
  if (current == HIGH && previous == LOW && (millis() - firstTime) > 200) {
    firstTime = millis();
  }

  millis_held = (millis() - firstTime);
  secs_held = millis_held / 1000;

  // This if statement is a basic debouncing tool, the button must be pushed for at least
  // 100 milliseconds in a row for it to be considered as a push.
  if (millis_held > 50) {

    if (current == LOW && secs_held > prev_secs_held) {
      secs_held =0;
      prev_secs_held = 0;
    }

    // check if the button was released since we last checked
    if (current == HIGH) {

      // If the button was held for 3-6 seconds blink LED 10 times
      if (secs_held >= 2 && secs_held < 10) {
        ledBlink(HIGH, 1500, LED_PIN);
        Serial.print("   Milliseconds held: ");
      }

      // If the button was held for 3-6 seconds blink LED 10 times
      if (secs_held > 15) {
        secs_held =0;
        prev_secs_held = 0;
      }

      // ===============================================================================
    }
  }

  Serial.println(secs_held);
  Serial.println(current);
  

  previous = current;
  prev_secs_held = secs_held;
}

// Just a simple helper function to blink an led in various patterns
/*void ledblink(int times, int lengthms, int pinnum){
  for (int x=0; x<times;x++) {
    digitalWrite(pinnum, HIGH);
    delay (lengthms);
    digitalWrite(pinnum, LOW);
    delay(lengthms);
  }
};*/


void ledBlink(boolean enable, uint16_t lengthms, uint8_t pinnum){

  if (enable == HIGH) {
    if (currentMillisLedTimer - previousMillisLedTimer >= lengthms) {
      previousMillisLedTimer = currentMillisLedTimer;
  
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
      digitalWrite(pinnum, ledState);
    };
  } else {
    previousMillisLedTimer = currentMillisLedTimer;
  };
};
