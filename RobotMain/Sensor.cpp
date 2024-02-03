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
 * @brief measures the moisture value at this sensor's reading pin
 * 
 * @return the measured moisture value 
 */
int Sensor::measureMoisture()
{
    Serial.println("sensor: measuring moisture: " + String(analogRead(readingPin))); // for debugging
    return analogRead(readingPin);
}