#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  delay(2000);
}

void loop() {
  // faire des choses ici
  avancer();
  delay(5000);
  stop();
  while(1);
}

void avancer() {
  // code pour faire avancer
  analogWrite(IN1, 255);
  analogWrite(IN2, 0);
  analogWrite(IN3, 255);
  analogWrite(IN4, 0);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
