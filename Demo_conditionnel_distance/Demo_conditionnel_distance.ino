#define TRIG_PIN  7
#define ECHO_PIN  8
#define LED      13

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  float obstacle = capteurDistance();

  if(obstacle > 20){
    digitalWrite(LED, LOW);
  }
  else if (obstacle <= 20 && obstacle > 10) {
    digitalWrite(LED, HIGH);
    Serial.println("Danger");
  }
  else {
    Serial.println("Collision");
  }
  
  delay(100);
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
