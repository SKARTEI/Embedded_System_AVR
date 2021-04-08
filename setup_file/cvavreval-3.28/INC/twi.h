/******************************************************************************
 TWI driver library for the CodeVisionAVR C V3 Compiler
 
 Copyright (C) 2010-2015 Pavel Haiduc, HP InfoTech S.R.L., All rights reserved.
*******************************************************************************/

#ifndef _TWI_INCLUDED_
#define _TWI_INCLUDED_

#include <stdbool.h>

// TWI transaction result values
#define TWI_RES_OK 0
#define TWI_RES_BUFFER_OVERFLOW 1
#define TWI_RES_ARBITRATION_LOST 2
#define TWI_RES_BUS_ERROR 3
#define TWI_RES_NACK_RECEIVED 4
#define TWI_RES_BUS_TIMEOUT 5
#define TWI_RES_FAIL 6
#define TWI_RES_UNKNOWN 7

extern unsigned char twi_tx_index; // data index in the transmit buffer
extern unsigned char twi_rx_index; // data index in the receive buffer
extern unsigned char twi_result; // holds the result of the last TWI transaction

// TWI master initialization
// bit_rate - SCL bit rate [kHz]
void twi_master_init(unsigned int bit_rate);

// function used for performing a TWI master transaction
// slave_addr - 7 bit address of the TWI slave with which the transaction must be performed
// tx_data - pointer to the buffer that holds the data to be transmitted to the slave
// tx_count - number of bytes that must be transmitted to the slave during the transaction
// rx_data - pointer to the buffer that holds the data received from the slave
// rx_count - number of bytes that must be received from the slave during the transaction
// returns true on success
bool twi_master_trans(
     unsigned char slave_addr,
     unsigned char *tx_data, unsigned char tx_count,
     unsigned char *rx_data, unsigned char rx_count);

// TWI slave initialization
// match_any_addr - if true, the slave match address logic responds to all received addresses
// addr - 7 bit address of the TWI slave
// rx_buffer - pointer to the slave receive buffer
// rx_buffer_size - size of the slave receive buffer
// tx_buffer - pointer to the slave transmit buffer
// slave_rx_handler - pointer to the TWI slave receive processing function
// slave_tx_handler - pointer to the TWI slave transmit processing function
void twi_slave_init(
     bool match_any_addr,
     unsigned char addr,
     unsigned char *rx_buffer,
     unsigned char rx_buffer_size,
     unsigned char *tx_buffer,
     bool (*slave_rx_handler)(bool rx_complete),
     unsigned char (*slave_tx_handler)(bool tx_complete)
     );

#pragma library twi.lib

#endif
