/************************************************
CodeVisionAVR C Compiler V3.09+
(C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

Program memory access support and Atmel Studio 6
compatibility macros/functions.
************************************************/

#ifndef _PGMSPACE_INCLUDED_
#define _PGMSPACE_INCLUDED_

#include <string.h>

#define PROGMEM flash

#ifndef PGM_P
#define PGM_P flash char *
#endif

#ifndef PGM_VOID_P
#define PGM_VOID_P flash void *
#endif

#define PSTR(s) ((flash char *)(s))

#define pgm_read_byte_near(address_short) *((flash unsigned char *)(address_short))
#define pgm_read_word_near(address_short) *((flash unsigned short *)(address_short))
#define pgm_read_dword_near(address_short) *((flash unsigned long *)(address_short))
#define pgm_read_float_near(address_short) *((flash float *)(address_short))
#define pgm_read_ptr_near(address_short) (flash void *) (*((flash unsigned short *)(address_short)))

#define pgm_read_byte_far(address_long) *((flash unsigned char *)(address_long))
#define pgm_read_word_far(address_long) *((flash unsigned short *)(address_long))
#define pgm_read_dword_far(address_long) *((flash unsigned long *)(address_long))
#define pgm_read_float_far(address_long) *((flash float *)(address_long))
#define pgm_read_ptr_far(address_long) (flash void *) (*((flash unsigned long *)(address_long)))

#define pgm_read_byte(address) *((flash unsigned char *)(address))
#define pgm_read_word(address) *((flash unsigned short *)(address))
#define pgm_read_dword(address) *((flash unsigned long *)(address))
#define pgm_read_float(address) *((flash float *)(address))
#if defined(_MODEL_TINY_) || defined(_MODEL_SMALL_)
#define pgm_read_ptr(address)  (flash void *) (*((flash unsigned short *)(address)))
#else
#define pgm_read_ptr(address)  (flash void *) (*((flash unsigned long *)(address)))
#endif

#define memcmp_P(buf1,buf2,n) memcmpf(buf1,buf2,n)
#define strcat_P(str1,str2) strcatf(str1,str2)
#define strcmp_P(str1,str2) strcmpf(str1,str2)
#define strcpy_P(dest,src) strcpyf(dest,src)
#define strcspn_P(str,set) strcspnf(str,set)
#define strlcpy_P (dest,src,n) strlcpyf(dest,src,n)
#define __strlen_P(str) strlenf(str)
#define strlen_P(str) strlenf(str)
#define strncmp_P(str1,str2,n) strncmpf(str1,str2,n)
#define strncat_P(str1,str2,n) strncatf(str1,str2,n)
#define strncpy_P(dest,src,n) strncpyf(dest,src,n)
#define strpbrk_P(str,set) strpbrkf(str,set)
#define strspn_P(str,set) strspnf(str,set)
#define strstr_P(str1,str2) strstrf(str1,str2)
#define strtok_P(str1,str2) strtok(str1,str2)

#define memcmp_PF(buf1,buf2,n) memcmpf(buf1,buf2,n)
#define strcat_PF(str1,str2) strcatf(str1,str2)
#define strcmp_PF(str1,str2) strcmpf(str1,str2)
#define strcpy_PF(dest,src) strcpyf(dest,src)
#define strcspn_PF(str,set) strcspnf(str,set)
#define strlcpy_PF (dest,src,n) strlcpyf(dest,src,n)
#define strlen_PF(str) strlenf(str)
#define strncmp_PF(str1,str2,n) strncmpf(str1,str2,n)
#define strncat_PF(str1,str2,n) strncatf(str1,str2,n)
#define strncpy_PF(dest,src,n) strncpyf(dest,src,n)
#define strpbrk_PF(str,set) strpbrkf(str,set)
#define strspn_PF(str,set) strspnf(str,set)
#define strstr_PF(str1,str2) strstrf(str1,str2)
#define strtok_PF(str1,str2) strtok(str1,str2)

#endif
