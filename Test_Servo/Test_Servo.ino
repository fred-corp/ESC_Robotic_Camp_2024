#include <Servo.h>

#define SERVO_PIN 10

Servo monServo;

void setup() {
  monServo.attach(SERVO_PIN);
}

void loop() {
  for(int angle = 0; angle <= 180; angle++) {
    monServo.write(angle);
    delay(10);
  }

  for(int angle = 180; angle >= 0; angle--) {
    monServo.write(angle);
    delay(10);
  }
}
