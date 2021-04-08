/******************************************************************************
  CodeVisionAVR C Compiler
  (C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

  Non-local jump functions
******************************************************************************/

#ifndef _SETJMP_INCLUDED_
#define _SETJMP_INCLUDED_

// 21052014_1, 21052014_2
#if defined (_CHIP_ATXMEGA128A1_) || defined (_CHIP_ATXMEGA128A1U_) || \
    defined (_CHIP_ATXMEGA128A3_) || defined (_CHIP_ATXMEGA128A3U_) || \
    defined (_CHIP_ATXMEGA128A4_) || defined (_CHIP_ATXMEGA128A4U_) || \
    defined (_CHIP_ATXMEGA128B1_) || defined (_CHIP_ATXMEGA128B3_) || \
    defined (_CHIP_ATXMEGA128C3_) || \
    defined (_CHIP_ATXMEGA128D3_) || defined (_CHIP_ATXMEGA128D4_) || \
    defined (_CHIP_ATXMEGA192A1_) || defined (_CHIP_ATXMEGA192A3_) || \
    defined (_CHIP_ATXMEGA192A3U_) || defined (_CHIP_ATXMEGA192C3_) || \
    defined (_CHIP_ATXMEGA192D3_) || defined (_CHIP_ATXMEGA256A1_) || \
    defined (_CHIP_ATXMEGA256A3_) || defined (_CHIP_ATXMEGA256A3U_) || \
    defined (_CHIP_ATXMEGA256A3B_) || defined (_CHIP_ATXMEGA256A3BU_) || \
    defined (_CHIP_ATXMEGA256C3_) || defined (_CHIP_ATXMEGA256D3_) || \
    defined (_CHIP_ATXMEGA384C3_) || defined (_CHIP_ATXMEGA384D3_) || \
    defined (_CHIP_ATMEGA2560_) || defined (_CHIP_ATMEGA2560V_) || \
    defined (_CHIP_ATMEGA2561_) || defined (_CHIP_ATMEGA2561V_) || \
    defined (_CHIP_ATMEGA256RFR2_)
typedef char jmp_buf[11];
#else
typedef char jmp_buf[9];
#endif

int setjmp(char *env);
void longjmp(char *env, int retval);

#pragma library setjmp.lib

#endif
