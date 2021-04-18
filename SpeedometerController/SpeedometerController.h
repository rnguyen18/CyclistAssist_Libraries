/*
  LightController.h - Library for controlling lights.
*/

#ifndef SpeedometerController_h
#define SpeedometerController_h

#include "Arduino.h"

class SpeedometerController
{
  public:
    SpeedometerController(int sensorPin, int outputPin);
	void Update();
  private:
	bool on;
	static const int SEND_TIMING = 1000;
	int rotations;
};

#endif