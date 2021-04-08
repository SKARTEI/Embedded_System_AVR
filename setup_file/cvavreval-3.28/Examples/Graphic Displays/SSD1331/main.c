/*********************************************************************
Solomon Systech SSD1331 Graphic controller demo
(C) Copyright 2011-2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

The demo is designed to run on an ATxmega128A1
XPlained development board with chip clock of 32 MHz.

An Univision Technology UG-9664HDDAG01 96x64 OLED 
color display module was used for the purpose of this demo.

The display module connections using the 8080 parallel interface are:
DB0    - PORTA bit 0
DB1    - PORTA bit 1
DB2    - PORTA bit 2
DB3    - PORTA bit 3
DB4    - PORTA bit 4
DB5    - PORTA bit 5
DB6    - PORTA bit 6
DB7    - PORTA bit 7

/RES   - PORTD bit 0
/CS    - PORTD bit 1
D/C    - PORTD bit 2
/RD    - PORTD bit 3
/WR    - PORTD bit 4

VSS    - GND
VDD    - +3.3V decoupled with 10uF/16V tantalum capacitor to GND
VDDIO  - +3.3V decoupled with 10uF/16V tantalum capacitor to GND
VCC    - +14V decoupled with 10uF/25V tantalum capacitor to GND

VCOMH  - decoupled with 4.7uF/16V tantalum capacitor to GND
IREF   - 1.2 Mohm resistor to GND

Set signals to use 8-bit 8080 parallel interface mode:
BS1    - +3.3V
BS2    - +3.3V

Make sure to specify the correct connections in the
Project|Configure|C Compiler|Libraries|Graphic LCD menu.

This program exceeds the code size limit of the Evaluation
version of CodeVisionAVR.
In this case you can program the ATxmega128A1 FLASH with
the contents of the
\EXAMPLES\Graphic Displays\SSD1331\Release\Exe\Full Demo.hex
file.
*********************************************************************/

#include <io.h>
#include <glcd.h>
#include <delay.h>
/* Meter functions */
#include "meter.h"
/* Bar-graph gauge functions */
#include "bargraph.h"
/* Include some fonts needed by the demo */
#include <font5x7.h>
#include "arial14.h"
#include "arial_bold14.h"
#include "courier7x14.h"
#include "courier_bold14.h"
#include "script19.h"

/* Small dots filling pattern */
flash unsigned char small_dots[]={0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55};

/* Solid filling pattern */
flash unsigned char solid_fill[]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

/* RAM buffer used for image storage */
unsigned char buffer[3100];

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

flash GLCDCOL_t colors[]=
{
GLCD_CL_WHITE,
GLCD_CL_GRAY,
GLCD_CL_LIGHT_GRAY,
GLCD_CL_GREEN,
GLCD_CL_LIME,
GLCD_CL_BLUE,
GLCD_CL_RED,
GLCD_CL_AQUA,
GLCD_CL_YELLOW,
GLCD_CL_MAGENTA,
GLCD_CL_CYAN,
GLCD_CL_DARK_CYAN,
GLCD_CL_ORANGE,
GLCD_CL_PINK,
GLCD_CL_BROWN,
GLCD_CL_VIOLET,
GLCD_CL_SILVER,
GLCD_CL_GOLD,
GLCD_CL_NAVY,
GLCD_CL_MAROON,
GLCD_CL_PURPLE,
GLCD_CL_OLIVE
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
unsigned char i;
int x,y;
meter_t meter;
bargraph_t bargraph;
GLCDINIT_t glcd_init_data;

system_clocks_init();

/* 5x7 font is used */
glcd_init_data.font=font5x7;
/* No need for reading data from external memory */
glcd_init_data.readxmem=NULL;
/* No need for reading data from external memory */ 
glcd_init_data.writexmem=NULL;
/* Set the Front Clock Divider */
glcd_init_data.divset=SSD1331_DEFAULT_DIVSET;
/* Set the Oscillator Frequency */
glcd_init_data.osc_freq=SSD1331_DEFAULT_OSC_FREQ;
/* Set the Phase 1 Period */
glcd_init_data.phase1=SSD1331_DEFAULT_PHASE1;
/* Set the Phase 2 Period */
glcd_init_data.phase2=SSD1331_DEFAULT_PHASE2;
/* Set the Pre-charge Voltage */
glcd_init_data.precharge_v=SSD1331_DEFAULT_PRECHARGE_V;
/* Set the VCOMH voltage */
glcd_init_data.vcomh=SSD1331_DEFAULT_VCOMH;
/* The horizontal coordinates are reversed
   Modify accordingly for your display, based on the datasheet */
glcd_init_data.reverse_x=SSD1331_REVX_REV;
/* The vertical coordinates are reversed
   Modify accordingly for your display, based on the datasheet */
glcd_init_data.reverse_y=SSD1331_REVY_REV;
/* Color order: RGB
   Modify accordingly for your display, based on the datasheet */
glcd_init_data.color_bgr=SSD1331_COLOR_RGB;
/* Horizontal COM connections are splitted odd/even (display is interlaced)
   Modify accordingly for your display, based on the datasheet */
glcd_init_data.com_split=SSD1331_COM_SPLIT_ON;
/* Set the Second Pre-charge Periods */
glcd_init_data.precharge_t2_red=SSD1331_DEFAULT_PRECHARGE_T2_RED;
glcd_init_data.precharge_t2_green=SSD1331_DEFAULT_PRECHARGE_T2_GREEN;
glcd_init_data.precharge_t2_blue=SSD1331_DEFAULT_PRECHARGE_T2_BLUE;
/* Set the Contrast Current for each color */
glcd_init_data.contrast_red=SSD1331_DEFAULT_CONTRAST_RED;
glcd_init_data.contrast_green=SSD1331_DEFAULT_CONTRAST_GREEN;
glcd_init_data.contrast_blue=SSD1331_DEFAULT_CONTRAST_BLUE;
/* Set the Master Current */
glcd_init_data.master_current=SSD1331_DEFAULT_MASTER_CURRENT;
/* Use the default linear gray scale table for gamma settings*/
glcd_init_data.gray_scale_table=SSD1331_DEFAULT_GRAY_SCALE;

/* Initialize the SSD1331 graphic controller */
glcd_init(&glcd_init_data);

/* Set text color */
glcd_setcolor(GLCD_CL_GREEN);

/* Display a literal char string located in FLASH */
glcd_outtextf("SSD1331 Demo");
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(0,10,"Font samples:");

/* Display some font samples */
glcd_setcolor(GLCD_CL_YELLOW);
glcd_outtextxyf(0,20,"Standard 5x7");

glcd_setfont(arial14);
glcd_outtextxyf(0,30,"Arial\n");

glcd_setfont(arial_bold14);
glcd_outtextf("Arial Bold");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

glcd_setfont(courier7x14);
glcd_outtextf("Courier\n");

glcd_setfont(courier_bold14);
glcd_outtextf("Courier Bold");

glcd_setfont(script19);
glcd_outtextf("Script");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

glcd_setfont(font5x7);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Variable text:\n");

glcd_setcolor(GLCD_CL_YELLOW);
glcd_setfont(courier_bold14);
glcd_outtextf("SSD1331\n");

/* Set horizontal justification: 2 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(2,1);
glcd_outtextf("SSD1331\n");

/* Set horizontal justification: 3 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(3,1);
glcd_outtextf("SSD1331\n");

/* Set horizontal justification: 4 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(4,1);
glcd_outtextf("SSD1331");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

/* Set horizontal justification: 1 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(1,1);
glcd_setfont(font5x7);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Line styles:");

/* Draw various styles of lines */
glcd_setcolor(GLCD_CL_YELLOW);

/* Line thickness: 1 pixel */
glcd_line(0,10,95,10);

glcd_setlinestyle(1,GLCD_LINE_DOT_SMALL);
glcd_line(0,15,95,15);

glcd_setlinestyle(1,GLCD_LINE_DOT_LARGE);
glcd_line(0,20,95,20);

/* Line thickness: 2 pixels */
glcd_setlinestyle(2,GLCD_LINE_SOLID);
glcd_line(0,25,95,25);

glcd_setlinestyle(2,GLCD_LINE_DOT_SMALL);
glcd_line(0,30,95,30);

glcd_setlinestyle(2,GLCD_LINE_DOT_LARGE);
glcd_line(0,35,95,35);

/* Line thickness: 4 pixels */
glcd_setlinestyle(4,GLCD_LINE_SOLID);
glcd_line(0,40,95,40);

glcd_setlinestyle(4,GLCD_LINE_DOT_SMALL);
glcd_line(0,45,95,45);

glcd_setlinestyle(4,GLCD_LINE_DOT_LARGE);
glcd_line(0,50,95,50);

/* 3 seconds delay */
delay_ms(3000);
/* Clear display */
glcd_clear();

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Colored lines:");

/* Draw some colored lines */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
i=1; /* Don't use black color for lines */
for (x=0; x<96; x+=4)
    {
    glcd_setcolor(colors[i++]);
    if (i>=(sizeof(colors)/sizeof(GLCDCOL_t))) i=1;
    glcd_line(0,10,x,63);
    }

i=1;
for (x=95; x>=0; x-=4) 
    {
    glcd_setcolor(colors[i++]);
    if (i>=(sizeof(colors)/sizeof(GLCDCOL_t))) i=1;
    glcd_line(95,63,x,10);
    }

/* 3 seconds delay */
delay_ms(3000);
/* Clear display */
glcd_clear();

/* Draw a hexagon with line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
glcd_setcolor(GLCD_CL_GREEN);
glcd_drawpoly(7,hexagon);

/* 1 second delay */
delay_ms(1000);

glcd_setfillcolor(GLCD_CL_RED);
/* Fill the hexagon with solid fill */
glcd_floodfill(30,17,GLCD_CL_GREEN);

/* Write a text inside the filled hexagon
   using transparent mode */
glcd_transparent(true);
glcd_settpcolor(GLCD_CL_RED);
glcd_setcolor(GLCD_CL_YELLOW);
glcd_outtextxyf(30,17,"Fill");
glcd_transparent(false);

/* Save hexagon image to RAM */
glcd_getimage(22,0,37,41,buffer);
/* Restore the default foreground
   and background colors */
glcd_setcolor(GLCD_CL_CYAN);
glcd_setbkcolor(GLCD_CL_BLACK);
glcd_outtextxyf(0,47,"Image was saved\nto RAM");

/* 3 seconds delay */
delay_ms(3000);
/* Clear display */
glcd_clear();

glcd_outtextf("Circles & arcs:");

glcd_setcolor(GLCD_CL_YELLOW);
/* Draw a circle with line thickness: 1 pixel */
glcd_circle(21,33,20);

glcd_setcolor(GLCD_CL_BLUE);
/* Draw an arc of a circle with line thickness: 1 pixel */
glcd_arc(21,33,0,120,15);

glcd_setcolor(GLCD_CL_RED);
/* Draw a circle with line thickness: 3 pixels */
glcd_setlinestyle(3,GLCD_LINE_SOLID);
glcd_circle(63,33,20);

glcd_setcolor(GLCD_CL_GREEN);
/* Draw an arc of a circle with line thickness: 3 pixels */
glcd_arc(63,33,0,210,15);

/* 3 seconds delay */
delay_ms(3000);
/* Clear display */
glcd_clear();

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Pie slice:");
glcd_setcolor(GLCD_CL_YELLOW);

/* Set line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID);

/* Draw filled pie slice */
glcd_pieslice(38,32,30,300,20);

/* 3 seconds delay */
delay_ms(3000);
/* Clear display */
glcd_clear();

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Rectangles &\nfilled bar:");
glcd_setcolor(GLCD_CL_YELLOW);

/* Draw a rectangle with line thickness: 1 pixel 
   and solid line */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
glcd_rectrel(0,20,40,25);

glcd_setcolor(GLCD_CL_RED);

/* Draw a rectangle with line thickness: 3 pixel
   and dotted line */
glcd_setlinestyle(3,GLCD_LINE_DOT_LARGE);
glcd_rectrel(42,20,40,25);

/* Draw a bar filled with a pattern */
glcd_setfillf(small_dots,GLCD_CL_GREEN);
glcd_bar(14,49,70,65);

/* 3 seconds delay */
delay_ms(3000);
/* Clear display */
glcd_clear();

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Rounded\nrectangle:");
glcd_setcolor(GLCD_CL_MAGENTA);

/* Draw rounded rectangle */
glcd_rectround(5,25,74,38,8);

/* 3 seconds delay */
delay_ms(3000);
/* Clear display */
glcd_clear();

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Put image\nfrom RAM:");
/* Display image saved in RAM */
glcd_putimage(56,0,buffer,GLCD_PUTCOPY);

/* 1 second delay */
delay_ms(1000);

/* Power-save mode test */
glcd_outtextxyf(0,46,"Entering\npower-save mode");

/* 1 second delay */
delay_ms(1000);

/* Turn display off and enter power-save mode */
glcd_display(false);

/* 2 seconds delay */
delay_ms(2000);

/* Exit power-save mode and turn display on */
glcd_display(true);
glcd_outtextxyf(0,46,"Exited  \npower-save mode");

/* 2 seconds delay */
delay_ms(2000);
glcd_clear();

/* Set fill pattern and color */
glcd_setfillf(solid_fill,GLCD_CL_WHITE);

/* Set line style solid */
glcd_setlinestyle(1,GLCD_LINE_SOLID);

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Meter:");

/* Display a meter gauge */
meter.xc=48;
meter.yc=50;
meter.radius=25;
meter.min_value=0;
meter.max_value=100;
meter.ticks=11;

meter_init(&meter);

for (i=0; i<4; i++)
    {
    for (x=meter.min_value; x<=meter.max_value; x+=5)
        {
        meter_update(&meter,x);
        delay_ms(100);
        }
    for (x=meter.max_value; x>=meter.min_value; x-=5)
        {
        meter_update(&meter,x);
        delay_ms(100);
        }
    }
    
/* 3 seconds delay */
delay_ms(3000);
glcd_clear();

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Bargraph:");

/* Display a bargraph gauge */
bargraph.xt=18;
bargraph.yt=15;
bargraph.width=60;
bargraph.height=40;
bargraph.min_value=meter.min_value;
bargraph.max_value=meter.max_value;
bargraph.ticks=meter.ticks;

bargraph_init(&bargraph);

for (i=0; i<4; i++)
    {
    for (x=meter.min_value; x<=meter.max_value; x+=5)
        {
        bargraph_update(&bargraph,x);
        delay_ms(100);
        }
    for (x=meter.max_value; x>=meter.min_value; x-=5)
        {
        bargraph_update(&bargraph,x);
        delay_ms(100);
        }
    }

/* 3 seconds delay */
delay_ms(3000);
glcd_clear();

/* Display the predefined colors */
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Colors:");
glcd_setcolor(GLCD_CL_WHITE);

for (i=0; i<(sizeof(colors)/sizeof(GLCDCOL_t));i++)
    {
    glcd_setfillcolor(colors[i]);
    x=(i & 1)*48;
    y=(i>>1)*5+10;
    glcd_barrel(x,y,40,4);
    };

/* Stop here */
while (1);
}
