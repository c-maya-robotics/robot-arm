#ifndef Arm_Joints_h
#define Arm_Joints_h

#include "Arduino.h"
#include <Servo_megaTinyCore.h>

enum
{
  LEFT,
  RIGHT
};

class Joint
{
  private:
    byte _initialAngle;
    byte _upperBoundary;
    byte _lowerBoundary;

    int currentAngle;

    Servo s;

  public:
    Joint(byte servoPin, byte initialAngle, byte lowerBoundary, byte upperBoundary);
    void intervalMove(byte moveDirection, byte angleChange = 1);
    void setInitialState();
};

#endif
