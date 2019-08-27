#include <Servo.h>
Servo servoA;
int angle = 0;

void setup() {
  Serial.begin(9600);
  servoA.attach(3);
}

void loop() {
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++) 
  { 
    servoA.write(angle); 
    delay(15); 
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--) 
  { 
    servoA.write(angle); 
    delay(15); 
  } 
}
