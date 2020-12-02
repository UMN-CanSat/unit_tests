// UBLOX GPS functions

void initUBLOX() {
  UBLOX_SERIAL.begin(UBLOX_BAUD);
  delay(50);
  ublox.init();
  Serial.println("UBLOX initialized...");
}

void updateUBLOX() {
  ublox.update();
  
  // Update GPS data struct
  ublox_data.millis = millis();
  ublox_data.year = ublox.getYear();
  ublox_data.month = ublox.getMonth();
  ublox_data.day = ublox.getDay();
  ublox_data.hour = ublox.getHour();
  ublox_data.min = ublox.getMinute();
  ublox_data.sec = ublox.getSecond();
  ublox_data.sats = ublox.getSats();
  ublox_data.lat = ublox.getLat();
  ublox_data.lon = ublox.getLon();
  ublox_data.alt = ublox.getAlt_meters();
  
}
