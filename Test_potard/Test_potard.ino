#define POTARD A0
#define LED     6

void setup() {
  pinMode(POTARD, INPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int tension = analogRead(POTARD);

  int luminosite = map(tension, 0, 1023, 0, 255);

  analogWrite(LED, luminosite);
  
  Serial.println(tension);
  delay(50);
}
