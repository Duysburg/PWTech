#pragma once
#include "RobotBrainUnit.h"
// ------------------------------------------------------------------------------
// ACHTUNG: Ich hab den Inhalt der loop()-Funktion in TEST_Sensor() in RobotBrain.ino verschoben damit der Sensor getestet werden kann.
// Ansonsten hab ich am code nichts geändert. :)
// ------------------------------------------------------------------------------

//class definition
class Sensor{

    private:
    int powerPin;         //PowerPin
    int readingPin;       //ReadingPin

    public:
    int actual_moisture;  //sensor value of moisture

    Sensor(int powerP, int readP) {
      this->powerPin = powerP;
      this->readingPin = readP;
      this->actual_moisture = measureMoisture();
    }

    /**
     * @brief measure the current moisture level
     * @return current moisture level
    */
    int measureMoisture() {
        //sensor measuring
        digitalWrite(powerPin, HIGH);
        delay(10);
        this->actual_moisture = analogRead(readingPin);  //read sensor
        digitalWrite(powerPin, LOW);
        return analogRead(readingPin);
    }

};

//
//not implemented yet
//

  //Switching light
  //lightSwitch(sensor.actual_moisture);

//LightFunction - not implemented
/*
void lightSwitch(int sensor, Plant p){
  if(sensor > p->moistureThreshhold){
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }else{
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
};
*/

// ----------------------------------------------------------------
// NACH ROBOTBRAIN.INO VERSCHOBEN
// ----------------------------------------------------------------
// void loop() {
//   // put your main code here, to run repeatedly:

//   Sensor sensor = Sensor(8, A0);
//   Serial.println(sensor.actual_moisture);
//   Serial.println("running ...");

//   Serial.println(sensor.actual_moisture);
//   Serial.println("Running ...");

//   delay(1000);

// }
