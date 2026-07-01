#include <LedControl.h>

// Pin untuk MAX7219
#define DATA_IN     48  // Pin DIN (Data In)
#define LOAD        50  // Pin CS (Chip Select)
#define CLOCK       52  // Pin CLK (Clock)
#define MAX_DEVICES 4   // Jumlah modul MAX7219 yang digunakan

// Membuat objek LedControl untuk 4 display
LedControl lc = LedControl(DATA_IN, CLOCK, LOAD, MAX_DEVICES);

// Pola untuk angka 1 (8x8 matriks)
byte angka1[8] = {
  0b00011000,  // Baris 1
  0b00111000,  // Baris 2
  0b00011000,  // Baris 3
  0b00011000,  // Baris 4
  0b00011000,  // Baris 5
  0b00011000,  // Baris 6
  0b00011000,  // Baris 7
  0b00111100   // Baris 8
};

void setup() {
  // Inisialisasi MAX7219 untuk 4 display
  for (int i = 0; i < MAX_DEVICES; i++) {
    lc.shutdown(i, false);     // Matikan mode tidur
    lc.setIntensity(i, 1);     // Atur kecerahan (0-15)
    lc.clearDisplay(i);        // Bersihkan display
  }
}

void loop() {
  // Menampilkan angka 1 pada Display ke-2 (indeks 1)
  for (int row = 0; row < 8; row++) {
    lc.setRow(1, row, angka1[row]);  // Menampilkan pola angka1
  }
  
  // delay(1000);  // Tunda selama 1 detik sebelum menampilkan angka berikutnya
}