// Adafruit MPL115A2 Pressure Sensor Test

void initMPL115A2() {
  mpl115a2.begin();
}

void updateMPL115A2() {
  // Get pressure and temperature data
  mpl115a2Temp = mpl115a2.getTemperature();
  mpl115a2PressurePa = mpl115a2.getPressure()*1000;
}
