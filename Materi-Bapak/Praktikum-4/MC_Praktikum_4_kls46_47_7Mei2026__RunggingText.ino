/*
 * Program: Menampilkan teks berjalan di 7-segment 4 digit
 * Fitur: Dukungan huruf A–Z dan angka 0–9
 * Teknik: Scanning manual
 */

void setup() {
  // Inisialisasi pin segmen (a–g + h)
  for (byte i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  // Inisialisasi pin digit (Digit1–Digit4)
  for (byte i = 10; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

// ---------------------------
// PROSEDUR CLEAR SEGMENT
// ---------------------------
void clearSeg() {
  for (byte i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);  // semua segmen mati
  }
}

// ---------------------------
// PROSEDUR ANGKA 0–9
// ---------------------------
void angka0() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}
void angka1() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}
void angka2() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}
void angka3() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}
void angka4() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void angka5() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void angka6() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void angka7() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}
void angka8() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void angka9() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

// ---------------------------
// PROSEDUR HURUF A–Z
// ---------------------------
void hurufA() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufB() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufC() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}
void hurufD() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}
void hurufE() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufF() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufG() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufH() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufI() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}
void hurufJ() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}
void hurufK() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufL() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}
void hurufM() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}

void hurufN() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}
void hurufO() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}
void hurufP() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufQ() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufR() {
  digitalWrite(2, LOW);   //a
  digitalWrite(3, HIGH);  //b
  digitalWrite(4, HIGH);  //c
  digitalWrite(5, HIGH);  //d
  digitalWrite(6, LOW);   //e
  digitalWrite(7, LOW);   //f
  digitalWrite(8, HIGH);  //g
}
void hurufS() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
void hurufT() {
  digitalWrite(2, HIGH);  //segment a
  digitalWrite(3, HIGH);  //segment b
  digitalWrite(4, HIGH);  //segment c
  digitalWrite(5, LOW);   //segment d
  digitalWrite(6, LOW);   //segment e
  digitalWrite(7, LOW);   //segment f
  digitalWrite(8, LOW);   //segment G
}
void hurufU() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}
void hurufV() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}


void hurufW() {
  digitalWrite(2, HIGH);  // a mati
  digitalWrite(3, LOW);   // b nyala
  digitalWrite(4, LOW);   // c nyala
  digitalWrite(5, LOW);   // d nyala
  digitalWrite(6, LOW);   // e nyala
  digitalWrite(7, LOW);   // f nyala
  digitalWrite(8, HIGH);  // g mati
}

void hurufX() {
  digitalWrite(2, LOW);   // a nyala
  digitalWrite(3, LOW);   // b nyala
  digitalWrite(4, LOW);   // c nyala
  digitalWrite(5, HIGH);  // d mati
  digitalWrite(6, LOW);   // e nyala
  digitalWrite(7, LOW);   // f nyala
  digitalWrite(8, LOW);   // g nyala
}

void hurufY() {
  digitalWrite(2, LOW);   // a nyala
  digitalWrite(3, LOW);   // b nyala
  digitalWrite(4, LOW);   // c nyala
  digitalWrite(5, LOW);   // d nyala
  digitalWrite(6, HIGH);  // e mati
  digitalWrite(7, LOW);   // f nyala
  digitalWrite(8, LOW);   // g nyala
}

void hurufZ() {
  digitalWrite(2, LOW);   // a nyala
  digitalWrite(3, LOW);   // b nyala
  digitalWrite(4, HIGH);  // c mati
  digitalWrite(5, LOW);   // d nyala
  digitalWrite(6, LOW);   // e nyala
  digitalWrite(7, HIGH);  // f mati
  digitalWrite(8, LOW);   // g nyala
}

// ---------------------------
// PROSEDUR TAMPILKAN KARAKTER DI DIGIT
// ---------------------------
void tampilkanKarakter(int digit, char c) {
  // Matikan semua digit dulu
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

  // Pilih digit yang aktif
  if (digit == 1) digitalWrite(10, LOW);
  if (digit == 2) digitalWrite(11, LOW);
  if (digit == 3) digitalWrite(12, LOW);
  if (digit == 4) digitalWrite(13, LOW);

  // Tampilkan karakter sesuai c
  switch (c) {
    // Angka
    case '0': angka0(); break;
    case '1': angka1(); break;
    case '2': angka2(); break;
    case '3': angka3(); break;
    case '4': angka4(); break;
    case '5': angka5(); break;
    case '6': angka6(); break;
    case '7': angka7(); break;
    case '8': angka8(); break;
    case '9': angka9(); break;

    // Huruf A–Z
    case 'A': hurufA(); break;
    case 'B': hurufB(); break;
    case 'C': hurufC(); break;
    case 'D': hurufD(); break;
    case 'E': hurufE(); break;
    case 'F': hurufF(); break;
    case 'G': hurufG(); break;
    case 'H': hurufH(); break;
    case 'I': hurufI(); break;
    case 'J': hurufJ(); break;
    case 'K': hurufK(); break;
    case 'L': hurufL(); break;
    case 'M': hurufM(); break;
    case 'N': hurufN(); break;
    case 'O': hurufO(); break;
    case 'P': hurufP(); break;
    case 'Q': hurufQ(); break;
    case 'R': hurufR(); break;
    case 'S': hurufS(); break;
    case 'T': hurufT(); break;
    case 'U': hurufU(); break;
    case 'V': hurufV(); break;
    case 'W': hurufW(); break;
    case 'X': hurufX(); break;
    case 'Y': hurufY(); break;
    case 'Z': hurufZ(); break;

    default: clearSeg(); break;
  }
}

void loop() {
  int d = 3;            // delay scanning per digit
  int stepDelay = 500;  // jeda antar langkah animasi (ms)

  // String yang ingin ditampilkan
  // char teks[] = { 'B', 'U', 'D', 'I', ' ', 'R', 'A', 'H', 'M', 'A', 'N', 'I', ' ', '2', '0', '2', '6' };
  char teks[] = { 'S', 'T', 'M', 'I', 'K', ' ', 'B', 'A', 'N', 'J', 'A', 'R', 'B', 'A', 'R', 'U' };

  int panjang = sizeof(teks);

  // Geser huruf dari kanan ke kiri
  for (int offset = 0; offset <= panjang + 3; offset++) {
    unsigned long start = millis();
    while (millis() - start < stepDelay) {
      // scanning 4 digit
      for (int digit = 1; digit <= 4; digit++) {
        int idx = offset + digit - 4;  // hitung index huruf
        if (idx >= 0 && idx < panjang) {
          tampilkanKarakter(digit, teks[idx]);
        } else {
          clearSeg();  // kosong
        }
        delay(d);
      }
    }
  }

  // Setelah selesai, kosongkan display sebentar
  unsigned long kosongStart = millis();
  while (millis() - kosongStart < 800) {
    for (int digit = 1; digit <= 4; digit++) {
      clearSeg();
      delay(d);
    }
  }
}