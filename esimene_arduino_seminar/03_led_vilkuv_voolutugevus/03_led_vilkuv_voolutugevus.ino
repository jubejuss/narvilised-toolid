// Lisame vooltuguvuse. Saab lambi heledust muuta, kuid ka müned teise voluringi tugevust muuta
#define aeg 500
#define LED 11

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED, 0); // 0 - 5 V = 0 - 255 (st meil on 8bitine vahemik)
  delay(aeg);
  analogWrite(LED, 75);
  delay(aeg);
  analogWrite(LED, 150);
  delay(aeg);
  analogWrite(LED, 255);
  delay(aeg);
}
