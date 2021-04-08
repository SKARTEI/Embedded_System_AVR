//*****************************************************************************
// Bosch Sensortec BMP180 Digital Pressure Sensor functions
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

#ifndef _BMP180_INCLUDED_
#define _BMP180_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#else
#include <twi.h>
#endif

// BMP180 I2C bus address
#define BMP180_I2C_ADDR 0x77

#define BMP180_CHIP_ID_REG 0xD0 // Chip ID register
#define BMP180_SOFT_RESET_REG 0xE0 // Software Reset register

#define BMP180_CTRL_MEAS_REG 0xF4    // Control & Measurement register
#define BMP180_ADC_OUT_MSB_REG 0xF6  // Read ADC Result register MSB
#define BMP180_ADC_OUT_LSB_REG 0xF7  // Read ADC Result register LSB
#define BMP180_ADC_OUT_XLSB_REG 0xF8 // Read ADC Result register XLSB

// Addresses of BMP180 calibration parameters
#define	BMP180_CALIB_PARAM_AC1_MSB 0xAA
#define	BMP180_CALIB_PARAM_AC1_LSB 0xAB
#define BMP180_CALIB_PARAM_AC2_MSB 0xAC
#define BMP180_CALIB_PARAM_AC2_LSB 0xAD
#define	BMP180_CALIB_PARAM_AC3_MSB 0xAE
#define	BMP180_CALIB_PARAM_AC3_LSB 0xAF
#define	BMP180_CALIB_PARAM_AC4_MSB 0xB0
#define	BMP180_CALIB_PARAM_AC4_LSB 0xB1
#define	BMP180_CALIB_PARAM_AC5_MSB 0xB2
#define	BMP180_CALIB_PARAM_AC5_LSB 0xB3
#define	BMP180_CALIB_PARAM_AC6_MSB 0xB4
#define	BMP180_CALIB_PARAM_AC6_LSB 0xB5
#define	BMP180_CALIB_PARAM_B1_MSB 0xB6
#define	BMP180_CALIB_PARAM_B1_LSB 0xB7
#define	BMP180_CALIB_PARAM_B2_MSB 0xB8
#define	BMP180_CALIB_PARAM_B2_LSB 0xB9
#define	BMP180_CALIB_PARAM_MB_MSB 0xBA
#define	BMP180_CALIB_PARAM_MB_LSB 0xBB
#define	BMP180_CALIB_PARAM_MC_MSB 0xBC
#define	BMP180_CALIB_PARAM_MC_LSB 0xBD
#define	BMP180_CALIB_PARAM_MD_MSB 0xBE
#define	BMP180_CALIB_PARAM_MD_LSB 0xBF

// Chip ID for BMP180
#define BMP180_CHIP_ID 0x55
// Soft Reset register command for reseting chip 
#define BMP180_SOFT_RESET_CMD 0xB6 
// Control register value for measuring temperature
#define BMP180_CTRL_TEMP 0x2E
// Control register value for measuring pressure
#define BMP180_CTRL_PRES 0x34

// BMP180 pressure measurement modes (conversion time)
#define BMP180_ULTRA_LOW_POWER_MODE 0 // Ultra Low Power Mode (5ms)
#define BMP180_STANDARD_MODE 1     // Standard Mode (8ms)
#define BMP180_HI_RES_MODE 2       // High Resolution Mode (14ms)
#define BMP180_ULTRA_HI_RES_MODE 3 // Ultra High Resolution Mode (26ms)
#define BMP180_ADVANCED_RES_MODE 4 // Advanced Resolution Mode (76ms)

// Return values for the BMP180 functions:
#define BMP180_INIT_OK 0         // The initialization was successful
#define BMP180_COMM_ERROR -32768 // TWI communication with the device has failed
#define BMP180_INIT_ERROR -32767 // TWI initialization parameters are not correct
#define BMP180_CALIB_ERROR -32766 // The calibration data read from the device PROM is not correct

// Structure that holds BMP180 calibration parameters
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
} BMP180_CALIB_PARAM_t;

extern BMP180_CALIB_PARAM_t bmp180_calib_param;

// Writes a byte of data to the BMP180 register
short bmp180_wrreg(unsigned char reg,unsigned char data);
// Reads a byte of data from the BMP180 register
short bmp180_rdreg(unsigned char reg);

// Initialize the BMP180
#ifdef _ATXMEGA_DEVICE_
short bmp180_init(TWI_MASTER_INFO_t *twi_master,unsigned char mode);
#else
short bmp180_init(unsigned char mode);
#endif

// Reads the temperature [C]
float bmp180_temperature(void);
// Reads the pressure in [Pa]
long bmp180_pressure(void);

#pragma library bmp180_twi.lib

#endif

