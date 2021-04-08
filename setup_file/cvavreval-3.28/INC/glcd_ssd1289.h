//*****************************************************************************
// Library functions for color TFT graphic LCDs with the
// Solomon Systech SSD1289 controller
// (C) 2010-2014 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.15
// Version: 1.04
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00
// 23092011_1 - Initial release.
// V1.01
// 14022012_1 - Optimized code
// 16022012_1 - Optimized code
// 20022012_4 - Added image transparency support
// 24022012_1 - Added the "reverse_x" member to the GLCDINIT_t structure.
//              Replaced the "gate_scan" member with "reverse_y".
// V1.02
// 30032012_1 - Added the "cl_bits_order" member to the GLCDINIT_t structure.
// 01042012_1 - Improved the speed of the glcd_clear function.
// 02042012_1 - Added fast horizontal & vertical line drawing functions.
//
//
// V1.03
// 28062012_1 - removed not needed:
//              SETBIT(_GLCD_SSD1289_D_NC_OUT_,_GLCD_SSD1289_D_NC_BIT_);
//
// V1.04
// 27082014_2 - Added support for 8 bit data bus connection.
// 29082014_1 - Added support for 320x240 landscape display mode.
//*****************************************************************************

#ifndef _GLCD_SSD1289_INCLUDED_
#define _GLCD_SSD1289_INCLUDED_

#include <glcd_types.h>

// 02042012_1
// Use fast horizontal & vertical line drawing functions.
#define _GLCD_FAST_LINEH_
#define _GLCD_FAST_LINEV_

// SSD1289 controller ID
#define SSD1289_CTRL_ID 0x8989

// SSD1289 command register definitions
#define SSD1289_CMD_OSC 0x00 // Oscillator register
// Osc. register commands
#define SSD1289_STOP_OSC 0  // Stop oscillator
#define SSD1289_START_OSC 1 // Start oscillator

#define SSD1289_CMD_DRIVER_OUT 0x01 // Driver output control
// Driver output control bits positions
#define SSD1289_RL_BIT 14 // RL bit pos. selects the output
                          // shift direction of source driver
#define SSD1289_REV_BIT 13 // REV bit pos. displays reversed graphics
#define SSD1289_CAD_BIT 12 // CAD bit pos. retention capacitor config.
#define SSD1289_BGR_BIT 11 // BGR bit pos. selects writing order to GDDRAM
                           // RGB or BGR
#define SSD1289_SM_BIT 10  // SM bit pos. gate scan sequence interlaced or not
#define SSD1289_TB_BIT 9   // TB bit position selects the output shift direction

#define SSD1289_CMD_DRIVING_WAVEFORM 0x02 // LCD driving waveform control
// Driving waveform control bits positions
#define SSD1289_FLD_BIT 12 // FLD bit pos. splits one frame into 3 fields
                           // to reduce flicker

#define SSD1289_CMD_POWER_CONTROL1 0x03 // Power control 1
// Power control 1 bits positions
#define SSD1289_DCT0_BIT 12 // DCT0 bit pos.
#define SSD1289_BT0_BIT 9 // BT0 bit pos. controls the step-up factor
                          // of the step-up circuit
#define SSD1289_DC0_BIT 4 // DC0 bit pos. controls the cycle for the
                          // step-up circuit
#define SSD1289_AP0_BIT 1 // AP0 bit pos. adjust the amount of current
                          // from the constant current source in the
                          // internal op. amplifier circuit

#define SSD1289_CMD_CMP_REG1 0x05 // Compare register 1
#define SSD1289_CMD_CMP_REG2 0x06 // Compare register 2
#define SSD1289_CMD_DISPLAY_CONTROL 0x07 // Display control register
// Display control register bit positions
#define SSD1289_DC_GON_BIT 5
#define SSD1289_DC_DTE_BIT 4
#define SSD1289_DC_D1_BIT 1
#define SSD1289_DC_D0_BIT 0

#define SSD1289_CMD_FRAME_CYCLE 0x0b // Frame cycle control register
#define SSD1289_CMD_POWER_CONTROL2 0x0c // Power control 2 register
#define SSD1289_CMD_POWER_CONTROL3 0x0d // Power control 3 register
#define SSD1289_CMD_POWER_CONTROL4 0x0e // Power control 4 register
// Power control 4 register bits positions
#define SSD1289_VCOMG_BIT 13 // VCOMG bit pos.
#define SSD1289_VDV0_BIT 8 // VDV0 bit pos. sets the alternating amplitudes
                           // of VcomL voltage

#define SSD1289_CMD_GATE_SCAN_POS 0x0f // Gate scan position register
#define SSD1289_CMD_SLEEP_MODE 0x10 // Sleep mode register
// Sleep mode commands
#define SSD1289_SLEEP_OFF 0
#define SSD1289_SLEEP_ON 1

#define SSD1289_CMD_ENTRY_MODE 0x11 // Entry mode register
#define SSD1289_CMD_GENERIC_IF_CTRL 0x15 // Generic interface control register
#define SSD1289_CMD_HORIZ_PORCH 0x16 // Horizontal porch register
#define SSD1289_CMD_VERT_PORCH 0x17 // Vertical porch register
#define SSD1289_CMD_POWER_CONTROL5 0x1e // Power control 5 register
// Power control 5 register bits positions
#define SSD1289_NOTP_BIT 7 // nOTP bit pos.
#define SSD1289_VCM0_BIT 0 // VCM0 bit pos. sets the VcomH voltage

#define SSD1289_CMD_GDDRAM_DATA 0x22 // GDDRAM read/write data register
#define SSD1289_CMD_GDDRAM_WR_MASK1 0x23 // GDDRAM write data mask 1 register
#define SSD1289_CMD_GDDRAM_WR_MASK2 0x24 // GDDRAM write data mask 2 register
#define SSD1289_CMD_FRAME_FREQ 0x25 // Frame frequency control register
// Bit position for frame control bits
#define SSD1289_OSC0_BIT 12
#define SSD1289_OSC1_BIT 13
#define SSD1289_OSC2_BIT 14
#define SSD1289_OSC3_BIT 15

#define SSD1289_CMD_GAMMA_CONTROL1 0x30 // Gamma control 1
// Gamma control 1 bit positions
#define SSD1289_PKP00_BIT 0
#define SSD1289_PKP10_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL2 0x31 // Gamma control 2
// Gamma control 2 bit positions
#define SSD1289_PKP20_BIT 0
#define SSD1289_PKP30_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL3 0x32 // Gamma control 3
// Gamma control 3 bit positions
#define SSD1289_PKP40_BIT 0
#define SSD1289_PKP50_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL4 0x33 // Gamma control 4
// Gamma control 4 bit positions
#define SSD1289_PRP00_BIT 0
#define SSD1289_PRP10_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL5 0x34 // Gamma control 5
// Gamma control 5 bit positions
#define SSD1289_PKN00_BIT 0
#define SSD1289_PKN10_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL6 0x35 // Gamma control 6
// Gamma control 6 bit positions
#define SSD1289_PKN20_BIT 0
#define SSD1289_PKN30_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL7 0x36 // Gamma control 7
// Gamma control 7 bit positions
#define SSD1289_PKN40_BIT 0
#define SSD1289_PKN50_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL8 0x37 // Gamma control 8
// Gamma control 8 bit positions
#define SSD1289_PRN00_BIT 0
#define SSD1289_PRN10_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL9 0x3a // Gamma control 9
// Gamma control 9 bit positions
#define SSD1289_VRP00_BIT 0
#define SSD1289_VRP10_BIT 8

#define SSD1289_CMD_GAMMA_CONTROL10 0x3b // Gamma control 10
// Gamma control 10 bit positions
#define SSD1289_VRN00_BIT 0
#define SSD1289_VRN10_BIT 8

#define SSD1289_CMD_VERT_SCROLL1 0x41 // Vertical scroll control for screen 1
#define SSD1289_CMD_VERT_SCROLL2 0x42 // Vertical scroll control for screen 2
#define SSD1289_CMD_HORIZ_RAM_ADDR 0x44 // Addresses of horizontal start/end window positions
#define SSD1289_CMD_VERT_RAM_ADDR_START 0x45 // Address of vertical start window positions
#define SSD1289_CMD_VERT_RAM_ADDR_END 0x46 // Address of vertical end window positions
#define SSD1289_CMD_DRV_POS_START1 0x48 // Driving start line position for screen 1
#define SSD1289_CMD_DRV_POS_END1 0x49 // Driving end line position for screen 1
#define SSD1289_CMD_DRV_POS_START2 0x4a // Driving start line position for screen 2
#define SSD1289_CMD_DRV_POS_END2 0x4b // Driving end line position for screen 2
#define SSD1289_CMD_GDDRAMX 0x4e // Set GDDRAM X address counter register
#define SSD1289_CMD_GDDRAMY 0x4f // Set GDDRAM Y address counter register

// Structure that contains controller specific graphic LCD initialization data
typedef struct
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr);
        // pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char reverse_x:1; // reverse display horizontally 24022012_1
        unsigned char reverse_y:1; // reverse display vertically 24022012_1
        // 30032012_1
        unsigned char cl_bits_order:1; // selects the color bits writing order to the display RAM
                                       // =0 -> RGB, =1 ->BGR
        // power control registers bits
        unsigned char stepup_factor:3; // step-up factor of the step-up circuit
                                       // see BT0..BT2 bits in the datasheet
        unsigned char stepup_cycle:4;  // controls the cycle for the step-up circuit
        unsigned char crt_source:3; // adjusts the amount of current
                                    // from the constant current source in the
                                    // internal op. amplifier circuit (AP0..AP2 bits)
        unsigned char vcix2:3;  // adjusts the VCIX2 voltage
        unsigned char vlcd63:4; // adjusts the VLCD63 voltage
        unsigned char vcoml:5;  // adjusts the amplitude of the VcomL alternating
                                // drive voltage
        unsigned char vcomh:5;  // adjusts the amplitude of the VcomH voltage
                                // VcomH=VLCD63*(0.35+vcomh*0.01) [V]
        unsigned char frame_freq:4; // LCD frame frequency
        // positive gamma control registers bits
        unsigned char pkp00:3; // PKP00..PKP02 positive gamma micro adj.
        unsigned char pkp10:3; // PKP10..PKP12 positive gamma micro adj.
        unsigned char pkp20:3; // PKP20..PKP22 positive gamma micro adj.
        unsigned char pkp30:3; // PKP30..PKP32 positive gamma micro adj.
        unsigned char pkp40:3; // PKP40..PKP42 positive gamma micro adj.
        unsigned char pkp50:3; // PKP50..PKP52 positive gamma micro adj.
        unsigned char prp00:3; // PRP00..PRP02 positive gamma gradient adj.
        unsigned char prp10:3; // PRP10..PRP12 positive gamma gradient adj.
        unsigned char vrp00:4; // VRP00..VRP03 positive gamma amplification adj.
        unsigned char vrp10:5; // VRP10..VRP14 positive gamma amplification adj.
        // negative gamma control registers bits
        unsigned char pkn00:3; // PKN00..PKN02 negative gamma micro adj.
        unsigned char pkn10:3; // PKN10..PKN12 negative gamma micro adj.
        unsigned char pkn20:3; // PKN20..PKN22 positive gamma micro adj.
        unsigned char pkn30:3; // PKN30..PKN32 positive gamma micro adj.
        unsigned char pkn40:3; // PKN40..PKN42 negative gamma micro adj.
        unsigned char pkn50:3; // PKN50..PKN52 negative gamma micro adj.
        unsigned char prn00:3; // PRN00..PRN02 negative gamma gradient adj.
        unsigned char prn10:3; // PRN10..PRN12 negative gamma gradient adj.
        unsigned char vrn00:4; // VRN00..VRN03 negative gamma amplification adj.
        unsigned char vrn10:5; // VRN10..VRN14 negative gamma amplification adj.
        } GLCDINIT_t;

// Initialization values for reverse_x
#define SSD1289_REVX_NORM 0 // No horizontal reverse
#define SSD1289_REVX_REV 1 // Horizontal reverse

// Initialization values for reverse_y
#define SSD1289_REVY_NORM 0 // No vertical reverse
#define SSD1289_REVY_REV 1 // Vertical reverse

// 30032012_1
// Initialization values for cl_bits_order
#define SSD1289_CL_BITS_RGB 0 // Write color bits to display RAM in RGB order
#define SSD1289_CL_BITS_BGR 1 // Write color bits to display RAM in BGR order

// Initilization values for dc30 step-up circuit cycle
#define SSD1289_STEPUP_FLINE24 0 // Fline *24
#define SSD1289_STEPUP_FLINE16 1 // Fline *16
#define SSD1289_STEPUP_FLINE12 2 // Fline *12
#define SSD1289_STEPUP_FLINE8 3 // Fline *8
#define SSD1289_STEPUP_FLINE6 4 // Fline *6
#define SSD1289_STEPUP_FLINE5 5 // Fline *5
#define SSD1289_STEPUP_FLINE4 6 // Fline *4
#define SSD1289_STEPUP_FLINE3 7 // Fline *3
#define SSD1289_STEPUP_FLINE2 8 // Fline *2
#define SSD1289_STEPUP_FLINE1 9 // Fline *1
#define SSD1289_STEPUP_FOSC4 10 // Fosc /4  (Fosc=510kHz)
#define SSD1289_STEPUP_FOSC6 11 // Fosc /6
#define SSD1289_STEPUP_FOSC8 12 // Fosc /8
#define SSD1289_STEPUP_FOSC10 13 // Fosc /10
#define SSD1289_STEPUP_FOSC12 14 // Fosc /12
#define SSD1289_STEPUP_FOSC16 15 // Fosc /16

// Initialization values for the VCIX2 voltage
#define SSD1289_VCIX2_5V1 0 // 5.1V
#define SSD1289_VCIX2_5V2 1 // 5.2V
#define SSD1289_VCIX2_5V3 2 // 5.3V
#define SSD1289_VCIX2_5V4 3 // 5.4V
#define SSD1289_VCIX2_5V5 4 // 5.5V
#define SSD1289_VCIX2_5V6 5 // 5.6V
#define SSD1289_VCIX2_5V7 6 // 5.7V
#define SSD1289_VCIX2_5V8 7 // 5.8V

// Initialization values for the VLCD63 voltage
#define SSD1289_VLCD63_3V08 0 // VLCD63=3.08V
#define SSD1289_VLCD63_3V24 1 // VLCD63=3.24V
#define SSD1289_VLCD63_3V40 2 // VLCD63=3.40V
#define SSD1289_VLCD63_3V56 3 // VLCD63=3.56V
#define SSD1289_VLCD63_3V70 4 // VLCD63=3.70V
#define SSD1289_VLCD63_3V86 5 // VLCD63=3.86V
#define SSD1289_VLCD63_4V04 6 // VLCD63=4.04V
#define SSD1289_VLCD63_4V18 7 // VLCD63=4.18V
#define SSD1289_VLCD63_4V33 8 // VLCD63=4.33V
#define SSD1289_VLCD63_4V49 9 // VLCD63=4.49V
#define SSD1289_VLCD63_4V67 10 // VLCD63=4.67V
#define SSD1289_VLCD63_4V80 11 // VLCD63=4.80V
#define SSD1289_VLCD63_5V00 12 // VLCD63=5.00V
#define SSD1289_VLCD63_5V14 13 // VLCD63=5.14V
#define SSD1289_VLCD63_5V29 14 // VLCD63=5.29V
#define SSD1289_VLCD63_5V45 15 // VLCD63=5.45V

// Initialization values for the VcomL voltage
#define SSD1289_VCOML_0_60 0 // VcomL=VLCD63*0.60
#define SSD1289_VCOML_0_63 1 // VcomL=VLCD63*0.63
#define SSD1289_VCOML_0_66 2 // VcomL=VLCD63*0.66
#define SSD1289_VCOML_0_69 3 // VcomL=VLCD63*0.69
#define SSD1289_VCOML_0_72 4 // VcomL=VLCD63*0.72
#define SSD1289_VCOML_0_75 5 // VcomL=VLCD63*0.75
#define SSD1289_VCOML_0_78 6 // VcomL=VLCD63*0.78
#define SSD1289_VCOML_0_81 7 // VcomL=VLCD63*0.81
#define SSD1289_VCOML_0_84 8 // VcomL=VLCD63*0.84
#define SSD1289_VCOML_0_87 9 // VcomL=VLCD63*0.87
#define SSD1289_VCOML_0_90 10 // VcomL=VLCD63*0.90
#define SSD1289_VCOML_0_93 11 // VcomL=VLCD63*0.93
#define SSD1289_VCOML_0_96 12 // VcomL=VLCD63*0.96
#define SSD1289_VCOML_0_99 13 // VcomL=VLCD63*0.99
#define SSD1289_VCOML_1_02 14 // VcomL=VLCD63*1.02
#define SSD1289_VCOML_EXT_RES 15 // VcomL is set by external var. resistor
#define SSD1289_VCOML_1_05 16 // VcomL=VLCD63*1.05
#define SSD1289_VCOML_1_08 17 // VcomL=VLCD63*1.08
#define SSD1289_VCOML_1_11 18 // VcomL=VLCD63*1.11
#define SSD1289_VCOML_1_14 19 // VcomL=VLCD63*1.14
#define SSD1289_VCOML_1_17 20 // VcomL=VLCD63*1.17
#define SSD1289_VCOML_1_20 21 // VcomL=VLCD63*1.20
#define SSD1289_VCOML_1_23 22 // VcomL=VLCD63*1.23

// Initialization values for frame_freq
#define SSD1289_FRAME50 0 // 50Hz
#define SSD1289_FRAME55 2 // 55Hz
#define SSD1289_FRAME60 5 // 60Hz
#define SSD1289_FRAME65 8 // 65Hz
#define SSD1289_FRAME70 0x0A // 70Hz
#define SSD1289_FRAME75 0x0C // 75Hz
#define SSD1289_FRAME80 0x0E // 80Hz

// Default value for reverse_x
#define SSD1289_DEFAULT_REVX SSD1289_REVX_NORM // No horizontal reverse
// Default value for reverse_y
#define SSD1289_DEFAULT_REVY SSD1289_REVY_NORM // No vertical reverse
// 30032012_1
// Default value for cl_bits_order (color bits writing order to display RAM)
#define SSD1289_DEFAULT_CL_BITS SSD1289_CL_BITS_RGB // write in RGB order

#define SSD1289_DEFAULT_STEPUP_FACTOR 4 // Power control 1 BT0..BT2 step-up factor of the step-up circuit
#define SSD1289_DEFAULT_STEPUP_CYCLE SSD1289_STEPUP_FOSC4 // Power control 1 DC0..DC3 step-up circuit cycle
#define SSD1289_DEFAULT_CRT_SOURCE 2 // Power control 1 AP0..AP2 adjusts the amount of current
                                     // from the constant current source in the
                                     // internal op. amplifier circuit
#define SSD1289_DEFAULT_VCIX2 SSD1289_VCIX2_5V1 // Default value for VCIX2 voltage
#define SSD1289_DEFAULT_VLCD63 SSD1289_VLCD63_4V80 // Default value for VLCD63 voltage
#define SSD1289_DEFAULT_VCOML SSD1289_VCOML_0_72 // Default value for VcomL alternating drive voltage
#define SSD1289_DEFAULT_VCOMH 0x1A // Default value for VcomH=VLCD63*(0.35+0x1A*0.01)

#define SSD1289_DEFAULT_FLD 1 // Default value for driving waveform control
                              // FLD bit, splits one frame into 3 fields
                              // to reduce flicker

#define SSD1289_DEFAULT_FRAME_FREQ SSD1289_FRAME80 // Default value for
                                                   // LCD frame frequency

// Default initialization values for the gamma control register bits
#define SSD1289_DEFAULT_PKP00 7 // PKP00..PKP02 positive gamma micro adj.
#define SSD1289_DEFAULT_PKP10 7 // PKP10..PKP12 positive gamma micro adj.
#define SSD1289_DEFAULT_PKP20 4 // PKP20..PKP22 positive gamma micro adj.
#define SSD1289_DEFAULT_PKP30 2 // PKP30..PKP32 positive gamma micro adj.
#define SSD1289_DEFAULT_PKP40 4 // PKP40..PKP42 positive gamma micro adj.
#define SSD1289_DEFAULT_PKP50 2 // PKP50..PKP52 positive gamma micro adj.
#define SSD1289_DEFAULT_PRP00 2 // PRP00..PRP02 positive gamma gradient adj.
#define SSD1289_DEFAULT_PRP10 5 // PRP10..PRP12 positive gamma gradient adj.
#define SSD1289_DEFAULT_VRP00 2 // VRP00..VRP03 positive gamma amplification adj.
#define SSD1289_DEFAULT_VRP10 3 // VRP10..VRP14 positive gamma amplification adj.
#define SSD1289_DEFAULT_PKN00 7 // PKN00..PKN02 negative gamma micro adj.
#define SSD1289_DEFAULT_PKN10 5 // PKN10..PKN12 negative gamma micro adj.
#define SSD1289_DEFAULT_PKN20 4 // PKN20..PKN22 positive gamma micro adj.
#define SSD1289_DEFAULT_PKN30 2 // PKN30..PKN32 positive gamma micro adj.
#define SSD1289_DEFAULT_PKN40 4 // PKN40..PKN42 negative gamma micro adj.
#define SSD1289_DEFAULT_PKN50 2 // PKN50..PKN52 negative gamma micro adj.
#define SSD1289_DEFAULT_PRN00 2 // PRN00..PRN02 negative gamma gradient adj.
#define SSD1289_DEFAULT_PRN10 5 // PRN10..PRN12 negative gamma gradient adj.
#define SSD1289_DEFAULT_VRN00 2 // VRN00..VRN03 negative gamma amplification adj.
#define SSD1289_DEFAULT_VRN10 3 // VRN10..VRN14 negative gamma amplification adj.

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

// Writes a command to the SSD1289 controller.
void ssd1289_wrcmd(unsigned char cmd);
// Writes data to the SSD1289 controller.
void ssd1289_wrdata(unsigned short data);
// Reads a data word from the SSD1289 controller.
unsigned short ssd1289_rddata(void);
// Writes a word to a register of the SSD1289 controller.
void ssd1289_wrreg(unsigned char index, unsigned short data);
// Reads a word from a register of the SSD1289 controller.
unsigned short ssd1289_rdreg(unsigned char index);

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

#pragma library glcd_ssd1289.lib

#endif




