/***************************************************************
RAiO Technology RA8875 Color TFT and
FocalTech Systems FT5206 Capacitve Touchscreen 
controllers demo.
(C) Copyright 2011-2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

This program can't be compiled with the Evaluation or
Standard versions of CodeVisionAVR, because the glcd_ra8875.lib
file is supplied only with the Advanced license.
In this case you can program the ATxmega128A1 FLASH with
the contents of the
\EXAMPLES\Graphic Displays\Capacitive Touchscreen\FT5206\Release\Exe\ct_demo.hex
file.

The demo is designed to run on the Atmel XMEGA-A1 Xplained
development board with an ATxmega128A1
chip using the internal 32 MHz oscillator
as clock source.

In this demo the RA8875 controller operates in 
8 bit interface mode.
For better performance the 16 bit operating mode can
be selected by accessing the
Project|Configure|C Compiler|Libraries|Graphic LCD menu.
In this situation the DB8-DB15 signals must be also
connected to one of the ATxmega128A1 ports.   

A 800x480 7" type ER-TFTM070-5 TFT LCD module from 
East Rising Technology Co. Ltd. (http://www.buydisplay.com) 
is used for the purpose of this demo.
It can be replaced with other similar modules with
the RA8875 TFT and FT5206 touchscreen controllers. 

The TFT display module connections are:
DB0      - PORTA bit 0
DB1      - PORTA bit 1
DB2      - PORTA bit 2
DB3      - PORTA bit 3
DB4      - PORTA bit 4
DB5      - PORTA bit 5
DB6      - PORTA bit 6
DB7      - PORTA bit 7

DB8      - GND, from from PORTA header pin 9 of 
                the Atmel XMEGA-A1 Xplained board
DB9      - GND
DB10     - GND
DB11     - GND
DB12     - GND
DB13     - GND
DB14     - GND
DB15     - GND

/CS      - PORTD bit 6
RS       - PORTD bit 7
/RD      - PORTD bit 2
/WR      - PORTD bit 3
/RESET   - PORTD bit 4

FT5206 touchscreen controller signals:
CTP_SDA  - PORTD bit 0, has 10k pull-up resistor on the display board
CTP_SCL  - PORTD bit 1, has 10k pull-up resistor on the display board
CTP_WAKE - not connected, has 10k pull-up resistor on the display board
CTP_/RST - PORTD bit 4
CTP_/INT - PORTD bit 5

BL_CONTROL - 3.3V from PORTD header pin 10 of 
             the Atmel XMEGA-A1 Xplained board
VSS        - GND from PORTD header pin 9 of
             the Atmel XMEGA-A1 Xplained board
VDD        - +5V from external power supply 
             (Jumper JP8 on the ER-TFTM070-5 must be OPEN)

The following jumpers must be set on the module:
J6, J9, J12, J13, J15

The following jumpers must be opened on the module:
J7, J8, J10, J11, J14, J16

The TFT controller connections can be modified by accessing
the Project|Configure|C Compiler|Libraries|Graphic LCD menu.
***************************************************************/

#include <io.h>
#include <glcd.h>
#include <delay.h>
#include <stdio.h>
#include <font5x7.h>
#include "arial_bold14.h"
/* FT5206 capacitive touchscreen controller functions */
#include <ft5x06.h>
/* Initialization functions */
#include "init.h"
/* Touched point display functions */
#include "cross.h"
/* Functions used for displaying a button */
#include "button.h"
#include "ok_glyph.h"

/* I/O PORTD Pin used for sensing the touchscreen controller's /INT signal */
#define CT_INT_PIN 5

/* Display buffer */
char display_buf[80];

/* "Next" button initialization data */
button_t button_next=
{
.left=60,
.top=410,
.width=80,
.height=30,
.border_color=GLCD_CL_BLUE,
.bg_color=GLCD_CL_LIGHT_GRAY,
.pressed_color=GLCD_CL_WHITE,
.text_color=GLCD_CL_BLACK,
.glyph_tp_color=GLCD_CL_WHITE,
.glyph=ok_glyph,
.caption="Next",
.font=arial_bold14
};

/* TWI clock rate [bps] */
#define TWI_CLK_RATE 100000

/* Structure that holds information used by the 
   TWID master peripheral for performing a TWI 
   bus transaction */
TWI_MASTER_INFO_t twid_master;
  
/* Interrupt sevice routine for the 
   TWID peripheral in master mode */
interrupt [TWID_TWIM_vect] void twid_master_isr(void)
{
twi_master_int_handler(&twid_master);
}

/* PORTD interrupt 0 service routine 
   triggered by a high to low transition
   on PORTD Pin 5 */
interrupt [PORTD_INT0_vect] void portd_int0_isr(void)
{
/* Process the touchscreen controller's interrupt.
   Ensure that the interrupt was from PORTD Pin 5
   (Pin 5 is low level), in case this ISR will be 
   used later for other pins' interrupts too. */
if (TSTBIT(PORTD.IN,CT_INT_PIN)==0) ct_inthandler();
/* You may add additional code here ... */
}

/* Returns true if the displayed touch point "+" or its
   displayed text coordinates overlap the "Next" button */
bool test_btn_overlap(CTPOINT_t point)
{
if ((point.x>(button_next.left-50)) && (point.x<(button_next.left+button_next.width+50)) &&
   (point.y>=(button_next.top-20)) && (point.y<(button_next.top+button_next.height+20))) return true;
return false;
}

void main()
{
unsigned char n;
/* Structure that holds the TFT controller initialization data */
GLCDINIT_t tft_init_data;
struct
     {
     signed char touched; /* # of touched points */
     CTPOINT_t points[5]; /* Touched points coordinates */
     }
     /* Data for previously touched points */
     pdata0,
     /* Data for currently touched points */
     pdata;

/* Set the ATxmega128A1 to run from the internal 32MHz oscillator */
system_clocks_init();

/* LCD controller initialization data */
/* Set default font 5x7 */
tft_init_data.font=font5x7;
/* No external mem. read function */ 
tft_init_data.readxmem=NULL;
/* No external mem. write function */ 
tft_init_data.writexmem=NULL;
/* Set horizontal display reverse state */
tft_init_data.reverse_x=RA8875_DEFAULT_REVX;
/* Set vertical display reverse state */
tft_init_data.reverse_y=RA8875_DEFAULT_REVY;
/* Specify the external crystal oscillator''s clock frequency [kHz] */
tft_init_data.osc_clk=20000;
/* Specify the TFT pixel clock frequency [kHz] */
tft_init_data.pixel_clk=30000;

/* Initializes the RA8875 TFT controller.
   Also resets the FT5206 touchscreen controller,
   because the reset signals of both the
   TFT and touchscreen controllers
   are connected together. */
glcd_init(&tft_init_data);

/* General TWID peripheral initialization:
   no external driver interface
   no SDA hold time */
twi_init(&TWID,false,false);

/* Initialize the TWID as master */
twi_master_init(&twid_master,&TWID,TWI_MASTER_INTLVL_LO_gc,TWI_BAUD_REG(_MCU_CLOCK_FREQUENCY_,TWI_CLK_RATE));

/* Configure PORTD Pin 5 to sense the 
   touchscreen controller's /INT signal.
   Set Pin 5 as input. */
CLRBIT(PORTD.DIR,CT_INT_PIN);
/* Pin 5 Input/Sense configuration: Sense falling edge */
PORTD.PIN5CTRL=PORT_ISC_FALLING_gc;
/* Interrupt 0 level: Low
   Interrupt 1 level: Disabled */
PORTD.INTCTRL=(PORTC.INTCTRL & (~(PORT_INT1LVL_gm | PORT_INT0LVL_gm))) |
	PORT_INT1LVL_OFF_gc | PORT_INT0LVL_LO_gc;
/* Pin 0 Pin Change interrupt 0: Off
   Pin 1 Pin Change interrupt 0: Off
   Pin 2 Pin Change interrupt 0: Off
   Pin 3 Pin Change interrupt 0: Off
   Pin 4 Pin Change interrupt 0: Off
   Pin 5 Pin Change interrupt 0: On - triggered by the touchscreen controller's /INT signal
   Pin 6 Pin Change interrupt 0: Off
   Pin 7 Pin Change interrupt 0: Off */
PORTD.INT0MASK=(1<<CT_INT_PIN);

/* Interrupt system initialization */
/* Optimize for speed */
#pragma optsize-
/* Low level interrupt: On
   Round-robin scheduling for low level interrupt: Off
   Medium level interrupt: Off
   High level interrupt: Off */
n=PMIC_LOLVLEN_bm;
CCP=CCP_IOREG_gc;
PMIC.CTRL=n;
/* Restore optimization for size if needed */
#pragma optsize_default

/* Enable interrupts for communication 
   with the touchscreen controller 
   using the TWID peripheral and
   sensing the /INT signal */
#asm("sei") 

glcd_outtextxyf(0,0,"FT5206 Capacitive Touchscreen controller demo");

/* Initialize the capacitive touch controller */
if (!ct_init(&twid_master))
   {
   glcd_outtextxyf(0,10,"Touchscreen controller initialization failed");
   while (1);
   }

glcd_outtextxyf(0,10,"Please touch the screen...");
glcd_outtextxyf(0,20,"Or touch the \"Next\" button to continue with the demo");

/* Create the "Next" button */
button_init(&button_next);

/* Use 5x7 font for displaying */
glcd_setfont(font5x7);

/* Initially there's no previously touched point to erase */
pdata0.touched=0;
while (1)
    {
    /* Read a point from the touchscreen and display it */
    pdata.touched=ct_getxy(&pdata.points[0].x,&pdata.points[0].y);
    if (pdata.touched>0) /* Touched point detected */
       {
       /* If necessary, erase the previously displayed touched point,
          making sure not to overlap the "Next" button */
       if (pdata0.touched && (!test_btn_overlap(pdata0.points[0]))) 
          erase_ct_point(pdata0.points[0]);
       /* Check if the user has touched the "Next" button */
       if ((pdata.points[0].x>=button_next.left) && (pdata.points[0].x<(button_next.left+button_next.width)) &&
          (pdata.points[0].y>=button_next.top) && (pdata.points[0].y<(button_next.top+button_next.height)))
          {
          /* Yes, switch to the next part of the demo */
          /* Signal that the button was pressed */
          button_next.pressed=true;
          button_update(&button_next);
          /* Wait 1 second, so the user can see that the button was pressed */
          delay_ms(1000);
          button_next.pressed=false;
          break; 
          }
       /* No, save new touched point data, 
          so it can be erased in the next cycle */
       pdata0=pdata;
       /* Display the new touched point,
          making sure not to overlap the "Next" button */
       if (!test_btn_overlap(pdata.points[0])) display_ct_point(pdata.points[0]);
       }
    }

glcd_clear();    
/* Use 5x7 font for displaying */
glcd_setfont(font5x7);
/* Restore the foreground color */
glcd_setcolor(GLCD_CL_WHITE);
glcd_outtextf("Detect touching multiple points\n"
              "Touch the screen with up to 5 fingers at the same time");

/* Initially there are no previously touched points to erase */
pdata0.touched=0;
while (1)
    {
    /* Get the # of touched points */
    pdata.touched=ct_getpoints(pdata.points);
    if (pdata.touched>0) /* Touched point(s) detected */
       {
       /* If necessary, erase previously displayed point(s) */ 
       for (n=0; n<pdata0.touched; n++) erase_ct_point(pdata0.points[n]);
       /* Save new touched point(s) data, 
          so they can be erased in the next cycle */
       pdata0=pdata;
       /* Display them */
       for (n=0; n<pdata0.touched; n++) display_ct_point(pdata0.points[n]);
       /* Display the # of touched points */
       sprintf(display_buf,"Touched point(s): %1d",pdata0.touched);
       glcd_outtextxy(0,30,display_buf);
       }
    }
}
