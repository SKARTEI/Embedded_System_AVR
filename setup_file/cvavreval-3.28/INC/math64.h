//*****************************************************************************
// 64-bit integer math library
// (C) 2014-2015 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.21+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00
// 29042015_1 - Initial release.
//*****************************************************************************

#ifndef _MATH64_INCLUDED_
#define _MATH64_INCLUDED_

typedef struct
{
unsigned long lo;
long hi;
} long64_t;

typedef struct
{
unsigned long lo;
unsigned long hi;
} ulong64_t;

// Macro used for initializing a 64-bit long64_t or ulong64_t
// variable with a numeral n during declaration
// example: long64_t abc=__INIT64(12345678900000LL);
#define __INIT64(n) {(n)&0xFFFFFFFF,(n)>>32}
// Macro used for assigning a numeral n to
// a 64-bit long64_t or ulong64_t variable x
// example: __EQU64(abc,12345678900000LL); // abc=12345678900000LL;
#define __EQU64(x,n) ((unsigned long *) &(x))[0]=((n)&0xFFFFFFFF),((unsigned long *) &(x))[1]=((n)>>32) 
// Macro used for casting a 8 byte variable to long64_t type
#define __LONG64(x) (*((long64_t *) &(x)))
// Macro used for casting a 8 byte variable to ulong64_t type
#define __ULONG64(x) (*((ulong64_t *) &(x)))

// Assigns 32-bit signed long to 64-bit signed integer
long64_t tolong64(long x);
// Assigns 32-bit unsigned long to 64-bit unsigned integer
ulong64_t tolong64u(unsigned long x);
// Returns -x 
long64_t neg64(long64_t x);
// Returns the absolute value of x
ulong64_t abs64(long64_t x);
// Returns ~x
ulong64_t com64(ulong64_t x);
// Returns !x
ulong64_t not64(ulong64_t x);
// Returns -1, 0 or 1 if the 64-bit signed integer x is negative, zero or positive
signed char sign64(long64_t x);
// Compares two 64-bit signed integers
// Returns 1 for x>y, 0 for x==y, -1 for x<y
signed char cmp64(long64_t x, long64_t y);
// Compares two 64-bit unsigned integers
// Returns 1 for x>y, 0 for x==y, -1 for x<y
signed char cmp64u(ulong64_t x, ulong64_t y);
// Returns x+y
long64_t add64(long64_t x, long64_t y);
// Returns x-y
long64_t sub64(long64_t x, long64_t y);
// Returns signed x*y
long64_t mul64(long64_t x, long64_t y);
// Returns unsigned x*y
ulong64_t mul64u(ulong64_t x, ulong64_t y);
// Returns signed x/y
long64_t div64(long64_t x, long64_t y);
// Returns unsigned x/y
ulong64_t div64u(ulong64_t x, ulong64_t y);
// Returns signed x%y
long64_t mod64(long64_t x, long64_t y);
// Returns unsigned x%y
ulong64_t mod64u(ulong64_t x, ulong64_t y);
// Returns unsigned x | y
ulong64_t or64(ulong64_t x, ulong64_t y);
// Returns unsigned x & y
ulong64_t and64(ulong64_t x, ulong64_t y);
// Returns unsigned x ^ y
ulong64_t xor64(ulong64_t x, ulong64_t y);
// Arithmetic shift right *x=*x >> n
void asr64(long64_t *x, unsigned char n);
// Logic shift right *x=*x >> n
void lsr64(ulong64_t *x, unsigned char n);
// Logic shift left *x=*x << n
void lsl64(ulong64_t *x, unsigned char n);
// Increments a 64-bit signed integer pointed by *x
// *x=*x+1
void inc64(long64_t *x);
// Decrements a 64-bit signed integer pointed by *x
// *x=*x-1
void dec64(long64_t *x);
// Returns the square root of a 64-bit unsigned integer
unsigned long sqrt64(ulong64_t x);
// Converts the string str, containing a decimal number, 
// to a 64-bit signed integer
long64_t atol64(char *str);
// Converts the string str, containing a hexadecimal number, 
// to a 64-bit unsigned integer
ulong64_t xtol64(char *str);
// Converts the 64-bit signed integer x to characters in string str
// in decimal representation
void ltoa64(long64_t x, char *str);
// Converts the 64-bit unsigned integer x to characters in string str
// in hexadecimal representation
void ltox64(ulong64_t x, char *str);
// Outputs the 64-bit signed integer in decimal format, 
// using the 'putchar' function (stdio.h)
void printl64(long64_t x);
// Outputs the 64-bit unsigned integer in hexadecimal format, 
// using the 'putchar' function (stdio.h)
void printx64(ulong64_t x);

#pragma library math64.lib

#endif
