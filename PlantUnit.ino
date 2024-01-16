
//Pflanzenobjekt für indiv. Daten
struct _Plant{
  string name;             //plant name
  int optmoisture;          //optimal moisture
  int thresh;               //threshhold of moisture - should not be less
  Sensor sensor; 
  Pump pump; 

  Plant(string plantname, int optimalmoisture, int threshhold, int sensorPin; int pumpPin;){
    this->pname = plantname; 
    this->optmoisture = optimalmoisture; 
    this->thresh = threshhold; 
    this->sensor = Sensor(sensorPin); 
    this->pump = Pump(pumpPin); 
  }

} Plant; 


// Widerstandsbasiert, wahrscheinlich ist ein relatives Gefühl ausreichend
//zB - gefühlte Stati: trocken, leicht feucht, feuchte Erde, frisch gegossen/Sehr nass
//   -> Widerstand von den drei Bereichen messen und als Richtwert zu entnehmen 
//zB - 1) 10  2) 20 3) 30 4) 40 (Kalibrieren durch eigene Tests der Widerstände)

