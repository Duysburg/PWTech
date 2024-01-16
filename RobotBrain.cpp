

void setup() {
  // put your setup code here, to run once:
  Serial.Begin(9600);
  pinMode(powerpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

    
    const int delayTime = 1000; // mil sec - 1000 milisekunden = 1 sec.  

    //automatsierte Loop Anfrage an den Server für neue Parameter

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


}
