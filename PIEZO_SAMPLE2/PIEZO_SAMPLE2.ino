#define VIB_SENSOR A0
#define TOUCH 1
void setup(){
  Serial.begin(9600);
  pinMode(VIB_SENSOR, INPUT);
}

void loop(){
//  Serial.println(analogRead(VIB_SENSOR));
  int isTouch = digitalRead(VIB_SENSOR);
  if(isTouch == TOUCH){
    Serial.println("TOUCH");
    }
  delay(100);
}
