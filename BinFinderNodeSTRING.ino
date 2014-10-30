#include <Servo.h>
#include <Process.h>

Process XYNAMEstring;

Servo servoX;
Servo servoY;
int posX;
int posY;

int laser = 4;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(laser, OUTPUT);
  digitalWrite(laser, LOW);
  servoX.attach(2);
  servoY.attach(3);

}

void loop() {

  int sendData = 0;
  Servo currentServoX;
  Servo currentServoY;

  // if there's any serial data in the buffer, read a byte:
  if (Serial.available() > 0) {
    int inByte = Serial.read();

    // respond to the values 'r', 'g', 'b'.
    // you don't care about any other value:
    switch (inByte) {
      case'r':     // red
        sendData = 1;
        currentServoX = servoX;
        break;

      case 'g':    // green
        sendData = 2;
        currentServoY = servoY;

        break;

      case 'NAME':    // green
        sendData = 3;
        currentServoX = servoX;
        currentServoY = servoY;

        break;

        //  digitalWrite(laser, HIGH);
    }


    if (sendData == 1 ) {
      int PositionX = Serial.parseInt();
      // map the result to a level from 0 to 255
      PositionX = map(PositionX, 0, 100, 1, 180);
      posX = PositionX;
      servoX.write(posX);
      delay(15);
      digitalWrite(laser, HIGH);
      delay(1000);
      digitalWrite(laser, LOW);


      Serial.print("posX:");
      Serial.println(posX);
      delay(10);
    }


    if (sendData == 2 ) {
      int PositionY = Serial.parseInt();
      // map the result to a level from 0 to 255
      PositionY = map(PositionY, 0, 100, 1, 180);
      posY = PositionY;
      servoY.write(posY);
      digitalWrite(laser, HIGH);
      delay(1000);
      digitalWrite(laser, LOW);


      Serial.print("posY");
      Serial.println(posY);
      delay(10);
    }


    if (sendData == 3 ) {

      String XYString = XYNAMEstring.readString();

      // find the colons:
      int firstColon = XYString.indexOf(":");
      int secondColon = XYString.lastIndexOf(":");

      String posXstring = XYString.substring(0, firstColon);
      String posYstring = XYString.substring(firstColon + 1, secondColon);

      //int PositionNAMEX = Serial.parseInt();
      //int PositionNAMEY = Serial.parseInt();
      // map the result to a level from 0 to 255

      PositionNAMEX = posXstring.toInt();
      PositionNAMEY = posYstring.toInt();


      PositionNAMEX = map(PositionNAMEX, 0, 100, 1, 180);
      posY = PositionNAMEX;
      servoY.write(posY);

      PositionNAMEY = map(PositionNAMEY, 0, 100, 1, 180);
      posX = PositionNAMEY;
      servoX.write(posX);


      digitalWrite(laser, HIGH);
      delay(1000);
      digitalWrite(laser, LOW);
      Serial.print("PositionNAMEX");
      Serial.println(ositionNAMEX);
      delay(10);
    }

  }
}

