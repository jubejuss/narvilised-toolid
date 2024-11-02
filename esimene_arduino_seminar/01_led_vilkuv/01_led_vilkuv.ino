// näide milles paneme ledi vilkuma. See on sama kui miski vidin sisse välja lülitada.
#define aeg 500
#define LED 11

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  delay(aeg);
  digitalWrite(LED, LOW);
  delay(aeg);
}
