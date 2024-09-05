int potPosition;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potPosition = analogRead(0);
  Serial.println(potPosition);
}
