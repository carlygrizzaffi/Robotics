void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //use serial port
  Serial.print("setup completed!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("We are ");
  Serial.println("looping now!");
  delay(100);
}
