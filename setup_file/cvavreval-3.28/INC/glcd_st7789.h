//*****************************************************************************
// Library functions for color TFT graphic LCDs with the
// Sitronix ST7789S controller
// (C) 2016 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.26+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00
// 09032016_1 - Initial release.
//*****************************************************************************

#ifndef _GLCD_ST7789_INCLUDED_
#define _GLCD_ST7789_INCLUDED_

#include <glcd_types.h>

// Use fast horizontal & vertical line drawing functions.
#define _GLCD_FAST_LINEH_
#define _GLCD_FAST_LINEV_

// ST7789 commands
#define ST7789_CMD_NOP 0x00 // No operation
#define ST7789_CMD_SOFT_RESET 0x01 // Software reset
#define ST7789_CMD_GET_DISPLAY_ID 0x04 // Get display identification information:
                                       // LCD module manufacturer ID, module/driver version ID,
                                       // module/driver ID
#define ST7789_CMD_GET_DISPLAY_STATUS 0x09 // Get display status
#define ST7789_CMD_GET_PWR_MODE 0x0A // Get the current power mode
#define ST7789_CMD_GET_MADCTL 0x0B // Get the Memory Address Control status bits: MX, MY, MH, MV, ML
#define ST7789_CMD_GET_PIXEL_FORMAT 0x0C // Get the display pixel format
#define ST7789_CMD_GET_DISPLAY_MODE 0x0D // Returns the display image mode status
#define ST7789_CMD_GET_SIGNAL_MODE 0x0E // Get the current display signal mode from the peripheral
#define ST7789_CMD_GET_SELF_DIAGNOSTIC 0x0F // Returns the display self-diagnostic result
#define ST7789_CMD_ENT_SLEEP 0x10 // Enter sleep mode
#define ST7789_CMD_EXIT_SLEEP 0x11 // Exit from sleep mode
#define ST7789_CMD_ENT_PARTIAL_MODE 0x12 // Enter partial display mode
#define ST7789_CMD_ENT_NORMAL_MODE 0x13 // Enter normal display mode
#define ST7789_CMD_EXIT_INVERT_MODE 0x20 // Exit from inverted display mode
#define ST7789_CMD_ENT_INVERT_MODE 0x21 // Enter inverted display mode
#define ST7789_CMD_SET_GAMMA 0x26 // Selects the gamma curve used by the display device
#define ST7789_CMD_BLANK_DISPLAY 0x28 // Set display off, without clearing the frame buffer
#define ST7789_CMD_ON_DISPLAY 0x29 // Set display on
#define ST7789_CMD_SET_COLUMN_ADDR 0x2A // Set the column extent of the frame buffer accessed with the
                                        // ST7789_CMD_RD_MEM_CONT and ST7789_CMD_WR_MEM_CONT commands
#define ST7789_CMD_SET_ROW_ADDR 0x2B // Set the row extent of the frame buffer accessed with the
                                     // ST7789_CMD_RD_MEM_CONT and ST7789_CMD_WR_MEM_CONT commands
#define ST7789_CMD_WR_MEM_START 0x2C // Transfer image information from uC to ST7789 starting with the
                                     // location specified by ST7789_CMD_SET_COLUMN_ADDR and
                                     // ST7789_CMD_SET_ROW_ADDR
#define ST7789_CMD_RD_MEM_START 0x2E // Transfer image information from ST7789 to uC starting with the
                                     // location specified by ST7789_CMD_SET_COLUMN_ADDR and
                                     // ST7789_CMD_SET_ROW_ADDR
#define ST7789_CMD_SET_PARTIAL_AREA 0x30 // Defines the partial display mode area
#define ST7789_CMD_SET_SCROLL_AREA 0x33 // Defines the vertical scrolling and fixed areas
#define ST7789_CMD_SET_TEAR_OFF 0x34 // Disable sending synchronization information from the display
#define ST7789_CMD_SET_TEAR_ON 0x35 // Enable sending synchronization information from the display
#define ST7789_CMD_SET_ADDR_MODE 0x36 // Set read order from uC to frame buffer and
                                      // from frame buffer to the display panel
#define ST7789_CMD_SET_SCROLL_START 0x37 // Set the start of the vertical scrolling area
                                          // in the frame buffer
#define ST7789_CMD_EXIT_IDLE_MODE 0x38 // Exit idle mode
#define ST7789_CMD_ENT_IDLE_MODE 0x39 // Enter idle mode
#define ST7789_CMD_SET_PIXEL_FORMAT 0x3A // Set pixel format
#define ST7789_CMD_WR_MEM_CONT 0x3C // Transfer image data from uC to ST7789 continuing from the
                                    // last ST7789_CMD_WR_MEM_START or ST7789_CMD_WR_MEM_CONT
#define ST7789_CMD_RD_MEM_CONT 0x3E // Transfer image data from ST7789 to uC continuing from the
                                    // last ST7789_CMD_RD_MEM_START or ST7789_CMD_RD_MEM_CONT
#define ST7789_CMD_SET_TEAR_SCANLINE 0x44 // Enable sending the TE signal to the uC when the
                                          // display refresh reaches the provided scan line
#define ST7789_CMD_GET_TEAR_SCANLINE 0x45 // Get the current scan line
#define ST7789_CMD_SET_BRIGHTNESS 0x51 // Set display brightness
#define ST7789_CMD_GET_BRIGHTNESS 0x52 // Get the display brightness
#define ST7789_CMD_SET_CTRL_DISPLAY 0x53 // Set the brightness control block,
                                         // display dimming and backlight
#define ST7789_CMD_GET_CTRL_DISPLAY 0x54 // Get the brightness control block,
                                         // display dimming and backlight status
#define ST7789_CMD_SET_CONTENT_ADAPTIVE_BRIGHTNESS 0x55 // Set the parameters for the content
                                                        // adaptive brightness
#define ST7789_CMD_GET_CONTENT_ADAPTIVE_BRIGHTNESS 0x56 // Get the parameters for the content
                                                        // adaptive brightness
#define ST7789_CMD_SET_CABC_MIN_BRIGHTNESS 0x5E // Set the minimum display brightness for
                                                // the content adaptive brightness function
#define ST7789_CMD_GET_CABC_MIN_BRIGHTNESS 0x5F // Get the minimum display brightness for
                                                // the content adaptive brightness function
#define ST7789_CMD_RAM_CTRL 0xB0 // RAM control
#define ST7789_CMD_RGB_CTRL 0xB1 // RGB control
#define ST7789_CMD_PORCH_CTRL 0xB2 // Porch control
#define ST7789_CMD_FRAME_RATE_CTRL1 0xB3 // Frame rate control 1 in partial/idle mode
#define ST7789_CMD_GATE_CTRL_VGH_VGL 0xB7 // Gate control voltages VGH and VGL
#define ST7789_CMD_DIGITAL_GAMMA_ENABLE 0xBA // Digital gamma enable
#define ST7789_CMD_SET_VCOM 0xBB // Set VCOM
#define ST7789_CMD_LCM_CTRL 0xC0 // LCM control
#define ST7789_CMD_SET_ID 0xC1 // Set ID
#define ST7789_CMD_VDV_VRH_CMD_ENABLE 0xC2 // VDV and VRH command enable
#define ST7789_CMD_SET_VRH 0xC3 // Set VRH
#define ST7789_CMD_SET_VDV 0xC4 // Set VDV
#define ST7789_CMD_SET_VCOM_OFFSET 0xC5 // Set VCOM offset
#define ST7789_CMD_FRAME_RATE_CTRL2 0xC6 // Frame rate control 2 in normal mode
#define ST7789_CMD_CABC_CTRL 0xC7 // CABC control
#define ST7789_CMD_REG_VAL_SEL1 0xC8 // Register value selection 1
#define ST7789_CMD_REG_VAL_SEL2 0xCA // Register value selection 2
#define ST7789_CMD_POWER_CTRL1 0xD0 // Power control 1
#define ST7789_CMD_VAP_VAN_ENABLE 0xD2 // Enable VAP/VAN signal output
#define ST7789_CMD_GET_ID1 0xDA // Get the LCD manufacturer ID
#define ST7789_CMD_GET_ID2 0xDB // Get the LCD module/driver IC version
#define ST7789_CMD_GET_ID3 0xDC // Get the LCD module/driver ID
#define ST7789_CMD_SET_POSITIVE_GAMMA_CTRL 0xE0 // Set positive gamma correction control parameters
#define ST7789_CMD_SET_NEGATIVE_GAMMA_CTRL 0xE1 // Set negative gamma correction control parameters
#define ST7789_CMD_SET_DIGITAL_GAMMA_LOOK_UP_RED 0xE2 // Set digital gamma look-up table for red color
#define ST7789_CMD_SET_DIGITAL_GAMMA_LOOK_UP_BLUE 0xE3 // Set digital gamma look-up table for blue color
#define ST7789_CMD_GATE_CTRL 0xE4 // Gate control
#define ST7789_CMD_POWER_CTRL2 0xE8 // Power control 2
#define ST7789_CMD_EQ_TIME_CTRL 0xE9 // Equalize time control
#define ST7789_CMD_PGM_CTRL 0xEC // Program control
#define ST7789_CMD_PGM_MODE_ENABLE 0xFA // Program mode enable
#define ST7789_CMD_NVM_SET 0xFC // NVM setting
#define ST7789_CMD_PGM_ACTION 0xFE // Program action

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
        unsigned char vgl:3; // set VGL (see the datasheet)
        unsigned char vgh:3; // set VGH (see the datasheet)
        unsigned char vrh:6; // set VRH (see the datasheet)
        unsigned char vdv:6; // set VDV (see the datasheet)
        unsigned char vcom:6; // set VCOM (see the datasheet)
        unsigned char frame_rate:5; // set vertical frame rate 39..119Hz
        } GLCDINIT_t;

// Initialization values for reverse_x
#define ST7789_REVX_NORM 0 // No horizontal reverse
#define ST7789_REVX_REV 1 // Horizontal reverse

// Initialization values for reverse_y
#define ST7789_REVY_NORM 0 // No vertical reverse
#define ST7789_REVY_REV 1 // Vertical reverse

// Initialization values for cl_bits_order
#define ST7789_CL_BITS_RGB 0 // RGB
#define ST7789_CL_BITS_BGR 1 // BGR

// Initialization values for frame_rate
#define ST7789_FRAME_RATE_39 0x1F // 39Hz
#define ST7789_FRAME_RATE_40 0x1E // 40Hz
#define ST7789_FRAME_RATE_41 0x1D // 41Hz
#define ST7789_FRAME_RATE_42 0x1C // 42Hz
#define ST7789_FRAME_RATE_43 0x1B // 43Hz
#define ST7789_FRAME_RATE_44 0x1A // 44Hz
#define ST7789_FRAME_RATE_45 0x19 // 45Hz
#define ST7789_FRAME_RATE_46 0x18 // 46Hz
#define ST7789_FRAME_RATE_48 0x17 // 48Hz
#define ST7789_FRAME_RATE_49 0x16 // 49Hz
#define ST7789_FRAME_RATE_50 0x15 // 50Hz
#define ST7789_FRAME_RATE_52 0x14 // 52Hz
#define ST7789_FRAME_RATE_53 0x13 // 53Hz
#define ST7789_FRAME_RATE_55 0x12 // 55Hz
#define ST7789_FRAME_RATE_57 0x11 // 57Hz
#define ST7789_FRAME_RATE_58 0x10 // 58Hz
#define ST7789_FRAME_RATE_60 0x0F // 60Hz
#define ST7789_FRAME_RATE_62 0x0E // 62Hz
#define ST7789_FRAME_RATE_64 0x0D // 64Hz
#define ST7789_FRAME_RATE_67 0x0C // 67Hz
#define ST7789_FRAME_RATE_69 0x0B // 69Hz
#define ST7789_FRAME_RATE_72 0x0A // 72Hz
#define ST7789_FRAME_RATE_75 0x09 // 75Hz
#define ST7789_FRAME_RATE_78 0x08 // 78Hz
#define ST7789_FRAME_RATE_82 0x07 // 82Hz
#define ST7789_FRAME_RATE_86 0x06 // 86Hz
#define ST7789_FRAME_RATE_90 0x05 // 90Hz
#define ST7789_FRAME_RATE_94 0x04 // 94Hz
#define ST7789_FRAME_RATE_99 0x03 // 99Hz
#define ST7789_FRAME_RATE_105 0x02 // 105Hz
#define ST7789_FRAME_RATE_111 0x01 // 111Hz
#define ST7789_FRAME_RATE_119 0x00 // 119Hz

// Default initialization values for GLCDINIT_t
// Default value for reverse_x
#define ST7789_DEFAULT_REVX ST7789_REVX_NORM // No horizontal reverse
// Default value for reverse_y
#define ST7789_DEFAULT_REVY ST7789_REVY_NORM // No vertical reverse
// Default value for cl_bits_order
#define ST7789_DEFAULT_CL_BITS ST7789_CL_BITS_RGB // write in RGB order
// Default value for vgl
#define ST7789_DEFAULT_VGL 0x05 // -10.43V
// Default value for vgh
#define ST7789_DEFAULT_VGH 0x03 // 13.26V
// Default value for vrh
#define ST7789_DEFAULT_VRH 0x11
// Default value for vdv
#define ST7789_DEFAULT_VDV 0x20
// Default value for vcom
#define ST7789_DEFAULT_VCOM 0x2B // 1.175V
// Default value for frame_rate
#define ST7789_DEFAULT_FRAME_RATE ST7789_FRAME_RATE_60 // 60Hz

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

// Writes a command to the ST7789 controller.
void st7789_wrcmd(unsigned char cmd);
// Writes a command data byte to the ST7789 controller.
void st7789_wrdata(unsigned char data);
// Reads a command result data byte from the ST7789 controller.
unsigned char st7789_rddata(void);
// Writes a color data for 1 pixel to the ST7789 controller's display RAM.
void st7789_wrdram(GLCDCOL_t color);
// Reads color data for 1 pixel from the ST7789 controller's display RAM.
GLCDCOL_t st7789_rddram(void);
// Puts/exits the ST7789 controller to/from sleep mode.
void st7789_sleep(bool on);

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

#pragma library glcd_st7789.lib

#endif




