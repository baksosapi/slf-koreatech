#define LED 2
#define SWITCH 3
boolean isLedOn = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SWITCH), interrupt, CHANGE);
  digitalWrite(LED, LOW);
}

void loop() {
   digitalWrite(LED, !isLedOn);
}

void interrupt()   // interrupt handler
{
  // State transition
  isLedOn = !isLedOn;
}
