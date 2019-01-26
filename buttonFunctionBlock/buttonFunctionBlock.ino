int inPin = D0;  // the pin number for input (for me a push button)
int ledPin = D4; 

boolean   currentButtonState;         // Current state of the button
boolean   previousButtonState = LOW;
uint32_t  millis_held;                // How long the button was held (milliseconds)
uint8_t   secs_held;                  // How long the button was held (seconds)
uint8_t   prev_secs_held;             // How long the button was held in the previous check
uint32_t  firstTime;                  // how long since the button was first pressed 
boolean   output =              LOW;
boolean   toogleVariable =      LOW;

//LED-timer
boolean         ledState =                 LOW; 
uint32_t        previousMillisLedTimer =   1;
uint32_t        currentMillisLedTimer =    1;
const uint16_t  intervalLedTimer =         1000;

void setup() {
  Serial.begin(38400);         // Use serial for debugging
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT_PULLUP);
  //digitalWrite(inPin, LOW);  // Turn on 20k pullup resistors to simplify switch input
  digitalWrite(ledPin, HIGH); //Nem világít (SBU21)
}

void loop() {
  currentButtonState = digitalRead(inPin);
  currentMillisLedTimer = millis();

  ledBlink(Button(2), 100, ledPin);
  Serial.print(millis_held);
  Serial.print("   ");
  Serial.print(secs_held);
  Serial.print("   ");
  Serial.print(prev_secs_held);
  Serial.print("   ");
  Serial.print(firstTime);
  Serial.println("-----------------------------------------");
};
