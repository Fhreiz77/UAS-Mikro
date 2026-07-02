const int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};  // daftar pin LED
const int jumlahPin = sizeof(pins) / sizeof(pins[0]);
int d = 300;

void setup() {
  for (int i = 0; i < jumlahPin; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // pola: menyalakan 2 LED berurutan, mematikan sisanya
  for (int i = 0; i < jumlahPin - 1; i++) {
    // matikan semua LED dulu
    for (int j = 0; j < jumlahPin; j++) {
      digitalWrite(pins[j], LOW);
    }
    // nyalakan LED ke-i dan ke-(i+1)
    digitalWrite(pins[i], HIGH);
    digitalWrite(pins[i + 1], HIGH);

    delay(d);
  }
}
