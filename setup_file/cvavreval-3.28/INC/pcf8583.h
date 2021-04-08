/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Philips PCF8583
  Real Time Clock using software bit-banged
  I2C bus communication.
  
  The I/O port and bits used for the SDA and
  SCL signals must be specified in the
  Project|Configure|C Compiler|Libraries|I2C menu.
*/

#ifndef _PCF8583_INCLUDED_
#define _PCF8583_INCLUDED_

#include <i2c.h>

#pragma used+

extern unsigned char rtc_status;
extern bit rtc_alarm;

// for compatibility with older programs
#define __rtc_status rtc_status
#define __rtc_alarm rtc_alarm

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

#pragma library pcf8583.lib

#endif

