/*********************************************************************
Solomon Systech SSD1351 Graphic controller demo
(C) Copyright 2011-2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

The demo is designed to run on an ATxmega128A1
XPlained development board with chip clock of 32 MHz.

An Univision Technology UG-2828GDEDF11 128x128 OLED 
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
VCI    - +3.3V decoupled with 10uF/16V tantalum capacitor to GND
VDDIO  - +3.3V decoupled with 1uF/16V tantalum capacitor to GND
VCC    - +13V decoupled with 10uF/16V tantalum capacitor to GND

VDD    - decoupled with 1uF/16V tantalum capacitor to GND
VCOMH  - decoupled with 4.7uF/16V tantalum capacitor to GND
VSL    - 51 ohm resistor - |>|- 1N4148 diode to GND
IREF   - 1 Mohm resistor to GND
GPIO0  - Not connected
GPIO1  - Not connected

Set signals to use 8-bit 8080 parallel interface mode:
BS0    - GND
BS1    - +3.3V

Make sure to specify the correct connections in the
Project|Configure|C Compiler|Libraries|Graphic LCD menu.

This program exceeds the code size limit of the Evaluation
version of CodeVisionAVR.
In this case you can program the ATxmega128A1 FLASH with
the contents of the
\EXAMPLES\Graphic Displays\SSD1351\Release\Exe\Full Demo.hex
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

typedef struct
      {
      flash char *name;
      GLCDCOL_t col;
      } color_data;

flash color_data colors[]=
{
"White",GLCD_CL_WHITE,
"Gray",GLCD_CL_GRAY,
"Lt. Gray",GLCD_CL_LIGHT_GRAY,
"Green",GLCD_CL_GREEN,
"Lime",GLCD_CL_LIME,
"Blue",GLCD_CL_BLUE,
"Red",GLCD_CL_RED,
"Aqua",GLCD_CL_AQUA,
"Yellow",GLCD_CL_YELLOW,
"Magenta",GLCD_CL_MAGENTA,
"Cyan",GLCD_CL_CYAN,
"Dk. Cyan",GLCD_CL_DARK_CYAN,
"Orange",GLCD_CL_ORANGE,
"Pink",GLCD_CL_PINK,
"Brown",GLCD_CL_BROWN,
"Violet",GLCD_CL_VIOLET,
"Silver",GLCD_CL_SILVER,
"Gold",GLCD_CL_GOLD,
"Navy",GLCD_CL_NAVY,
"Maroon",GLCD_CL_MAROON,
"Purple",GLCD_CL_PURPLE,
"Olive",GLCD_CL_OLIVE
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
glcd_init_data.divset=SSD1351_DEFAULT_DIVSET;
/* Set the Oscillator Frequency */
glcd_init_data.osc_freq=SSD1351_DEFAULT_OSC_FREQ;
/* Set the Phase 1 Period */
glcd_init_data.phase1=SSD1351_DEFAULT_PHASE1;
/* Set the Phase 2 Period */
glcd_init_data.phase2=SSD1351_DEFAULT_PHASE2;
/* Set the Pre-charge Voltage */
glcd_init_data.precharge_v=SSD1351_DEFAULT_PRECHARGE_V;
/* Set the VCOMH voltage */
glcd_init_data.vcomh=SSD1351_DEFAULT_VCOMH;
/* The horizontal coordinates are not reversed
   Modify accordingly for your display, based on the datasheet */
glcd_init_data.reverse_x=SSD1351_REVX_NORM;
/* The vertical coordinates are reversed
   Modify accordingly for your display, based on the datasheet */
glcd_init_data.reverse_y=SSD1351_REVY_REV;
/* Color order: BGR
   Modify accordingly for your display, based on the datasheet */
glcd_init_data.color_bgr=SSD1351_COLOR_BGR;
/* Horizontal COM connections are splitted odd/even (display is interlaced)
   Modify accordingly for your display, based on the datasheet */
glcd_init_data.com_split=SSD1351_COM_SPLIT_ON;
/* Set the Second Pre-charge Period */
glcd_init_data.precharge_t2=SSD1351_DEFAULT_PRECHARGE_T2;
/* Set the Contrast Current for each color */
glcd_init_data.contrast_red=SSD1351_DEFAULT_CONTRAST_RED;
glcd_init_data.contrast_green=SSD1351_DEFAULT_CONTRAST_GREEN;
glcd_init_data.contrast_blue=SSD1351_DEFAULT_CONTRAST_BLUE;
/* Set the Master Contrast Current */
glcd_init_data.master_contrast=SSD1351_DEFAULT_MASTER_CONTRAST;
/* The General Purpose Input/Outputs are not used */
glcd_init_data.gpio0=SSD1351_GPIO_HIZ;
glcd_init_data.gpio1=SSD1351_GPIO_HIZ;
/* Use the default linear gray scale table for gamma settings*/
glcd_init_data.gray_scale_table=SSD1351_DEFAULT_GRAY_SCALE;

/* Initialize the SSD1351 graphic controller */
glcd_init(&glcd_init_data);

/* Set text color */
glcd_setcolor(GLCD_CL_GREEN);

/* Display literal char string located in FLASH */
glcd_outtextf("SSD1351 Graphics Demo");
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(0,10,"Font samples:");

/* Display some font samples */
glcd_setcolor(GLCD_CL_YELLOW);
glcd_outtextxyf(0,20,"Standard 5x7");

glcd_setfont(arial14);
glcd_outtextxyf(0,30,"Arial 14\n");

glcd_setfont(arial_bold14);
glcd_outtextf("Arial Bold 14\n");

glcd_setfont(courier7x14);
glcd_outtextf("Courier 7x14\n");

glcd_setfont(courier_bold14);
glcd_outtextf("Courier Bold 14\n");

glcd_setfont(script19);
glcd_outtextf("Script 19");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

glcd_setfont(font5x7);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Var. text spacing:\n");

glcd_setcolor(GLCD_CL_YELLOW);
glcd_setfont(courier_bold14);
glcd_outtextf("SSD1351 Demo\n");
/* Set horizontal justification: 2 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(2,1);
glcd_outtextf("SSD1351 Demo\n");
/* Set horizontal justification: 3 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(3,1);
glcd_outtextf("SSD1351 Demo");

/* 4 seconds delay */
delay_ms(4000);
/* Clear display */
glcd_clear();

/* Set horizontal justification: 1 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(1,1);
glcd_setfont(font5x7);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Some line styles:");

/* Draw various styles of lines */
glcd_setcolor(GLCD_CL_YELLOW);

/* Line thickness: 1 pixel */
glcd_line(0,10,127,10);

glcd_setlinestyle(1,GLCD_LINE_DOT_SMALL);
glcd_line(0,15,127,15);

glcd_setlinestyle(1,GLCD_LINE_DOT_LARGE);
glcd_line(0,20,127,20);

/* Line thickness: 2 pixels */
glcd_setlinestyle(2,GLCD_LINE_SOLID);
glcd_line(0,25,127,25);

glcd_setlinestyle(2,GLCD_LINE_DOT_SMALL);
glcd_line(0,30,127,30);

glcd_setlinestyle(2,GLCD_LINE_DOT_LARGE);
glcd_line(0,35,127,35);

/* Line thickness: 4 pixels */
glcd_setlinestyle(4,GLCD_LINE_SOLID);
glcd_line(0,40,127,40);

glcd_setlinestyle(4,GLCD_LINE_DOT_SMALL);
glcd_line(0,45,127,45);

glcd_setlinestyle(4,GLCD_LINE_DOT_LARGE);
glcd_line(0,50,127,50);

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

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(0,64,"Pie slice:");
glcd_setcolor(GLCD_CL_YELLOW);

/* Set line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID);

/* Draw filled pie slice */
glcd_pieslice(38,97,30,300,20);

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

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(0,70,"Rounded rectangle:");
glcd_setcolor(GLCD_CL_MAGENTA);

/* Draw rounded rectangle */
glcd_rectround(5,82,74,38,8);

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
glcd_outtextxyf(0,46,"Entering power-save\nmode...     ");

/* 1 second delay */
delay_ms(1000);

/* Turn display off and enter power-save mode */
glcd_display(false);

/* 2 seconds delay */
delay_ms(2000);

/* Exit power-save mode and turn display on */
glcd_display(true);
glcd_outtextxyf(0,46,"Exited power-save  \nmode        ");

/* 2 seconds delay */
delay_ms(2000);
glcd_clear();

/* Set fill pattern and color */
glcd_setfillf(solid_fill,GLCD_CL_WHITE);

/* Set line style solid */
glcd_setlinestyle(1,GLCD_LINE_SOLID);

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Meter & bargraph:");

/* Display a meter gauge */
meter.xc=64;
meter.yc=70;
meter.radius=46;
meter.min_value=0;
meter.max_value=100;
meter.ticks=11;

meter_init(&meter);

/* Display a bar-graph gauge */
bargraph.xt=15;
bargraph.yt=80;
bargraph.width=100;
bargraph.height=40;
bargraph.min_value=meter.min_value;
bargraph.max_value=meter.max_value;
bargraph.ticks=meter.ticks;

bargraph_init(&bargraph);

for (i=0; i<4; i++)
    {
    for (x=meter.min_value; x<=meter.max_value; x+=5)
        {
        meter_update(&meter,x);
        bargraph_update(&bargraph,x);
        delay_ms(100);
        }
    for (x=meter.max_value; x>=meter.min_value; x-=5)
        {
        meter_update(&meter,x);
        bargraph_update(&bargraph,x);
        delay_ms(100);
        }
    }
    
/* 3 seconds delay */
delay_ms(3000);
glcd_clear();

/* Display the predefined colors */
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Predefined colors:");
glcd_setcolor(GLCD_CL_WHITE);

for (i=0; i<(sizeof(colors)/sizeof(color_data));i++)
    {
    glcd_setfillcolor(colors[i].col);
    x=(i & 1)*64;
    y=(i>>1)*10+10;
    glcd_outtextxyf(x,y,colors[i].name);
    glcd_barrel(x+50,y,10,9);
    };

/* Stop here */
while (1);
}
