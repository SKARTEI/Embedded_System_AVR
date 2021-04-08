/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Maxim/Dallas Semiconductor
  DS1621 I2C bus thermometer/thermostat
  functions using the hardware Two Wire Interface (TWI).

  FOR ATxmega CHIPS THE TWI PERIPHERAL
  USED FOR COMMUNICATION WITH THE DS1621
  CHIP MUST BE FIRST INITIALIZED, AS IN THE
  EXAMPLE BELOW:
  
  #include <ds1621_twi.h>
  
  // TWI clock rate [bps]
  #define TWI_CLK_RATE 100000

  // structure that holds information used by the TWID master
  // for performing a TWI bus transaction
  TWI_MASTER_INFO_t twid_master;

  interrupt [TWID_TWIM_vect] void twid_master_isr(void)
  {
  twi_master_int_handler(&twid_master);
  }

  void main(void)
  {
  // general TWID initialization
  // no external driver interface
  // no SDA hold time
  twi_init(&TWID,false,false);

  // initialize the TWID master
  twi_master_init(&twid_master,&TWID,TWI_MASTER_INTLVL_LO_gc,TWI_BAUD_REG(_MCU_CLOCK_FREQUENCY_,TWI_CLK_RATE));
  
  // set the DS1621 functions to use TWID
  ds1621_twi_init(&twid_master);
  
  // enable LO interrupt level
  PMIC.CTRL |= PMIC_LOLVLEN_bm;
  
  // enable interrupts
  #asm("sei")

  // now the rest of the DS1621 functions can be used
  // initialize the DS1621
  ds1621_init(0,20,25,0);

  // ....
  }
*/

#ifndef _DS1621_TWI_INCLUDED_
#define _DS1621_TWI_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#pragma used+
void ds1621_twi_init(TWI_MASTER_INFO_t *ptwim);
#pragma used-
#else
#include <twi.h>
#endif

#pragma used+

void ds1621_init(unsigned char chip,signed char tlow,signed char thigh,
unsigned char pol);
unsigned char ds1621_get_status(unsigned char chip);
void ds1621_set_status(unsigned char chip,unsigned char status);
void ds1621_start(unsigned char chip);
void ds1621_stop(unsigned char chip);
int ds1621_temperature_10(unsigned char chip);

#pragma used-

#pragma library ds1621_twi.lib

#endif

