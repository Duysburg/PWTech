#include "PumpingUnit.h"

void setup()
{
    Serial.begin(9600);
    Pump mainPump = Pump(7);
    mainPump.pumpForTime(1000);
}

void loop()
{
}
