/*
  LightController.h - Library for controlling lights.
*/

#ifndef LightController_h
#define LightController_h

#include "Arduino.h"

class BrakeLightController
{
  public:
    BrakeLightController(int sensorPin, int outputPin);
	void Update();
  private:
};

#endif