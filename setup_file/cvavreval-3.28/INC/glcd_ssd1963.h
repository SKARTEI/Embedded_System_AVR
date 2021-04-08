//*****************************************************************************
// Library functions for color TFT graphic LCDs with the
// Solomon Systech SSD1963 controller
// (C) 2010-2013 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.07+
// Version: 1.05
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00
// 14022012_1 - Initial release.
//
// V1.01
// 01042012_1 - Improved the speed of the glcd_clear function for 16 bit
//              interface
// 02042012_1 - Added fast horizontal & vertical line drawing functions.
// 02042012_2 - Added the "cl_bits_order" member to the GLCDINIT_t structure
//
// V1.02
// 24012013_1 - Corrected the ssd1963_setwindow function for 8bit
//              GLCDX_t or GLCDY_t (for displays with horizontal or
//              vertical resolutions lower than 256 pixels)
//
// V1.03
// 27032013_1 - Corrected the glcd_block function not working correctly in
//              transparent modes: GLCD_PUTTP and GLCD_PUTCHAR
// 28032013_1 - Added the "lshift" member to the GLCDINIT_t structure
//
// V1.04
// 26062013_1 - Improved write timing for compatibility with some displays
//
// V1.05
// 11092013_1 - Improved code size
// 12092013_1 - Updated the default initilaization values for 7" 800x480
//              display
//*****************************************************************************

#ifndef _GLCD_SSD1963_INCLUDED_
#define _GLCD_SSD1963_INCLUDED_

#include <glcd_types.h>

// 02042012_1
// Use fast horizontal & vertical line drawing functions.
#define _GLCD_FAST_LINEH_
#define _GLCD_FAST_LINEV_

// SSD1963 commands
#define SSD1963_CMD_NOP 0x00 // No operation
#define SSD1963_CMD_SOFT_RESET 0x01 // Software reset
#define SSD1963_CMD_GET_PWR_MODE 0x0A // Get the current power mode
#define SSD1963_CMD_GET_ADDR_MODE 0x0B // Get the frame buffer to the display panel read order
#define SSD1963_CMD_GET_DISPLAY_MODE 0x0D // Returns the display image mode status
#define SSD1963_CMD_GET_SIGNAL_MODE 0x0E // Get the current display signal mode from the peripheral
#define SSD1963_CMD_ENT_SLEEP 0x10 // Enter sleep mode
#define SSD1963_CMD_EXIT_SLEEP 0x11 // Exit from sleep mode
#define SSD1963_CMD_ENT_PARTIAL_MODE 0x12 // Enter partial display mode
#define SSD1963_CMD_ENT_NORMAL_MODE 0x13 // Enter normal display mode
#define SSD1963_CMD_EXIT_INVERT_MODE 0x20 // Exit from inverted display mode
#define SSD1963_CMD_ENT_INVERT_MODE 0x21 // Enter inverted display mode
#define SSD1963_CMD_SET_GAMMA 0x26 // Selects the gamma curve used by the display device
#define SSD1963_CMD_BLANK_DISPLAY 0x28 // Set display off, without clearing the frame buffer
#define SSD1963_CMD_ON_DISPLAY 0x29 // Set display on
#define SSD1963_CMD_SET_COLUMN_ADDR 0x2A // Set the column extent of the frame buffer accessed with the
                                         // SSD1963_CMD_RD_MEM_CONT and SSD1963_CMD_WR_MEM_CONT commands
#define SSD1963_CMD_SET_PAGE_ADDR 0x2B // Set the page extent of the frame buffer accessed with the
                                       // SSD1963_CMD_RD_MEM_CONT and SSD1963_CMD_WR_MEM_CONT commands
#define SSD1963_CMD_WR_MEM_START 0x2C // Transfer image information from uC to SSD1963 starting with the
                                      // location specified by SSD1963_CMD_SET_COLUMN_ADDR and
                                      // SSD1963_CMD_SET_PAGE_ADDR
#define SSD1963_CMD_RD_MEM_START 0x2E // Transfer image information from SSD1963 to uC starting with the
                                      // location specified by SSD1963_CMD_SET_COLUMN_ADDR and
                                      // SSD1963_CMD_SET_PAGE_ADDR
#define SSD1963_CMD_SET_PARTIAL_AREA 0x30 // Defines the partial display mode area
#define SSD1963_CMD_SET_SCROLL_AREA 0x33 // Defines the vertical scrolling and fixed areas
#define SSD1963_CMD_SET_TEAR_OFF 0x34 // Disable sending synchronization information from the display
#define SSD1963_CMD_SET_TEAR_ON 0x35 // Enable sending synchronization information from the display
#define SSD1963_CMD_SET_ADDR_MODE 0x36 // Set read order from uC to frame buffer and
                                       // from frame buffer to the display panel
#define SSD1963_CMD_SET_SCROLL_START 0x37 // Set the start of the vertical scrolling area
                                          // in the frame buffer
#define SSD1963_CMD_EXIT_IDLE_MODE 0x38 // Exit idle mode
#define SSD1963_CMD_ENT_IDLE_MODE 0x39 // Enter idle mode
#define SSD1963_CMD_SET_PIXEL_FORMAT 0x3A // Set pixel format:
#define SSD1963_PIXEL_3BIT 0x10 // 3-bit/pixel
#define SSD1963_PIXEL_8BIT 0x20 // 8-bit/pixel
#define SSD1963_PIXEL_12BIT 0x30 // 12-bit/pixel
#define SSD1963_PIXEL_16BIT 0x50 // 16-bit/pixel
#define SSD1963_PIXEL_18BIT 0x60 // 18-bit/pixel
#define SSD1963_PIXEL_24BIT 0x70 // 24-bit/pixel

#define SSD1963_CMD_WR_MEM_CONT 0x3C // Transfer image data from uC to SSD1963 continuing from the
                                     // last SSD1963_CMD_WR_MEM_START or SSD1963_CMD_WR_MEM_CONT
#define SSD1963_CMD_RD_MEM_CONT 0x3E // Transfer image data from SSD1963 to uC continuing from the
                                     // last SSD1963_CMD_RD_MEM_START or SSD1963_CMD_RD_MEM_CONT
#define SSD1963_CMD_SET_TEAR_SCANLINE 0x44 // Enable sending the TE signal to the uC when the
                                           // display refresh reaches the provided scanline
#define SSD1963_CMD_GET_TEAR_SCANLINE 0x45 // Get the current scanline
#define SSD1963_CMD_RD_DDB 0xA1 // Read the Device Descriptor Block of SSD1963:
#define SSD1963_SUPPLIER_ID 0x5701 // Solomon Systech supplier ID
#define SSD1963_PRODUCT_ID 0x61 // SSD1963 product ID
#define SSD1963_REVISION 0x01 // SSD1963 min. revision

#define SSD1963_CMD_SET_LCD_MODE 0xB0 // Set LCD panel mode and resolution
#define SSD1963_CMD_GET_LCD_MODE 0xB1 // Get LCD panel mode and resolution
#define SSD1963_CMD_SET_HOR_PERIOD 0xB4 // Set front porch settings
#define SSD1963_CMD_GET_HOR_PERIOD 0xB5 // Get front porch settings
#define SSD1963_CMD_SET_VER_PERIOD 0xB6 // Set the vert. blanking interval between last scan line
                                        // and next LFRAME pulse
#define SSD1963_CMD_GET_VER_PERIOD 0xB7 // Get the vert. blanking interval between last scan line
                                        // and next LFRAME pulse
#define SSD1963_CMD_SET_GPIO_CONF 0xB8  // Set GPIO configuration
#define SSD1963_CMD_GET_GPIO_CONF 0xB9  // Get GPIO configuration
#define SSD1963_CMD_SET_GPIO_VAL 0xBA // Write data to the GPIOs configured as outputs
#define SSD1963_CMD_GET_GPIO_STATUS 0xBB // Read data from the GPIOs configured as inputs
#define SSD1963_CMD_SET_POST_PROC 0xBC // Set the image post processor
#define SSD1963_CMD_GET_POST_PROC 0xBD // Get the image post processor
#define SSD1963_CMD_SET_PWM_CONF 0xBE // Set PWM configuration
#define SSD1963_CMD_GET_PWM_CONF 0xBF // Get PWM configuration
#define SSD1963_CMD_SET_LCD_GEN0 0xC0 // Set the rise, fall, period and toggling properties
                                      // of LCD signal generator 0
#define SSD1963_CMD_GET_LCD_GEN0 0xC1 // Get the rise, fall, period and toggling properties
                                      // of LCD signal generator 0
#define SSD1963_CMD_SET_LCD_GEN1 0xC2 // Set the rise, fall, period and toggling properties
                                      // of LCD signal generator 1
#define SSD1963_CMD_GET_LCD_GEN1 0xC3 // Get the rise, fall, period and toggling properties
                                      // of LCD signal generator 1
#define SSD1963_CMD_SET_LCD_GEN2 0xC4 // Set the rise, fall, period and toggling properties
                                      // of LCD signal generator 2
#define SSD1963_CMD_GET_LCD_GEN2 0xC5 // Get the rise, fall, period and toggling properties
                                      // of LCD signal generator 2
#define SSD1963_CMD_SET_LCD_GEN3 0xC6 // Set the rise, fall, period and toggling properties
                                      // of LCD signal generator 3
#define SSD1963_CMD_GET_LCD_GEN3 0xC7 // Get the rise, fall, period and toggling properties
                                      // of LCD signal generator 3
#define SSD1963_CMD_SET_GPIO0_ROP 0xC8 // Set GPIO0 with respect to LCD signal generators using
                                       // ROP3 operation
#define SSD1963_CMD_GET_GPIO0_ROP 0xC9 // Get GPIO0 properties with respect to LCD signal generators
#define SSD1963_CMD_SET_GPIO1_ROP 0xCA // Set GPIO1 with respect to LCD signal generators using
                                       // ROP3 operation
#define SSD1963_CMD_GET_GPIO1_ROP 0xCB // Get GPIO1 properties with respect to LCD signal generators
#define SSD1963_CMD_SET_GPIO2_ROP 0xCC // Set GPIO2 with respect to LCD signal generators using
                                       // ROP3 operation
#define SSD1963_CMD_GET_GPIO2_ROP 0xCD // Get GPIO2 properties with respect to LCD signal generators
#define SSD1963_CMD_SET_GPIO3_ROP 0xCE // Set GPIO3 with respect to LCD signal generators using
                                       // ROP3 operation
#define SSD1963_CMD_GET_GPIO3_ROP 0xCF // Get GPIO3 properties with respect to LCD signal generators
#define SSD1963_CMD_SET_DBC_CONF 0xD0 // Set Dynamic Backlight Control configuration
#define SSD1963_CMD_GET_DBC_CONF 0xD1 // Get Dynamic Backlight Control configuration
#define SSD1963_CMD_SET_DBC_THRES 0xD4 // Set the threshold for each level of power saving
#define SSD1963_CMD_GET_DBC_THRES 0xD5 // Get the threshold for each level of power saving
#define SSD1963_CMD_SET_PLL 0xE0 // Start the PLL
#define SSD1963_CMD_SET_PLL_MN 0xE2 // Set the PLL divider (M) and multiplier (N)
#define SSD1963_CMD_GET_PLL_MN 0xE3 // Get the PLL divider (M) and multiplier (N)
#define SSD1963_CMD_GET_PLL_STATUS 0xE4	// Get the current PLL status
#define SSD1963_CMD_DEEP_SLEEP 0xE5 // Set deep sleep mode, PLL will be stopped
#define SSD1963_CMD_SET_PCLK 0xE6	// Set pixel clock (LSHIFT signal) frequency
#define SSD1963_CMD_GET_PCLK 0xE7	// Get pixel clock (LSHIFT signal) frequency settings
#define SSD1963_CMD_SET_PDATA_INTERFACE 0xF0 // Set the pixel data format used for parallel
                                             // mode communication with the uC:
#define SSD1963_PIXEL_DATA_8BIT 0 // 8-bit
#define SSD1963_PIXEL_DATA_9BIT 6 // 9-bit
#define SSD1963_PIXEL_DATA_12BIT 1 // 12-bit
#define SSD1963_PIXEL_DATA_16BIT 2 // 16-bit packed
#define SSD1963_PIXEL_DATA_16BIT565 3 // 16-bit 565 format
#define SSD1963_PIXEL_DATA_18BIT 4 // 18-bit
#define SSD1963_PIXEL_DATA_24BIT 5 // 24-bit

#define SSD1963_CMD_GET_PDATA_INTERFACE 0xF1 // Get the pixel data format used for parallel
                                             // mode communication with the uC

#define SSD1963_PLL_FREQ 100 // SSD1963 PLL frequency [MHz]

// Structure that contains controller specific graphic LCD initialization data
typedef struct
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr);
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned short ctrl_clk; // SSD1963 controller external clock (crystal)
                                 // frequency [kHz]
        unsigned short tft_pixel_clk; // TFT pixel clock frequency [kHz]
        unsigned char hpulse_width; // TFT panel horizontal pulse width [pixel clock cycles]
        unsigned char hfront_porch; // TFT panel horizontal front porch width [pixel clock cycles]
        unsigned char hback_porch; // TFT panel horizontal back porch width [pixel clock cycles]
        unsigned char vpulse_width; // TFT panel vertical pulse width [line cycles]
        unsigned char vfront_porch; // TFT panel vertical front porch width [line cycles]
        unsigned char vback_porch; // TFT panel vertical back porch width [line cycles]

        unsigned char tft24bit:1; // specify TFT panel data width
                                  // =0 - 18bit, =1 - 24bit
        unsigned char lshift:1;   // specify the dot clock pulse polarity, 28032013_1
                                  // =0 - data latch on falling edge
                                  // =1 - data latch on rising edge
        unsigned char reverse_x:1; // reverse display horizontally
        unsigned char reverse_y:1; // reverse display vertically
        // 02042012_2
        unsigned char cl_bits_order:1; // selects the color bits writing order to the display RAM
                                       // =0 -> RGB, =1 ->BGR
        } GLCDINIT_t;

// Initialization values for tft24bit
#define SSD1963_TFT_DATA_WIDTH18 0 // TFT panel data width 18 bit
#define SSD1963_TFT_DATA_WIDTH24 1 // TFT panel data width 24 bit

// 28032013_1
// Initialization values for lshift
#define SSD1963_LSHIFT_LATCH_FALLING_EDGE 0 // data latch on falling edge
#define SSD1963_LSHIFT_LATCH_RISING_EDGE 1  // data latch on rising edge

// Initialization values for reverse_x
#define SSD1963_REVX_NORM 0 // No horizontal reverse
#define SSD1963_REVX_REV 1 // Horizontal reverse

// Initialization values for reverse_y
#define SSD1963_REVY_NORM 0 // No vertical reverse
#define SSD1963_REVY_REV 1 // Vertical reverse

// 02042012_2
// Initialization values for cl_bits_order
#define SSD1963_CL_BITS_RGB 0 // Write color bits to display RAM in RGB order
#define SSD1963_CL_BITS_BGR 1 // Write color bits to display RAM in BGR order

// Default initialization values for GLCDINIT_t
#define SSD1963_DEFAULT_CTRL_CLK 10000 // external clock frequency [kHz]

#if ((_GLCD_MAXX_==320) && (_GLCD_MAXY_==240))
// 3.5" 320x240 display
// TFT LCD pixel clock frequency [kHz]
#define SSD1963_DEFAULT_TFT_PIXEL_CLK_FREQ 7000 // 24012013_2

#define SSD1963_DEFAULT_TFT_HOR_PULSE_WIDTH 20
#define SSD1963_DEFAULT_TFT_HOR_FRONT_PORCH 20
#define SSD1963_DEFAULT_TFT_HOR_BACK_PORCH 51 // 24012013_2

#define SSD1963_DEFAULT_TFT_VER_PULSE_WIDTH 2
#define SSD1963_DEFAULT_TFT_VER_FRONT_PORCH 4
#define SSD1963_DEFAULT_TFT_VER_BACK_PORCH 16

// default tft24bit to 18 bit TFT
#define SSD1963_DEFAULT_TFT_DATA_WIDTH SSD1963_TFT_DATA_WIDTH18

#elif ((_GLCD_MAXX_==480) && (_GLCD_MAXY_==272))
// 4.3" 480x272 display
// TFT LCD pixel clock frequency [kHz]
#define SSD1963_DEFAULT_TFT_PIXEL_CLK_FREQ 9000

#define SSD1963_DEFAULT_TFT_HOR_PULSE_WIDTH 41
#define SSD1963_DEFAULT_TFT_HOR_FRONT_PORCH 2
#define SSD1963_DEFAULT_TFT_HOR_BACK_PORCH 2

#define SSD1963_DEFAULT_TFT_VER_PULSE_WIDTH 10
#define SSD1963_DEFAULT_TFT_VER_FRONT_PORCH 2
#define SSD1963_DEFAULT_TFT_VER_BACK_PORCH 2

// default tft24bit to 18 bit TFT
#define SSD1963_DEFAULT_TFT_DATA_WIDTH SSD1963_TFT_DATA_WIDTH18

#elif ((_GLCD_MAXX_==800) && (_GLCD_MAXY_==480))
// 7" 800x480 display
// TFT LCD pixel clock frequency [kHz]
#define SSD1963_DEFAULT_TFT_PIXEL_CLK_FREQ 33300 // 12092013_1

#define SSD1963_DEFAULT_TFT_HOR_PULSE_WIDTH 40 // 12092013_1
#define SSD1963_DEFAULT_TFT_HOR_FRONT_PORCH 82 // 12092013_1
#define SSD1963_DEFAULT_TFT_HOR_BACK_PORCH 7 // 12092013_1

#define SSD1963_DEFAULT_TFT_VER_PULSE_WIDTH 17 // 12092013_1
#define SSD1963_DEFAULT_TFT_VER_FRONT_PORCH 29 // 12092013_1
#define SSD1963_DEFAULT_TFT_VER_BACK_PORCH 22 // 12092013_1

// default tft24bit to 18 bit TFT
#define SSD1963_DEFAULT_TFT_DATA_WIDTH SSD1963_TFT_DATA_WIDTH18 // 12092013_1
#endif

// Default value for lshift, 28032013_1
#define SSD1963_DEFAULT_LSHIFT SSD1963_LSHIFT_LATCH_FALLING_EDGE
// Default value for reverse_x
#define SSD1963_DEFAULT_REVX SSD1963_REVX_NORM // No horizontal reverse
// Default value for reverse_y
#define SSD1963_DEFAULT_REVY SSD1963_REVY_NORM // No vertical reverse
// 02042012_2
// Default value for cl_bits_order
#define SSD1963_DEFAULT_CL_BITS SSD1963_CL_BITS_RGB // write in RGB order

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

// Writes a command to the SSD1963 controller.
void ssd1963_wrcmd(unsigned char cmd);
// Writes a command data byte to the SSD1963 controller.
void ssd1963_wrdata(unsigned char data);
// Reads a command result data byte from the SSD1963 controller.
unsigned char ssd1963_rddata(void);
// Writes a color data for 1 pixel to the SSD1963 controller's display RAM.
void ssd1963_wrdram(GLCDCOL_t color);
// Reads color data for 1 pixel from the SSD1963 controller's display RAM.
GLCDCOL_t ssd1963_rddram(void);
// Puts/exits the SSD1963 controller to/from sleep mode.
void ssd1963_sleep(bool on);

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

// 02042012_1
// Fast draw a horizontal line from (x0,y0) to (x1,y0).
void glcd_lineh(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1);
// Fast draw a vertical line from (x0,y0) to (x0,y1).
void glcd_linev(GLCDX_t x0, GLCDY_t y0, GLCDY_t y1);

#pragma library glcd_ssd1963.lib

#endif




