const int digitPins[4] = {10, 11, 12, 13};

void setup() {

  // pin a sampe g + dp
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }

  // pin digit
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH);
  }
}

void allDigitOff() { 
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], HIGH);
  }
}

void printNumbers(int number) {

  switch(number) {
      
      case 0:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        break;

      case 1:
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        break;

      case 2:
        digitalWrite(2, LOW); 
        digitalWrite(3, LOW); 
        digitalWrite(4, HIGH); 
        digitalWrite(5, LOW); 
        digitalWrite(6, LOW); 
        digitalWrite(7, HIGH); 
        digitalWrite(8, LOW); 
        break;

      case 3:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        break;

      case 4:
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        break;

      case 5:
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        break;

      case 6:
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        break;

      case 7:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        break;

      case 8:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        break;

      case 9:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        break;
  }
  digitalWrite(9, HIGH); // set DP defaultnya mati
}

void loop() {

  // digit 1 = 3
  allDigitOff();
  digitalWrite(digitPins[0], LOW);
  printNumbers(3);
  delay(3);
  digitalWrite(digitPins[0], HIGH)

  // digit 2 = 0
  allDigitOff();
  digitalWrite(digitPins[1], LOW);
  printNumbers(0);

  delay(3);

  digitalWrite(digitPins[1], HIGH);

  // digit 3 = 2
  allDigitOff();
  digitalWrite(digitPins[2], LOW);
  printNumbers(2);
  delay(3);
  digitalWrite(digitPins[2], HIGH)

  // digit 4 = 6
  allDigitOff();
  digitalWrite(digitPins[3], LOW);
  printNumbers(6);
  delay(3);
  digitalWrite(digitPins[3], HIGH)

}



