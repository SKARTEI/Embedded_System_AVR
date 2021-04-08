//*****************************************************************************
// Library functions for graphic LCDs with the Epson SED1530 controller
// (C) 2010-2012 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V2.05.7+
// Version: 1.03
//******************************************************************************

//******************************************************************************
// Revision history:
// 
// V1.00      Initial release.
// V1.01      05102011_2 - optimized the internal sed1530_busy function 
//            05102011_3 - fixed incorrect display when ADC=1
//                         (reversed RAM column address)  
// V1.02      23112011_1 - Added the "adc_rev132_x0" member to the GLCDINIT_t
//                         structure for displays that use reversed RAM column
//                         address driver (ADC=1) and the pixel with x=0 is 
//                         connected to column driver #132. 
// V1.03      20022012_1 - Renamed the "adc" member of GLCDINIT_t to "reverse_x"
//            20022012_2 - Renamed the "adc_rev132_x0" member of GLCDINIT_t to
//                         "rev132_x0"
//            20022012_3 - Added the "reverse_y" member to GLCDINIT_t
//******************************************************************************

#ifndef _GLCD_SED1530_INCLUDED_
#define _GLCD_SED1530_INCLUDED_

#include <glcd_types.h>

// SED1530 controller commands
#define SED1530_CMD_START_LINE 0x40 // set display start line
#define SED1530_CMD_SET_PAGE 0xB0 // set display page address
#define SED1530_CMD_SET_ADDR_LOW 0x00 // set column address bits 0..3
#define SED1530_CMD_SET_ADDR_HIGH 0x10 // set column address bits 4..7
#define SED1530_CMD_ADC_SELECT_NORM 0xA0 // set relationship between RAM column address and
                                         // display driver: normal
#define SED1530_CMD_ADC_SELECT_REV 0xA1  // set relationship between RAM column address and
                                         // display driver: reversed
#define SED1530_CMD_DISP_NORMAL 0xA6 // set normal display mode 
#define SED1530_CMD_DISP_REVERSE 0xA7 // set reversed display mode
#define SED1530_CMD_PIXELS_NORMAL 0xA4 // display the graphic RAM contents
#define SED1530_CMD_ALL_PIXELS_ON 0xA5 // all display pixels are on
#define SED1530_CMD_DISP_OFF 0xAE // display off
#define SED1530_CMD_DISP_ON 0xAF // display on
#define SED1530_CMD_LCD_BIAS_16 0xA2 // sets voltage ratio for LCD bias to 1/6
#define SED1530_CMD_LCD_BIAS_15 0xA3 // sets voltage ratio for LCD bias to 1/5
#define SED1530_CMD_COM0_63 0xC0 // sets the COM output scan direction 0->63
#define SED1530_CMD_COM63_0 0xC8 // sets the COM output scan direction 63->0
#define SED1530_CMD_POWER_CTRL 0x28 // turns on/off the voltage follower (| bit 0),
                                    // voltage regulator (| bit 1), voltage booster (| bit 2)
#define SED1530_VOLT_FOLLOWER_ON (1<<0)  // enable voltage follower
#define SED1530_VOLT_REGULATOR_ON (1<<1) // enable voltage regulator
#define SED1530_VOLT_BOOSTER_ON (1<<2)   // enable voltage booster

#define SED1530_CMD_ELECTRONIC_VOLUME 0x80 // sets the electronic volume register in order
                                           // to control the V5 LCD drive voltage
#define SED1530_CMD_RESET 0xE2 // resets the controller

// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char lcd_bias:1;     // =0 1/6 LCD bias, =1 1/5 LCD bias
        unsigned char reverse_x:1; // reverse display horizontally (ADC), 20022012_1 
        // 23112011_1, 20022012_2
        unsigned char rev132_x0:1; // set to 1 for displays that use reversed RAM column address (reverse_x=1)
                                   // driver and the pixel with x=0 is connected to column driver #132
        unsigned char reverse_y:1; // reverse display vertically (COM), 20022012_3 
        unsigned char lcd_contrast:4; // LCD contrast voltage: [0..31]
        } GLCDINIT_t;
        
// values used for lcd_bias initialization 
#define SED1530_LCD_BIAS_16 0 // sets LCD bias drive ratio 1/6
#define SED1530_LCD_BIAS_15 1 // sets LCD bias drive ratio 1/5

// values used for reverse_x initialization, 20022012_1 
#define SED1530_REVX_NORM 0 // set relationship between RAM column address and
                            // display driver: normal (ADC=0)
#define SED1530_REVX_REV 1  // set relationship between RAM column address and
                            // display driver: reversed (ADC=1)

// 23112011_1
// values used for rev132_x0 initilization
// effective only when reverse_x=1 (SED1530_REVX_REV)
#define SED1530_REV132_X0NC 0  // pixel with x=0 is not connected to column driver #132 when ADC=1
#define SED1530_REV132_X0CON 1 // pixel with x=0 is connected to column driver #132 when ADC=1

// values used for reverse_y initialization, 20022012_3 
#define SED1530_REVY_NORM 0 // sets the vertical COM output scan direction 0->63
#define SED1530_REVY_REV 1  // sets the vertical COM output scan direction 63->0

// default initialization values
#define SED1530_DEFAULT_LCD_BIAS SED1530_LCD_BIAS_16 // default value for LCD bias
#define SED1530_DEFAULT_REVX SED1530_REVX_NORM // default value for reverse_x, 20022012_1
// 23112011_1
// effective only when reverse_x=1 (SED1530_REVX_REV)
#define SED1530_DEFAULT_REV132_X0 SED1530_REV132_X0NC // default value for rev132_x0, 20022012_2
#define SED1530_DEFAULT_REVY SED1530_REVY_NORM // default value for reverse_y, 20022012_3
#define SED1530_DEFAULT_CONTRAST 7 // default contrast

// Writes a command to the LCD controller
void sed1530_wrcmd(unsigned char cmd);
// Sets the LCD contrast [0..31]
void sed1530_setcontrast(unsigned char contrast);

// Initializes the graphic controller and clears the LCD.
bool glcd_init(GLCDINIT_t *init_data);
// Turns LCD on/off.
void glcd_display(bool on);
// Clears the LCD by setting it's color to the background color.
void glcd_clear(void);
// Sets the color of the pixel at coordinates x, y.
void glcd_putpixel(GLCDX_t x, GLCDY_t y, GLCDCOL_t color);
// Returns the color of the pixel at coordinates x, y.
GLCDCOL_t glcd_getpixel(GLCDX_t x, GLCDY_t y);

// Writes/reads a block of bytes as a bitmap image
// at/from specified coordinates.
void glcd_block(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDMEM_t memt, GLCDMEMADDR_t addr, GLCDBLOCKMODE_t mode);

#pragma library glcd_sed1530.lib

#endif




