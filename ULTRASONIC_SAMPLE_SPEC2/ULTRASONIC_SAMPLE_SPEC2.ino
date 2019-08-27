#define trigPin 13                 
#define echoPin 12                

int redPin = 11; 
int greenPin = 10; 
int bluePin = 9;

void setup()
{
  Serial.begin (9600);       
     
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);  

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
}

void loop()
{
  long duration, distance;                   
  // (1) : generate ultrasonic waveform
  digitalWrite(trigPin, LOW);                
  delayMicroseconds(2);                
  digitalWrite(trigPin, HIGH);            
  delayMicroseconds(10);               

  // (2) : Waveform length - the time from the launch
  //       of the ultrasound to the return
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);   

  distance = duration * 17 / 1000;

  if (distance >= 200 || distance <= 0)       
  {
    Serial.println("Unable to measure distance");
  }
  else                                           
  {
    Serial.print(distance);                      
    Serial.println(" cm");

//    setColor(0, 255, 0); // green 
//    delay(1000); 
  }
  delay(500);                                    
}

// This function parameter receive directly R, G, B value.
void setColor(int red, int green, int blue) 
{ 
  analogWrite(redPin,   red-255); 
  analogWrite(greenPin, green-255); 
  analogWrite(bluePin,  blue-255); 
}
