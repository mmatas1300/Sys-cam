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
//=======================//
//======Vars Servo 2=====//
//======================//
Servo MyServo2;
int pinServo2 = 11;
long positionServo2 = 1500;
int directionServo2 = 0; // 0-left - 1-right
unsigned long previousMillis2 = 0;
unsigned long await2 = 1;//
unsigned long range2 = 0;//

//======Vars Global=====//
unsigned long currentMillis = 0;

void setup()
{
	MyServo1.attach(pinServo1);
	MyServo1.writeMicroseconds(1500); // set servo to mid-point
  MyServo2.attach(pinServo2);
	MyServo2.writeMicroseconds(1500); // set servo to mid-point
}

void loop()
{
  currentMillis = millis();
	trajectoryServo1();
  currentMillis = millis();
	trajectoryServo2();
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

		if (directionServo1 == 0)
		{
			positionServo1--;
			MyServo1.writeMicroseconds(positionServo1);
			if (positionServo1 < (600+range1))
			{
				directionServo1 = 1;
			}
		}

		if (directionServo1 == 1)
		{
			positionServo1++;
			MyServo1.writeMicroseconds(positionServo1);
			if (positionServo1 > (2300-range1))
			{
				directionServo1 = 0;
			}
		}
		previousMillis1 = currentMillis;
	}
}

//=======================//
//======Servo 2 rutina=====//
//======================//

void trajectoryServo2()
{
  int potAwait = analogRead(A2); //lectura analógica

  await2 = map(potAwait,0,1023,0,30); //función map para escalamiento

	if (currentMillis - previousMillis2 > await2)
	{
    int potRange = analogRead(A3); //lectura analógica
    range2 = map(potRange,0,1023,0,840); 

		if (directionServo2 == 0)
		{
			positionServo2--;
			MyServo2.writeMicroseconds(positionServo2);
			if (positionServo2 < (600+range2))
			{
				directionServo2 = 1;
			}
		}

		if (directionServo2 == 1)
		{
			positionServo2++;
			MyServo2.writeMicroseconds(positionServo2);
			if (positionServo2 > (2300-range2))
			{
				directionServo2 = 0;
			}
		}
		previousMillis2 = currentMillis;
	}
}



