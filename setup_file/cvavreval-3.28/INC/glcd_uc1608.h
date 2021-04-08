//******************************************************************************
// Library functions for graphic LCDs with the Ultrachip UC1608 controller
// (C) 2010-2014 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.10+
// Version: 1.00
//******************************************************************************

//******************************************************************************
// Revision history:
//
// V1.00      Initial release.
//******************************************************************************

#ifndef _GLCD_UC1608_INCLUDED_
#define _GLCD_UC1608_INCLUDED_

#include <glcd_types.h>

// UC1608 controller commands
#define UC1608_CMD_SET_ADDR_LOW 0x00 // set column address bits 0..3
#define UC1608_CMD_SET_ADDR_HIGH 0x10 // set column address bits 4..7
#define UC1608_CMD_MUX_RATE_TC 0x20 // sets the multiplex rate (# of rows)
                                    // and temperature compensation
#define UC1608_96ROWS (0<<2)  // 96 rows
#define UC1608_128ROWS (1<<2) // 128 rows (default)

#define UC1608_CMD_POWER_CTRL 0x28 // sets the usage of external or internal VLCD
                                   // and panel loading capacitance
#define UC1608_EXT_VLCD (0<<2) // use external VLCD source
#define UC1608_INT_VLCD (1<<2) // use internal VLCD source (default)

#define UC1608_CMD_START_LINE 0x40 // set display start line
#define UC1608_CMD_GAIN_POTENTIOMETER 0x81 // sets gain and potentiometer
#define UC1608_CMD_RAM_ADDR_CTRL 0x88 // controls the automatic column/page wrap around
                                      // and page address auto increment direction:
#define UC1608_WRAP_AROUND (1<<0) // enable automatic column/page wrap-around
                                  // on reaching boundary
#define UC1608_PA_AUTOINC (0<<2) // Page Address auto increment on reaching boundary
#define UC1608_PA_AUTODEC (1<<2) // Page Address auto decrement on reaching boundary

#define UC1608_CMD_SET_FIXED_LINES 0x90 // set the number of fixed display lines
#define UC1608_CMD_PIXELS_NORMAL 0xA4 // display the graphic RAM contents
#define UC1608_CMD_ALL_PIXELS_ON 0xA5 // all display pixels are on
#define UC1608_CMD_DISP_NORMAL 0xA6 // set normal display mode
#define UC1608_CMD_DISP_REVERSE 0xA7 // set reversed display mode
#define UC1608_CMD_DISP_OFF 0xAE // display off
#define UC1608_CMD_DISP_ON 0xAF // display on
#define UC1608_CMD_SET_PAGE 0xB0 // set display page address
#define UC1608_CMD_LCD_MAPPING_CTRL 0xC0 // set display horizontal and vertical mapping reversing
#define UC1608_CMD_RESET 0xE2 // resets the controller
#define UC1608_CMD_NOP 0xE3 // no operation
#define UC1608_CMD_BIAS_RATIO 0xE8 // set LCD voltage bias ratio
#define UC1608_RESET_CURSOR_MODE 0xEE // turns off the cursor update function
#define UC1608_SET_CURSOR_MODE 0xEF // turns on the cursor update function


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
        unsigned char contrast:6;  // LCD contrast value 0..63
        } GLCDINIT_t;

// values used for reverse_x initialization
#define UC1608_REVX_NORM 0 // set relationship between RAM column address and
                            // display driver: normal
#define UC1608_REVX_REV 1  // set relationship between RAM column address and
                            // display driver: reversed

// values used for reverse_y initialization
#define UC1608_REVY_NORM 0 // sets the vertical output scan direction 0->127
#define UC1608_REVY_REV 1  // sets the vertical output scan direction 127->0

// values used for temp_comp initialization
#define UC1608_TC000 (0<<0) // -0.00%/C (default)
#define UC1608_TC005 (1<<0) // -0.05%/C
#define UC1608_TC010 (2<<0) // -0.10%/C
#define UC1608_TC020 (3<<0) // -0.20%/C

// values used for panel_cap initialization
#define UC1608_PANEL_CAP_26NF (0<<0) // panel loading capacitance =< 26nF
#define UC1608_PANEL_CAP_43NF (1<<0) // 26nF < panel loading capacitance =< 43nF (default)
#define UC1608_PANEL_CAP_60NF (2<<0) // 43nF < panel loading capacitance =< 60nF
#define UC1608_PANEL_CAP_90NF (3<<0) // 60nF < panel loading capacitance =< 90nF

// values used for lcd_bias initialization
#define UC1608_BIAS_10_7 0 // 10.7
#define UC1608_BIAS_11_3 1 // 11.3
#define UC1608_BIAS_12_0 2 // 12.0 (default)
#define UC1608_BIAS_12_7 3 // 12.7

// default initialization values
#define UC1608_DEFAULT_REVX UC1608_REVX_NORM // default value for reverse_x
#define UC1608_DEFAULT_REVY UC1608_REVY_NORM // default value for reverse_y
#define UC1608_DEFAULT_TEMP_COMP UC1608_TC000 // default value for LCD temperature compensation
#define UC1608_DEFAULT_PANEL_CAP UC1608_PANEL_CAP_43NF // default LCD panel loading capacitance
#define UC1608_DEFAULT_LCD_BIAS UC1608_BIAS_12_0 // default LCD bias ratio
#define UC1608_DEFAULT_LCD_CONTRAST 18 // default LCD contrast 0..63
#define UC1608_DEFAULT_GAIN 1 // default gain

// Writes a command to the LCD controller
void uc1608_wrcmd(unsigned char cmd);
// Sets the LCD contrast [0..63]
void uc1608_setcontrast(unsigned char contrast);

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

#pragma library glcd_uc1608.lib

#endif




