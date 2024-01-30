#ifndef PLANT_H
#define PLANT_H
#include "Arduino.h"

class Sensor {
    private:
    int readingPin;

    public:
    int measureMoisture();
    Sensor(int readingPin);
};

#endif PLANT_H