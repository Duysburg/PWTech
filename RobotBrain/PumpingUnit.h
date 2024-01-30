#pragma once
#include "RobotBrainUnit.h"

class WaterPump {
  public:
    
    /// the pin the physical pump is connected to
    int PumpPin;

    /**
     *  @brief makes a new PumpObject
     *  @param pumpPin the pin this pump is connected to
     */
    WaterPump(int pumpPin) {
      PumpPin = pumpPin;
      pinMode(PumpPin, OUTPUT);
    }

    /**
     * sets the pV-5V; Stil: Hump activity based on the given boolean value
     * @param pumpActivity the boolean value indicating whether the pump should be active or not
     */
    void setPumpActivity(bool pumpActivity) {
      digitalWrite(PumpPin, pumpActivity ? HIGH : LOW);
    }

    /**
     * pumps the pump for a given time
     * @param timeMillis the time in milliseconds that the pump should run for
     */
    void pumpForTime(unsigned long timeMillis) {
      // start pumping
      unsigned long startTime = millis();
      digitalWrite(PumpPin, HIGH);

      // wait until time the program should pump has run out
      while (millis() - startTime < timeMillis) {
        Serial.println("pumping...");
      }

      // stop pumping
      digitalWrite(PumpPin, LOW);
    }
};
