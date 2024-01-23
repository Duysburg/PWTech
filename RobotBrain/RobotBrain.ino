#include "PumpingUnit.h"
#include "SensorUnit.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("Power to pin!");
    TEST_Pump(7);
    TEST_Sensor(8, A0);
}

void loop()
{
}

void TEST_Pump(int pumpPin) {
    Pump testPump = Pump(pumpPin);
    testPump.pumpForTime(5000);
}

void TEST_Sensor(int powerPin, int sensorPin) {
  Sensor testSensor = Sensor(powerPin, sensorPin);

  while (true) {
    Serial.print("Sensor reading: ");
    Serial.println(testSensor.actual_moisture);

    Serial.println(testSensor.actual_moisture);
    Serial.println("running ...");

    Serial.println(testSensor.actual_moisture);
    Serial.println("Running ...");

    delay(1000);
  }
}