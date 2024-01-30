#include "Sensor.h"

Sensor::Sensor(int readingPin)
{
    this->readingPin = readingPin;
}

/**
 * @brief measure the current moisture level
 * @return current moisture level
 */
int Sensor::measureMoisture()
{
    return analogRead(readingPin);
}