#include "RobotMain.h"
#include "Plant.h"
#include "Pump.h"
#include "Sensor.h"

Plant testPlant;
void setup() {
    Serial.begin(9600);

    RobotBrain robotBrain = RobotBrain();
    testPlant = Plant(robotBrain, "hi :)", 1, 1, 1, 1);
}

void loop() {
  testPlant.updatePlant();
}

/**
 * @brief a test function for the pump class
 * 
 * @param pumpPin the pin number of the pump to test
 */ 
void TEST_Pump(int pumpPin) {
    Pump testPump = Pump(pumpPin);
    testPump.pumpForTime(5000);
}

/**
 * @brief a test function for the sensor class
 * 
 * @param powerPin the pin number of the power supply for the sensor (?)
 * @param sensorPin the pin number of the sensor
 */
void TEST_Sensor(int powerPin, int sensorPin) {
  Sensor testSensor = Sensor(sensorPin);

  while (true) {
    Serial.println(testSensor.measureMoisture());
    delay(1000);
  }
}