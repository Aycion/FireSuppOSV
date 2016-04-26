#include <SoftwareSerial.h>
#include "Constants.h"
#include "Motor.h"
#include "Location.h"
#include "Navigation.h"
#include "FireSensor.h"
#include "Fan.h"

Motor* mleft;
Motor* mright;
Location* location;
Navigator* navigator;
FireSensor* fireL;
FireSensor* fireR;
Fan* fan;
//Sonic* s;

void setup()
{  
  Serial.begin(9600);
  Serial.println("setup");
  location = new Location();
  //
  fireL = new FireSensor(FIRE_PORT_L);
  fireR = new FireSensor(FIRE_PORT_R);
  fan = new Fan(FAN_PORT);
  //s = new Sonic(3,2);
  
  //drive to the oppisite wall  
  
  mright = new Motor(MOTOR_A_PWM,MOTOR_A_DIR);
  mleft = new Motor(MOTOR_B_PWM,MOTOR_B_DIR);
  navigator = new Navigator(location,NULL,NULL,NULL,mleft,mright);

  /*
   * The next two methods tell the OSV to navigate to a location roughly 30 centimeters in the negative x direction
   * from fire site A, and then rotate to face the fire site.
   */
  navigator->gotoWaypoint(2.600,1.700); //Location of first fire site = (2.900,1.700).
  navigator->rotateToAngle(0); //OSV should be directly to the left of the fire site, so rotates to face the positive x direction.
  
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
    delay(2000);
    fan->cycleFan();
  }
  delay(500);
  
}
