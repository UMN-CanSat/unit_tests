// MS5611 functions

void initMS5611() {
  while(!ms5611.begin())
  {
    Serial.println(F("Could not find a valid MS5611 barometer, check wiring..."));
    delay(500);
  }

  Serial.println(F("MS5611 barometer setup successful..."));
}

void updateMS5611(){
  // Read true temperature & Pressure
  ms5611Temp = ms5611.readTemperature();
  ms5611PressurePa = ms5611.readPressure();
}
