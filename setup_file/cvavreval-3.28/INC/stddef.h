/*
  CodeVisionAVR C Compiler
  (C) 1998-2008 Pavel Haiduc, HP InfoTech S.R.L.

  stddef.h standard header
*/

#ifndef _STDDEF_INCLUDED_
#define _STDDEF_INCLUDED_

#ifndef NULL
#define NULL 0
#endif

#ifndef _SIZE_T_
#define _SIZE_T_

#if defined _MODEL_MEDIUM_ | defined _MODEL_LARGE_
typedef unsigned long int size_t;
#else
typedef unsigned int size_t;
#endif

#endif

#ifndef _PTRDIFF_T_
#define _PTRDIFF_T_

#if defined _MODEL_MEDIUM_ | defined _MODEL_LARGE_
typedef long int ptrdiff_t;
#else
typedef int ptrdiff_t;
#endif

#endif

#ifndef offsetof
#define offsetof(type,member) ((size_t) (&((type *)0) -> member))
#endif

#ifndef wchar_t
#define wchar_t char
#endif

#endif
