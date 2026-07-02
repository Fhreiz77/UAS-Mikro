const int potPin = A0;
int digitPins[4] = { 10, 11, 12, 13 };  // Digit 1 (kiri) sampai Digit 4 (kanan)
int lastValue = 0;                      // menyimpan nilai terakhir
 
// ---------------------------
// SETUP
// ---------------------------
void setup() {
  for (int i = 2; i <= 9; i++) pinMode(i, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH);  // default OFF
  }
  Serial.begin(19200);
}

// ---------------------------
// PROSEDUR ANGKA 0–9
// ---------------------------
void angkaNol() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
void angkaSatu() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
void angkaDua() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void angkaTiga() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void angkaEmpat() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void angkaLima() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void angkaEnam() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void angkaTujuh() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
void angkaDelapan() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void angkaSembilan() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void tampilkanAngka(int num) {
  switch (num) {
    case 0: angkaNol(); break;
    case 1: angkaSatu(); break;
    case 2: angkaDua(); break;
    case 3: angkaTiga(); break;
    case 4: angkaEmpat(); break;
    case 5: angkaLima(); break;
    case 6: angkaEnam(); break;
    case 7: angkaTujuh(); break;
    case 8: angkaDelapan(); break;
    case 9: angkaSembilan(); break;
    default: angkaNol(); break;
  }
}

void tampilkanF() {
  //F
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void tampilkanU() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void tampilkanL() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

// ---------------------------
// FUNGSI MENAMPILKAN NILAI ADC KE DISPLAY (RATA KANAN)
// ---------------------------
void tampilkanADC(int nilai) {
  int ribuan = nilai / 1000;
  int ratusan = (nilai % 1000) / 100;
  int puluhan = (nilai % 100) / 10;
  int satuan = nilai % 10;
  int d = 3;

  if (nilai < 10) {
    digitalWrite(digitPins[3], LOW);
    tampilkanAngka(satuan);
    delay(d);
    digitalWrite(digitPins[3], HIGH);
  } else if (nilai < 100) {
    digitalWrite(digitPins[2], LOW);
    tampilkanAngka(puluhan);
    delay(d);
    digitalWrite(digitPins[2], HIGH);
    digitalWrite(digitPins[3], LOW);
    tampilkanAngka(satuan);
    delay(d);
    digitalWrite(digitPins[3], HIGH);
  } else if (nilai < 1000) {
    digitalWrite(digitPins[1], LOW);
    tampilkanAngka(ratusan);
    delay(d);
    digitalWrite(digitPins[1], HIGH);
    digitalWrite(digitPins[2], LOW);
    tampilkanAngka(puluhan);
    delay(d);
    digitalWrite(digitPins[2], HIGH);
    digitalWrite(digitPins[3], LOW);
    tampilkanAngka(satuan);
    delay(d);
    digitalWrite(digitPins[3], HIGH);
  }  else if (nilai < 1016) {
    digitalWrite(digitPins[0], LOW);
    tampilkanAngka(ribuan);
    delay(d);
    digitalWrite(digitPins[0], HIGH);
    digitalWrite(digitPins[1], LOW);
    tampilkanAngka(ratusan);
    delay(d);
    digitalWrite(digitPins[1], HIGH);
    digitalWrite(digitPins[2], LOW);
    tampilkanAngka(puluhan);
    delay(d);
    digitalWrite(digitPins[2], HIGH);
    digitalWrite(digitPins[3], LOW);
    tampilkanAngka(satuan);
    delay(d);
    digitalWrite(digitPins[3], HIGH);
  } else {
    digitalWrite(digitPins[0], LOW);
    tampilkanF();
    delay(d);
    digitalWrite(digitPins[0], HIGH);
    digitalWrite(digitPins[1], LOW);
    tampilkanU();
    delay(d);
    digitalWrite(digitPins[1], HIGH);
    digitalWrite(digitPins[2], LOW);
    tampilkanL();
    delay(d);
    digitalWrite(digitPins[2], HIGH);
    digitalWrite(digitPins[3], LOW);
    tampilkanL();
    digitalWrite(digitPins[3], HIGH);
  }
}

// ---------------------------
// LOOP UTAMA
// ---------------------------
void loop() {
  // ambil rata-rata 10 pembacaan untuk stabilisasi
  long total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(potPin);
  }
  int sensorValue = total / 10;

  // update hanya jika beda cukup besar
  if (abs(sensorValue - lastValue) > 2) {
    lastValue = sensorValue;
  }

  Serial.print("Nilai potensiometer: ");
  Serial.println(lastValue);

  // scanning berulang agar tampilan solid
  for (int i = 0; i < 100; i++) {
    tampilkanADC(lastValue);
  }
}
