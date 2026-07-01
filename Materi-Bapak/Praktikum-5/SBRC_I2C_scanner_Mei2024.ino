#include <Wire.h>

void setup() {
  Wire.begin(); // Mulai komunikasi I2C
  Serial.begin(115200); // Mulai komunikasi serial
  while (!Serial); // Tunggu hingga serial siap (hanya untuk Arduino Leonardo)
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++) {
    // Kirimkan sinyal ke setiap address I2C
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(5000); // Tunggu 5 detik sebelum scan ulang
}
