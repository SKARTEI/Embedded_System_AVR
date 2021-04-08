/************************************************
CodeVisionAVR C Compiler V3.09+
(C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

EEPROM access support and Atmel Studio 6
compatibility macros/functions.
************************************************/

#ifndef _EEPROM_INCLUDED_
#define _EEPROM_INCLUDED_

#define EEMEM eeprom

#define eeprom_read_byte(addr) *(eeprom unsigned char *) (addr)
#define eeprom_read_word(addr) *(eeprom unsigned short *) (addr)
#define eeprom_read_dword(addr) *(eeprom unsigned long *) (addr)
#define eeprom_read_float(addr) *(eeprom float *) (addr)
#ifdef _MODEL_TINY_
void eeprom_read_block(void *dst,eeprom void *src,unsigned char n);
#else
void eeprom_read_block(void *dst,eeprom void *src,unsigned short n);
#endif

#define eeprom_write_byte(addr,value) {*(eeprom unsigned char *) (addr)=(value);}
#define eeprom_write_word(addr,value) {*(eeprom unsigned short *) (addr)=(value);}
#define eeprom_write_dword(addr,value) {*(eeprom unsigned long *) (addr)=(value);}
#define eeprom_write_float(addr,value) {*(eeprom float *) (addr)=(value);}
#ifdef _MODEL_TINY_
void eeprom_write_block(void *src,eeprom void *dst,unsigned char n);
#else
void eeprom_write_block(void *src,eeprom void *dst,unsigned short n);
#endif

#define eeprom_update_byte(addr,value) {*(eeprom unsigned char *) (addr)=(value);}
#define eeprom_update_word(addr,value) {*(eeprom unsigned short *) (addr)=(value);}
#define eeprom_update_dword(addr,value) {*(eeprom unsigned long *) (addr)=(value);}
#define eeprom_update_float(addr,value) {*(eeprom float *) (addr)=(value);}
#define eeprom_update_block(src,dst,n) eeprom_write_block(src,dst,n)

#pragma library eeprom.lib

#endif
