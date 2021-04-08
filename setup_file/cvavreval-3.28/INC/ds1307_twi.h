/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Maxim/Dallas Semiconductors
  DS1307 Real Time Clock functions using the
  hardware Two Wire Interface (TWI).
    
  FOR ATxmega CHIPS THE TWI PERIPHERAL
  USED FOR COMMUNICATION WITH THE DS1307
  CHIP MUST BE FIRST INITIALIZED, AS IN THE
  EXAMPLE BELOW:
  
  #include <ds1307_twi.h>
  
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
  unsigned char h,m,s;

  // general TWID initialization
  // no external driver interface
  // no SDA hold time
  twi_init(&TWID,false,false);

  // initialize the TWID master
  twi_master_init(&twid_master,&TWID,TWI_MASTER_INTLVL_LO_gc,TWI_BAUD_REG(_MCU_CLOCK_FREQUENCY_,TWI_CLK_RATE));
  
  // set the DS1307 functions to use TWID
  ds1307_twi_init(&twid_master);
  
  // enable LO interrupt level
  PMIC.CTRL |= PMIC_LOLVLEN_bm;
  
  // enable interrupts
  #asm("sei")

  // now the rest of the DS1307 functions can be used
  // initialize the DS1307 RTC
  rtc_init(0,0,0);

  // read time from the DS1307 RTC
  rtc_get_time(&h,&m,&s);
  
  // ....
  }
   
*/

#ifndef _DS1307_TWI_INCLUDED_
#define _DS1307_TWI_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#pragma used+
void ds1307_twi_init(TWI_MASTER_INFO_t *ptwim);
#pragma used-
#else
#include <twi.h>
#endif

#pragma used+

unsigned char rtc_read(unsigned char address);
void rtc_write(unsigned char address,unsigned char data);
void rtc_init(unsigned char rs,unsigned char sqwe,unsigned char out);
void rtc_get_time(unsigned char *hour,unsigned char *min,unsigned char *sec);
void rtc_set_time(unsigned char hour,unsigned char min,unsigned char sec);
void rtc_get_date(unsigned char *week_day, unsigned char *day,unsigned char *month,unsigned char *year);
void rtc_set_date(unsigned char week_day, unsigned char day,unsigned char month,unsigned char year);

#pragma used-

#pragma library ds1307_twi.lib

#endif

