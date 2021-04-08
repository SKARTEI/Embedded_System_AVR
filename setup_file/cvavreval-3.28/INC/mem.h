/*
  CodeVisionAVR V2.0 C Compiler
  (C) 1998-2007 Pavel Haiduc, HP InfoTech S.R.L.

  Memory access macros */

#ifndef _MEM_INCLUDED_
#define _MEM_INCLUDED_

#if __CODEVISIONAVR__ < 2000
#error CodeVisionAVR V2.0 or later compiler required
#endif

#define pokeb(addr,data) *((unsigned char *)(addr))=(data)
#define pokew(addr,data) *((unsigned int *)(addr))=(data)
#define peekb(addr) *((unsigned char *)(addr))
#define peekw(addr) *((unsigned int *)(addr))

#endif

