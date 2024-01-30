#include "Plant.h"

/**
 * @brief This function checks the measured moisture value from the sensor and returns a boolean value based on whether the measured value is within the acceptable range.
 * (The inbuild LED is blinking if the measured moisture value is below the acceptable range.)
 *
 * @return true if the measured moisture value is within the acceptable range, false otherwise.
 */
Plant::Plant(String plantName, int wateringDuration, int optimalMoisture, int moistureThreshhold, int sensorPin, int powerPin)
{
    this->plantName = plantName;
    this->wateringDuration = wateringDuration;
    this->optimalMoisture = optimalMoisture;
    this->moistureThreshhold = moistureThreshhold;
}

/**
 * @brief this function blinks the built-in LED on the Arduino board for a specified duration
 *
 * @param durationInMillis The duration for which the LED is on or off (in milliseconds)
 */
void Plant::updatePlant() {
        int measuredMoisture = 10; //sensor.measureMoisture();
        bool isAcceptable = (measuredMoisture >= optimalMoisture - moistureThreshhold && measuredMoisture <= optimalMoisture + moistureThreshhold);
        if (!isAcceptable) {
          //blinkLed(100);
        }
        return isAcceptable;
}