


//class definition
struct _Sensor{
    
    int powerpin;         //PowerPin
    int actual_moisture;  //sensor value of moisture 

    Sensor(int pumpPin) {
      this->PumpPin = pumpPin;
    }

    void setMoistureSensor(){//sensor measuring
        digitalWrite(powerpin, HIGH);
        delay(10);
        this->actual_moisture = analogRead(A0);  //read sensor
        digital.Write(powerpin, LOW);
    }

} Sensor;

  


//
//not implemented yet 
//

  //Switching light
  //lightSwitch(sensor.actual_moisture);

//LightFunction - not implemented
void lightSwitch(int sensor, Plant p){
  if(sensor > p->thresh){
    digitalWrite(redLED, LOW); 
    digitalWrite(greenLED, HIGH); 
  }else{
    digitalWrite(redLED, HIGH); 
    digitalWrite(greenLED, LOW); 
  }
};
