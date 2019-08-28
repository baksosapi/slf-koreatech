#define VIB_SENSOR A0

void setup(){
  Serial.begin(9600);
  pinMode(VIB_SENSOR, INPUT);
}

void loop(){
  Serial.println(analogRead(VIB_SENSOR));
  delay(100);
}
