#ifndef _GLCD_XG7100_INCLUDED_
#define _GLCD_XG7100_INCLUDED_

/******************************************************************************
    © Copyright DELCOMp 2003-2014, All Rights Reserved
    DELCOMp bvba, Technologielaan 3, B-3001 Leuven, Belgium
    http://www.xgraph.be ©

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. The binary code, with or without modification, can only be installed
    on hardware manufactured and distributed by © DELCOMp or its approved
    distributors and subcontractors.

    2. Redistributions of source code must retain the above copyright notice,
    including the full address and URL, this list of conditions and the following
    disclaimer.

    3. Redistributions in binary form must reproduce the above copyright notice,
    including the full address and URL, this list of conditions and the following
    disclaimer in the documentation and/or other materials provided with the
    distribution.

    4. The name of © DELCOMp may not be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY DELCOMP "AS IS" AND ANY EXPRESS OR IMPLIED
    WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY AND
    SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL DELCOMP BE LIABLE FOR ANY DIRECT,
    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES
    LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
    THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

/* START LIBRARY DESCRIPTION **************************************************
    glcd_xg7100.lib
    Library functions for X-Graph XG7100 4.3 Type B, 5.6" and 7.0" LCD
    
    © Copyright DELCOMp 2003-2014, All Rights Reserved
    DELCOMp bvba, Technologielaan 3, B-3001 Leuven, Belgium
    http://www.xgraph.be ©

    CHANGE HISTORY:
    Date: 1.0, 19 Mar 2012
		  1.1, 29 Jul 2014
			- maxx/maxy added
			- xgraph.h removed
			- default Reset & Ready I/O lines (Port H) added
	
	IMPORTANT ATXMEGA CONFIGURATION:
	- VPORT0 is used by this lib. If this is not allowed disable the VPORT use (see USER DEFINES)
	- The CPU clock is used for the LCD timing and should be 32MHz.
	- The EBI is used. For max. performance it should be clocked at 64MHz using the ATXmega PLL.
	Note: the xgatxmega.lib library includes a function xmega_32MHz_pll() which inits the cpu clock & ebi clock correctly.	
			
	USER DEFINES:
	_GLCD_XG7100_NO_HW_INIT_: if defined will not init the clock output, PORT H & J and EBI interface
	_GLCD_NO_VPORT_: if defined VPORT0 is not used but dedicated I/O pins (see defines below)

*************************************************************	
CodeVision 3.15 integrated defines for XG7100:

XG7100 480x272 TFT 64k Colors
#define _GLCD_MAXX_ 480
#define _GLCD_MAXY_  272
#define _GLCD_MAXX_HW_ 480
#define _GLCD_MAXY_HW_ 272
#define _GLCD_COLOR_BITS_ 16
#define _GLCD_INTERNAL_FONT_WIDTH_ 0
#define _GLCD_INTERNAL_FONT_HEIGHT_ 0
#define _GLCD_CTRL_XG7100_
#define _BOARD_TYPE_ 0xd710

XG7100 320x234 TFT 64k Colors
#define _GLCD_MAXX_ 320
#define _GLCD_MAXY_  234
#define _GLCD_MAXX_HW_ 320
#define _GLCD_MAXY_HW_ 234
#define _GLCD_COLOR_BITS_ 16
#define _GLCD_INTERNAL_FONT_WIDTH_ 0
#define _GLCD_INTERNAL_FONT_HEIGHT_ 0
#define _GLCD_CTRL_XG7100_
#define _BOARD_TYPE_ 0xd711

XG7100 800x480 TFT 64k Colors
#define _GLCD_MAXX_ 800
#define _GLCD_MAXY_  480
#define _GLCD_MAXX_HW_ 800
#define _GLCD_MAXY_HW_ 480
#define _GLCD_COLOR_BITS_ 16
#define _GLCD_INTERNAL_FONT_WIDTH_ 0
#define _GLCD_INTERNAL_FONT_HEIGHT_ 0
#define _GLCD_CTRL_XG7100_
#define _BOARD_TYPE_ 0xd712

END DESCRIPTION *************************************************************/

#if (_GLCD_MAXY_ < 256)
	#undef _GLCD_MAXY_
	#define _GLCD_MAXY_ 257
#endif

#include <glcd_types.h>

#ifdef _GLCD_MAXX_HW_
	#ifdef _GLCD_MAXX_
		#undef _GLCD_MAXX_
	#endif
	extern unsigned short _GLCD_MAXX_;
#endif

#ifdef _GLCD_MAXY_HW_
	#ifdef _GLCD_MAXY_
		#undef _GLCD_MAXY_
	#endif
	extern unsigned short _GLCD_MAXY_;
#endif

#ifdef _GLCD_NO_VPORT_
    // READY
    #define _GLCD_READY_IN_ GETBIT(_GLCD_XG_READY_IN_, _GLCD_XG_READY_BIT_)
    #define _GLCD_ALE_DIR_IN_ {CLRBIT(_GLCD_XG_READY_DIR_,_GLCD_XG_READY_BIT_);}

    // RESET
    #define _GLCD_RESET_LOW_ {CLRBIT(_GLCD_XG_RESET_OUT_,_GLCD_XG_RESET_BIT_);}
    #define _GLCD_RESET_HIGH_ {SETBIT(_GLCD_XG_RESET_OUT_,_GLCD_XG_RESET_BIT_);}
    #define _GLCD_RESET_DIR_OUT_ {SETBIT(_GLCD_XG_RESET_DIR_,_GLCD_XG_RESET_BIT_);}
#else
	#define _GLCD_XG_READY_IN_ VPORT0_IN.5
	#define _GLCD_XG_READY_DIR_ VPORT0_DIR.5

	#define _GLCD_XG_RESET_OUT_ VPORT0_OUT.4
	#define _GLCD_XG_RESET_DIR_ VPORT0_DIR.4

    // READY
    #define _GLCD_READY_IN_ _GLCD_XG_READY_IN_
    #define _GLCD_READY_DIR_IN_ {_GLCD_XG_READY_DIR_ = 0;}

    // RESET
    #define _GLCD_RESET_LOW_ {_GLCD_XG_RESET_OUT_ = 0;}
    #define _GLCD_RESET_HIGH_ {_GLCD_XG_RESET_OUT_ = 1;}
    #define _GLCD_RESET_DIR_OUT_ {_GLCD_XG_RESET_DIR_ = 1;}
#endif

// Color definitions for 64k color mode
// Bits 0..4 -> Blue 0..4
// Bits 5..10 -> Green 0..5
// Bits 11..15 -> Red 0..4
#define GLCD_CL_BLACK 0x0000 
#define GLCD_CL_WHITE 0xFFFF 
#define GLCD_CL_GRAY 0x7BEF
#define GLCD_CL_LIGHT_GRAY 0xC618      
#define GLCD_CL_GREEN 0x07E0      
#define GLCD_CL_LIME 0x87E0 
#define GLCD_CL_BLUE 0x001F 
#define GLCD_CL_RED 0xF800 
#define GLCD_CL_AQUA 0x5D1C 
#define GLCD_CL_YELLOW 0xFFE0 
#define GLCD_CL_MAGENTA 0xF81F
#define GLCD_CL_CYAN 0x07FF
#define GLCD_CL_DARK_CYAN 0x03EF      
#define GLCD_CL_ORANGE 0xFCA0 
#define GLCD_CL_PINK 0xF97F
#define GLCD_CL_BROWN 0x8200
#define GLCD_CL_VIOLET 0x9199
#define GLCD_CL_SILVER 0xA510
#define GLCD_CL_GOLD 0xA508
#define GLCD_CL_NAVY 0x000F      
#define GLCD_CL_MAROON 0x7800      
#define GLCD_CL_PURPLE 0x780F      
#define GLCD_CL_OLIVE 0x7BE0
      
#define GLCD_ROTATE_0 0
#define GLCD_ROTATE_90 1
#define GLCD_ROTATE_180 2
#define GLCD_ROTATE_270 3

// Structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char reverse_x:1; // reverse display horizontally
        unsigned char reverse_y:1; // reverse display vertically
        unsigned char rotate;
        GLCDX_t maxx;
        GLCDY_t maxy;
        void (*preadxmem) (unsigned char *ptr, GLCDMEMADDR_t addr);
        } GLCDINIT_t;

typedef struct
{
	unsigned char rotate;
	void (*preadxmem) (unsigned char *ptr, GLCDMEMADDR_t addr);
} GLCDSTATE2_t;

extern GLCDSTATE2_t glcd_state2;

// Initialization values for reverse_x
#define XG_REVX_NORM 0  // No horizontal reverse
#define XG_REVX_REV 1   // Horizontal reverse

// Initialization values for reverse_y
#define XG_REVY_NORM 0  // No vertical reverse
#define XG_REVY_REV 1   // Vertical reverse
        
// Initializes the graphic controller and clears the LCD.
void glcd_init_module(void);
bool glcd_init(GLCDINIT_t *init_data);
// Turns LCD on/off.
void glcd_display(bool on);
// Clears the LCD by setting it's color to the background color.
void glcd_clear(void);
void glcd_clearwindow(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height);
// Sets the color of the pixel at coordinates x, y.
void glcd_putpixel(GLCDX_t x, GLCDY_t y, GLCDCOL_t color);
// Fills a block with color
void glcd_putblock(GLCDX_t x, GLCDY_t y, GLCDX_t w, GLCDY_t h, GLCDCOL_t color);
// Prepares a block for data
void glcd_prepblock(GLCDX_t x, GLCDY_t y, GLCDX_t w, GLCDY_t h);
// Sets the color of the pixel in a block.
void glcd_putdata(GLCDCOL_t color);
// Skips a byte in a block
void glcd_skipdata(void);
// Returns the color of the pixel at coordinates x, y.
GLCDCOL_t glcd_getpixel(GLCDX_t x, GLCDY_t y);

// Writes/reads a block of bytes as a bitmap image
// at/from specified coordinates.
void glcd_block(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDMEM_t memt, GLCDMEMADDR_t addr, GLCDBLOCKMODE_t mode);

#pragma library glcd_xg7100.lib

#endif




