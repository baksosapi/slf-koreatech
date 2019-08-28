#include <SoftwareSerial.h>
 
//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and Bluetooth module
//  Arduino      Bluetooth module
//    5V       -        VCC
//    GND      -        GND
//     2       -         Tx
//     3       -        Rx
//******************************************************//
int blueTx=2;
int blueRx=3;
SoftwareSerial bluetooth(blueTx, blueRx);
 
void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  // HANDLE BT AT COMMAND
  if (bluetooth.available()) {    
    Serial.write(bluetooth.read());  
  }
  if (Serial.available()) {
    delay(5);         
    bluetooth.write(Serial.read());  
  }
}
