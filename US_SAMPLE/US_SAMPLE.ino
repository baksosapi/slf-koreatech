#define trigPin 13                 
#define echoPin 12                

void setup()
{
  Serial.begin (9600);       
     
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);   
}

void loop()
{
//******************************************************//
  // Sample Code
  long duration, distance;                   
  // (1) : generate ultrasonic waveform
  digitalWrite(trigPin, LOW);                
  delayMicroseconds(2);                
  digitalWrite(trigPin, HIGH);            
  delayMicroseconds(10);               

  // (2) : Waveform length - the time from the launch
  //       of the ultrasound to the return
  digitalWrite(trigPin, LOW);
  // pulseIn(pin_number, pulse)
  // Read a pulse (HIGH or LOW) on the pin.
  // For example, if value is HIGH, first pulseIn() waits until the pin goes HIGH,
  // second starts a timer, finally waits for the pin to go low and stops the timer.
  //  - Parameter 1 [pin_number] : Pin Number
  //  - Parameter 2 [pulse]      : pulse (HIGH or LOW)
  duration = pulseIn(echoPin, HIGH);   

  distance = duration * 17 / 1000;
  // Why write "distance = duration * 17 / 1000" code
  // Distance is time x speed.
  // The speed is 340mm per second at the speed of sound,
  // so the time * 340m is converted to 34,000cm in order to change in cm.
  // The duration that the time value is stored in is stored in microseconds,
  // so it divides 1,000,000 for conversion.
  // So the time x 34,000 / 1,000,000 comes out and the sum is the distance * 34 / 1,000.
  // However, it took two times to reach and return to the obstacle, so divide by two.
  // Then comes the formula of time x 17 / 1,000.

  if (distance >= 200 || distance <= 0)       
  {
    Serial.println("Unable to measure distance");
  }
  else                                           
  {
    Serial.print(distance);                      
    Serial.println(" cm");                       
  }
  delay(500);                                    
}
