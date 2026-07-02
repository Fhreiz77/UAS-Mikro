//To Save Memory and Time (Mostly Time)
//Function yg dibuat khusus untuk huruf dan angka yang digunakan

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

void clearSeg() {
  for (byte i = 2; i <= 9; i++) {
    digitalWrite(i, HIGH);  // semua segmen mati
  }
}

//Tampilin Nama
void ShowA() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, LOW); // c
  digitalWrite(5, HIGH); // d mati
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, LOW); // g
}

void ShowR() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, HIGH); // b
  digitalWrite(4, HIGH); // c
  digitalWrite(5, HIGH); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, HIGH); // g
}

void ShowI() {
  digitalWrite(2, HIGH); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, LOW); // c
  digitalWrite(5, HIGH); // d
  digitalWrite(6, HIGH); // e
  digitalWrite(7, HIGH); // f
  digitalWrite(8, HIGH); // g
}

void ShowL() {
  digitalWrite(2, HIGH); // a
  digitalWrite(3, HIGH); // b
  digitalWrite(4, HIGH); // c
  digitalWrite(5, LOW); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, HIGH); // g
}

void ShowJ() {
  digitalWrite(2, HIGH); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, LOW); // c
  digitalWrite(5, LOW); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, HIGH); // f
  digitalWrite(8, HIGH); // g
}

void ShowO() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, LOW); // c
  digitalWrite(5, LOW); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, HIGH); // g
}

void ShowH() {
  digitalWrite(2, HIGH); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, LOW); // c
  digitalWrite(5, HIGH); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, LOW); // g
}

void ShowN() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, LOW); // c
  digitalWrite(5, HIGH); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, HIGH); // g
}

void ShowE() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, HIGH); // b
  digitalWrite(4, HIGH); // c
  digitalWrite(5, LOW); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, LOW); // g
}

void ShowZ() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, HIGH); // c
  digitalWrite(5, LOW); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, HIGH); // f
  digitalWrite(8, LOW); // g
}

//Tampilin Angka
void Show0() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, LOW); // c
  digitalWrite(5, LOW); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, HIGH); // g
}

void Show2() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, LOW); // b
  digitalWrite(4, HIGH); // c
  digitalWrite(5, LOW); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, HIGH); // f
  digitalWrite(8, LOW); // g
}

void Show6() {
  digitalWrite(2, LOW); // a
  digitalWrite(3, HIGH); // b
  digitalWrite(4, LOW); // c
  digitalWrite(5, LOW); // d
  digitalWrite(6, LOW); // e
  digitalWrite(7, LOW); // f
  digitalWrite(8, LOW); // g
}

void ShowWord(int digit, char c) {
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

  if (digit == 1) {
    digitalWrite(10, LOW);
  }
  if (digit == 2) {
    digitalWrite(11, LOW);
  }
  if (digit == 3) {
    digitalWrite(12, LOW);
  }
  if (digit == 4) {
    digitalWrite(13, LOW);
  }

  switch (c) {
    //Alphabet
    case 'A' : ShowA(); break;
    case 'R' : ShowR(); break;
    case 'I' : ShowI(); break;
    case 'L' : ShowL(); break;
    case 'J' : ShowJ(); break;
    case 'O' : ShowO(); break;
    case 'H' : ShowH(); break;
    case 'N' : ShowN(); break;
    case 'E' : ShowE(); break;
    case 'Z' : ShowZ(); break;

    //Angka
    case '0' : Show0(); break;
    case '2' : Show2(); break;
    case '6' : Show6(); break;

    default : clearSeg(); break;
  }
}

void loop() {
  int d = 3;            // delay scanning per digit
  int stepDelay = 200;  // jeda antar langkah animasi (ms)

  char teks[] = { 'A', 'R', 'I', 'L', ' ', 'J', 'O', 'H', 'N', ' ', 'R', 'E', 'J', 'I', ' ', '2', '0', '2', '6' };
  // char teks[] = 'ARIL JOHN REJI, Z kdd jar ';
  int panjang = sizeof(teks);

  for (int offset = 0; offset <= panjang + 3; offset++) {
    unsigned long start = millis();
    while (millis() - start < stepDelay) {
      // scanning 4 digit
      for (int digit = 1; digit <= 4; digit++) {
        int idx = offset + digit - 4;  // hitung index Show
        if (idx >= 0 && idx < panjang) {
          ShowWord(digit, teks[idx]);
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
