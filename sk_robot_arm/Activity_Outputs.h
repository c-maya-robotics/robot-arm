#ifndef Activity_Outputs_h
#define Activity_Outputs_h

#include "Arduino.h"

class LED
{
  private:
    byte _ledPin;
  public:
    LED(byte ledPin);
    void flash(int onTime = 60, int offTime = 0, byte amount = 1, int preDelay = 0, int postDelay = 0);
};

#endif
