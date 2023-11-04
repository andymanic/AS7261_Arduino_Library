/*
 Name:		AS726X.h
 Created:	7/11/2017 12:06:22 PM
 Author:	andrew.england
 Editor:	http://www.visualmicro.com

 Modified by Andrew McDonald (andymanic1)
*/

#ifndef _AS726X_h
#define _AS726X_h
#include "Arduino.h"
#include "Wire.h"
class AS726X {
public:
	AS726X();
	bool begin(TwoWire &wirePort = Wire, uint8_t gain = 3, uint8_t measurementMode = 3);
	void takeMeasurements();
	uint8_t getVersion();
	void takeMeasurementsWithBulb();
	uint8_t getTemperature();
	float getTemperatureF();
	void setMeasurementMode(uint8_t mode);
	bool dataAvailable();
	void enableIndicator();
	void disableIndicator();
	void setIndicatorCurrent(uint8_t current);
	void enableBulb();
	void disableBulb();
	void setBulbCurrent(uint8_t current);
	void softReset();
	void setGain(uint8_t gain);
	void setIntegrationTime(uint8_t integrationValue);
	void enableInterrupt();
	void disableInterrupt();
	//Get the various color readings
	int getX();
	int getY();
	int getZ();
	int getNIR();
	int getDark();
	int getClear();

	//Returns the various calibration data
	float getCalibratedX();
	float getCalibratedY();
	float getCalibratedZ();
	float getCalibratedNIR();
	float getCalibratedDark();
	float getCalibratedClear();

private:
	TwoWire *_i2cPort;
	int getChannel(uint8_t channelRegister);
	float getCalibratedValue(uint8_t calAddress);
	float convertBytesToFloat(uint32_t myLong);
	void clearDataAvailable();
	uint8_t virtualReadRegister(uint8_t virtualAddr);
	void virtualWriteRegister(uint8_t virtualAddr, uint8_t dataToWrite);
	void writeRegister(uint8_t addr, uint8_t val);
	uint8_t readRegister(uint8_t addr);
#define AS726X_ADDR 0x49 //7-bit unshifted default I2C Address
#define SENSORTYPE_AS7262 0x3E
#define SENSORTYPE_AS7263 0x3F

	//Register addresses
#define AS726x_DEVICE_TYPE 0x00
#define AS726x_HW_VERSION 0x01
#define AS726x_CONTROL_SETUP 0x04
#define AS726x_INT_T 0x05
#define AS726x_DEVICE_TEMP 0x06
#define AS726x_LED_CONTROL 0x07

#define AS72XX_SLAVE_STATUS_REG 0x00
#define AS72XX_SLAVE_WRITE_REG 0x01
#define AS72XX_SLAVE_READ_REG 0x02

	//The same register locations are shared between the AS7262 and AS7263, they're just called something different
	//AS7262 Registers
#define AS7261_X 0x08
#define AS7261_Y 0x0A
#define AS7261_Z 0x0C
#define AS7261_NIR 0x0E
#define AS7261_Dark 0x10
#define AS7261_Clear 0x12
#define AS7261_X_CAL 0x14
#define AS7261_Y_CAL 0x18
#define AS7261_Z_CAL 0x1C
#define AS7261_NIR_CAL 0x20
#define AS7261_Dark_CAL 0x24
#define AS7261_Clear_CAL 0x28



#define AS72XX_SLAVE_TX_VALID 0x02
#define AS72XX_SLAVE_RX_VALID 0x01

#define SENSORTYPE_AS7261 

#define POLLING_DELAY 5 //Amount of ms to wait between checking for virtual register changes

	uint8_t _sensorVersion = 0;
};

#endif