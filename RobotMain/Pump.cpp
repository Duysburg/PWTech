#include "Arduino.h"
#include "Pump.h"

/**
 *  @brief makes a new PumpObject
 *  @param pumpPin the pin this pump is connected to
 */
Pump::Pump(int pumpPin)
{
    this->PumpPin = pumpPin;
    pinMode(PumpPin, OUTPUT);
}

/**
 * sets the pump activity based on the given boolean value
 * @param pumpActivity the boolean value indicating whether the pump should be active or not
 */
void Pump::setPumpActivity(int pumpActivity)
{
    digitalWrite(PumpPin, pumpActivity);
}

/**
 * pumps the pump for a given time
 * @param pumpTimeMillis the time in milliseconds that the pump should run for
 */
void Pump::pumpForTime(unsigned long pumpTimeMillis)
{
    // start pumping
    unsigned long startTime = millis();
    digitalWrite(PumpPin, HIGH);

    // wait until time the program should pump has run out
    while (millis() - startTime < pumpTimeMillis)
    {
        Serial.print("pumping..."); // for debugging
    }

    // stop pumping
    digitalWrite(PumpPin, LOW);
}