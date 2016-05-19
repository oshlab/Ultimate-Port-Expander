#include "Ultimate_Port_Expander.h"

//<<constructor>>
UPE::UPE(uint8_t addr){
  _addr = addr;
  //Wire.begin();
}

//<<destructor>>
UPE::~UPE(){/*nothing to destruct*/}

void UPE::digitalWrite(byte pin,byte val){
  uint8_t dataPacket[3];	
  dataPacket[0] = DIGITAL_WRITE;    // method
  dataPacket[1] = pin;  // pin
  dataPacket[2] = val;  // val
  sendDataPacket(dataPacket,3);
  int received = receiveResponse();
}

int UPE::digitalRead(byte pin){
  uint8_t dataPacket[2];
  dataPacket[0] = DIGITAL_READ;    // method
  dataPacket[1] = pin;  // pin
  sendDataPacket(dataPacket,2);
  int received = receiveResponse();
  return received;
}

int UPE::digitalReadPullup(byte pin){
  uint8_t dataPacket[2];
  dataPacket[0] = DIGITAL_READ_PULLUP;    // method
  dataPacket[1] = pin;  // pin
  sendDataPacket(dataPacket,2);
  int received = receiveResponse();
  return received;
}

void UPE::analogWrite(byte pin,byte val){
  uint8_t dataPacket[3];
  dataPacket[0] = ANALOG_WRITE;    // method
  dataPacket[1] = pin;  // pin
  dataPacket[2] = val;  // val
  sendDataPacket(dataPacket,3);
  int received = receiveResponse();
}

int UPE::analogRead(byte pin){
  uint8_t dataPacket[2];
  dataPacket[0] = ANALOG_READ;    // method
  dataPacket[1] = pin;  // pin
  sendDataPacket(dataPacket, 2);
  int received = receiveResponse();
  return received;
}

void UPE::sendDataPacket(uint8_t dataPacket[], uint8_t size){
  Wire.beginTransmission(_addr);
  Wire.write(dataPacket, size);
  Wire.endTransmission(true);
  // delay(1);
}

int UPE::receiveResponse(){
  unsigned int receivedValue;
  int available = Wire.requestFrom(_addr, (byte)1);
  byte buffer[2];
  if(available == 1)
  {
     buffer[0] = Wire.read();
  }
  available = Wire.requestFrom(_addr, (byte)1);
  if(available == 1)
  {
     buffer[1] = Wire.read();
  }
  receivedValue = buffer[0] << 8 | buffer[1];
  
  return receivedValue;  
}