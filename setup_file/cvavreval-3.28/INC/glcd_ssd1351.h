//*********************************************************************************
// Library functions for graphic OLED displays with the
// Solomon Systech SSD1351 controller
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
// 25052015_1 - Initial release.
//*****************************************************************************

#ifndef _GLCD_SSD1351_INCLUDED_
#define _GLCD_SSD1351_INCLUDED_

#include <glcd_types.h>

// Use fast horizontal line drawing function.
#define _GLCD_FAST_LINEH_

// SSD1351 commands
#define SSD1351_CMD_SET_COLUMN_ADDR 0x15	// Set column start and end addresses
#define SSD1351_CMD_SET_ROW_ADDR 0x75		// Set row start and end addresses
#define SSD1351_CMD_WRITE_RAM 0x5C			// Enable MCU to write data into GDRAM
#define SSD1351_CMD_READ_RAM 0x5D			// Enable MCU to read data from GDRAM
#define SSD1351_CMD_HORIZ_SCROLL 0x96       // Horizontal scroll
#define SSD1351_CMD_HORIZ_SCROLL_STOP 0x9E  // Stop horizontal scroll
#define SSD1351_CMD_HORIZ_SCROLL_START 0x9F // Start horizontal scroll
#define SSD1351_CMD_REMAP_MODE 0xA0			// Set Re-map/Color Depth
#define SSD1351_CMD_SET_START_LINE 0xA1		// Set display start line
#define SSD1351_CMD_SET_DISPLAY_OFFSET 0xA2	// Set display offset
#define SSD1351_CMD_DISPLAY_ALL_OFF 0xA4		// Entire display off
#define SSD1351_CMD_DISPLAY_ALL_ON 0xA5			// Entire display on
#define SSD1351_CMD_DISPLAY_NORMAL 0xA6		// Normal display
#define SSD1351_CMD_DISPLAY_INVERSE 0xA7	// Inverse display
#define SSD1351_CMD_FUNC_SEL 0xAB			// Function selection
#define SSD1351_CMD_SLEEP_ON 0xAE			// Enter sleep mode
#define SSD1351_CMD_SLEEP_OFF 0xAF			// Exit sleep mode
#define SSD1351_CMD_SET_PHASE_LENGTH 0xB1   // Set phase 1 and 2 periods
#define SSD1351_CMD_SET_FRONT_CLK 0xB3      // Set front clock divider/oscillator frequency
#define SSD1351_CMD_SET_VSL 0xB4            // Set Segment Low Voltage (VSL)
#define SSD1351_CMD_SET_GPIO 0xB5           // Set GPIO pins state
#define SSD1351_CMD_SET_PRECHARGE2 0xB6     // Set second pre-charge period
#define SSD1351_CMD_SET_GRAYSCALE_TBL 0xB8  // Set gray scale pulse width table
#define SSD1351_CMD_SET_GRAYSCALE_LIN 0xB9  // Set default linear gray scale pulse width table
#define SSD1351_CMD_SET_PRECHARGE_VOLT 0xBB // Set the pre-charge voltage level
#define SSD1351_CMD_SET_VCOMH 0xBE          // Set the COM deselect voltage level
#define SSD1351_CMD_SET_CONTRAST 0xC1       // Set the contrast current for colors
#define SSD1351_CMD_SET_MASTER_CONTRAST 0xC7 // Set master contrast current
#define SSD1351_CMD_SET_MUX_RATIO 0xCA      // Set MUX ratio: 15..127
#define SSD1351_CMD_SET_COMMAND_LOCK 0xFD   // Set MCU protection status

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
        unsigned char phase1:4; // Phase 1 period
        unsigned char phase2:4; // Phase 2 period
        unsigned char precharge_v:5; // Pre-charge voltage= Vcc*(0.2+precharge_v*0.01275)
        unsigned char vcomh:3; // VCOMH voltage= Vcc*(0.72+vcomh*0.02)
		    unsigned char reverse_x:1; // reverse display horizontally
        unsigned char reverse_y:1;  // reverse display vertically
        unsigned char color_bgr:1;  // =0 - color order: R, G, B
                                    // =1 - color order: B, G, R
        unsigned char com_split:1; // enable odd/even split of COM pins (interlaced display)
        unsigned char precharge_t2:4; // Second pre-charge period [DCLK cycles]
        unsigned char contrast_red; // Contrast current= ISEG*contrast for red color
        unsigned char contrast_green; // Contrast current= ISEG*contrast for green color
        unsigned char contrast_blue; // Contrast current= ISEG*contrast for blue color
        unsigned char master_contrast:4; // Reduce the output current for all colors
                                         // to (master_contrast+1)/16
        unsigned char gpio0:2; // GPIO0
        unsigned char gpio1:2; // GPIO1
		    flash unsigned char *gray_scale_table; // pointer to gray scale table for gamma correction
                                               // (array located in FLASH with 32 byte values)
                                               // a NULL pointer specifies to use the default table
        } GLCDINIT_t;

// Initialization values for divset
#define SSD1351_DIV1 0 // Divide osc. by 1
#define SSD1351_DIV2 1 // Divide osc. by 2
#define SSD1351_DIV4 2 // Divide osc. by 4
#define SSD1351_DIV8 3 // Divide osc. by 8
#define SSD1351_DIV16 4 // Divide osc. by 16
#define SSD1351_DIV32 5 // Divide osc. by 32
#define SSD1351_DIV64 6 // Divide osc. by 64
#define SSD1351_DIV128 7 // Divide osc. by 128
#define SSD1351_DIV256 8 // Divide osc. by 256
#define SSD1351_DIV512 9 // Divide osc. by 512
#define SSD1351_DIV1024 10 // Divide osc. by 1024

// Initialization values for phase1
#define SSD1351_PHASE1_5DCLK 2 // Phase 1 period=5 DCLK cycles
#define SSD1351_PHASE1_7DCLK 3 // Phase 1 period=7 DCLK cycles
#define SSD1351_PHASE1_9DCLK 4 // Phase 1 period=9 DCLK cycles
#define SSD1351_PHASE1_11DCLK 5 // Phase 1 period=11 DCLK cycles
#define SSD1351_PHASE1_13DCLK 6 // Phase 1 period=13 DCLK cycles
#define SSD1351_PHASE1_15DCLK 7 // Phase 1 period=15 DCLK cycles
#define SSD1351_PHASE1_17DCLK 8 // Phase 1 period=17 DCLK cycles
#define SSD1351_PHASE1_19DCLK 9 // Phase 1 period=19 DCLK cycles
#define SSD1351_PHASE1_21DCLK 10 // Phase 1 period=21 DCLK cycles
#define SSD1351_PHASE1_23DCLK 11 // Phase 1 period=23 DCLK cycles
#define SSD1351_PHASE1_25DCLK 12 // Phase 1 period=25 DCLK cycles
#define SSD1351_PHASE1_27DCLK 13 // Phase 1 period=27 DCLK cycles
#define SSD1351_PHASE1_29DCLK 14 // Phase 1 period=29 DCLK cycles
#define SSD1351_PHASE1_31DCLK 15 // Phase 1 period=31 DCLK cycles

// Initialization values for phase2
#define SSD1351_PHASE2_3DCLK 3 // Phase 2 period=3 DCLK cycles
#define SSD1351_PHASE2_4DCLK 4 // Phase 2 period=4 DCLK cycles
#define SSD1351_PHASE2_5DCLK 5 // Phase 2 period=5 DCLK cycles
#define SSD1351_PHASE2_6DCLK 6 // Phase 2 period=6 DCLK cycles
#define SSD1351_PHASE2_7DCLK 7 // Phase 2 period=7 DCLK cycles
#define SSD1351_PHASE2_8DCLK 8 // Phase 2 period=8 DCLK cycles
#define SSD1351_PHASE2_9DCLK 9 // Phase 2 period=9 DCLK cycles
#define SSD1351_PHASE2_10DCLK 10 // Phase 2 period=10 DCLK cycles
#define SSD1351_PHASE2_11DCLK 11 // Phase 2 period=11 DCLK cycles
#define SSD1351_PHASE2_12DCLK 12 // Phase 2 period=12 DCLK cycles
#define SSD1351_PHASE2_13DCLK 13 // Phase 2 period=13 DCLK cycles
#define SSD1351_PHASE2_14DCLK 14 // Phase 2 period=14 DCLK cycles
#define SSD1351_PHASE2_15DCLK 15 // Phase 2 period=15 DCLK cycles

// Initialization values for reverse_x
#define SSD1351_REVX_NORM 0 // Scan from COM0 to COMn-1
#define SSD1351_REVX_REV 1 // Scan from COMn-1 to COM0

// Initialization values for reverse_y
#define SSD1351_REVY_NORM 0 // Scan from COM0 to COMn-1
#define SSD1351_REVY_REV 1 // Scan from COMn-1 to COM0

// Initialization values for color_bgr
#define SSD1351_COLOR_RGB 0 // Use R, G, B color order
#define SSD1351_COLOR_BGR 1 // Use B, G, R color order

// Initialization values for com_split
#define SSD1351_COM_SPLIT_OFF 0
#define SSD1351_COM_SPLIT_ON 1

// Initialization values for gpio0 and gpio1
#define SSD1351_GPIO_HIZ 0 // I/O pin HiZ, no input
#define SSD1351_GPIO_INPUT 1 // Set I/O pin as input
#define SSD1351_GPIO_OUTPUT_LOW 2 // Set I/O pin as output with logic level 0
#define SSD1351_GPIO_OUTPUT_HIGH 3 // Set I/O pin as output with logic level 1

// Initialization value for gray_scale_table
#define SSD1351_GRAY_SCALE_LINEAR NULL // Use a linear gray scale

// Default value for divset
#define SSD1351_DEFAULT_DIVSET SSD1351_DIV2
// Default value for osc_freq
#define SSD1351_DEFAULT_OSC_FREQ 0x0F
// Default value for phase1
#define SSD1351_DEFAULT_PHASE1 SSD1351_PHASE1_5DCLK
// Default value for phase2
#define SSD1351_DEFAULT_PHASE2 SSD1351_PHASE2_3DCLK
// Default value for precharge_v
#define SSD1351_DEFAULT_PRECHARGE_V 0x17
// Default value for reverse_x
#define SSD1351_DEFAULT_REVX SSD1351_REVX_NORM
// Default value for reverse_y
#define SSD1351_DEFAULT_REVY SSD1351_REVY_NORM
// Default value for color_bgr
#define SSD1351_DEFAULT_COLOR_BGR SSD1351_COLOR_RGB 
// Default value for com_split
#define SSD1351_DEFAULT_COM_SPLIT SSD1351_COM_SPLIT_OFF
// Default value for precharge_t2
#define SSD1351_DEFAULT_PRECHARGE_T2 1
// Default value for vcomh
#define SSD1351_DEFAULT_VCOMH 5
// Default values for contrast_red, contrast_green, contrast_blue 
#define SSD1351_DEFAULT_CONTRAST_RED 0x88
#define SSD1351_DEFAULT_CONTRAST_GREEN 0x70
#define SSD1351_DEFAULT_CONTRAST_BLUE 0x88
// Default value for master_contrast
#define SSD1351_DEFAULT_MASTER_CONTRAST 15
// Default value for gpio0
#define SSD1351_DEFAULT_GPIO0 SSD1351_GPIO_HIZ
// Default value for gpio1
#define SSD1351_DEFAULT_GPIO1 SSD1351_GPIO_HIZ
// Default value for gray_scale_table
#define SSD1351_DEFAULT_GRAY_SCALE SSD1351_GRAY_SCALE_LINEAR

// Usual color definitions
#if _GLCD_COLOR_BITS_==8
// Color definitions for 256 color mode
// Bits 0..2 -> Blue 0..2
// Bits 3..5 -> Green 0..2
// Bits 6..7 -> Red 0..1
#define GLCD_CL_BLACK 0x00
#define GLCD_CL_WHITE 0xFF
#define GLCD_CL_GRAY 0x5B
#define GLCD_CL_LIGHT_GRAY 0xF6
#define GLCD_CL_GREEN 0x38
#define GLCD_CL_LIME 0xB8
#define GLCD_CL_BLUE 0x07
#define GLCD_CL_RED 0xC0
#define GLCD_CL_AQUA 0x6F
#define GLCD_CL_YELLOW 0xF8
#define GLCD_CL_MAGENTA 0xC7
#define GLCD_CL_CYAN 0x3F
#define GLCD_CL_DARK_CYAN 0x1B
#define GLCD_CL_ORANGE 0xE0
#define GLCD_CL_PINK 0xCF
#define GLCD_CL_BROWN 0x90
#define GLCD_CL_VIOLET 0x8E
#define GLCD_CL_SILVER 0xAC
#define GLCD_CL_GOLD 0xAA
#define GLCD_CL_NAVY 0x03
#define GLCD_CL_MAROON 0x40
#define GLCD_CL_PURPLE 0x43
#define GLCD_CL_OLIVE 0x58

#elif _GLCD_COLOR_BITS_==16
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
#endif

// Writes a command to the SSD1351 controller.
// Sets D /C=0
void ssd1351_wrcmd(unsigned char cmd);
// Writes data to the SSD1351 controller.
// Sets D /C=1
void ssd1351_wrdata(unsigned char data);
// Reads data from the SSD1351 controller.
// Sets D /C=1
unsigned char ssd1351_rddata(void);
// Sets the OLED display master contrast value
void ssd1351_setcontrast(unsigned char contrast);

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

// Fast draw a horizontal line from (x0,y0) to (x1,y0).
void glcd_lineh(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1);

#pragma library glcd_ssd1351.lib

#endif
