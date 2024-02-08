#include <Servo.h>

Servo MyServo1;
int pinServo1 = 9;
long positionServo1 = 1500;
int directionServo1 = 0; // 0-left - 1-right

unsigned long previousMillis1 = 0;
unsigned long await1 = 50;//Definir rango

void setup()
{
	MyServo1.attach(pinServo1);
	MyServo1.writeMicroseconds(1500); // set servo to mid-point
}

void loop()
{
	trajectoryServo1();
}

void trajectoryServo1()
{
	unsigned long currentMillis = millis();

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