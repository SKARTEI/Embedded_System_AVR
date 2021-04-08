/***************************************************************************
Ultrachip UC1610 Graphic LCD controller demo
(C) Copyright 2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

The demo is designed to run on an ATxmega128A1
XPlained development board with chip clock of 32 MHz.

A DOGXL160W-7 160x104 graphic LCD module from
Electronic Assembly www.lcd-module.de is used 
for the purpose of this demo.
The UC1610 controller is used in 4 wire serial mode 
connection.

The graphic LCD module connections are:

Pin 19  VB1-  ---
                 |
               ===== 1uF/25V
               =====
                 | +
Pin 20  VB1+  ---

Pin 18  VB0-  ---
                 |
               ===== 1uF/25V
               =====
                 | +
Pin 21  VB0+  ---

Pin 17  VLCD  ---
                 |
               ===== 1uF/25V
               =====
                 |
                === GND

Pin 22 VDD      - +3.3V
Pin 23 VDD2/3   - +3.3V
Pin 24 VSS2     - GND
Pin 25 VSS      - GND

Pin 26 BM0      - GND
Pin 27 CD       - PORTD bit 2
Pin 28 /CS0     - PORTD bit 3
Pin 29 /RST     - PORTD bit 4
Pin 30 D6       - GND
Pin 31 SDA      - PORTD bit 0
Pin 32 SCK      - PORTD bit 1

Make sure to specify the correct connections in the
Project|Configure|C Compiler|Libraries|Graphic LCD menu.

This program exceeds the code size limit of the Evaluation
version of CodeVisionAVR.
In this case you can program the ATxmega128A1 FLASH with
the contents of the
\EXAMPLES\Graphic LCD\UC1610 EA DOGXL160-7\Serial\Release\Exe\Full_Demo.hex
file.
***************************************************************************/

#include <io.h>
#include <glcd.h>
#include <delay.h>

/* Include some fonts needed by the demo */
#include <font5x7.h>
#include "arial14.h"
#include "arial_bold14.h"
#include "courier7x14.h"
#include "courier_bold14.h"
#include "script19.h"

/* Small dots filling pattern */
flash unsigned char small_dots[]={0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55};

/* EEPROM buffer used for image storage */
eeprom unsigned char buffer[1000];

/* Hexagon point coordinates
   The last point's coordinates must match
   the first point coordinates,
   so that the polygon will be closed */
flash GLCDPOINT_t hexagon[7]=
{
{40,0},
{57,10},
{57,30},
{40,40},
{23,30},
{23,10},
{40,0}
};

/* System Clocks initialization */
void system_clocks_init(void)
{
unsigned char n,s;

// Optimize for speed
#pragma optsize-
// Save interrupts enabled/disabled state
s=SREG;
// Disable interrupts
#asm("cli")

// Internal 32 kHz RC oscillator initialization
// Enable the internal 32 kHz RC oscillator
OSC.CTRL|=OSC_RC32KEN_bm;
// Wait for the internal 32 kHz RC oscillator to stabilize
while ((OSC.STATUS & OSC_RC32KRDY_bm)==0);

// Internal 32 MHz RC oscillator initialization
// Enable the internal 32 MHz RC oscillator
OSC.CTRL|=OSC_RC32MEN_bm;

// System Clock prescaler A division factor: 1
// System Clock prescalers B & C division factors: B:1, C:1
// ClkPer4: 32000.000 kHz
// ClkPer2: 32000.000 kHz
// ClkPer:  32000.000 kHz
// ClkCPU:  32000.000 kHz
n=(CLK.PSCTRL & (~(CLK_PSADIV_gm | CLK_PSBCDIV1_bm | CLK_PSBCDIV0_bm))) |
    CLK_PSADIV_1_gc | CLK_PSBCDIV_1_1_gc;
CCP=CCP_IOREG_gc;
CLK.PSCTRL=n;

// Internal 32 MHz RC osc. calibration reference clock source: 32.768 kHz Internal Osc.
OSC.DFLLCTRL&= ~(OSC_RC32MCREF_bm | OSC_RC2MCREF_bm);
// Enable the autocalibration of the internal 32 MHz RC oscillator
DFLLRC32M.CTRL|=DFLL_ENABLE_bm;

// Wait for the internal 32 MHz RC oscillator to stabilize
while ((OSC.STATUS & OSC_RC32MRDY_bm)==0);

// Select the system clock source: 32 MHz Internal RC Osc.
n=(CLK.CTRL & (~CLK_SCLKSEL_gm)) | CLK_SCLKSEL_RC32M_gc;
CCP=CCP_IOREG_gc;
CLK.CTRL=n;

// Disable the unused oscillators: 2 MHz, external clock/crystal oscillator, PLL
OSC.CTRL&= ~(OSC_RC2MEN_bm | OSC_XOSCEN_bm | OSC_PLLEN_bm);

// Peripheral Clock output: Disabled
PORTCFG.CLKEVOUT=(PORTCFG.CLKEVOUT & (~PORTCFG_CLKOUT_gm)) | PORTCFG_CLKOUT_OFF_gc;

// Restore interrupts enabled/disabled state
SREG=s;
// Restore optimization for size if needed
#pragma optsize_default
}

void main()
{
GLCDINIT_t init;

system_clocks_init();

/* 5x7 font is used */
init.font=font5x7;

/* No need for reading data from external memory */
init.readxmem=NULL;

/* No need for reading data from external memory */
init.writexmem=NULL;

/* Set horizontal scan direction: normal */
init.reverse_x=UC1610_REVX_NORM;
/* Set vertical scan direction: normal */
init.reverse_y=UC1610_REVY_NORM;
/* Set LCD temperature compensation coeficient */
init.temp_comp=UC1610_DEFAULT_TEMP_COMP;
/* Set LCD panel capacitance */
init.panel_cap=UC1610_DEFAULT_PANEL_CAP;
/* Set LCD bias voltage ratio */
init.lcd_bias=UC1610_DEFAULT_LCD_BIAS;
/* Set LCD contrast */
init.contrast=UC1610_DEFAULT_LCD_CONTRAST;

/* Initialize the LCD controller and graphics */
glcd_init(&init);

/* Display literal char string located in FLASH */
glcd_outtextf("UC1610 Graphics Demo\nFont samples:");

/* Display some font samples */
glcd_outtextxyf(0,20,"Standard 5x7");

glcd_setfont(arial14);
glcd_outtextxyf(0,28,"Arial 14");

glcd_setfont(arial_bold14);
glcd_outtextxyf(0,40,"Arial Bold 14");

glcd_setfont(courier7x14);
glcd_outtextxyf(0,52,"Courier 7x14");

glcd_setfont(courier_bold14);
glcd_outtextxyf(0,64,"Courier Bold 14");

glcd_setfont(script19);
glcd_outtextxyf(0,76,"Script 19");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

glcd_setfont(font5x7);
glcd_outtextf("Variable text spacing:\n\n");
glcd_setfont(courier_bold14);
glcd_outtextf("CodeVisionAVR\n");

/* Set horizontal justification: 2 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(2,1);
glcd_outtextf("CodeVisionAVR\n");

/* Set horizontal justification: 3 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(3,1);
glcd_outtextf("CodeVisionAVR\n");

/* Set horizontal justification: 4 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(4,1);
glcd_outtextf("CodeVisionAVR\n");

/* Set horizontal justification: 5 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(5,1);
glcd_outtextf("CodeVisionAVR");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

/* Set horizontal justification: 1 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(1,1);
glcd_setfont(font5x7);
glcd_outtextf("Some line styles:");

/* Draw various styles of lines */
/* Line thickness: 1 pixel */
glcd_line(0,14,159,14);

glcd_setlinestyle(1,GLCD_LINE_DOT_SMALL);
glcd_line(0,19,159,19);

glcd_setlinestyle(1,GLCD_LINE_DOT_LARGE);
glcd_line(0,24,159,24);

/* Line thickness: 2 pixels */
glcd_setlinestyle(2,GLCD_LINE_SOLID);
glcd_line(0,29,159,29);

glcd_setlinestyle(2,GLCD_LINE_DOT_SMALL);
glcd_line(0,34,159,34);

glcd_setlinestyle(2,GLCD_LINE_DOT_LARGE);
glcd_line(0,39,159,39);

/* Line thickness: 4 pixels */
glcd_setlinestyle(4,GLCD_LINE_SOLID);
glcd_line(0,44,159,44);

glcd_setlinestyle(4,GLCD_LINE_DOT_SMALL);
glcd_line(0,49,159,49);

glcd_setlinestyle(4,GLCD_LINE_DOT_LARGE);
glcd_line(0,54,159,54);

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

/* Draw a hexagon with line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
glcd_drawpoly(7,hexagon);

/* 1 second delay */
delay_ms(1000);

/* Fill the hexagon with solid fill */
glcd_floodfill(48,24,1);

/* Write a text inside the filled hexagon in
   reversed colors */
glcd_setcolor(0);
glcd_setbkcolor(1);
glcd_outtextxyf(30,17,"Fill");

/* Save hexagon image in EEPROM */
glcd_getimagee(22,0,37,41,buffer);
/* Restore the default foreground
   and background colors */
glcd_setcolor(1);
glcd_setbkcolor(0);
glcd_outtextxyf(0,47,"Image was saved to EEPROM");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

/* Draw a circle with line thickness: 1 pixel */
glcd_circle(21,23,20);

/* Draw an arc of a circle with line thickness: 1 pixel */
glcd_arc(21,23,0,120,15);

/* Draw a circle with line thickness: 3 pixels */
glcd_setlinestyle(3,GLCD_LINE_SOLID);
glcd_circle(63,23,20);

/* Draw an arc of a circle with line thickness: 3 pixels */
glcd_arc(63,23,0,210,15);

glcd_outtextxyf(0,47,"Circles & arcs");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

/* Draw a rectangle with line thickness: 1 pixel
   and solid line */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
glcd_rectrel(0,0,40,25);

/* Draw a rectangle with line thickness: 3 pixel
   and dotted line */
glcd_setlinestyle(3,GLCD_LINE_DOT_LARGE);
glcd_rectrel(42,0,40,25);

/* Draw a bar filled with a pattern */
glcd_setfillf(small_dots,1);
glcd_bar(14,29,70,44);

glcd_outtextxyf(0,47,"Rectangles & filled bar");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

/* Draw rounded rectangle */
glcd_rectround(5,0,74,38,8);
glcd_outtextxyf(0,41,"Rounded rectangle");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

/* Set line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID);

/* Draw filled pie slice */
glcd_pieslice(39,39,30,300,30);

/* Set the fill color to background color,
   so that the pie slice will not be filled */
glcd_setfillcolor(glcd_getbkcolor());

/* Draw not filled pie slice */
glcd_pieslice(104,39,30,300,30);
glcd_outtextxyf(15,74,"Pie slices");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

glcd_outtextf("Put\nimage\nfrom\nEEPROM:");
/* Display image saved in EEPROM */
glcd_putimagee(56,0,buffer,GLCD_PUTCOPY);

glcd_outtextxyf(0,48,"Put\ninverted\nimage\nfrom\nEEPROM:");
/* Display image saved in EEPROM,
   using bitwise negation */
glcd_putimagee(56,48,buffer,GLCD_PUTNOT);
}
