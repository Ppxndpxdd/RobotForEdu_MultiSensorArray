# MultiSensorArray Library Documentation

The MultiSensorArray library allows you to interface with multiple sensors on multiple I2C multiplexers with ease. This documentation will guide you through the installation and usage of the library.

## Table of Contents

1. [Installation](#installation)
2. [Usage](#usage)
   - [Initialize the Library](#initialize-the-library)
   - [Reading Sensor Data](#reading-sensor-data)
3. [Examples](#examples)
   - [Example 1: Use with 2 Sensors and 1 Multiplexer](#example-1-use-with-2-sensors-and-1-multiplexer)
   - [Example 2: Use with 4 Sensors and 2 Multiplexers](#example-2-use-with-4-sensors-and-2-multiplexers)
4. [Advanced Usage](#advanced-usage)
   - [Using Multiple Multiplexers](#using-multiple-multiplexers)
5. [Library Reference](#library-reference)
6. [Troubleshooting](#troubleshooting)
7. [License](#license)

## Installation

1. Download the "MultiSensorArray" library ZIP file from the [GitHub repository](https://github.com/yourusername/multisensorarray).

2. Open the Arduino IDE.

3. Click on "Sketch" -> "Include Library" -> "Add .ZIP Library."

4. Browse to the location where you saved the ZIP file, select it, and click "Open."

5. The library is now installed.

## Usage

### Initialize the Library

Before you can use the MultiSensorArray library, you need to initialize it and specify the I2C addresses of your multiplexers.

```cpp
#include <Wire.h>
#include <MultiSensorArray.h>

// Define the I2C addresses of your multiplexers
uint8_t muxAddresses[] = {0x70}; // Addresses for 1 multiplexer

MultiSensorArray sensorArray(1, muxAddresses); // 1 multiplexer

void setup() {
  Serial.begin(9600);
  sensorArray.begin();
}
```
## Reading Sensor Data
You can read data from your sensors using the readDistance method. For example, to read data from sensor 0 on multiplexer 0:
```cpp
int distance = sensorArray.readDistance(0, 0);
```

## Examples
Example 1: Use with 2 Sensors and 1 Multiplexer
To use the library with 2 sensors and 1 multiplexer, follow these steps:
```cpp
// Define the I2C addresses of your multiplexers
uint8_t muxAddresses[] = {0x70}; // Addresses for 1 multiplexer

MultiSensorArray sensorArray(1, muxAddresses); // 1 multiplexer

void setup() {
  Serial.begin(9600);
  sensorArray.begin();
}

void loop() {
  int distance1 = sensorArray.readDistance(0, 0); // Read from the first sensor on multiplexer 0
  int distance2 = sensorArray.readDistance(0, 1); // Read from the second sensor on multiplexer 0

  // Use the sensor data as needed

  delay(1000); // Delay for 1 second before the next reading
}
```

## Example 2: Use with 4 Sensors and 2 Multiplexers
To use the library with 4 sensors and 2 multiplexers, follow these steps:
```cpp
// Define the I2C addresses of your multiplexers
uint8_t muxAddresses[] = {0x70, 0x71}; // Addresses for 2 multiplexers

MultiSensorArray sensorArray(2, muxAddresses); // 2 multiplexers

void setup() {
  Serial.begin(9600);
  sensorArray.begin();
}

void loop() {
  int distance1 = sensorArray.readDistance(0, 0); // Read from the first sensor on multiplexer 0
  int distance2 = sensorArray.readDistance(0, 1); // Read from the second sensor on multiplexer 0
  int distance3 = sensorArray.readDistance(1, 0); // Read from the first sensor on multiplexer 1
  int distance4 = sensorArray.readDistance(1, 1); // Read from the second sensor on multiplexer 1

  // Use the sensor data as needed

  delay(1000); // Delay for 1 second before the next reading
}
```
## Advanced Usage
Using Multiple Multiplexers
To use multiple multiplexers with the library, define the I2C addresses of each multiplexer and initialize the MultiSensorArray instance accordingly.
```cpp
// Define the I2C addresses of your multiplexers
uint8_t muxAddresses[] = {0x70, 0x71, 0x72}; // Addresses for 3 multiplexers

MultiSensorArray sensorArray(3, muxAddresses); // 3 multiplexers
```
## Library Reference
MultiSensorArray(uint8_t numMultiplexers, uint8_t* muxAddresses): Constructor to initialize the library with the number of multiplexers and their addresses.

void begin(): Initializes the library and the Wire (I2C) communication.

int readDistance(uint8_t muxIndex, uint8_t sensorIndex): Reads the distance from a specific sensor on a specific multiplexer.

## Troubleshooting
If you encounter any issues or have questions about the library, please refer to the GitHub repository for the latest updates and community support.

## License
This library is open-source and released under the MIT License.
