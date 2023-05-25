// Functions for the indicator outputs

#include "Activity_Outputs.h"

//Initialise LED object
LED::LED(byte ledPin)
{
  _ledPin = ledPin;

  pinMode(_ledPin, OUTPUT);
}

// Flash the LED
//  onTime      The time the LED should be on for
//  offTime     The time the LED should be off for
//  amount      The number of times the LED should flash
//  preDelay    The time to wait before the flash begins
//  postDelay   The time to wait after the process has completed
void LED::flash(int onTime, int offTime, byte amount, int preDelay, int postDelay)
{
  delay(preDelay);

  for (byte i = 0; i < amount; i++)
  {
    digitalWrite(_ledPin, HIGH);
    delay(onTime);

    digitalWrite(_ledPin, LOW);
    delay(offTime);
  }

  delay(postDelay);
}
