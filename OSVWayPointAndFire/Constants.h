#ifndef Constants_h
#define Constants_h
#include "Arduino.h"

//Set Constants
#define CORRECTING_CONSTANT 350
#define DELTA_TIME 0.25
#define WHEEL_RADIUS 5.5
#define WIDTH  30
#define MOTOR_MAX_SPEED PI
#define MARKER_NUMBER 111
#define TEAM_CONNECT_MESSAGE "Team It was Lit before We got there Connected!"

//Error Margins
#define FIRE_THRESHOLD 100
#define EPSILON .002
#define DISTANCE_RANGE 0.1
#define ERROR_RANGE .075f 
#define TIMEOUT_COUNT 2.0/DELTA_TIME
#define TIMEOUT_ANGLE .2 //about 10 degrees

//Digital Port Definitions
#define TX_PIN 1
#define RX_PIN 0
#define FAN_PORT 2
/*Motors*/
#define MOTOR_A_PWM 5
#define MOTOR_B_PWM 6
#define MOTOR_A_DIR 4
#define MOTOR_B_DIR 7
/*Sonic Sensors*/
#define SONIC_SENSOR_ECHO_L 8
#define SONIC_SENSOR_TRIG_L 9
#define SONIC_SENSOR_ECHO_M 10
#define SONIC_SENSOR_TRIG_M 11
#define SONIC_SENSOR_ECHO_R 12
#define SONIC_SENSOR_TRIG_R 13

//Analog Port Definitions
#define FIRE_PORT_L 0
#define FIRE_PORT_R 1

#endif
