#ifndef Navigation_h
#define Navigation_h

#include "Arduino.h"
#include "Location.h"
#include "Motor.h"
#include "Sonic.h"



class Navigator
{
	public:
		Navigator(Location* location, Sonic *sleft, Sonic *smiddle, Sonic *sright, Motor *leftm, Motor *rightm);
		void navBoulders();
		void gotoWaypoint(float x, float y);
		void rotateToAngle(float angle);
    void backUp(int timeToMove);
    static float getAngle(float x1, float y1, float x2, float y2);
	private:		
		Location* location;
		const float K = CORRECTING_CONSTANT;
		const float T = DELTA_TIME;
		Motor *_leftm,*_rightm;
		Sonic *_sleft, *_smiddle, *_sright;		
};

#endif
