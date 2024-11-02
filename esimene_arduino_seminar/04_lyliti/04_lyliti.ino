#define aeg 5
#define nupp 2
#define LED 11

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(nupp, INPUT);

}

void loop() {
  int nupuVajutus=digitalRead(nupp);
  if (nupuVajutus==1){
    for(int i=0; i<256; i=i+1){
    analogWrite(LED, i);
    delay(aeg);
  }
    for(int i=255; i>0; i=i-1){
      analogWrite(LED, i);
      delay(aeg);
    } 
    // nullime voolu
    digitalWrite(LED, LOW);
  }
}
