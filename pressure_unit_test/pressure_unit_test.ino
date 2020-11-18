// CanSat pressure sensor unit testing

// Teensy 3.6 used due to its onboard SD card

// Libraries
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <MS5611.h>
#include <Adafruit_DPS310.h>
#include <Adafruit_MPL115A2.h>

// MS5611 Pressure Sensor Variables
MS5611 ms5611;
float ms5611Temp;                 
float ms5611PressurePa;

// Adafruit DPS310 Pressure Sensor Variables
Adafruit_DPS310 dps;
float dps310Temp;
float dps310PressurePa; 

// this comment is to show how github works

void setup() {
  Serial.begin(9600);

  initMS5611();

  initDPS310();
}

void loop() {

  updateMS5611();

  updateDPS310();

}
