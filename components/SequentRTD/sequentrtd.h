#include "esphome.h"

enum
{
	RTD_VAL1_ADD = 0,
	RTD_VAL2_ADD = RTD_VAL1_ADD + 4,
	RTD_VAL3_ADD = RTD_VAL2_ADD + 4,
	RTD_VAL4_ADD = RTD_VAL3_ADD + 4,
	RTD_VAL5_ADD = RTD_VAL4_ADD + 4,
	RTD_VAL6_ADD = RTD_VAL5_ADD + 4,
	RTD_VAL7_ADD = RTD_VAL6_ADD + 4,
	RTD_VAL8_ADD = RTD_VAL7_ADD + 4,
	DIAG_TEMPERATURE_MEM_ADD = RTD_VAL8_ADD + 4,
	DIAG_5V_MEM_ADD,
	I2C_MEM_WDT_RESET_ADD = DIAG_5V_MEM_ADD + 2,
	I2C_MEM_WDT_INTERVAL_SET_ADD,
	I2C_MEM_WDT_INTERVAL_GET_ADD = I2C_MEM_WDT_INTERVAL_SET_ADD + 2,
	I2C_MEM_WDT_INIT_INTERVAL_SET_ADD = I2C_MEM_WDT_INTERVAL_GET_ADD + 2,
	I2C_MEM_WDT_INIT_INTERVAL_GET_ADD = I2C_MEM_WDT_INIT_INTERVAL_SET_ADD + 2,
	I2C_MEM_WDT_RESET_COUNT_ADD = I2C_MEM_WDT_INIT_INTERVAL_GET_ADD + 2,
	I2C_MEM_WDT_CLEAR_RESET_COUNT_ADD = I2C_MEM_WDT_RESET_COUNT_ADD + 2,
	I2C_MEM_WDT_POWER_OFF_INTERVAL_SET_ADD,
	I2C_MEM_WDT_POWER_OFF_INTERVAL_GET_ADD = I2C_MEM_WDT_POWER_OFF_INTERVAL_SET_ADD + 4,
	REVISION_HW_MAJOR_MEM_ADD  = I2C_MEM_WDT_POWER_OFF_INTERVAL_GET_ADD + 4,
	REVISION_HW_MINOR_MEM_ADD,
	REVISION_MAJOR_MEM_ADD,
	REVISION_MINOR_MEM_ADD,

	RTD_RES1_ADD,
	RTD_RES2_ADD = RTD_RES1_ADD + 4,
	RTD_RES3_ADD = RTD_RES2_ADD + 4,
	RTD_RES4_ADD = RTD_RES3_ADD + 4,
	RTD_RES5_ADD = RTD_RES4_ADD + 4,
	RTD_RES6_ADD = RTD_RES5_ADD + 4,
	RTD_RES7_ADD = RTD_RES6_ADD + 4,
	RTD_RES8_ADD = RTD_RES7_ADD + 4,
	RTD_REINIT_COUNT = RTD_RES8_ADD + 4,
	RTD_SPS1_ADD = RTD_REINIT_COUNT + 4,
	RTD_SPS2_ADD = RTD_SPS1_ADD + 2,
	RTD_CARD_TYPE = RTD_SPS2_ADD+2,
	RTD_RASP_VOLT,
	I2C_MODBUS_SETINGS_ADD = RTD_RASP_VOLT + 2, //5 bytes
	RTD_LEDS_FUNC = I2C_MODBUS_SETINGS_ADD + 5, //2 bytes
	RTD_LED_THRESHOLD1 = RTD_LEDS_FUNC + 2,
	RTD_LED_THRESHOLD2 = RTD_LED_THRESHOLD1 + 2,
	RTD_LED_THRESHOLD3 = RTD_LED_THRESHOLD2 + 2,
	RTD_LED_THRESHOLD4 = RTD_LED_THRESHOLD3 + 2,
	RTD_LED_THRESHOLD5 = RTD_LED_THRESHOLD4 + 2,
	RTD_LED_THRESHOLD6 = RTD_LED_THRESHOLD5 + 2,
	RTD_LED_THRESHOLD7 = RTD_LED_THRESHOLD6 + 2,
	RTD_LED_THRESHOLD8 = RTD_LED_THRESHOLD7 + 2,
	I2C_CALIB_RES = RTD_LED_THRESHOLD8 + 2,//float
	I2C_CALIB_CH = I2C_CALIB_RES + 4,//u8
	I2C_SENSORS_TYPE,
	I2C_MEM_ADS_SAMPLE_SWITCH,//u16

	SLAVE_BUFF_SIZE = 0xff

};


uint8_t _hwAdd;
#define SLAVE_OWN_ADDRESS_BASE 0x40


class sequentRTD : public PollingComponent, public Sensor {
 public:
  Sensor *RTD1_Temp = new Sensor();
  Sensor *RTD2_Temp = new Sensor();
  Sensor *RTD3_Temp = new Sensor();
  Sensor *RTD4_Temp = new Sensor();
  Sensor *RTD5_Temp = new Sensor();
  Sensor *RTD6_Temp = new Sensor();
  Sensor *RTD7_Temp = new Sensor();
  Sensor *RTD8_Temp = new Sensor();

  SequentRTD() : PollingComponent(5000) {}

  void setup() override {
    // Initialize the device here. Usually Wire.begin() will be called in here,
    // though that call is unnecessary if you have an 'i2c:' entry in your config
   
    _hwAdd = SLAVE_OWN_ADDRESS_BASE;
    Wire.begin();
  }

  void update() override {
  uint8 stack = id(stack_level).state; //Read the number set on the dashboard
  _hwAdd = SLAVE_OWN_ADDRESS_BASE + stack;
    }

  void loop() override {
    uint8_t buff[4];  
    float val = -1000;
    uint8 channel = 1;

    readFloat(RTD_VAL1_ADD + sizeof(float) * (channel -1), &val))
    RTD1_Temp->publish_state(val);
    channel++;

    readFloat(RTD_VAL1_ADD + sizeof(float) * (channel -1), &val))
    RTD2_Temp->publish_state(val);
    channel++;
     
    readFloat(RTD_VAL1_ADD + sizeof(float) * (channel -1), &val))
    RTD3_Temp->publish_state(val);
    channel++;
     
    readFloat(RTD_VAL1_ADD + sizeof(float) * (channel -1), &val))
    RTD4_Temp->publish_state(val);
    channel++;
     
    readFloat(RTD_VAL1_ADD + sizeof(float) * (channel -1), &val))
    RTD5_Temp->publish_state(val);
    channel++;
     
    readFloat(RTD_VAL1_ADD + sizeof(float) * (channel -1), &val))
    RTD6_Temp->publish_state(val);
    channel++;
     
    readFloat(RTD_VAL1_ADD + sizeof(float) * (channel -1), &val))
    RTD7_Temp->publish_state(val);
    channel++;
     
    readFloat(RTD_VAL1_ADD + sizeof(float) * (channel -1), &val))
    RTD8_Temp->publish_state(val);
    channel++;
   
  }
};


int readFloat(uint8_t add, float *value)
{
	uint8_t buff[4];
	int i = 0;

	if (0 == value)	{		return -1; }

	Wire.beginTransmission(_hwAdd);
	Wire.write(add);
	if (Wire.endTransmission() != 0)	{	return -1;	}
	Wire.requestFrom(_hwAdd, (uint8_t)4);
	if (4 <= Wire.available())
	{
		for (i = 0; i < 4; i++)
		{
			buff[i] = Wire.read();
		}
	}
	else
	{
		return -1;
	}
	memcpy(value, buff, 4);
	return 0;
}
