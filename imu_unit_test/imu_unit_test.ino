// Unit test that can be run on an Arduino Uno and can compare data from a Sparkfun LSM6DS3 and a Sparkfun LSM9DS1

// Libraries
#include "SparkFunLSM6DS3.h"
#include "ICM_20948.h"
#include <Wire.h>
#include <SPI.h>

// Timer variables
#define TIME_LOOP 100
float time_stamp = 0;

// LSM6DS3 variables
LSM6DS3 lsm6ds3;  // I2C address is 0x6B
float ds3_accX;
float ds3_accY;
float ds3_accZ;
float ds3_gyroX;
float ds3_gyroY;
float ds3_gyroZ;

// Qwiic ICM-20948
ICM_20948_I2C icm;

void setup() {
  Serial.begin(9600);

  initLSM6DS3();
  initICM();

  delay(30);
}

void loop() {
  // Update data
  updateLSM6DS3();
  updateICM();

  if(millis() - time_stamp > TIME_LOOP) {
    // print the data in a .csv format
    String dataString = build_data_string();
    Serial.println(dataString);
    // update the time stamp
    time_stamp = millis();
  }
}


String build_data_string() {
    String data = String(millis()) + ", " + String(ds3_accX, 4) + ", " + String(ds3_accY, 4) + ", " + String(ds3_accZ, 4) + ", ";
    data += String(ds3_gyroX, 4) + ", " + String(ds3_gyroY, 4) + ", " + String(ds3_gyroZ, 4) + ", ";
    data += String(icm.accX(), 4) + ", " + String(icm.accY(), 4) + ", " + String(icm.accZ(), 4) + ", ";
    data += String(icm.gyrX(), 4) + ", " + String(icm.gyrY(), 4) + ", " + String(icm.gyrZ(), 4) + ", ";
    data += String(icm.magX(), 4) + ", " + String(icm.magY(), 4) + ", " + String(icm.magZ(), 4) + ", ";

    return data;
}
