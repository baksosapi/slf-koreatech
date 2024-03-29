int fnd_pin[8] = {2, 3, 4, 5, A2, A3, A4, A5};
int fnd_digits[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},   // 0
  {0, 1, 1, 0, 0, 0, 0, 0},   // 1
  {1, 1, 0, 1, 1, 0, 1, 0},   // 2
  {1, 1, 1, 1, 0, 0, 1, 0},   // 3
  {0, 1, 1, 0, 0, 1, 1, 0},   // 4
  {1, 0, 1, 1, 0, 1, 1, 0},   // 5
  {1, 0, 1, 1, 1, 1, 1, 0},   // 6
  {1, 1, 1, 0, 0, 0, 0, 0},   // 7
  {1, 1, 1, 1, 1, 1, 1, 0},   // 8
  {1, 1, 1, 1, 0, 1, 1, 0}    // 9
};

void setup() {
  for(int i = 0 ; i < 8 ; i++)
  {
    pinMode(fnd_pin[i], OUTPUT);
  }
}

void loop() {
  // Display 0 to 9
  for(int i = 0 ; i < 10 ; i++)
  {
    display(i);
    delay(1000);
  }
}

void display(int num)
{
  if(num < 0) num = 0;
  else if(num >= 10) num = 9;

  for(int i = 0 ; i < 8 ; i++)
  {
    digitalWrite(fnd_pin[i], fnd_digits[num][i]);
  }
}
