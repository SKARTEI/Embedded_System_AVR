/************************************************
CodeVisionAVR C Compiler V3.0
(C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

AVR Interrupt support and Atmel Studio 6
compatibility macros/functions.
************************************************/ 

#ifndef _INTERRUPT_INCLUDED_
#define _INTERRUPT_INCLUDED_

#include <io.h>

#define sei() #asm("sei")
#define cli() #asm("cli")
#define __enable_interrupt() #asm("sei")
#define __disable_interrupt() #asm("cli")
#define cpu_irq_enable() #asm("sei")
#define cpu_irq_disable() #asm("cli")
#define ISR(vector) interrupt [vector] void __isr##vector (void)

typedef unsigned char irqflags_t;

#pragma warn-
static inline unsigned char cpu_irq_save(void)
{
irqflags_t flags = SREG;
__disable_interrupt();
return flags;
}
#ifdef _WARNINGS_ON_
#pragma warn+
#endif

#define cpu_irq_restore(flags) {SREG = flags;}

#ifdef _ATXMEGA_DEVICE_

#define irq_initialize_vectors() {PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;}
#define cpu_irq_is_enabled_flags(flags) (flags & CPU_I_bm);

#else

#define cpu_irq_is_enabled_flags(flags) (flags & (1<<SREG_I));

#endif

#define cpu_irq_is_enabled() cpu_irq_is_enabled_flags(SREG)

#endif

