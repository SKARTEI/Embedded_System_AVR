//*****************************************************************************
// Library functions for color TFT graphic LCDs with the
// Solomon Systech SSD2119 controller
// (C) 2010-2012 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V2.05.8+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00
// 28032012_1 - Initial release.
//*****************************************************************************

#ifndef _GLCD_SSD2119_INCLUDED_
#define _GLCD_SSD2119_INCLUDED_

#include <glcd_types.h>

// SSD2119 controller ID
#ifdef _GLCD_SSD2119_8BIT_BUS_
#define SSD2119_CTRL_ID 0x9999
#else
#define SSD2119_CTRL_ID 0x9919
#endif

// Use fast horizontal & vertical line drawing functions.
#define _GLCD_FAST_LINEH_
#define _GLCD_FAST_LINEV_

// SSD2119 command register definitions
#define SSD2119_CMD_OSC 0x00 // Oscillator register
// Osc. register commands
#define SSD2119_STOP_OSC 0  // Stop oscillator
#define SSD2119_START_OSC 1 // Start oscillator

#define SSD2119_CMD_DRIVER_OUT 0x01 // Driver output control
// Driver output control bits positions
#define SSD2119_RL_BIT 14 // RL bit pos. selects the output
                          // shift direction of source driver
#define SSD2119_REV_BIT 13 // REV bit pos. displays reversed graphics
#define SSD2119_GD_BIT 12 // GD bit pos. selects the first output gate
#define SSD2119_BGR_BIT 11 // BGR bit pos. selects writing order to GDDRAM
                           // =0 -> RGB or =1 -> BGR
#define SSD2119_SM_BIT 10  // SM bit pos. gate scan sequence interlaced or not
#define SSD2119_TB_BIT 9   // TB bit position selects the output shift direction                          

#define SSD2119_CMD_DRIVING_WAVEFORM 0x02 // LCD driving waveform control
// Driving waveform control bits positions
#define SSD2119_FLD_BIT 12 // FLD bit pos. splits one frame into 3 fields
                           // to reduce flicker

#define SSD2119_CMD_POWER_CONTROL1 0x03 // Power control 1
// Power control 1 bits positions
#define SSD2119_DCT0_BIT 12 // DCT0 bit pos.
#define SSD2119_BT0_BIT 9 // BT0 bit pos. controls the step-up factor
                          // of the step-up circuit
#define SSD2119_DC0_BIT 4 // DC0 bit pos. controls the cycle for the
                          // step-up circuit
#define SSD2119_AP0_BIT 1 // AP0 bit pos. adjust the amount of current
                          // from the constant current source in the
                          // internal op. amplifier circuit

#define SSD2119_CMD_DISPLAY_CONTROL 0x07 // Display control register
// Display control register bit positions
#define SSD2119_DC_GON_BIT 5
#define SSD2119_DC_DTE_BIT 4
#define SSD2119_DC_D1_BIT 1
#define SSD2119_DC_D0_BIT 0

#define SSD2119_CMD_FRAME_CYCLE 0x0b // Frame cycle control register
#define SSD2119_CMD_POWER_CONTROL2 0x0c // Power control 2 register
#define SSD2119_CMD_POWER_CONTROL3 0x0d // Power control 3 register
#define SSD2119_CMD_POWER_CONTROL4 0x0e // Power control 4 register
// Power control 4 register bits positions
#define SSD2119_VCOMG_BIT 13 // VCOMG bit pos.
#define SSD2119_VDV0_BIT 8 // VDV0 bit pos. sets the alternationg amplitudes
                           // of VcomL voltage

#define SSD2119_CMD_GATE_SCAN_POS 0x0f // Gate scan position register
#define SSD2119_CMD_SLEEP_MODE 0x10 // Sleep mode register
// Sleep mode commands
#define SSD2119_SLEEP_OFF 0 // Exit sleep mode
#define SSD2119_SLEEP_ON 1 // Enter sleep mode

#define SSD2119_CMD_ENTRY_MODE 0x11 // Entry mode register
#define SSD2119_CMD_DEEP_SLEEP_MODE 0x12 // Deep sleep mode register
// Deep sleep mode commands
#define SSD2119_DEEP_SLEEP_OFF 0x0d99 // Disable deep sleep mode
#define SSD2119_DEEP_SLEEP_ON 0x2d99 // Enable deep sleep mode

#define SSD2119_CMD_GENERIC_IF_CTRL 0x15 // Generic interface control register
#define SSD2119_CMD_HORIZ_PORCH 0x16 // Horizontal porch register
#define SSD2119_CMD_VERT_PORCH 0x17 // Vertical porch register
#define SSD2119_CMD_POWER_CONTROL5 0x1e // Power control 5 register
// Power control 5 register bits positions
#define SSD2119_NOTP_BIT 7 // nOTP bit pos.
#define SSD2119_VCM0_BIT 0 // VCM0 bit pos. sets the VcomH voltage

#define SSD2119_CMD_GDDRAM_DATA 0x22 // GDDRAM read/write data register
#define SSD2119_CMD_FRAME_FREQ 0x25 // Frame frequency control register
// Bit position for frame control bits
#define SSD2119_OSC0_BIT 12
#define SSD2119_OSC1_BIT 13
#define SSD2119_OSC2_BIT 14
#define SSD2119_OSC3_BIT 15

#define SSD2119_CMD_GAMMA_CONTROL1 0x30 // Gamma control 1
// Gamma control 1 bit positions
#define SSD2119_PKP00_BIT 0
#define SSD2119_PKP10_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL2 0x31 // Gamma control 2
// Gamma control 2 bit positions
#define SSD2119_PKP20_BIT 0
#define SSD2119_PKP30_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL3 0x32 // Gamma control 3
// Gamma control 3 bit positions
#define SSD2119_PKP40_BIT 0
#define SSD2119_PKP50_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL4 0x33 // Gamma control 4
// Gamma control 4 bit positions
#define SSD2119_PRP00_BIT 0
#define SSD2119_PRP10_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL5 0x34 // Gamma control 5
// Gamma control 5 bit positions
#define SSD2119_PKN00_BIT 0
#define SSD2119_PKN10_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL6 0x35 // Gamma control 6
// Gamma control 6 bit positions
#define SSD2119_PKN20_BIT 0
#define SSD2119_PKN30_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL7 0x36 // Gamma control 7
// Gamma control 7 bit positions
#define SSD2119_PKN40_BIT 0
#define SSD2119_PKN50_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL8 0x37 // Gamma control 8
// Gamma control 8 bit positions
#define SSD2119_PRN00_BIT 0
#define SSD2119_PRN10_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL9 0x3a // Gamma control 9
// Gamma control 9 bit positions
#define SSD2119_VRP00_BIT 0
#define SSD2119_VRP10_BIT 8

#define SSD2119_CMD_GAMMA_CONTROL10 0x3b // Gamma control 10
// Gamma control 10 bit positions
#define SSD2119_VRN00_BIT 0
#define SSD2119_VRN10_BIT 8

#define SSD2119_CMD_VERT_SCROLL1 0x41 // Vertical scroll control for screen 1
#define SSD2119_CMD_VERT_SCROLL2 0x42 // Vertical scroll control for screen 2
#define SSD2119_CMD_VERT_RAM_ADDR 0x44 // Addresses of vertical start/end window positions
#define SSD2119_CMD_HORIZ_RAM_ADDR_START 0x45 // Address of horizontal start window positions
#define SSD2119_CMD_HORIZ_RAM_ADDR_END 0x46 // Address of horizontal end window positions
#define SSD2119_CMD_DRV_POS_START1 0x48 // Driving start line position for screen 1 
#define SSD2119_CMD_DRV_POS_END1 0x49 // Driving end line position for screen 1 
#define SSD2119_CMD_DRV_POS_START2 0x4a // Driving start line position for screen 2 
#define SSD2119_CMD_DRV_POS_END2 0x4b // Driving end line position for screen 2 
#define SSD2119_CMD_GDDRAMX 0x4e // Set GDDRAM X address counter register
#define SSD2119_CMD_GDDRAMY 0x4f // Set GDDRAM Y address counter register

// Structure that contains controller specific graphic LCD initialization data
typedef struct 
        {
        flash unsigned char *font; // default font after initialization
        // pointer to the function used for reading a byte from external memory
        unsigned char (*readxmem) (GLCDMEMADDR_t addr); 
        // Pointer to the function used for writing a byte to external memory
        void (*writexmem) (GLCDMEMADDR_t addr, unsigned char data);
        unsigned char reverse_x:1; // reverse display horizontally
        unsigned char reverse_y:1; // reverse display vertically
        unsigned char first_out_gate:1; // selects the first output gate  
                                        // GD bit of Driver Output Control register
                                        // =0 Gate 1 on left side of display
                                        // =1 Gate 2 on left side of display
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
#define SSD2119_REVX_NORM 0 // No horizontal reverse
#define SSD2119_REVX_REV 1 // Horizontal reverse

// Initialization values for reverse_y
#define SSD2119_REVY_NORM 0 // No vertical reverse
#define SSD2119_REVY_REV 1 // Vertical reverse

// Initialization values for first_out_gate
#define SSD2119_FIRST_OUT_GATE1 0 // Gate 1 on left side of display
#define SSD2119_FIRST_OUT_GATE2 1 // Gate 2 on left side of display

// Initialization values for cl_bits_order
#define SSD2119_CL_BITS_RGB 0 // Write color bits to display RAM in RGB order
#define SSD2119_CL_BITS_BGR 1 // Write color bits to display RAM in BGR order

// Initilization values for DC30 step-up circuit cycle
// (Power Control Reg. 1)
#define SSD2119_STEPUP_FLINE24 0 // Fline *24
#define SSD2119_STEPUP_FLINE16 1 // Fline *16
#define SSD2119_STEPUP_FLINE12 2 // Fline *12
#define SSD2119_STEPUP_FLINE8 3 // Fline *8
#define SSD2119_STEPUP_FLINE6 4 // Fline *6
#define SSD2119_STEPUP_FLINE5 5 // Fline *5
#define SSD2119_STEPUP_FLINE4 6 // Fline *4
#define SSD2119_STEPUP_FLINE3 7 // Fline *3
#define SSD2119_STEPUP_FLINE2 8 // Fline *2
#define SSD2119_STEPUP_FLINE1 9 // Fline *1
#define SSD2119_STEPUP_FOSC4 10 // Fosc /4  (Fosc=510kHz)
#define SSD2119_STEPUP_FOSC6 11 // Fosc /6
#define SSD2119_STEPUP_FOSC8 12 // Fosc /8
#define SSD2119_STEPUP_FOSC10 13 // Fosc /10
#define SSD2119_STEPUP_FOSC12 14 // Fosc /12
#define SSD2119_STEPUP_FOSC16 15 // Fosc /16

// Initialization values for the VCIX2 voltage 
// (Power Control Reg. 2)
#define SSD2119_VCIX2_5V1 0 // 5.1V
#define SSD2119_VCIX2_5V3 1 // 5.3V
#define SSD2119_VCIX2_5V5 2 // 5.5V
#define SSD2119_VCIX2_5V7 3 // 5.7V
#define SSD2119_VCIX2_5V9 4 // 5.9V
#define SSD2119_VCIX2_6V1 5 // 6.1V

// Initialization values for the VLCD63 voltage
// (bits VRH0..3 from Power Control Reg. 3)
#define SSD2119_VLCD63_3V56 3 // VLCD63=3.56V
#define SSD2119_VLCD63_3V70 4 // VLCD63=3.70V
#define SSD2119_VLCD63_3V86 5 // VLCD63=3.86V
#define SSD2119_VLCD63_4V04 6 // VLCD63=4.04V
#define SSD2119_VLCD63_4V18 7 // VLCD63=4.18V
#define SSD2119_VLCD63_4V33 8 // VLCD63=4.33V
#define SSD2119_VLCD63_4V49 9 // VLCD63=4.49V
#define SSD2119_VLCD63_4V67 10 // VLCD63=4.67V
#define SSD2119_VLCD63_4V80 11 // VLCD63=4.80V
#define SSD2119_VLCD63_5V00 12 // VLCD63=5.00V
#define SSD2119_VLCD63_5V14 13 // VLCD63=5.14V
#define SSD2119_VLCD63_5V29 14 // VLCD63=5.29V
#define SSD2119_VLCD63_5V45 15 // VLCD63=5.45V
#define SSD2119_VLCD63_5V62 0 // VLCD63=5.62V
#define SSD2119_VLCD63_5V80 1 // VLCD63=5.80V
#define SSD2119_VLCD63_6V00 2 // VLCD63=6.00V

// Initialization values for the VcomL voltage
// (bits VDV0..4 from Power Control Reg. 4)
#define SSD2119_VCOML_0_60 0 // VcomL=VLCD63*0.60
#define SSD2119_VCOML_0_63 1 // VcomL=VLCD63*0.63
#define SSD2119_VCOML_0_66 2 // VcomL=VLCD63*0.66
#define SSD2119_VCOML_0_69 3 // VcomL=VLCD63*0.69
#define SSD2119_VCOML_0_72 4 // VcomL=VLCD63*0.72
#define SSD2119_VCOML_0_75 5 // VcomL=VLCD63*0.75
#define SSD2119_VCOML_0_78 6 // VcomL=VLCD63*0.78
#define SSD2119_VCOML_0_81 7 // VcomL=VLCD63*0.81
#define SSD2119_VCOML_0_84 8 // VcomL=VLCD63*0.84
#define SSD2119_VCOML_0_87 9 // VcomL=VLCD63*0.87
#define SSD2119_VCOML_0_90 10 // VcomL=VLCD63*0.90
#define SSD2119_VCOML_0_93 11 // VcomL=VLCD63*0.93
#define SSD2119_VCOML_0_96 12 // VcomL=VLCD63*0.96
#define SSD2119_VCOML_0_99 13 // VcomL=VLCD63*0.99
#define SSD2119_VCOML_1_02 14 // VcomL=VLCD63*1.02
#define SSD2119_VCOML_EXT_RES 15 // VcomL is set by external var. resistor
#define SSD2119_VCOML_1_05 16 // VcomL=VLCD63*1.05
#define SSD2119_VCOML_1_08 17 // VcomL=VLCD63*1.08
#define SSD2119_VCOML_1_11 18 // VcomL=VLCD63*1.11
#define SSD2119_VCOML_1_14 19 // VcomL=VLCD63*1.14
#define SSD2119_VCOML_1_17 20 // VcomL=VLCD63*1.17
#define SSD2119_VCOML_1_20 21 // VcomL=VLCD63*1.20
#define SSD2119_VCOML_1_23 22 // VcomL=VLCD63*1.23

// Initialization values for frame_freq
#define SSD2119_FRAME50 0 // 50Hz
#define SSD2119_FRAME55 2 // 55Hz
#define SSD2119_FRAME60 5 // 60Hz
#define SSD2119_FRAME65 8 // 65Hz
#define SSD2119_FRAME70 0x0A // 70Hz
#define SSD2119_FRAME75 0x0C // 75Hz
#define SSD2119_FRAME80 0x0E // 80Hz

// Default value for reverse_x
#define SSD2119_DEFAULT_REVX SSD2119_REVX_NORM // No horizontal reverse
// Default value for reverse_y
#define SSD2119_DEFAULT_REVY SSD2119_REVY_NORM // No vertical reverse
// Default value for first_out_gate
#define SSD2119_DEFAULT_FIRST_OUT_GATE SSD2119_FIRST_OUT_GATE2 // Gate 2 on left side of display
// Default value for cl_bits_order
#define SSD2119_DEFAULT_CL_BITS SSD2119_CL_BITS_RGB // write in RGB order

#define SSD2119_DEFAULT_STEPUP_FACTOR 4 // Power control 1 BT0..BT2 step-up factor of the step-up circuit
#define SSD2119_DEFAULT_STEPUP_CYCLE SSD2119_STEPUP_FOSC4 // Power control 1 DC0..DC3 step-up circuit cycle
#define SSD2119_DEFAULT_CRT_SOURCE 2 // Power control 1 AP0..AP2 adjusts the amount of current
                                     // from the constant current source in the
                                     // internal op. amplifier circuit
#define SSD2119_DEFAULT_VCIX2 SSD2119_VCIX2_5V1 // Default value for VCIX2 voltage
#define SSD2119_DEFAULT_VLCD63 SSD2119_VLCD63_4V80 // Default value for VLCD63 voltage
#define SSD2119_DEFAULT_VCOML SSD2119_VCOML_0_72 // Default value for VcomL alternating drive voltage
#define SSD2119_DEFAULT_VCOMH 0x1A // Default value for VcomH=VLCD63*(0.35+0x1A*0.01)

#define SSD2119_DEFAULT_FLD 1 // Default value for driving waveform control
                              // FLD bit, splits one frame into 3 fields
                              // to reduce flicker

#define SSD2119_DEFAULT_FRAME_FREQ SSD2119_FRAME80 // Default value for
                                                   // LCD frame frequency
 
// Default initialization values for the gamma control register bits
#define SSD2119_DEFAULT_PKP00 7 // PKP00..PKP02 positive gamma micro adj.
#define SSD2119_DEFAULT_PKP10 7 // PKP10..PKP12 positive gamma micro adj.
#define SSD2119_DEFAULT_PKP20 4 // PKP20..PKP22 positive gamma micro adj.
#define SSD2119_DEFAULT_PKP30 2 // PKP30..PKP32 positive gamma micro adj.
#define SSD2119_DEFAULT_PKP40 4 // PKP40..PKP42 positive gamma micro adj.
#define SSD2119_DEFAULT_PKP50 2 // PKP50..PKP52 positive gamma micro adj.
#define SSD2119_DEFAULT_PRP00 2 // PRP00..PRP02 positive gamma gradient adj.
#define SSD2119_DEFAULT_PRP10 5 // PRP10..PRP12 positive gamma gradient adj.
#define SSD2119_DEFAULT_VRP00 2 // VRP00..VRP03 positive gamma amplification adj.
#define SSD2119_DEFAULT_VRP10 3 // VRP10..VRP14 positive gamma amplification adj.
#define SSD2119_DEFAULT_PKN00 7 // PKN00..PKN02 negative gamma micro adj.
#define SSD2119_DEFAULT_PKN10 5 // PKN10..PKN12 negative gamma micro adj.
#define SSD2119_DEFAULT_PKN20 4 // PKN20..PKN22 positive gamma micro adj.
#define SSD2119_DEFAULT_PKN30 2 // PKN30..PKN32 positive gamma micro adj.
#define SSD2119_DEFAULT_PKN40 4 // PKN40..PKN42 negative gamma micro adj.
#define SSD2119_DEFAULT_PKN50 2 // PKN50..PKN52 negative gamma micro adj.
#define SSD2119_DEFAULT_PRN00 2 // PRN00..PRN02 negative gamma gradient adj.
#define SSD2119_DEFAULT_PRN10 5 // PRN10..PRN12 negative gamma gradient adj.
#define SSD2119_DEFAULT_VRN00 2 // VRN00..VRN03 negative gamma amplification adj.
#define SSD2119_DEFAULT_VRN10 3 // VRN10..VRN14 negative gamma amplification adj.

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

// Writes a command to the SSD2119 controller.
void ssd2119_wrcmd(unsigned char cmd);
// Writes data to the SSD2119 controller.
void ssd2119_wrdata(unsigned short data);
// Reads a data word from the SSD2119 controller.
unsigned short ssd2119_rddata(void);
// Writes a word to a register of the SSD2119 controller.
void ssd2119_wrreg(unsigned char index, unsigned short data);
// Reads a word from a register of the SSD2119 controller.
unsigned short ssd2119_rdreg(unsigned char index);
        
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

#pragma library glcd_ssd2119.lib

#endif




