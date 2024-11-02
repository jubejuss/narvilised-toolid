#define aeg 25
#define pot A0
#define LED 11

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600); // umbes tähemärki sekundis - Baud
}

void loop() {
  int potValue=analogRead(pot); // 0 - 1023 = 0 - 5 V potValue on väärtus, mis näitab potentsiomeetri väärtust
  potValue=map(potValue, 0, 1023, 0, 255); // 0 - 1023 = 0 - 255 see on funktsioon, mis muudab väärtuse vahemiku
  Serial.print("Potentsiomeetri väärtus: "); // Prindime labeli
  Serial.println(potValue); // kirjuta serial ühenduse peale potValue
  delay(aeg);
  analogWrite(LED, potValue); // LED väärtus on potValue
  
}
