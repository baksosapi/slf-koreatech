#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

#define VIB_SENSOR A0
#define TOUCH 1

#define deviceID "baksosD1566959289843"
#define authnRqtNo "bluf60n11"
#define extrSysID "OPEN_TCP_001PTL001_1000007612"

#define WIFI_SSID "ICT-LAB-2.4G" // SSID
#define WIFI_PASS "12345678" //psswd
#define TAG_ID "PIEZO"

IoTMakers g_im;

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

void setup() {
  pinMode(VIB_SENSOR, INPUT);
  Serial.begin(9600);
  init_iotmakers();
}

void loop() {

  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
  }

  int dTouch;
  int aTouch;

  dTouch = digitalRead(VIB_SENSOR);
  aTouch = analogRead(VIB_SENSOR);

  if(dTouch == TOUCH){
    Serial.println("TOUCHED");
    g_im.send_numdata(TAG_ID, (int)aTouch);
  } else {
    g_im.send_numdata(TAG_ID, (int)aTouch);
  }
  delay(100);
  g_im.loop(); 
}
