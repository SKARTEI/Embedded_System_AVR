//*****************************************************************************
// Library functions for graphic LCDs with the Samsung KS0108 controller
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

#ifndef _GLCD_KS0108_INCLUDED_
#define _GLCD_KS0108_INCLUDED_

#include <glcd_types.h>

// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data); 
        } GLCDINIT_t;
        
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

#pragma library glcd_ks0108.lib

#endif




