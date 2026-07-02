#include <Wire.h>        //Penggunaan I2C
#include <RTClib.h>      // Realtime clock
#include <LedControl.h>  // Penggunaan dot matrix MX7219
#include <Keypad.h>      // Penggunaan membran keypad 4x4

RTC_DS1307 rtc;
DateTime now;


#define DATA_IN 48
#define LOAD 50
#define CLOCK 52
#define MAX_DEVICES 4

LedControl lc = LedControl(DATA_IN, CLOCK, LOAD, MAX_DEVICES);

// ======================================================
// FONT 8x8
// ======================================================

// ------------------------------------------------------
// ANGKA 0-9
// ------------------------------------------------------

const byte fontDigit[10][8] = {

  { 0x3C,
    0x66,
    0x6E,
    0x76,
    0x66,
    0x66,
    0x3C,
    0x00 },  // 0

  {
    0x18,
    0x38,
    0x18,
    0x18,
    0x18,
    0x18,
    0x3C,
    0x00 },  // 1

  {
    0x3C,
    0x66,
    0x06,
    0x0C,
    0x30,
    0x60,
    0x7E,
    0x00 },  // 2
  {
    0x3C,
    0x66,
    0x06,
    0x1C,
    0x06,
    0x66,
    0x3C,
    0x00 },  // 3

  {
    0x0C,
    0x1C,
    0x2C,
    0x4C,
    0x7E,
    0x0C,
    0x0C,
    0x00 },  // 4

  {
    0x7E,
    0x60,
    0x7C,
    0x06,
    0x06,
    0x66,
    0x3C,
    0x00 },  // 5

  {
    0x3C,
    0x60,
    0x7C,
    0x66,
    0x66,
    0x66,
    0x3C,
    0x00 },  // 6

  {
    0x7E,
    0x06,
    0x0C,
    0x18,
    0x30,
    0x30,
    0x30,
    0x00 },  // 7

  {
    0x3C,
    0x66,
    0x66,
    0x3C,
    0x66,
    0x66,
    0x3C,
    0x00 },  // 8

  {
    0x3C,
    0x66,
    0x66,
    0x3E,
    0x06,
    0x0C,
    0x38,
    0x00 }  // 9
};

// ------------------------------------------------------
// HURUF BESAR A-Z
// ------------------------------------------------------

const byte fontUpper[27][8] = {

  { 0x18, 0x3C, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x00 },  // A
  { 0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x00 },  // B
  { 0x3C, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3C, 0x00 },  // C
  { 0x78, 0x6C, 0x66, 0x66, 0x66, 0x6C, 0x78, 0x00 },  // D
  { 0x7E, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x7E, 0x00 },  // E
  { 0x7E, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x60, 0x00 },  // F
  { 0x3C, 0x66, 0x60, 0x6E, 0x66, 0x66, 0x3C, 0x00 },  // G
  { 0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00 },  // H
  { 0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00 },  // I
  { 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x6C, 0x38, 0x00 },  // J
  { 0x66, 0x6C, 0x78, 0x70, 0x78, 0x6C, 0x66, 0x00 },  // K
  { 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x00 },  // L
  { 0x63, 0x77, 0x7F, 0x6B, 0x63, 0x63, 0x63, 0x00 },  // M
  { 0x66, 0x76, 0x7E, 0x7E, 0x6E, 0x66, 0x66, 0x00 },  // N
  { 0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00 },  // O
  { 0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60, 0x60, 0x00 },  // P
  { 0x3C, 0x66, 0x66, 0x66, 0x6E, 0x3C, 0x0E, 0x00 },  // Q
  { 0x7C, 0x66, 0x66, 0x7C, 0x78, 0x6C, 0x66, 0x00 },  // R
  { 0x3C, 0x66, 0x60, 0x3C, 0x06, 0x66, 0x3C, 0x00 },  // S
  { 0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00 },  // T
  { 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00 },  // U
  { 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x00 },  // V
  { 0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00 },  // W
  { 0x66, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x66, 0x00 },  // X
  { 0x66, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x18, 0x00 },  // Y
  { 0x7E, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x7E, 0x00 },  // Z
  { 0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18 }   //
};

// ------------------------------------------------------
//  New Character
// ------------------------------------------------------

const byte chara[8] = {
  0b00100100,
  0b01111110,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000,
  0b00000000
};




// ------------------------------------------------------
// HURUF kecil a-z
// ------------------------------------------------------

const byte fontLower[26][8] = {

  { 0x00, 0x00, 0x3C, 0x06, 0x3E, 0x66, 0x3E, 0x00 },  // a
  { 0x60, 0x60, 0x7C, 0x66, 0x66, 0x66, 0x7C, 0x00 },  // b
  { 0x00, 0x00, 0x3C, 0x66, 0x60, 0x66, 0x3C, 0x00 },  // c
  { 0x06, 0x06, 0x3E, 0x66, 0x66, 0x66, 0x3E, 0x00 },  // d
  { 0x00, 0x00, 0x3C, 0x66, 0x7E, 0x60, 0x3C, 0x00 },  // e
  { 0x1C, 0x30, 0x30, 0x7C, 0x30, 0x30, 0x30, 0x00 },  // f
  { 0x00, 0x3E, 0x66, 0x66, 0x3E, 0x06, 0x3C, 0x00 },  // g
  { 0x60, 0x60, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x00 },  // h
  { 0x18, 0x00, 0x38, 0x18, 0x18, 0x18, 0x3C, 0x00 },  // i
  { 0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0x6C, 0x38, 0x00 },  // j
  { 0x60, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0x00 },  // k
  { 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00 },  // l
  { 0x00, 0x00, 0x6C, 0x7E, 0x7E, 0x6B, 0x63, 0x00 },  // m
  { 0x00, 0x00, 0x7C, 0x66, 0x66, 0x66, 0x66, 0x00 },  // n
  { 0x00, 0x00, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00 },  // o
  { 0x00, 0x00, 0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60 },  // p
  { 0x00, 0x00, 0x3E, 0x66, 0x66, 0x3E, 0x06, 0x06 },  // q
  { 0x00, 0x00, 0x6E, 0x70, 0x60, 0x60, 0x60, 0x00 },  // r
  { 0x00, 0x00, 0x3E, 0x60, 0x3C, 0x06, 0x7C, 0x00 },  // s
  { 0x30, 0x30, 0x7C, 0x30, 0x30, 0x30, 0x1C, 0x00 },  // t
  { 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3E, 0x00 },  // u
  { 0x00, 0x00, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x00 },  // v
  { 0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00 },  // w
  { 0x00, 0x00, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x00 },  // x
  { 0x00, 0x00, 0x66, 0x66, 0x3E, 0x06, 0x3C, 0x00 },  // y
  { 0x00, 0x00, 0x7E, 0x0C, 0x18, 0x30, 0x7E, 0x00 }   // z

};

// ======================================================
// FUNGSI MEMBERSIHKAN DISPLAY
// ======================================================

void clearAll() {
  for (int i = 0; i < MAX_DEVICES; i++) {
    lc.clearDisplay(i);
  }
}

// ======================================================
// TAMPILKAN SATU KARAKTER
// ======================================================

void tampilKarakter(int display, char c) {
  byte buffer[8];

  // default kosong
  for (int i = 0; i < 8; i++) {
    buffer[i] = 0x00;
  }

  // angka
  if (c >= '0' && c <= '9') {
    for (int i = 0; i < 8; i++) {
      buffer[i] = fontDigit[c - '0'][i];
    }
  }

  // huruf besar
  else if (c >= 'A' && c <= 'Z') {
    for (int i = 0; i < 8; i++) {
      buffer[i] = fontUpper[c - 'A'][i];
    }
  }

  // huruf kecil
  else if (c >= 'a' && c <= 'z') {
    for (int i = 0; i < 8; i++) {
      buffer[i] = fontLower[c - 'a'][i];
    }
  }

  else {
    for (int i = 0; i < 8; i++) {
      buffer[i] = chara[i];
    }
  }

  // tampilkan ke matrix
  for (int row = 0; row < 8; row++) {
    lc.setRow(display, row, buffer[row]);
  }
}

// ======================================================
// SUBROUTINE TAMPIL 4 KARAKTER
// ======================================================

void tampil4Karakter(const char *text) {
  for (int i = 0; i < 4; i++) {
    if (text[i] != '\0') {
      // urutan dibalik karena susunan MAX7219
      tampilKarakter(3 - i, text[i]);
    } else {
      tampilKarakter(3 - i, ' ');
    }
  }
}


// ======================================================
// RUNNING TEXT
// ======================================================

// void scrollText(const char *text, int speedDelay) {
//   int len = strlen(text);

//   char buffer[5];

//   for (int pos = 0; pos < len + 4; pos++) {
//     for (int i = 0; i < 4; i++) {
//       int idx = pos + i - 4;

//       if (idx >= 0 && idx < len) {
//         buffer[i] = text[idx];
//       } else {
//         buffer[i] = ' ';
//       }
//     }

//     buffer[4] = '\0';

//     tampil4Karakter(buffer);

//     delay(speedDelay);
//   }
// }

const byte ROWS = 4;
const byte COLS = 4;


char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// byte rowPins[ROWS] = { 17, 19, 21, 23 };   // pin baris keypad
// byte colPins[COLS] = { 25, 27, 29, 31 };   // pin kolom keypad


byte rowPins[ROWS] = { 5, 7, 9, 11 };     // pin baris keypad
byte colPins[COLS] = { 13, 15, 17, 19 };  // pin kolom keypad


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ================= TAMPIL KARAKTER =================
void tampilDigit(int display, int angka) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(display, row, fontDigit[angka][row]);
  }
}


void tampil4Digit(int d1, int d2, int d3, int d4) {
  tampilDigit(3, d1);  // kiri
  tampilDigit(2, d2);
  tampilDigit(1, d3);
  tampilDigit(0, d4);  // kanan
}


// ======================================================
// SETUP
// ======================================================

void setup() {
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("RTC ERROR");
    while (1)
      ;
  }

  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  for (int i = 0; i < MAX_DEVICES; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 3);
    lc.clearDisplay(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  now = rtc.now();

  // ===== TAMPIL JAM =====
  int jamPuluhan = now.hour() / 10;
  int jamSatuan = now.hour() % 10;
  int minPuluhan = now.minute() / 10;
  int minSatuan = now.minute() % 10;


  // ===== TAMPIL TANGGAL =====
  int tglPuluhan = now.day() / 10;
  int tglSatuan = now.day() % 10;
  int blnPuluhan = now.month() / 10;
  int blnSatuan = now.month() % 10;

  int tahunSatuan = now.year() % 10;
  int tahunPuluhan = now.year() / 10;

  // int yr = now.year();

  //tampilkan di serial monitor
  Serial.print("Tanggal sekarang : ");
  Serial.print(tglPuluhan);
  Serial.print(tglSatuan);
  Serial.print(blnPuluhan);
  Serial.println(blnSatuan);
  delay(500);

  Serial.print("Waktu sekarang : ");
  Serial.print(jamPuluhan);
  Serial.print(jamSatuan);
  Serial.print(minPuluhan);
  Serial.println(minSatuan);
  delay(500);

  Serial.print(tahunPuluhan);
  Serial.print(tahunSatuan);   


  if (key == 'A') {
    // tampil4Karakter("AWOK");
    // typeid(now.year());
    tampil4Digit(2, 2, 2, 2);
    delay(2000);
  }

  if (key == 'B') {
    tampil4Digit(jamPuluhan, jamSatuan, minPuluhan, minSatuan);
    delay(1000);
  }


  if (key == 'C') {
    tampil4Digit(tglPuluhan, tglSatuan, blnPuluhan, blnSatuan);
    delay(1000);
  }

  if (key == 'D') {
    tampil4Digit(blnPuluhan, blnSatuan, tahunPuluhan, tahunSatuan);
    delay(1000);
  }
}
