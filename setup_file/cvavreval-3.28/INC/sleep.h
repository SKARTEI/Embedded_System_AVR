/*
  CodeVisionAVR V3.0 C Compiler
  (C) 1998-2013 Pavel Haiduc, HP InfoTech S.R.L.

  Prototypes for power management functions
*/

#ifndef _SLEEP_INCLUDED_
#define _SLEEP_INCLUDED_

#include <io.h>

#define sleep_enter() #asm("sleep")

#if (defined _ATXMEGA_DEVICE_)

#define sleep_enable() {SLEEP.CTRL |= SLEEP_SEN_bm;}
#define sleep_disable() {SLEEP.CTRL &= ~SLEEP_SEN_bm;}
#define sleep_set_mode(mode) {SLEEP.CTRL = mode | (SLEEP.CTRL & ~SLEEP_SMODE_gm);}

#define __POWERDOWN_SUPPORTED__
#define __POWERSAVE_SUPPORTED__
#define __STANDBY_SUPPORTED__
#define __EXTENDED_STANDBY_SUPPORTED__

#elif (!defined __SLEEP_SUPPORTED__)

#error Power management functions not supported for this chip

#else

#pragma used+
void sleep_enable(void);
void sleep_disable(void);
#pragma used-

#endif

#pragma used+
void idle(void);

#ifdef __POWERDOWN_SUPPORTED__
void powerdown(void);
#endif

#ifdef __POWERSAVE_SUPPORTED__
void powersave(void);
#endif

#ifdef __POWEROFF_SUPPORTED__
void poweroff(void);
#endif

#ifdef __STANDBY_SUPPORTED__
void standby(void);
#endif

#ifdef __EXTENDED_STANDBY_SUPPORTED__
void extended_standby(void);
#endif
#pragma used-

#pragma library sleep.lib

#endif

