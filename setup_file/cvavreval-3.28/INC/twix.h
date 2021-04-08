/***********************************************************************************
 ATxmega TWI driver library for the CodeVisionAVR C V2.05.6+ Compiler
 
 Copyright (C) 2010-2012 Pavel Haiduc and HP InfoTech S.R.L., All rights reserved.
***********************************************************************************/

#ifndef _TWIX_INCLUDED_
#define _TWIX_INCLUDED_
 
#include <stdbool.h>
#include <string.h>
#include <io.h>

// TWI module general initialization
// module - pointer to the TWI peripheral module to be initialized
// ext_driver - enable using an external driver interface
// sda_hold - enable an internal hold time on SDA with respect to the
// SCL negative edge
void twi_init(TWI_t *module,bool ext_driver_intf,unsigned char sda_hold);

// TWI master definitions & functions

// structure that holds information used by the TWI master
// for performing a TWI bus transaction
typedef struct
{
TWI_t *module;                // ptr. to the used TWI interface module 
unsigned char slave_address;  // I2C slave address
unsigned char *tx_buffer;     // ptr. to transmit buffer
unsigned char bytes_to_tx;    // number of bytes to transmit to the slave
unsigned char tx_counter;     // number of transmitted bytes
unsigned char *rx_buffer;     // ptr. to receive buffer
unsigned char bytes_to_rx;    // number of bytes to receive from the slave
unsigned char rx_counter;     // number of received bytes
unsigned char result;         // transaction result
} TWI_MASTER_INFO_t;

// TWI master transaction result values
#define TWIM_RES_UNKNOWN 0
#define TWIM_RES_OK 1
#define TWIM_RES_BUFFER_OVERFLOW 2
#define TWIM_RES_ARBITRATION_LOST 3
#define TWIM_RES_BUS_ERROR 4
#define TWIM_RES_NACK_RECEIVED 5
#define TWIM_RES_FAIL 6

// macro used for calculating the value of the BAUD register for the desired
// TWI clock rate TWI_CLK_RATE [bps] based on the System Clock SYS_CLK [Hz]
#define TWI_BAUD_REG(SYS_CLK,TWI_CLK_RATE) (((SYS_CLK)/((TWI_CLK_RATE)*2))-5)

// TWI master initialization
// twi - pointer to the structure that holds information used by the TWI master
// for performing a TWI bus transaction
// module - pointer to the TWI peripheral module to be initialized as TWI master
// int_level - interrupt priority level to be used for TWI master
// baud_reg - initialization value for the TWI master BAUD register
void twi_master_init(
     TWI_MASTER_INFO_t *twi,
     TWI_t *module,
     TWI_MASTER_INTLVL_t int_level,
     unsigned char baud_reg);
     
// TWI master interrupt handler
// twi - pointer to the structure that holds information used by the TWI master
void twi_master_int_handler(TWI_MASTER_INFO_t *twi);

// function used for performing a TWI master transaction
// twi - pointer to the structure that holds information used by the TWI master
// slave_addr - 7 bit address of the TWI slave with which the transaction must be performed
// tx_data - pointer to the buffer that holds the data to be transmitted to the slave
// tx_count - number of bytes that must be transmitted to the slave during the transaction
// rx_data - pointer to the buffer that holds the data received from the slave
// rx_count - number of bytes that must be received from the slave during the transaction
// returns true on success
bool twi_master_trans(
     TWI_MASTER_INFO_t *twi,
     unsigned char slave_addr,
     unsigned char *tx_data, unsigned char tx_count,
     unsigned char *rx_data, unsigned char rx_count);

// TWI slave definitions & functions
     
// structure that holds information used by the TWI slave
// for performing a TWI bus transaction
typedef struct
{
TWI_t *module;                // ptr. to the used TWI interface module
unsigned char *rx_buffer;     // ptr. to receive buffer
unsigned char rx_buffer_size; // receive buffer size
unsigned char rx_index;       // index in the receive buffer of the last received byte
unsigned char *tx_buffer;     // ptr. to transmit buffer
unsigned char tx_index;       // index in the transmit buffer of the last transmitted byte
unsigned char bytes_to_tx;    // number of bytes to transmit to the master
void (*twi_trans) (void);     // pointer to TWI slave transaction processing function
unsigned result;              // transaction result
} TWI_SLAVE_INFO_t;

// TWI slave transaction result values
#define TWIS_RES_UNKNOWN 0
#define TWIS_RES_OK 1
#define TWIS_RES_ADDR_MATCH 2
#define TWIS_RES_BUFFER_OVERFLOW 3
#define TWIS_RES_TRANSMIT_COLLISION 4
#define TWIS_RES_BUS_ERROR 5
#define TWIS_RES_FAIL 6
#define TWIS_RES_HALT 7

// TWI slave initialization
// twi - pointer to the structure that holds information used by the TWI slave
// for performing a TWI bus transaction
// module - pointer to the TWI peripheral module to be initialized as TWI slave
// int_level - interrupt priority level to be used for TWI slave
// match_any_addr - if true, the slave match address logic responds to all received addresses
// addr - 7 bit address of the TWI slave
// addr_mask_reg - value for the SLAVE.ADDRMASK register:
//                 if bit 0=0 -> bits 1..7 = slave address bit mask
//                 if bit 0=1 -> bits 1..7 = second slave address
// rx_buffer - pointer to the slave receive buffer
// rx_buffer_size - size of the slave receive buffer
// tx_buffer - pointer to the slave transmit buffer
// twi_slave_trans - pointer to the TWI slave transaction processing function
void twi_slave_init(
     TWI_SLAVE_INFO_t *twi,
     TWI_t *module,
     TWI_SLAVE_INTLVL_t int_level,
     bool match_any_addr,
     unsigned char addr,
     unsigned char addr_mask_reg,
     unsigned char *rx_buffer,
     unsigned char rx_buffer_size,
     unsigned char *tx_buffer,
     void (*twi_slave_trans)(void));
     
// TWI slave interrupt handler
// twi - pointer to the structure that holds information used by the TWI slave 
void twi_slave_int_handler(TWI_SLAVE_INFO_t *twi);

// function used to halt a TWI slave transaction
// twi - pointer to the structure that holds information used by the TWI slave 
void twi_slave_halt_trans(TWI_SLAVE_INFO_t *twi);

#pragma library twix.lib
          
#endif
