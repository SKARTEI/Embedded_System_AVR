/*
  CodeVisionAVR C Compiler
  (C) 1998-2001 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for Dallas Semiconductor
  DS2433 1 Wire bus EEPROM functions

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
    #include <ds2433.h>
*/

#ifndef _DS2433_INCLUDED_
#define _DS2433_INCLUDED_

#include <1wire.h>

#define DS2433_FAMILY_CODE 0x23

#pragma used+

// read a block of size bytes starting from memory address addr
// and stores it at dest
// returns 1 if successful, 0 if not
unsigned char ds2433_read_block(unsigned char *romcode,
unsigned char *dest,unsigned int addr,unsigned int size);
// read a byte from memory address addr and stores it at data
// returns 1 if successful, 0 if not
unsigned char ds2433_read(unsigned char *romcode,
unsigned int addr,unsigned char *data);
// write a block of size bytes, located at source,
// starting from memory address addr
// returns 1 if successful, 0 if not
unsigned char ds2433_write_block(unsigned char *romcode,
unsigned char *source,unsigned int addr,unsigned int size);
// write the byte data at memory address addr
// returns 1 if successful, 0 if not
unsigned char ds2433_write(unsigned char *romcode,unsigned int addr,
unsigned char data);

#pragma used-
#pragma library ds2433.lib

#endif

