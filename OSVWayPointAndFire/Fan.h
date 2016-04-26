#ifndef Fan_h
#define Fan_h
#include "Constants.h"

class Fan {
  public:
    Fan(int digitalPort);
    void turnFanOn();
    void turnFanOff();
    void cycleFan();
  private:
    int _digitalPort;

};


#endif
