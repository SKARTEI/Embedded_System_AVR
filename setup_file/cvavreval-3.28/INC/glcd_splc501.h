//******************************************************************************
// Library functions for graphic LCDs with the SPLC501C controller
// (C) 2010-2012 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V2.05.7+
// Version: 1.03
//******************************************************************************

//******************************************************************************
// Revision history:
// 
// V1.00      Initial release.
// V1.01      05102011_2 - optimized the internal splc501_busy function
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

#ifndef _GLCD_SPLC501_INCLUDED_
#define _GLCD_SPLC501_INCLUDED_

#include <glcd_types.h>

// SPLC501 controller commands
#define SPLC501_CMD_START_LINE 0x40 // set display start line
#define SPLC501_CMD_SET_PAGE 0xB0 // set display page address
#define SPLC501_CMD_SET_ADDR_LOW 0x00 // set column address bits 0..3
#define SPLC501_CMD_SET_ADDR_HIGH 0x10 // set column address bits 4..7
#define SPLC501_CMD_ADC_SELECT_NORM 0xA0 // set relationship between RAM column address and
                                         // display driver: normal
#define SPLC501_CMD_ADC_SELECT_REV 0xA1  // set relationship between RAM column address and
                                         // display driver: reversed
#define SPLC501_CMD_DISP_NORMAL 0xA6 // set normal display mode 
#define SPLC501_CMD_DISP_REVERSE 0xA7 // set reversed display mode
#define SPLC501_CMD_PIXELS_NORMAL 0xA4 // display the graphic RAM contents
#define SPLC501_CMD_ALL_PIXELS_ON 0xA5 // all display pixels are on
#define SPLC501_CMD_DISP_OFF 0xAE // display off
#define SPLC501_CMD_DISP_ON 0xAF // display on
#define SPLC501_CMD_LCD_BIAS_19 0xA2 // sets voltage ratio for LCD bias to 1/9
#define SPLC501_CMD_LCD_BIAS_17 0xA3 // sets voltage ratio for LCD bias to 1/7
#define SPLC501_CMD_COM0_63 0xC0 // sets the COM output scan direction 0->63
#define SPLC501_CMD_COM63_0 0xC8 // sets the COM output scan direction 63->0
#define SPLC501_CMD_POWER_CTRL 0x28 // turns on/off the voltage follower (| bit 0),
                                    // voltage regulator (| bit 1), voltage booster (| bit 2)
#define SPLC501_VOLT_FOLLOWER_ON (1<<0)  // enable voltage follower
#define SPLC501_VOLT_REGULATOR_ON (1<<1) // enable voltage regulator
#define SPLC501_VOLT_BOOSTER_ON (1<<2)   // enable voltage booster

#define SPLC501_CMD_VOLT_REG_V5 0x20 // sets the V5 voltage regulator internal resistor ratio
#define SPLC501_CMD_ELECTRONIC_VOLUME 0x81 // sets the electronic volume register in order
                                           // to control the V5 LCD drive voltage
                                       
#define SPLC501_CMD_SET_DRIVING_MODE 0xD2 // used to set the LCD driving mode

#define SPLC501_CMD_RESET 0xE2 // resets the controller

// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char lcd_bias:1;     // =0 1/9 LCD bias, =1 1/7 LCD bias
        unsigned char reverse_x:1; // reverse display horizontally (ADC), 20022012_1 
        // 23112011_1, 20022012_2
        unsigned char rev132_x0:1; // set to 1 for displays that use reversed RAM column address (reverse_x=1)
                                   // driver and the pixel with x=0 is connected to column driver #132
        unsigned char reverse_y:1; // reverse display vertically (COM), 20022012_3 
        unsigned char volt_reg_v5:3; // set V5 voltage regulator internal resistor ratio [0..7]
        unsigned char driving_mode:2; // set LCD driving mode:
                                      // 0 - mode 1, 1 - mode 2, 2 - mode 3, 3 - mode 4
        unsigned char lcd_contrast:5; // LCD contrast voltage: [0..63]
        } GLCDINIT_t;
        
// values used for lcd_bias initialization 
#define SPLC501_LCD_BIAS_19 0 // sets LCD bias drive ratio 1/9
#define SPLC501_LCD_BIAS_17 1 // sets LCD bias drive ratio 1/7

// values used for reverse_x initialization, 20022012_1 
#define SPLC501_REVX_NORM 0 // set relationship between RAM column address and
                            // display driver: normal (ADC=0)
#define SPLC501_REVX_REV 1  // set relationship between RAM column address and
                            // display driver: reversed (ADC=1)

// 23112011_1
// values used for rev132_x0 initilization
// effective only when reverse_x=1 (SPLC501_REVX_REV)
#define SPLC501_REV132_X0NC 0  // pixel with x=0 is not connected to column driver #132 when ADC=1
#define SPLC501_REV132_X0CON 1 // pixel with x=0 is connected to column driver #132 when ADC=1

// values used for reverse_y initialization, 20022012_3 
#define SPLC501_REVY_NORM 0 // sets the vertical COM output scan direction 0->63
#define SPLC501_REVY_REV 1  // sets the vertical COM output scan direction 63->0

// values used for driving_mode initialization
#define SPLC501_DRIVING_MODE1 0 // driving mode 1  
#define SPLC501_DRIVING_MODE2 1 // driving mode 2  
#define SPLC501_DRIVING_MODE3 2 // driving mode 3  
#define SPLC501_DRIVING_MODE4 3 // driving mode 4  

// default initialization values
#define SPLC501_DEFAULT_LCD_BIAS SPLC501_LCD_BIAS_19 // default value for LCD bias
#define SPLC501_DEFAULT_REVX SPLC501_REVX_NORM // default value for reverse_x, 20022012_1
// 23112011_1
// effective only when reverse_x=1 (SPLC501_REVX_REV)
#define SPLC501_DEFAULT_REV132_X0 SPLC501_REV132_X0NC // default value for rev132_x0, 20022012_2
#define SPLC501_DEFAULT_REVY SPLC501_REVY_NORM // default value for reverse_y, 20022012_3

#define SPLC501_DEFAULT_VOLT_REG_V5 6 // default V5 voltage regulator internal resistor ratio
#define SPLC501_DEFAULT_DRIVING_MODE SPLC501_DRIVING_MODE1 // default LCD driving mode
#define SPLC501_DEFAULT_CONTRAST 7 // default contrast

// Writes a command to the LCD controller
void splc501_wrcmd(unsigned char cmd);
// Sets the LCD contrast [0..63]
void splc501_setcontrast(unsigned char contrast);

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

#pragma library glcd_splc501.lib

#endif




