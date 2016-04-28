#include "FireSensor.h"

FireSensor::FireSensor(int pin):
  ANALOG_PORT(pin)
{
  //nothing
}

bool FireSensor::isFireActive()
{
  int output = analogRead(ANALOG_PORT);
  return (output > FIRE_THRESHOLD);
}

int FireSensor::getRawOutput()
{
  return analogRead(ANALOG_PORT);

}
