/*
  CodeVisionAVR C Compiler
  (C) 2001 Pavel Haiduc, HP InfoTech S.R.L.

  Gray code conversion functions
*/

#ifndef _GRAY_INCLUDED_
#define _GRAY_INCLUDED_

#pragma used+

unsigned char gray2binc(unsigned char n);
unsigned int gray2bin(unsigned int n);
unsigned long gray2binl(unsigned long n);
unsigned char bin2grayc(unsigned char n);
unsigned int bin2gray(unsigned int n);
unsigned long bin2grayl(unsigned long n);

#pragma used-
#pragma library gray.lib

#endif
