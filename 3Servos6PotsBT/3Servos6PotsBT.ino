#include <Servo.h>
#include <SoftwareSerial.h>
//===Bluetooth===//
SoftwareSerial bluetooth(3, 5);
String configVector;
int vCam1=50;
int vCam2=50;
int vCam3=50;
int aCam1=50;
int aCam2=50;
int aCam3=50;

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
int pinServo2 = 10;
long positionServo2 = 1500;
int directionServo2 = 0; // 0-left - 1-right
unsigned long previousMillis2 = 0;
unsigned long await2 = 1;//
unsigned long range2 = 0;//
//=======================//
//======Vars Servo 3=====//
//======================//
Servo MyServo3;
int pinServo3 = 11;
long positionServo3 = 1500;
int directionServo3 = 0; // 0-left - 1-right
unsigned long previousMillis3 = 0;
unsigned long await3 = 1;//
unsigned long range3 = 0;//

//======Vars Global=====//
unsigned long currentMillis = 0;
const int buttonMode = 7;  // 
int buttonState=0;

void setup()
{
  bluetooth.begin(9600);
  configVector="";
  pinMode(buttonMode, INPUT);
	MyServo1.attach(pinServo1);
  MyServo2.attach(pinServo2);
  MyServo3.attach(pinServo3);
	MyServo1.writeMicroseconds(1500); // set servo to mid-point
  MyServo2.writeMicroseconds(1500); // set servo to mid-point
  MyServo3.writeMicroseconds(1500); // set servo to mid-point
}

void loop()
{
  buttonState = digitalRead(buttonMode);
  if (buttonState == LOW) {
    currentMillis = millis();
	  trajectoryServo1();
    currentMillis = millis();
	  trajectoryServo2();
    currentMillis = millis();
	  trajectoryServo3();
  } else {
    getParamsBT();
    currentMillis = millis();
	  trajectoryServo1BT();
    currentMillis = millis();
	  trajectoryServo2BT();
    currentMillis = millis();
	  trajectoryServo3BT();
  }

}

//=======================//
//=Bluetooth get params==//
//======================//
void getParamsBT()
{
  configVector = "";
  while (bluetooth.available()) {
      char charConfig = bluetooth.read();
      configVector = String(configVector + charConfig);
  }

  if(configVector.compareTo("")!=0)
  {
    int indexA = configVector.indexOf("A");
    int indexB = configVector.indexOf("B");
    String velCam1 = configVector.substring(indexA+1,indexB);
    int indexC = configVector.indexOf("C");
    String velCam2 = configVector.substring(indexB+1,indexC);
    int indexD = configVector.indexOf("D");
    String velCam3 = configVector.substring(indexC+1,indexD);
    int indexE = configVector.indexOf("E");
    String angCam1 = configVector.substring(indexD+1,indexE);
    int indexF = configVector.indexOf("F");
    String angCam2 = configVector.substring(indexE+1,indexF);
    String angCam3 = configVector.substring(indexF+1);
    vCam1 = velCam1.toInt();
    vCam2 = velCam2.toInt();
    vCam3 = velCam3.toInt();
    aCam1 = angCam1.toInt();
    aCam2 = angCam2.toInt();
    aCam3 = angCam3.toInt();
  }
}

//=======================//
//=Servo 1 rutina BT====//
//======================//

void trajectoryServo1BT()
{
  await1 = map(vCam1,0,100,50,0); //función map para escalamiento
	if (currentMillis - previousMillis1 > await1)
	{
    range1 = map(aCam1,0,100,840,0); 

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
//==Servo 2 rutina BT===//
//======================//

void trajectoryServo2BT()
{
  await2 = map(vCam2,0,100,50,0); //función map para escalamiento

	if (currentMillis - previousMillis2 > await2)
	{
    range2 = map(aCam2,0,100,840,0); 

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

//=======================//
//==Servo 3 rutina BT===//
//======================//

void trajectoryServo3BT()
{
  await3 = map(vCam3,0,100,50,0); 

	if (currentMillis - previousMillis3 > await3)
	{ 
    range3 = map(aCam3,0,100,840,0); 

		if (directionServo3 == 0)
		{
			positionServo3--;
			MyServo3.writeMicroseconds(positionServo3);
			if (positionServo3 < (600+range3))
			{
				directionServo3 = 1;
			}
		}

		if (directionServo3 == 1)
		{
			positionServo3++;
			MyServo3.writeMicroseconds(positionServo3);
			if (positionServo3 > (2300-range3))
			{
				directionServo3 = 0;
			}
		}
		previousMillis3 = currentMillis;
	}
}

//=======================//
//======Servo 1 rutina=====//
//======================//

void trajectoryServo1()
{
  int potAwait = analogRead(A0); //lectura analógica

  await1 = map(potAwait,0,1023,50,0); //función map para escalamiento

	if (currentMillis - previousMillis1 > await1)
	{
    int potRange = analogRead(A1); //lectura analógica
    range1 = map(potRange,0,1023,840,0); 

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
  await2 = map(potAwait,0,1023,50,0); //función map para escalamiento

	if (currentMillis - previousMillis2 > await2)
	{
    int potRange = analogRead(A3); //lectura analógica
    range2 = map(potRange,0,1023,840,0); 

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

//=======================//
//======Servo 3 rutina=====//
//======================//

void trajectoryServo3()
{
  int potAwait = analogRead(A4); 

  await3 = map(potAwait,0,1023,50,0); 

	if (currentMillis - previousMillis3 > await3)
	{
    int potRange = analogRead(A5); 
    range3 = map(potRange,0,1023,840,0); 

		if (directionServo3 == 0)
		{
			positionServo3--;
			MyServo3.writeMicroseconds(positionServo3);
			if (positionServo3 < (600+range3))
			{
				directionServo3 = 1;
			}
		}

		if (directionServo3 == 1)
		{
			positionServo3++;
			MyServo3.writeMicroseconds(positionServo3);
			if (positionServo3 > (2300-range3))
			{
				directionServo3 = 0;
			}
		}
		previousMillis3 = currentMillis;
	}
}


