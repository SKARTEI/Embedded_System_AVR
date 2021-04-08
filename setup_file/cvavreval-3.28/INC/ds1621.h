/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for the Maxim/Dallas Semiconductor
  DS1621 I2C bus thermometer/thermostat
  functions using software bit-banged I2C bus
  communication.

  The I/O port and bits used for the SDA and
  SCL signals must be specified in the
  Project|Configure|C Compiler|Libraries|I2C menu.
*/

#ifndef _DS1621_INCLUDED_
#define _DS1621_INCLUDED_

#include <i2c.h>

#pragma used+

void ds1621_init(unsigned char chip,signed char tlow,signed char thigh,
unsigned char pol);
unsigned char ds1621_get_status(unsigned char chip);
void ds1621_set_status(unsigned char chip,unsigned char status);
void ds1621_start(unsigned char chip);
void ds1621_stop(unsigned char chip);
int ds1621_temperature_10(unsigned char chip);

#pragma used-
#pragma library ds1621.lib

#endif

