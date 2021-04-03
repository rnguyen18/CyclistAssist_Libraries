/*
  LightController.h - Library for controlling lights.
*/

#ifndef LightController_h
#define LightController_h

#include "Arduino.h"

class LightController
{
  public:
    LightController(int headlightPin, int leftPin, int rightPin);
	void Update();
	void UpdateInput(char charIn);
  private:
	int headlight_pin;
	int left_pin;
	int right_pin;
	int blink_start;
    char light;
	bool blinkers;
	bool headlight;
	static const int BLINKER_TIMING = 1000;
};

#endif