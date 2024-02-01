#ifndef ROBOTMAIN_H
#define ROBOTMAIN_H

#include "Pump.h"

class RobotBrain {
  public:
  bool currentlyWatering = false;

  RobotBrain() {
  }

  /**
   * (a plant) requests the robot brain to water a plant with the given id (all neccessary steps before and after watering - like moving - are performed)
   * 
   * @param pump the pump that should water the plant
   * @param duration the duration of the watering in milliseconds
   */
  void requestWatering(Pump pump, unsigned long duration);
};

#endif