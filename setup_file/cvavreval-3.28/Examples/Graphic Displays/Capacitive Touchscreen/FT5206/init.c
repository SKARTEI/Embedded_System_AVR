/* Peripheral initialization */

#include <io.h>

/* System Clocks initialization */
void system_clocks_init(void)
{
unsigned char n,s;

/* Optimize for speed */
#pragma optsize- 
/* Save interrupts enabled/disabled state */
s=SREG;
/* Disable interrupts */
#asm("cli")

/* Internal 32 kHz RC oscillator initialization
   Enable the internal 32 kHz RC oscillator */
OSC.CTRL|=OSC_RC32KEN_bm;
/* Wait for the internal 32 kHz RC oscillator to stabilize */
while ((OSC.STATUS & OSC_RC32KRDY_bm)==0);

/* Internal 32 MHz RC oscillator initialization
   Enable the internal 32 MHz RC oscillator */
OSC.CTRL|=OSC_RC32MEN_bm;

/* System Clock prescaler A division factor: 1
   System Clock prescalers B & C division factors: B:1, C:1
   ClkPer4: 32000.000 kHz
   ClkPer2: 32000.000 kHz
   ClkPer:  32000.000 kHz
   ClkCPU:  32000.000 kHz */
n=(CLK.PSCTRL & (~(CLK_PSADIV_gm | CLK_PSBCDIV1_bm | CLK_PSBCDIV0_bm))) |
	CLK_PSADIV_1_gc | CLK_PSBCDIV_1_1_gc;
CCP=CCP_IOREG_gc;
CLK.PSCTRL=n;

/* Select the system clock source: 32 MHz Internal RC Osc. */
n=(CLK.CTRL & (~CLK_SCLKSEL_gm)) | CLK_SCLKSEL_RC32M_gc;
CCP=CCP_IOREG_gc;
CLK.CTRL=n;

/* Disable the unused oscillators: 2 MHz, external clock/crystal oscillator, PLL */
OSC.CTRL&= ~(OSC_RC2MEN_bm | OSC_XOSCEN_bm | OSC_PLLEN_bm);

/* Peripheral Clock output: Disabled */
PORTCFG.CLKEVOUT=(PORTCFG.CLKEVOUT & (~PORTCFG_CLKOUT_gm)) | PORTCFG_CLKOUT_OFF_gc;

/* Restore interrupts enabled/disabled state */
SREG=s;
/* Restore optimization for size if needed */
#pragma optsize_default
}
