// Header file for the movement controls

#ifndef Movement_Controls_h
#define Movement_Controls_h

#include "Arduino.h"

enum
{
  IDLE_STATE,
  SINGLE_PRESSED,
  SINGLE_RELEASED,
  HELD_PRESSED,
  HELD_RELEASED
};

class Button
{
  private:
    byte _buttonPin;
    byte _debounceTime;
    unsigned long _holdTime;

    byte lastState;
    bool buttonDown;
    bool buttonHeld;

    unsigned long previousMillis;
    unsigned long timeDifference;

  public:
    Button(byte buttonPin, byte debounceTime, unsigned long holdTime = 0);
    byte getReading();
};

class Dial
{
  private:
    byte _dialPin;
  public:
    Dial(byte dialPin);
    int getReading();
};

#endif
