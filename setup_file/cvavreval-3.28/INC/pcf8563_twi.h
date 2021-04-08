/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Philips PCF8563
  Real Time Clock functions using the
  hardware Two Wire Interface (TWI).

  FOR ATxmega CHIPS THE TWI PERIPHERAL
  USED FOR COMMUNICATION WITH THE PCF8563
  CHIP MUST BE FIRST INITIALIZED, AS IN THE
  EXAMPLE BELOW:
  
  #include <pcf8563_twi.h>
  
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
  
  // set the PCF8563 functions to use TWID
  pcf8563_twi_init(&twid_master);
  
  // enable LO interrupt level
  PMIC.CTRL |= PMIC_LOLVLEN_bm;
  
  // enable interrupts
  #asm("sei")

  // now the rest of the PCF8563 functions can be used
  // initialize the PCF8563 RTC
  rtc_init(0,RTC_CLKOUT_OFF,RTC_TIMER_OFF);

  // read time from the PCF8563 RTC
  rtc_get_time(&h,&m,&s);
  
  // ....
  }
*/

#ifndef _PCF8563_TWI_INCLUDED_
#define _PCF8563_TWI_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#pragma used+
void pcf8563_twi_init(TWI_MASTER_INFO_t *ptwim);
#pragma used-
#else
#include <twi.h>
#endif

/* values used for the Control/Status2
   register bits initialization in rtc_init */
#define RTC_TIE_ON 1
#define RTC_AIE_ON 2
#define RTC_TP_ON 0x10

/* values used for the CLKOUT configuration
   register initialization in rtc_init */
#define RTC_CLKOUT_OFF 0
#define RTC_CLKOUT_1 0x83
#define RTC_CLKOUT_32 0x82
#define RTC_CLKOUT_1024 0x81
#define RTC_CLKOUT_32768 0x80

/* values used for the Timer configuration
   register initialization in rtc_init */
#define RTC_TIMER_OFF 0
#define RTC_TIMER_CLK_1_60 0x83
#define RTC_TIMER_CLK_1 0x82
#define RTC_TIMER_CLK_64 0x81
#define RTC_TIMER_CLK_4096 0x80

#pragma used+

unsigned char rtc_read(unsigned char address);
void rtc_write(unsigned char address,unsigned char data);
void rtc_init(unsigned char ctrl2,unsigned char clkout,unsigned char timer_ctrl);
unsigned char rtc_get_time(unsigned char *hour,unsigned char *min,unsigned char *sec);
void rtc_set_time(unsigned char hour,unsigned char min,unsigned char sec);
void rtc_get_date(unsigned char *day,unsigned char *month,unsigned *year);
void rtc_set_date(unsigned char day,unsigned char month,unsigned year);
void rtc_alarm_on(void);
void rtc_alarm_off(void);
void rtc_get_alarm(unsigned char *day,unsigned char *hour,unsigned char *min);
void rtc_set_alarm(unsigned char day,unsigned char hour,unsigned char min);
void rtc_set_timer(unsigned char val);

#pragma used-

#pragma library pcf8563_twi.lib

#endif

