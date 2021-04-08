//******************************************************************************
// Library functions for graphic LCDs with the UltraChip UC1701 controller
// (C) 2010-2012 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V2.05.7+
// Version: 1.01
//******************************************************************************

//******************************************************************************
// Revision history:
// 
// V1.00      Initial release.
// V1.01      20022012_1 - Renamed the "seg_dir" member of GLCDINIT_t to 
//                        "reverse_x"
//            20022012_2 - Renamed the "seg_dir_rev132_x0" member of GLCDINIT_t
//                         to "rev132_x0"
//            20022012_3 - Added the "reverse_y" member to GLCDINIT_t
//******************************************************************************

#ifndef _GLCD_UC1701_INCLUDED_
#define _GLCD_UC1701_INCLUDED_

#include <glcd_types.h>

// UC1701 controller commands
#define UC1701_CMD_SET_SCROLL_LINE 0x40 // set the scroll line number
#define UC1701_CMD_SET_PAGE 0xB0 // set display page address
#define UC1701_CMD_SET_ADDR_LOW 0x00 // set column address bits 0..3
#define UC1701_CMD_SET_ADDR_HIGH 0x10 // set column address bits 4..7
#define UC1701_CMD_SEG_DIR_NORM 0xA0 // set relationship between RAM column address and
                                     // display driver: normal (MX=0)
#define UC1701_CMD_SEG_DIR_REV 0xA1  // set relationship between RAM column address and
                                     // display driver: reversed (MX=1)
#define UC1701_CMD_DISP_NORMAL 0xA6 // set normal display mode 
#define UC1701_CMD_DISP_REVERSE 0xA7 // set reversed display mode
#define UC1701_CMD_PIXELS_NORMAL 0xA4 // display the graphic RAM contents
#define UC1701_CMD_ALL_PIXELS_ON 0xA5 // all display pixels are on
#define UC1701_CMD_STATIC_INDICATOR_OFF 0xAC // turn off static indicator
#define UC1701_CMD_STATIC_INDICATOR_ON 0xAD // turn on static indicator
#define UC1701_CMD_DISP_OFF 0xAE // turn display off
#define UC1701_CMD_DISP_ON 0xAF // turn display on
#define UC1701_CMD_LCD_BIAS_LOW 0xA2  // sets voltage ratio for LCD bias to 1/9 (duty cycle=1/65), 
                                      // 1/8 (duty cycle=1/49), 1/6 (duty cycle=1/33), 1/8 (duty cycle=1/55), 
                                      // 1/8 (duty cycle=1/53)
#define UC1701_CMD_LCD_BIAS_HIGH 0xA3 // sets voltage ratio for LCD bias to 1/7 (duty cycle=1/65),
                                      // 1/6 (duty cycle=1/49), 1/5 (duty cycle=1/33), 1/6 (duty cycle=1/55),
                                      // 1/6 (duty cycle=1/53)
#define UC1701_CMD_COM0_63 0xC0 // sets the COM output scan direction 0->63 (MY=0)
#define UC1701_CMD_COM63_0 0xC8 // sets the COM output scan direction 63->0 (MY=1)

#define UC1701_CMD_POWER_CTRL 0x28 // turns on/off the voltage follower (| bit 0),
                                    // voltage regulator (| bit 1), voltage booster (| bit 2)
#define UC1701_VOLT_FOLLOWER_ON (1<<0)  // enable voltage follower
#define UC1701_VOLT_REGULATOR_ON (1<<1) // enable voltage regulator
#define UC1701_VOLT_BOOSTER_ON (1<<2)   // enable voltage booster

#define UC1701_CMD_VLCD_RES 0x20 // sets the VLCD voltage regulator internal resistor ratio
#define UC1701_CMD_ELECTRONIC_VOLUME 0x81 // sets the electronic volume register in order
                                          // to control the VLCD drive voltage
                                          
#define UC1701_CMD_ADV_PGM_CTRL0 0xFA // advanced program control 0
                                      // used to set LCD temp. compensation coefficient (TC)
                                       
#define UC1701_CMD_RESET 0xE2 // resets the controller

// set cursor update mode when writing to display RAM
// reading from display RAM doesn't affect the column address register CA
#define UC1701_CMD_CURSOR_UPDATE_ON 0xE0 // the column address CA will be incremented
                                         // when writing to display RAM
#define UC1701_CMD_CURSOR_UPDATE_OFF 0xEE // the column address CA will not be incremented
                                          // when writing to display RAM

// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char lcd_bias:1;     // =0 LCD bias voltage ratio low, =1 LCD bias voltage ratio high
        unsigned char reverse_x:1; // reverse display horizontally, 20022012_1 
        // 20022012_2
        unsigned char rev132_x0:1; // set to 1 for displays that use reversed RAM column address (reverse_x=1)
                                   // driver and the pixel with x=0 is connected to column driver #132
        unsigned char reverse_y:1; // reverse display vertically, 20022012_3 
        unsigned char volt_reg_vlcd:3; // set VLCD voltage regulator internal resistor ratio [0..7]
        unsigned char lcd_contrast:5; // LCD contrast voltage: [0..63]
        unsigned char lcd_temp_comp:1; // LCD temperature compensation coefficient (TC) (=0 -0.05%/C, =1 -0.11%/C)
        } GLCDINIT_t;
        
// values used for lcd_bias initialization 
#define UC1701_LCD_BIAS_LOW 0 // sets LCD bias voltage drive ratio 1/9, 1/8, 1/6
#define UC1701_LCD_BIAS_HIGH 1 // sets LCD bias voltage drive ratio 1/7, 1/6, 1/5

// values used for reverse_x initialization, 20022012_1 
#define UC1701_REVX_NORM 0 // set relationship between RAM column address and
                            // display driver: normal (ADC=0)
#define UC1701_REVX_REV 1  // set relationship between RAM column address and
                            // display driver: reversed (ADC=1)

// 23112011_1
// values used for rev132_x0 initilization
// effective only when reverse_x=1 (UC1701_REVX_REV)
#define UC1701_REV132_X0NC 0  // pixel with x=0 is not connected to column driver #132 when ADC=1
#define UC1701_REV132_X0CON 1 // pixel with x=0 is connected to column driver #132 when ADC=1

// values used for reverse_y initialization, 20022012_3 
#define UC1701_REVY_NORM 0 // sets the vertical COM output scan direction 0->63
#define UC1701_REVY_REV 1  // sets the vertical COM output scan direction 63->0

// values used for lcd_temp_comp initialization
#define UC1701_LCD_TEMP_COMP_005 0 // -0.05%/C
#define UC1701_LCD_TEMP_COMP_011 1 // -0.11%/C

// default initialization values
#define UC1701_DEFAULT_LCD_BIAS UC1701_LCD_BIAS_LOW // default value for LCD bias

#define UC1701_DEFAULT_REVX UC1701_REVX_NORM // default value for reverse_x, 20022012_1
// 23112011_1
// effective only when reverse_x=1 (UC1701_REVX_REV)
#define UC1701_DEFAULT_REV132_X0 UC1701_REV132_X0NC // default value for rev132_x0, 20022012_2
#define UC1701_DEFAULT_REVY UC1701_REVY_NORM // default value for reverse_y, 20022012_3

#define UC1701_DEFAULT_VLCD_RES 6 // default VLCD voltage regulator internal resistor ratio
#define UC1701_DEFAULT_CONTRAST 7 // default contrast
#define UC1701_DEFAULT_LCD_TEMP_COMP UC1701_LCD_TEMP_COMP_011 // default LCD temperature compensation coefficient

// Writes a command to the LCD controller
void uc1701_wrcmd(unsigned char cmd);
// Sets the LCD contrast [0..63]
void uc1701_setcontrast(unsigned char contrast);

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

#pragma library glcd_uc1701.lib

#endif




