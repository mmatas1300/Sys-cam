#include <Servo.h>
//=======================//
//======Vars Servo 1=====//
//======================//
Servo MyServo1;
int pinServo1 = 9;
long positionServo1 = 1500;
int directionServo1 = 0; // 0-left - 1-right
unsigned long previousMillis1 = 0;
unsigned long await1 = 1;//Definir rango

//======Vars Global=====//
unsigned long currentMillis = 0;

void setup()
{
	MyServo1.attach(pinServo1);
	MyServo1.writeMicroseconds(1500); // set servo to mid-point
}

void loop()
{
  currentMillis = millis();
	trajectoryServo1();
}

//=======================//
//======Servo 1 rutina=====//
//======================//

void trajectoryServo1()
{
	if (currentMillis - previousMillis1 > await1)
	{
		if (directionServo1 == 0)
		{
			positionServo1--;
			MyServo1.writeMicroseconds(positionServo1);
			if (positionServo1 == 700)
			{
				directionServo1 = 1;
			}
		}

		if (directionServo1 == 1)
		{
			positionServo1++;
			MyServo1.writeMicroseconds(positionServo1);
			if (positionServo1 == 2400)
			{
				directionServo1 = 0;
			}
		}
		previousMillis1 = currentMillis;
	}
}