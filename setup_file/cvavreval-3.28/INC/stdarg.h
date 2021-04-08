// CodeVisionAVR C Compiler V2.0
// (C) 1998-2007 Pavel Haiduc, HP InfoTech S.R.L.

// Variable length argument list macros

#ifndef _STDARG_INCLUDED_
#define _STDARG_INCLUDED_

#ifndef NULL
#define NULL 0
#endif

typedef char *va_list;

#define va_start(ap,v) ap=(va_list) &v-sizeof(long)
#define va_arg(ap,t) (ap-=sizeof(long), (t) ((long *) ap)[1])
#define va_end(ap)

#endif
 