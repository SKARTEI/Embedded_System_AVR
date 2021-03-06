/*******************************************************************************
Solomon Systech SSD1963 Color TFT LCD and
ADS7846 Resistive Touchscreen controller demo
(C) Copyright 2011-2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

This program can't be compiled with the Evaluation or
Standard versions of CodeVisionAVR, because the glcd_ssd1963.lib
file is supplied only with the Advanced license.
In this case you can program the ATxmega128A1 FLASH with
the contents of the
\EXAMPLES\Graphic LCD\Resistive Touchscreen\SSD1963 480x272\Release\Exe\demo_rtouch.hex
file.

The demo is designed to run on the STK600
development board with an ATxmega128A1
chip using the internal 32 MHz oscillator
as clock source.

In this demo the SSD1963 controller operates in 
8 bit interface mode.
For better performance the 16 bit operating mode can
be selected by accessing the
Project|Configure|C Compiler|Libraries|Graphic LCD menu.
In this situation the DB8-DB15 signals must be also
connected to one of the ATxmega128A1 ports.   

An ER-TFTM043-4 480x272 4.3" TFT LCD module
from www.buydisplay.com is used for
the purpose of this demo.
It can be replaced with other similar modules with
the SSD1963 controller. 

The TFT LCD module connections are:
DB0  - PORTC bit 0
DB1  - PORTC bit 1
DB2  - PORTC bit 2
DB3  - PORTC bit 3
DB4  - PORTC bit 4
DB5  - PORTC bit 5
DB6  - PORTC bit 6
DB7  - PORTC bit 7

DB8  - not connected
DB9  - not connected
DB10 - not connected
DB11 - not connected
DB12 - not connected
DB13 - not connected
DB14 - not connected
DB15 - not connected

/CS  - PORTE bit 0
D/C  - PORTE bit 1
/RD  - PORTE bit 2
/WR  - PORTE bit 3
/RST - PORTE bit 4

Backlight control - PORTD bit 5

VSS   - GND
VDD   - +5V  (Jumper J8 NOT SET, the ER-TFTM043-4 display 
              module uses its own 3.3V voltage regulator)

ADS7846 touch screen controller connections:
/CS     - PORTF bit 0
DCLK    - PORTF bit 1
DIN     - PORTF bit 2
DOUT    - PORTF bit 3
/PENIRQ - PORTF bit 4

If you are using a different LCD module,
please use the connections from the module datasheet.

The connections can be modified by accessing the
Project|Configure|C Compiler|Libraries|Graphic Display and
Project|Configure|C Compiler|Libraries|Resistive Touchscreen
menus.
*******************************************************************************/

#include <io.h>
#include <glcd.h>
#include <delay.h>
#include <stdio.h>
/* Resistive touchscreen functions */
#include <rtouch.h>

/* Include the font needed by the demo */
#include <font5x7.h>

#include "init.h"

/* Resistive touchscreen calibration helper functions */
#include "calibrate.h"

/* Timer/counter TCC0 Overflow/Underflow interrupt service routine called every 10ms */
interrupt [TCC0_OVF_vect] void tcc0_overflow_isr(void)
{
/* Called to detect the ADS7846 controller's
   /PENIRQ signal becoming 0 when the screen was touched */
rt_timerproc();
}

/* Display buffer */
char display_buf[80];

void demo_message(void)
{
glcd_outtextxyf(0,0,"ADS7846 Resistive Touch Controller Demo");
}

flash RTPOINT_t test_points[]={{20,30}, {100,100}, {200,200}};

void main()
{
GLCDINIT_t tft_init_data;
unsigned char n;
unsigned short x,y;
bit result;

/* Set the ATxmega128A1 to run from the internal 32MHz oscillator */
system_clocks_init();

/* Initialize timer TCC0 */
tcc0_init();

/* Turn on backlight */
SETBIT(PORTE.DIR,5);
SETBIT(PORTE.OUT,5);

#asm("sei")

/* LCD controller initialization data */
/* Set default font 5x7 */
tft_init_data.font=font5x7;
/* No external mem. read function */ 
tft_init_data.readxmem=NULL;
/* No external mem. write function */ 
tft_init_data.writexmem=NULL;
/* SSD1963 crystal [kHz] */ 
tft_init_data.ctrl_clk=10000; 
/* ER-TFTM043-4 4.3" 480x272 TFT display parameters from the datasheet */
/* TFT pixel clock [kHz] */
tft_init_data.tft_pixel_clk=9000; 
tft_init_data.hpulse_width=41;
tft_init_data.hfront_porch=2;
tft_init_data.hback_porch=2;
tft_init_data.vpulse_width=10;
tft_init_data.vfront_porch=2;
tft_init_data.vback_porch=2;
/* 24 bit panel data width for ER-TFTM043-4 */
tft_init_data.tft24bit=SSD1963_TFT_DATA_WIDTH24;
/* dot clock pulse polarity */
tft_init_data.lshift=SSD1963_DEFAULT_LSHIFT;
/* Normal display, no horizontal reverse */ 
tft_init_data.reverse_x=SSD1963_REVX_NORM;
/* Normal display, no vertical reverse */ 
tft_init_data.reverse_y=SSD1963_REVY_NORM;
/* Pixel order: BGR for ER-TFTM043-4 */
tft_init_data.cl_bits_order=SSD1963_CL_BITS_BGR; 

/* Initialize the LCD controller */
glcd_init(&tft_init_data);

/***** The most important, otherwise the ER-TFTM043-4 display will not start *****/
ssd1963_wrcmd(SSD1963_CMD_SET_GPIO_CONF);
ssd1963_wrdata(0x0F); /* GPIO is controlled by the host GPIO[3:0]=output GPIO[0]=1  LCD ON  GPIO[0]=1  LCD OFF */
ssd1963_wrdata(0x01); /* GPIO0 normal */
 
ssd1963_wrcmd(SSD1963_CMD_SET_GPIO_VAL);
ssd1963_wrdata(0x01); /* GPIO[0] out 1 --- LCD display on/off control PIN */
/*********************************************************************************/

demo_message();

/* Interrupt system initialization in order to be able to sense /PENIRQ
   generated by the ADS7846, using TCC0 overflow interrupt */
// Optimize for speed
#pragma optsize- 
// Low level interrupt: On
// Round-robin scheduling for low level interrupt: Off
// Medium level interrupt: Off
// High level interrupt: Off
// The interrupt vectors will be placed at the start of the Application FLASH section
n=(PMIC.CTRL & (~(PMIC_RREN_bm | PMIC_IVSEL_bm | PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm))) |
	PMIC_LOLVLEN_bm;
CCP=CCP_IOREG_gc;
PMIC.CTRL=n;
// Set the default priority for round-robin scheduling
PMIC.INTPRI=0x00;
// Restore optimization for size if needed
#pragma optsize_default

/* Initialize the ADS7846 resistive touch controller in differential mode */
if (!rt_init(RTOUCH_MODE_DIFFERENTIAL))
   {
   /* Globally enable interrupts in order to be able to sense /PENIRQ */
   #asm("sei")
   
   /* No valid touch controller calibration data found in EEPROM,
      so we need top calibrate it now */
   if (!calibrate_touchscreen())
      {
      glcd_outtextxyf(0,20,"Touch controller calibration failed");
      while (1); /* Calibration error, stop here */
      }

   glcd_outtextxyf(0,20,"Touch controller calibrated OK");
   delay_ms(3000);
   glcd_clear();
   demo_message();
   }

/* Globally enable interrupts in order to be able to sense /PENIRQ */
#asm("sei")

/* Plot some points and ask the user to touch them */
glcd_outtextxyf(0,10,"Touch cross center to read coordinates");
for (n=0; n<sizeof(test_points)/sizeof(RTPOINT_t); n++)
    {
    display_rt_point(test_points[n]);
    result=rt_getxy(&x,&y);
    erase_rt_point(test_points[n]);
    if (result)
       {
       sprintf(display_buf,"Coordinates read by the touchscreen:\nX=%d, Y=%d",x,y);
       glcd_outtextxy(0,10,display_buf);
       }
    else
       glcd_outtextxy(0,10,"Error reading coordinates");
    delay_ms(1000);
    }

delay_ms(2000);
glcd_clear();
glcd_outtextf("Touch the screen to draw...");

while (1)
    {
    /* Read a point from the touchscreen and display it */ 
    if (rt_getxy(&x,&y))
       {
       glcd_setpixel(x,y);
       delay_ms(10);
       }
    }
}
