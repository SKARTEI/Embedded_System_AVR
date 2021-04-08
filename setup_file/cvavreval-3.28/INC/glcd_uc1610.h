//******************************************************************************
// Library functions for graphic LCDs with the Ultrachip UC1610 controller
// using the serial interface mode.
// (C) 2010-2016 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.25+
// Version: 1.01
//******************************************************************************

//******************************************************************************
// Revision history:
//
// V1.00      Initial release.
// V1.01      21012016_1 Fixed reverse_x and reverse_y not working correctly
//            28012016_2 Added support for SPI mode
//******************************************************************************

#ifndef _GLCD_UC1610_INCLUDED_
#define _GLCD_UC1610_INCLUDED_

#include <glcd_types.h>

// UC1610 controller commands
#define UC1610_CMD_SET_ADDR_LOW 0x00  // set column address bits 0..3
#define UC1610_CMD_SET_ADDR_HIGH 0x10 // set column address bits 4..7
#define UC1610_CMD_TEMP_COMP 0x24 // set Vbias temperature compensation
#define UC1610_CMD_PANEL_LOADING 0x28 // set panel loading capacitance
#define UC1610_CMD_PUMP_CTRL 0x2C // programs the build-in charge pump stages:
#define UC1610_EXT_VLCD 0         // uses external Vlcd
#define UC1610_7X_PUMP  1         // uses internal Vlcd, 7x pump   
#define UC1610_6X_PUMP  2         // uses internal Vlcd, 6x pump   
#define UC1610_8X_PUMP  3         // uses internal Vlcd, 8x pump   

#define UC1610_CMD_SCROLL_LINE_LSB 0x40 // set scroll line bits 0..3 
#define UC1610_CMD_SCROLL_LINE_MSB 0x50 // set scroll line bits 4..6
#define UC1610_CMD_SET_PAGE 0x60        // set display page address
#define UC1610_CMD_VBIAS 0x81           // set Vbias potentiometer
#define UC1610_CMD_PARTIAL_CTRL 0x84    // set partial display function
#define UC1610_CMD_RAM_ADDR_CTRL 0x88   // controls the automatic column/page wrap around
                                        // and page address auto increment direction:
#define UC1610_WRAP_AROUND (1<<0) // enable automatic column/page wrap-around
                                  // on reaching boundary
#define UC1610_CA_AUTOINC_FIRST (0<<1) // column address first auto increments on reaching boundary
#define UC1610_PA_AUTOINC_FIRST (1<<1) // page address first auto increments on reaching boundary
#define UC1610_PA_AUTOINC (0<<2)  // page address auto increment on reaching boundary
#define UC1610_PA_AUTODEC (1<<2)  // page address auto decrement on reaching boundary

#define UC1610_CMD_SET_FIXED_LINES 0x90 // set the number of fixed display lines
#define UC1610_CMD_SET_LINE_RATE 0xA0   // set the Line Rate (Frame Rate = Line Rate/Mux Rate)
#define UC1610_LINE_RATE_12_1 0 // Line Rate= 12.1 kLines/s
#define UC1610_LINE_RATE_13_4 1 // Line Rate= 13.4 kLines/s
#define UC1610_LINE_RATE_14_7 2 // Line Rate= 14.7 kLines/s
#define UC1610_LINE_RATE_16_6 3 // Line Rate= 16.6 kLines/s

#define UC1610_CMD_PIXELS_NORMAL 0xA4 // display the graphic RAM contents
#define UC1610_CMD_ALL_PIXELS_ON 0xA5 // all display pixels are on
#define UC1610_CMD_DISP_NORMAL 0xA6   // set normal display mode
#define UC1610_CMD_DISP_REVERSE 0xA7  // set reversed display mode
#define UC1610_CMD_DISP_OFF 0xAE      // display off
#define UC1610_CMD_DISP_ON 0xAF       // display on
#define UC1610_CMD_LCD_MAPPING_CTRL 0xC0 // set display horizontal and vertical mapping reversing
#define UC1610_CMD_LCD_GRAY_SHADE 0xD0   // set the voltage RMS separation between the two
                                         // gray shade levels
#define UC1610_CMD_RESET 0xE2 // resets the controller
#define UC1610_CMD_NOP 0xE3   // no operation
#define UC1610_CMD_BIAS_RATIO 0xE8 // set the LCD voltage bias ratio
#define UC1610_CMD_RESET_CURSOR_MODE 0xEE // turns off the cursor update function
#define UC1610_CMD_SET_CURSOR_MODE 0xEF   // turns on the cursor update function
#define UC1610_CMD_COM_END 0xF1    // set the number of used COM electrodes -1
#define UC1610_CMD_DISP_START 0xF2 // set the starting COM electrode, which has been assigned
                                   // a full scanning period, and which will output
                                   // an active COM scanning pulse
#define UC1610_CMD_DISP_END 0xF3   // set the ending COM electrode, which has been assigned
                                   // a full scanning period, and which will output
                                   // an active COM scanning pulse
#define UC1610_CMD_WINDOW_START_COL 0xF4  // set the display window start column address
#define UC1610_CMD_WINDOW_START_PAGE 0xF5 // set the display window start page address
#define UC1610_CMD_WINDOW_END_COL 0xF6    // set the display window end column address
#define UC1610_CMD_WINDOW_END_PAGE 0xF7   // set the display window end page address
#define UC1610_CMD_WINDOW_PGM_EN 0xF8     // enables the window program function 

// structure that contains controller specific graphic LCD initialization data
typedef struct
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr);
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char reverse_x:1; // reverse display horizontally
        unsigned char reverse_y:1; // reverse display vertically
        unsigned char temp_comp:2; // temperature compensation
        unsigned char panel_cap:2; // LCD panel capacitance
        unsigned char lcd_bias:2;  // LCD bias voltage ratio
        unsigned char contrast;    // LCD contrast 0..255
        } GLCDINIT_t;

// values used for reverse_x initialization
#define UC1610_REVX_NORM 0 // set relationship between RAM column address and
                            // display driver: normal
#define UC1610_REVX_REV 1  // set relationship between RAM column address and
                            // display driver: reversed

// values used for reverse_y initialization
#define UC1610_REVY_NORM 0 // sets the vertical output scan direction 0->103
#define UC1610_REVY_REV 1  // sets the vertical output scan direction 103->0

// values used for temp_comp initialization
#define UC1610_TC005 0   // -0.05%/C
#define UC1610_TC010 1   // -0.10%/C
#define UC1610_TC015 2   // -0.15%/C
#define UC1610_TC020 3   // -0.20%/C

// values used for panel_cap initialization
#define UC1610_PANEL_CAP_16NF 0 // Cpanel <= 16nF
#define UC1610_PANEL_CAP_21NF 1 // 16nF < Cpanel <= 21nF
#define UC1610_PANEL_CAP_28NF 2 // 21nF < Cpanel <= 28nF
#define UC1610_PANEL_CAP_38NF 3 // 28nF < Cpanel <= 38nF

// values used for lcd_bias initialization
#define UC1610_BIAS_1_5 0  // 1/5
#define UC1610_BIAS_1_10 1 // 1/10
#define UC1610_BIAS_1_11 2 // 1/11
#define UC1610_BIAS_1_12 3 // 1/12

// default initialization values
#define UC1610_DEFAULT_REVX UC1610_REVX_NORM // default value for reverse_x
#define UC1610_DEFAULT_REVY UC1610_REVY_NORM // default value for reverse_y
#define UC1610_DEFAULT_TEMP_COMP UC1610_TC005 // default value for LCD temperature compensation
#define UC1610_DEFAULT_PANEL_CAP UC1610_PANEL_CAP_38NF // default LCD panel loading capacitance
#define UC1610_DEFAULT_LCD_BIAS UC1610_BIAS_1_12 // default LCD bias ratio
#define UC1610_DEFAULT_LCD_CONTRAST 0x5F // default LCD contrast 0..255

// Writes a command to the LCD controller
void uc1610_wrcmd(unsigned char cmd);
// Sets the LCD contrast [0..63]
void uc1610_setcontrast(unsigned char contrast);

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

#pragma library glcd_uc1610.lib

#endif




