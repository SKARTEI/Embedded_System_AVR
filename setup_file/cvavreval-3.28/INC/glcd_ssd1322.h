//******************************************************************************
// Library functions for graphic OLED displays with the
// Solomon Systech SSD1322 controller
// (C) 2010-2016 Pavel Haiduc, HP InfoTech s.r.l.,
// All rights reserved
//
// Compiler: CodeVisionAVR V3.25+
// Version: 1.01
//******************************************************************************

//******************************************************************************
// Revision history:
//
// V1.00      Initial release.
// V1.01      19012016_1 Fixed bug in glcd_block and glcd_lineh for 
//            256x64 displays
//******************************************************************************

#ifndef _GLCD_SSD1322_INCLUDED_
#define _GLCD_SSD1322_INCLUDED_

#include <glcd_types.h>

// Use fast horizontal line drawing function.
#define _GLCD_FAST_LINEH_

// SSD1322 commands
#define SSD1322_CMD_SET_COLUMN_ADDR 0x15	// Set column start and end addresses
#define SSD1322_CMD_SET_ROW_ADDR 0x75		// Set row start and end addresses
#define SSD1322_CMD_WRITE_RAM 0x5C			// Enable MCU to write data into GDRAM
#define SSD1322_CMD_READ_RAM 0x5D			// Enable MCU to read data from GDRAM
#define SSD1322_CMD_REMAP_MODE 0xA0			// Set Re-map and dual COM line modes
#define SSD1322_CMD_SET_START_LINE 0xA1		// Set display start line
#define SSD1322_CMD_SET_DISPLAY_OFFSET 0xA2	// Set display offset
#define SSD1322_CMD_DISPLAY_OFF 0xA4		// Entire display off
#define SSD1322_CMD_DISPLAY_ON 0xA5			// Entire display on
#define SSD1322_CMD_DISPLAY_NORMAL 0xA6		// Normal display
#define SSD1322_CMD_DISPLAY_INVERSE 0xA7	// Inverse display
#define SSD1322_CMD_DISPLAY_PARTIAL_ON 0xA8	// Enable partial display mode
#define SSD1322_CMD_DISPLAY_PARTIAL_OFF 0xA9 // Exit partial display mode
#define SSD1322_CMD_FUNC_SEL 0xAB			// Function selection
#define SSD1322_CMD_SLEEP_ON 0xAE			// Enter sleep mode
#define SSD1322_CMD_SLEEP_OFF 0xAF			// Exit sleep mode
#define SSD1322_CMD_SET_PHASE_LENGTH 0xB1   // Set phase 1 and 2 periods
#define SSD1322_CMD_SET_FRONT_CLK 0xB3      // Set front clock divider/oscillator
                                            // frequency
#define SSD1322_CMD_SET_DISPLAY_ENHA 0xB4   // Display enhancement A
#define SSD1322_CMD_SET_GPIO 0xB5           // Set GPIO pins state
#define SSD1322_CMD_SET_PRECHARGE2 0xB6     // Set second pre-charge period
#define SSD1322_CMD_EN_GRAYSCALE_TABLE 0x00 // This command is sent to enable
											// the SSD1322_CMD_SET_GRAYSCALE_TBL
                                            // command
#define SSD1322_CMD_SET_GRAYSCALE_TBL 0xB8  // Set gray scale table
#define SSD1322_CMD_SET_GRAYSCALE_LIN 0xB9  // Set default linear gray scale table
#define SSD1322_CMD_SET_PRECHARGE_VOLT 0xBB // Set the pre-charge voltage level
#define SSD1322_CMD_SET_VCOMH 0xBE          // Set the COM deselect voltage level
#define SSD1322_CMD_SET_CONTRAST 0xC1       // Set the contrast value
#define SSD1322_CMD_SET_MASTER_CONTRAST 0xC7 // Set master contrast current
#define SSD1322_CMD_SET_MUX_RATIO 0xCA      // Set MUX ratio: 16..128
#define SSD1322_CMD_SET_DISPLAY_ENHB 0xD1   // Display enhancement B
#define SSD1322_CMD_SET_COMMAND_LOCK 0xFD   // Set MCU protection status

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
		unsigned char offset_x0; // horizontal segment offset of pixel with x=0
		unsigned char reverse_x:1; // reverse display horizontally
        unsigned char reverse_y:1;  // reverse display vertically
        unsigned char com_split:1; // enable odd/even split of COM pins
        unsigned char dual_com:1;  // =0 - disable dual COM mode
                                   // =1 - enable dual COM mode
        unsigned char precharge_t2:4; // Second pre-charge period [DCLK cycles]
        unsigned char contrast; // Contrast current= ISEG*contrast
        unsigned char master_contrast:4; // Reduce the output current for all levels
                                         // of gray to (master_contrast+1)/16
        unsigned char gpio0:2; // GPIO0
        unsigned char gpio1:2; // GPIO1
		    flash unsigned char *gray_scale_table; // pointer to gray scale table with gamma settings
        } GLCDINIT_t;

// Initialization values for divset
#define SSD1322_DIV1 0 // Divide osc. by 1
#define SSD1322_DIV2 1 // Divide osc. by 2
#define SSD1322_DIV4 2 // Divide osc. by 4
#define SSD1322_DIV8 3 // Divide osc. by 8
#define SSD1322_DIV16 4 // Divide osc. by 16
#define SSD1322_DIV32 5 // Divide osc. by 32
#define SSD1322_DIV64 6 // Divide osc. by 64
#define SSD1322_DIV128 7 // Divide osc. by 128
#define SSD1322_DIV256 8 // Divide osc. by 256
#define SSD1322_DIV512 9 // Divide osc. by 512
#define SSD1322_DIV1024 10 // Divide osc. by 1024

// Initialization values for phase1
#define SSD1322_PHASE1_5DCLK 2 // Phase 1 period=5 DCLK cycles
#define SSD1322_PHASE1_7DCLK 3 // Phase 1 period=7 DCLK cycles
#define SSD1322_PHASE1_9DCLK 4 // Phase 1 period=9 DCLK cycles
#define SSD1322_PHASE1_11DCLK 5 // Phase 1 period=11 DCLK cycles
#define SSD1322_PHASE1_13DCLK 6 // Phase 1 period=13 DCLK cycles
#define SSD1322_PHASE1_15DCLK 7 // Phase 1 period=15 DCLK cycles
#define SSD1322_PHASE1_17DCLK 8 // Phase 1 period=17 DCLK cycles
#define SSD1322_PHASE1_19DCLK 9 // Phase 1 period=19 DCLK cycles
#define SSD1322_PHASE1_21DCLK 10 // Phase 1 period=21 DCLK cycles
#define SSD1322_PHASE1_23DCLK 11 // Phase 1 period=23 DCLK cycles
#define SSD1322_PHASE1_25DCLK 12 // Phase 1 period=25 DCLK cycles
#define SSD1322_PHASE1_27DCLK 13 // Phase 1 period=27 DCLK cycles
#define SSD1322_PHASE1_29DCLK 14 // Phase 1 period=29 DCLK cycles
#define SSD1322_PHASE1_31DCLK 15 // Phase 1 period=31 DCLK cycles

// Initialization values for phase2
#define SSD1322_PHASE2_3DCLK 3 // Phase 2 period=3 DCLK cycles
#define SSD1322_PHASE2_4DCLK 4 // Phase 2 period=4 DCLK cycles
#define SSD1322_PHASE2_5DCLK 5 // Phase 2 period=5 DCLK cycles
#define SSD1322_PHASE2_6DCLK 6 // Phase 2 period=6 DCLK cycles
#define SSD1322_PHASE2_7DCLK 7 // Phase 2 period=7 DCLK cycles
#define SSD1322_PHASE2_8DCLK 8 // Phase 2 period=8 DCLK cycles
#define SSD1322_PHASE2_9DCLK 9 // Phase 2 period=9 DCLK cycles
#define SSD1322_PHASE2_10DCLK 10 // Phase 2 period=10 DCLK cycles
#define SSD1322_PHASE2_11DCLK 11 // Phase 2 period=11 DCLK cycles
#define SSD1322_PHASE2_12DCLK 12 // Phase 2 period=12 DCLK cycles
#define SSD1322_PHASE2_13DCLK 13 // Phase 2 period=13 DCLK cycles
#define SSD1322_PHASE2_14DCLK 14 // Phase 2 period=14 DCLK cycles
#define SSD1322_PHASE2_15DCLK 15 // Phase 2 period=15 DCLK cycles

// Initialization values for reverse_x
#define SSD1322_REVX_NORM 0 // Scan from COM0 to COMn-1
#define SSD1322_REVX_REV 1 // Scan from COMn-1 to COM0

// Initialization values for reverse_y
#define SSD1322_REVY_NORM 0 // Scan from COM0 to COMn-1
#define SSD1322_REVY_REV 1 // Scan from COMn-1 to COM0

// Initialization values for com_split
#define SSD1322_COM_SPLIT_OFF 0
#define SSD1322_COM_SPLIT_ON 1

// Initialization values for dual_com
#define SSD1322_DUAL_COM_OFF 0 // Disable dual COM mode
#define SSD1322_DUAL_COM_ON 1 // Enable dual COM mode

// Initialization values for gpio0 and gpio1
#define SSD1322_GPIO_HIZ 0 // I/O pin HiZ, no input
#define SSD1322_GPIO_INPUT 1 // Set I/O pin as input
#define SSD1322_GPIO_OUTPUT_LOW 2 // Set I/O pin as output with logic level 0
#define SSD1322_GPIO_OUTPUT_HIGH 3 // Set I/O pin as output with logic level 1

// Initialization value for gray_scale_table
#define SSD1322_GRAY_SCALE_LINEAR NULL // Use a linear gray scale

// Default value for divset
#define SSD1322_DEFAULT_DIVSET SSD1322_DIV2
// Default value for osc_freq
#define SSD1322_DEFAULT_OSC_FREQ 0x09
// Default value for phase1
#define SSD1322_DEFAULT_PHASE1 SSD1322_PHASE1_31DCLK
// Default value for phase2
#define SSD1322_DEFAULT_PHASE2 SSD1322_PHASE2_15DCLK
// Default value for precharge_v
#define SSD1322_DEFAULT_PRECHARGE_V 0x1F
// Default value for offset_x0
#define SSD1322_DEFAULT_OFFSETX0 0
// Default value for reverse_x
#define SSD1322_DEFAULT_REVX SSD1322_REVX_NORM
// Default value for reverse_y
#define SSD1322_DEFAULT_REVY SSD1322_REVY_NORM
// Default value for com_split
#define SSD1322_DEFAULT_COM_SPLIT SSD1322_COM_SPLIT_OFF
// Default value for dual_com
#define SSD1322_DEFAULT_DUAL_COM SSD1322_DUAL_COM_OFF
// Default value for precharge_t2
#define SSD1322_DEFAULT_PRECHARGE_T2 8
// Default value for vcomh
#define SSD1322_DEFAULT_VCOMH 7
// Default value for contrast
#define SSD1322_DEFAULT_CONTRAST 0xDF
// Default value for master_contrast
#define SSD1322_DEFAULT_MASTER_CONTRAST 15
// Default value for gpio0
#define SSD1322_DEFAULT_GPIO0 SSD1322_GPIO_HIZ
// Default value for gpio1
#define SSD1322_DEFAULT_GPIO1 SSD1322_GPIO_HIZ
// Default value for gray_scale_table
#define SSD1322_DEFAULT_GRAY_SCALE SSD1322_GRAY_SCALE_LINEAR

// Usual color definitions
#define GLCD_CL_BLACK 0x00
#define GLCD_CL_DARK_GRAY 0x04
#define GLCD_CL_GRAY 0x08
#define GLCD_CL_LIGHT_GRAY 0x0C
#define GLCD_CL_WHITE 0x0F

// Writes a command to the SSD1322 controller.
// Sets D /C=0
void ssd1322_wrcmd(unsigned char cmd);
// Writes data to the SSD1322 controller.
// Sets D /C=1
void ssd1322_wrdata(unsigned char data);
// Reads data from the SSD1322 controller.
// Sets D /C=1
unsigned char ssd1322_rddata(void);
// Sets the OLED display contrast value: 0..127
void ssd1322_setcontrast(unsigned char contrast);

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

#pragma library glcd_ssd1322.lib

#endif
