/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Philips PCF8583
  Real Time Clock functions using the
  hardware Two Wire Interface (TWI).

  FOR ATxmega CHIPS THE TWI PERIPHERAL
  USED FOR COMMUNICATION WITH THE PCF8583
  CHIP MUST BE FIRST INITIALIZED, AS IN THE
  EXAMPLE BELOW:
  
  #include <pcf8583_twi.h>
  
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
  
  // set the PCF8583 functions to use TWID
  pcf8583_twi_init(&twid_master);
  
  // enable LO interrupt level
  PMIC.CTRL |= PMIC_LOLVLEN_bm;
  
  // enable interrupts
  #asm("sei")

  // now the rest of the PCF8583 functions can be used
  // initialize the PCF8583 RTC
  rtc_init(0,0);

  // read time from the PCF8583 RTC
  rtc_get_time(0,&h,&m,&s);
  
  // ....
  }
*/

#ifndef _PCF8583_TWI_INCLUDED_
#define _PCF8583_TWI_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#pragma used+
void pcf8583_twi_init(TWI_MASTER_INFO_t *ptwim);
#pragma used-
#else
#include <twi.h>
#endif

#pragma used+

extern unsigned char rtc_status;
extern bit rtc_alarm;

unsigned char rtc_read(unsigned char chip,unsigned char address);
void rtc_write(unsigned char chip, unsigned char address,unsigned char data);
unsigned char rtc_get_status(unsigned char chip);
void rtc_init(unsigned char chip,unsigned char dated_alarm);
void rtc_alarm_off(unsigned char chip);
void rtc_alarm_on(unsigned char chip);
void rtc_get_time(unsigned char chip,unsigned char *hour,unsigned char *min,
unsigned char *sec,unsigned char *hsec);
void rtc_set_time(unsigned char chip,unsigned char hour,unsigned char min,
unsigned char sec,unsigned char hsec);
void rtc_get_date(unsigned char chip,unsigned char *day,unsigned char *month,
unsigned *year);
void rtc_set_date(unsigned char chip,unsigned char day,unsigned char month,
unsigned year);
void rtc_get_alarm_time(unsigned char chip,unsigned char *hour,
unsigned char *min,unsigned char *sec,unsigned char *hsec);
void rtc_set_alarm_time(unsigned char chip,unsigned char hour,
unsigned char min,unsigned char sec,unsigned char hsec);
void rtc_get_alarm_date(unsigned char chip,unsigned char *day,
unsigned char *month);
void rtc_set_alarm_date(unsigned char chip,unsigned char day,
unsigned char month);

#pragma used-

#pragma library pcf8583_twi.lib

#endif

