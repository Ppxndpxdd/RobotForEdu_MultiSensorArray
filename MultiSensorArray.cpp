#include "MultiSensorArray.h"

MultiSensorArray::MultiSensorArray(uint8_t numMultiplexers, uint8_t* muxAddresses) {
  this->numMultiplexers = numMultiplexers;
  this->muxAddresses = muxAddresses;
}

void MultiSensorArray::begin() {
  Wire.begin();
}

int MultiSensorArray::readDistance(uint8_t muxIndex, uint8_t sensorIndex) {
  if (muxIndex >= this->numMultiplexers) {
    return -1; // Invalid muxIndex
  }

  Wire.beginTransmission(this->muxAddresses[muxIndex]);
  Wire.write(1 << sensorIndex);
  int ans = Wire.endTransmission();
  delay(200);

  if (ans == 0) {
    Wire.beginTransmission(0x40); // I2C address of GP2Y0E03
    Wire.write(0x5E);            // Data address of Distance Value
    ans = Wire.endTransmission();

    if (ans == 0) {
      ans = Wire.requestFrom(0x40, 2);
      byte c[2];
      c[0] = Wire.read(); // Read the 11th to 4th bits of data c [1]
      c[1] = Wire.read(); // Read the 3rd and 0th bits of the data
      ans = ((c[0] * 16 + c[1]) / 16) / 4; // Calculate the distance
    }
  }

  return ans;
}
