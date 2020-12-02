// Unit test for the various GPS sensors under consideration

#include <UbloxGPS.h>
#include <Adafruit_GPS.h>

#define ADAFRUIT_SERIAL Serial1
#define UBLOX_SERIAL Serial2
#define TIMER_LOOP_LENGTH 1000

// Data struct
struct gps_data
{
  unsigned int millis;
  unsigned int year;
  unsigned int month;
  unsigned int day;
  unsigned int hour;
  unsigned int min;
  unsigned int sec;
  unsigned int sats;
  float lat;
  float lon;
  float alt;
};

typedef struct gps_data data;

// Timer
float timer = 0;

// UBLOX variables
UbloxGPS ublox = UbloxGPS(&UBLOX_SERIAL);
data ublox_data;

// Adafruit variables
Adafruit_GPS adafruit(&ADAFRUIT_SERIAL);
data adafruit_data;

void setup() {
  // initialize serial ports
  Serial.begin(115200);
  delay(50);
  Serial.println("Serial Ports intialized...");
  
  initUBLOX();

  initAdafruit();

  String headerString = "Ublox Millis, Ublox Latitude, Ublox Longitude, Ublox Altitude (m), Ublox Satellites, ";
  headerString += "Adafruit Millis, Adafruit Latitude, Adafruit Longitude, Adafruit Altitude (m), Adafruit Satellite";
  Serial.println(headerString);
}

void loop() {

  updateUBLOX();
  updateAdafruit();
  
  if(millis() - timer > TIMER_LOOP_LENGTH) {
    printData();
    timer = millis();
  }
}


void printData() {
  String data_string;
  data_string = String(ublox_data.millis) + ", " + String(ublox_data.lat,6) + ", " + String(ublox_data.lon,6) + ", " + String(ublox_data.alt,6) + ", " + String(ublox_data.sats) + ", ";
  data_string += String(adafruit_data.millis) + ", " + String(adafruit_data.lat,6) + ", " + String(adafruit_data.lon,6) + ", " + String(adafruit_data.alt,6) + ", " + String(adafruit_data.sats);
  Serial.println(data_string);
}
