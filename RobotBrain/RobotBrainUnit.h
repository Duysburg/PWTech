#pragma once
#include "Arduino.h"
#include "PumpingUnit.h"
#include "SensorUnit.h"
#include "PlantUnit.h"

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
