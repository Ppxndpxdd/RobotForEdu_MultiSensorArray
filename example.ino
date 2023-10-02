#include <Wire.h>
#include <MultiSensorArray.h>

// Define the I2C addresses of your multiplexers
uint8_t muxAddresses[] = {0x70}; // Example address for 1 multiplexer

MultiSensorArray sensorArray(1, muxAddresses); // 1 multiplexer

void setup() {
  Serial.begin(9600);
  sensorArray.begin();
}

void loop() {
  int distance1 = sensorArray.readDistance(0, 0); // Read sensor 0 on multiplexer 0
  int distance2 = sensorArray.readDistance(0, 1); // Read sensor 1 on multiplexer 0

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  delay(1000); // Delay between readings
}
