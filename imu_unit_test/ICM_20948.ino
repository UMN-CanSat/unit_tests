// ICM-20948 Functions

void initICM() {
  // I2C initialization stuff
  Wire.begin();
  Wire.setClock(400000);

  // ICM IMU initialization
  bool initialized = false;
  while(!initialized) {
    icm.begin(Wire,1);  // input values are (Wire Port, AD0 Value)

    Serial.print(F("Initialization of the sensor returned: "));
    Serial.println(icm.statusString());
    if(icm.status != ICM_20948_Stat_Ok){
      Serial.println( "Trying again..." );
      delay(500);
    }else{
      initialized = true;
    }
  }

  Serial.println("Initialized ICM...");
}

void updateICM() {
  if(icm.dataReady()) {
    icm.getAGMT();
  }
}
