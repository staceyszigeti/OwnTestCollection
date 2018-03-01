void setup()
{
  Serial.begin(4800);
}

void loop()
{
  
while (Serial.available())
      Serial.write(Serial.read());

}

