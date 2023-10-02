#ifndef MultiSensorArray_h
#define MultiSensorArray_h

#include <Arduino.h>
#include <Wire.h>

class MultiSensorArray {
public:
  MultiSensorArray(uint8_t numMultiplexers, uint8_t* muxAddresses);
  void begin();
  int readDistance(uint8_t muxIndex, uint8_t sensorIndex);

private:
  uint8_t numMultiplexers;
  uint8_t* muxAddresses;
};

#endif
