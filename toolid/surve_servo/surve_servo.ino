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

unsigned long startms;
unsigned long currentms;
const unsigned long period = 1000;

int nihelemised;

bool case1 = false;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo.attach(9);
}

void loop() {
  
  currentms = millis();
  if(currentms - startms >= period){
    servo.write(nihelemised * 10);
    nihelemised = 0;
    startms = currentms;
  }
  
  sensor4 = analogRead(sensorpin4);
  sensor1 = analogRead(sensorpin1);
  sensor2 = analogRead(sensorpin2);
  sensor3 = analogRead(sensorpin3);
  Serial.println(sensor4);
  Serial.println(sensor2);
  Serial.println(sensor1);
  Serial.println(sensor3);
  
  if(sensor4 > 2 * sensor2){
    nihelemised++;
  }
  delay(100);
  // put your main code here, to run repeatedly:
}