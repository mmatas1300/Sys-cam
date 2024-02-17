#include <SoftwareSerial.h>

// Set up a new SoftwareSerial object
SoftwareSerial bluetooth(3, 5);
String configVector;
int vCam1=50;
int vCam2=50;
int vCam3=50;
int aCam1=50;
int aCam2=50;
int aCam3=50;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  configVector="";

}

void loop() {
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

    Serial.println(vCam1);
    Serial.println(vCam2);
    Serial.println(vCam3);
    Serial.println(aCam1);
    Serial.println(aCam2);
    Serial.println(aCam3);
  }
  

}