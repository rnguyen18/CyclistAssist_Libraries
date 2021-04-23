/*
  LightController.h - Library for controlling lights.
*/

#ifndef SpeedometerController_h
#define SpeedometerController_h

#include "Arduino.h"

class SpeedometerController
{
  public:
    SpeedometerController(int sensorPin);
	int Update();
  private:
	int sensor_pin;
	unsigned long time;
	int on;
	static const int SEND_TIMING = 500;
	unsigned long start_revolution;
	int period;
};

#endif