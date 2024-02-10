#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(9);
  myservo.writeMicroseconds(1450);  // set servo to mid-point
}

void loop() {

  for(int i = 600; i<2300 ;i++ ){
    myservo.writeMicroseconds(i);
    delay(1);
  }

  for(int i = 2300; i>600 ;i-- ){
    myservo.writeMicroseconds(i);
    delay(1);
  }




}