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
  
}
