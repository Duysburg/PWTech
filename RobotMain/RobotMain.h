#ifndef ROBOTMAIN_H
#define ROBOTMAIN_H

#include "Pump.h"

class RobotBrain {
  public:
  Pump* pump;
  bool currentlyWatering = false;

  RobotBrain(int pumpPin);
  ~RobotBrain();

  void requestWatering(unsigned long duration);
};

#endif