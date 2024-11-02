#define aeg 5
#define nupp 2
#define LED 11

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(nupp, INPUT_PULLUP); //see muudab seadistuse

}

void loop() {
  int nupuVajutus=digitalRead(nupp);
  if (nupuVajutus==0){ // nupuVajutus on 0, kui nuppu vajutatakse
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
