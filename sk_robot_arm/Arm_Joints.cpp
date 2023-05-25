// Functions for the arm joint movement

#include "Arm_Joints.h"

//Initialise joint object
Joint::Joint(byte servoPin, byte initialAngle, byte lowerBoundary, byte upperBoundary)
{
  s.attach(servoPin);
  s.write(initialAngle);

  currentAngle = initialAngle;

  _initialAngle = initialAngle;
  _upperBoundary = upperBoundary;
  _lowerBoundary = lowerBoundary;
}

// Rotate the servo
//  moveDirection   The direction the servo should move in, left or right
//  angleChange     The size of the steps it should make in one move interval
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

// Return the servo to its initial position
void Joint::setInitialState()
{
  currentAngle = _initialAngle;

  s.write(currentAngle);
}
