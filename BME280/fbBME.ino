boolean fbBMESetup()
{
    if (! bme.begin()) {
        return LOW;
    };

    delay(10);
    
    /* 
    For more details on the following scenarious, see chapter
    3.5 "Recommended modes of operation" in the datasheet
    weather monitoring
    forced mode, 1x temperature / 1x humidity / 1x pressure oversampling, filter off
    */
    bme.setSampling(Adafruit_BME280::MODE_FORCED,
                    Adafruit_BME280::SAMPLING_X1, // temperature
                    Adafruit_BME280::SAMPLING_X1, // pressure
                    Adafruit_BME280::SAMPLING_X1, // humidity
                    Adafruit_BME280::FILTER_OFF   );
    return HIGH;                
};

boolean fbBMERead(int interval)
{
    unsigned long currentMillis = millis();
    
    if (currentMillis - BMEpreviousMillis > interval) {
      BMEpreviousMillis = currentMillis;
      
      bme.takeForcedMeasurement();
      
      fTemperature = bme.readTemperature();
      fPressure = bme.readPressure() / 100.0F;

      Serial.println(fTemperature);
      Serial.println(fPressure);   
    };
};

void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    /*Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");*/

    Serial.println();
}
