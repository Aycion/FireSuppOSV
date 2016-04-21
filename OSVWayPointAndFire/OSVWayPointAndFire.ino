#include <SoftwareSerial.h>
#include "Constants.h"
#include "Motor.h"
#include "Location.h"
#include "Navigation.h"
#include "FireSensor.h"

Motor* mleft;
Motor* mright;
Location* location;
Navigator* navigator;
FireSensor* fireL;
FireSensor* fireR;
//Sonic* s;

void setup()
{  
  Serial.begin(9600);
  Serial.println("setup");
  location = new Location();
  //
  fireL = new FireSensor(FIRE_PORT_L);
  fireR = new FireSensor(FIRE_PORT_R);
  
  //s = new Sonic(3,2);
  
  //drive to the oppisite wall  
  
  mright = new Motor(MOTOR_A_PWM,MOTOR_A_DIR);
  mleft = new Motor(MOTOR_B_PWM,MOTOR_B_DIR);
  navigator = new Navigator(location,NULL,NULL,NULL,mleft,mright);
  
  navigator->gotoWaypoint(2900,1700); //Location of first fire site = (2900,1700)
  
  /*navigator->rotateToAngle(0);
  delay(2000);
  navigator->rotateToAngle(PI/2);
  delay(2000);
  navigator->rotateToAngle(PI);
  delay(2000);
  navigator->rotateToAngle(-PI/2);
  delay(2000);
  navigator->rotateToAngle(0);*/
  
}

void loop()
{
  //navigator->gotoWaypoint(3825,1000);
 
 // String s = String(location->getX(),3);
  //String s =  String((int)location->getX()); 
  //location->say(s);
  if (fireR->isFireActive() || fireL->isFireActive())
  {
    location->say("Active Fire Detected");
  }
  delay(500);
  
}
