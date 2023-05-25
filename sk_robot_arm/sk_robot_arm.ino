// The main program for my robot arm

#include "Activity_Outputs.h"       // Indicators, like LEDs and buzzers
#include "Movement_Controls.h"      // Handles the button and pot inputs
#include "Arm_Joints.h"             // Controls the servos on the arm

// Onboard activity LED
LED activityLight(PIN_PA2);

// Three input buttons
Button lButton(PIN_PA7, 50, 180);   // Rotate servo left
Button rButton(PIN_PB3, 50, 180);   // Rotate servo right
Button sButton(PIN_PA6, 50, 800);   // Go to the next servo

// Speed control potentiometer
Dial speedControl(PIN_PB0);

// The servo joints on the arm
Joint base(PIN_PA4, 90, 1, 200);
Joint shoulder(PIN_PA5, 110, 40, 180);
Joint elbow(PIN_PB2, 30, 1, 200);

// The joints above stored in an array
Joint armJoints[3] = {base, shoulder, elbow};
byte currentJoint = 0;

// The amount of steps for one sharp rotation
byte sharpTurn = 40;

// The value that determines movement speed
int speedInterval;

void setup()
{
  // Flash the activity LED to let the user know the program has begun
  activityLight.flash(60, 100, 3, 600);
}

void loop()
{
  // Set the speed interval according to the potentiometer value
  speedInterval = speedControl.getReading();

  // Functions to handle the button inputs
  leftButton_Input();
  rightButton_Input();
  selectButton_Input();
}

void leftButton_Input()
{
  // Get a reading from the button
  //    On release, perform a left turn according to the sharp turn value
  //    When being held, gradually turn to the left according to the speed dial value
  //    When no longer being held, flash the activity LED
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
  // Get a reading from the button
  //    On release, perform a right turn according to the sharp turn value
  //    When being held, gradually turn to the right according to the speed dial value
  //    When no longer being held, flash the activity LED
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
  // Get a reading from the button
  //    On release, iterate the joint array selector value and flash the activity LED
  //    When being held, return the servos to their startup states
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
