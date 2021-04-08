/*
  CodeVisionAVR C Compiler
  (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for Dallas Semiconductor
  DS1820 1 Wire bus temperature sensor
  functions

  BEFORE #include -ING THIS FILE YOU
  MUST DECLARE THE I/O ADDRESS OF THE
  DATA REGISTER OF THE PORT AT WHICH
  THE 1 WIRE BUS IS CONNECTED AND
  THE DATA BIT USED

  EXAMPLE FOR PORTB:

    #asm
        .equ __w1_port=0x18
        .equ __w1_bit=3
    #endasm
    #include <ds1820.h>
*/

#ifndef _DS1820_INCLUDED_
#define _DS1820_INCLUDED_

#include <1wire.h>

#define DS1820_FAMILY_CODE 0x10
#define DS1820_SEARCH_ROM_CMD 0xf0
#define DS1820_ALARM_SEARCH_CMD 0xec

#pragma used+
extern struct __ds1820_scratch_pad_struct
       {
       unsigned char temp_lsb,temp_msb;
       signed char   temp_high,temp_low;
       unsigned char res1,res2,
                     cnt_rem,cnt_c,
                     crc;
       } __ds1820_scratch_pad;

unsigned char ds1820_select(unsigned char *addr);
unsigned char ds1820_read_spd(unsigned char *addr);
int ds1820_temperature_10(unsigned char *addr);
unsigned char ds1820_set_alarm(unsigned char *addr,signed char temp_low,signed char temp_high);
#pragma used-

#pragma library ds1820.lib

#endif

