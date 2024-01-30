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