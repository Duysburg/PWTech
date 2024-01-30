// auto generated file
#pragma once

class WaterPump {
  public:
    
    /// the pin the physical pump is connected to
    int PumpPin;

    /**
     *  @brief makes a new PumpObject
     *  @param pumpPin the pin this pump is connected to
     */
    WaterPump(int pumpPin) {
      PumpPin = pumpPin;
      pinMode(PumpPin, OUTPUT);
    }

    /**
     * sets the pV-5V; Stil: Hump activity based on the given boolean value
     * @param pumpActivity the boolean value indicating whether the pump should be active or not
     */
    void setPumpActivity(bool pumpActivity) {
      digitalWrite(PumpPin, pumpActivity ? HIGH : LOW);
    }

    /**
     * pumps the pump for a given time
     * @param timeMillis the time in milliseconds that the pump should run for
     */
    void pumpForTime(unsigned long timeMillis) {
      // start pumping
      unsigned long startTime = millis();
      digitalWrite(PumpPin, HIGH);

      // wait until time the program should pump has run out
      while (millis() - startTime < timeMillis) {
        Serial.println("pumping...");
      }

      // stop pumping
      digitalWrite(PumpPin, LOW);
    }
};
#pragma once
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
#pragma once
#include "Arduino.h"

class RobotBrain {
  public:
  RobotBrain() {
  }
  
  /**
   * (a plant) requests the robot brain to water a plant with the given id (all neccessary steps before and after watering - like moving - are performed)
   * 
   * @param requestingPlant the plant that should be watered
   * @param pump the pump that should water the plant
   * @param duration the duration of the watering in milliseconds
   */
  void requestWatering(WaterPump pump, unsigned long duration) {
    // move the pump to plant
    pump.pumpForTime(5000);
    // communicate to the plant that it is no longer watered
    requestingPlant.currentlyBeeingWatered = false;
  }
};
#pragma once

class Plant {
private:
    String plantName;
    int optimalMoisture;
    /// threshhold of moisture - should not be less
    int moistureThreshhold;
    int wateringDuration;
    RobotBrain robotBrain;
    Sensor sensor;
    WaterPump pump; 

    /**
     * @brief This function checks the measured moisture value from the sensor and returns a boolean value based on whether the measured value is within the acceptable range.
     * (The inbuild LED is blinking if the measured moisture value is below the acceptable range.)
     * 
     * @return true if the measured moisture value is within the acceptable range, false otherwise.
     */
    bool checkSensor() {
        int measuredMoisture = sensor.measureMoisture();
        bool isAcceptable = (measuredMoisture >= optimalMoisture - moistureThreshhold && measuredMoisture <= optimalMoisture + moistureThreshhold);
        if (!isAcceptable) {
          blinkLed(100);
        }
        return isAcceptable;
    }
    
      /**
     * @brief this function blinks the built-in LED on the Arduino board for a specified duration
     * 
     * @param durationInMillis The duration for which the LED is on or off (in milliseconds)
     */
    void blinkLed(long durationInMillis) {
        for (int i = 0; i < 5; i++) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(durationInMillis);
          digitalWrite(LED_BUILTIN, LOW);
          delay(durationInMillis);
        }
      }

public:
    bool currentlyBeeingWatered = false;

  /**
   * constructor for the plant object
   * 
   * @param robotBrain the main robot brain object
   * @param plantName the name of the plant
   * @param wateringDuration the duration of the watering process
   * @param optimalMoisture the optimal moisture level for the plant
   * @param threshhold the tolerance around the moisture level
   * @param sensorPin the pin number for the sensor
   * @param pumpPin the pin number for the pump
   */
  Plant(RobotBrain robotBrain, String plantName, int wateringDuration, int optimalMoisture, int hreshhold, int sensorPin, int pumpPin) {
    this->plantName = plantName; 
    this->wateringDuration = wateringDuration;
    this->optimalMoisture = optimalMoisture; 
    this->moistureThreshhold = threshhold; 

    this->robotBrain = robotBrain;
    this->sensor = Sensor(sensorPin); 
    this->pump = WaterPump(pumpPin); 
  }

  /**
   * update the plant object (needs to be called periodically)
  */
  void updatePlant() {
    if (!currentlyBeeingWatered && checkSensor()) {
        currentlyBeeingWatered = true;
        robotBrain.requestWatering(this, pump, wateringDuration);
    }
  }
}
