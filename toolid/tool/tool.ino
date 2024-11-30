#include <Servo.h>

Servo servo;

int sensorpin4 = A4;
int sensor4;
int sensorpin1 = A1;
int sensor1;
int sensorpin2 = A2;
int sensor2;
int sensorpin3 = A3;
int sensor3;

int tsukkel = 15;
int tsukkelPraegu;
int nihelemisiKokku;

int vasakNihe;
int paremNihe;
int nihelmiseTolerants = 50;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(9);
  kalibreeri();
}

void loop() {
  kontrolli();
  kalibreeri();
}

void kalibreeri(){
  long kumulatiivneParem = 0;
  long kumulatiivneVasak = 0;
  //5 sekundit
  for(int i=0; i<20; i++){
    kumulatiivneParem = kumulatiivneParem + analogRead(sensorpin1) +  analogRead(sensorpin2);
    kumulatiivneVasak = kumulatiivneVasak + analogRead(sensorpin4) +  analogRead(sensorpin3);
    delay(50); 
  }
  vasakNihe = int(kumulatiivneVasak/20);
  paremNihe = int(kumulatiivneParem/20);
  Serial.println("----------------");
  Serial.print("VasakNihe: ");
  Serial.println(vasakNihe);
  Serial.print("ParemNihe: ");
  Serial.println(paremNihe);
  Serial.println("----------------");
}

void kontrolli(){
  int nihelemisi = 0;
  //5 sekundit
  for(int i=0; i<20; i++){
    if(abs(analogRead(sensorpin4) + analogRead(sensorpin3) - vasakNihe) > nihelmiseTolerants){
      nihelemisi++;
    }
    if(abs(analogRead(sensorpin1) + analogRead(sensorpin2) - paremNihe) > nihelmiseTolerants){
      nihelemisi++;
    }
    delay(50);
  }
  Serial.print("Nihelimisi: ");
  Serial.println(nihelemisi);
  tsukkelPraegu++;
  nihelemisiKokku = nihelemisiKokku + nihelemisi;
  if(tsukkelPraegu >= tsukkel){

    Serial.println(nihelemisiKokku);
    if(nihelemisiKokku <= 180){
      servo.write(int(120 - int(nihelemisiKokku / 1.5)));
      Serial.println("If");
    } else { 
      Serial.println("Else");
      servo.write(0);
    }
    
    tsukkelPraegu = 0;
    nihelemisiKokku = 0;
  }
}
