class Pump {
  public:
    
    /// the pin the physical pump is connected to
    
    int PumpPin;

    Pump(int pumpPin) {
      this->PumpPin = pumpPin;
    }

    void setPumpActivity(bool pumpActivity) {
      digitalWrite(PumpPin, pumpActivity ? HIGH : LOW);
    }

    void pumpForTime(unsigned long timeMillis) {
      // start pumping
      unsigned long startTime = millis();
      digitalWrite(pumpPin, HIGH);

      // wait until time the program should pump has run out
      while (millis() - startTime < timeMillis) {
        // wait
      }

      // stop pumping
      digitalWrite(pumpPin, LOW);
    }
};
