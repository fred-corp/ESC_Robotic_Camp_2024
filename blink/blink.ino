/*
 * Ce programme fait clignotter une
 * LED connectée à une broche numérique
 * de l'Arduino UNO
 * 
 * Frédéric D. - 2024
 */

#define LED_PIN 6        // LED branchée sur broche 6

#define DELAY_ON  250
#define DELAY_OFF 750

void setup() {
  // Définir broche 13 comme sortie
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(DELAY_ON);
  digitalWrite(LED_PIN, LOW);
  delay(DELAY_OFF);
}
