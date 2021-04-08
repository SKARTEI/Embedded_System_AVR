/*
  CodeVisionAVR V2.04.5 C Compiler
  (C) 1998-2010 Pavel Haiduc, HP InfoTech S.R.L.

  Prototype for SPI access function */

#ifndef _SPI_INCLUDED_
#define _SPI_INCLUDED_

#ifdef _ATXMEGA_DEVICE_
// SPIC will be used as default SPI controller for the ATxmega chips
#ifndef _ATXMEGA_SPI_
#define _ATXMEGA_SPI_ SPIC
#endif

// PORTC will be used as default SPI I/O port for the ATxmega chips
#ifndef _ATXMEGA_SPI_PORT_
#define _ATXMEGA_SPI_PORT_ PORTC
#endif

#include <io.h>
#include <stdbool.h>

// macro used to set the SS pin high
#define spi_master_ss_high(_pinBM) (_ATXMEGA_SPI_PORT_.OUTSET=(_pinBM))
// macro used to set the SS pin low
#define spi_master_ss_low(_pinBM) (_ATXMEGA_SPI_PORT_.OUTCLR=(_pinBM))

#pragma used+
void spi_init(bool master_mode,bool lsb_first,SPI_MODE_t mode,bool clk2x,SPI_PRESCALER_t clock_div,unsigned char ss_pin);
#pragma used-

#endif

#pragma used+
unsigned char spi(unsigned char data);
#pragma used-

#pragma library spi.lib
#endif

