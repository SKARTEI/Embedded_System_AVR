/*
  CodeVisionAVR C Compiler
  (C) 1998-2008 Pavel Haiduc, HP InfoTech S.R.L.

  stdint.h standard header
*/

#ifndef _STDINT_INCLUDED_
#define _STDINT_INCLUDED_

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef long int32_t;
typedef unsigned long uint32_t;

// An integer type large enough to be able to hold a pointer to RAM.
#ifdef _MODEL_TINY_
typedef signed char intptr_t;
typedef unsigned char uintptr_t;
#else
typedef short intptr_t;
typedef unsigned short uintptr_t;
#endif

// An integer type large enough to be able to hold a pointer to FLASH.
#if defined _MODEL_MEDIUM_ | defined _MODEL_LARGE_
typedef long flash_intptr_t;
typedef unsigned long flash_uintptr_t;
#else
typedef short flash_intptr_t;
typedef unsigned short flash_uintptr_t;
#endif

// An integer type large enough to be able to hold a pointer to EEPROM.
typedef short eeprom_intptr_t;
typedef unsigned short eeprom_uintptr_t;

#endif
