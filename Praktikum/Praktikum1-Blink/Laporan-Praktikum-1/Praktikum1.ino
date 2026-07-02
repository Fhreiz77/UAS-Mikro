//Kelompok 1
//Jonathan Andrew Wijaya (310124023844)
//Nazril Anbiya Rasyada (310124023851)
//Muhammad Iqbal Fahrezi (310124023855)

void setup() {
 for (int i = 2; i <= 9; i++) { pinMode(i, OUTPUT); }
}

void loop() {

  int d_short = 100;
  int d_long = 300;

  for (int i = 2, j = 9; i <= 5; i++ && j--) {
    digitalWrite(i, HIGH);
    digitalWrite(j, HIGH);
    delay(d_long);
    digitalWrite(i, LOW);
    digitalWrite(j, LOW);
  }

  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);
    delay(d_short);
    digitalWrite(i, LOW);
 }

  for (int i = 9; i >= 2; i--) {
    digitalWrite(i, HIGH);
    delay(d_short);
    digitalWrite(i, LOW);
  }

  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);
    delay(d_short);
  }

  for (int i = 2; i <= 9; i++) {
    digitalWrite(i, LOW);
    delay(d_short);
  }

  for (int i = 9; i >= 2; i--) {
    digitalWrite(i, HIGH);
    delay(d_short);
  }

  for (int i = 9; i >= 2; i--) {
    digitalWrite(i, LOW);
    delay(d_short);
  }

  for (int i = 5, j = 6; i>=2; i-- && j++) {
    digitalWrite(i, HIGH);
    digitalWrite(j, HIGH);
    delay(d_long);
    digitalWrite(i, LOW);
    digitalWrite(j, LOW);
    
}
