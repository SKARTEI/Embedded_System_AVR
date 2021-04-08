/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Philips PCF8563
  Real Time Clock using software bit-banged
  I2C communication.
  
  The I/O port and bits used for the SDA and
  SCL signals must be specified in the
  Project|Configure|C Compiler|Libraries|I2C menu.
*/

#ifndef _PCF8563_INCLUDED_
#define _PCF8563_INCLUDED_

#include <i2c.h>

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

#pragma library pcf8563.lib

#endif

