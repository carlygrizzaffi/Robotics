int leftwhisker = 5;
int rightwhisker = 7;
//we declared variables for each whisker pin.


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("We are set up!");

  pinMode(leftwhisker, INPUT);
  pinMode(rightwhisker, INPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  int leftWhiskerValue = digitalRead(leftwhisker);
  int rightWhiskerValue = digitalRead(rightwhisker);
  //Serial.print("left :");
  //Serial.println(leftWhiskerValue);
  //Serial.print("right :");
  //Serial.println("rightWhiskerValue");
  if(leftWhiskerValue == 1 && rightWhiskerValue == 1){
      Serial.println("Left and Right are pressed!");
    }else if (leftWhiskerValue == 1){
      Serial.println("Left is pressed!");
    }else if (rightWhiskerValue == 1){
      Serial.println("Right is pressed!");
    }else{
      Serial.println("No whiskers are pressed!");
    }

  delay(100);
}
