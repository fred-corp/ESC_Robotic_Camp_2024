#include <Servo.h>

#define SERVO_PIN 10

Servo monServo;

void setup() {
  monServo.attach(SERVO_PIN);
  monServo.write(90);
}

void loop() {
  
}
