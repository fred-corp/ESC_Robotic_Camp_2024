#define BOUTON 4


void setup() {
  pinMode(BOUTON, INPUT);

  Serial.begin(9600);
}

void loop() {
  bool etat_bouton = digitalRead(BOUTON);
  
  Serial.println(etat_bouton);
  delay(50);
  
}
