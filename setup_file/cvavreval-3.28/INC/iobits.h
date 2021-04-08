/************************************************** 
  CodeVisionAVR C Compiler V3.08+
  (C) 1998-2013 Pavel Haiduc, HP InfoTech S.R.L.

  I/O register bit manipulation macros
**************************************************/

#ifndef _IOBITS_INCLUDED_
#define _IOBITS_INCLUDED_

#if __CODEVISIONAVR__ < 2047
// _ATXMEGA_DEVICE_ not defined in older compilers
#error iobits.h requires CodeVisionAVR V2.04.7 of later
#endif

#define __BM(b) (1 << (b))
#define __BV(b) __BM(b)

#ifdef _ATXMEGA_DEVICE_
// I/O port bit manipulation for ATxmega devices
#define __CONCAT(a,b) a##b // concatenate 2 strings
// set port bit b, atomic
// example: SETBIT(PORTA.OUT,5)
#define SETBIT(port,b) {__CONCAT(port,SET) = __BM(b);}
// clear port bit b, atomic
#define CLRBIT(port,b) {__CONCAT(port,CLR) = __BM(b);}
// toggle port bit b, atomic
#define TGLBIT(port,b) {__CONCAT(port,TGL) = __BM(b);}
#else
// I/O port bit manipulation for non-ATxmega AVR devices
// set port bit b, atomic for sfr port address <= 0x1F
// example: SETBIT(PORTA,5)
#define SETBIT(port,b) {(port) |= __BM(b);}
// clear port bit b, atomic for sfr port address <= 0x1F
#define CLRBIT(port,b) {(port) &= ~__BM(b);}
// toggle port bit b
#define TGLBIT(port,b) {(port) ^= __BM(b);}
#endif

// set port bit b to value
#define EQUBIT(port,b,value) {if (value) SETBIT(port,b) else CLRBIT(port,b);}
// test port bit b, returns 0 or 1
#define TSTBIT(port,b) ((port & __BM(b)) != 0)

#endif
