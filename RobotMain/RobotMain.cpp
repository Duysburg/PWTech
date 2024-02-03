#include <Arduino.h>
#include "RobotMain.h"

/**
 * @brief Constructor for the RobotBrain class
 * 
 * @param pumpPin the pin number of the robotBrain's pump
*/
RobotBrain::RobotBrain(int pumpPin)
{
    this->pump = new Pump(pumpPin);
}

/**
 * @brief Deconstructor for the RobotBrain class
*/
RobotBrain::~RobotBrain()
{
    delete pump;
}

/**
 * @brief Request watering for the specified duration.
 *
 * @param duration the duration of watering in milliseconds
 */
void RobotBrain::requestWatering(unsigned long duration)
{
    // communicate to all plants that the robot is currently watering
    currentlyWatering = true;
    Serial.println("robotbrain: start watering plants"); // for debugging
    // move the pump to plant
    pump->pumpForTime(5000);
    // communicate to all plants that the robot is no longer watering
    currentlyWatering = false;
    Serial.println("\nrobotbrain: stop watering plants"); // for debugging

}