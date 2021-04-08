//*****************************************************************************
// Library functions for color TFT graphic LCDs with the
// RAiO Technology RA8875 controller
// (C) 2010-2015 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.22+
// Version: 1.02
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00
// 07012015_1 - Initial release.
//
// V1.01
// 04032015_1 - Added support for 480x272 displays.
//
// V1.02
// 09062015_1 - Corrected radiusx, radiusy parameter names for the
//              glcd_ellipse and glcd_fillellipse functions.
//*****************************************************************************

#ifndef _GLCD_RA8875_INCLUDED_
#define _GLCD_RA8875_INCLUDED_

#include <glcd_types.h>

// Use hardware line drawing functions
#define _GLCD_HW_LINE_
// Use hardware triangle drawing functions
#define _GLCD_HW_TRIANGLE_
#define _GLCD_HW_TRIANGLE_FILLED_
// Use hardware rectangle drawing functions
#define _GLCD_HW_RECT_
#define _GLCD_HW_RECT_FILLED_
#define _GLCD_HW_RECT_ROUNDED_
#define _GLCD_HW_RECT_ROUNDED_FILLED_
// Use hardware circle drawing functions
#define _GLCD_HW_CIRCLE_
#define _GLCD_HW_CIRCLE_FILLED_
// Use hardware ellipse drawing functions
#define _GLCD_HW_ELLIPSE_
#define _GLCD_HW_ELLIPSE_FILLED_

// RA8875 registers
#define RA8875_STSR 0x00      // Status Register
#define RA8875_PWRR 0x01      // Power and Display Control Register
#define RA8875_MRWC 0x02      // Memory Read/Write Command
#define RA8875_PCSR 0x04      // Pixel Clock Setting Register
#define RA8875_SROC 0x05      // Serial Flash/ROM Configuration Register
#define RA8875_SFCLR 0x06     // Serial Flash/ROM CLK Setting Register
#define RA8875_SYSR 0x10      // System Configuration Register
#define RA8875_GPI 0x12       // General Purpose Input
#define RA8875_GPO 0x13       // General Purpose Output
#define RA8875_HDWR 0x14      // LCD Horizontal Display Width Register
#define RA8875_HNDFTR 0x15    // Horizontal Non-Display Period Fine Tuning Option Register
#define RA8875_HNDR 0x16      // LCD Horizontal Non-Display Period Register
#define RA8875_HSTR 0x17      // HSYNC Start Position Register
#define RA8875_HPWR 0x18      // HSYNC Pulse Width Register
#define RA8875_VDHR0 0x19     // LCD Vertical Display Height Register 0
#define RA8875_VDHR1 0x1A     // LCD Vertical Display Height Register 1
#define RA8875_VNDR0 0x1B     // LCD Vertical Non-Display Period Register 0
#define RA8875_VNDR1 0x1C     // LCD Vertical Non-Display Period Register 1
#define RA8875_VSTR0 0x1D     // VSYNC Start Position Register 0
#define RA8875_VSTR1 0x1E     // VSYNC Start Position Register 1
#define RA8875_VPWR 0x1F      // VSYNC Pulse Width Register
#define RA8875_DPCR 0x20      // Display Configuration Register
#define RA8875_FNCR0 0x21     // Font Control Register 0
#define RA8875_FNCR1 0x22     // Font Control Register 1
#define RA8875_CGSR 0x23      // CGRAM Select Register
#define RA8875_HOFS0 0x24     // Horizontal Scroll Offset Register 0
#define RA8875_HOFS1 0x25     // Horizontal Scroll Offset Register 1
#define RA8875_VOFS0 0x26     // Vertical Scroll Offset Register 0
#define RA8875_VOFS1 0x27     // Vertical Scroll Offset Register 1
#define RA8875_FLDR 0x29      // Font Line Distance Setting Register
#define RA8875_F_CURXL 0x2A   // Font Write Cursor Horizontal Position Register 0
#define RA8875_F_CURXH 0x2B   // Font Write Cursor Horizontal Position Register 1
#define RA8875_F_CURYL 0x2C   // Font Write Cursor Vertical Position Register 0
#define RA8875_F_CURYH 0x2D   // Font Write Cursor Vertical Position Register 1
#define RA8875_FWTSR 0x2E     // Font Write Type Setting Register
#define RA8875_SFRS 0x2F      // Serial Font ROM Setting
#define RA8875_HSAW0 0x30     // Horizontal Start Point 0 of Active Window
#define RA8875_HSAW1 0x31     // Horizontal Start Point 1 of Active Window
#define RA8875_VSAW0 0x32     // Vertical Start Point 0 of Active Window
#define RA8875_VSAW1 0x33     // Vertical Start Point 1 of Active Window
#define RA8875_HEAW0 0x34     // Horizontal End Point 0 of Active Window
#define RA8875_HEAW1 0x35     // Horizontal End Point 1 of Active Window
#define RA8875_VEAW0 0x36     // Vertical End Point 0 of Active Window
#define RA8875_VEAW1 0x37     // Vertical End Point 1 of Active Window
#define RA8875_HSSW0 0x38     // Horizontal Start Point 0 of Scroll Window
#define RA8875_HSSW1 0x39     // Horizontal Start Point 1 of Scroll Window
#define RA8875_VSSW0 0x3A     // Vertical Start Point 0 of Scroll Window
#define RA8875_VSSW1 0x3B     // Vertical Start Point 1 of Scroll Window
#define RA8875_HESW0 0x3C     // Horizontal End Point 0 of Scroll Window
#define RA8875_HESW1 0x3D     // Horizontal End Point 1 of Scroll Window
#define RA8875_VESW0 0x3E     // Vertical End Point 0 of Scroll Window
#define RA8875_VESW1 0x3F     // Vertical End Point 1 of Scroll Window
#define RA8875_MWCR0 0x40     // Memory Write Control Register 0
#define RA8875_MWCR1 0x41     // Memory Write Control Register 1
#define RA8875_BTCR 0x44      // Blink Time Control Register
#define RA8875_MRCD 0x45      // Memory Read Cursor Direction
#define RA8875_CURH0 0x46     // Memory Write Cursor Horizontal Position Register 0
#define RA8875_CURH1 0x47     // Memory Write Cursor Horizontal Position Register 1
#define RA8875_CURV0 0x48     // Memory Write Cursor Vertical Position Register 0
#define RA8875_CURV1 0x49     // Memory Write Cursor Vertical Position Register 1
#define RA8875_RCURH0 0x4A    // Memory Read Cursor Horizontal Position Register 0
#define RA8875_RCURH1 0x4B    // Memory Read Cursor Horizontal Position Register 1
#define RA8875_RCURV0 0x4C    // Memory Read Cursor Vertical Position Register 0
#define RA8875_RCURV1 0x4D    // Memory Read Cursor Vertical Position Register 1
#define RA8875_CURHS 0x4E     // Font Write Cursor and Memory Write Cursor Horizontal Size Register
#define RA8875_CURVS 0x4F     // Font Write Cursor Vertical Size Register
#define RA8875_BECR0 0x50     // BTE Function Control Register 0
#define RA8875_BECR1 0x51     // BTE Function Control Register 1
#define RA8875_LTPR0 0x52     // Layer Transparency Register 0
#define RA8875_LTPR1 0x53     // Layer Transparency Register 1
#define RA8875_HSBE0 0x54     // Horizontal Source Point 0 of BTE
#define RA8875_HSBE1 0x55     // Horizontal Source Point 1 of BTE
#define RA8875_VSBE0 0x56     // Vertical Source Point 0 of BTE
#define RA8875_VSBE1 0x57     // Vertical Source Point 1 of BTE
#define RA8875_HDBE0 0x58     // Horizontal Destination Point 0 of BTE
#define RA8875_HDBE1 0x59     // Horizontal Destination Point 1 of BTE
#define RA8875_VDBE0 0x5A     // Vertical Destination Point 0 of BTE
#define RA8875_VDBE1 0x5B     // Vertical Destination Point 1 of BTE
#define RA8875_BEWR0 0x5C     // BTE Width Register 0
#define RA8875_BEWR1 0x5D     // BTE Width Register 1
#define RA8875_BEHR0 0x5E     // BTE Height Register 0
#define RA8875_BEHR1 0x5F     // BTE Height Register 1
#define RA8875_BGCR0 0x60     // Background Color Register 0
#define RA8875_BGCR1 0x61     // Background Color Register 1
#define RA8875_BGCR2 0x62     // Background Color Register 2
#define RA8875_FGCR0 0x63     // Foreground Color Register 0
#define RA8875_FGCR1 0x64     // Foreground Color Register 1
#define RA8875_FGCR2 0x65     // Foreground Color Register 2
#define RA8875_PTNO 0x66      // Pattern Set No for BTE
#define RA8875_BGTR0 0x67     // Background Color Register for Transparent 0
#define RA8875_BGTR1 0x68     // Background Color Register for Transparent 1
#define RA8875_BGTR2 0x69     // Background Color Register for Transparent 2
#define RA8875_TPCR0 0x70     // Touch Panel Control Register 0
#define RA8875_TPCR1 0x71     // Touch Panel Control Register 1
#define RA8875_TPXH 0x72      // Touch Panel X High Byte Data Register
#define RA8875_TPYH 0x73      // Touch Panel Y High Byte Data Register
#define RA8875_TPXYL 0x74     // Touch Panel X/Y Low Byte Data Register
#define RA8875_GCHP0 0x80     // Graphic Cursor Horizontal Position Register 0
#define RA8875_GCHP1 0x81     // Graphic Cursor Horizontal Position Register 1
#define RA8875_GCVP0 0x82     // Graphic Cursor Vertical Position Register 0
#define RA8875_GCVP1 0x83     // Graphic Cursor Vertical Position Register 1
#define RA8875_GCC0 0x84      // Graphic Cursor Color 0
#define RA8875_GCC1 0x85      // Graphic Cursor Color 1
#define RA8875_PLLC1 0x88     // PLL Control Register 1
#define RA8875_PLLC2 0x89     // PLL Control Register 2
#define RA8875_P1CR 0x8A      // PWM1 Control Register
#define RA8875_P1DCR 0x8B     // PWM1 Duty Cycle Register
#define RA8875_P2CR 0x8C      // PWM2 Control Register
#define RA8875_P2DCR 0x8D     // PWM2 Duty Cycle Register
#define RA8875_MCLR 0x8E      // Memory Clear Control Register
#define RA8875_DCR 0x90       // Draw Line/Circle/Square Control Register
#define RA8875_DLHSR0 0x91    // Draw Line/Square Horizontal Start Address Register 0
#define RA8875_DLHSR1 0x92    // Draw Line/Square Horizontal Start Address Register 1
#define RA8875_DLVSR0 0x93    // Draw Line/Square Vertical Start Address Register 0
#define RA8875_DLVSR1 0x94    // Draw Line/Square Vertical Start Address Register 1
#define RA8875_DLHER0 0x95    // Draw Line/Square Horizontal End Address Register 0
#define RA8875_DLHER1 0x96    // Draw Line/Square Horizontal End Address Register 1
#define RA8875_DLVER0 0x97    // Draw Line/Square Vertical End Address Register 0
#define RA8875_DLVER1 0x98    // Draw Line/Square Vertical End Address Register 1
#define RA8875_DCHR0 0x99     // Draw Circle Center Horizontal Address Register 0
#define RA8875_DCHR1 0x9A     // Draw Circle Center Horizontal Address Register 1
#define RA8875_DCVR0 0x9B     // Draw Circle Center Vertical Address Register 0
#define RA8875_DCVR1 0x9C     // Draw Circle Center Vertical Address Register 1
#define RA8875_DCRR 0x9D      // Draw Circle Radius Register
#define RA8875_DECSCR 0xA0    // Draw Ellipse/Ellipse Curve/Circle Square Control Register
#define RA8875_ELL_A0 0xA1    // Draw Ellipse/Circle Square Long axis Setting Register 0
#define RA8875_ELL_A1 0xA2    // Draw Ellipse/Circle Square Long axis Setting Register 1
#define RA8875_ELL_B0 0xA3    // Draw Ellipse/Circle Square Short axis Setting Register 0
#define RA8875_ELL_B1 0xA4    // Draw Ellipse/Circle Square Short axis Setting Register 1
#define RA8875_DEHR0 0xA5     // Draw Ellipse/Circle Square Center Horizontal Address Register 0
#define RA8875_DEHR1 0xA6     // Draw Ellipse/Circle Square Center Horizontal Address Register 1
#define RA8875_DEVR0 0xA7     // Draw Ellipse/Circle Square Center Vertical Address Register 0
#define RA8875_DEVR1 0xA8     // Draw Ellipse/Circle Square Center Vertical Address Register 1
#define RA8875_DTPH0 0xA9     // Draw Triangle Point 2 Horizontal Address Register 0
#define RA8875_DTPH1 0xAA     // Draw Triangle Point 2 Horizontal Address Register 1
#define RA8875_DTPV0 0xAB     // Draw Triangle Point 2 Vertical Address Register 0
#define RA8875_DTPV1 0xAC     // Draw Triangle Point 2 Vertical Address Register 1
#define RA8875_SSAR0 0xB0     // DMA Source Starting Address Register 0
#define RA8875_SSAR1 0xB1     // DMA Source Starting Address Register 1
#define RA8875_SSAR2 0xB2     // DMA Source Starting Address Register 2
#define RA8875_DTNR0 0xB4     // DMA Transfer Number Register 0
#define RA8875_BWR0 0xB4      // DMA Block Width Register 0
#define RA8875_BWR1 0xB5      // DMA Block Width Register 1
#define RA8875_DTNR1 0xB6     // DMA Transfer Number Register 1
#define RA8875_BHR0 0xB6      // DMA Block Height Register 0
#define RA8875_BHR1 0xB7      // DMA Block Height Register 1
#define RA8875_DTNR2 0xB8     // DMA Transfer Number Register 2
#define RA8875_SPWR0 0xB8     // DMA Source Picture Width Register 0
#define RA8875_SPWR1 0xB9     // DMA Source Picture Width Register 1
#define RA8875_DMACR 0xBF     // DMA Configuration Register
#define RA8875_KSCR1 0xC0     // Key-Scan Control Register 1
#define RA8875_KSCR2 0xC1     // Key-Scan Control Register 2
#define RA8875_KSDR0 0xC2     // Key-Scan Data Register 0
#define RA8875_KSDR1 0xC3     // Key-Scan Data Register 1
#define RA8875_KSDR2 0xC4     // Key-Scan Data Register 2
#define RA8875_GPIOX 0xC7     // Extra General Purpose IO Register
#define RA8875_FWSAXA0 0xD0   // Floating Windows Start Address XA 0
#define RA8875_FWSAXA1 0xD1   // Floating Windows Start Address XA 1
#define RA8875_FWSAYA0 0xD2   // Floating Windows Start Address YA 0
#define RA8875_FWSAYA1 0xD3   // Floating Windows Start Address YA 1
#define RA8875_FWW0 0xD4      // Floating Windows Width 0
#define RA8875_FWW1 0xD5      // Floating Windows Width 1
#define RA8875_FWH0 0xD6      // Floating Windows Height 0
#define RA8875_FWH1 0xD7      // Floating Windows Height 1
#define RA8875_FWDXA0 0xD8    // Floating Windows Display X Address 0
#define RA8875_FWDXA1 0xD9    // Floating Windows Display X Address 1
#define RA8875_FWDYA0 0xDA    // Floating Windows Display Y Address 0
#define RA8875_FWDYA1 0xDB    // Floating Windows Display Y Address 1
#define RA8875_SACS_MODE 0xE0 // Serial Flash/ROM Direct Access Mode
#define RA8875_SACS_ADDR 0xE1 // Serial Flash/ROM Direct Access Mode Address
#define RA8875_SACS_DATA 0xE2 // Serial Flash/ROM Direct Access Data Read
#define RA8875_INTC1 0xF0     // Interrupt Control Register 1
#define RA8875_INTC2 0xF1     // Interrupt Control Register 2

// Status register bits
#define RA8875_STATUS_MEM_BUSY (1<<7)    // Memory Read/Write busy
#define RA8875_STATUS_BTE_BUSY (1<<6)    // BTE busy
#define RA8875_STATUS_TOUCH_EVENT (1<<5) // Touch panel event detected
#define RA8875_STATUS_SLEEP (1<<4)       // The controller is in SLEEP mode
#define RA8875_STATUS_FLASH_BUSY (1<<0)  // FLASH/ROM busy in DMA mode

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
        unsigned short osc_clk;    // external crystal oscillator frequency 15000..30000 [kHz]
        unsigned short pixel_clk;  // TFT LCD pixel clock frequency [kHz]
        } GLCDINIT_t;

// Default initialization values for GLCDINIT_t
// Default value for reverse_x
#define RA8875_DEFAULT_REVX 0 // not horizontally reversed

// Default value for reverse_y
#define RA8875_DEFAULT_REVY 0 // not vertically reversed

// 04032015_1
#if _GLCD_MAXX_==480
// 4.3" 480x272 ER-TFTM043-3 display
// Default value for osc_clk external crystal clock frequency [kHz]
#define RA8875_DEFAULT_OSC_CLK_FREQ 20000
// TFT LCD pixel clock frequency [kHz]
#define RA8875_DEFAULT_TFT_PIXEL_CLK_FREQ 13750

// Display specific initialization values for some registers
#define RA8875_HNDFT 0x02 // Horizontal Non-Display Period Fine Tune
#define RA8875_HST 0x01   // HSYNC Start position
#define RA8875_HPW 0x03   // HSYNC Pulse width
#define RA8875_VND 0x000F // Vertical Non-Display area
#define RA8875_VST 0x000E // VSYNC Start position

#elif _GLCD_MAXX_==800
// 7" 800x480 ER-TFTM070-5 display
// Default value for osc_clk external crystal clock frequency [kHz]
#define RA8875_DEFAULT_OSC_CLK_FREQ 20000
// TFT LCD pixel clock frequency [kHz]
#define RA8875_DEFAULT_TFT_PIXEL_CLK_FREQ 30000

// Display specific initialization values for some registers
#define RA8875_HNDFT 0x00 // Horizontal Non-Display Period Fine Tune
#define RA8875_HST 0x03   // HSYNC Start position
#define RA8875_HPW 0x0B   // HSYNC Pulse width
#define RA8875_VND 0x0020 // Vertical Non-Display area
#define RA8875_VST 0x0016 // VSYNC Start position

#else
#error Display not supported by the RA8875 library
#endif


// Usual color definitions
#if _GLCD_COLOR_BITS_==8
// Color definitions for 256 color mode
// Bits 0..1 -> Blue 0..1
// Bits 2..4 -> Green 0..2
// Bits 5..7 -> Red 0..2

// Macro used for converting R5G6B5 color format to R3G3B2
#define GLCD_CL_R5G6B5_R3G3B2(c) ((((c)>>8) & 0xE0) | (((c)>>6) & 0x1C) | (((c)>>3) & 0x03))

#define GLCD_CL_BLACK 0x00
#define GLCD_CL_WHITE 0xFF
#define GLCD_CL_GRAY GLCD_CL_R5G6B5_R3G3B2(0x7BEF)
#define GLCD_CL_LIGHT_GRAY GLCD_CL_R5G6B5_R3G3B2(0xC618)
#define GLCD_CL_GREEN GLCD_CL_R5G6B5_R3G3B2(0x07E0)
#define GLCD_CL_LIME GLCD_CL_R5G6B5_R3G3B2(0x87E0)
#define GLCD_CL_BLUE GLCD_CL_R5G6B5_R3G3B2(0x001F)
#define GLCD_CL_RED GLCD_CL_R5G6B5_R3G3B2(0xF800)
#define GLCD_CL_AQUA GLCD_CL_R5G6B5_R3G3B2(0x5D1C)
#define GLCD_CL_YELLOW GLCD_CL_R5G6B5_R3G3B2(0xFFE0)
#define GLCD_CL_MAGENTA GLCD_CL_R5G6B5_R3G3B2(0xF81F)
#define GLCD_CL_CYAN GLCD_CL_R5G6B5_R3G3B2(0x07FF)
#define GLCD_CL_DARK_CYAN GLCD_CL_R5G6B5_R3G3B2(0x03EF)
#define GLCD_CL_ORANGE GLCD_CL_R5G6B5_R3G3B2(0xFCA0)
#define GLCD_CL_PINK GLCD_CL_R5G6B5_R3G3B2(0xF97F)
#define GLCD_CL_BROWN GLCD_CL_R5G6B5_R3G3B2(0x8200)
#define GLCD_CL_VIOLET GLCD_CL_R5G6B5_R3G3B2(0x9199)
#define GLCD_CL_SILVER GLCD_CL_R5G6B5_R3G3B2(0xA510)
#define GLCD_CL_GOLD GLCD_CL_R5G6B5_R3G3B2(0xA508)
#define GLCD_CL_NAVY GLCD_CL_R5G6B5_R3G3B2(0x000F)
#define GLCD_CL_MAROON GLCD_CL_R5G6B5_R3G3B2(0x7800)
#define GLCD_CL_PURPLE GLCD_CL_R5G6B5_R3G3B2(0x780F)
#define GLCD_CL_OLIVE GLCD_CL_R5G6B5_R3G3B2(0x7BE0)

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

// Writes a data byte to the RA8875 controller's register.
void ra8875_wrreg(unsigned char reg, unsigned char data);
// Reads a data byte to the RA8875 controller's register.
unsigned char ra8875_rdreg(unsigned char reg);
// Reads the status of the RA8875 controller.
unsigned char ra8875_rdstatus(void);
// Waits until the RA8875 controller completes the current memory read/write operation.
void ra8875_membusy(void);
// Waits until the RA8875 controller completes the current BTE operation.
void ra8875_btebusy(void);
// Waits until the RA8875 controller completes the current DMA operation.
void ra8875_dmabusy(void);
// Prepare to start writing to the graphic display memory.
void ra8875_memwr(void);
// Writes color data to the graphic display memory.
void ra8875_wrdata(GLCDCOL_t color);
// Prepare to start reading from the graphic display memory.
// Note: Performs the first dummy read.
void ra8875_memrd(void);
// Reads color data from the the graphic display memory.
GLCDCOL_t ra8875_rddata(void);
// Sets the current display window.
void ra8875_setwindow(GLCDX_t x0,GLCDY_t y0,GLCDX_t x1,GLCDY_t y1);
// Sets the background color for graphic memory clear operation.
void ra8875_setbkcolor(GLCDCOL_t color);
// Sets the foreground color for graphic memory fill & drawing operations.
void ra8875_setfgcolor(GLCDCOL_t color);
// Sets the background transparent color for graphic memory fill & drawing operations.
void ra8875_settpcolor(GLCDCOL_t color);

// Puts/exits the RA8875 controller to/from sleep mode.
void ra8875_sleep(bool on);

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
// Draws a line with the current color, thickness and bit pattern.
void glcd_line(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1, GLCDY_t y1);
// Draws a rectangle using the current line thickness, bit pattern and drawing color.
void glcd_rectangle(GLCDX_t left, GLCDY_t top, GLCDX_t right, GLCDY_t bottom);
// Draws a filled-in rectangular bar, using absolute coordinates.
void glcd_bar(GLCDX_t left, GLCDY_t top, GLCDX_t right, GLCDY_t bottom);
// Draws a filled-in rectangular bar, using relative coordinates.
void glcd_barrel(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height);
// Draws a rectangle with rounded corners using the current line thickness
// and drawing color.
void glcd_rectround(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height, GLCDRAD_t radius);
// Draws a filled rectangle with rounded corners using the current fill color.
void glcd_fillrectround(GLCDX_t left, GLCDY_t top, GLCDX_t width, GLCDY_t height, GLCDRAD_t radius);
// Draws a circle at specified center coordinates using the current
// color and thickness.
void glcd_circle(GLCDX_t x, GLCDY_t y, GLCDRAD_t radius);
// Draws and fills a circle at specified center coordinates using the current
// fill color.
void glcd_fillcircle(GLCDX_t x, GLCDY_t y, GLCDRAD_t radius);

// High level graphic functions specific to the RA8875.
// Draws a triangle using the current color and line thickness.
void glcd_triangle(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1, GLCDY_t y1, GLCDX_t x2, GLCDY_t y2);
// Draws a filled triangle using the current fill color.
void glcd_filltriangle(GLCDX_t x0, GLCDY_t y0, GLCDX_t x1, GLCDY_t y1, GLCDX_t x2, GLCDY_t y2);

#pragma library glcd_ra8875.lib

#endif




