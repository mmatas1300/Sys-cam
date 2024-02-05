#include <SoftwareSerial.h>

// Set up a new SoftwareSerial object
SoftwareSerial bluetooth(3, 5);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
      char mychar =bluetooth.read();
      Serial.print(mychar);

  }

  if (Serial.available()) {
    char myOtroChar = Serial.read();
    bluetooth.print(myOtroChar);
  }
}