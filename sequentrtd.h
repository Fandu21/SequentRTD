#include "esphome.h"






class sequentRTD : public PollingComponent {
 public:
  void setup() override {
    // Initialize the device here. Usually Wire.begin() will be called in here,
    // though that call is unnecessary if you have an 'i2c:' entry in your config

    Wire.begin();
  }
  void loop() override {
    // Example: write the value 0x42 to register 0x78 of device with address 0x21
    Wire.beginTransmission(0x21);
    Wire.write(0x78);
    Wire.write(0x42);
    Wire.endTransmission();
  }
};