// PRAKTIKUM KE-5  KULIAH DARING MIKROKONTROLER
// MODUL ARDUINO MEGA 2560 PRO MINI dan MEMBRAN KEYPAD 4X4
// ANTI BOUNCHING
// KELAS 46-47 REGULER SORE
// 4 Juni 2026
// PENGAMPU: BUDI RAHMANI

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

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

byte rowPins[ROWS] = { 5, 7, 9, 11 };  // pin baris keypad
byte colPins[COLS] = { 13, 15, 17, 19 };  // pin kolom keypad

// byte rowPins[ROWS] = { 3, 5, 7, 9 };   // pin baris keypad
// byte colPins[COLS] = { 11, 13, 15, 17 };   // pin kolom keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200);
  keypad.setDebounceTime(50);  // atur debounce agar tidak ganda

  lcd.init();  // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Mikrokontroler");
  lcd.setCursor(0, 1);
  lcd.print("Kelas 46!");
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {  // hanya jika ada tombol valid
    Serial.print("Key Pressed : ");
    Serial.println(key);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tombol ditekan:");
    lcd.setCursor(0, 1);
    lcd.print(key);
  }
}
