#include "PumpingUnit.h"
#include "SensorUnit.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("Robot started!");

    RobotBrain robotBrain = RobotBrain(pumpList, durationList);
    robotBrain.requestWatering(0);
}

void loop()
{
}

class RobotBrain {
  public:
  RobotBrain(Pump[] pumpList, unsigned long[] durationList) {
    // tests
    TEST_Pump(7);
    TEST_Sensor(8, A0);
  }
  
  /**
   * @brief (a plant) requests the robot brain to water a plant with the given id (all neccessary steps before and after watering - like moving - are performed)
   * 
   * @param pump the pump that should water the plant
   * @param duration the duration of the watering in milliseconds
   */
  void requestWatering(Pump pump, unsigned long duration) {
    // move the pump to plant
    pump.pumpForTime(5000);
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