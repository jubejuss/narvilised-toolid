// sujuv muutus
#define aeg 5
#define LED 11

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  for(int i=0; i<256; i=i+1){
    analogWrite(LED, i);
    delay(aeg);
  }
  for(int i=255; i>0; i=i-1){
    analogWrite(LED, i);
    delay(aeg);
  }  
}
