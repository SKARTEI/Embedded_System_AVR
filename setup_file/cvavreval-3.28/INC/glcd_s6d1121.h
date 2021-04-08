//*****************************************************************************
// Library functions for color TFT graphic LCDs with the
// Samsung S6D1121 controller
// (C) 2010-2014 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.15+
// Version: 1.01
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00
// 11112013_1 - Initial release.
//
// V1.01
// 05092014_1 - Added support for 320x240 landscape mode.
//*****************************************************************************

#ifndef _GLCD_S6D1121_INCLUDED_
#define _GLCD_S6D1121_INCLUDED_

#include <glcd_types.h>

// Use fast horizontal & vertical line drawing functions.
#define _GLCD_FAST_LINEH_
#define _GLCD_FAST_LINEV_

// S6D1121 controller ID
#define S6D1121_CTRL_ID 0x1121

// S6D1121 command register definitions
#define S6D1121_CMD_RD_PROD_CODE 0x00 // Read product code
#define S6D1121_CMD_DRIVER_OUT 0x01 // Driver output control
#define S6D1121_CMD_DRIVING_WAVEFORM 0x02 // LCD driving waveform control
#define S6D1121_CMD_ENTRY_MODE 0x03 // Entry mode control
#define S6D1121_CMD_OSC_CONTROL 0x04 // Oscillator control register
#define S6D1121_CMD_DISPLAY_CONTROL1 0x07 // Display control register 1
#define S6D1121_CMD_DISPLAY_CONTROL2 0x08 // Display control register 2
#define S6D1121_CMD_FRAME_CYCLE_CONTROL1 0x0a // Frame cycle control 1
#define S6D1121_CMD_FRAME_CYCLE_CONTROL2 0x0b // Frame cycle control 2
#define S6D1121_CMD_EXT_IF_CONTROL 0x0c // External display interface control register
#define S6D1121_CMD_POWER_CONTROL1 0x10 // Power control 1 register
#define S6D1121_CMD_POWER_CONTROL2 0x11 // Power control 2 register
#define S6D1121_CMD_POWER_CONTROL3 0x12 // Power control 3 register
#define S6D1121_CMD_POWER_CONTROL4 0x13 // Power control 4 register
#define S6D1121_CMD_POWER_CONTROL5 0x14 // Power control 5 register
#define S6D1121_CMD_POWER_CONTROL6 0x15 // Power control 6 register
#define S6D1121_CMD_POWER_CONTROL7 0x16 // Power control 7 register
#define S6D1121_CMD_GDDRAMX 0x20 // Set GRAM X address counter register
#define S6D1121_CMD_GDDRAMY 0x21 // Set GRAM Y address counter register
#define S6D1121_CMD_GDDRAM_DATA 0x22 // GRAM read/write data register
#define S6D1121_CMD_GAMMA_CONTROL1 0x30 // Gamma control 1
#define S6D1121_CMD_GAMMA_CONTROL2 0x31 // Gamma control 2
#define S6D1121_CMD_GAMMA_CONTROL3 0x32 // Gamma control 3
#define S6D1121_CMD_GAMMA_CONTROL4 0x33 // Gamma control 4
#define S6D1121_CMD_GAMMA_CONTROL5 0x34 // Gamma control 5
#define S6D1121_CMD_GAMMA_CONTROL6 0x35 // Gamma control 6
#define S6D1121_CMD_GAMMA_CONTROL7 0x36 // Gamma control 7
#define S6D1121_CMD_GAMMA_CONTROL8 0x37 // Gamma control 8
#define S6D1121_CMD_GAMMA_CONTROL9 0x38 // Gamma control 9
#define S6D1121_CMD_GAMMA_CONTROL10 0x39 // Gamma control 10
#define S6D1121_CMD_GAMMA_CONTROL11 0x3a // Gamma control 11
#define S6D1121_CMD_GAMMA_CONTROL12 0x3b // Gamma control 12
#define S6D1121_CMD_GAMMA_CONTROL13 0x3c // Gamma control 13
#define S6D1121_CMD_GAMMA_CONTROL14 0x3d // Gamma control 14
#define S6D1121_CMD_VERT_SCROLL_CONTROL 0x41 // Vertical scroll control
#define S6D1121_CMD_SCREEN1_DRIVING_POS_START 0x42 // Screen 1 driving position start
#define S6D1121_CMD_SCREEN1_DRIVING_POS_END 0x43 // Screen 1 driving position end
#define S6D1121_CMD_SCREEN2_DRIVING_POS_START 0x44 // Screen 2 driving position start
#define S6D1121_CMD_SCREEN2_DRIVING_POS_END 0x45 // Screen 2 driving position end
#define S6D1121_CMD_HORIZ_RAM_ADDR_START_END 0x46 // Address of horizontal start/end window positions
#define S6D1121_CMD_VERT_RAM_ADDR_END 0x47 // Address of vertical end window positions
#define S6D1121_CMD_VERT_RAM_ADDR_START 0x48 // Address of vertical start window positions
#define S6D1121_CMD_MDDI_WAKEUP_CONTROL 0x50 // MDDI wake up control
#define S6D1121_CMD_MDDI_WAKEUP_START 0x51 // MDDI wake up start position
#define S6D1121_CMD_SUBPANEL_CONTROL1 0x52 // Sub panel control 1
#define S6D1121_CMD_SUBPANEL_CONTROL2 0x53 // Sub panel control 2
#define S6D1121_CMD_SUBPANEL_CONTROL3 0x54 // Sub panel control 3
#define S6D1121_CMD_GPIO_CONTROL1 0x55 // GPIO control 1
#define S6D1121_CMD_GPIO_CONTROL2 0x56 // GPIO control 2
#define S6D1121_CMD_GPIO_CONTROL3 0x57 // GPIO control 3
#define S6D1121_CMD_GPIO_CONTROL4 0x58 // GPIO control 4
#define S6D1121_CMD_GPIO_CONTROL5 0x59 // GPIO control 5
#define S6D1121_CMD_MTP_CONTROL 0x60 // Multi Time Programmable control
#define S6D1121_CMD_MTP_RD_VCOMH 0x61 // Multi Time Programmable read VCOMH
#define S6D1121_CMD_MTP_TEST_KEY 0x62 // Multi Time Programmable test key
#define S6D1121_CMD_GOE_TIMING_CONTROL 0x70 // GOE start/end timing control
#define S6D1121_CMD_GSP_CLK_DELAY_CONTROL 0x71 // GSP clock delay control
#define S6D1121_CMD_VCOM_OUTPUT_CONTROL 0x78 // VCOM output control
#define S6D1121_CMD_PANEL_SIG_CONTROL1 0x79 // Panel signal control 1
#define S6D1121_CMD_PANEL_SIG_CONTROL2 0x7A // Panel signal control 2

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
        unsigned char cl_bits_order:1; // selects the color bits writing order to the display RAM
                                       // =0 -> RGB, =1 ->BGR
        unsigned char lcd_type:1; // LCD type =0 normally black, =1 normally white
		unsigned char vci1:3; // VCI1 voltage
		unsigned char vcoml:6; // VCOML=2.52+vcoml*0.04 [V]
		unsigned char vcomh:6; // VCOMH=3.52+(vcomh-10)*0.033 [V]
		unsigned char vcomdc:6; // VCOMDC=2.40+vcomdc*0.03125 [V]
        unsigned char gamma_voltage:6; // GVDD=3.0+gamma_voltage*0.03 [V]
        flash unsigned short *gamma_control; // pointer to an array located in FLASH memory
                                             // which contains gamma control adjustment
                                             // values for registers 1..14
        } GLCDINIT_t;

// Initialization values for reverse_x
#define S6D1121_REVX_NORM 0 // No horizontal reverse
#define S6D1121_REVX_REV 1 // Horizontal reverse

// Initialization values for reverse_y
#define S6D1121_REVY_NORM 0 // No vertical reverse
#define S6D1121_REVY_REV 1 // Vertical reverse

// Initialization values for cl_bits_order
#define S6D1121_CL_BITS_RGB 0 // Write color bits to display RAM in RGB order
#define S6D1121_CL_BITS_BGR 1 // Write color bits to display RAM in BGR order

// Initialization values for lcd_type
#define S6D1121_LCD_TYPE_BLACK 0
#define S6D1121_LCD_TYPE_WHITE 1

// Initialization values for vci1
#define S6D1121_VCI1_0_68VCIREF 0 // VCI1=0.68xVCI_REF
#define S6D1121_VCI1_0_83VCIREF 1 // VCI1=0.83xVCI_REF
#define S6D1121_VCI1_0_92VCIREF 2 // VCI1=0.92xVCI_REF
#define S6D1121_VCI1_1_00VCIREF 3 // VCI1=1.00xVCI_REF
#define S6D1121_VCI1_0_575VCIREF 4 // VCI1=0.575xVCI_REF

// Default value for reverse_x
#define S6D1121_DEFAULT_REVX S6D1121_REVX_NORM // No horizontal reverse
// Default value for reverse_y
#define S6D1121_DEFAULT_REVY S6D1121_REVY_NORM // No vertical reverse
// Default value for cl_bits_order (color bits writing order to display RAM)
#define S6D1121_DEFAULT_CL_BITS S6D1121_CL_BITS_RGB // write in RGB order
// Default value for lcd_type
#define S6D1121_DEFAULT_LCD_TYPE S6D1121_LCD_TYPE_WHITE
// Default value for vci1
#define S6D1121_DEFAULT_VCI1 S6D1121_VCI1_1_00VCIREF
// Default value for vcoml
#define S6D1121_DEFAULT_VCOML 0x2A
// Default value for vcomh
#define S6D1121_DEFAULT_VCOMH 0x26
// Default value for vcomdc
#define S6D1121_DEFAULT_VCOMDC 0x25
// Default value for gamma_voltage
#define S6D1121_DEFAULT_GAMMA_VOLTAGE 0x20
// Use the default initialization values, stored in the library,
// for the gamma control registers
#define S6D1121_DEFAULT_GAMMA 0

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
#define GLCD_CL_LIME 0xB0
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
#define GLCD_CL_LIME 0x87C0
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

// Writes a command to the S6D1121 controller.
void s6d1121_wrcmd(unsigned char cmd);
// Writes data to the S6D1121 controller.
void s6d1121_wrdata(unsigned short data);
// Reads a data word from the S6D1121 controller.
unsigned short s6d1121_rddata(void);
// Writes a word to a register of the S6D1121 controller.
void s6d1121_wrreg(unsigned char index, unsigned short data);
// Reads a word from a register of the S6D1121 controller.
unsigned short s6d1121_rdreg(unsigned char index);

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

// Fast draw a horizontal line from (x0,y0) to (x1,y0).
void glcd_lineh(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1);
// Fast draw a vertical line from (x0,y0) to (x0,y1).
void glcd_linev(GLCDX_t x0, GLCDY_t y0, GLCDY_t y1);

#pragma library glcd_s6d1121.lib

#endif
