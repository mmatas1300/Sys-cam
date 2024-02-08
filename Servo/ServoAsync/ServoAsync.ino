#include <Servo.h>
//=======================//
//======Vars Servo 1=====//
//======================//
Servo MyServo1;
int pinServo1 = 9;
long positionServo1 = 1500;
int directionServo1 = 0; // 0-left - 1-right
unsigned long previousMillis1 = 0;
unsigned long await1 = 1;//
unsigned long range1 = 0;//

//======Vars Global=====//
unsigned long currentMillis = 0;

void setup()
{
	MyServo1.attach(pinServo1);
	MyServo1.writeMicroseconds(1500); // set servo to mid-point
  Serial.begin(9600);
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


  int potAwait = analogRead(A0); //lectura analógica

  await1 = map(potAwait,0,1023,0,30); //función map para escalamiento

	if (currentMillis - previousMillis1 > await1)
	{
    int potRange = analogRead(A1); //lectura analógica
    range1 = map(potRange,0,1023,0,840); 
    Serial.println(range1); //primera variable a mostrar

		if (directionServo1 == 0)
		{
			positionServo1--;
			MyServo1.writeMicroseconds(positionServo1);
			if (positionServo1 < (720+range1))
			{
				directionServo1 = 1;
			}
		}

		if (directionServo1 == 1)
		{
			positionServo1++;
			MyServo1.writeMicroseconds(positionServo1);
			if (positionServo1 > (2380-range1))
			{
				directionServo1 = 0;
			}
		}
		previousMillis1 = currentMillis;
	}
}