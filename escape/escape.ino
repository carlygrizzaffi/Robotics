#include <Servo.h>
int leftWhisker = 5;
int piezo = A0;
int rightWhisker = 7;
int sensorReading = 0;
int lValue ;
int rValue;
Servo servoLeft;
Servo servoRight;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12
  servoLeft.writeMicroseconds(1500);        // Calibrate left servo
  servoRight.writeMicroseconds(1500);
  pinMode(leftWhisker, INPUT);
  pinMode(rightWhisker, INPUT);

}

void movement(){
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay(500);
}
void stop1 () {
   servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
  delay(4000);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorReading = analogRead(piezo);
  Serial.println(sensorReading);
  lValue = digitalRead(leftWhisker);
  rValue = digitalRead(rightWhisker);
  if (sensorReading >= 630) {
  stop1();
  }
  else if (lValue == 0 && rValue== 0) {
    //turn 180
     servoLeft.writeMicroseconds(700);
  servoRight.writeMicroseconds(400);
  delay(1600);
  }
  else if (lValue == 0 && rValue == 1) {
    //turn right 90
     servoLeft.writeMicroseconds(700);
  servoRight.writeMicroseconds(400);
  delay(800);
  }
  else if (lValue == 1 && rValue == 0) {
    //turn left 90 
     servoLeft.writeMicroseconds(400);
  servoRight.writeMicroseconds(700);
  delay(800);
  }
  else {
    movement();
  }
 
}
