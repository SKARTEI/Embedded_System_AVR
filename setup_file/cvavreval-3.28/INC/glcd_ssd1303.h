//******************************************************************************
// Library functions for graphic OLED displays with the
// Solomon Systech SSD1303 and Sino Wealth SH1101A controllers
// (C) 2010-2013 Pavel Haiduc, HP InfoTech s.r.l.,
// All rights reserved
//
// Compiler: CodeVisionAVR V3.07+
// Version: 1.01
//******************************************************************************

//******************************************************************************
// Revision history:
// 
// V1.00      Initial release.
//
// V1.01      Corrected macros SSD1303_CMD_POWER_SAVE_OFF and
//            SSD1303_CMD_POWER_SAVE_ON  
//******************************************************************************

#ifndef _GLCD_SSD1303_INCLUDED_
#define _GLCD_SSD1303_INCLUDED_

#include <glcd_types.h>

// SSD1303 controller commands
#define SSD1303_CMD_SET_ADDR_LOW 0x00 // set column address bits 0..3
#define SSD1303_CMD_SET_ADDR_HIGH 0x10 // set column address bits 4..7
#define SSD1303_CMD_SET_HORIZ_SCROLL 0x26 // horizontal scroll setup
#define SSD1303_CMD_HORIZ_SCROLL_OFF 0x2E // deactivate horizontal scroll
#define SSD1303_CMD_HORIZ_SCROLL_ON 0x2F // activate horizontal scroll
#define SSD1303_CMD_START_LINE 0x40 // set display start line
#define SSD1303_CMD_SET_PAGE 0xB0 // set display page address

#define SSD1303_CMD_SET_CONTRAST 0x81 // sets the contrast control register
#define SSD1303_CMD_SET_BRIGHTNESS 0x82 // sets the brightness control register
#define SSD1303_CMD_SET_LUT 0x91 // sets the Look Up Table
#define SSD1303_CMD_SET_COLOR_BANK1_16 0x92 // sets the colors for banks 1-16                                       
#define SSD1303_CMD_SET_COLOR_BANK17_32 0x93 // sets the colors for banks 17-32                                       

#define SSD1303_CMD_ADC_SELECT_NORM 0xA0 // set the relationship between RAM column address and
                                         // display driver: normal
#define SSD1303_CMD_ADC_SELECT_REV 0xA1  // set the relationship between RAM column address and
                                         // display driver: reversed
#define SSD1303_CMD_DISP_NORMAL 0xA6 // set normal display mode 
#define SSD1303_CMD_DISP_REVERSE 0xA7 // set reversed display mode
#define SSD1303_CMD_MUX_RATIO 0xA8 // set multiplex ratio
#define SSD1303_CMD_PIXELS_NORMAL 0xA4 // display the graphic RAM contents
#define SSD1303_CMD_ALL_PIXELS_ON 0xA5 // all display pixels are on
#define SSD1303_CMD_DC_DC 0xAD // turn the DC/DC converter on/off
#define SSD1303_DC_DC_OFF 0x8A // second byte of the command: DC/DC off
#define SSD1303_DC_DC_ON 0x8B // second byte of the command: DC/DC on

#define SSD1303_CMD_DISP_OFF 0xAE // display off
#define SSD1303_CMD_DISP_ON 0xAF // display on

#define SSD1303_CMD_COM0_63 0xC0 // sets the COM output scan direction 0->63
#define SSD1303_CMD_COM63_0 0xC8 // sets the COM output scan direction 63->0

#define SSD1303_CMD_DISPL_OFFSET 0xD3 // set display offset
#define SSD1303_CMD_DISPL_CLK 0xD5 // set display clock division ratio and oscillator frequency
#define SSD1303_CMD_AREA_COLOR_POWER_SAVE 0xD8 // set area color and power-save modes
#define SSD1303_CMD_POWER_SAVE_OFF 0 // second command byte for power-save off
#define SSD1303_CMD_POWER_SAVE_ON 0x05 // second command byte for power-save on
#define SSD1303_CMD_PRECHARGE_PERIOD 0xD9 // set pre-charge period for Phase 1 and Phase 2
#define SSD1303_CMD_COM_CONFIG 0xDA // set COM pins hardware configuration: interlaced or non-interlaced
#define SSD1303_CMD_INTERLACED 0x12 // second command byte for interlaced operation
#define SSD1303_CMD_NON_INTERLACED 0x02 // second command byte for non-interlaced operation

#define SSD1303_CMD_VCOM_DESELECT 0xDB // set VCOM deselect level

// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char reverse_x:1; // reverse display horizontally (ADC) 
        unsigned char reverse_xoffs:3; // specify the X offset when plotting pixels
                                       // if reverse_x=1, usual value is 132-_GLCD_MAXX_
        unsigned char reverse_y:1; // reverse display vertically (COM)
        unsigned char interlaced:1; // use vertically interlaced display
        unsigned char contrast; // OLED contrast
        } GLCDINIT_t;
        
// values used for reverse_x initialization
#define SSD1303_REVX_NORM 0 // set relationship between RAM column address and
                            // display driver: normal (ADC=0)
#define SSD1303_REVX_REV 1  // set relationship between RAM column address and
                            // display driver: reversed (ADC=1)

// values used for reverse_y initialization 
#define SSD1303_REVY_NORM 0 // sets the vertical COM output scan direction 0->63
#define SSD1303_REVY_REV 1  // sets the vertical COM output scan direction 63->0

// values used for interlaced initialization
#define SSD1303_NON_INTERLACED 0
#define SSD1303_INTERLACED 1

// default initialization values
// default value for reverse_x
#define SSD1303_DEFAULT_REVX SSD1303_REVX_NORM 
// default value for reverse_xoffs
// effective only when reverse_x=1 (SSD1303_REVX_REV)
#define SSD1303_DEFAULT_REV_XOFFS (132-_GLCD_MAXX_)
// default value for reverse_y 
#define SSD1303_DEFAULT_REVY SSD1303_REVY_NORM
// default value for interlaced 
#define SSD1303_DEFAULT_INTERLACED SSD1303_INTERLACED
// default contrast 
#define SSD1303_DEFAULT_CONTRAST 128

// Writes a command to the OLED display controller
void ssd1303_wrcmd(unsigned char cmd);
// Sets the OLED display contrast
void ssd1303_setcontrast(unsigned char contrast);

// Initializes the graphic controller and clears the display.
bool glcd_init(GLCDINIT_t *init_data);
// Turns display on/off.
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

#pragma library glcd_ssd1303.lib

#endif




