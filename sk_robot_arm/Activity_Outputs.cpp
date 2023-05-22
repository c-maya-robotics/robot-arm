#include "Activity_Outputs.h"

LED::LED(byte ledPin)
{
  _ledPin = ledPin;

  pinMode(_ledPin, OUTPUT);
}

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
