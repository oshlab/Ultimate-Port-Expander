#ifndef ULTIMATE_PORT_EXPANDER_H
#define ULTIMATE_PORT_EXPANDER_H
     
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <Wire.h>

#include "UPE_codes.h"

class UPE {
  public:
    UPE(uint8_t addr);
    ~UPE();
    void digitalWrite(uint8_t pin,uint8_t val);
    int16_t digitalRead(uint8_t pin);
    int16_t digitalReadPullup(uint8_t pin);
    void analogWrite(uint8_t pin,uint8_t val);
    int16_t analogRead(uint8_t pin);
    void sendDataPacket(uint8_t dataPacket[], uint8_t size);
    void setIntPin(uint8_t pin);
    int16_t receiveResponse();
	
  private:
    uint8_t _addr;
};

#endif