#define BUZZER 6
#define SIGNAL_PIN A0
int distance = 0;

void setup(){
  Serial.begin(9600);

    pinMode(SIGNAL_PIN, INPUT);
    pinMode(BUZZER, OUTPUT);
}


void loop(){
  int volt = map(analogRead(SIGNAL_PIN), 0, 1023, 0, 5000);
  distance = (21.61/ (volt-0.166)) * 1000;

  if(distance <= 100){
    tone(BUZZER, 600);
    delay(distance * 5);
    noTone(BUZZER);
    delay(distance * 5);
  }else{
    delay(500);
    }
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);

}
