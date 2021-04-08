//******************************************************************************
// Library functions for graphic LCDs with the Sitronix ST7567 controller
// (C) 2010-2016 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.25+
// Version: 1.01
//******************************************************************************

//******************************************************************************
// Revision history:
//
// V1.00      Initial release.
// V1.01      28012016_2 - Added support for SPI interface mode
//******************************************************************************

#ifndef _GLCD_ST7567_INCLUDED_
#define _GLCD_ST7567_INCLUDED_

#include <glcd_types.h>

// ST7567 controller commands
#define ST7567_CMD_START_LINE 0x40 // set display start line
#define ST7567_CMD_SET_PAGE 0xB0 // set display page address
#define ST7567_CMD_SET_ADDR_LOW 0x00 // set column address bits 0..3
#define ST7567_CMD_SET_ADDR_HIGH 0x10 // set column address bits 4..7
#define ST7567_CMD_MX_SELECT_NORM 0xA0 // set relationship between RAM column address and
                                         // display driver: normal
#define ST7567_CMD_MX_SELECT_REV 0xA1  // set relationship between RAM column address and
                                         // display driver: reversed
#define ST7567_CMD_DISP_NORMAL 0xA6 // set normal display mode
#define ST7567_CMD_DISP_REVERSE 0xA7 // set reversed display mode
#define ST7567_CMD_PIXELS_NORMAL 0xA4 // display the graphic RAM contents
#define ST7567_CMD_ALL_PIXELS_ON 0xA5 // all display pixels are on
#define ST7567_CMD_STATIC_INDICATOR_OFF 0xAC // turn off static indicator
#define ST7567_CMD_STATIC_INDICATOR_ON 0xAD // turn on static indicator
#define ST7567_CMD_DISP_OFF 0xAE // display off
#define ST7567_CMD_DISP_ON 0xAF // display on
#define ST7567_CMD_LCD_BIAS_LOW 0xA2  // sets voltage ratio for LCD bias to 1/9 (duty cycle=1/65),
                                      // 1/8 (duty cycle=1/49), 1/6 (duty cycle=1/33), 1/8 (duty cycle=1/55)
#define ST7567_CMD_LCD_BIAS_HIGH 0xA3 // sets voltage ratio for LCD bias to 1/7 (duty cycle=1/65),
                                      // 1/6 (duty cycle=1/49), 1/5 (duty cycle=1/33), 1/6 (duty cycle=1/55)
#define ST7567_CMD_COM0_63 0xC0 // sets the COM output scan direction 0->63
#define ST7567_CMD_COM63_0 0xC8 // sets the COM output scan direction 63->0

#define ST7567_CMD_POWER_CTRL 0x28 // turns on/off the voltage follower (| bit 0),
                                    // voltage regulator (| bit 1), voltage booster (| bit 2)
#define ST7567_VOLT_FOLLOWER_ON (1<<0)  // enable voltage follower
#define ST7567_VOLT_REGULATOR_ON (1<<1) // enable voltage regulator
#define ST7567_VOLT_BOOSTER_ON (1<<2)   // enable voltage booster

#define ST7567_CMD_VOLT_REG_RATIO 0x20 // sets the resistor ratio of the internal voltage regulator
#define ST7567_CMD_ELECTRONIC_VOLUME 0x81 // sets the electronic volume register in order
                                          // to control the V0 LCD drive voltage
#define ST7567_CMD_SET_BOOSTER_LEVEL 0xF8 // sets the booster level
#define ST7567_CMD_RESET 0xE2 // resets the controller
#define ST7567_CMD_NOP 0xE3   // no operation

// structure that contains controller specific graphic LCD initialization data
typedef struct
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr);
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char lcd_bias:1;      // =0 LCD bias voltage ratio low, =1 LCD bias voltage ratio high
        unsigned char reverse_x:1;     // reverse display horizontally (MX)
        unsigned char rev132_x0:1;     // set to 1 for displays that use reversed RAM column address (reverse_x=1)
                                       // driver and the pixel with x=0 is connected to column driver #132
        unsigned char reverse_y:1;     // reverse display vertically (COM)
        unsigned char volt_reg_ratio:3; // sets the resistor ratio of the internal voltage regulator
        unsigned char booster_level:1; // sets the booster level: 0 – x4, 1 – x5
        unsigned char lcd_contrast:6;  // LCD contrast voltage: [0..63]
        } GLCDINIT_t;

// values used for lcd_bias initialization
#define ST7567_LCD_BIAS_LOW 0 // sets LCD bias voltage drive ratio 1/9, 1/8, 1/6
#define ST7567_LCD_BIAS_HIGH 1 // sets LCD bias voltage drive ratio 1/7, 1/6, 1/5

// values used for reverse_x initialization, 20022012_1
#define ST7567_REVX_NORM 0 // set relationship between RAM column address and
                            // display driver: normal (MX=0)
#define ST7567_REVX_REV 1  // set relationship between RAM column address and
                            // display driver: reversed (MX=1)

// values used for rev132_x0 initilization
// effective only when reverse_x=1 (ST7567_REVX_REV)
#define ST7567_REV132_X0NC 0  // pixel with x=0 is not connected to column driver #132 when MX=1
#define ST7567_REV132_X0CON 1 // pixel with x=0 is connected to column driver #132 when MX=1

// values used for reverse_y initialization
#define ST7567_REVY_NORM 0 // sets the vertical COM output scan direction 0->63
#define ST7567_REVY_REV 1  // sets the vertical COM output scan direction 63->0

// values used for volt_reg_ratio initialization
#define ST7567_VOLT_REG_RATIO_3_0 0 // 3.0
#define ST7567_VOLT_REG_RATIO_3_5 1 // 3.5
#define ST7567_VOLT_REG_RATIO_4_0 2 // 4.0
#define ST7567_VOLT_REG_RATIO_4_5 3 // 4.5
#define ST7567_VOLT_REG_RATIO_5_0 4 // 5.0
#define ST7567_VOLT_REG_RATIO_5_5 5 // 5.5
#define ST7567_VOLT_REG_RATIO_6_0 6 // 6.0
#define ST7567_VOLT_REG_RATIO_6_5 7 // 6.5

// values used for booster_level initialization
#define ST7567_BOOSTER_LEVEL_4X 0  // 4x
#define ST7567_BOOSTER_LEVEL_5X 1  // 5x

// default initialization values
#define ST7567_DEFAULT_LCD_BIAS ST7567_LCD_BIAS_LOW // default value for LCD bias
#define ST7567_DEFAULT_REVX ST7567_REVX_NORM // default value for reverse_x
// effective only when reverse_x=1 (ST7567_REVX_REV)
#define ST7567_DEFAULT_REV132_X0 ST7567_REV132_X0NC // default value for rev132_x0
#define ST7567_DEFAULT_REVY ST7567_REVY_NORM // default value for reverse_y
#define ST7567_DEFAULT_VOLT_REG_RATIO ST7567_VOLT_REG_RATIO_6_0 // default internal voltage regulator ratio
#define ST7567_DEFAULT_BOOSTER_LEVEL ST7567_BOOSTER_LEVEL_4X // default booster level
#define ST7567_DEFAULT_CONTRAST 31 // default contrast

// Writes a command to the LCD controller
void st7567_wrcmd(unsigned char cmd);
// Sets the LCD contrast [0..63]
void st7567_setcontrast(unsigned char contrast);

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

#pragma library glcd_st7567.lib

#endif




