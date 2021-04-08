/***************************************************************************
Ultrachip UC1610 Graphic LCD controller demo
(C) Copyright 2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

The demo is designed to run on an ATxmega128A1
XPlained development board with a chip clock 
of 2 MHz from the internal RC oscillator.

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
***************************************************************************/

#include <io.h>
#include <glcd.h>
#include <delay.h>

void main()
{
int x;
GLCDINIT_t init;


/* no font is used */
init.font=NULL;

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

/* Draw some lines */
for (x=0; x<80; x+=4) glcd_line(0,0,x,63);
for (x=79; x>=0; x-=4) glcd_line(79,63,x,0);

/* Draw various styles of lines */
/* Line thickness: 1 pixel */
glcd_line(85,10,159,10);

glcd_setlinestyle(1,GLCD_LINE_DOT_SMALL);
glcd_line(85,15,159,15);

glcd_setlinestyle(1,GLCD_LINE_DOT_LARGE);
glcd_line(85,20,159,20);

/* Line thickness: 2 pixels */
glcd_setlinestyle(2,GLCD_LINE_SOLID);
glcd_line(85,25,159,25);

glcd_setlinestyle(2,GLCD_LINE_DOT_SMALL);
glcd_line(85,30,159,30);

glcd_setlinestyle(2,GLCD_LINE_DOT_LARGE);
glcd_line(85,35,159,35);

/* Line thickness: 4 pixels */
glcd_setlinestyle(4,GLCD_LINE_SOLID);
glcd_line(85,40,159,40);

glcd_setlinestyle(4,GLCD_LINE_DOT_SMALL);
glcd_line(85,45,159,45);

glcd_setlinestyle(4,GLCD_LINE_DOT_LARGE);
glcd_line(85,50,159,50);

delay_ms(3000);
glcd_clear();

/* Draw a circle with line thickness: 1 pixel */
glcd_setlinestyle(1,GLCD_LINE_SOLID);
glcd_circle(79,51,40);

/* Draw a circle with line thickness: 4 pixels */
glcd_setlinestyle(4,GLCD_LINE_SOLID);
glcd_circle(79,51,30);
}
