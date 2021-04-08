/*************************************************************************
CodeVisionAVR C Compiler V3.00
(C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.

ATxmega Peripheral Modules helper structures definitions
*************************************************************************/

#ifndef __XMSTRUCT_INCLUDED__
#define __XMSTRUCT_INCLUDED__


typedef volatile unsigned char register8_t;
typedef volatile unsigned int register16_t;
typedef volatile unsigned long register32_t;

#define _SFR_MEM8(r) (*(register8_t *) (r))
#define _SFR_MEM16(r) (*(register16_t *) (r))

#define _WORDREGISTER(register_name) union\
        {\
        register16_t register_name;\
        struct\
             {\
             register8_t register_name ## L;\
             register8_t register_name ## H;\
             };\
        }

#define _DWORDREGISTER(register_name) union\
        {\
        register32_t register_name;\
        struct\
             {\
             register8_t register_name ## 0;\
             register8_t register_name ## 1;\
             register8_t register_name ## 2;\
             register8_t register_name ## 3;\
             };\
        }

#ifndef ADCACAL0_offset
#define ADCACAL0_offset 0x20
#endif

#ifndef ADCACAL1_offset
#define ADCACAL1_offset 0x21
#endif

#ifndef ADCBCAL0_offset
#define ADCBCAL0_offset 0x24
#endif

#ifndef ADCBCAL1_offset
#define ADCBCAL1_offset 0x25
#endif

// for compatibility with new V3.0 headers
#define FDEVMASK FDEMASK

#endif
