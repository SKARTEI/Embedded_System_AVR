/*
  CodeVisionAVR C Compiler
  (C) 1998-2007 Pavel Haiduc, HP InfoTech S.R.L.

  BCD conversion functions
*/

#ifndef _BCD_INCLUDED_
#define _BCD_INCLUDED_

#pragma used+

unsigned char bcd2bin(unsigned char n);
unsigned char bin2bcd(unsigned char n);

#pragma used-

#pragma library bcd.lib

#endif
