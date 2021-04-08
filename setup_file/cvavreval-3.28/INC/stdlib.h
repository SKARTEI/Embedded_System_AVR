/* CodeVisionAVR C Compiler V2.0
   Prototypes for standard library functions

   (C) 1998-2008 Pavel Haiduc, HP InfoTech S.R.L.
*/

#ifndef _STDLIB_INCLUDED_
#define _STDLIB_INCLUDED_

#ifndef NULL
#define NULL 0
#endif

#ifndef RAND_MAX
#define RAND_MAX 32767
#endif

#pragma used+

unsigned char cabs(signed char x);
unsigned int abs(int x);
unsigned long labs(long x);
float fabs(float x);
int atoi(char *str);
long int atol(char *str);
float atof(char *str);
void itoa(int n,char *str);
void ltoa(long int n,char *str);
void ftoa(float n,unsigned char decimals,char *str);
void ftoe(float n,unsigned char decimals,char *str);
void srand(int seed);
int rand(void);
void *malloc(unsigned int size);
void *calloc(unsigned int num, unsigned int size);
void *realloc(void *ptr, unsigned int size); 
void free(void *ptr);

#pragma used-
#pragma library stdlib.lib

#endif

