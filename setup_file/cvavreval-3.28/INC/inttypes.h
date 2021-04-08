/*
  CodeVisionAVR C Compiler
  (C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

  inttypes.h standard header
*/

#ifndef _INTTYPES_INCLUDED_
#define _INTTYPES_INCLUDED_

#include <stdint.h>

typedef int32_t int_farptr_t;
typedef uint32_t uint_farptr_t;

#define		PRId8			"d"
#define		PRIi8			"i"
#define		PRId16			"d"
#define		PRIi16			"i"
#define		PRId32			"ld"
#define		PRIi32			"li"
#define		PRId64			"lld"
#define		PRIi64			"lli"
#define		PRIdMAX			"lld"
#define		PRIiMAX			"lli"

#define		PRIdPTR			PRId16
#define		PRIiPTR			PRIi16

#define		PRIu8			"u"
#define		PRIx8			"x"
#define		PRIX8			"X"
#define		PRIu16			"u"
#define		PRIx16			"x"
#define		PRIX16			"X"
#define		PRIu32			"lu"
#define		PRIx32			"lx"
#define		PRIX32			"lX"

#define		PRIu64			"llu"
#define		PRIx64			"llx"
#define		PRIX64			"llX"
#define		PRIuMAX			"llu"
#define		PRIxMAX			"llx"
#define		PRIXMAX			"llX"

#define		PRIuPTR			PRIu16
#define		PRIxPTR			PRIx16
#define		PRIXPTR			PRIX16

#define		SCNd16			"d"
#define		SCNi16			"i"
#define		SCNd32			"ld"
#define		SCNi32			"li"

#define		SCNd64			"lld"
#define		SCNi64			"lli"
#define		SCNdMAX			"lld"
#define		SCNiMAX			"lli"

#define		SCNdPTR			SCNd16
#define		SCNiPTR			SCNi16

#define		SCNu16			"u"
#define		SCNx16			"x"
#define		SCNu32			"lu"
#define		SCNx32			"lx"

#define		SCNu64			"llu"
#define		SCNx64			"llx"
#define		SCNuMAX			"llu"
#define		SCNxMAX			"llx"

#define		SCNuPTR			SCNu16
#define		SCNxPTR			SCNx16

#endif
