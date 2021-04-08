//*****************************************************************************
// Measurement Specialties MS5611 Digital Pressure Sensor functions
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

#ifndef _MS5611_TWI_INCLUDED_
#define _MS5611_TWI_INCLUDED_

#include <stdbool.h>

#ifdef _ATXMEGA_DEVICE_
// TWI for Xmega chips
#include <twix.h>
#else
// TWI for non-Xmega chips
#include <twi.h>
#endif

// MS5611 7-bit I2C bus addresses
#define MS5611_BUS_ADDR_CSB_LOW  0x77 // for CSB pin=0
#define MS5611_BUS_ADDR_CSB_HIGH 0x76 // for CSB pin=1

// MS5611 ADC Over-Sampling Ratio
#define MS5611_OSR_256 0x00  // OSR=256
#define MS5611_OSR_512 0x01  // OSR=512
#define MS5611_OSR_1024 0x02 // OSR=1024
#define MS5611_OSR_2048 0x03 // OSR=2048
#define MS5611_OSR_4096 0x04 // OSR=4096

// Return values for the MS5611 functions:
#define MS5611_INIT_OK 0         // The initialization was successful
#define MS5611_COMM_ERROR -32768 // TWI communication with the device has failed
#define MS5611_INIT_ERROR -32767 // TWI initialization parameters are not correct
#define MS5611_CRC_ERROR  -32766 // The CRC of calibration data read from the device PROM is not correct

// Initializes the MS5611 library variables, issues a Reset command
// and reads the calibration data from the device PROM,
// checking its CRC
#ifdef _ATXMEGA_DEVICE_
// Xmega chips
short ms5611_init(TWI_MASTER_INFO_t *twi_master, unsigned char device_address, unsigned char osr);
#else
// non-Xmega chips
short ms5611_init(unsigned char device_address, unsigned char osr);
#endif

// Measures the temperature [C] with 0.01C resolution
float ms5611_temperature(void);
// Measures the pressure [Pa]
long ms5611_pressure(void);

#pragma library ms5611_twi.lib

#endif


