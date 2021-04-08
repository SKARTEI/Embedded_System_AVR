//*****************************************************************************
// Library functions for graphic LCDs with the EPSON S1D13700 controller
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

#ifndef _GLCD_S1D13700_INCLUDED_
#define _GLCD_S1D13700_INCLUDED_

#include <glcd_types.h>

// S1D13700 commands
#define S1D13700_SYSTEM_SET 0X40  // Initialize device and display
#define S1D13700_MWRITE 0X42  // Write to display memory
#define S1D13700_MREAD 0x43  // Read from display memory
#define S1D13700_SCROLL 0X44  // Set display start address and display regions
#define S1D13700_CSRW 0X46 // Set cursor address
#define S1D13700_CSRR 0X47 // Read cursor address
#define S1D13700_CSRDIR_RIGHT 0X4C  // Set direction of cursor movement to right
#define S1D13700_POWER_SAVE 0X53  // Enter standby mode
#define S1D13700_DISP_ON_OFF 0X58  // Enable/disable display and display flashing
#define S1D13700_HDOT_SCR 0X5A  // Set horizontal scroll position
#define S1D13700_OVLAY 0X5B  // Set display overlay format
#define S1D13700_CGRAM_ADDR 0X5C  // Set start address of character generator RAM
#define S1D13700_CSRFORM 0X5D  // Set cursor type
#define S1D13700_GRAYSCALE 0x60 // Set grayscale depth

// S1D13700 initialization parameters
#define S1D13700_CHARS_LINE (_GLCD_MAXX_/_GLCD_INTERNAL_FONT_WIDTH_)
#define S1D13700_TXT_SIZE (S1D13700_CHARS_LINE*(_GLCD_MAXY_/_GLCD_INTERNAL_FONT_HEIGHT_))
#define S1D13700_GFX_START (0+S1D13700_TXT_SIZE)
#define S1D13700_GFX_SIZE (((unsigned long) _GLCD_MAXX_*_GLCD_MAXY_)/8)
#define S1D13700_CG_START (0+S1D13700_TXT_SIZE+S1D13700_GFX_SIZE)

#define S1D13700_M0 0 // internal character generator ROM
#define S1D13700_M2 0 // 8 pixel char height for bitmaps
#define S1D13700_WS 0 // single panel drive
#define S1D13700_IV 1 // no screen-top line correction
#define S1D13700_FX 7 // character width=8 pixels -1
#define S1D13700_FY 7 // character height=8 pixels -1
#define S1D13700_WF 1 // 2 frame AC drive
#define S1D13700_CR (_GLCD_MAXX_/8-1)
#define S1D13700_TCR 0x34
#define S1D13700_LF (_GLCD_MAXY_-1) // # lines per frame -1
#define S1D13700_APL ((_GLCD_MAXX_/8) & 0xFF) // LSB # of addresses per line
#define S1D13700_APH ((_GLCD_MAXX_/8)>>8) // MSB # of addresses per line
#define S1D13700_LINES (_GLCD_MAXY_/_GLCD_INTERNAL_FONT_HEIGHT_)
#define S1D13700_SAD1L 0 // LSB_start_text_area
#define S1D13700_SAD1H 0 // MSB_start_text_area
#define S1D13700_SL1 (_GLCD_MAXY_-1) // # screen lines -1 per scrolling screen for text screen
#define S1D13700_SAD2L (S1D13700_GFX_START & 0xFF)
#define S1D13700_SAD2H (S1D13700_GFX_START>>8)
#define S1D13700_SL2 (_GLCD_MAXY_-1) // # screen lines -1 per scrolling line for graphics screen
#define S1D13700_SAD3L 0 // layer 3 not used
#define S1D13700_SAD3H 0
#define S1D13700_SAD4L 0 // layer 4 not used
#define S1D13700_SAD4H 0
#define S1D13700_SAGL (S1D13700_CG_START & 0xFF)
#define S1D13700_SAGH (S1D13700_CG_START>>8)
#define S1D13700_CRX 3 // cursor width 8 pixels
#define S1D13700_CRY 7 // cursor on line 8
#define S1D13700_CM 0 // underscore cursor
#define S1D13700_MX0 0 // OR text with graphics
#define S1D13700_MX1 0
#define S1D13700_DM1 0 // screen block 1 in text mode
#define S1D13700_DM2 0 // screen block 3 in text mode
#define S1D13700_OV  0 // 2 layers

#define S1D13700_P1_SYSTEM_SET (0x10 | (S1D13700_IV<<5) | (S1D13700_WS<<3) | (S1D13700_M2<<2) | S1D13700_M0)
#define S1D13700_P2_SYSTEM_SET ((S1D13700_WF<<7) | S1D13700_FX)
#define S1D13700_P3_SYSTEM_SET S1D13700_FY  
#define S1D13700_P4_SYSTEM_SET S1D13700_CR
#define S1D13700_P5_SYSTEM_SET S1D13700_TCR 
#define S1D13700_P6_SYSTEM_SET S1D13700_LF  
#define S1D13700_P7_SYSTEM_SET S1D13700_APL
#define S1D13700_P8_SYSTEM_SET S1D13700_APH

#define S1D13700_P1_SCROLL S1D13700_SAD1L  
#define S1D13700_P2_SCROLL S1D13700_SAD1H  
#define S1D13700_P3_SCROLL S1D13700_SL1
#define S1D13700_P4_SCROLL S1D13700_SAD2L 
#define S1D13700_P5_SCROLL S1D13700_SAD2H
#define S1D13700_P6_SCROLL S1D13700_SL2
#define S1D13700_P7_SCROLL S1D13700_SAD3L
#define S1D13700_P8_SCROLL S1D13700_SAD3H
#define S1D13700_P9_SCROLL S1D13700_SAD4L
#define S1D13700_P10_SCROLL S1D13700_SAD4H

#define S1D13700_P1_CSR_FORM S1D13700_CRX
#define S1D13700_P2_CSR_FORM ((S1D13700_CM<<7) | S1D13700_CRY)

#define S1D13700_P1_HDOT_SCR 0x00 // 0 pixels to scroll

#define S1D13700_P1_OVLAY ((S1D13700_OV<<4) | (S1D13700_DM2<<3) | (S1D13700_DM1<<2) | (S1D13700_MX1<<1) | S1D13700_MX0)
#define S1D13700_P1_DISP 0x14  // Cursor Off, second screen No flashing
                               // Screen block 1 On, Screen block 2 On
                               // Screen block 3 Off, Screen block 3 Off

#if _GLCD_COLOR_BITS_==4
#define S1D13700_P1_GRAYSCALE 2 // 4 grayscale bits/pixel
#elif _GLCD_COLOR_BITS_==2
#define S1D13700_P1_GRAYSCALE 1 // 2 grayscale bits/pixel
#else
#define S1D13700_P1_GRAYSCALE 0 // 1 grayscale bits/pixel
#endif

// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data); 
        } GLCDINIT_t;

// Writes a command to the S1D13700 controller.
void s1d_wrcmd(unsigned char cmd);
// Writes data to the S1D13700 controller.
void s1d_wrdata(unsigned char data);
// Reads data from the S1D13700 controller.
unsigned char s1d_rddata(void);
        
// Initializes the graphic controller and clears the LCD.
bool glcd_init(GLCDINIT_t *init_data);
// Turns LCD on/off.
void glcd_display(bool on);
// Clears the LCD by setting it's color to the background color.
void glcd_clear(void);
// Clears the text area when the internal character generator is used.
void glcd_cleartext(void);
// Clears the graphics area by setting it's color to the background color.
void glcd_cleargraphics(void);
// Sets the color of the pixel at coordinates x, y.
void glcd_putpixel(GLCDX_t x, GLCDY_t y, GLCDCOL_t color);
// Returns the color of the pixel at coordinates x, y.
GLCDCOL_t glcd_getpixel(GLCDX_t x, GLCDY_t y);

// Displays an ASCII character at the col, row character positions using the
// Character Generator
void glcd_putcharcg(unsigned char col,unsigned char row,unsigned char c);
// Defines a character in the Character Generator external RAM, c>=0x80.
void glcd_definechar(unsigned char c,flash unsigned char *data);

// Writes/reads a block of bytes as a bitmap image
// at/from specified coordinates.
void glcd_block(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDMEM_t memt, GLCDMEMADDR_t addr, GLCDBLOCKMODE_t mode);

#pragma library glcd_s1d13700.lib

#endif




