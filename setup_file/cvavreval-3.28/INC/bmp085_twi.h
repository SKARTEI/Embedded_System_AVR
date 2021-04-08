//*****************************************************************************
// Bosch Sensortec BMP085 Digital Pressure Sensor functions
// (C) 2015 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.21+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00
// 22042015_1 - Initial release.
//*****************************************************************************

#ifndef _BMP085_INCLUDED_
#define _BMP085_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#else
#include <twi.h>
#endif

// BMP085 I2C bus address
#define BMP085_I2C_ADDR 0x77

#define BMP085_CHIP_ID_REG 0xD0 // Chip ID register
#define BMP085_VERSION_REG 0xD1 // Chip Version register
#define BMP085_SOFT_RESET_REG 0xE0 // Software Reset register

#define BMP085_CTRL_MEAS_REG 0xF4    // Control & Measurement register
#define BMP085_ADC_OUT_MSB_REG 0xF6  // Read ADC Result register MSB
#define BMP085_ADC_OUT_LSB_REG 0xF7  // Read ADC Result register LSB
#define BMP085_ADC_OUT_XLSB_REG 0xF8 // Read ADC Result register XLSB

// Addresses of BMP085 calibration parameters
#define	BMP085_CALIB_PARAM_AC1_MSB 0xAA
#define	BMP085_CALIB_PARAM_AC1_LSB 0xAB
#define BMP085_CALIB_PARAM_AC2_MSB 0xAC
#define BMP085_CALIB_PARAM_AC2_LSB 0xAD
#define	BMP085_CALIB_PARAM_AC3_MSB 0xAE
#define	BMP085_CALIB_PARAM_AC3_LSB 0xAF
#define	BMP085_CALIB_PARAM_AC4_MSB 0xB0
#define	BMP085_CALIB_PARAM_AC4_LSB 0xB1
#define	BMP085_CALIB_PARAM_AC5_MSB 0xB2
#define	BMP085_CALIB_PARAM_AC5_LSB 0xB3
#define	BMP085_CALIB_PARAM_AC6_MSB 0xB4
#define	BMP085_CALIB_PARAM_AC6_LSB 0xB5
#define	BMP085_CALIB_PARAM_B1_MSB 0xB6
#define	BMP085_CALIB_PARAM_B1_LSB 0xB7
#define	BMP085_CALIB_PARAM_B2_MSB 0xB8
#define	BMP085_CALIB_PARAM_B2_LSB 0xB9
#define	BMP085_CALIB_PARAM_MB_MSB 0xBA
#define	BMP085_CALIB_PARAM_MB_LSB 0xBB
#define	BMP085_CALIB_PARAM_MC_MSB 0xBC
#define	BMP085_CALIB_PARAM_MC_LSB 0xBD
#define	BMP085_CALIB_PARAM_MD_MSB 0xBE
#define	BMP085_CALIB_PARAM_MD_LSB 0xBF

// Chip ID for BMP085
#define BMP085_CHIP_ID 0x55
// Soft Reset register command for reseting chip 
#define BMP085_SOFT_RESET_CMD 0xB6 
// Control register value for measuring temperature
#define BMP085_CTRL_TEMP 0x2E
// Control register value for measuring pressure
#define BMP085_CTRL_PRES 0x34

// BMP085 pressure measurement modes (conversion time)
#define BMP085_ULTRA_LOW_POWER_MODE 0 // Ultra Low Power Mode (5ms)
#define BMP085_STANDARD_MODE 1     // Standard Mode (8ms)
#define BMP085_HI_RES_MODE 2       // High Resolution Mode (14ms)
#define BMP085_ULTRA_HI_RES_MODE 3 // Ultra High Resolution Mode (26ms)
#define BMP085_ADVANCED_RES_MODE 4 // Advanced Resolution Mode (76ms)

// Return values for the BMP085 functions:
#define BMP085_INIT_OK 0         // The initialization was successful
#define BMP085_COMM_ERROR -32768 // TWI communication with the device has failed
#define BMP085_INIT_ERROR -32767 // TWI initialization parameters are not correct
#define BMP085_CALIB_ERROR -32766 // The calibration data read from the device PROM is not correct

// Structure that holds BMP085 calibration parameters
// read from the internal EEPROM
typedef struct  
{
short ac1; // AC1 parameter
short ac2; // AC2 parameter
short ac3; // AC3 parameter
unsigned short ac4; // AC4 parameter
unsigned short ac5; // AC5 parameter
unsigned short ac6; // AC6 parameter
short b1; // B1 parameter
short b2; // B2 parameter
short mb; // MB parameter
short mc; // MC parameter
short md; // MD parameter
} BMP085_CALIB_PARAM_t;

extern BMP085_CALIB_PARAM_t bmp085_calib_param;

// Writes a byte of data to the BMP085 register
short bmp085_wrreg(unsigned char reg,unsigned char data);
// Reads a byte of data from the BMP085 register
short bmp085_rdreg(unsigned char reg);

// Initialize the BMP085
#ifdef _ATXMEGA_DEVICE_
short bmp085_init(TWI_MASTER_INFO_t *twi_master,unsigned char mode);
#else
short bmp085_init(unsigned char mode);
#endif

// Reads the temperature [C]
float bmp085_temperature(void);
// Reads the pressure in [Pa]
long bmp085_pressure(void);

#pragma library bmp085_twi.lib

#endif

