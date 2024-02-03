#include "Plant.h"

/**
 * @brief This function checks the measured moisture value from the sensor and returns a boolean value based on whether the measured value is within the acceptable range.
 * (The inbuild LED is blinking if the measured moisture value is below the acceptable range.)
 *
 * @param robotBrain pointer to the main robot brain object
 * @param plantName the name of the plant
 * @param wateringDuration the duration of the plant watering in milliseconds
 * @param optimalMoisture the optimal moisture level for the plant
 * @param threshhold the tolerance around the moisture level before the plant should be watered
 * @param sensorPin the pin number for the moisture sensor
 * 
 * @return true if the measured moisture value is within the acceptable range, false otherwise.
 */
Plant::Plant(RobotBrain* robotBrain, String plantName, int wateringDuration, int optimalMoisture, int threshhold, int sensorPin)
{
    this->robotBrain = robotBrain;
    this->plantName = plantName;
    this->wateringDuration = wateringDuration;
    this->optimalMoisture = optimalMoisture;
    this->moistureThreshhold = moistureThreshhold;
    this->sensor = new Sensor(sensorPin);
}

/**
 * @brief Deconstrucor for the Plant class
*/
Plant::~Plant() {
    // Clean up the memory for the pointers
    delete robotBrain;
    delete sensor;
}

/**
 * @brief This function checks the measured moisture value from the sensor and returns a boolean value based on whether the measured value is within the acceptable range.
 * (The inbuild LED is blinking if the measured moisture value is below the acceptable range.)
 *
 * @return true if the measured moisture value is within the acceptable range, false otherwise.
 */
bool Plant::checkSensor()
{
  Serial.println("plant: checking sensor"); // for debugging
  int measuredMoisture = sensor->measureMoisture();
  bool isAcceptable = measuredMoisture >= optimalMoisture - moistureThreshhold;
  return isAcceptable;
}

/**
 * @brief update the plant object (needs to be called periodically)
 */
void Plant::updatePlant()
{
  if (!currentlyBeingWatered && !checkSensor())
  {
    Serial.println("plant: start watering plant"); // for debugging
    currentlyBeingWatered = true;
    robotBrain->requestWatering(wateringDuration);
    currentlyBeingWatered = false;
    Serial.println("plant: stop watering plant"); // for debugging
  }
}

// ---------- DEPRECATED ----------
// the function cannot be run asynchronously easely
//
// /**
//  * @brief this function blinks the built-in LED on the Arduino board for a specified duration
//  *
//  * @param durationInMillis The duration for which the LED is on or off (in milliseconds)
//  */
// void Plant::blinkLed(int durationInMillis)
// {
//   for (int i = 0; i < 5; i++)
//   {
//     digitalWrite(LED_BUILTIN, HIGH);
//     delay(durationInMillis);
//     digitalWrite(LED_BUILTIN, LOW);
//     delay(durationInMillis);
//   }
// }