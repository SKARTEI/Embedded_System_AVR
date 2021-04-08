//*****************************************************************************
// Library functions for color TFT graphic LCDs with the
// Samsung S6D0164X01 controller
// (C) 2010-2015 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.22+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00
// 20052015_1 - Initial release.
//*****************************************************************************

#ifndef _GLCD_S6D0164_INCLUDED_
#define _GLCD_S6D0164_INCLUDED_

#include <glcd_types.h>

// Use fast horizontal & vertical line drawing functions.
#define _GLCD_FAST_LINEH_
#define _GLCD_FAST_LINEV_

// S6D0164 controller ID
#define S6D0164_CTRL_ID 0x0164

// S6D0164 command register definitions
#define S6D0164_CMD_RD_PROD_CODE 0x00 // Read product code
#define S6D0164_CMD_DRIVER_OUT 0x01 // Driver output control
#define S6D0164_CMD_DRIVING_WAVEFORM 0x02 // LCD driving waveform control
#define S6D0164_CMD_ENTRY_MODE 0x03 // Entry mode control
#define S6D0164_CMD_DISPLAY_CONTROL 0x07 // Display control register
#define S6D0164_CMD_BLANK_PERIOD_CONTROL1 0x08 // Blank period control register 1
#define S6D0164_CMD_FRAME_CYCLE_CONTROL 0x0b // Frame cycle control register
#define S6D0164_CMD_EXT_IF_CONTROL 0x0c // External display interface control register
#define S6D0164_CMD_START_OSC 0x0f // Start oscillator register
#define S6D0164_CMD_POWER_CONTROL1 0x10 // Power control 1 register
#define S6D0164_CMD_POWER_CONTROL2 0x11 // Power control 2 register
#define S6D0164_CMD_POWER_CONTROL3 0x12 // Power control 3 register
#define S6D0164_CMD_POWER_CONTROL4 0x13 // Power control 4 register
#define S6D0164_CMD_POWER_CONTROL5 0x14 // Power control 5 register
#define S6D0164_CMD_VCI_RECYCLING 0x15 //  VCI recycling period setting register
#define S6D0164_CMD_GDDRAMX 0x20 // Set GRAM X address counter register
#define S6D0164_CMD_GDDRAMY 0x21 // Set GRAM Y address counter register
#define S6D0164_CMD_GDDRAM_DATA 0x22 // GRAM read/write data register
#define S6D0164_CMD_SOFTWARE_RESET 0x28 // Software reset register
#define S6D0164_CMD_GATE_SCAN 0x30 // Gate scan position register
#define S6D0164_CMD_VERT_SCROLL_CONTROL1_END 0x31 // Vertical scroll control 1 end addr.
#define S6D0164_CMD_VERT_SCROLL_CONTROL1_START 0x32 // Vertical scroll control 1 start addr.
#define S6D0164_CMD_VERT_SCROLL_CONTROL2 0x33 // Vertical scroll control 2
#define S6D0164_CMD_SCREEN_DRIVING_POS_END 0x34 // Partial Screen end driving position
#define S6D0164_CMD_SCREEN_DRIVING_POS_START 0x35 // Partial Screen start driving position
#define S6D0164_CMD_HORIZ_RAM_ADDR_END 0x36 // Address of horizontal end window position
#define S6D0164_CMD_HORIZ_RAM_ADDR_START 0x37 // Address of horizontal start window position
#define S6D0164_CMD_VERT_RAM_ADDR_END 0x38 // Address of vertical end window position
#define S6D0164_CMD_VERT_RAM_ADDR_START 0x39 // Address of vertical start window position
#define S6D0164_CMD_GAMMA_CONTROL1 0x50 // Gamma control 1
#define S6D0164_CMD_GAMMA_CONTROL2 0x51 // Gamma control 2
#define S6D0164_CMD_GAMMA_CONTROL3 0x52 // Gamma control 3
#define S6D0164_CMD_GAMMA_CONTROL4 0x53 // Gamma control 4
#define S6D0164_CMD_GAMMA_CONTROL5 0x54 // Gamma control 5
#define S6D0164_CMD_GAMMA_CONTROL6 0x55 // Gamma control 6
#define S6D0164_CMD_GAMMA_CONTROL7 0x56 // Gamma control 7
#define S6D0164_CMD_GAMMA_CONTROL8 0x57 // Gamma control 8
#define S6D0164_CMD_GAMMA_CONTROL9 0x58 // Gamma control 9
#define S6D0164_CMD_GAMMA_CONTROL10 0x59 // Gamma control 10

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
		unsigned char vci1:4; // VCI1 voltage
		unsigned char vcoml:7; // VCOML=GVDD*(0.534+0.006*(vcoml-15)) [V]
		unsigned char vcomh:7; // VCOMH=GVDD*(0.4015+0.0055*vcomh) [V]
        unsigned char gamma_voltage:7; // GVDD=2.50+gamma_voltage*0.02 [V]
        flash unsigned short *gamma_control; // pointer to an array located in FLASH memory
                                             // which contains gamma control adjustment
                                             // values for registers 1..10
        } GLCDINIT_t;

// Initialization values for reverse_x
#define S6D0164_REVX_NORM 0 // No horizontal reverse
#define S6D0164_REVX_REV 1 // Horizontal reverse

// Initialization values for reverse_y
#define S6D0164_REVY_NORM 0 // No vertical reverse
#define S6D0164_REVY_REV 1 // Vertical reverse

// Initialization values for cl_bits_order
#define S6D0164_CL_BITS_RGB 0 // Write color bits to display RAM in RGB order
#define S6D0164_CL_BITS_BGR 1 // Write color bits to display RAM in BGR order

// Initialization values for lcd_type
#define S6D0164_LCD_TYPE_BLACK 0
#define S6D0164_LCD_TYPE_WHITE 1

// Initialization values for vci1
#define S6D0164_VCI1_1_35V 0 // VCI1=1.35V
#define S6D0164_VCI1_1_75V 1 // VCI1=1.75V
#define S6D0164_VCI1_2_07V 2 // VCI1=2.07V
#define S6D0164_VCI1_2_16V 3 // VCI1=2.16V
#define S6D0164_VCI1_2_25V 4 // VCI1=2.25V
#define S6D0164_VCI1_2_34V 5 // VCI1=2.34V
#define S6D0164_VCI1_2_43V 6 // VCI1=2.43V
#define S6D0164_VCI1_2_52V 7 // VCI1=2.52V
#define S6D0164_VCI1_2_58V 8 // VCI1=2.58V
#define S6D0164_VCI1_2_64V 9 // VCI1=2.64V
#define S6D0164_VCI1_2_70V 10 // VCI1=2.70V
#define S6D0164_VCI1_2_76V 11 // VCI1=2.76V
#define S6D0164_VCI1_2_82V 12 // VCI1=2.82V
#define S6D0164_VCI1_2_88V 13 // VCI1=2.88V
#define S6D0164_VCI1_2_94V 14 // VCI1=2.94V
#define S6D0164_VCI1_3_00V 15 // VCI1=3.00V

// Default value for reverse_x
#define S6D0164_DEFAULT_REVX S6D0164_REVX_NORM // No horizontal reverse
// Default value for reverse_y
#define S6D0164_DEFAULT_REVY S6D0164_REVY_NORM // No vertical reverse
// Default value for cl_bits_order (color bits writing order to display RAM)
#define S6D0164_DEFAULT_CL_BITS S6D0164_CL_BITS_RGB // write in RGB order
// Default value for lcd_type
#define S6D0164_DEFAULT_LCD_TYPE S6D0164_LCD_TYPE_WHITE
// Default value for vci1
#define S6D0164_DEFAULT_VCI1 S6D0164_VCI1_2_70V
// Default value for vcoml
#define S6D0164_DEFAULT_VCOML 0x49
// Default value for vcomh
#define S6D0164_DEFAULT_VCOMH 0x42
// Default value for gamma_voltage
#define S6D0164_DEFAULT_GAMMA_VOLTAGE 0x6C
// Use the default initialization values, stored in the library,
// for the gamma control registers
#define S6D0164_DEFAULT_GAMMA 0

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

// Writes a command to the S6D0164 controller.
void s6d0164_wrcmd(unsigned char cmd);
// Writes data to the S6D0164 controller.
void s6d0164_wrdata(unsigned short data);
// Reads a data word from the S6D0164 controller.
unsigned short s6d0164_rddata(void);
// Writes a word to a register of the S6D0164 controller.
void s6d0164_wrreg(unsigned char index, unsigned short data);
// Reads a word from a register of the S6D0164 controller.
unsigned short s6d0164_rdreg(unsigned char index);

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

#pragma library glcd_s6d0164.lib

#endif
