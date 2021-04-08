//*****************************************************************************
// Bosch Sensortec BMP280 Digital Pressure Sensor functions
// (C) 2016 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.26+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00
// 16022016_2 - Initial release.
//*****************************************************************************

#ifndef _BMP280_INCLUDED_
#define _BMP280_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#else
#include <twi.h>
#endif

// BMP280 7-bit I2C bus addresses
#define BMP280_I2C_ADDR_SDO_LOW 0x76 // The SDO pin is set to logic 0
#define BMP280_I2C_ADDR_SDO_HIGH 0x77  // The SDO pin is set to logic 1

// BMP280 calibration data registers:
#define BMP280_TEMP_CALIB_DIG_T1_LSB_REG  0x88
#define BMP280_TEMP_CALIB_DIG_T1_MSB_REG  0x89
#define BMP280_TEMP_CALIB_DIG_T2_LSB_REG  0x8A
#define BMP280_TEMP_CALIB_DIG_T2_MSB_REG  0x8B
#define BMP280_TEMP_CALIB_DIG_T3_LSB_REG  0x8C
#define BMP280_TEMP_CALIB_DIG_T3_MSB_REG  0x8D
#define BMP280_PRESS_CALIB_DIG_P1_LSB_REG 0x8E
#define BMP280_PRESS_CALIB_DIG_P1_MSB_REG 0x8F
#define BMP280_PRESS_CALIB_DIG_P2_LSB_REG 0x90
#define BMP280_PRESS_CALIB_DIG_P2_MSB_REG 0x91
#define BMP280_PRESS_CALIB_DIG_P3_LSB_REG 0x92
#define BMP280_PRESS_CALIB_DIG_P3_MSB_REG 0x93
#define BMP280_PRESS_CALIB_DIG_P4_LSB_REG 0x94
#define BMP280_PRESS_CALIB_DIG_P4_MSB_REG 0x95
#define BMP280_PRESS_CALIB_DIG_P5_LSB_REG 0x96
#define BMP280_PRESS_CALIB_DIG_P5_MSB_REG 0x97
#define BMP280_PRESS_CALIB_DIG_P6_LSB_REG 0x98
#define BMP280_PRESS_CALIB_DIG_P6_MSB_REG 0x99
#define BMP280_PRESS_CALIB_DIG_P7_LSB_REG 0x9A
#define BMP280_PRESS_CALIB_DIG_P7_MSB_REG 0x9B
#define BMP280_PRESS_CALIB_DIG_P8_LSB_REG 0x9C
#define BMP280_PRESS_CALIB_DIG_P8_MSB_REG 0x9D
#define BMP280_PRESS_CALIB_DIG_P9_LSB_REG 0x9E
#define BMP280_PRESS_CALIB_DIG_P9_MSB_REG 0x9F

// BMP280 Registers:
#define BMP280_CHIP_ID_REG 0xD0    // Chip ID register
#define BMP280_SOFT_RESET_REG 0xE0 // Software Reset register

#define BMP280_STATUS_REG 0xF3     // Status register
#define BMP280_CTRL_MEAS_REG 0xF4  // Control & Measurement register
#define BMP280_CONFIG_REG 0xF5     // Configuration register

#define BMP280_PRESS_MSB_REG 0xF7  // Read ADC Pressure Result register MSB
#define BMP280_PRESS_LSB_REG 0xF8  // Read ADC Pressure Result register LSB
#define BMP280_PRESS_XLSB_REG 0xF9 // Read ADC Pressure Result register XLSB

#define BMP280_TEMP_MSB_REG 0xFA   // Read ADC Temperature Result register MSB
#define BMP280_TEMP_LSB_REG 0xFB   // Read ADC Temperature Result register LSB
#define BMP280_TEMP_XLSB_REG 0xFC  // Read ADC Temperature Result register XLSB

// Chip ID for BMP280
#define BMP280_CHIP_ID 0x58
// Soft Reset register command for reseting chip 
#define BMP280_SOFT_RESET_CMD 0xB6 
// Control register value for measuring temperature
#define BMP280_CTRL_TEMP 0x2E
// Control register value for measuring pressure
#define BMP280_CTRL_PRES 0x34

// BMP280 measurement modes
#define BMP280_SLEEP_MODE 0x00  // Sleep mode
#define BMP280_FORCED_MODE 0x01 // Forced mode, single measurement
#define BMP280_NORMAL_MODE 0x03 // Normal mode, continuous measurement cycles

// BMP280 pressure measurement modes
#define BMP280_ULTRA_LOW_POWER_MODE 0 // Ultra Low Power Mode
#define BMP280_LOW_POWER_MODE 1       // Low Power Mode
#define BMP280_STANDARD_RES_MODE 2    // Standard Resolution Mode
#define BMP280_HI_RES_MODE 3          // High Resolution Mode
#define BMP280_ULTRA_HI_RES_MODE 4    // Ultra High Resolution Mode

// Return values for the BMP280 functions:
#define BMP280_INIT_OK 0         // The initialization was successful
#define BMP280_COMM_ERROR -32768 // TWI communication with the device has failed
#define BMP280_INIT_ERROR -32767 // TWI initialization parameters are not correct
#define BMP280_MEAS_ERROR -32766 // Measurement error or calibration coefficients
                                 // read from device's EEPROM are not correct
// Pressure oversampling modes
#define BMP280_OVERSAMP_OFF 0x00
#define BMP280_OVERSAMP_1X 0x01
#define BMP280_OVERSAMP_2X 0x02
#define BMP280_OVERSAMP_4X 0x03
#define BMP280_OVERSAMP_8X 0x04
#define BMP280_OVERSAMP_16X 0x05

// Filter coefficient
#define BMP280_FILTER_COEFF_OFF 0x00
#define BMP280_FILTER_COEFF_2  0x01
#define BMP280_FILTER_COEFF_4  0x02
#define BMP280_FILTER_COEFF_8  0x03
#define BMP280_FILTER_COEFF_16 0x04

// Structure that holds BMP280 calibration parameters
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
} BMP280_CALIB_PARAM_t;

extern BMP280_CALIB_PARAM_t bmp280_calib_param;

//*****************************************************************************
// Writes a byte of data to the BMP280 register.
// reg - register index
// data - byte to write
// Returns:
// BMP280_INIT_OK (0)   - write has succeeded
// negative value BMP280_COMM_ERROR - TWI communication error with the device.
//*****************************************************************************
short bmp280_wrreg(unsigned char reg,unsigned char data);

//*****************************************************************************
// Reads a byte of data from the BMP280 register.
// reg - register index
// Returns:
// positive value 0..255 - read has succeeded
// negative value BMP280_COMM_ERROR - TWI communication error with the device.
//*****************************************************************************
short bmp280_rdreg(unsigned char reg);

// Initialize the BMP280
#ifdef _ATXMEGA_DEVICE_
//*****************************************************************************
// Initialize the BMP280.
// twi_master -     pointer to the structure that holds
//                  information used by the TWI master
//                  XMEGA module, used for communication with
//                  the pressure sensor, for performing a
//                  TWI bus transaction
// device_address - 7-bit I2C bus address of the BMP280 chip:
//                  BMP280_I2C_ADDR_SDO_LOW..BMP280_I2C_ADDR_SDO_HI
// mode -           BMP280 pressure measurement mode:
//                  BMP280_ULTRA_LOW_POWER_MODE..BMP280_ULTRA_HI_RES_MODE
// filter_coeff -   IIR Filter coefficient:
//                  BMP280_FILTER_COEFF_OFF..BMP280_FILTER_COEFF_16
// Returns:
// BMP280_INIT_OK     - the initialization has succeeded
// BMP280_COMM_ERROR  - TWI communication error with the device
// BMP280_INIT_ERROR  - the initialization parameters are not correct
//*****************************************************************************
short bmp280_init(TWI_MASTER_INFO_t *twi_master,unsigned char device_address,unsigned char mode,unsigned char filter_coeff);
#else
//*****************************************************************************
// Initialize the BMP280.
// device_address - 7-bit I2C bus address of the BMP280 chip:
//                  BMP280_I2C_ADDR_SDO_LOW..BMP280_I2C_ADDR_SDO_HI
// mode -           BMP280 pressure measurement mode:
//                  BMP280_ULTRA_LOW_POWER_MODE..BMP280_ULTRA_HI_RES_MODE
// filter_coeff -   IIR Filter coefficient:
//                  BMP280_FILTER_COEFF_OFF..BMP280_FILTER_COEFF_16
// Returns:
// BMP280_INIT_OK     - the initialization has succeeded
// BMP280_COMM_ERROR  - TWI communication error with the device
// BMP280_INIT_ERROR  - the initialization parameters are not correct
//*****************************************************************************
short bmp280_init(unsigned char device_address,unsigned char mode,unsigned char filter_coeff);
#endif

//*****************************************************************************
// Reads the compensated temperature [C] with 0.01 C resolution.
// Returns:
// temperature value or
// BMP280_INIT_ERROR - the device was not properly initialized
// BMP280_COMM_ERROR - TWI communication error with the device.
//*****************************************************************************
float bmp280_temperature(void);

//*****************************************************************************
// Reads the compensated pressure [Pa] with 0.1 Pa resolution.
// Returns:
// positive pressure value or
// BMP280_INIT_ERROR - the device was not properly initialized
// BMP280_MEAS_ERROR - measurement or calibration error
// BMP280_COMM_ERROR - TWI communication error with the device.
// Note: calculations are performed on 64-bits with higher precision.
//*****************************************************************************
float bmp280_pressure(void);

//*****************************************************************************
// Reads the compensated pressure [Pa] with 1 Pa resolution.
// Returns:
// positive pressure value or
// BMP280_INIT_ERROR - the device was not properly initialized
// BMP280_MEAS_ERROR - measurement or calibration error
// BMP280_COMM_ERROR - TWI communication error with the device.
// Note: calculations are performed on 32-bits with lower precision.
//*****************************************************************************
long bmp280_pressure_low_res(void);

#pragma library bmp280_twi.lib

#endif

