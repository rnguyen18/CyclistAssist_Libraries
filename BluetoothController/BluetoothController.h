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
	void WriteString(String string_output);
    void Write(char char_output);
    char Read();
	void Update();
  private:
    int rx_pin;
    int tx_pin;
    SoftwareSerial mySerial;
	String buffer;
	char send_byte[2];
};

#endif