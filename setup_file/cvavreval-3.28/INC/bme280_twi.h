//*****************************************************************************
// Bosch Sensortec BME280 Digital Humidity and Pressure Sensor functions
// (C) 2016 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.26+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00
// 08032016_1 - Initial release.
//*****************************************************************************

#ifndef _BME280_INCLUDED_
#define _BME280_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#else
#include <twi.h>
#endif

// BME280 7-bit I2C bus addresses
#define BME280_I2C_ADDR_SDO_LOW 0x76 // The SDO pin is set to logic 0
#define BME280_I2C_ADDR_SDO_HIGH 0x77  // The SDO pin is set to logic 1

// BME280 calibration data registers:
#define BME280_TEMP_CALIB_DIG_T1_LSB_REG  0x88
#define BME280_TEMP_CALIB_DIG_T1_MSB_REG  0x89
#define BME280_TEMP_CALIB_DIG_T2_LSB_REG  0x8A
#define BME280_TEMP_CALIB_DIG_T2_MSB_REG  0x8B
#define BME280_TEMP_CALIB_DIG_T3_LSB_REG  0x8C
#define BME280_TEMP_CALIB_DIG_T3_MSB_REG  0x8D
#define BME280_PRESS_CALIB_DIG_P1_LSB_REG 0x8E
#define BME280_PRESS_CALIB_DIG_P1_MSB_REG 0x8F
#define BME280_PRESS_CALIB_DIG_P2_LSB_REG 0x90
#define BME280_PRESS_CALIB_DIG_P2_MSB_REG 0x91
#define BME280_PRESS_CALIB_DIG_P3_LSB_REG 0x92
#define BME280_PRESS_CALIB_DIG_P3_MSB_REG 0x93
#define BME280_PRESS_CALIB_DIG_P4_LSB_REG 0x94
#define BME280_PRESS_CALIB_DIG_P4_MSB_REG 0x95
#define BME280_PRESS_CALIB_DIG_P5_LSB_REG 0x96
#define BME280_PRESS_CALIB_DIG_P5_MSB_REG 0x97
#define BME280_PRESS_CALIB_DIG_P6_LSB_REG 0x98
#define BME280_PRESS_CALIB_DIG_P6_MSB_REG 0x99
#define BME280_PRESS_CALIB_DIG_P7_LSB_REG 0x9A
#define BME280_PRESS_CALIB_DIG_P7_MSB_REG 0x9B
#define BME280_PRESS_CALIB_DIG_P8_LSB_REG 0x9C
#define BME280_PRESS_CALIB_DIG_P8_MSB_REG 0x9D
#define BME280_PRESS_CALIB_DIG_P9_LSB_REG 0x9E
#define BME280_PRESS_CALIB_DIG_P9_MSB_REG 0x9F

#define BME280_HUM_CALIB_DIG_H1_REG       0xA1

#define BME280_HUM_CALIB_DIG_H2_LSB_REG   0xE1
#define BME280_HUM_CALIB_DIG_H2_MSB_REG   0xE2
#define BME280_HUM_CALIB_DIG_H3_REG       0xE3
#define BME280_HUM_CALIB_DIG_H4_MSB_REG   0xE4
#define BME280_HUM_CALIB_DIG_H4_LSB_REG   0xE5
#define BME280_HUM_CALIB_DIG_H5_MSB_REG   0xE6
#define BME280_HUM_CALIB_DIG_H6_REG       0xE7

// BME280 Registers:
#define BME280_CHIP_ID_REG 0xD0    // Chip ID register
#define BME280_SOFT_RESET_REG 0xE0 // Software Reset register

#define BME280_CTRL_HUM_REG 0xF2   // Humidity oversampling control register
#define BME280_STATUS_REG 0xF3     // Status register
#define BME280_CTRL_MEAS_REG 0xF4  // Control & Measurement register
#define BME280_CONFIG_REG 0xF5     // Configuration register

#define BME280_PRESS_MSB_REG 0xF7  // Read ADC Pressure Result register MSB
#define BME280_PRESS_LSB_REG 0xF8  // Read ADC Pressure Result register LSB
#define BME280_PRESS_XLSB_REG 0xF9 // Read ADC Pressure Result register XLSB

#define BME280_TEMP_MSB_REG 0xFA   // Read ADC Temperature Result register MSB
#define BME280_TEMP_LSB_REG 0xFB   // Read ADC Temperature Result register LSB
#define BME280_TEMP_XLSB_REG 0xFC  // Read ADC Temperature Result register XLSB

#define BME280_HUM_MSB_REG 0xFD    // Read ADC Humidity Result register MSB
#define BME280_HUM_LSB_REG 0xFE    // Read ADC Humidity Result register LSB

// Chip ID for BME280
#define BME280_CHIP_ID 0x60
// Soft Reset register command for reseting chip 
#define BME280_SOFT_RESET_CMD 0xB6 
// Control register value for measuring temperature
#define BME280_CTRL_TEMP 0x2E
// Control register value for measuring pressure
#define BME280_CTRL_PRES 0x34

// BME280 measurement modes
#define BME280_SLEEP_MODE 0x00  // Sleep mode
#define BME280_FORCED_MODE 0x01 // Forced mode, single measurement
#define BME280_NORMAL_MODE 0x03 // Normal mode, continuous measurement cycles

// BME280 pressure measurement modes
#define BME280_PRESSURE_OFF 0         // Pressure measurement disabled
#define BME280_ULTRA_LOW_POWER_MODE 1 // Ultra Low Power Mode
#define BME280_LOW_POWER_MODE 2       // Low Power Mode
#define BME280_STANDARD_RES_MODE 3    // Standard Resolution Mode
#define BME280_HI_RES_MODE 4          // High Resolution Mode
#define BME280_ULTRA_HI_RES_MODE 5    // Ultra High Resolution Mode

// Return values for the BME280 functions:
#define BME280_INIT_OK 0         // The initialization was successful
#define BME280_COMM_ERROR -32768 // TWI communication with the device has failed
#define BME280_INIT_ERROR -32767 // TWI initialization parameters are not correct
#define BME280_MEAS_ERROR -32766 // Measurement error or calibration coefficients
                                 // read from device's EEPROM are not correct
// Pressure/temperature/humidity oversampling modes
#define BME280_OVERSAMP_OFF 0x00
#define BME280_OVERSAMP_1X 0x01
#define BME280_OVERSAMP_2X 0x02
#define BME280_OVERSAMP_4X 0x03
#define BME280_OVERSAMP_8X 0x04
#define BME280_OVERSAMP_16X 0x05

// Filter coefficient
#define BME280_FILTER_COEFF_OFF 0x00
#define BME280_FILTER_COEFF_2  0x01
#define BME280_FILTER_COEFF_4  0x02
#define BME280_FILTER_COEFF_8  0x03
#define BME280_FILTER_COEFF_16 0x04

// Structure that holds BME280 calibration coefficients
// read from the internal EEPROM
typedef struct  
{
unsigned short dig_T1;
signed short dig_T2;
signed short dig_T3;
unsigned short dig_P1;
signed short dig_P2;
signed short dig_P3;
signed short dig_P4;
signed short dig_P5;
signed short dig_P6;
signed short dig_P7;
signed short dig_P8;
signed short dig_P9;
unsigned char dig_H1;
signed short dig_H2;
unsigned char dig_H3;
signed short dig_H4;
signed short dig_H5;
signed char dig_H6;
} BME280_CALIB_PARAM_t;

extern BME280_CALIB_PARAM_t bme280_calib_param;

//*****************************************************************************
// Writes a byte of data to the BME280 register.
// reg - register index
// data - byte to write
// Returns:
// BME280_INIT_OK (0)   - write has succeeded
// negative value BME280_COMM_ERROR - TWI communication error with the device.
//*****************************************************************************
short bme280_wrreg(unsigned char reg,unsigned char data);

//*****************************************************************************
// Reads a byte of data from the BME280 register.
// reg - register index
// Returns:
// positive value 0..255 - read has succeeded
// negative value BME280_COMM_ERROR - TWI communication error with the device.
//*****************************************************************************
short bme280_rdreg(unsigned char reg);

// Initialize the BME280
#ifdef _ATXMEGA_DEVICE_
//*****************************************************************************
// Initialize the BME280.
// twi_master -     pointer to the structure that holds
//                  information used by the TWI master
//                  XMEGA module, used for communication with
//                  the pressure sensor, for performing a
//                  TWI bus transaction
// device_address - 7-bit I2C bus address of the BME280 chip:
//                  BME280_I2C_ADDR_SDO_LOW..BME280_I2C_ADDR_SDO_HI
// mode -           BME280 pressure measurement mode:
//                  BME280_ULTRA_LOW_POWER_MODE..BME280_ULTRA_HI_RES_MODE
// filter_coeff -   IIR Filter coefficient:
//                  BME280_FILTER_COEFF_OFF..BME280_FILTER_COEFF_16
// hum_oversampling - humiditity measurement oversampling mode:
//                  BME280_OVERSAMP_OFF..BME280_OVERSAMP_16X
// Returns:
// BME280_INIT_OK     - the initialization has succeeded
// BME280_COMM_ERROR  - TWI communication error with the device
// BME280_INIT_ERROR  - the initialization parameters are not correct
//*****************************************************************************
short bme280_init(TWI_MASTER_INFO_t *twi_master,unsigned char device_address,
      unsigned char mode,unsigned char filter_coeff,unsigned char hum_oversampling);
#else
//*****************************************************************************
// Initialize the BME280.
// device_address - 7-bit I2C bus address of the BME280 chip:
//                  BME280_I2C_ADDR_SDO_LOW..BME280_I2C_ADDR_SDO_HI
// mode -           BME280 pressure measurement mode:
//                  BME280_ULTRA_LOW_POWER_MODE..BME280_ULTRA_HI_RES_MODE
// filter_coeff -   IIR Filter coefficient:
//                  BME280_FILTER_COEFF_OFF..BME280_FILTER_COEFF_16
// hum_oversampling - humiditity measurement oversampling mode:
//                  BME280_OVERSAMP_OFF..BME280_OVERSAMP_16X
// Returns:
// BME280_INIT_OK     - the initialization has succeeded
// BME280_COMM_ERROR  - TWI communication error with the device
// BME280_INIT_ERROR  - the initialization parameters are not correct
//*****************************************************************************
short bme280_init(unsigned char device_address,unsigned char mode,
      unsigned char filter_coeff,unsigned char hum_oversampling);
#endif

//*****************************************************************************
// Reads the compensated temperature [C] with 0.01 C resolution.
// Returns:
// temperature value or
// BME280_INIT_ERROR - the device was not properly initialized
// BME280_COMM_ERROR - TWI communication error with the device.
//*****************************************************************************
float bme280_temperature(void);

//*****************************************************************************
// Reads the compensated pressure [Pa] with 0.1 Pa resolution.
// Returns:
// positive pressure value or
// BME280_INIT_ERROR - the device was not properly initialized
// BME280_MEAS_ERROR - measurement or calibration error
// BME280_COMM_ERROR - TWI communication error with the device.
// Note: calculations are performed on 64-bits with higher precision.
//*****************************************************************************
float bme280_pressure(void);

//*****************************************************************************
// Reads the compensated pressure [Pa] with 1 Pa resolution.
// Returns:
// positive pressure value or
// BME280_INIT_ERROR - the device was not properly initialized
// BME280_MEAS_ERROR - measurement or calibration error
// BME280_COMM_ERROR - TWI communication error with the device.
// Note: calculations are performed on 32-bits with lower precision.
//*****************************************************************************
long bme280_pressure_low_res(void);

//*****************************************************************************
// Reads the compensated relative humidity [%].
// Returns:
// positive humidity value or
// BME280_INIT_ERROR - the device was not properly initialized
// BME280_MEAS_ERROR - measurement or calibration error
// BME280_COMM_ERROR - TWI communication error with the device.
//*****************************************************************************
float bme280_humidity(void);

#pragma library bme280_twi.lib

#endif

