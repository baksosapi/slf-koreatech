#include <OneWire.h>
#include <DallasTemperature.h>

OneWire  ds(2);  // This is where DQ of your DS18B20 will connect.

void getDeviceAddress(void) {
  byte i;
  byte addr[8];
  
  Serial.println("Getting the address...\n\r");
  /* initiate a search for the OneWire object we created and read its value into
  addr array we declared above*/
  
  while(ds.search(addr)) {
    Serial.println ("The address is:\t");
    //read each byte in the address array
    for( i = 0; i < 8; i++) {
      Serial.print("0x");
      if (addr[i] < 16) {
        Serial.print('0');
      }
      // print each byte in the address array in hex format
      Serial.print(addr[i], HEX);
      if (i < 7) {
        Serial.print(", ");
      }
    }
    // a check to make sure that what we read is correct.
    if ( OneWire::crc8( addr, 7) != addr[7]) {
        Serial.print("CRC is not valid!\n");
        return;
    }
  }
  ds.reset_search();
  return;
}


// Port on 2 on your Arduino
OneWire oneWire(2);

// declare as sensor referenec by passing oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// MY ADDRESS
DeviceAddress tempSensor = {0x28, 0x76, 0xF6, 0x42, 0x0B, 0x00, 0x00, 0x28};

// A Variable to hold the temperature you retrieve
float Temp;

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  getDeviceAddress();
  
}

void loop() {

  sensors.setResolution(tempSensor, 9);
  Serial.print("Sensor Resolution : ");
  Serial.print(sensors.getResolution(tempSensor), DEC);
  Serial.println();
  
  sensors.requestTemperaturesByAddress(tempSensor);
  Temp = sensors.getTempC(tempSensor);
  
  Serial.print("Temp C: ");
  Serial.println(Temp, 6);
  delay(500);

  sensors.setResolution(tempSensor, 12);
  Serial.print("Sensor Resolution : ");
  Serial.print(sensors.getResolution(tempSensor), DEC);
  Serial.println();

  sensors.requestTemperaturesByAddress(tempSensor);
  Temp = sensors.getTempC(tempSensor);
  
  Serial.print("Temp in C: ");
  Serial.println(Temp, 6);
  delay(1000);
  Serial.println();
  Serial.println();
}
