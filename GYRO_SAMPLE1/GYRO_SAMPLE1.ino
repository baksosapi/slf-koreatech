#define VIB_SENSOR A0
#define TOUCH 1

#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

IoTMakers g_im;

#define deviceID    "baksosD1566959289843"
#define authnRqtNo  "bluf60n11"
#define extrSysID   "OPEN_TCP_001PTL001_1000007612"

#define WIFI_SSID   "ICT-LAB-2.4G"
#define WIFI_PASS   "12345678"


#define TAG_ID "PIEZO"

void init_iotmakers()
{
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

void setup(){
  Serial.begin(9600);
  pinMode(VIB_SENSOR, INPUT);
}

void loop(){

  static unsigned long tick = millis();

  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
  }

    send_touch();

  g_im.loop();
}

int send_touch(){

    int isTouch = digitalRead(VIB_SENSOR);
    int data;
  if(isTouch == TOUCH){
    Serial.println("TOUCH");
    int data = analogRead(VIB_SENSOR);
    Serial.println(data);
    }
  
  delay(100);

  
  if(g_im.send_numdata(TAG_ID, (double)data) < 0)
  {
    Serial.println(F("fail"));
    return -1;
  }

  return 0;
  }
