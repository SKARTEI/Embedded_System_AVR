// CodeVisionAVR C Compiler V3.25+
// (C) 1998-2016 Pavel Haiduc, HP InfoTech S.R.L.

// Prototypes for string functions

#ifndef _STRING_INCLUDED_
#define _STRING_INCLUDED_

#ifndef NULL
#define NULL 0
#endif

#pragma used+

char *strcat(char *str1,char *str2);
char *strcatf(char *str1,char flash *str2);
char *strchr(char *str,char c);
flash char *strchrf(flash char *str,char c); // 23012016_2
signed char strcmp(char *str1,char *str2);
signed char strcmpf(char *str1,char flash *str2);
char *strcpy(char *dest,char *src);
char *strcpyf(char *dest,char flash *src);
unsigned char strlcpy(char *dest,char *src,unsigned char n);	// safe replacement of strncpy
unsigned char strlcpyf(char *dest,char flash *src,unsigned char n); // safe replacement of strncpyf
unsigned int strlenf(char flash *str);
char *strncat(char *str1,char *str2,unsigned char n);
char *strncatf(char *str1,char flash *str2,unsigned char n);
signed char strncmp(char *str1,char *str2,unsigned char n);
signed char strncmpf(char *str1,char flash *str2,unsigned char n);
char *strncpy(char *dest,char *src,unsigned char n);
char *strncpyf(char *dest,char flash *src,unsigned char n);
char *strpbrk(char *str,char *set);
char *strpbrkf(char *str,char flash *set);
char *strrchr(char *str,char c);
flash char *strrchrf(flash char *str,char c); // 23012016_2
char *strrpbrk(char *str,char *set);
char *strrpbrkf(char *str,char flash *set);
char *strstr(char *str1,char *str2);
char *strstrf(char *str1,char flash *str2);
char *strtok(char *str1,char flash *str2);
 
#ifdef _MODEL_TINY_
unsigned char strlen(char *str);
void *memccpy(void *dest,void *src,char c,unsigned char n);
void *memchr(void *buf,unsigned char c,unsigned char n);
signed char memcmp(void *buf1,void *buf2,unsigned char n);
signed char memcmpf(void *buf1,void flash *buf2,unsigned char n);
void *memcpy(void *dest,void *src,unsigned char n);
void *memcpyf(void *dest,void flash *src,unsigned char n);
void *memmove(void *dest,void *src,unsigned char n);
void *memset(void *buf,unsigned char c,unsigned char n);
unsigned char strcspn(char *str,char *set);
unsigned char strcspnf(char *str,char flash *set);
signed char strpos(char *str,char c);
signed char strrpos(char *str,char c);
unsigned char strspn(char *str,char *set);
unsigned char strspnf(char *str,char flash *set);
#else
unsigned int strlen(char *str);
void *memccpy(void *dest,void *src,char c,unsigned n);
void *memchr(void *buf,unsigned char c,unsigned n);
signed char memcmp(void *buf1,void *buf2,unsigned n);
signed char memcmpf(void *buf1,void flash *buf2,unsigned n);
void *memcpy(void *dest,void *src,unsigned n);
void *memcpyf(void *dest,void flash *src,unsigned n);
void *memmove(void *dest,void *src,unsigned n);
void *memset(void *buf,unsigned char c,unsigned n);
unsigned int strcspn(char *str,char *set);
unsigned int strcspnf(char *str,char flash *set);
int strpos(char *str,char c);
int strrpos(char *str,char c);
unsigned int strspn(char *str,char *set);
unsigned int strspnf(char *str,char flash *set);
#endif

#pragma used-
#pragma library string.lib

#endif

