#define VIB_SENSOR A0
#define TOUCH 1
void setup(){
  Serial.begin(9600);
  pinMode(VIB_SENSOR, INPUT);
}

void loop(){
  int isTouch = digitalRead(VIB_SENSOR);
  if(isTouch == TOUCH){
    Serial.println("TOUCH");
  Serial.println(analogRead(VIB_SENSOR));
    }
  delay(100);
}
