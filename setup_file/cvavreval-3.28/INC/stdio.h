// CodeVisionAVR V3.25+ C Compiler
// (C) 1998-2016 Pavel Haiduc, HP InfoTech S.R.L.

// Prototypes for standard I/O functions

#ifndef _STDIO_INCLUDED_
#define _STDIO_INCLUDED_

#include <io.h>
#include <stdarg.h>

#ifndef NULL
#define NULL 0
#endif

#ifndef EOF
#define EOF -1
#endif

#pragma used+

#ifdef _ALTERNATE_GETCHAR_9BIT_
unsigned int getchar(void);
#else
char getchar(void);
#endif

#ifdef _ALTERNATE_PUTCHAR_9BIT_
void putchar(unsigned int c);
#else
void putchar(char c);
#endif

void puts(char *str);
void putsf(char flash *str);
int printf(char flash *fmtstr,...);
int sprintf(char *str, char flash *fmtstr,...);
int vprintf(char flash * fmtstr, va_list argptr);
int vsprintf(char *str, char flash * fmtstr, va_list argptr);

#ifdef _MODEL_TINY_
char *gets(char *str,unsigned char len);
int snprintf(char *str, unsigned char size, char flash *fmtstr,...);
int vsnprintf(char *str, unsigned char size, char flash * fmtstr, va_list argptr);
#else
char *gets(char *str,unsigned int len);
int snprintf(char *str, unsigned int size, char flash *fmtstr,...);
int vsnprintf(char *str, unsigned int size, char flash * fmtstr, va_list argptr);
#endif

// for compatibility with C11
#define get_s(str,len) gets((str),(len))

int scanf(char flash *fmtstr,...);
int sscanf(char *str, char flash *fmtstr,...);

#ifdef _USE_FATFS_
// try to first include the header file from the project directory, 18052012_2
#include "ff.h" 
int fgetc(FIL *fp);
char *fgets(char *str,unsigned int len,FIL *fp);

#if !_FS_READONLY // 29092014_1
int fputc(char k,FIL* fp);
int fputs(char *str,FIL* fp);
int fputsf(char flash *str,FIL* fp);
int fprintf(FIL *fp, char flash *fmtstr,...);
int fvprintf(FIL *fp, char flash *fmtstr, va_list argptr); // 24012016_2
#endif

int fscanf(FIL *fp, char flash *fmtstr,...);
unsigned char feof(FIL* fp);
unsigned char ferror(FIL *fp);
#endif

// USARTC0 will be used as default USART for the ATxmega chips
#ifdef _ATXMEGA_DEVICE_
#ifndef _ATXMEGA_USART_
#define _ATXMEGA_USART_ USARTC0
#endif
#endif

#pragma used-

#pragma library stdio.lib

#endif

