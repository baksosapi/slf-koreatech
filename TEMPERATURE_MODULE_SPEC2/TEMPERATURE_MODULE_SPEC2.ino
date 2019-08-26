#include <OneWire.h>
OneWire ds(2);
int timeInMilis = 3000;
unsigned long time = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  byte i;
  byte present = 0;

  byte data[12];
  byte addr[8];
  float Suhu;

  if(!ds.search(addr)){
    ds.reset_search();
    return;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);
  
  // Sampling Speed
  //delay(1000);
  time = millis();
  while(millis() < time + timeInMilis)

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad

  for (i=0; i<9; i++){
    data[i] = ds.read();
    }

  Suhu = (data[1]<<8)+data[0];
  Suhu=Suhu/16;

  // Celcius
  Serial.print("Temperature C=");
  Serial.print(Suhu);
  Serial.println(" ");
}
