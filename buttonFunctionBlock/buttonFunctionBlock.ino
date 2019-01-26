int inPin = D0;  // the pin number for input (for me a push button)
int ledPin = D4; 

int current;         // Current state of the button
long millis_held;    // How long the button was held (milliseconds)
long secs_held;      // How long the button was held (seconds)
long prev_secs_held; // How long the button was held in the previous check
byte previous = LOW;
unsigned long firstTime; // how long since the button was first pressed 
boolean output = LOW;
boolean segedvaltozo = LOW;

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
  currentMillisLedTimer = millis();

  // if the button state changes to pressed, remember the start time 
  if (current == HIGH && previous == LOW && (millis() - firstTime) > 200) {
    firstTime = millis();
  }

  millis_held = (millis() - firstTime);
  secs_held = millis_held / 1000;

  if (millis_held > 50) {

    if (current == LOW && secs_held > prev_secs_held) {
      secs_held =0;
      prev_secs_held = 0;
    };

    if (current == HIGH) {

      if (secs_held >= 2 && segedvaltozo == LOW) {
        output = !output;
        segedvaltozo = HIGH;
      };

      if (secs_held < 2 && segedvaltozo == HIGH) {
        output = !output;
        segedvaltozo = LOW;
        secs_held =0;
        prev_secs_held = 0;
      };
    };
  };

  previous = current;
  prev_secs_held = secs_held;

  ledBlink(output, 100, ledPin);
  Serial.println(output);
};

void ledBlink(boolean enable, uint16_t lengthms, uint8_t pinnum){

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
