#include "FireSensor.h"

FireSensor::FireSensor(int pin):
	ANALOG_PORT(pin)
{
	//nothing
}

bool FireSensor::isFireActive()
{
	int output = analogRead(ANALOG_PORT);
	if (output > FIRE_THRESHOLD)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

int FireSensor::getRawOutput()
{
	return analogRead(ANALOG_PORT);
	
}
