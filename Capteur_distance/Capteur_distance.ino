#define TRIG_PIN 7
#define ECHO_PIN 8


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  float obstacle = capteurDistance();

  Serial.println(obstacle);
  delay(50);
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
