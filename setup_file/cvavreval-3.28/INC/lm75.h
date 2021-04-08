/*
  CodeVisionAVR V2.05.1+ C Compiler
  (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

  National Semiconductor LM75 temperature sensor
  functions using software bit-banged I2C bus
  communication.
  
  The I/O port and bits used for the SDA and
  SCL signals must be specified in the
  Project|Configure|C Compiler|Libraries|I2C menu.
*/

#ifndef _LM75_INCLUDED_
#define _LM75_INCLUDED_

#include <i2c.h>

#pragma used+

void lm75_init(unsigned char chip,signed char thyst,signed char tos,
unsigned char pol);
int lm75_temperature_10(unsigned char chip);

#pragma used-

#pragma library lm75.lib

#endif

