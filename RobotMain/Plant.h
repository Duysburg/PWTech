#ifndef PLANT_H
#define PLANT_H
#include "Arduino.h"
#include "RobotMain.h"
#include "Sensor.h"
#include "Pump.h"


/// @brief plant object to manage the plant
class Plant {
    private:
        String plantName;
        int optimalMoisture;
        int moistureThreshhold;
        int wateringDuration;

        RobotBrain robotBrain = RobotBrain();
        Sensor sensor = Sensor(0);
        Pump pump = Pump(1);

        bool checkSensor();
        void blinkLed(int durationInMillis);
    public:
        bool currentlyBeeingWatered = false;

        void updatePlant();
        Plant(RobotBrain robotBrain, Pump pump, String plantName, int wateringDuration, int optimalMoisture, int threshhold, int sensorPin);
};

#endif PLANT_H