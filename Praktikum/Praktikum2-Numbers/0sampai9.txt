void setup() {
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(19200);
}

void AngkaNol() {
  digitalWrite(2,LOW); // segment a
  digitalWrite(3,LOW); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,LOW); // segment d
  digitalWrite(6,LOW); // segment e
  digitalWrite(7,LOW); // segment f
  digitalWrite(8,HIGH); // segment g
}

void AngkaSatu() {
  digitalWrite(2,HIGH); // segment a
  digitalWrite(3,LOW); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,HIGH); // segment d
  digitalWrite(6,HIGH); // segment e
  digitalWrite(7,HIGH); // segment f
  digitalWrite(8,HIGH); // segment g
}

void AngkaDua() {
  digitalWrite(2,LOW); // segment a
  digitalWrite(3,LOW); // segment b
  digitalWrite(4,HIGH); // segment c
  digitalWrite(5,LOW); // segment d
  digitalWrite(6,LOW); // segment e
  digitalWrite(7,HIGH); // segment f
  digitalWrite(8,LOW); // segment g
}

void AngkaTiga() {
  digitalWrite(2,LOW); // segment a
  digitalWrite(3,LOW); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,LOW); // segment d
  digitalWrite(6,HIGH); // segment e
  digitalWrite(7,HIGH); // segment f
  digitalWrite(8,LOW); // segment g
}

void AngkaEmpat() {
  digitalWrite(2,HIGH); // segment a 
  digitalWrite(3,LOW); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,HIGH); // segment d
  digitalWrite(6,HIGH); // segment e
  digitalWrite(7,LOW); // segment f
  digitalWrite(8,LOW); // segment g
}

void AngkaLima() {
  digitalWrite(2,LOW); // segment a
  digitalWrite(3,HIGH); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,LOW); // segment d
  digitalWrite(6,HIGH); // segment e
  digitalWrite(7,LOW); // segment f
  digitalWrite(8,LOW); // segment g
}

void AngkaEnam() {
  digitalWrite(2,LOW); // segment a
  digitalWrite(3,HIGH); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,LOW); // segment d
  digitalWrite(6,LOW); // segment e
  digitalWrite(7,LOW); // segment f
  digitalWrite(8,LOW); // segment g
}

void AngkaTujuh() {
  digitalWrite(2,LOW); // segment a
  digitalWrite(3,LOW); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,HIGH); // segment d
  digitalWrite(6,HIGH); // segment e
  digitalWrite(7,HIGH); // segment f
  digitalWrite(8,HIGH); // segment g
}

void AngkaDelapan() {
  digitalWrite(2,LOW); // segment a
  digitalWrite(3,LOW); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,LOW); // segment d
  digitalWrite(6,LOW); // segment e
  digitalWrite(7,LOW); // segment f
  digitalWrite(8,LOW); // segment g
} 

void AngkaSembilan () {
  digitalWrite(2,LOW); // segment a
  digitalWrite(3,LOW); // segment b
  digitalWrite(4,LOW); // segment c
  digitalWrite(5,LOW); // segment d
  digitalWrite(6,HIGH); // segment e
  digitalWrite(7,LOW); // segment f
  digitalWrite(8,LOW); // segment g
}

void loop() {

  int SensorValue = analogRead(A0);

  Serial.println("Value Potensio Meter :");
  // Serial.println(SensorValue);
  if (SensorValue >= 0 && SensorValue <= 369) {
      AngkaSatu();
      Serial.println(SensorValue);
  } else if(SensorValue >= 370 && SensorValue <= 499) {
    AngkaDua();
    Serial.println(SensorValue);
  } else if (SensorValue >= 500 && SensorValue <= 799) {
    AngkaTiga();
    Serial.println(SensorValue);
  } else if (SensorValue >= 800) {
    AngkaEmpat();
    Serial.println(SensorValue);
  };
  delay(100);

  // AngkaSembilan();
  // delay(d);
  // AngkaDelapan();
  // delay(d);
  // AngkaTujuh();
  // delay(d);
  // AngkaEnam();
  // delay(500);
  // AngkaLima();
  // delay(500);
  // AngkaEmpat();
  // delay(500);
  // AngkaTiga();
  // delay(500);
  // AngkaDua();
  // delay(500);
  // AngkaSatu();
  // delay(500);
  // AngkaNol();
  // delay(500);
  
}

