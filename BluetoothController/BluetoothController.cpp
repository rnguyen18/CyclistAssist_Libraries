#include "Arduino.h"
#include "BluetoothController.h"
#include "SoftwareSerial.h"

BluetoothController::BluetoothController(int rxPin,int txPin) : mySerial(SoftwareSerial(rxPin, txPin)) {
	rx_pin = rxPin;
	tx_pin = txPin;
	mySerial.begin(9600);
}


void BluetoothController::Write(char char_output) {
    mySerial.write(char_output);
}

char BluetoothController::Read() {
    char char_input = mySerial.read();
    return char_input;
}