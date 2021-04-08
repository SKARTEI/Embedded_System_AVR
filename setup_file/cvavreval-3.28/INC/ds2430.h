/*
  CodeVisionAVR C Compiler
  (C) 1998-2001 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for Dallas Semiconductor
  DS2430 1 Wire bus EEPROM functions

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
    #include <ds2430.h>
*/

#ifndef _DS2430_INCLUDED_
#define _DS2430_INCLUDED_

#include <1wire.h>

#define DS2430_FAMILY_CODE 0x14

#pragma used+

// read a block of size bytes starting from memory address addr
// and stores it at dest
// returns 1 if successful, 0 if not
unsigned char ds2430_read_block(unsigned char *romcode,
unsigned char *dest,unsigned char addr,unsigned char size);
// read a byte from memory address addr and stores it at data
// returns 1 if successful, 0 if not
unsigned char ds2430_read(unsigned char *romcode,
unsigned char addr,unsigned char *data);
// write a block of size bytes, located at source,
// starting from memory address addr
// returns 1 if successful, 0 if not
unsigned char ds2430_write_block(unsigned char *romcode,
unsigned char *source,unsigned char addr,unsigned char size);
// write the byte data at memory address addr
// returns 1 if successful, 0 if not
unsigned char ds2430_write(unsigned char *romcode,
unsigned char addr,unsigned char data);
// read a block of size bytes, starting from application
// register address addr and stores it at dest
// returns 1 if successful, 0 if not
unsigned char ds2430_read_appreg_block(unsigned char *romcode,
unsigned char *dest,unsigned char addr,unsigned char size);
// write a block of size bytes, located at source,
// starting from application register address addr
// returns 1 if successful, 0 if not
unsigned char ds2430_write_appreg_block(unsigned char *romcode,
unsigned char *source,unsigned char addr,unsigned char size);

#pragma used-
#pragma library ds2430.lib

#endif

