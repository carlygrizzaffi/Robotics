#include <Servo.h>

int piezo = A0;

int sensorReading = 0;
int threshold = 490;

Servo servoLeft;
Servo servoRight;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12
  servoLeft.writeMicroseconds(1500);        // Calibrate left servo
  servoRight.writeMicroseconds(1500);
}

void movement(){
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorReading = analogRead(piezo);

  Serial.println(sensorReading);

  if (sensorReading >= 490) {
    movement();
    delay(100);
  }else{
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
    delay(100);
  }
  
  delay(100);
}
