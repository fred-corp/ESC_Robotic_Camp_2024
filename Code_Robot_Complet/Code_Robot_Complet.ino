#include <Servo.h>

// Broches
// H-Bridge
#define IN1        3
#define IN2        5
#define IN3        6
#define IN4        9
// Servomoteur
#define SERVO_PIN 10
Servo monServo;
// Capteur de distance
#define TRIG_PIN   7
#define ECHO_PIN   8

// Valeurs callibration
#define ANGLE_FACE    90
#define ANGLE_GAUCHE 180
#define ANGLE_DROIT    0

// Mots-clés
#define NORMAL   0
#define OBSTACLE 1
#define MANUEL   2

int etat = NORMAL;


void setup() {
  // H-Bridge
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // Servomoteur
  monServo.attach(SERVO_PIN);
  // Capteur de distance
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  monServo.write(ANGLE_FACE);
  delay(1000);
}

void loop() {
  switch(etat){
    case NORMAL:
      // Avancer et regarder si il y a un obstacle
      break;
    case OBSTACLE:
      // Stop, regarder à gauche et à droite, choisir direction
      // et repasser à l'état normal
      break;
    case MANUEL:
      // Plus tard
      break;
  }
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

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void avancer(int vitesse) {
  int PWM = map(vitesse, 0, 100, 0, 255);
  
  int gauche = map(PWM, 0, 255, 0, 255);
  int droite = map(PWM, 0, 255, 0, 255);
  
  analogWrite(IN1, gauche);
  analogWrite(IN2, 0);
  analogWrite(IN3, droite);
  analogWrite(IN4, 0);
}

void reculer(int vitesse) {
  int PWM = map(vitesse, 0, 100, 0, 255);
  
  int gauche = map(PWM, 0, 255, 0, 255);
  int droite = map(PWM, 0, 255, 0, 255);
  
  analogWrite(IN1, 0);
  analogWrite(IN2, gauche);
  analogWrite(IN3, 0);
  analogWrite(IN4, droite);
}

void gauche(int vitesse) {
  int PWM = map(vitesse, 0, 100, 0, 255);
  
  int gauche = map(PWM, 0, 255, 0, 255);
  int droite = map(PWM, 0, 255, 0, 255);
  
  analogWrite(IN1, 0);
  analogWrite(IN2, gauche);
  analogWrite(IN3, droite);
  analogWrite(IN4, 0);
}

void droite(int vitesse) {
  int PWM = map(vitesse, 0, 100, 0, 255);
  
  int gauche = map(PWM, 0, 255, 0, 255);
  int droite = map(PWM, 0, 255, 0, 255);
  
  analogWrite(IN1, gauche);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, droite);
}
