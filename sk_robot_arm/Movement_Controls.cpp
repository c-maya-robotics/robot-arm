#include "Movement_Controls.h"

Button::Button(byte buttonPin, byte debounceTime, unsigned long holdTime)
{
  _buttonPin = buttonPin;
  _debounceTime = debounceTime;
  _holdTime = holdTime;

  pinMode(_buttonPin, INPUT);
}

byte Button::getReading()
{
  unsigned long currentMillis = millis();

  byte pinReading = digitalRead(_buttonPin);
  byte readResult = IDLE_STATE;

  if (pinReading != lastState)
  {
    previousMillis = currentMillis;
  }

  if (pinReading == HIGH)
  {
    timeDifference = currentMillis - previousMillis;

    if (buttonDown == false && timeDifference >= _debounceTime)
    {
      buttonDown = true;
      readResult = SINGLE_PRESSED;
    }

    if (_holdTime > 0 && timeDifference >= _holdTime)
    {
      buttonHeld = true;
      readResult = HELD_PRESSED;
    }
  }
  else
  {
    if (buttonDown == true)
    {
      buttonDown = false;
      readResult = SINGLE_RELEASED;
    }

    if (buttonHeld == true)
    {
      buttonHeld = false;
      readResult = HELD_RELEASED;
    }
  }

  lastState = pinReading;

  return readResult;
}

Dial::Dial(byte dialPin)
{
  _dialPin = dialPin;
}

int Dial::getReading()
{
  int reading = analogRead(_dialPin);
  return map(reading, 0, 1023, 4, 40);
}
