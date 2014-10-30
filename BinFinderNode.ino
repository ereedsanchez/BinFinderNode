#include <Servo.h>

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
  Servo currentServo;

  // if there's any serial data in the buffer, read a byte:
  if (Serial.available() > 0) {
    int inByte = Serial.read();

    // respond to the values 'r', 'g', 'b'.
    // you don't care about any other value:
    switch (inByte) {
      case'r':     // red
        sendData = 1;
        currentServo = servoX;
        break;

      case 'g':    // green
        sendData = 2;
        currentServo = servoY;

        break;

        //  digitalWrite(laser, HIGH);
    }


    if (sendData == 1 ) {
      int Position1 = Serial.parseInt();
      // map the result to a level from 0 to 255
      Position1 = map(Position1, 0, 100, 1, 180);
      posX = Position1;
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
      int Position2 = Serial.parseInt();
      // map the result to a level from 0 to 255
      Position2 = map(Position2, 0, 100, 1, 180);
      posY = Position2;
      servoY.write(posY);
      digitalWrite(laser, HIGH);
      delay(1000);
      digitalWrite(laser, LOW);
      Serial.print("posY");
      Serial.println(posY);

      delay(10);

    }

  }
}
