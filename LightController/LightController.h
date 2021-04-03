/*
  LightController.h - Library for controlling lights.
*/

#ifndef LightController_h
#define LightController_h

#include "Arduino.h"

class LightController
{
  public:
    LightController(int frontPin,int backPin,int leftPin,int rightPin);
	void Update();
	void UpdateInput(char charIn);
  private:
	int front_pin;
	int rear_pin;
	int left_pin;
	int right_pin;
	bool on;
    char light;
	bool blink;
	int blink_start;
	static const int BLINKER_TIMING = 1000;
};

#endif