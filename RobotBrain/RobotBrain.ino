#include "allUnits.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("Robot started!");

    // tests
    TEST_Pump(7);
    TEST_Sensor(8, A0);

    RobotBrain robotBrain = RobotBrain();
    robotBrain.requestWatering(0, 1000);
}

void loop()
{
}

  
/**
 * @brief a test function for the pump class
 * 
 * @param pumpPin the pin number of the pump to test
 */ 
void TEST_Pump(int pumpPin) {
    WaterPump testPump = WaterPump(pumpPin);
    testPump.pumpForTime(5000);
}

/**
 * @brief a test function for the sensor class
 * 
 * @param powerPin the pin number of the power supply for the sensor (?)
 * @param sensorPin the pin number of the sensor
 */
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