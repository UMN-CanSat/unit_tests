// CanSat pressure sensor unit testing

// Arduino Uno used, data should be printed out and copied from the serial monitor

// Libraries
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <MS5611.h>
#include <Adafruit_DPS310.h>
#include <Adafruit_MPL115A2.h>

// Pin Definitions
#define DPS310_CS 10

// Time Definitions
#define LOOPTIME 250
float timer = 0;

// MS5611 Pressure Sensor Variables
MS5611 ms5611;
float ms5611Temp;                 
float ms5611PressurePa;

// Adafruit DPS310 Pressure Sensor Variables
Adafruit_DPS310 dps;
float dps310Temp;
float dps310PressurePa; 

// Digikey DPS310 Prssure Sensor Variables
Adafruit_MPL115A2 mpl115a2;
float mpl115a2Temp;
float mpl115a2PressurePa;

// this comment is to show how github works

void setup() {
  Serial.begin(9600);

  // initMS5611();

  initDPS310();

  initMPL115A2();

  String dataHeader = "millis, dps310_temp, dps310_pressure, mpl115a2_temp, mpl115a2_pressure";

  Serial.println(dataHeader);
}

void loop() {

  if (millis() - timer > LOOPTIME) {

    // updateMS5611();
  
    updateDPS310();
  
    updateMPL115A2();
  
    String dataString = String(millis()) + ", " + String(dps310Temp) + ", " + String(dps310PressurePa) + ", " + String(mpl115a2Temp) + ", " + String(mpl115a2PressurePa);
    
    Serial.println(dataString);

    timer = millis();
    
  }
  
}
