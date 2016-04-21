#ifndef Sonic_h
#define Sonic_h

#include "Arduino.h"
#include "Constants.h"

class Sonic {
	public:
		Sonic(int echoPin, int trigPin);
		long getDistance();
	private:
		const int ECHO_PIN;
		const int TRIG_PIN;
};
#endif