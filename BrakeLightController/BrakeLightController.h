/*
  LightController.h - Library for controlling lights.
*/

#ifndef GrakeLightController_h
#define BrakeLightController_h

#include "Arduino.h"

class BrakeLightController
{
  public:
    BrakeLightController(int sensorPin, int outputPin);
	void Update();
  private:
	int sensor_pin;
	int output_pin;
};

#endif