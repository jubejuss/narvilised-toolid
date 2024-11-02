// Lisame vooltuguvuse. Saab lambi heledust muuta, kuid ka müned teise voluringi tugevust muuta
#define aeg 500
#define LED 11

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  analogWrite(LED, 0); // 0 - 5 V = 0 - 255 (st meil on 8bitine vahemik)
  delay(aeg);
  analogWrite(LED, 75);
  delay(aeg);
  analogWrite(LED, 150);
  delay(aeg);
  analogWrite(LED, 255);
  delay(aeg);
}
