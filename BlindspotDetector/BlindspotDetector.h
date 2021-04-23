/*
  BlindspotDetector.h - Library for controlling lights.
*/

#ifndef BlindspotDetector_h
#define BlindspotDetector_h

#define SONAR_NUM 2

#include "Arduino.h"
#include "NewPing.h"

class BlindspotDetector
{
  public:
    BlindspotDetector(int trigPinA, int echoPinA, int trigPinB, int echoPinB);
	int Update();
  private:
	int trig_PinA;
	int echo_PinA;
	int trig_PinB;
	int echo_PinB;
    int period;
    int distance[SONAR_NUM];
    int both1;
    int both2;
    int output;
    long duration;
    unsigned long time_now;
    static const int level_1_low = 10;
    static const int level_1_high = 50;
    static const int level_2_high = 130;
    static const int level_3_high = 200;
};

#endif