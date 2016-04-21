#include "Arduino.h"
#include "Location.h"

Location::Location():
	//Construct the SoftwearSerial Object and enes100 object
	sSerial(RX_PIN,TX_PIN),
	rf(&Serial)
{    
	sSerial.begin(9600);
	delay(500);
	rf.resetServer();
	rf.sendMessage(TEAM_CONNECT_MESSAGE);

}

float Location::getX()
{	
	if(rf.receiveMarker(&marker,MARKER_NUMBER)) 
	{
		return marker.x;
	}
	else 
	{		
		return -1;
	}
        
}

float Location::getY()
{
	if(rf.receiveMarker(&marker,MARKER_NUMBER)) 
	{
		return marker.y;
	}
	else 
	{
		return -1;
	}
        
}

float Location::getAngle()
{
	if(rf.receiveMarker(&marker,MARKER_NUMBER)) 
	{
		return marker.theta;
	}
	else 
	{
		return -1;
	}
        
}
