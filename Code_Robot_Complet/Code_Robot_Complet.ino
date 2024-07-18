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

// Valeurs clés
#define ANGLE_FACE    90
#define ANGLE_GAUCHE 180
#define ANGLE_DROIT    0

// mots-clés
#define NORMAL   0
#define OBSTACLE 1
#define MANUEL   2

int etat = NORMAL;


void setup() {
  
}

void loop() {
  
}
