#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9

int vitesse_croisiere = 85;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  delay(2000);
}

void loop() {
  // faire des choses ici

  for(int i = 0; i <= vitesse_croisiere; i++) {
    avancer(i);
    delay(5);
  }
  
  delay(5000);

  for(int i = vitesse_croisiere; i >= 0; i--) {
    avancer(i);
    delay(5);
  }
  
  stop();
  while(1);
}

void avancer(int vitesse) {
  int PWM = map(vitesse, 0, 100, 0, 255);
  
  int gauche = map(PWM, 0, 255, 0, 234);
  int droite = map(PWM, 0, 255, 0, 255);
  
  analogWrite(IN1, gauche);
  analogWrite(IN2, 0);
  analogWrite(IN3, droite);
  analogWrite(IN4, 0);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
