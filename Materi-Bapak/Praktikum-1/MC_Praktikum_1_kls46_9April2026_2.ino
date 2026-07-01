void setup() {
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
}
void loop() {
  int d = 100;
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  for (int i = 4; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  delay(d);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  for (int i = 5; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  delay(d);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  for (int i = 6; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  delay(d);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  for (int i = 7; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  delay(d);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  for (int i = 8; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  delay(d);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  for (int i = 9; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  delay(d);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(d);
}
