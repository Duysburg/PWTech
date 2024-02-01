#include "Sensor.h"

/**
 * @brief Construct a new Sensor object
 * 
 * @param readingPin the pin on the Arduino board connected to the moisture sensor
 */
Sensor::Sensor(int readingPin)
{
    this->readingPin = readingPin;
}

/**
 * @brief Measure the current moisture level
 * 
 * @return the current moisture level
 */
int Sensor::measureMoisture()
{
    return analogRead(readingPin);
}