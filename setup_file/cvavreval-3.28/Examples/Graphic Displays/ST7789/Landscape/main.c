/****************************************************************
Sitronix ST7789S Color TFT LCD controller demo
(C) Copyright 2016 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

This program can't be compiled with the Evaluation or
Standard versions of CodeVisionAVR, because the
glcd_st7789.lib file is supplied only with the
Advanced license.
In this case you can program the ATxmega128A1 FLASH with
the contents of the
\EXAMPLES\Graphic Displays\ST7789\Landscape\Release\Exe\demo_landscape.hex
file.

The demo is designed to run on the Atmel XMEGA-A1 Xplained
development board with an ATxmega128A1
chip using the internal 32 MHz oscillator
as clock source.

A type NHD-2.4-240320CF-CTXI#-F 240x320 2.4" TFT LCD
module from www.newhavendisplay.com
is used for the purpose of this demo.
It can be replaced with other similar modules with
the ST7789 controller.
The display is connected to the XMEGA-A1 Xplained
board using a NHD-FFC40 addapter, also from
www.newhavendisplay.com

In this demo the controller is operated in 64k color mode
using a 8 bit interface .

The TFT LCD module connections are:
14 DB0  - GND
15 DB1  - GND
16 DB2  - GND
17 DB3  - GND
18 DB4  - GND
19 DB5  - GND
20 DB6  - GND
21 DB7  - GND

22 DB8  - PORTA bit 0
23 DB9  - PORTA bit 1
24 DB10 - PORTA bit 2
25 DB11 - PORTA bit 3
26 DB12 - PORTA bit 4
27 DB13 - PORTA bit 5
28 DB14 - PORTA bit 6
29 DB15 - PORTA bit 7

10 /CS  - PORTD bit 0
11 RS (D/C) - PORTD bit 1
13 /RD  - PORTD bit 2
12 /WR  - PORTD bit 3
30 /RES - PORTD bit 4

31 IM0  - +3.3V Use 8 bit interface mode

Backlight connections:
38 LED-A  - +3.3V
34 LED-K1 - connected to GND using a 470 ohm resistor
35 LED-K2 - connected to GND using a 470 ohm resistor
36 LED-K3 - connected to GND using a 470 ohm resistor
37 LED-K4 - connected to GND using a 470 ohm resistor

Power supply connections:
7 VDD   - +3.3V
8 IOVDD - +3.3V
1  GND  - GND
33 GND  - GND
39 GND  - GND

If you are using a different TFT module,
please use the connections from the module's datasheet.

The connections can be modified by accessing the
Project|Configure|C Compiler|Libraries|Graphic LCD menu.
****************************************************************/

#include <io.h>
#include <glcd.h>
#include <delay.h>

/* Meter functions */
#include "meter.h"
/* Bar-graph gauge functions */
#include "bargraph.h"
/* Button functions */
#include "button.h"
/* Glyphs for buttons */
#include "ok_glyph.h"
#include "cancel_glyph.h"

/* Include some fonts needed by the demo */
#include <font5x7.h>
#include "arial14.h"
#include "arial_bold14.h"
#include "courier7x14.h"
#include "courier_bold14.h"
#include "la_bamba17.h"

#include "image.h"

/* Small dots filling pattern */
flash unsigned char small_dots[]={0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55};

/* Solid filling pattern */
flash unsigned char solid_fill[]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

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
"Black",GLCD_CL_BLACK,
"White",GLCD_CL_WHITE,
"Gray",GLCD_CL_GRAY,
"Light Gray",GLCD_CL_LIGHT_GRAY,
"Green",GLCD_CL_GREEN,
"Lime",GLCD_CL_LIME,
"Blue",GLCD_CL_BLUE,
"Red",GLCD_CL_RED,
"Aqua",GLCD_CL_AQUA,
"Yellow",GLCD_CL_YELLOW,
"Magenta",GLCD_CL_MAGENTA,
"Cyan",GLCD_CL_CYAN,
"Dark Cyan",GLCD_CL_DARK_CYAN,
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

flash char * flash button_state[2]=
      {"Buttons not pressed",
       "Buttons pressed     "};

/* Buffer used for image storage */
unsigned char buffer[3100];

// System Clocks initialization
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
//OSC.DFLLCTRL&= ~(OSC_RC32MCREF_bm | OSC_RC2MCREF_bm);
// Enable the autocalibration of the internal 32 MHz RC oscillator
//DFLLRC32M.CTRL|=DFLL_ENABLE_bm;

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
GLCDINIT_t glcd_init_data;
unsigned char i;
int x,y;
meter_t meter;
bargraph_t bargraph;
button_t button_ok,button_cancel;

/* Set the ATxmega128A1 to run from the internal 32MHz oscillator */
system_clocks_init();

/* Initialize the TFT controller with the values
   required by the NHD-2.4-240320CF-CTXI#-F display */

/* Specify the current font for displaying text */
glcd_init_data.font=font5x7;
/* No function is used for reading image data from external memory */
glcd_init_data.readxmem=NULL;
/* No function is used for writing image data to external memory */
glcd_init_data.writexmem=NULL;
/* Horizontal display not reversed */
glcd_init_data.reverse_x=ST7789_REVX_NORM;
/* Vertical display not reversed */
glcd_init_data.reverse_y=ST7789_REVY_NORM;
/* Color bit writing order: RGB */
glcd_init_data.cl_bits_order=ST7789_CL_BITS_RGB;
/* Use default value for VGL */
glcd_init_data.vgl=ST7789_DEFAULT_VGL;
/* Use default value for VGH */
glcd_init_data.vgh=ST7789_DEFAULT_VGH;
/* Use default value for VRH */
glcd_init_data.vrh=ST7789_DEFAULT_VRH;
/* Use default value for VDV */
glcd_init_data.vrh=ST7789_DEFAULT_VDV;
/* Use default value for VCOM */
glcd_init_data.vcom=ST7789_DEFAULT_VCOM;
/* Use default value for frame rate */
glcd_init_data.frame_rate=ST7789_DEFAULT_FRAME_RATE;

glcd_init(&glcd_init_data);

/* Display literal char string located in FLASH */
glcd_outtextf("Sitronix ST7789S Landscape Graphics Demo\n"
              "Here are some font samples:");

/* Display some font samples */
glcd_setcolor(GLCD_CL_YELLOW);
glcd_outtextxyf(0,20,"Standard, 5x7 pixels");

glcd_setfont(arial14);
glcd_setcolor(GLCD_CL_RED);
glcd_outtextxyf(0,30,"Arial, 14 pixels height\n");

glcd_setfont(arial_bold14);
glcd_setcolor(GLCD_CL_MAGENTA);
glcd_outtextf("Arial Bold, 14 pixels height\n");

glcd_setfont(courier7x14);
glcd_setcolor(GLCD_CL_GREEN);
glcd_outtextf("Courier, 7x14 pixels\n");

glcd_setfont(courier_bold14);
glcd_setcolor(GLCD_CL_LIME);
glcd_outtextf("Courier Bold,14 pixels height\n");

glcd_setfont(la_bamba17);
glcd_setcolor(GLCD_CL_AQUA);
glcd_outtextf("La Bamba,17 pixels height\n");

glcd_setfont(arial_bold14);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("\nVariable text spacing:\n");

glcd_setfont(courier_bold14);
glcd_setcolor(GLCD_CL_YELLOW);

for (i=1; i<=6; i++)
    {
    /* Set variable horizontal justification and
       vertical justification: 1 pixel */
    glcd_settextjustify(i,1);
    glcd_outtextf("ST7789 TFT Controller\n");
    }

/* 5 seconds delay */
delay_ms(5000);
/* Clear display */
glcd_clear();

/* Set horizontal justification: 1 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(1,1);
glcd_setfont(arial_bold14);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Line styles:");

/* Draw various styles of lines */
glcd_setcolor(GLCD_CL_LIME);
/* Line thickness: 1 pixel */
glcd_line(0,20,319,20);

glcd_setlinestyle(1,GLCD_LINE_DOT_SMALL);
glcd_line(0,25,319,25);

glcd_setlinestyle(1,GLCD_LINE_DOT_LARGE);
glcd_line(0,30,319,30);

/* Line thickness: 2 pixels */
glcd_setlinestyle(2,GLCD_LINE_SOLID);
glcd_line(0,35,319,35);

glcd_setlinestyle(2,GLCD_LINE_DOT_SMALL);
glcd_line(0,40,319,40);

glcd_setlinestyle(2,GLCD_LINE_DOT_LARGE);
glcd_line(0,45,319,45);

/* Line thickness: 4 pixels */
glcd_setlinestyle(4,GLCD_LINE_SOLID);
glcd_line(0,50,319,50);

glcd_setlinestyle(4,GLCD_LINE_DOT_SMALL);
glcd_line(0,55,319,55);

glcd_setlinestyle(4,GLCD_LINE_DOT_LARGE);
glcd_line(0,60,319,60);

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(0,70,"Coloured lines:");

/* Draw some coloured lines */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
i=1; /* Don't use black color for lines */
for (x=0; x<320; x+=4)
    {
    glcd_setcolor(colors[i++].col);
    if (i>=(sizeof(colors)/sizeof(color_data))) i=1;
    glcd_line(319,90,x,239);
    }

i=1;
for (x=319; x>=0; x-=4)
    {
    glcd_setcolor(colors[i++].col);
    if (i>=(sizeof(colors)/sizeof(color_data))) i=1;
    glcd_line(0,239,x,90);
    }

/* 5 seconds delay */
delay_ms(5000);
/* Clear display */
glcd_clear();

/* Draw a hexagon with line thickness: 1 pixel */
glcd_setcolor(GLCD_CL_YELLOW);
glcd_setlinestyle(1,GLCD_LINE_SOLID);
glcd_drawpoly(7,hexagon);

/* Write a text inside the hexagon */
glcd_setfont(font5x7);
glcd_outtextxyf(30,17,"Fill");

/* Fill the hexagon with solid red color fill */
glcd_setfillcolor(GLCD_CL_RED);
glcd_floodfill(48,24,GLCD_CL_YELLOW /* border color */);

/* Save hexagon image in RAM */
glcd_getimage(22,0,37,41,buffer);

glcd_setfont(font5x7);
glcd_outtextxyf(0,47,"Image was saved to RAM");

/* Draw a circle with line thickness: 1 pixel */
glcd_circle(21,83,20);

/* Draw an arc of a circle with line thickness: 1 pixel */
glcd_setcolor(GLCD_CL_RED);
glcd_arc(21,83,0,120,15);

/* Draw a circle with line thickness: 3 pixels */
glcd_setlinestyle(3,GLCD_LINE_SOLID);
glcd_setcolor(GLCD_CL_LIME);
glcd_circle(63,83,20);

/* Draw an arc of a circle with line thickness: 3 pixels */
glcd_setcolor(GLCD_CL_MAGENTA);
glcd_arc(63,83,0,210,15);

glcd_setcolor(GLCD_CL_YELLOW);
glcd_outtextxyf(0,107,"Circles & arcs");

/* Draw a rectangle with line thickness: 1 pixel
   and solid line */
glcd_setcolor(GLCD_CL_RED);
glcd_setlinestyle(1,GLCD_LINE_SOLID);
glcd_rectrel(100,60,40,25);

/* Draw a rectangle with line thickness: 3 pixel
   and dotted line */
glcd_setcolor(GLCD_CL_AQUA);
glcd_setlinestyle(3,GLCD_LINE_DOT_LARGE);
glcd_rectrel(142,60,40,25);

/* Draw a bar filled with a pattern of green color */
glcd_setfillf(small_dots,GLCD_CL_GREEN);
glcd_bar(114,89,170,104);

glcd_setcolor(GLCD_CL_YELLOW);
glcd_outtextxyf(100,107,"Rectangles & filled bar");

/* Draw rounded rectangle */
glcd_setcolor(GLCD_CL_RED);
glcd_rectround(5,125,74,38,8);

glcd_setcolor(GLCD_CL_YELLOW);
glcd_outtextxyf(16,136,"Rounded");
glcd_outtextxyf(16,144,"rectangle");

/* Set line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID);

glcd_setcolor(GLCD_CL_YELLOW);
glcd_outtextxyf(100,120,"Pie");
glcd_outtextxyf(100,127,"slice:");

/* Draw a pie slice filled with blue color */
glcd_setfillcolor(GLCD_CL_BLUE);
glcd_pieslice(170,143,30,300,20);

glcd_outtextxyf(0,170,"Display\nan image\nfrom\nRAM:");

/* Display image saved in RAM
   without transparency */
glcd_putimage(50,170,buffer,GLCD_PUTCOPY);

glcd_outtextxyf(0,215,"Non-transparent mode");

/* Set transparent color */
glcd_settpcolor(GLCD_CL_RED);

/* Display image saved in RAM
   with transparency */
glcd_putimage(150,170,buffer,GLCD_PUTTP);

glcd_outtextxyf(130,215,"Transparent mode");

glcd_setfont(arial_bold14);
glcd_setcolor(GLCD_CL_CYAN);

/* 5 seconds delay */
delay_ms(5000);
/* Clear display */
glcd_clear();

glcd_outtextf("Display an image from FLASH:");

/* Display image stored in FLASH */
glcd_putimagef(5,20,img,GLCD_PUTCOPY);

/* 5 seconds delay */
delay_ms(5000);
/* Clear display */
glcd_clear();

/* Set fill pattern and color */
glcd_setfillf(solid_fill,GLCD_CL_WHITE);

glcd_outtextxyf(20,0,"Meter & Bar-graph gauges:");

/* Display a meter gauge */
meter.xc=80;
meter.yc=80;
meter.radius=50;
meter.min_value=0;
meter.max_value=100;
meter.ticks=11;

meter_init(&meter);

/* Display a bar-graph gauge */
bargraph.xt=165;
bargraph.yt=meter.yc-50;
bargraph.width=90;
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

glcd_setfont(arial_bold14);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(20,100,"Button examples:");

/* Create OK button */
button_ok.left=20;
button_ok.top=130;
button_ok.width=80;
button_ok.height=30;
button_ok.border_color=GLCD_CL_BLUE;
button_ok.bg_color=GLCD_CL_LIGHT_GRAY;
button_ok.pressed_color=GLCD_CL_WHITE;
button_ok.text_color=GLCD_CL_BLACK;
button_ok.glyph_tp_color=GLCD_CL_WHITE;
button_ok.glyph=ok_glyph;
button_ok.caption="OK";
button_ok.font=arial_bold14;

button_init(&button_ok);

/* Create Cancel button */
/* Most of the parameters are the same for both buttons, */
button_cancel=button_ok;
/* except left coordinate, */
button_cancel.left=110;
/* glyph */
button_cancel.glyph=cancel_glyph;
/* and caption */
button_cancel.caption="Cancel";

button_init(&button_cancel);

/* Ensure that text is displayed in non-transparent mode */
glcd_transparent(false);

/* Toggle buttons */
for (i=0;i<10;i++)
    {
    button_ok.pressed=!button_ok.pressed;
    button_update(&button_ok);

    button_cancel.pressed=button_ok.pressed;
    button_update(&button_cancel);

    glcd_setcolor(GLCD_CL_CYAN);
    glcd_outtextxyf(20,175,button_state[button_ok.pressed]);
    delay_ms(500);
    }

/* 2 seconds delay */
delay_ms(2000);

/* Clear display */
glcd_clear();

glcd_outtextf("Predefined colors:");

/* Display the predefined colors */

/* Set fill pattern and color */
glcd_setfillf(solid_fill,GLCD_CL_WHITE);

glcd_setfont(font5x7);
glcd_setcolor(GLCD_CL_WHITE);

for (i=0; i<(sizeof(colors)/sizeof(color_data));i++)
    {
    glcd_setfillcolor(colors[i].col);
    x=(i & 1)*120;
    y=(i>>1)*16+16;
    glcd_outtextxyf(x,y+3,colors[i].name);
    glcd_barrel(x+65,y,45,15);
    };

/* Stop here */
while (1);
}
