/*
  CodeVisionAVR C Compiler
  (C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.
  
  Writes a diagnostic message to the U(S)ART
*/

#ifndef _ASSERT_INCLUDED_
#define _ASSERT_INCLUDED_

#ifdef NDEBUG

#define assert(x)

#else

#include <stdio.h>

#define assert(x) {if (!(x)) printf("assertion error \x22%p\x22 in file \x22%p\x22, line %u\r\n",#x,__FILE__,__LINE__)}

#endif
#endif
