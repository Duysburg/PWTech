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