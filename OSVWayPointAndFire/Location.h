#ifndef Location_h
#define Location_h

#include "Arduino.h"
#include "Constants.h"
#include <SoftwareSerial.h>
#include "enes100.h"


class Location
{
	public:
		Location();
		float getX();
		float getY();
		float getAngle();
    void say(String s){
      rf.sendMessage(s);
    };
    void say(double s){
      rf.sendMessage(s);
    };
	private:
		SoftwareSerial sSerial;
		enes100::RfClient<HardwareSerial> rf;
		enes100::Marker marker;		
};
#endif
