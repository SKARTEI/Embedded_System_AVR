//*****************************************************************************
// Library functions for graphic LCDs with the Philips PCD8544 controller
// (C) 2010-2011 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V2.05.3+
// Version: 1.01
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00      Initial release.
// 
// V1.01
// 06072011_2 Added GLCD_CLEARBLOCK and GLCD_SETBLOCK modes to the 
//            glcd_block function.
//            These are required by the modified glcd_putchar function from
//            graphics.h
//*****************************************************************************

#ifndef _GLCD_PCD8544_INCLUDED_
#define _GLCD_PCD8544_INCLUDED_

#include <glcd_types.h>

// PCD8544 commands
#define PCD8544_FUNCTION_SET 0x20 // Function set, horizontal addressing
// Puts controller in power-down mode,
// must be combined with PCD8544_FUNCTION_SET
#define PCD8544_POWER_DOWN 0x04
// Use extended instruction set, 
// must be combined with PCD8544_FUNCTION_SET
#define PCD8544_EXT_INST 0x01 

#define PCD8544_DISPLAY_BLANK 0x08 // Sets display blank
#define PCD8544_DISPLAY_NORMAL 0x0C // Sets display normal mode
#define PCD8544_DISPLAY_ALL_ON 0x09 // Sets all display segments on
#define PCD8544_DISPLAY_INVERSE 0x0D // Sets inverse video mode
#define PCD8544_SETX 0X80  // Sets X address of display RAM
#define PCD8544_SETY 0X40  // Sets Y address of display RAM

// Extended instruction set
// enabled by PCD8544_FUNCTION_SET+PCD8544_EXT_INST
#define PCD8544_TEMP_CTRL 0x04 // Sets temperature coefficient
#define PCD8544_BIAS_SYSTEM 0x10 // Sets bias system
#define PCD8544_VLCD 0x80 // Sets VLCD value
 
// PCD8544 initialization parameters
#define PCD8544_GFX_SIZE (_GLCD_MAXX_*_GLCD_MAXY_/8)
// Optimal default values for Nokia 3310, 5110 LCDs
#define PCD8544_DEFAULT_TEMP_COEF 0 // Temp. coefficient
#define PCD8544_DEFAULT_BIAS 3 // Bias System for 1/48 duty cycle
#define PCD8544_DEFAULT_VLCD 0x32 // VLCD

// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data); 
        unsigned char temp_coef:2; // temperature coefficient bits [0..3]
        unsigned char bias:3; // bias system bits [0..7]
        unsigned char vlcd:7; // VLCD set bits [0..127]
        } GLCDINIT_t;

// Writes a command to the PCD8544 controller.
void pcd8544_wrcmd(unsigned char cmd);
// Reads a byte from pixel coordinates x, y.
unsigned char pcd8544_rdbyte(GLCDX_t x, GLCDY_t y);
// Sets the write position at x, y coordinates.
void pcd8544_gotoxy(GLCDX_t x, GLCDY_t y);
// Write a byte to the current write position and increments it.
void pcd8544_wrbyte(unsigned char data);
// Controls the LCD contrast by setting the VLCD value (0..0x7F)
void pcd8544_setvlcd(unsigned char vlcd);
        
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

#pragma library glcd_pcd8544.lib

#endif




