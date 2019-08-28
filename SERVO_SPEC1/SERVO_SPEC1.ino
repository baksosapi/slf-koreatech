#include <Servo.h>
Servo servoA;
int angle = 0;

void setup() {
  Serial.begin(9600);
  servoA.attach(3);
}

void loop() {
  long t0 = millis();

  for (int i=1; i<10; i++){

    long t1 = millis();
    // scan from 0 to 180 degrees
    for(angle = 0; angle < 180; angle++) 
    { 
      servoA.write(angle); 
      delay(15); 
    } 
    Serial.print("Time Forward-");
    Serial.println(i);
    Serial.println(millis()-t1); // waktu 1 putaran

    long t2 = millis();
    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 0; angle--) 
    { 
      servoA.write(angle); 
      delay(15); 
    } 
    Serial.print("Time Backward-");
    Serial.println(i);
    Serial.println(millis()-t2); // waktu 1 putaran

  }
  Serial.println("Time Average");
  Serial.print((millis()-t0)/10);
}
