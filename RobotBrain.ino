#include "PumpingUnit.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("Power to pin!");
    digitalWrite(2, HIGH);
    Pump mainPump = Pump(2);
}

void loop()
{
  Serial.println("running.");
  Serial.println("running..");
  Serial.println("running...");
}
