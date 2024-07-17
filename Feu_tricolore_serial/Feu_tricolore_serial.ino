// Connexions
#define VERT    8
#define ORANGE  9
#define ROUGE  10

// Delais
#define DELAI_VERT   5000
#define DELAI_ORANGE 1000
#define DELAI_ROUGE  5000

void setup() {
  pinMode(VERT, OUTPUT);
  pinMode(ORANGE, OUTPUT);
  pinMode(ROUGE, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Feu vert allumé");
  digitalWrite(VERT, HIGH);
  delay(DELAI_VERT);
  digitalWrite(VERT, LOW);

  Serial.println("Feu orange allumé");
  digitalWrite(ORANGE, HIGH);
  delay(DELAI_ORANGE);
  digitalWrite(ORANGE, LOW);

  Serial.println("Feu rouge allumé");
  digitalWrite(ROUGE, HIGH);
  delay(DELAI_ROUGE);
  digitalWrite(ROUGE, LOW);
}
