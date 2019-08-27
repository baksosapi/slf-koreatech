#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>
#include <OneWire.h>

IoTMakers g_im;
#define deviceID    "baksosD1566884288080"
#define authnRqtNo  "mxyy703il"
#define extrSysID   "OPEN_TCP_001PTL001_1000007612"

#define WIFI_SSID   "ICT-LAB-2.4G"
#define WIFI_PASS   "12345678"

#define LIGHT A3

// Very Important!!!!
// IoTMakers tag stream id must be the same below !!!
#define TAG_ID "LIGHT"

void init_iotmakers(){
  while(1)
  {
    Serial.print(F("Connect to AP..."));
    while(g_im.begin(WIFI_SSID, WIFI_PASS) < 0)
    {
      Serial.println(F("retrying"));
      delay(100);
    }

    Serial.println(F("Success"));

    g_im.init(deviceID, authnRqtNo, extrSysID);
  
    Serial.print(F("Connect to platform..."));
    while(g_im.connect() < 0)
    {
      Serial.println(F("retrying."));
      delay(100);
    }
    Serial.println(F("Success"));
  
    Serial.print(F("Auth..."));
    if(g_im.auth_device() >= 0)
    {
      Serial.println(F("Success..."));
      return;
    }
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(LIGHT, INPUT);
  
  init_iotmakers();
}

void loop() {
  static unsigned long tick = millis();

  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
  }

  if((millis() - tick) > 1000)
  {
    send_ambient_light();
    tick = millis();
  }

  g_im.loop();
}

int send_ambient_light()
{
  // This Scope is package of temperature sensor
  // Raw coding (with register address) look at "5_Temperature_Sensor Project"
  
  // Read ambient light sensor
  int value = analogRead(LIGHT);

  // Map Function : map(value, fromLow, fromHigh, toLow, toHigh)
  // - In programming, you sometimes need to change a range of values.
  //   For example, in Arduino, when you want to output the
  //   potentiometer analog input value (0 ~ 1023) as PWM value (0 ~ 255)
  //   to control the brightness of the LED, you have to adjust the
  //   range of the input value to the output value range.
  //   It is called Mapping.
  // - Parameter 1 [value]    : analog input value
  // - Parameter 2 [fromLow]  : lower bound of current range value
  // - Parameter 3 [fromHigh] : upper bound of the current range value
  // - Parameter 4 [toLow]    : lower bound of target range value
  // - Parameter 5 [toHigh]   : upper bound of the target range value

  // The Ambient light sensor measures low voltage when it is bright
  // and high voltage when it is dark.
  int data = map(value, 0, 1023, 1023, 0);

  Serial.print("LIGHT : ");
  Serial.println(data);
  
  if(g_im.send_numdata(TAG_ID, (double)data) < 0)
  {
    Serial.println(F("fail"));
    return -1;
  }

  return 0;
}
