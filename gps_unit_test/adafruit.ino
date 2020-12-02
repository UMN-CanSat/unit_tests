// Adafruit Ultimate GPS functions

void initAdafruit() {
  adafruit.begin(9600);
  adafruit.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // pull RMC and GGA data
  adafruit.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // 1 Hz update rate
  delay(1000);
  Serial.println("Adafruit initialized...");
}

void  updateAdafruit() {
  
  adafruit.read();

  if (adafruit.newNMEAreceived()) {
    if(!adafruit.parse(adafruit.lastNMEA())) {
      return;
    }
  }
  
  // Update GPS data struct
  adafruit_data.millis = millis();
  adafruit_data.year = adafruit.year;
  adafruit_data.month = adafruit.month;
  adafruit_data.day = adafruit.day;
  adafruit_data.hour = adafruit.hour;
  adafruit_data.min = adafruit.minute;
  adafruit_data.sec = adafruit.seconds;
  adafruit_data.sats = adafruit.satellites;
  adafruit_data.lat = adafruit.latitudeDegrees;
  adafruit_data.lon = adafruit.longitudeDegrees;
  adafruit_data.alt = adafruit.altitude;
}
