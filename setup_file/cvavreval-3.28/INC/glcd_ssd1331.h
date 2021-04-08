//*********************************************************************************
// Library functions for graphic OLED displays with the
// Solomon Systech SSD1331 controller
// (C) 2010-2015 Pavel Haiduc, HP InfoTech s.r.l.,
// All rights reserved
//
// Compiler: CodeVisionAVR V3.22+
// Version: 1.00
//*********************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00
// 02062015_1 - Initial release.
//*****************************************************************************

#ifndef _GLCD_SSD1331_INCLUDED_
#define _GLCD_SSD1331_INCLUDED_

#include <glcd_types.h>

// Use hardware line drawing functions
#define _GLCD_HW_LINE_
// Use hardware rectangle drawing functions
#define _GLCD_HW_RECT_
#define _GLCD_HW_RECT_FILLED_

// SSD1331 commands
#define SSD1331_CMD_SET_COLUMN_ADDR 0x15	// Set column start and end addresses
#define SSD1331_CMD_DRAW_LINE 0x21          // Draw line
#define SSD1331_CMD_DRAW_RECTANGLE 0x22     // Draw rectangle
#define SSD1331_CMD_COPY 0x23               // Copy block
#define SSD1331_CMD_DIM_WINDOW 0x24         // Window will become darker
#define SSD1331_CMD_CLEAR_WINDOW 0x25       // Clear window
#define SSD1331_CMD_FILL_CTRL 0x26          // Enable/disable fill when drawing rectangle
#define SSD1331_CMD_SET_SCROLL 0x27         // Continuous horizontal & vertical scrolling setup
#define SSD1331_CMD_STOP_SCROLL 0x2E        // Stop scrolling
#define SSD1331_CMD_START_SCROLL 0x2F       // Start scrolling
#define SSD1331_CMD_SET_ROW_ADDR 0x75		// Set row start and end addresses
#define SSD1331_CMD_SET_CONTRAST_A 0x81     // Set the contrast current for color A
#define SSD1331_CMD_SET_CONTRAST_B 0x82     // Set the contrast current for color B
#define SSD1331_CMD_SET_CONTRAST_C 0x83     // Set the contrast current for color C
#define SSD1331_CMD_SET_MASTER_CURRENT 0x87 // Set master current
#define SSD1331_CMD_SET_PRECHARGE2_A 0x8A   // Set second pre-charge speed for color A
#define SSD1331_CMD_SET_PRECHARGE2_B 0x8B   // Set second pre-charge speed for color B
#define SSD1331_CMD_SET_PRECHARGE2_C 0x8C   // Set second pre-charge speed for color C
#define SSD1331_CMD_REMAP_MODE 0xA0			// Set Re-map/Color Depth
#define SSD1331_CMD_SET_START_LINE 0xA1		// Set display start line
#define SSD1331_CMD_SET_DISPLAY_OFFSET 0xA2	// Set display offset
#define SSD1331_CMD_DISPLAY_NORMAL 0xA4		// Normal display
#define SSD1331_CMD_DISPLAY_ALL_ON 0xA5		// Set all display pixels on
#define SSD1331_CMD_DISPLAY_ALL_OFF 0xA6	// Set all display pixels off
#define SSD1331_CMD_DISPLAY_INVERSE 0xA7	// Inverse display
#define SSD1331_CMD_SET_MUX_RATIO 0xA8      // Set multiplex ratio
#define SSD1331_CMD_SET_MASTER_CONFIG 0xAD	// Set master configuration
#define SSD1331_CMD_DISPLAY_OFF 0xAE		// Display off
#define SSD1331_CMD_DISPLAY_ON 0xAF			// Display on
#define SSD1331_CMD_POWERSAVE_MODE 0xB0     // Power save mode
#define SSD1331_CMD_SET_PHASE_LENGTH 0xB1   // Set phase 1 and 2 periods
#define SSD1331_CMD_SET_FRONT_CLK 0xB3      // Set front clock divider/oscillator frequency
#define SSD1331_CMD_SET_GRAYSCALE_TBL 0xB8  // Set gray scale pulse width table
#define SSD1331_CMD_SET_GRAYSCALE_LIN 0xB9  // Set default linear gray scale pulse width table
#define SSD1331_CMD_SET_PRECHARGE_VOLT 0xBB // Set the pre-charge voltage level
#define SSD1331_CMD_SET_VCOMH 0xBE          // Set the COM deselect voltage level
#define SSD1331_CMD_SET_COMMAND_LOCK 0xFD   // Set MCU protection status

// Structure that contains controller specific graphic controller initialization data
typedef struct
        {
        flash unsigned char *font; // Default font after initialization
        // Pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr);
        // Pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char divset:4; // Front clock divider
        unsigned char osc_freq:4; // Oscillator frequency
        unsigned char phase1:4; // Phase 1 period: 1..15 [DCLK cycles]
        unsigned char phase2:4; // Phase 2 period: 1..15 [DCLK cycles]
        unsigned char precharge_v:5; // Pre-charge voltage= Vcc*(0.1+precharge_v*0.0125)
        unsigned char vcomh:5; // VCOMH voltage= Vcc*(0.44+vcomh*0.0122)
		unsigned char reverse_x:1; // reverse display horizontally
        unsigned char reverse_y:1; // reverse display vertically
        unsigned char color_bgr:1; // =0 - color order: R, G, B
                                   // =1 - color order: B, G, R
        unsigned char com_split:1; // enable odd/even split of COM pins (interlaced display)
        unsigned char precharge_t2_red;   // Second pre-charge period [DCLK cycles] for red color
        unsigned char precharge_t2_green; // Second pre-charge period [DCLK cycles] for green color
        unsigned char precharge_t2_blue;  // Second pre-charge period [DCLK cycles] for blue color
        unsigned char contrast_red;   // Contrast current= ISEG*contrast for red color
        unsigned char contrast_green; // Contrast current= ISEG*contrast for green color
        unsigned char contrast_blue;  // Contrast current= ISEG*contrast for blue color
        unsigned char master_current:4; // Reduce the output current for all colors
                                         // to (master_current+1)/16
		flash unsigned char *gray_scale_table; // pointer to gray scale table for gamma correction
                                               // (array located in FLASH with 32 byte values)
                                               // a NULL pointer specifies to use the default table
        } GLCDINIT_t;

// Initialization values for divset
#define SSD1331_DIV1 0 // Divide osc. by 1
#define SSD1331_DIV2 1 // Divide osc. by 2
#define SSD1331_DIV4 2 // Divide osc. by 4
#define SSD1331_DIV8 3 // Divide osc. by 8
#define SSD1331_DIV16 4 // Divide osc. by 16
#define SSD1331_DIV32 5 // Divide osc. by 32
#define SSD1331_DIV64 6 // Divide osc. by 64
#define SSD1331_DIV128 7 // Divide osc. by 128
#define SSD1331_DIV256 8 // Divide osc. by 256
#define SSD1331_DIV512 9 // Divide osc. by 512
#define SSD1331_DIV1024 10 // Divide osc. by 1024

// Initialization values for reverse_x
#define SSD1331_REVX_NORM 0 // Scan from COM0 to COMn-1
#define SSD1331_REVX_REV 1 // Scan from COMn-1 to COM0

// Initialization values for reverse_y
#define SSD1331_REVY_NORM 0 // Scan from COM0 to COMn-1
#define SSD1331_REVY_REV 1 // Scan from COMn-1 to COM0

// Initialization values for color_bgr
#define SSD1331_COLOR_RGB 0 // Use R, G, B color order
#define SSD1331_COLOR_BGR 1 // Use B, G, R color order

// Initialization values for com_split
#define SSD1331_COM_SPLIT_OFF 0
#define SSD1331_COM_SPLIT_ON 1

// Initialization value for gray_scale_table
#define SSD1331_GRAY_SCALE_LINEAR NULL // Use a linear gray scale

// Default value for divset
#define SSD1331_DEFAULT_DIVSET SSD1331_DIV2
// Default value for osc_freq
#define SSD1331_DEFAULT_OSC_FREQ 0x0F
// Default value for phase1
#define SSD1331_DEFAULT_PHASE1 1
// Default value for phase2
#define SSD1331_DEFAULT_PHASE2 3
// Default value for precharge_v
#define SSD1331_DEFAULT_PRECHARGE_V 0x1D
// Default value for reverse_x
#define SSD1331_DEFAULT_REVX SSD1331_REVX_NORM
// Default value for reverse_y
#define SSD1331_DEFAULT_REVY SSD1331_REVY_NORM
// Default value for color_bgr
#define SSD1331_DEFAULT_COLOR_BGR SSD1331_COLOR_RGB 
// Default value for com_split
#define SSD1331_DEFAULT_COM_SPLIT SSD1331_COM_SPLIT_OFF
// Default values for precharge_t2_red, precharge_t2_green, precharge_t2_blue 
#define SSD1331_DEFAULT_PRECHARGE_T2_RED 0x64
#define SSD1331_DEFAULT_PRECHARGE_T2_GREEN 0x78
#define SSD1331_DEFAULT_PRECHARGE_T2_BLUE 0x64
// Default value for vcomh
#define SSD1331_DEFAULT_VCOMH 0x3F
// Default values for contrast_red, contrast_green, contrast_blue 
#define SSD1331_DEFAULT_CONTRAST_RED 0x91
#define SSD1331_DEFAULT_CONTRAST_GREEN 0x50
#define SSD1331_DEFAULT_CONTRAST_BLUE 0x7D
// Default value for master_current
#define SSD1331_DEFAULT_MASTER_CURRENT 6
// Default value for gray_scale_table
#define SSD1331_DEFAULT_GRAY_SCALE SSD1331_GRAY_SCALE_LINEAR

#if _GLCD_COLOR_BITS_==8
// Color definitions for 256 color mode
// Bits 0..1 -> Blue 0..1
// Bits 2..4 -> Green 0..2
// Bits 5..7 -> Red 0..2
#define SSD1331_SETCL(c) ((((c)>>8) & 0xE0) | (((c)>>6) & 0x1C) | (((c)>>3) & 0x03))
#elif _GLCD_COLOR_BITS_==16
// Color definitions for 64k color mode
// Bits 0..4 -> Blue 0..4
// Bits 5..10 -> Green 0..5
// Bits 11..15 -> Red 0..4
#define SSD1331_SETCL(c) (c)
#endif

// Usual color definitions
#define GLCD_CL_BLACK SSD1331_SETCL(0x0000)
#define GLCD_CL_WHITE SSD1331_SETCL(0xFFFF)
#define GLCD_CL_GRAY SSD1331_SETCL(0x7BEF)
#define GLCD_CL_LIGHT_GRAY SSD1331_SETCL(0xC618)
#define GLCD_CL_GREEN SSD1331_SETCL(0x07E0)
#define GLCD_CL_LIME SSD1331_SETCL(0x87E0)
#define GLCD_CL_BLUE SSD1331_SETCL(0x001F)
#define GLCD_CL_RED SSD1331_SETCL(0xF800)
#define GLCD_CL_AQUA SSD1331_SETCL(0x5D1C)
#define GLCD_CL_YELLOW SSD1331_SETCL(0xFFE0)
#define GLCD_CL_MAGENTA SSD1331_SETCL(0xF81F)
#define GLCD_CL_CYAN SSD1331_SETCL(0x07FF)
#define GLCD_CL_DARK_CYAN SSD1331_SETCL(0x03EF)
#define GLCD_CL_ORANGE SSD1331_SETCL(0xFCA0)
#define GLCD_CL_PINK SSD1331_SETCL(0xF97F)
#define GLCD_CL_BROWN SSD1331_SETCL(0x8200)
#define GLCD_CL_VIOLET SSD1331_SETCL(0x9199)
#define GLCD_CL_SILVER SSD1331_SETCL(0xA510)
#define GLCD_CL_GOLD SSD1331_SETCL(0xA508)
#define GLCD_CL_NAVY SSD1331_SETCL(0x000F)
#define GLCD_CL_MAROON SSD1331_SETCL(0x7800)
#define GLCD_CL_PURPLE SSD1331_SETCL(0x780F)
#define GLCD_CL_OLIVE SSD1331_SETCL(0x7BE0)

// Writes a command to the SSD1331 controller.
// Sets D /C=0
void ssd1331_wrcmd(unsigned char cmd);
// Reads the status data byte from the SSD1331 controller
// Sets D /C=0
unsigned char ssd1331_rdstatus(void);
// Writes a data byte to the SSD1331 controller.
// Sets D /C=1
void ssd1331_wrdata(unsigned char data);
// Reads a data byte from the SSD1331 controller.
// Sets D /C=1
unsigned char ssd1331_rddata(void);
// Waits until the controller has finished executing
// a hardware accelerated drawing command
void ssd1331_busy(void);
// Sets the OLED display contrast value
void ssd1331_setcontrast(unsigned char contrast);

// Initializes the graphic controller and clears the display.
bool glcd_init(GLCDINIT_t *init_data);
// Turns the display on/off.
void glcd_display(bool on);
// Clears the display by setting it's color to the background color.
void glcd_clear(void);
// Sets the color of the pixel at coordinates x, y.
void glcd_putpixel(GLCDX_t x, GLCDY_t y, GLCDCOL_t color);
// Returns the color of the pixel at coordinates x, y.
GLCDCOL_t glcd_getpixel(GLCDX_t x, GLCDY_t y);

// Writes/reads a block of bytes as a bitmap image
// at/from specified coordinates.
void glcd_block(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDMEM_t memt, GLCDMEMADDR_t addr, GLCDBLOCKMODE_t mode);
// Draws a line with the current color, thickness and bit pattern.
void glcd_line(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1, GLCDY_t y1);
// Draws a rectangle using the current line thickness, bit pattern and drawing color.
void glcd_rectangle(GLCDX_t left, GLCDY_t top, GLCDX_t right, GLCDY_t bottom);
// Draws a filled-in rectangular bar, using absolute coordinates.
void glcd_bar(GLCDX_t left, GLCDY_t top, GLCDX_t right, GLCDY_t bottom);
// Draws a filled-in rectangular bar, using relative coordinates.
void glcd_barrel(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height);

#pragma library glcd_ssd1331.lib

#endif
