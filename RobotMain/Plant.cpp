#include "Plant.h"

Plant::Plant(String plantName, int wateringDuration, int optimalMoisture, int moistureThreshhold, int sensorPin, int powerPin)
{
    this->plantName = plantName;
    this->wateringDuration = wateringDuration;
    this->optimalMoisture = optimalMoisture;
    this->moistureThreshhold = moistureThreshhold;
}
