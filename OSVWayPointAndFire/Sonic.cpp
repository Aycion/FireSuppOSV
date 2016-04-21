#include "Sonic.h"

Sonic::Sonic(int echoPin, int trigPin):
	ECHO_PIN(echoPin),
	TRIG_PIN(trigPin)
{
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
}

long Sonic::getDistance()
{
	long duration, distance;
	
	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);
	duration = pulseIn(ECHO_PIN, HIGH);
	distance = (duration/2) / 29.1;
	return distance;
}
