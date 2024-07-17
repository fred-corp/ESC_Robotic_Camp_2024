#define LED_PIN 6        // LED branchée sur broche 6

void setup() {
  // Définir broche LED_PIN comme sortie
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, 5);
  delay(1000);
  analogWrite(LED_PIN, 127);
  delay(1000);
  analogWrite(LED_PIN, 250);
  delay(1000);
  
}
