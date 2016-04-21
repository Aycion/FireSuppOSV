#include "Motor.h"

Motor::Motor(int pwm,int dir)
{
	pinMode(pwm, OUTPUT);
	pinMode(dir, OUTPUT);
	_pwm = pwm;
	_dir = dir;
}

void Motor::setSpeed(int speed, int direction)
{	
	analogWrite(_pwm,speed);
	digitalWrite(_dir,direction);
}