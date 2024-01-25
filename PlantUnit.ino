
//Pflanzenobjekt für indiv. Daten
struct _Plant{
  ///plant name
  String name;             
  ///optimal moisture
  int optmoisture;          
  ///threshhold of moisture - should not be less
  int thresh;               
  RobotBrain _robotBrain;
  Sensor sensor; 
  Pump pump; 

  /**
   * constructor for the plant object
   * 
   * @param robotBrain the main robot brain object
   * @param plantname the name of the plant
   * @param optimalmoisture the optimal moisture level for the plant
   * @param threshhold the tolerance around the moisture level
   * @param sensorPin the pin number for the sensor
   * @param pumpPin the pin number for the pump
   */
  Plant(RobotBrain robotBrain, String plantname, int optimalmoisture, int threshhold, int sensorPin, int pumpPin) {
    name = plantname; 
    optmoisture = optimalmoisture; 
    thresh = threshhold; 

    _robotBrain = robotBrain;
    sensor = Sensor(sensorPin); 
    pump = Pump(pumpPin); 
  }

} Plant; 


// Widerstandsbasiert, wahrscheinlich ist ein relatives Gefühl ausreichend
//zB - gefühlte Stati: trocken, leicht feucht, feuchte Erde, frisch gegossen/Sehr nass
//   -> Widerstand von den drei Bereichen messen und als Richtwert zu entnehmen 
//zB - 1) 10  2) 20 3) 30 4) 40 (Kalibrieren durch eigene Tests der Widerstände)