#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor
{
	public:
		Motor(int pwm,int dir);
		void setSpeed(int speed,int direction);			
	private:
		int _pwm, _dir;
};

#endif