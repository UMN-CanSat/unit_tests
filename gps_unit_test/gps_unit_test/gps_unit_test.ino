// Unit test for the various GPS sensors under consideration

#include <UbloxGPS.h>

#define UBLOX_SERIAL Serial2
#define TIMER_LOOP_LENGTH 1000

// Data struct
struct gps_data
{
  int year;
  int month;
  int day;
  int hour;
  int min;
  int sec;
  int sats;
  float lat;
  float lon;
  float alt;
};

typedef struct gps_data data;

// Timer
float timer = 0;

// UBLOX variables
UbloxGPS ublox = UbloxGPS(&Serial2);
data ublox_data;

void setup() {
  // initialize serial ports
  Serial.begin(9600);
  Serial2.begin(UBLOX_BAUD);
  delay(50);
  Serial.println("Serial Ports intialized...");
  
  initUBLOX();
}

void loop() {
  updateUBLOX();
  
  if(millis() - timer > TIMER_LOOP_LENGTH) {
    printData();
    timer = millis();
  }
}


void printData() {
  String data_string;
  data_string = String(ublox_data.lat,6) + ", " + String(ublox_data.lon,6) + ", " + String(ublox_data.alt,6) + ", " + String(ublox_data.sats);
  Serial.println(data_string);
}
