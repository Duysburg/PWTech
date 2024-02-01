// auto generated file
#ifndef Pump_H
#define Pump_H

class Pump  {
    public:
    int PumpPin;
    void setPumpActivity(int pumpActivity);
    void pumpForTime(unsigned long pumpTimeMillis);
    Pump(int pumpPin);
};

#endif
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
#ifndef Sensor_H
#define Sensor_H
#include "Arduino.h"

class Sensor {
    private:
    int readingPin;

    public:
    int measureMoisture();
    Sensor(int readingPin);
};

#endif Sensor_H
// auto generated file
