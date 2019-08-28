#include <Wire.h>
#include <WiFi.h>
#include <IoTStarterKit_WiFi.h>

#define deviceID "baksosD1566960968605"
#define authnRqtNo "zacq7kz0t"
#define extrSysID "OPEN_TCP_001PTL001_1000007612"

#define WIFI_SSID "ICT-LAB-2.4G" // SSID
#define WIFI_PASS "12345678" //psswd
#define TAG_IDAX "ACX"
#define TAG_IDAY "ACY"
#define TAG_IDAZ "ACZ"
#define TAG_IDGX "GYX"
#define TAG_IDGY "GYY"
#define TAG_IDGZ "GYZ"
#define TAG_IDTM "Temp"

const int MPU = 0x68;
int16_t ac_x, ac_y, ac_z, tmp, gy_x, gy_y, gy_z;

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
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU);
  Wire.write(0x1B);
  Wire.write(0xF8);
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU);
  Wire.write(0x1C);
  Wire.write(0xF8);
  Wire.endTransmission(true);

  init_iotmakers();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

  if(g_im.isServerDisconnected() == 1)
  {
    init_iotmakers();
  }

  ac_x = Wire.read() << 8 | Wire.read();
  ac_y = Wire.read() << 8 | Wire.read();
  ac_z = Wire.read() << 8 | Wire.read();   
  tmp = Wire.read() << 8 | Wire.read();
  gy_x = Wire.read() << 8 | Wire.read();
  gy_y = Wire.read() << 8 | Wire.read();
  gy_z = Wire.read() << 8 | Wire.read();

  int xaxis = (ac_x - 1090);
  int yaxis = (ac_y - 930);
  int zaxis = (ac_z - 1000);

  g_im.send_numdata(TAG_IDAX, (int)xaxis);
  g_im.send_numdata(TAG_IDAY, (int)yaxis);
  g_im.send_numdata(TAG_IDAZ, (int)zaxis);
  g_im.send_numdata(TAG_IDGX, (int)gy_x);
  g_im.send_numdata(TAG_IDGY, (int)gy_y);
  g_im.send_numdata(TAG_IDGZ, (int)gy_z);
  g_im.send_numdata(TAG_IDTM, (int)tmp);

  Serial.print("xaxis : ");
  Serial.print(xaxis);
  Serial.println();
  Serial.print("yaxis : ");
  Serial.print(yaxis);
  Serial.println();
  Serial.print("zaxis : ");
  Serial.print(zaxis);
  Serial.println();
  Serial.print("temp : ");
  Serial.print(tmp);
  Serial.println();
  Serial.print("G Y axis : ");
  Serial.print(gy_y);
  Serial.println();
  Serial.print("G X axis : ");
  Serial.print(gy_x);
  Serial.println();
  Serial.print("G Z axis : ");
  Serial.print(gy_z);
  Serial.println();
  Serial.println();
  delay(1000);
  g_im.loop(); 
}
