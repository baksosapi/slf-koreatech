int BUZZER = 6;

void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
    
  tone(BUZZER, 400);
  delay(1000);

  // - Piezo Buzzer Off
  Serial.println("OFF");
  noTone(BUZZER);
  delay(1000);
}
