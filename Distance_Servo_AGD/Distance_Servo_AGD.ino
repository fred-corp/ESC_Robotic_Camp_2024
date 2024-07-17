#include <Servo.h>

#define TRIG_PIN   7
#define ECHO_PIN   8
#define LED       13
#define SERVO_PIN 10

#define devant 90
#define gauche 180
#define droite 0

Servo monServo;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED, OUTPUT);

  monServo.attach(SERVO_PIN);

  Serial.begin(9600);
}

void loop() {
  monServo.write(devant);
  delay(250);
  float distanceDevant = capteurDistance();
  delay(100);

  monServo.write(gauche);
  delay(250);
  float distanceGauche = capteurDistance();
  delay(100);

  monServo.write(droite);
  delay(250);
  float distanceDroite = capteurDistance();
  delay(100);
  
  Serial.print(", distance à gauche : ");
  Serial.print(distanceGauche);
  Serial.print(", distance à droite : ");
  Serial.println(distanceDroite);
  delay(250);
}

float capteurDistance() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(10);

  long temps = pulseIn(ECHO_PIN, HIGH);

  // calculer la distance en centimètres
  float distance = (temps * 340.0 / 10000.0) / 2.0;

  return distance;
}
