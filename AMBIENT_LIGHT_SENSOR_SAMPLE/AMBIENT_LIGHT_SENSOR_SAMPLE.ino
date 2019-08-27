#define LIGHT A3
#define LED A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LIGHT, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(LIGHT);
  int data = map(value, 0, 1023, 1023, 0);

  Serial.print("LIGHT: ");
  Serial.println(data);

  analogWrite(LED, value);
  delay(100);
}
