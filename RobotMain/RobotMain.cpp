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
 * @brief This function changes the key values of a plant identified by its name.
 *
 * @param plantName the name of the plant
 * @param wateringDuration the new watering duration for the plant (set to -1 to not change the value)
 * @param optimalMoisture the new optimal moisture level for the plant (set to -1 to not change the value)
 * @param threshhold the new tolerance around the moisture level for the plant (set to -1 to not change the value)
 * 
 * @return true if the plant is found, false otherwise
 */
bool RobotBrain::changePlantValues(String plantName, int wateringDuration, int optimalMoisture, int threshhold)
{
  // Find the plant with the given name
  for (int i = 0; i < numPlants; i++)
  {
    if (plants[i].plantName == plantName)
    {
      // Update the key values of the plant
      if (wateringDuration != -1)
        plants[i].wateringDuration = wateringDuration;
      if (optimalMoisture != -1)
        plants[i].optimalMoisture = optimalMoisture;
      if (threshhold != -1)
        plants[i].threshhold = threshhold;
      return true;
    }
  }

  // If the plant is not found, display an error message
  Serial.println("Plant not found!");
  return false;
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