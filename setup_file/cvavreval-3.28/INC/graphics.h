//*****************************************************************************
// Library functions for graphic LCDs
// (C) 2010-2016 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.25+
// Version: 1.13
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00      Initial release.
//
// V1.01
// 06072011_2 Modified the glcd_putchar function so that it fills the spaces
//            between the characters with the background color.
//            Added the GLCD_CLEARBLOCK and GLCD_SETBLOCK modes to the
//            glcd_block function for this purpose.
//
// V1.02
// 30092011_1 Modified the glcd_imagezise function to support color displays.
// 03102011_1 Modified the glcd_getimage, glcd_getimagee, glcd_getimagex
//            functions to support only the GLCD_PUTCOPY mode for color
//            displays.
// 26102011_1 Rewrote the glcd_floodfill function in order to significantly
//            reduce Data Stack usage.
// 27102011_2 Added the glcd_setfillcolor and glcd_getfillcolor macros.
// 27102011_3 Added the transparent text display mode for color displays.
// 28102011_1 Fixed a bug in glcd_line which prevented drawing lines for
//            y coordinates larger than _GLCD_MAXX_ value.
// 28102011_2 Modified the declarations of glcd_circle, glcd_arc,
//            glcd_pieslice, glcd_fillcircle functions to support the
//            GLCDRAD_t data type for radius parameter.
//
// V1.03
// 02022012_4 Added transparency support for displaying images.
//
// V1.04
// 02042012_1 Added usage of hardware accelerated line drawing.
//
// V1.05
// 27072012_1 Don't declare the new_line local variable
//            when hardware accelerated line drawing is used.
//
// V1.06
// 20092012_1 Fixed: the glcd_putimagex function was not accessing data
//            from external memory
//
// V1.07
// 04062013_1 Fixed: the glcd_getcharw function was not returning a correct
//            value if the last character from the displayed font had
//            ASCII code 0xFF
//
// V1.08
// 24082013_1 Added support for the SSD1322 display controller
//
// V1.09
// 22112013_1 If the _GLCD_MAXX_ or _GLCD_MAXY_ macros are not defined,
//            replace them with corresponding variables
//
// V1.10
// 20102014_1 Added compatibility with enhanced parameter passing mode 2
//
// V1.11
// 07012015_1 Added support for RA8875 TFT controller
// 03022015_1 Added small code optimization in the glcd_line function
// 03022015_2 Added the glcd_fillrectround function
// 04022015_1 Added definition for _GLCD_FILL_PATTERN_HEIGHT_
// 06022015_3 Added the glcd_triangle and glcd_filltriangle functions
//
// V1.12
// 10062015_1 Added the glcd_ellipse and glcd_fillellipse functions
//            for all the graphic controllers.
//
// V1.13
// 07012016_1 Corrected the glcd_imagesize function returning 0
//            for width=_GLCD_MAXX_ or height=_GLCD_MAXY_ 
// 12012016_1 Added the glcd_printf and glcd_printfxy functions
// 23012016_1 Added the glcd_boxsize, glcd_boxsizef and
//            glcd_boxsizee functions
// 24012016_1 Added the glcd_outtextoffs, glcd_outtextoffsf and
//            glcd_outtextoffse functions
// 10022016_1 Fixed: glcd_rectrel drawed the rectangle 1 pixel
//            wider and higher than specified
//*****************************************************************************

#ifndef _GRAPHICS_INCLUDED_
#define _GRAPHICS_INCLUDED_

#include <glcd.h>

extern GLCDSTATE_t glcd_state;

// 22112013_1
#ifndef _GLCD_MAXX_
extern unsigned short _GLCD_MAXX_;
#endif
// 22112013_1
#ifndef _GLCD_MAXY_
extern unsigned short _GLCD_MAXY_;
#endif

// Initializes the graphic controller and clears the LCD.
bool glcd_init(GLCDINIT_t *init_data);
// Turns LCD on/off.
void glcd_display(bool on);

// Sets the display's foreground color.
#define glcd_setcolor(foreground_color) {glcd_state.fgcolor=(foreground_color);}
// Sets the display's background color.
#define glcd_setbkcolor(background_color) {glcd_state.bkcolor=(background_color);}
// Sets the transparent color for image displaying in transparent mode. 20022012_4
#define glcd_settpcolor(transparent_color) {glcd_state.tpcolor=(transparent_color);}
// Sets the fill color for glcd_floodfill. 27102011_2
#define glcd_setfillcolor(fill_color) {glcd_state.fill.color=(fill_color);}
// Returns the display's foreground color.
#define glcd_getcolor() glcd_state.fgcolor
// Returns the display's background color.
#define glcd_getbkcolor() glcd_state.bkcolor
// Returns transparent color for image displaying in transparent mode. 20022012_4
#define glcd_gettpcolor() glcd_state.tpcolor
// Returns the fill color used by glcd_floodfill. 27102011_2
#define glcd_getfillcolor() glcd_state.fill.color
// Returns the maximum supported color.
#define glcd_getmaxcolor() _GLCD_MAXCOLOR_
// Returns the maximum X horizontal coordinate value.
#define glcd_getmaxx() (_GLCD_MAXX_-1)
// Returns the maximum Y vertical coordinate value.
#define glcd_getmaxy() (_GLCD_MAXY_-1)

// Clears the LCD by setting it's color to the background color.
void glcd_clear(void);

#if _GLCD_INTERNAL_FONT_WIDTH_==0
#define glcd_cleargraphics() glcd_clear()
#endif

// Ensure that X coordinates are clipped.
short glcd_clipx(short x);
// Ensure that Y coordinates are clipped.
short glcd_clipy(short y);
// Sets the color of the pixel at coordinates x, y.
void glcd_putpixel(GLCDX_t x, GLCDY_t y, GLCDCOL_t color);
// Sets the pixel at coordinates x, y to the foreground color.
void glcd_setpixel(GLCDX_t x, GLCDY_t y);
// Clears the pixel at coordinates x, y (sets to the background color).
void glcd_clrpixel(GLCDX_t x, GLCDY_t y);
// Returns the color of the pixel at coordinates x, y.
GLCDCOL_t glcd_getpixel(GLCDX_t x, GLCDY_t y);

// Moves the current plot coordinate position to the x, y coordinates.
void glcd_moveto(GLCDX_t x, GLCDY_t y);
// Moves the current plot coordinate position to a new relative position.
void glcd_moverel(GLCDDX_t dx, GLCDDY_t dy);

// Returns the value of the current position x coordinate
#define glcd_getx() glcd_state.cx
// Returns the value of the current position y coordinate
#define glcd_gety() glcd_state.cy

// Selects the current font used for displaying text.
#define glcd_setfont(font_name) {glcd_state.text.font=(flash unsigned char *) font_name;}
// Sets the horizontal and vertical text justification values.
void glcd_settextjustify(unsigned char horiz, unsigned char vert);
// 27102011_3
// Enables/disables displaying transparent text for color displays
#if _GLCD_COLOR_BITS_>1
#define glcd_transparent(on) {glcd_state.text.transparent=((on)!=0);}
#endif

// Returns the width of a character for the current font,
// including the horizontal justification.
unsigned char glcd_charwidth(char c);
// Returns the text height for the current font,
// including the vertical justification.
unsigned char glcd_textheight(void);
// Returns the text width of a char string for the current font,
// including the horizontal justification.
GLCDX_t glcd_textwidth(char *str);
// Returns the text width of a char string located in FLASH for the current
// font, including the horizontal justification.
GLCDX_t glcd_textwidthf(flash char *str);
// Returns the text width of a char string located in EEPROM for the current
// font, including the horizontal justification.
GLCDX_t glcd_textwidthe(eeprom char *str);
// 23012016_1
// Establishes the size of the box needed to display the contents
// of the text char string located in RAM, using the current font
void glcd_boxsize(char *str,GLCDX_t *width,GLCDY_t *height);
// 23012016_1
// Establishes the size of the box needed to display the contents
// of the text char string located in FLASH, using the current font
void glcd_boxsizef(flash char *str,GLCDX_t *width,GLCDY_t *height);
// 23012016_1
// Establishes the size of the box needed to display the contents
// of the text char string located in EEPROM, using the current font
void glcd_boxsizee(eeprom char *str,GLCDX_t *width,GLCDY_t *height);

// Displays an ASCII character at the current x, y position.
void glcd_putchar(char c);
// Displays an ASCII character at the specified x, y coordinates.
void glcd_putcharxy(GLCDX_t x, GLCDY_t y, char c);

// Displays a NULL terminated character string located in RAM
// at the current display position.
void glcd_outtext(char *str);
// Displays a NULL terminated character string located in FLASH
// at the current display position.
void glcd_outtextf(flash char *str);
// Displays a NULL terminated character string located in EEPROM
// at the current display position.
void glcd_outtexte(eeprom char *str);

// Displays a NULL terminated character string located in RAM at the
// specified x, y coordinates.
void glcd_outtextxy(GLCDX_t x, GLCDY_t y, char *str);
// Displays a NULL terminated character string located in FLASH at the
// specified x, y coordinates.
void glcd_outtextxyf(GLCDX_t x, GLCDY_t y, flash char *str);
// Displays a NULL terminated character string located in EEPROM at the
// specified x, y coordinates
void glcd_outtextxye(GLCDX_t x, GLCDY_t y, eeprom char *str);
// 24012016_1
// Displays a NULL terminated character string located in RAM,
// containing multiple lines of text terminated with the '\n'
// character, starting from the specified x, y coordinates.
// The start of the text lines will have an offset of x pixels
// from the left edge of the screen.
void glcd_outtextoffs(GLCDX_t x, GLCDY_t y, char *str);
// 24012016_1
// Displays a NULL terminated character string located in FLASH memory,
// containing multiple lines of text terminated with the '\n'
// character, starting from the specified x, y coordinates.
// The start of the text lines will have an offset of x pixels
// from the left edge of the screen.
void glcd_outtextoffsf(GLCDX_t x, GLCDY_t y, flash char *str);
// 24012016_1
// Displays a NULL terminated character string located in EEPROM,
// containing multiple lines of text terminated with the '\n'
// character, starting from the specified x, y coordinates.
// The start of the text lines will have an offset of x pixels
// from the left edge of the screen.
void glcd_outtextoffse(GLCDX_t x, GLCDY_t y, eeprom char *str);
// 12012016_1
// Displays formatted output at the current display position
int glcd_printf(flash char *fmtstr,...);
// 12012016_1
// Displays formatted output at the specified x, y coordinates
int glcd_printfxy(GLCDX_t x, GLCDY_t y, flash char *fmtstr,...);

// Writes/reads a block of bytes as a bitmap image
// at/from specified coordinates.
void glcd_block(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDMEM_t memt, GLCDMEMADDR_t addr, GLCDBLOCKMODE_t mode);

// Returns the memory size in bytes needed to store a rectangular image.
unsigned long glcd_imagesize(GLCDX_t width, GLCDY_t height);
// Displays an image located in RAM at specified coordinates.
unsigned long glcd_putimage(GLCDX_t left, GLCDY_t top, unsigned char *pimg,
     GLCDBLOCKMODE_t mode);
// Displays an image located in FLASH at specified coordinates.
unsigned long glcd_putimagef(GLCDX_t left, GLCDY_t top, flash unsigned char *pimg,
     GLCDBLOCKMODE_t mode);
// Displays an image located in EEPROM at specified coordinates.
unsigned long glcd_putimagee(GLCDX_t left, GLCDY_t top, eeprom unsigned char *pimg,
     GLCDBLOCKMODE_t mode);
// Displays an image located in external memory at specified coordinates.
unsigned long glcd_putimagex(GLCDX_t left, GLCDY_t top, GLCDMEMADDR_t addr,
     GLCDBLOCKMODE_t mode);
// Saves a rectangular display area to RAM.
unsigned long glcd_getimage(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     unsigned char *pimg);
// Saves a rectangular display area to EEPROM.
unsigned long glcd_getimagee(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     eeprom unsigned char *pimg);
// Saves a rectangular display area to external memory.
unsigned long glcd_getimagex(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDMEMADDR_t addr);

// Set line displaying style.
#define glcd_setlinestyle(thickness,bit_pattern) \
       {glcd_state.line.thick=(thickness), glcd_state.line.pattern=(bit_pattern);}
// Set current line thickness. 02112011_3
#define glcd_setlinethick(thickness) {glcd_state.line.thick=(thickness);}
// Returns current line thickness setting. 02112011_4
#define glcd_getlinethick() glcd_state.line.thick
// Returns current line bit pattern setting.
#define glcd_getlinepattern() glcd_state.line.pattern

// Draws a line with the current color, thickness and bit pattern.
void glcd_line(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1, GLCDY_t y1);
// Draws a line from the current plot coordinate position to a new position
// using the current color, thickness and bit pattern.
void glcd_lineto(GLCDX_t x, GLCDY_t y);
// Draws a line from the current plot coordinate position to a new relative position
// using the current color, thickness and bit pattern.
void glcd_linerel(GLCDDX_t dx, GLCDDY_t dy);

// Draws a rectangle using the current line thickness, bit pattern and drawing color.
void glcd_rectangle(GLCDX_t left, GLCDY_t top, GLCDX_t right, GLCDY_t bottom);
// Draws a rectangle using the current line thickness, bit pattern and drawing color.
void glcd_rectrel(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height);
// Draws a rectangle with rounded corners using the current line thickness
// and drawing color.
void glcd_rectround(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDRAD_t radius);
// Draws a filled rectangle with rounded corners using the current fill color.
void glcd_fillrectround(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height,
     GLCDRAD_t radius);
// Draws a polygon using the current line thickness, bit pattern and drawing color.
void glcd_drawpoly(unsigned char npoints, flash GLCDPOINT_t *polypoints);

// Draws a circle at specified center coordinates using the current
// color and thickness.
void glcd_circle(GLCDX_t x, GLCDY_t y, GLCDRAD_t radius);
// Draws an arc of a circle at specified center coordinates using the current
// color and thickness.
// The angles are measured starting from the 3 o'clock counter-clockwise.
void glcd_arc(GLCDX_t x, GLCDY_t y, unsigned short start_angle,
     unsigned short end_angle, GLCDRAD_t radius);
// Fills in the GLCDARCCOORDS_t structure pointed to by arccoords
// with information about the last call to glcd_arc.
void glcd_getarccoords(GLCDARCCOORDS_t *arccoords);

// Sets an user defined 8x8 pixel fill pattern from RAM and the fill color.
void glcd_setfill(unsigned char *pattern, GLCDCOL_t color);
// Sets an user defined 8x8 pixel fill pattern from FLASH and the fill color.
void glcd_setfillf(flash unsigned char *pattern, GLCDCOL_t color);
// Sets an user defined 8x8 pixel fill pattern from EEPROM and the fill color.
void glcd_setfille(eeprom unsigned char *pattern, GLCDCOL_t color);
// Reads the current 8x8 pixel fill pattern to RAM and the fill color.
void glcd_getfill(unsigned char *pattern, GLCDCOL_t *color);
// Reads the current 8x8 pixel fill pattern to EEPROM and the fill color.
void glcd_getfille(eeprom unsigned char *pattern, GLCDCOL_t *color);

// Draws a filled-in rectangular bar, using absolute coordinates.
// The bar is filled using the current fill pattern and fill color.
// No outline is drawn.
void glcd_bar(GLCDX_t left, GLCDY_t top, GLCDX_t right, GLCDY_t bottom);
// Draws a filled-in rectangular bar, using relative coordinates.
// The bar is filled using the current fill pattern and fill color.
// No outline is drawn.
void glcd_barrel(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height);
// Fills a closed polygon with the current fill color.
void glcd_floodfill(GLCDX_t x, GLCDY_t y, GLCDCOL_t border);
// Draws and fills a circle at specified center coordinates using the current
// fill color.
void glcd_fillcircle(GLCDX_t x, GLCDY_t y, GLCDRAD_t radius);
// Draws a pie slice at specified center coordinates using the
// current foreground color and line thickness.
// After that the pie slice is filled with the current fill color.
// The angles are measured starting from from 3 o'clock counter-clockwise.
void glcd_pieslice(GLCDX_t x, GLCDY_t y, unsigned short start_angle,
     unsigned short end_angle, GLCDRAD_t radius);
// 06022015_3
// Draws a triangle using the current color and line thickness.
void glcd_triangle(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1, GLCDY_t y1, GLCDX_t x2, GLCDY_t y2);
// Draws a filled triangle using the current fill color.
void glcd_filltriangle(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1, GLCDY_t y1, GLCDX_t x2, GLCDY_t y2);
// 10062015_1
// Draws an ellipse at specified center coordinates using the current
// color and line thickness.
void glcd_ellipse(GLCDX_t x, GLCDY_t y, GLCDX_t radiusx, GLCDY_t radiusy); // 09062015_1
// Draws a filled ellipse at specified center coordinates using the current
// fill color.
void glcd_fillellipse(GLCDX_t x, GLCDY_t y, GLCDX_t radiusx, GLCDY_t radiusy); // 09062015_1

#pragma library graphics.lib

#endif
