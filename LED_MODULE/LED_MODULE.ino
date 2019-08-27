#define LED 2

void setup(){
  pinMode(LED,OUTPUT);
  digitalWrite(LED, HIGH);
  }

void loop(){
  led_on();
  delay_1s();
  led_off();
  delay_1s();
  }

  void led_on(){
    digitalWrite(LED, LOW);
    }

    void led_off(){
      digitalWrite(LED, HIGH);
      }

      void delay_1s(){
        delay(1000);
        }
