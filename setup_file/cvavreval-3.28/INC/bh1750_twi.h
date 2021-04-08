//*****************************************************************************
// ROHM Semiconductor BH1750FVI Ambient Light Sensor functions
// (C) 2015 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.26+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00
// 29022016_1 - Initial release.
//*****************************************************************************

#ifndef _BH1750_INCLUDED_
#define _BH1750_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#else
#include <twi.h>
#endif

#include <stdbool.h>

// BH1750FVI 7-bit I2C bus addresses
#define BH1750_I2C_ADDR0 0x23 // ADDR pin=0
#define BH1750_I2C_ADDR1 0x5C // ADDR pin=1

// BH1750FVI commands
#define BH1750_POWER_DOWN 0x00     // Power down
#define BH1750_POWER_ON 0x01       // Power on, wait for a measurement command
#define BH1750_RESET 0x07          // Reset the data register
#define BH1750_CONT_CONV_LOW_RES 0x13   // Use continous measurement mode (typ. 16ms) with low resolution (4lx)
#define BH1750_CONT_CONV_HIGH_RES 0x10  // Use continous measurement mode (typ. 120ms) with high resolution (1lx)
#define BH1750_CONT_CONV_HIGH_RES2 0x11 // Use continous measurement mode 2 (typ. 120ms) with high resolution (0.5lx)
#define BH1750_SINGLE_CONV_LOW_RES 0x23   // Use single measurement mode (typ. 16ms) with low resolution (4lx)
#define BH1750_SINGLE_CONV_HIGH_RES 0x20  // Use single measurement mode (typ. 120ms) with high resolution (1lx)
#define BH1750_SINGLE_CONV_HIGH_RES2 0x21 // Use single measurement mode 2 (typ. 120ms) with high resolution (0.5lx)
#define BH1750_MEAS_TIME_LOW_BITS 0x60  // Set bits 0..4 of measurement time register
#define BH1750_MEAS_TIME_HIGH_BITS 0x40 // Set bits 5..7 of measurement time register

#define BH1750_MT_REG_DEFAULT 0x45 // Default value for measurement time register

// Return values for the bh1750_init, bh1750_start, bh1750_rdlight  functions:
#define BH1750_RES_OK 0      // The command was successful
#define BH1750_COMM_ERROR -1 // TWI communication with the device has failed
#define BH1750_INIT_ERROR -2 // Initialization was not perfomed correctly

// Writes a command to the BH1750TVI.
// device_address - BH1750FVI 7-bit I2C bus address
// cmd  - command to be written
// Returns: true - command has succeeded
//          false - TWI communication error with the device.
bool bh1750_wrcmd(unsigned char device_address, unsigned char cmd);

// Initialize the BH1750
#ifdef _ATXMEGA_DEVICE_
// Initialize the BH1750.
// twi_master  - pointer to the structure that holds 
//               information used by the TWI master
//               XMEGA module, used for communication with 
//               the pressure sensor, for performing a 
//               TWI bus transaction
// device_address - BH1750FVI 7-bit I2C bus address
// mt_reg - initialization value for measurement time register: 31..254
// Returns:
// BH1750_RES_OK      - the initialization has succeeded
// BH1750_INIT_ERROR  - TWI was not initialized before calling the function
// BH1750_COMM_ERROR  - TWI communication error with the device
signed char bh1750_init(TWI_MASTER_INFO_t *twi_master, unsigned char device_address, unsigned char mt_reg);
#else
// Initialize the BH1750.
// device_address - BH1750FVI 7-bit I2C bus address
// mt_reg - initialization value for measurement time register: 31..254
// Returns:
// BH1750_RES_OK      - the initialization has succeeded
// BH1750_INIT_ERROR  - TWI was not initialized before calling the function
// BH1750_COMM_ERROR  - TWI communication error with the device
signed char bh1750_init(unsigned char device_address, unsigned char mt_reg);
#endif

// Starts an illuminance measurement.
// device_address - BH1750FVI 7-bit I2C bus address
// mode - measurement mode: BH1750_CONT_LOW_RES..BH1750_SINGLE_HIGH_RES2
// Returns:
// BH1750_RES_OK - Measurement started successfuly
// BH1750_COMM_ERROR - TWI communication with the device has failed
// BH1750_INIT_ERROR - Device initialization was not perfomed before calling the function
signed char bh1750_start(unsigned char device_address, unsigned char mode);

// Reads the result in [lx] of an illuminance measurement, 
// previously started using the bh1750_start function.
// device_address - BH1750FVI 7-bit I2C bus address
// Returns:
// zero or positive value - read has succeeded
// BH1750_COMM_ERROR - TWI communication with the device has failed
// BH1750_INIT_ERROR - Device initialization was not perfomed before calling the function
float bh1750_rdlight(unsigned char device_address);

#pragma library bh1750_twi.lib

#endif

