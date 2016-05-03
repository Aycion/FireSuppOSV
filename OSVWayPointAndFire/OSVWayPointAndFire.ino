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
Sonic* sonic1;
Sonic* sonic2;
Sonic* sonic3;
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

  mright = new Motor(MOTOR_A_PWM, MOTOR_A_DIR);
  mleft = new Motor(MOTOR_B_PWM, MOTOR_B_DIR);
  sonic1 = new Sonic(SONIC_SENSOR_ECHO_L, SONIC_SENSOR_ECHO_L);
  sonic2 = new Sonic(SONIC_SENSOR_ECHO_M, SONIC_SENSOR_ECHO_M);
  sonic3 = new Sonic(SONIC_SENSOR_ECHO_R, SONIC_SENSOR_ECHO_R);
  navigator = new Navigator(location, sonic1, sonic2, sonic3, mleft, mright);
  
  /*
     The next two methods tell the OSV to navigate to a location roughly 30 centimeters in the negative x direction
     from fire site A, and then rotate to face the fire site.
  */

  //Get Past Boulders
  location->say("Navigating boulders\n");
  navigator->navBoulders();
  location->say("Done navigating boulders\n");
  //navigator->gotoWaypoint(0.500, 1.000);
  //navigator->gotoWaypoint(1.200, 1.000);
  //navigator->gotoWaypoint(1.700, 1.000);

  //Fire Site 1

  //navigator->gotoWaypoint(1.700, 1.650);
  navigator->gotoWaypoint(2.550, 1.650); //Location of first fire site = (2.900,1.700).

  navigator->rotateToAngle(Navigator::getAngle(location->getX(), location->getY(), 2.900, 1.700)); //OSV should be directly to the left of the fire site, so rotates to face the positive x direction.
  searchForFire();

  //Fire Site 2
  navigator->backUp(500);
  navigator->gotoWaypoint(2.550, 0.900);
  navigator->gotoWaypoint(3.350, 0.900);
  navigator->rotateToAngle(Navigator::getAngle(location->getX(), location->getY(), 3.700, 0.900));
  searchForFire();

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

}

void searchForFire()
{
  /* location->say("Checking Fire Site \n");
    if(fireR->isFireActive() || fireL->isFireActive()){
    location->say("Fire is active");
    while(fireR->isFireActive() || fireL->isFireActive()){
      fan->cycleFan();
    }
    location->say("Fire Extinguished");
    }
  */
  bool fireActive;
  do {
    location->say("Looking for active flame...\n");
    delay(2000);
    fireActive = (fireR->isFireActive() || fireL->isFireActive());
    delay(2000);
    fireActive = (fireR->isFireActive() || fireL->isFireActive());
    
    if (fireActive)
    {
      location->say("Active Fire Detected");

      delay(500);
      fan->cycleFan();
      delay(1000);
      fireActive = (fireR->isFireActive() || fireL->isFireActive());
      if (!fireActive)
      {
        location->say("Fire Extinguished\n");
      }
    } else
    {
      location->say("No active fire detected\n");
    }
  } while (fireActive);

  delay(500);
}

