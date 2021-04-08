// CodeVisionAVR C Compiler
// (C) 1998-2007 Pavel Haiduc, HP InfoTech S.R.L.

// Prototypes for character type functions

#ifndef _CTYPE_INCLUDED_
#define _CTYPE_INCLUDED_

#pragma used+

unsigned char isalnum(char c);
unsigned char isalpha(char c);
unsigned char isascii(char c);
unsigned char iscntrl(char c);
unsigned char isdigit(char c);
unsigned char islower(char c);
unsigned char isprint(char c);
unsigned char ispunct(char c);
unsigned char isspace(char c);
unsigned char isupper(char c);
unsigned char isxdigit(char c);
unsigned char toint(char c);
char tolower(char c);
char toupper(char c);
#define toascii(c) ((c) & 0x7f) 

#pragma used-

#pragma library ctype.lib

#endif

