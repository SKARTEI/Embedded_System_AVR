#ifndef _GLCD_XG43A_INCLUDED_
#define _GLCD_XG43A_INCLUDED_

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
    glcd_xg43a.lib
    Library functions for X-Graph XG7100 4.3 Type A
    
    © Copyright DELCOMp 2003-2014, All Rights Reserved
    DELCOMp bvba, Technologielaan 3, B-3001 Leuven, Belgium
    http://www.xgraph.be ©

    CHANGE HISTORY:
    Date: 1.0, 30 Jul 2014

*************************************************************	
CodeVision 3.15 integrated defines for XG43A:

XG43A 480x272 TFT 64k Colors
#define _GLCD_MAXX_ 480
#define _GLCD_MAXY_  272
#define _GLCD_MAXX_HW_ 480
#define _GLCD_MAXY_HW_ 272
#define _GLCD_COLOR_BITS_ 16
#define _GLCD_INTERNAL_FONT_WIDTH_ 0
#define _GLCD_INTERNAL_FONT_HEIGHT_ 0
#define _GLCD_CTRL_XG43A_

END DESCRIPTION *************************************************************/

#include <glcd_types.h>

#ifdef _GLCD_MAXX_
	#undef _GLCD_MAXX_
#endif
extern GLCDX_t _GLCD_MAXX_;

#ifdef _GLCD_MAXY_
	#undef _GLCD_MAXY_
#endif
extern GLCDY_t _GLCD_MAXY_;

#ifndef _GLCD_XG43A_NCS_OUT_
	#define _GLCD_XG43A_NCS_OUT_ PORTH.OUT
	#define _GLCD_XG43A_NCS_DIR_ PORTH.DIR
	#define _GLCD_XG43A_NCS_BIT_ 4
	#ifndef _GLCD_NO_VPORT_
		#define _GLCD_XG43A_NCS_VPORT_ VPORT0_OUT.4
	#endif
#endif

#ifndef _GLCD_XG43A_NWR_OUT_
	#define _GLCD_XG43A_NWR_OUT_ PORTH.OUT
	#define _GLCD_XG43A_NWR_DIR_ PORTH.DIR
	#define _GLCD_XG43A_NWR_BIT_ 0
	#ifndef _GLCD_NO_VPORT_
		#define _GLCD_XG43A_NWR_VPORT_ VPORT0_OUT.0
	#endif
#endif

#ifndef _GLCD_XG43A_NRD_OUT_
	#define _GLCD_XG43A_NRD_OUT_ PORTH.OUT
	#define _GLCD_XG43A_NRD_DIR_ PORTH.DIR
	#define _GLCD_XG43A_NRD_BIT_ 1
	#ifndef _GLCD_NO_VPORT_
		#define _GLCD_XG43A_NRD_VPORT_ VPORT0_OUT.1
	#endif
#endif

#ifndef _GLCD_XG43A_CMD_OUT_
	#define _GLCD_XG43A_CMD_OUT_ PORTH.OUT
	#define _GLCD_XG43A_CMD_DIR_ PORTH.DIR
	#define _GLCD_XG43A_CMD_BIT_ 5
	#ifndef _GLCD_NO_VPORT_
		#define _GLCD_XG43A_CMD_VPORT_ VPORT0_OUT.5
	#endif
#endif

#ifndef _GLCD_XG43A_PON_OUT_
	#define _GLCD_XG43A_PON_OUT_ PORTK.OUT
	#define _GLCD_XG43A_PON_DIR_ PORTK.DIR
	#define _GLCD_XG43A_PON_BIT_ 6
	#ifndef _GLCD_NO_VPORT_
		#define _GLCD_XG43A_PON_VPORT_ VPORT3_OUT.6
	#endif
#endif

#ifndef _GLCD_XG43A_DB_DIR_
	#define _GLCD_XG43A_DB_DIR_ PORTJ.DIR
	#ifndef _GLCD_NO_VPORT_
		#define _GLCD_XG43A_DB_OUT_ VPORT1_OUT
	#else
		#define _GLCD_XG43A_DB_OUT_ PORTJ.OUT
	#endif
	#define _GLCD_XG43A_DB_IN_ PORTJ.IN
#endif

#ifdef _GLCD_XG43A_DB_DIR_
    #define _GLCD_DATA_BUS_
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

// XG43A command register definitions
#define XG43A_CMD_PLL 0x40           // 20-100MHz PLL range, 8mA output driver capability, fast slew rate
#define XG43A_CMD_PLL_PRE 0x41       // PLL Programmable pre-divider
#define XG43A_CMD_PLL_LOOP 0x42      // PLL Programmable loop divider

#define XG43A_CMD_MSB_HOR_RES 0x08   // MSB of input image horizontal resolution (480 dots is the actual LCD size)
#define XG43A_CMD_LSB_HOR_RES 0x09   // LSB of input image horizontal resolution
#define XG43A_CMD_MSB_MEM_WR 0x0a    // MSB of Memory write address
#define XG43A_CMD_MLSB_MEM_WR 0x0b   // MLSB of Memory write address
#define XG43A_CMD_LSB_MEM_WR 0x0c    // LSB of Memory write address

#define XG43A_CMD_MODE1 0x10         // Output data bits not swapped, test mode disabled, no data blanking, parallel mode, clock = system clock / 4
#define XG43A_CMD_MODE2 0x11         // Even line: RGB, Odd line: RGB
#define XG43A_CMD_MSB_HS_START 0x12  // MSB of HSync pulse start
#define XG43A_CMD_LSB_HS_START 0x13  // LSB of HSync pulse start
#define XG43A_CMD_MSB_HS_WIDTH 0x14  // MSB of HSync pulse width
#define XG43A_CMD_LSB_HS_WIDTH 0x15  // LSB of HSync pulse width
#define XG43A_CMD_MSB_DE_START 0x16  // MSB of DE horizontal start
#define XG43A_CMD_LSB_DE_START 0x17  // LSB of DE horizontal start
#define XG43A_CMD_MSB_DE_WIDTH 0x18  // MSB of DE horizontal active region
#define XG43A_CMD_LSB_DE_WIDTH 0x19  // LSB of DE horizontal active region
#define XG43A_CMD_MSB_H_TOTAL 0x1a   // MSB of output H total
#define XG43A_CMD_LSB_H_TOTAL 0x1b   // LSB of output H total
#define XG43A_CMD_MSB_VS_START 0x1c  // MSB of VSync pulse start
#define XG43A_CMD_LSB_VS_START 0x1d  // LSB of VSync pulse start
#define XG43A_CMD_MSB_VS_WIDTH 0x1e  // MSB of VSync pulse width
#define XG43A_CMD_LSB_VS_WIDTH 0x1f  // LSB of VSync pulse width
#define XG43A_CMD_MSB_DE_VSTART 0x20 // MSB of DE vertical start
#define XG43A_CMD_LSB_DE_VSTART 0x21 // LSB of DE vertical start
#define XG43A_CMD_MSB_DE_VWIDTH 0x22 // MSB of DE vertical active region
#define XG43A_CMD_LSB_DE_VWIDTH 0x23 // LSB of DE vertical active region
#define XG43A_CMD_MSB_V_TOTAL 0x24   // MSB of output V total
#define XG43A_CMD_LSB_V_TOTAL 0x25   // LSB of output V total

#define XG43A_CMD_MSB_MEM_RD 0x26    // MSB of Memory read address
#define XG43A_CMD_MLSB_MEM_RD 0x27   // MLSB of Memory read address
#define XG43A_CMD_LSB_MEM_RD 0x28    // LSB of Memory read address

#define XG43A_CMD_START 0x29         // Start signals (HSync, VSync, DE)

#define XG43A_CMD_MSB_HS_SHIFT 0x30  // MSB of horizontal shift
#define XG43A_CMD_LSB_HS_SHIFT 0x31  // LSB of horizontal shift
#define XG43A_CMD_MSB_VS_SHIFT 0x32  // MSB of vertical shift
#define XG43A_CMD_LSB_VS_SHIFT 0x33  // LSB of vertical shift
#define XG43A_CMD_MSB_IMAGE_HOR 0x34 // MSB of image horizontal physical resolution in memory (512 dots, max. could be 564)
#define XG43A_CMD_LSB_IMAGE_HOR 0x35 // LSB of image horizontal physical resolution in memory
#define XG43A_CMD_MSB_IMAGE_VER 0x36 // MSB of image vertical physical resolution in memory (272 lines, max. could be 300 with 512 dots)
#define XG43A_CMD_LSB_IMAGE_VER 0x37 // LSB of image vertical physical resolution in memory

#define XG43A_CMD_MSB_HOR_START 0x00 // MSB of horizontal start coordinate value
#define XG43A_CMD_LSB_HOR_START 0x01 // LSB of horizontal start coordinate value
#define XG43A_CMD_MSB_HOR_END 0x02   // MSB of horizontal end coordinate value (512 dots, to ease ram address calculations)
#define XG43A_CMD_LSB_HOR_END 0x03   // LSB of horizontal end coordinate value
#define XG43A_CMD_MSB_VER_START 0x04 // MSB of vertical start coordinate value
#define XG43A_CMD_LSB_VER_START 0x05 // LSB of vertical start coordinate value
#define XG43A_CMD_MSB_VER_END 0x06   // MSB of vertical end coordinate value
#define XG43A_CMD_LSB_VER_END 0x07   // LSB of vertical end coordinate value

#define XG43A_CMD_POWER 0x2d         // X_DCON level control, no clock inversion, no image rotation

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
        //GLCDX_t maxx; 
        //GLCDY_t maxy;
		void (*preadxmem) (unsigned char *ptr, GLCDMEMADDR_t addr);
    } GLCDSTATE2_t;    

extern GLCDSTATE2_t glcd_state2;

// Initialization values for reverse_x
#define XG_REVX_NORM 0  // No horizontal reverse
#define XG_REVX_REV 1   // Horizontal reverse

// Initialization values for reverse_y
#define XG_REVY_NORM 0  // No vertical reverse
#define XG_REVY_REV 1   // Vertical reverse

// Writes data to the XG43A controller.
void xg43a_wrdata(unsigned short data);
// Reads a data word from the XG43A controller.
unsigned short xg43a_rddata(void);
// Writes a byte to a register of the XG43A controller.
void xg43a_wrreg(unsigned char index, unsigned char data);
// Reads a byte from a register of the XG43A controller.
unsigned char xg43a_rdreg(unsigned char index);

void xg43a_setdata(void);
void xg43a_clrdata(void);
        
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
// Returns the color of the pixel at coordinates x, y.
GLCDCOL_t glcd_getpixel(GLCDX_t x, GLCDY_t y);

// Writes/reads a block of bytes as a bitmap image
// at/from specified coordinates.
void glcd_block(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDMEM_t memt, GLCDMEMADDR_t addr, GLCDBLOCKMODE_t mode);

#pragma library glcd_xg43a.lib

#endif




