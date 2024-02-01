#include "RobotMain.h"

void RobotBrain::requestWatering(Pump pump, unsigned long duration)
{
    // communicate to all plants that the robot is currently watering
    currentlyWatering = true;
    // move the pump to plant
    pump.pumpForTime(5000);
    // communicate to all plants that the robot is no longer watering
    currentlyWatering = false;

}