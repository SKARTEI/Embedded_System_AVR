//*****************************************************************************
// Library functions for graphic LCDs with the EPSON SED1335 controller
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

#ifndef _GLCD_SED1335_INCLUDED_
#define _GLCD_SED1335_INCLUDED_

#include <glcd_types.h>

// SED1335 commands
#define SED1335_SYSTEM_SET 0X40  // Initialize device and display
#define SED1335_MWRITE 0X42  // Write to display memory
#define SED1335_MREAD 0x43  // Read from display memory
#define SED1335_SCROLL 0X44  // Set display start address and display regions
#define SED1335_CSRW 0X46 // Set cursor address
#define SED1335_CSRR 0X47 // Read cursor address
#define SED1335_CSRDIR_RIGHT 0X4C  // Set direction of cursor movement to right
#define SED1335_SLEEP_IN 0X53  // Enter standby mode
#define SED1335_DISP_ON_OFF 0X58  // Enable/disable display and display flashing
#define SED1335_HDOT_SCR 0X5A  // Set horizontal scroll position
#define SED1335_OVLAY 0X5B  // Set display overlay format
#define SED1335_CGRAM_ADDR 0X5C  // Set start address of character generator RAM
#define SED1335_CSRFORM 0X5D  // Set cursor type

// SED1335 initialization parameters
#define SED1335_CHARS_LINE (_GLCD_MAXX_/_GLCD_INTERNAL_FONT_WIDTH_)
#define SED1335_TXT_SIZE (SED1335_CHARS_LINE*(_GLCD_MAXY_/_GLCD_INTERNAL_FONT_HEIGHT_))
#define SED1335_GFX_START (0+SED1335_TXT_SIZE)
#define SED1335_GFX_SIZE (((unsigned long) _GLCD_MAXX_*_GLCD_MAXY_)/8)
#define SED1335_CG_START (0+SED1335_TXT_SIZE+SED1335_GFX_SIZE)

#define SED1335_M0 0 // internal character generator ROM
#define SED1335_M1 1 // D6 correction
#define SED1335_M2 0 // 8 pixel char height for bitmaps
#define SED1335_WS 0 // single panel drive
#define SED1335_IV 1 // no screen-top line correction
#define SED1335_FX 7 // character width=8 pixels -1
#define SED1335_FY 7 // character height=8 pixels -1
#define SED1335_WF 1 // 2 frame AC drive
#define SED1335_CR (_GLCD_MAXX_/8-1)
#define SED1335_TCR 90
#define SED1335_LF (_GLCD_MAXY_-1) // # lines per frame -1
#define SED1335_APL ((_GLCD_MAXX_/8) & 0xFF) // LSB # of addresses per line
#define SED1335_APH ((_GLCD_MAXX_/8)>>8) // MSB # of addresses per line
#define SED1335_LINES (_GLCD_MAXY_/_GLCD_INTERNAL_FONT_HEIGHT_)
#define SED1335_SAD1L 0 // LSB_start_text_area
#define SED1335_SAD1H 0 // MSB_start_text_area
#define SED1335_SL1 (_GLCD_MAXY_-1) // # screen lines -1 per scrolling screen for text screen
#define SED1335_SAD2L (SED1335_GFX_START & 0xFF)
#define SED1335_SAD2H (SED1335_GFX_START>>8)
#define SED1335_SL2 (_GLCD_MAXY_-1) // # screen lines -1 per scrolling line for graphics screen
#define SED1335_SAD3L 0 // layer 3 not used
#define SED1335_SAD3H 0
#define SED1335_SAD4L 0 // layer 4 not used
#define SED1335_SAD4H 0
#define SED1335_SAGL (SED1335_CG_START & 0xFF)
#define SED1335_SAGH (SED1335_CG_START>>8)
#define SED1335_CRX 3 // cursor width 8 pixels
#define SED1335_CRY 7 // cursor on line 8
#define SED1335_CM 0 // underscore cursor
#define SED1335_MX0 0 // OR text with graphics
#define SED1335_MX1 0
#define SED1335_DM1 0 // screen block 1 in text mode
#define SED1335_DM2 0 // screen block 3 in text mode
#define SED1335_OV  0 // 2 layers

#define SED1335_P1_SYSTEM_SET (0x10 | (SED1335_IV<<5) | (SED1335_WS<<3) | (SED1335_M2<<2) | (SED1335_M1<<1) | SED1335_M0)
#define SED1335_P2_SYSTEM_SET ((SED1335_WF<<7) | SED1335_FX)
#define SED1335_P3_SYSTEM_SET SED1335_FY  
#define SED1335_P4_SYSTEM_SET SED1335_CR
#define SED1335_P5_SYSTEM_SET SED1335_TCR 
#define SED1335_P6_SYSTEM_SET SED1335_LF  
#define SED1335_P7_SYSTEM_SET SED1335_APL
#define SED1335_P8_SYSTEM_SET SED1335_APH

#define SED1335_P1_SCROLL SED1335_SAD1L  
#define SED1335_P2_SCROLL SED1335_SAD1H  
#define SED1335_P3_SCROLL SED1335_SL1
#define SED1335_P4_SCROLL SED1335_SAD2L 
#define SED1335_P5_SCROLL SED1335_SAD2H
#define SED1335_P6_SCROLL SED1335_SL2
#define SED1335_P7_SCROLL SED1335_SAD3L
#define SED1335_P8_SCROLL SED1335_SAD3H
#define SED1335_P9_SCROLL SED1335_SAD4L
#define SED1335_P10_SCROLL SED1335_SAD4H

#define SED1335_P1_CSR_FORM SED1335_CRX
#define SED1335_P2_CSR_FORM ((SED1335_CM<<7) | SED1335_CRY)

#define SED1335_P1_HDOT_SCR 0x00 // 0 pixels to scroll

#define SED1335_P1_OVLAY ((SED1335_OV<<4) | (SED1335_DM2<<3) | (SED1335_DM1<<2) | (SED1335_MX1<<1) | SED1335_MX0)
#define SED1335_P1_DISP 0x14  // Cursor Off, second screen No flashing
                              // Screen block 1 On, Screen block 2 On
                              // Screen block 3 Off, Screen block 3 Off

// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data); 
        } GLCDINIT_t;

// Writes a command to the SED1335 controller.
void sed1335_wrcmd(unsigned char cmd);
// Writes data to the SED1335 controller.
void sed1335_wrdata(unsigned char data);
// Reads data from the SED1335 controller.
unsigned char sed1335_rddata(void);
// Specifies if the BUSY flag should be tested on data read/write in order
// to reduce display flicker
void sed1335_fastmode(unsigned char on);
        
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

#pragma library glcd_sed1335.lib

#endif




