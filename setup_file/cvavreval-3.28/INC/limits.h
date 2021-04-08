/* CodeVisionAVR C Compiler
   (C) 1998-2000 Pavel Haiduc, HP InfoTech S.R.L. */

#ifndef _LIMITS_INCLUDED_
#define _LIMITS_INCLUDED_

#define CHAR_BIT         8              /* number of bits in a char */
#define MB_LEN_MAX       1              /* max. # bytes in multibyte char */

#define SCHAR_MIN       -128            /* minimum signed    char value */
#define SCHAR_MAX        127            /* maximum signed    char value */
#define UCHAR_MAX        255            /* maximum unsigned  char value */

#ifdef _UNSIGNED_CHAR_
#define CHAR_MIN         0              /* minimum           char value */
#define CHAR_MAX         255            /* maximum           char value */
#else
#define CHAR_MIN        -128            /* minimum           char value */
#define CHAR_MAX         127            /* maximum           char value */
#endif

#define SHRT_MIN       (-32767-1)       /* minimum signed   short value */
#define SHRT_MAX         32767          /* maximum signed   short value */
#define USHRT_MAX        0xFFFF         /* maximum unsigned short value */
#define INT_MIN        (-32767-1)       /* minimum signed     int value */
#define INT_MAX          32767          /* maximum signed     int value */
#define UINT_MAX         0xFFFF         /* maximum unsigned   int value */
#define LONG_MIN       (-2147483647L-1) /* minimum signed    long value */
#define LONG_MAX         2147483647L    /* maximum signed    long value */
#define ULONG_MAX        0xFFFFFFFF     /* maximum unsigned  long value */

#endif

