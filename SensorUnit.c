
//Sensorklasse für indiv. Daten
struct _sensor{
  string sname;         //Pflanzenname
  int actual_moisture;  //Feuchtigkeitswert
  int powerpin;         
} sensor;

const int powerpin = 8;
//Zeitabstand der Messung
const int delayTime = 1000; // mil sec - 1000 milisekunden = 1 sec.  


int moisture = 10; // Widerstandsbasiert, wahrscheinlich ist ein relatives Gefühl ausreichend
//zB - gefühlte Stati: trocken, leicht feucht, feuchte Erde, frisch gegossen/Sehr nass
//   -> Widerstand von den drei Bereichen messen und als Richtwert zu entnehmen 
//zB - 1) 10  2) 20 3) 30 4) 40 (Kalibrieren durch eigene Tests der Widerstände)



  //Sensormessung
  digitalWrite(powerpin, HIGH);
  delay(10);
  sensor = analogRead(A0);  //read sensor
  digital.Write(powerpin, LOW);

  //Ausgabe der Sensordaten + Switch des Lichts
  lightSwitch(sensor); 
  Serial.println(sensor);

  //Zeitraum zur nächsten Messung
  delayTime = measureTime(sensor); 
  delay(delayTime);

//LichtPINS 
const int redLED = 2; 
const int greenLED = 3; 

void lightSwitch(int sensor, plant p){
  if(sensor > p->thresh){
    digitalWrite(redLED, LOW); 
    digitalWrite(greenLED, HIGH); 
  }else{
    digitalWrite(redLED, HIGH); 
    digitalWrite(greenLED, LOW); 
  }
}

//Methode für den Abstand zwischen den Messungen
int measurePeriod() {
  int period;

  //trocken - Zweitmessung (t=0)
  if (moisture < 10){
    period = 0; 
    return period; 
  }
  //leicht feucht - kurze Messung (12h)
  if (moisture < 10){
    period = 100; 
    return period; 
  }
  //feucht - mittlere Dauer bis zur nächten Messung (2d)
  if (moisture < 10){
    period = 400; 
    return period;
  }
  //sehr feucht - lange Dauer bis zur nächsten Messung (3d)
  if (moisture < 600){
    period = 0; 
    return period;
  }

  period = NULL; 
  return period;
}