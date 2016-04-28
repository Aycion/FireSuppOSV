#include "Fan.h"

Fan::Fan(int pin)
{
  pinMode(pin, OUTPUT);
  _digitalPort = pin;
}

void Fan::turnFanOn()
{
  digitalWrite(_digitalPort, HIGH);
}

void Fan::turnFanOff()
{
  digitalWrite(_digitalPort, LOW);
}

void Fan::cycleFan()
{
  turnFanOn();
  delay(1000);
  turnFanOff();
}

