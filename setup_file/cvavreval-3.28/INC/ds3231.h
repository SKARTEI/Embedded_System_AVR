/*****************************************************************************
  CodeVisionAVR V3.23+ C Compiler
  (C) 2011-2015 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Maxim DS3231 Real Time Clock 
  functions using the bit-banged I2C.
*****************************************************************************/

#ifndef _DS3231_INCLUDED_
#define _DS3231_INCLUDED_

#include <stdbool.h>

/* DS3231 register definitions */
#define DS3231_SEC_REG 0x00      /* Seconds register */
#define DS3231_MIN_REG 0x01      /* Minutes register */
#define DS3231_HOUR_REG 0x02     /* Hours register */
#define DS3231_WEEK_DAY_REG 0x03 /* Week day register */
#define DS3231_DATE_REG 0x04     /* Date register */
#define DS3231_MONTH_REG 0x05    /* Month register */
#define DS3231_YEAR_REG 0x06     /* Year register */
#define DS3231_AL1SEC_REG 0x07   /* Alarm 1 seconds register */
#define DS3231_AL1MIN_REG 0x08   /* Alarm 1 minutes register */
#define DS3231_AL1HOUR_REG 0x09  /* Alarm 1 hours register */
#define DS3231_AL1DATE_REG 0x0A  /* Alarm 1 date register */
#define DS3231_AL2MIN_REG 0x0B   /* Alarm 2 minutes register */
#define DS3231_AL2HOUR_REG 0x0C  /* Alarm 2 hours register */
#define DS3231_AL2DATE_REG 0x0D  /* Alarm 2 date register */
#define DS3231_CTRL_REG 0x0E     /* Control register */
#define DS3231_STS_REG 0x0F      /* Status register */
#define DS3231_AGGING_OFFS 0x10  /* Agging offset register */
#define DS3231_AGGING_TEMP_MSB 0x11  /* Temperature MSB */
#define DS3231_AGGING_TEMP_LSB 0x12  /* Temperature LSB */

/* DS3231 control register bits definitions */
#define DS3231_CTRL_A1IE 0  /* Alarm 1 interrupt enable */
#define DS3231_CTRL_A2IE 1  /* Alarm 2 interrupt enable */
#define DS3231_CTRL_INTCN 2 /* Interrupt control */
#define DS3231_CTRL_RS1 3   /* Rate select bit 1 */
#define DS3231_CTRL_RS2 4   /* Rate select bit 2 */
#define DS3231_CTRL_CONV 5  /* Start temperature conversion */
#define DS3231_CTRL_BBSQW 6 /* Battery-Backed Square-Wave enable */
#define DS3231_CTRL_NEOSC 7 /* Enable the oscillator when set to logic 0 */

/* DS3231 status register bits definitions */
#define DS3231_STS_A1F 0      /* Alarm 1 flag */
#define DS3231_STS_A2F 1      /* Alarm 2 flag */
#define DS3231_STS_BSY 2      /* Device is busy executing TXCO functions */
#define DS3231_STS_EN32KHZ 3  /* Enable the 32kHz output */
#define DS3231_STS_OSF 7      /* A logic 1 in this bit indicates that 
                                 the oscillator either is stopped or 
                                 was stopped for some period */

/* Operating modes of the ~INT/SQW output 
   to be used by the int_sqw_mode parameter
   of the rtc_int function */
#define DS3231_INT_SQW_OFF 0 /* The ~INT/SQW output is disabled */
#define DS3231_INT_ON 1      /* A match between the timekeeping registers 
                                and either of the alarm registers 
                                activates the ~INT/SQW output 
                                (if the alarm is also enabled) */
#define DS3231_SQW_1HZ 2     /* SQW outputs a 1Hz square wave */
#define DS3231_SQW_1024HZ 3  /* SQW outputs a 1024Hz square wave */
#define DS3231_SQW_4096HZ 4  /* SQW outputs a 4096Hz square wave */
#define DS3231_SQW_8192HZ 5  /* SQW outputs a 8192Hz square wave */

/* Alarm settings */
typedef struct
{
unsigned char sec;        /* Alarm seconds value [0..59] */
unsigned char min;        /* Alarm minutes value [0..59] */
unsigned char hour;       /* Alarm hour value [0..23] */
unsigned char day;        /* Date day value [1..31] */
unsigned char use_sec:1;  /* Trigger alarm when seconds match */
unsigned char use_min:1;  /* Trigger alarm when minutes match */
unsigned char use_hour:1; /* Trigger alarm when hour match */
unsigned char use_day:1;  /* Trigger alarm when date day match */
unsigned char enabled:1;  /* Alarm interrupt is enabled */
} DS3231_ALARM_t;

#pragma used+

/* Returns the data read from the specified address of DS3231 register */
unsigned char ds3231_read(unsigned char address);

/* Writes data to the specified address of DS3231 register */
void ds3231_write(unsigned char address,unsigned char data);

/* Returns the data read from the DS3231 status register */
#define ds3231_read_status() ds3231_read(DS3231_STS_REG)


#ifdef _ATXMEGA_DEVICE_
/* Initializes the DS3231 library to use the Xmega TWI peripheral
   ptwim - points to a structure that holds the XMEGA TWI peripheral 
   information when operating in master mode */
void ds3231_twi_init(TWI_MASTER_INFO_t *ptwim);
#endif
 
/* Initializes the DS3231 RTC
   int_sqw_mode - specifies the operating modes of the ~INT/SQW output
   en32khz - enables outputing a 32kHz square wave on the 32kHz pin */
void rtc_init(unsigned char int_sqw_mode,bool en32khz);

/* Reads the current time from the DS3231 RTC
   hour - points to an unsigned char variable that will hold the hours value [0..23]
   min  - points to an unsigned char variable that will hold the minutes value [0..59]
   sec  - points to an unsigned char variable that will hold the seconds value [0..59] */
void rtc_get_time(unsigned char *hour,unsigned char *min,unsigned char *sec);

/* Sets the DS3231 RTC time
   hour - sets the hours value [0..23]
   min  - sets the minutes value [0..59]
   sec  - sets the seconds value [0..59] */
void rtc_set_time(unsigned char hour,unsigned char min,unsigned char sec);

/* Reads the current date from the DS3231 RTC
   week_day - points to an unsigned char variable that will hold the week day value [1..7]
   day - points to an unsigned char variable that will hold the date day value [1..31]
   month - points to an unsigned char variable that will hold the month value [1..12]
   year  - points to an unsigned char variable that will hold the year value [0..199] */
void rtc_get_date(unsigned char *week_day, unsigned char *day,unsigned char *month,unsigned char *year);

/* Sets the DS3231 RTC date
   week_day - sets the week day value [1..7]
   day - sets the date day value [1..31]
   month - sets the month value [1..12]
   year  - sets the year value [0..199] */
void rtc_set_date(unsigned char week_day, unsigned char day,unsigned char month,unsigned char year);

/* Sets the DS3231 RTC alarm 1
   alarm - points to a structure that holds the settings for alarm 1 */
void rtc_set_alarm1(DS3231_ALARM_t *alarm);
     
/* Reads the DS3231 RTC alarm 1 settings.
   alarm - points to a structure that will hold the settings for alarm 1 */
void rtc_get_alarm1(DS3231_ALARM_t *alarm);

/* Enables or disables DS3231 alarm 1 interrupt */
void rtc_enable_alarm1(bool alarm_on);

/* Sets the DS3231 RTC alarm 2
   alarm - points to a structure that holds the settings for alarm 2 */
void rtc_set_alarm2(DS3231_ALARM_t *alarm);

/* Reads the DS3231 RTC alarm 2 settings.
   alarm - points to a structure that will hold the settings for alarm 2 */
void rtc_get_alarm2(DS3231_ALARM_t *alarm);

/* Enables or disables DS3231 alarm 2 interrupt */
void rtc_enable_alarm2(bool alarm_on);

/* Reads the DS3231 temperature in [°C] with 0.25°C resolution */
float ds3231_get_temp(void);

#pragma used-

#pragma library ds3231.lib

#endif

