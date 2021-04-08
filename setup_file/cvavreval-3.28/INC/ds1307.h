/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Maxim/Dallas Semiconductors
  DS1307 Real Time Clock using software bit-banged
  I2C bus communication, V1.1
    
  The I/O port and bits used for the SDA and
  SCL signals must be specified in the
  Project|Configure|C Compiler|Libraries|I2C menu.
*/

#ifndef _DS1307_INCLUDED_
#define _DS1307_INCLUDED_

#include <i2c.h>

#pragma used+

unsigned char rtc_read(unsigned char address);
void rtc_write(unsigned char address,unsigned char data);
void rtc_init(unsigned char rs,unsigned char sqwe,unsigned char out);
void rtc_get_time(unsigned char *hour,unsigned char *min,unsigned char *sec);
void rtc_set_time(unsigned char hour,unsigned char min,unsigned char sec);
void rtc_get_date(unsigned char *week_day, unsigned char *day,unsigned char *month,unsigned char *year);
void rtc_set_date(unsigned char week_day, unsigned char day,unsigned char month,unsigned char year);

#pragma used-

#pragma library ds1307.lib

#endif

