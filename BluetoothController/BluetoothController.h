/*
  BluetoothController.h - Library for controlling lights.
*/

#ifndef BluetoothController_h
#define BluetoothController_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class BluetoothController
{
  public:
    BluetoothController(int rxPin,int txPin);
    void Write(char char_output);
    char Read();
  private:
    int rx_pin;
    int tx_pin;
    SoftwareSerial mySerial;
};

#endif