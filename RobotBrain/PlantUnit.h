#include "RobotBrainUnit.h"

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
     * 
     * @return true if the measured moisture value is within the acceptable range, false otherwise.
     */
    bool checkSensor() {
        int measuredMoisture = sensor.measureMoisture();
        return (measuredMoisture >= optimalMoisture - moistureThreshhold && measuredMoisture <= optimalMoisture + moistureThreshhold);
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