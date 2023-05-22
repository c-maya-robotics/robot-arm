#include "Activity_Outputs.h"
#include "Movement_Controls.h"
#include "Arm_Joints.h"

LED activityLight(PIN_PA2);

Button lButton(PIN_PA7, 50, 180);
Button rButton(PIN_PB3, 50, 180);
Button sButton(PIN_PA6, 50, 800);

Dial speedControl(PIN_PB0);

Joint base(PIN_PA4, 90, 1, 200);
Joint shoulder(PIN_PA5, 110, 40, 180);
Joint elbow(PIN_PB2, 30, 1, 200);

byte currentJoint = 0;
Joint armJoints[3] = {base, shoulder, elbow};

byte sharpTurn = 40;

int speedInterval;

void setup()
{
  activityLight.flash(60, 100, 3, 600);
}

void loop()
{
  speedInterval = speedControl.getReading();

  leftButton_Input();
  rightButton_Input();
  selectButton_Input();
}

void leftButton_Input()
{
  switch (lButton.getReading())
  {
    case SINGLE_RELEASED:
      armJoints[currentJoint].intervalMove(LEFT, sharpTurn);
      break;
    case HELD_PRESSED:
      armJoints[currentJoint].intervalMove(LEFT);
      delay(speedInterval);
      break;
    case HELD_RELEASED:
      activityLight.flash();
      break;
  }
}

void rightButton_Input()
{
  switch (rButton.getReading())
  {
    case SINGLE_RELEASED:
      armJoints[currentJoint].intervalMove(RIGHT, sharpTurn);
      break;
    case HELD_PRESSED:
      armJoints[currentJoint].intervalMove(RIGHT);
      delay(speedInterval);
      break;
    case HELD_RELEASED:
      activityLight.flash();
      break;
  }
}

void selectButton_Input()
{
  switch (sButton.getReading())
  {
    case SINGLE_RELEASED:
      if (currentJoint < 2)
        currentJoint++;
      else
        currentJoint = 0;

      activityLight.flash();
      break;

    case HELD_PRESSED:
      armJoints[0].setInitialState();
      armJoints[1].setInitialState();
      armJoints[2].setInitialState();

      currentJoint = 0;

      activityLight.flash(60, 100, 1);

      break;
  }
}
