#include <SoftwareSerial.h>
 
//******************************************************//
// Hardware Configuration
//  - Connect IoT Starter Kit and Bluetooth module
//  Arduino      Bluetooth module
//    5V       -        VCC
//    GND      -        GND
//     2       -        Rx
//     3       -        Tx
//******************************************************//
int blueRx=0;
int blueTx=1;
SoftwareSerial bluetooth(blueTx, blueRx);
String str;

void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);

//  pinMode(13, OUTPUT);
}

void loop()
{
//   HANDLE BT AT COMMAND
  if (bluetooth.available()) {    
    Serial.write(bluetooth.read());
  }
  if (Serial.available()) {
    delay(5);         
    bluetooth.write(Serial.read());  
  }
//  while(bluetooth.available()){
//    char aChar = bluetooth.read();
//    str += aChar;
//    delay(5);
//  }
//
//  if(!str.equals("")){
//    Serial.println("Received : "+str);
//    str = ""; // clear
//  }
}
