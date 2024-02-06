#ifndef ROBOTMAIN_H
#define ROBOTMAIN_H

#include "Pump.h"
#include "Plant.h"

class RobotBrain {
  public:
  Pump* pump;
  bool currentlyWatering = false;
  // create plants variable and assign the plant objects to it
  int plantNum = 3;
  Plant *plants[3] = {
    new Plant(this, "plant1", 1, 1, 1, 1),
    new Plant(this, "plant2", 1, 1, 1, 1),
    new Plant(this, "plant3", 1, 1, 1, 1)
  };

  RobotBrain(int pumpPin);
  ~RobotBrain();

  bool changePlantValues(String plantName, int wateringDuration, int optimalMoisture, int threshhold);

  void requestWatering(unsigned long duration);
};

#endif