
//Pflanzenobjekt für indiv. Daten
struct plant{
  string pname;     //Pflanzenname
  int optmoisture;  //Optimale Feuchte
  int thresh;       //Grenzwert der Feuchtigkeit
  //Zeitabstand der Messung 
} 
plant plantone;
plantone.pname = Plantisella;
plantone.optmoisture = 1200;   //muss nachgeschaut werden je Pflanze
plantone.thresh = 600; 

int moisture = plantone->optmoisture;





int moisture = 10; // Widerstandsbasiert, wahrscheinlich ist ein relatives Gefühl ausreichend
//zB - gefühlte Stati: trocken, leicht feucht, feuchte Erde, frisch gegossen/Sehr nass
//   -> Widerstand von den drei Bereichen messen und als Richtwert zu entnehmen 
//zB - 1) 10  2) 20 3) 30 4) 40 (Kalibrieren durch eigene Tests der Widerstände)
