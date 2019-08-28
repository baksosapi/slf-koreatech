#include <Wire.h>
const int MPU = 0x68;
int16_t ac_x, ac_y, ac_z, tmp, gy_x, gy_y, gy_z;

void setup() {
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
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

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
}
