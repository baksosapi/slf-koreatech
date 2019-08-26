int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  }

void loop(){
  setColor(148,0,211);//Violet  148, 0, 211 #9400D3 

  delay(500);
  setColor(75,0,130);//Indigo  75, 0, 130  #4B0082 

  delay(500);
  setColor(0,0,255);//Blue  0, 0, 255 #0000FF 

  delay(500);
  setColor(0,255,0);//Green 0, 255, 0 #00FF00 

  delay(1500);
  setColor(255,255,0);//Yellow  255, 255, 0 #FFFF00 

  delay(500);
  setColor(255,127,0);//Orange  255, 127, 0 #FF7F00 

  delay(500);
  setColor(255,0,0);//Red 255, 0 , 0  #FF0000

  delay(500);
  }

  void setColor(int red, int green, int blue){
    analogWrite(redPin, 255-red);
    analogWrite(greenPin, 255-green);
    analogWrite(bluePin, 255-blue);
    }
