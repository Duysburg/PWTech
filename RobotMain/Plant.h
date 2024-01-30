#ifndef PLANT_H
#define PLANT_H
#include "Arduino.h"
#include "Sensor.h"


/// @brief plant object to manage the plant
class Plant {
    private:
        String plantName;
        int optimalMoisture;
        int moistureThreshhold;
        int wateringDuration;
        // Sensor sensor;
        bool checkSensor();
        void blinkLed(int durationInMillis);
    public:
        bool currentlyBeeingWatered = false;
        void updatePlant();
        Plant(String plantName, int wateringDuration, int optimalMoisture, int threshhold, int sensorPin, int pumpPin);
};
// class Plant {
// private:
//     RobotBrain robotBrain;
//     Sensor sensor;
//     WaterPump pump; 

// public:

//     Plant(RobotBrain robotBrain, String plantName, int wateringDuration, int optimalMoisture, int hreshhold, int sensorPin, int pumpPin);
// };

#endif PLANT_H