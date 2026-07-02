void setup() {
    for (int i = 2; i <= 9; i++) { pinMode(i, OUTPUT); }
}
void loop() {
  int d = 500;
    for (int i = 2, j = 9; i<=5; i++ && j--) {
      digitalWrite(i, HIGH);
      digitalWrite(j, HIGH);
      delay(d);
      digitalWrite(i, LOW);
      digitalWrite(j, LOW);
      }

      
}