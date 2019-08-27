#define LED 2
#define SWITCH 3

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SWITCH), interrupt, CHANGE);
  digitalWrite(LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(SWITCH)==0)
    digitalWrite(LED, HIGH);
  else 
    digitalWrite(LED, LOW);
}

void interrupt()   // interrupt handler
{
  // State transition
  isLedOn = !isLedOn;
}
