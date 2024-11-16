int sensorpin1 = A1;
int sensorpin2 = A2;
int sensorpin3 = A3;
int sensorpin4 = A4;
int sensor1;
int sensor2;
int sensor3;
int sensor4;

void setup() {
  //määrasime pordi, mis suudab andmeid vastu võtta
  Serial.begin(9600);
}

void loop() {
  // loeme sensorite väärtusi
  sensor1 = analogRead(sensorpin1);
  sensor2 = analogRead(sensorpin2);
  sensor3 = analogRead(sensorpin3);
  sensor4 = analogRead(sensorpin4);
  
  // Output values in format for Arduino Serial Plotter
  Serial.print(sensor1);
  Serial.print(" ");
  Serial.print(sensor2);
  Serial.print(" "); 
  Serial.print(sensor3);
  Serial.print(" ");
  Serial.print(sensor4);
  Serial.print(" ");
  Serial.print(0);
  Serial.print(" ");
  Serial.println(400); //0 ja 400 määravad ära vahemiku, et graafikud ei liiguks kaootiliselt
  delay(100);
}
