#include "Arm_Joints.h"

Joint::Joint(byte servoPin, byte initialAngle, byte lowerBoundary, byte upperBoundary)
{
  s.attach(servoPin);
  s.write(initialAngle);

  currentAngle = initialAngle;

  _initialAngle = initialAngle;
  _upperBoundary = upperBoundary;
  _lowerBoundary = lowerBoundary;
}

void Joint::intervalMove(byte moveDirection, byte angleChange)
{
  if (moveDirection == LEFT)
    currentAngle += angleChange;
  if (moveDirection == RIGHT)
    currentAngle -= angleChange;

  if (currentAngle > _upperBoundary)
    currentAngle = _upperBoundary;
  if (currentAngle < _lowerBoundary)
    currentAngle = _lowerBoundary;

  s.write(currentAngle);
}

void Joint::setInitialState()
{
  currentAngle = _initialAngle;

  s.write(currentAngle);
}
