#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(9);
  myservo.writeMicroseconds(700);  // set servo to mid-point
}

void loop() {

  for(int i = 700; i<=2300 ;i++ ){
    myservo.writeMicroseconds(i);
    delay(5);
  }

  for(int i = 2299; i>700 ;i-- ){
    myservo.writeMicroseconds(i);
    delay(5);
  }




}