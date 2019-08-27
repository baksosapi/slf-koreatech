#define LIGHT A3
int BUZZER = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LIGHT, INPUT);

  pinMode(BUZZER, OUTPUT)
  ;
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(LIGHT);
  int data = map(value, 0, 1023, 1023, 0);

  Serial.print("LIGHT: ");
  Serial.println(data);

  if(data < 420){
    tone(BUZZER, 400);
    delay(1000);
  } else {
    noTone(BUZZER);
    delay(1000);  
  }
  delay(100);
}
