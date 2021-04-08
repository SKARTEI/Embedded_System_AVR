//*****************************************************************************
// Library functions for graphic LCDs with the Sitronix ST7920 controller
// (C) 2010-2012 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V2.05.8+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00      Initial release.
// 
//*****************************************************************************

#ifndef _GLCD_ST7920_INCLUDED_
#define _GLCD_ST7920_INCLUDED_

#include <glcd_types.h>

// ST7920 commands
// Basic command set
#define ST7920_DISPLAY_CLEAR 0x01 // clear display
#define ST7920_RETURN_HOME 0x02 // return cursor to origin
#define ST7920_ENTRY_MODE_SET 0x04 // set cursor position & display shift when
                                   // doing write or read
// entry mode bits:
#define ST7920_ENTRY_CURSOR_RIGHT 0x02 // cursor moves right, address counter+=1
#define ST7920_ENTRY_SHIFT_DISPL 0x01 // shift entire display

#define ST7920_DISPLAY_CTRL 0x08 // display control
// display control bits:
#define ST7920_DISPLAY_ON 0x04 // display on
#define ST7920_CURSOR_ON 0x02 // cursor on
#define ST7920_BLINK 0x01 // character blinks at cursor position

#define ST7920_CURSOR_DISPLAY_SHIFT_CTRL 0x10 // cursor/display shift control
// cursor/display shift control bits:
#define ST7920_SHIFT_DISPLAY 0x08 // shift display
#define ST7920_SHIFT_RIGHT 0x04 // shifts right

#define ST7920_FUNC_SET 0x20 // function set
// function set control bits:
// must not be applied at the same time!
// change ST7920_8BIT or ST7920_GRAPHICS_ON first, then ST7920_EXTENDED 
#define ST7920_8BIT 0x10 // 8 bit interface
#define ST7920_EXTENDED 0x04 // select the extended command set
#define ST7920_GRAPHICS_ON 0x02 // turn graphics display on

#define ST7920_SET_CGRAM_ADDR 0x40 // writes CGRAM address into address counter AC 
#define ST7920_SET_DDRAM_ADDR 0x80 // writes DDRAM address into address counter AC
                                   // start for line #1 of text AC=0x00
                                   // start for line #2 of text AC=0x10
                                   // start for line #3 of text AC=horizontal_display_resolution/16
                                   // start for line #4 of text AC=0x10+horizontal_display_resolution/16
// Extended command set
#define ST7920_STANDBY 0x01 // enter standby mode
#define ST7920_ENABLE_SET_CGRAM_ADDR 0x02 // enable the ST7920_SET_CGRAM_ADDR command
#define ST7920_VERT_SCROLL 0x03 // enable vertical scroll mode and disable the
                                // ST7920_SET_CGRAM_ADDR command
#define ST7920_REVERSE_LINE 0x04 // toggle reverse condition for a line of text
#define ST7920_SET_SCROLL_ADDR 0x40 // set vertical scroll displacement address
#define ST7920_SET_GDRAM_ADDR 0x80 // set the vertical and horizontal addresses
                                   // for the graphic display RAM into address counter
 
// structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data); 
        } GLCDINIT_t;

// Writes a command to the ST7920 controller.
void st7920_wrcmd(unsigned char cmd);
// Writes data to the ST7920 controller's RAM.
void st7920_wrdata(unsigned char data);
// Reads data from the ST7920 controller's RAM.
unsigned char st7920_rddata(void);
        
// Initializes the graphic controller and clears the LCD.
bool glcd_init(GLCDINIT_t *init_data);
// Turns LCD on/off.
void glcd_display(bool on);
// Clears the LCD by setting it's color to the background color.
void glcd_clear(void);
// Clears the text area when the internal character generator is used.
void glcd_cleartext(void);
// Clears the graphics area by setting it's color to the background color.
void glcd_cleargraphics(void);
// Sets the color of the pixel at coordinates x, y.
void glcd_putpixel(GLCDX_t x, GLCDY_t y, GLCDCOL_t color);
// Returns the color of the pixel at coordinates x, y.
GLCDCOL_t glcd_getpixel(GLCDX_t x, GLCDY_t y);

// Writes/reads a block of bytes as a bitmap image
// at/from specified coordinates.
void glcd_block(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDMEM_t memt, GLCDMEMADDR_t addr, GLCDBLOCKMODE_t mode);

// Displays an ASCII character at the x, y character positions 
// using the internal character generator
void glcd_putcharcg(unsigned char x,unsigned char y,unsigned char c);
// Defines a character in the Character Generator RAM.
void glcd_definechar(unsigned char c,flash unsigned char *data);

// The following functions are compatible with the ones for
// the alphanumeric LCDs from alcd.h

// Clears the text area when the internal character generator is used.
#define lcd_clear() glcd_cleartext()  
// Sets the LCD display position when displaying text
// using the internal character generator.
void lcd_gotoxy(unsigned char x,unsigned char y);
// Displays an ASCII character at current text character position
// using the internal character generator.
void lcd_putchar(char c);
// Write the string str located in SRAM to the LCD
// using the internal character generator.
void lcd_puts(char *str);
// Write the string str located in FLASH to the LCD
// using the internal character generator.
void lcd_putsf(char flash *str);
// Write the string str located in EEPROM to the LCD
// using the internal character generator.
void lcd_putse(char eeprom *str);

#pragma library glcd_st7920.lib

#endif




