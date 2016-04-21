#ifndef FireSensor_h
#define FireSensor_h
#include "Constants.h"

#include "Arduino.h"

class FireSensor {
	public:
		FireSensor(int analogPort);
		bool isFireActive();
		int getRawOutput();
	private:
		const int ANALOG_PORT;
	
};
#endif
