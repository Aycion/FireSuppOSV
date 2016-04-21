#ifndef Constants_h
#define Constants_h
#include "Arduino.h"
#define TEAM_CONNECT_MESSAGE "Team It was Lit before We got there Connected!"
#define TX_PIN 1
#define RX_PIN 0
#define MARKER_NUMBER 107
#define FIRE_THRESHOLD 100
#define MOTOR_A_PWM 5
#define MOTOR_B_PWM 6
#define MOTOR_A_DIR 4
#define MOTOR_B_DIR 7
#define CORRECTING_CONSTANT 150
#define ERROR_RANGE .075f 
#define DELTA_TIME 0.25
#define WHEEL_RADIUS 5.5
#define WIDTH  30
//#define PI 3.1416
#define MOTOR_MAX_SPEED PI
#define TIMEOUT_COUNT 20.0/DELTA_TIME
#define DISTANCE_RANGE 40
#define FIRE_PORT_L 0
#define FIRE_PORT_R 1



#endif
