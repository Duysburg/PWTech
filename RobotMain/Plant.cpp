#include "Plant.h"

/**
 * @brief This function checks the measured moisture value from the sensor and returns a boolean value based on whether the measured value is within the acceptable range.
 * (The inbuild LED is blinking if the measured moisture value is below the acceptable range.)
 *
 * @return true if the measured moisture value is within the acceptable range, false otherwise.
 */
Plant::Plant(RobotBrain robotBrain, Pump pump, String plantName, int wateringDuration, int optimalMoisture, int threshhold, int sensorPin)
{
    this->robotBrain = robotBrain;
    this->plantName = plantName;
    this->wateringDuration = wateringDuration;
    this->optimalMoisture = optimalMoisture;
    this->moistureThreshhold = moistureThreshhold;
    this->sensor = Sensor(sensorPin);
    this->pump = pump;
}

/**
 * @brief This function checks the measured moisture value from the sensor and returns a boolean value based on whether the measured value is within the acceptable range.
 * (The inbuild LED is blinking if the measured moisture value is below the acceptable range.)
 *
 * @return true if the measured moisture value is within the acceptable range, false otherwise.
 */
bool Plant::checkSensor()
{
  int measuredMoisture = 10; //sensor.measureMoisture();
  bool isAcceptable = (measuredMoisture >= optimalMoisture - moistureThreshhold && measuredMoisture <= optimalMoisture + moistureThreshhold);
  if (!isAcceptable)
  {
    blinkLed(100);
  }
  return isAcceptable;
}

/**
 * @brief this function blinks the built-in LED on the Arduino board for a specified duration
 *
 * @param durationInMillis The duration for which the LED is on or off (in milliseconds)
 */
void Plant::blinkLed(int durationInMillis)
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(durationInMillis);
    digitalWrite(LED_BUILTIN, LOW);
    delay(durationInMillis);
  }
}

/**
 * @brief update the plant object (needs to be called periodically)
 */
void Plant::updatePlant()
{
  if (!currentlyBeeingWatered && checkSensor())
  {
    currentlyBeeingWatered = true;
    robotBrain.requestWatering(pump, wateringDuration);
  }
}