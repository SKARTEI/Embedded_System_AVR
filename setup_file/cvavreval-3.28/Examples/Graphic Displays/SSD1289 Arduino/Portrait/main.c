/*********************************************************************************************
Solomon Systech SSD1289 Color TFT LCD controller demo
(C) Copyright 2011-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

This program can't be compiled with the Evaluation or
Standard versions of CodeVisionAVR,
because the glcd_ssd1289.lib file is supplied only with
the Advanced license.
In this case you can program the ATmega2560 FLASH with
the contents of the
\EXAMPLES\Graphic LCD\SSD1289 Arduino\Exe\demo_8bit.hex
file.

The demo is designed to run on an Arduino Mega2560
development board with an ATmega2560 chip using a
16 MHz crystal oscillator as clock source.

The SSD1289 TFT controller is used in an 8-bit bus
connection, 64k color mode.
This mode is supported only by CodeVisionAVR V3.15
or later compilers.

A "3.2" TFT Arduino TFT LCD Shield Rev. B" from:

http://www.uctronics.com/32-tft-lcd-shield-touch-panel-tf-reader-for-arduino-p-1111.html

is used for the purpose of this demo.

VERY IMPORTANT:
- Due to a design flaw in the Arduino Mega board,
you must cut the traces and insert two 10k SMD
resistors between the ATmega8U2 RXD (PORTD bit 3),
respectively TXD (PORTD bit 2), signals and the RN4B,
respectively RN4A, 1k resistors that lead to the
ATmega2560 PORTE bit 0, respectively PORTE bit 1 signals.
This way the total resistance between ATmega2560 PORTE bit 0,
respectively bit 1, and ATmega8U2 PORTD bit 3,
respectively bit 2, will be 11k.
Failure to do so, will result in the glcd_getpixel
and glcd_floodfill functions not working properly
with this TFT LCD shield.
- The DIP switches 1 and 2 on the TFT shield must be
set in the ON position.

The TFT LCD shield connections to the Arduino Mega2560 are:
D0 (TFT DB0) - PORTE bit 0
D1 (TFT DB1) - PORTE bit 1
D2 (TFT DB2) - PORTE bit 4
D3 (TFT DB3) - PORTE bit 5
D4 (TFT DB4) - PORTG bit 5
D5 (TFT DB5) - PORTE bit 3
D6 (TFT DB6) - PORTH bit 3
D7 (TFT DB7) - PORTH bit 4

A0 (TFT /CS) - PORTF bit 0
A1 (TFT D/C) - PORTF bit 1
A2 (TFT /WR) - PORTF bit 2
A3 (TFT /RD) - PORTF bit 3

GND   - Arduino Mega2560 GND
+5V   - Arduino Mega2560 +5V
+3.3V - Arduino Mega2560 +3.3V

The connections can be modified by accessing the
Project|Configure|C Compiler|Libraries|Graphic LCD menu.
*********************************************************************************************/

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
#include "la_bamba17.h"

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

/* Buffer used for image storage */
unsigned char buffer[3100];

void main()
{
GLCDINIT_t glcd_init_data;
unsigned char i;
int x,y;
meter_t meter;
bargraph_t bargraph;

/* USART0 must be disabled, so that PORTE bits 0 and 1
   will not conflict with the SSD1289 data bus */
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (0<<RXEN0) | (0<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);

/* Initialize the LCD controller with the default values
   from glcd_ssd1289.h */

/* Specify the current font for displaying text */
glcd_init_data.font=font5x7;
/* No function is used for reading image data from external memory */
glcd_init_data.readxmem=NULL;
/* No function is used for writing image data to external memory */
glcd_init_data.writexmem=NULL;
/* Horizontal display is reversed */
glcd_init_data.reverse_x=SSD1289_REVX_REV;
/* Normal display, no vertical reverse */
glcd_init_data.reverse_y=SSD1289_REVY_NORM;
/* Color bit writing order: BGR */
glcd_init_data.cl_bits_order=SSD1289_CL_BITS_BGR;
/* Power control 1 BT0..BT2 step-up factor of the step-up circuit */
glcd_init_data.stepup_factor=SSD1289_DEFAULT_STEPUP_FACTOR;
/* Power control 1 DC0..DC3, DCT0..DCT3 step-up circuit cycle */
glcd_init_data.stepup_cycle=SSD1289_DEFAULT_STEPUP_CYCLE;
/* Power control 1 AP0..AP2 adjusts the amount of current
   from the constant current source in the
   internal op. amplifier circuit */
glcd_init_data.crt_source=SSD1289_DEFAULT_CRT_SOURCE;
/* Default value for VCIX2 voltage */
glcd_init_data.vcix2=SSD1289_DEFAULT_VCIX2;
/* Default value for VLCD63 voltage */
glcd_init_data.vlcd63=SSD1289_DEFAULT_VLCD63;
// Default value for VcomL alternating drive voltage
glcd_init_data.vcoml=SSD1289_DEFAULT_VCOML;
/* Default value for VcomH voltage */
glcd_init_data.vcomh=SSD1289_DEFAULT_VCOMH;
/* Frame frequency */
glcd_init_data.frame_freq=SSD1289_DEFAULT_FRAME_FREQ;
/* PKP00..PKP02 positive gamma micro adj. */
glcd_init_data.pkp00=SSD1289_DEFAULT_PKP00;
/* PKP10..PKP12 positive gamma micro adj. */
glcd_init_data.pkp10=SSD1289_DEFAULT_PKP10;
/* PKP20..PKP22 positive gamma micro adj. */
glcd_init_data.pkp20=SSD1289_DEFAULT_PKP20;
/* PKP30..PKP32 positive gamma micro adj. */
glcd_init_data.pkp30=SSD1289_DEFAULT_PKP30;
/* PKP40..PKP42 positive gamma micro adj. */
glcd_init_data.pkp40=SSD1289_DEFAULT_PKP40;
/* PKP50..PKP52 positive gamma micro adj. */
glcd_init_data.pkp50=SSD1289_DEFAULT_PKP50;
/* PRP00..PRP02 positive gamma gradient adj. */
glcd_init_data.prp00=SSD1289_DEFAULT_PRP00;
/* PRP10..PRP12 positive gamma gradient adj. */
glcd_init_data.prp10=SSD1289_DEFAULT_PRP10;
/* VRP00..VRP03 positive gamma amplification adj. */
glcd_init_data.vrp00=SSD1289_DEFAULT_VRP00;
/* VRP10..VRP14 positive gamma amplification adj. */
glcd_init_data.vrp10=SSD1289_DEFAULT_VRP10;
/* PKN00..PKN02 negative gamma micro adj. */
glcd_init_data.pkn00=SSD1289_DEFAULT_PKN00;
/* PKN10..PKN12 negative gamma micro adj. */
glcd_init_data.pkn10=SSD1289_DEFAULT_PKN10;
/* PKN20..PKN22 positive gamma micro adj. */
glcd_init_data.pkn20=SSD1289_DEFAULT_PKN20;
/* PKN30..PKN32 positive gamma micro adj. */
glcd_init_data.pkn30=SSD1289_DEFAULT_PKN30;
/* PKN40..PKN42 negative gamma micro adj. */
glcd_init_data.pkn40=SSD1289_DEFAULT_PKN40;
/* PKN50..PKN52 negative gamma micro adj. */
glcd_init_data.pkn50=SSD1289_DEFAULT_PKN50;
/* PRN00..PRN02 negative gamma gradient adj. */
glcd_init_data.prn00=SSD1289_DEFAULT_PRN00;
/* PRN10..PRN12 negative gamma gradient adj. */
glcd_init_data.prn10=SSD1289_DEFAULT_PRN10;
/* VRN00..VRN03 negative gamma amplification adj. */
glcd_init_data.vrn00=SSD1289_DEFAULT_VRN00;
/* VRN10..VRN14 negative gamma amplification adj. */
glcd_init_data.vrn10=SSD1289_DEFAULT_VRN10;

glcd_init(&glcd_init_data);

/* Use transparent displaying mode for text */
glcd_transparent(1);

/* Display literal char string located in FLASH */
glcd_outtextf("Solomon Systech SSD1289 Graphics Demo\n"
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
glcd_outtextf("SSD1289 TFT Controller\n");
/* Set horizontal justification: 2 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(2,1);
glcd_outtextf("SSD1289 TFT Controller\n");
/* Set horizontal justification: 3 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(3,1);
glcd_outtextf("SSD1289 TFT Controller");

/* Set horizontal justification: 1 pixels and
   vertical justification: 1 pixel */
glcd_settextjustify(1,1);
glcd_setfont(arial_bold14);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(0,190,"Line styles:");

/* Draw various styles of lines */
glcd_setcolor(GLCD_CL_ORANGE);
/* Line thickness: 1 pixel */
glcd_line(0,210,239,210);

glcd_setlinestyle(1,GLCD_LINE_DOT_SMALL);
glcd_line(0,215,239,215);

glcd_setlinestyle(1,GLCD_LINE_DOT_LARGE);
glcd_line(0,220,239,220);

/* Line thickness: 2 pixels */
glcd_setlinestyle(2,GLCD_LINE_SOLID);
glcd_line(0,225,239,225);

glcd_setlinestyle(2,GLCD_LINE_DOT_SMALL);
glcd_line(0,230,239,230);

glcd_setlinestyle(2,GLCD_LINE_DOT_LARGE);
glcd_line(0,235,239,235);

/* Line thickness: 4 pixels */
glcd_setlinestyle(4,GLCD_LINE_SOLID);
glcd_line(0,240,239,240);

glcd_setlinestyle(4,GLCD_LINE_DOT_SMALL);
glcd_line(0,245,239,245);

glcd_setlinestyle(4,GLCD_LINE_DOT_LARGE);
glcd_line(0,250,239,250);

glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(0,260,"Coloured lines:");

/* Draw some coloured lines */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
i=1; /* Don't use black color for lines */
for (x=0; x<240; x+=4)
    {
    glcd_setcolor(colors[i++].col);
    if (i>=(sizeof(colors)/sizeof(color_data))) i=1;
    glcd_line(0,275,x,319);
    }

i=1;
for (x=239; x>=0; x-=4)
    {
    glcd_setcolor(colors[i++].col);
    if (i>=(sizeof(colors)/sizeof(color_data))) i=1;
    glcd_line(239,319,x,275);
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

glcd_outtextxyf(0,170,"Put\nimage\nfrom\nRAM:");

/* Display image saved in RAM
   without transparency */
glcd_putimage(46,170,buffer,GLCD_PUTCOPY);

glcd_outtextxyf(0,215,"Non-transparent mode");

/* Set transparent color */
glcd_settpcolor(GLCD_CL_RED);

/* Display image saved in RAM
   with transparency */
glcd_putimage(150,170,buffer,GLCD_PUTTP);

glcd_outtextxyf(130,215,"Transparent mode");

/* Set fill pattern and color */
glcd_setfillf(solid_fill,GLCD_CL_WHITE);

glcd_setfont(arial_bold14);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextxyf(30,225,"Meter & Bar-graph gauges:");

/* Display a meter gauge */
meter.xc=60;
meter.yc=305;
meter.radius=50;
meter.min_value=0;
meter.max_value=100;
meter.ticks=11;

meter_init(&meter);

/* Display a bar-graph gauge */
bargraph.xt=133;
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

/* 5 seconds delay */
delay_ms(5000);
/* Clear display */
glcd_clear();

glcd_setfont(arial_bold14);
glcd_setcolor(GLCD_CL_CYAN);
glcd_outtextf("Predefined colors:");

/* Display the predefined colors */

/* Set fill pattern and color */
glcd_setfillf(solid_fill,GLCD_CL_WHITE);

glcd_setfont(font5x7);
glcd_setcolor(GLCD_CL_WHITE);

for (i=0; i<(sizeof(colors)/sizeof(color_data));i++)
    {
    glcd_setfillcolor(colors[i].col);
    x=(i%2)*120;
    y=(i/2)*20+20;
    glcd_outtextxyf(x,y+6,colors[i].name);
    glcd_barrel(x+65,y,45,19);
    };

/* Stop here */
while (1);
}
