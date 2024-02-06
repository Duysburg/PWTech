#ifndef PLANT_H
#define PLANT_H

#include "Arduino.h"

#include "RobotMain.h"
#include "Sensor.h"
#include "Pump.h"

class Plant {
    private:
        String plantName;

        RobotBrain* robotBrain;
        Sensor* sensor;

        bool checkSensor();
    public:
        int optimalMoisture;
        int moistureThreshhold;
        int wateringDuration;

        bool currentlyBeingWatered = false;

        void updatePlant();
        Plant(RobotBrain* robotBrain, String plantName, int wateringDuration, int optimalMoisture, int threshhold, int sensorPin);
        ~Plant();
};

#endif PLANT_H