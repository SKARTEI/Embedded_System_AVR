//*****************************************************************************
// Library functions for color TFT graphic LCDs with the
// Ilitek ILI9328 controller
// (C) 2010-2014 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.15+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
//
// V1.00
// 15092014_1 - Initial release.
//*****************************************************************************

#ifndef _GLCD_ILI9328_INCLUDED_
#define _GLCD_ILI9328_INCLUDED_

#include <glcd_types.h>

// Use fast horizontal & vertical line drawing functions.
#define _GLCD_FAST_LINEH_
#define _GLCD_FAST_LINEV_

// ILI9328 controller ID
#define ILI9328_CTRL_ID 0x9328

// ILI9328 command register definitions
#define ILI9328_CMD_OSC 0x00 // Oscillator register
// Osc. register commands
#define ILI9328_STOP_OSC 0  // Stop oscillator
#define ILI9328_START_OSC 1 // Start oscillator

#define ILI9328_CMD_DRIVER_OUT 0x01 // Driver output control
// Driver output control bits positions
#define ILI9328_SS_BIT 8 // SS bit pos. selects the output
                         // shift direction of source driver
#define ILI9328_SM_BIT 10  // SM bit pos. gate scan sequence interlaced or not

#define ILI9328_CMD_DRIVING_WAVEFORM 0x02 // LCD driving waveform control
// Driving waveform control bits positions
#define ILI9328_BC_BIT 9 // =0 select frame/field inversion
                         // =1 select line inversion
#define ILI9328_EOR_BIT 8 // EOR=1 and BC=1 set line inversion
                          // EOR=1 and BC=0 set frame/field inversion

#define ILI9328_CMD_ENTRY_MODE 0x03 // Entry mode control
#define ILI9328_TRI_BIT 15 // TRI =1 data is transfered in 3 transfers
                           // through the 8-bit interface
#define ILI9328_DFM_BIT 14 // DFM bit
#define ILI9328_BGR_BIT 12 // =0 RGB bit order when writing pixel data
                           // =1 BGR bit order when writing pixel data
#define ILI9328_ORG_BIT 7  // ORG bit =0 origin not moved
                           // =1 origin moves according to ID10
#define ILI9328_ID1_BIT 5  // ID10 bits control AC increase/decrease
#define ILI9328_ID0_BIT 4  // after updating pixel data
#define ILI9328_AM_BIT 3 // AM bit =0 address is updated in horizontal wrting dir.
                         // =1 address is update in vertical writing direction

#define ILI9328_RESIZE_CONTROL 0x04 // Resizing control register

#define ILI9328_CMD_DISPLAY_CONTROL1 0x07 // Display control register 1
// Display control register bit positions
#define ILI9328_PTDE1_BIT 13
#define ILI9328_PTDE0_BIT 12
#define ILI9328_BASEE_BIT 8
#define ILI9328_GON_BIT 5
#define ILI9328_DTE_BIT 4
#define ILI9328_CL_BIT 3
#define ILI9328_D1_BIT 1
#define ILI9328_D0_BIT 0

#define ILI9328_CMD_DISPLAY_CONTROL2 0x08 // Display control register 2
#define ILI9328_CMD_DISPLAY_CONTROL3 0x09 // Display control register 3
#define ILI9328_CMD_DISPLAY_CONTROL4 0x0a // Display control register 4

#define ILI9328_CMD_RGB_IF_CONTROL1 0x0c // RGB display interface control register 1
// Display interface control register bit positions
#define ILI9328_ENC2_BIT 14 // Set the GRAM write cycle through the RGB interface
#define ILI9328_ENC1_BIT 13
#define ILI9328_ENC0_BIT 12
#define ILI9328_RM_BIT 8 // =0 access the GRAM using the system interface
                         // =1 access the GRAM using the RGB interface
#define ILI9328_DM1_BIT 5 // Select the display operating mode:
#define ILI9328_DM0_BIT 4 // =00 internal system clock
                          // =01 RGB interface
                          // =10 VSYNC interface
#define ILI9328_RIM1_BIT 1 // Select the RGB interface data width:
#define ILI9328_RIM0_BIT 0 // =00 18bit, =01 16bit, =10 6bit

#define ILI9328_FRAME_MARKER_POS 0x0d // Frame marker position
#define ILI9328_CMD_RGB_IF_CONTROL2 0x0f // RGB display interface control register 2

#define ILI9328_CMD_POWER_CONTROL1 0x10 // Power control 1 register
// Power control 1 register bits positions
#define ILI9328_SAP_BIT 12 // SAP source driver output control
                           // =1 enabled
#define ILI9328_BT2_BIT 10 // BT0..2 controls the step-up factor
#define ILI9328_BT1_BIT 9  // of the step-up circuit
#define ILI9328_BT0_BIT 8
#define ILI9328_APE_BIT 7  // APE power supply enable bit
#define ILI9328_AP2_BIT 6 // AP0..2 adjusts the amount of current
#define ILI9328_AP1_BIT 5 // from the constant current source in the
#define ILI9328_AP0_BIT 4 // internal op. amplifier circuit
#define ILI9328_DSTB_BIT 2 // Enters deep standby mode
#define ILI9328_SLP_BIT 1 // Enters sleep mode
#define ILI9328_STB_BIT 0 // Enters standby mode

#define ILI9328_CMD_POWER_CONTROL2 0x11 // Power control 2 register
// Power control 2 register bits positions
#define ILI9328_DC12_BIT 10 // step-up circuit 2 operating frequency
#define ILI9328_DC11_BIT 9
#define ILI9328_DC10_BIT 8
#define ILI9328_DC02_BIT 6 // step-up circuit 1 operating frequency
#define ILI9328_DC01_BIT 5
#define ILI9328_DC00_BIT 4
#define ILI9328_VC2_BIT 2 // ratio factor of Vci1 to generate the
#define ILI9328_VC1_BIT 1 // reference voltage
#define ILI9328_VC0_BIT 0

#define ILI9328_CMD_POWER_CONTROL3 0x12 // Power control 3 register
// Power control 3 register bits positions
#define ILI9328_VCIRE_BIT 7 // VCIRE =0 external ref. voltage Vci
                            // =1 internal ref. voltage 2.5V
#define ILI9328_PON_BIT 4 // PON =0 VGL output disabled
                          // =1 VGL output enabled
#define ILI9328_VRH3_BIT 3 // VRH3..0 sets the multiplication
#define ILI9328_VRH2_BIT 2 // factor of Vci applied to the VREG1OUT
#define ILI9328_VRH1_BIT 1
#define ILI9328_VRH0_BIT 0

#define ILI9328_CMD_POWER_CONTROL4 0x13 // Power control 4 register
// Power control 4 register bits positions
#define ILI9328_VDV0_BIT 8 // VDV0 bit pos. sets the alternating amplitudes
                           // of Vcom voltage based on VREG1OUT

#define ILI9328_CMD_GDDRAMX 0x20 // Set GRAM X address counter register
#define ILI9328_CMD_GDDRAMY 0x21 // Set GRAM Y address counter register
#define ILI9328_CMD_GDDRAM_DATA 0x22 // GRAM read/write data register

#define ILI9328_CMD_POWER_CONTROL7 0x29 // Power control 7 register

#define ILI9328_CMD_FRAME_RATE 0x2b // Frame rate frequency control register

#define ILI9328_CMD_GAMMA_CONTROL1 0x30 // Gamma control 1
// Gamma control 1 bit positions
#define ILI9328_KP00_BIT 0
#define ILI9328_KP10_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL2 0x31 // Gamma control 2
// Gamma control 2 bit positions
#define ILI9328_KP20_BIT 0
#define ILI9328_KP30_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL3 0x32 // Gamma control 3
// Gamma control 3 bit positions
#define ILI9328_KP40_BIT 0
#define ILI9328_KP50_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL4 0x35 // Gamma control 4
// Gamma control 4 bit positions
#define ILI9328_RP00_BIT 0
#define ILI9328_RP10_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL5 0x36 // Gamma control 5
// Gamma control 5 bit positions
#define ILI9328_VRP00_BIT 0
#define ILI9328_VRP10_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL6 0x37 // Gamma control 6
// Gamma control 6 bit positions
#define ILI9328_KN00_BIT 0
#define ILI9328_KN10_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL7 0x38 // Gamma control 7
// Gamma control 7 bit positions
#define ILI9328_KN20_BIT 0
#define ILI9328_KN30_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL8 0x39 // Gamma control 8
// Gamma control 8 bit positions
#define ILI9328_KN40_BIT 0
#define ILI9328_KN50_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL9 0x3c // Gamma control 9
// Gamma control 9 bit positions
#define ILI9328_RN00_BIT 0
#define ILI9328_RN10_BIT 8

#define ILI9328_CMD_GAMMA_CONTROL10 0x3d // Gamma control 10
// Gamma control 10 bit positions
#define ILI9328_VRN00_BIT 0
#define ILI9328_VRN10_BIT 8

#define ILI9328_CMD_HORIZ_RAM_ADDR_START 0x50 // Address of horizontal start window positions
#define ILI9328_CMD_HORIZ_RAM_ADDR_END 0x51 // Address of horizontal end window positions
#define ILI9328_CMD_VERT_RAM_ADDR_START 0x52 // Address of vertical start window positions
#define ILI9328_CMD_VERT_RAM_ADDR_END 0x53 // Address of vertical end window positions
#define ILI9328_CMD_DRIVER_OUT_CONTROL2 0x60 // Driver output control
// Driver output control bits
#define ILI9328_GS_BIT 15 // GS =0 gate scans from 1->320
                          // =1 gate scans from 320->1
#define ILI9328_NL0_BIT 8 // NL0..5, # of LCD lines/8-1
#define ILI9328_SCN0_BIT 0 // SCN0..5

#define ILI9328_CMD_BASE_IMG_DISPLAY_CONTROL 0x61 // Base image display control
// Base image display control bits
#define ILI9328_NDL_BIT 2 // NDL driver output level for non-displayed area
#define ILI9328_VLE_BIT 1 // VLE vertical scroll enable
#define ILI9328_REV_BIT 0 // REV enable image grayscale inversion

#define ILI9328_CMD_VERT_SCROLL_CONTROL 0x6a // Vertical scroll control
#define ILI9328_CMD_PARTIAL_IMG1_DISPLAY_POS 0x80 // Partial image 1 display position
#define ILI9328_CMD_PARTIAL_IMG1_START_LINE 0x81 // Partial image 1 display start line
#define ILI9328_CMD_PARTIAL_IMG1_END_LINE 0x82 // Partial image 1 display end line
#define ILI9328_CMD_PARTIAL_IMG2_DISPLAY_POS 0x83 // Partial image 2 display position
#define ILI9328_CMD_PARTIAL_IMG2_START_LINE 0x84 // Partial image 2 display start line
#define ILI9328_CMD_PARTIAL_IMG2_END_LINE 0x85 // Partial image 2 display end line
#define ILI9328_CMD_PANEL_IF_CONTROL1 0x90 // Panel interface control 1
// Panel interface control 1 bits
#define ILI9328_DIVI1_BIT 9 // DIVI0..1 sets the division ratio of internal clock frequency
#define ILI9328_DIVI0_BIT 8
#define ILI9328_RTNI0_BIT 0

#define ILI9328_CMD_PANEL_IF_CONTROL2 0x92 // Panel interface control 2
// Panel interface control 2 bits
#define ILI9328_NOW0_BIT 8

#define ILI9328_CMD_PANEL_IF_CONTROL4 0x95 // Panel interface control 4
#define ILI9328_CMD_OTP_VCM_PROG_CONTROL 0xA1 // OTP VCM programming control
#define ILI9328_CMD_OTP_VCM_STATUS_ENABLE 0xA2 // OTP VCM status and enable
#define ILI9328_CMD_OTP_PGM_ID_KEY 0xA5 // OTP programming ID key

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
        // power control registers bits
        unsigned char stepup_factor:3; // step-up factor of the step-up circuit
                                       // see BT0..BT2 bits in the datasheet
        unsigned char stepup_freq1:3;  // controls the frequency for the step-up circuit 1
        unsigned char stepup_freq2:3;  // controls the frequency for the step-up circuit 2
        unsigned char crt_source:3; // adjusts the amount of current
                                    // from the constant current source in the
                                    // internal op. amplifier circuit (AP0..AP2 bits)
        unsigned char vreg1out:4;  // adjusts the VREG1OUT voltage
        unsigned char vcom:5;  // adjusts the amplitude of the Vcom alternating
                               // drive voltage based on VREG1OUT voltage
        unsigned char vcomh:6;  // adjusts the amplitude of the VcomH drive voltage
                                // based on VREG1OUT voltage
                                // VcomH=VREG1OUT*(vcomh*0.005+0.685) [V]
        unsigned char frame_freq:4; // LCD frame frequency
        // positive gamma control registers bits
        unsigned char kp00:3; // KP00..KP02 positive gamma micro adj.
        unsigned char kp10:3; // KP10..KP12 positive gamma micro adj.
        unsigned char kp20:3; // KP20..KP22 positive gamma micro adj.
        unsigned char kp30:3; // KP30..KP32 positive gamma micro adj.
        unsigned char kp40:3; // KP40..KP42 positive gamma micro adj.
        unsigned char kp50:3; // KP50..KP52 positive gamma micro adj.
        unsigned char rp00:3; // RP00..RP02 positive gamma gradient adj.
        unsigned char rp10:3; // RP10..RP12 positive gamma gradient adj.
        unsigned char vrp00:4; // VRP00..VRP03 positive gamma amplification adj.
        unsigned char vrp10:5; // VRP10..VRP14 positive gamma amplification adj.
        // negative gamma control registers bits
        unsigned char kn00:3; // KN00..KN02 negative gamma micro adj.
        unsigned char kn10:3; // KN10..KN12 negative gamma micro adj.
        unsigned char kn20:3; // KN20..KN22 positive gamma micro adj.
        unsigned char kn30:3; // KN30..KN32 positive gamma micro adj.
        unsigned char kn40:3; // KN40..KN42 negative gamma micro adj.
        unsigned char kn50:3; // KN50..KN52 negative gamma micro adj.
        unsigned char rn00:3; // RN00..RN02 negative gamma gradient adj.
        unsigned char rn10:3; // RN10..RN12 negative gamma gradient adj.
        unsigned char vrn00:4; // VRN00..VRN03 negative gamma amplification adj.
        unsigned char vrn10:5; // VRN10..VRN14 negative gamma amplification adj.
        } GLCDINIT_t;

// Initialization values for reverse_x
#define ILI9328_REVX_NORM 0 // No horizontal reverse
#define ILI9328_REVX_REV 1 // Horizontal reverse

// Initialization values for reverse_y
#define ILI9328_REVY_NORM 0 // No vertical reverse
#define ILI9328_REVY_REV 1 // Vertical reverse

// Initialization values for cl_bits_order
#define ILI9328_CL_BITS_RGB 0 // Write color bits to display RAM in RGB order
#define ILI9328_CL_BITS_BGR 1 // Write color bits to display RAM in BGR order

// Initialization values for the VREG1OUT voltage
#define ILI9328_VREG1OUT_4V000 8 // 4.000 V
#define ILI9328_VREG1OUT_4V125 9 // 4.125 V
#define ILI9328_VREG1OUT_4V250 10 // 4.250 V
#define ILI9328_VREG1OUT_4V375 11 // 4.375 V
#define ILI9328_VREG1OUT_4V500 12 // 4.500 V
#define ILI9328_VREG1OUT_4V625 13 // 4.625 V
#define ILI9328_VREG1OUT_4V750 14 // 4.750 V
#define ILI9328_VREG1OUT_4V875 15 // 4.875 V
#define ILI9328_VREG1OUT_5V000 1 // 5.000 V
#define ILI9328_VREG1OUT_5V125 2 // 5.125 V
#define ILI9328_VREG1OUT_5V250 3 // 5.250 V
#define ILI9328_VREG1OUT_5V500 4 // 5.500 V
#define ILI9328_VREG1OUT_5V750 5 // 5.750 V
#define ILI9328_VREG1OUT_6V000 6 // 6.000 V

// Initialization values for the Vcom voltage
#define ILI9328_VCOM_0_70 0 // Vcom=VREG1OUT*0.70
#define ILI9328_VCOM_0_72 1 // Vcom=VREG1OUT*0.72
#define ILI9328_VCOM_0_74 2 // Vcom=VREG1OUT*0.74
#define ILI9328_VCOM_0_76 3 // Vcom=VREG1OUT*0.76
#define ILI9328_VCOM_0_78 4 // Vcom=VREG1OUT*0.78
#define ILI9328_VCOM_0_80 5 // Vcom=VREG1OUT*0.80
#define ILI9328_VCOM_0_82 6 // Vcom=VREG1OUT*0.82
#define ILI9328_VCOM_0_84 7 // Vcom=VREG1OUT*0.84
#define ILI9328_VCOM_0_86 8 // Vcom=VREG1OUT*0.86
#define ILI9328_VCOM_0_88 9 // Vcom=VREG1OUT*0.88
#define ILI9328_VCOM_0_90 10 // Vcom=VREG1OUT*0.90
#define ILI9328_VCOM_0_92 11 // Vcom=VREG1OUT*0.92
#define ILI9328_VCOM_0_94 12 // Vcom=VREG1OUT*0.94
#define ILI9328_VCOM_0_96 13 // Vcom=VREG1OUT*0.96
#define ILI9328_VCOM_0_98 14 // Vcom=VREG1OUT*0.98
#define ILI9328_VCOM_1_00 15 // Vcom=VREG1OUT*1.00
#define ILI9328_VCOM_1_02 0x14 // Vcom=VREG1OUT*1.02
#define ILI9328_VCOM_1_04 0x15 // Vcom=VREG1OUT*1.04
#define ILI9328_VCOM_1_06 0x16 // Vcom=VREG1OUT*1.06
#define ILI9328_VCOM_1_08 0x17 // Vcom=VREG1OUT*1.08
#define ILI9328_VCOM_1_10 0x18 // Vcom=VREG1OUT*1.10
#define ILI9328_VCOM_1_12 0x19 // Vcom=VREG1OUT*1.12
#define ILI9328_VCOM_1_14 0x1A // Vcom=VREG1OUT*1.14
#define ILI9328_VCOM_1_16 0x1B // Vcom=VREG1OUT*1.16
#define ILI9328_VCOM_1_18 0x1C // Vcom=VREG1OUT*1.18
#define ILI9328_VCOM_1_20 0x1D // Vcom=VREG1OUT*1.20
#define ILI9328_VCOM_1_22 0x1E // Vcom=VREG1OUT*1.22
#define ILI9328_VCOM_1_24 0x1F // Vcom=VREG1OUT*1.24

// Initialization value for VcomH
// VcomH=VREG1OUT*(VREG1OUT_MULT1000/1000)
// VREG1OUT_MULT1000=685..1000
#define ILI9328_VCOMH(VREG1OUT_MULT1000) ((VREG1OUT_MULT1000-685)/5)

// Initialization values for stepup_freq1
#define ILI9328_STEPUP1_FOSC 0 // FDCDC1=Fosc
#define ILI9328_STEPUP1_FOSC2 1 // FDCDC1=Fosc/2
#define ILI9328_STEPUP1_FOSC4 2 // FDCDC1=Fosc/4
#define ILI9328_STEPUP1_FOSC8 3 // FDCDC1=Fosc/8
#define ILI9328_STEPUP1_FOSC16 4 // FDCDC1=Fosc/16
#define ILI9328_STEPUP1_FOSC32 5 // FDCDC1=Fosc/32
#define ILI9328_STEPUP1_FOSC64 6 // FDCDC1=Fosc/64
#define ILI9328_STEPUP1_HALT 7 // Halt step-up circuit 1

// Initialization values for stepup_freq2
#define ILI9328_STEPUP2_FOSC4 0 // FDCDC2=Fosc/4
#define ILI9328_STEPUP2_FOSC8 1 // FDCDC2=Fosc/8
#define ILI9328_STEPUP2_FOSC16 2 // FDCDC2=Fosc/16
#define ILI9328_STEPUP2_FOSC32 3 // FDCDC2=Fosc/32
#define ILI9328_STEPUP2_FOSC64 4 // FDCDC2=Fosc/64
#define ILI9328_STEPUP2_FOSC128 5 // FDCDC2=Fosc/128
#define ILI9328_STEPUP2_FOSC256 6 // FDCDC2=Fosc/256
#define ILI9328_STEPUP2_HALT 7 // Halt step-up circuit 2

// Initialization values for frame_freq
#define ILI9328_FRAME40 0 // 40Hz
#define ILI9328_FRAME43 1 // 43Hz
#define ILI9328_FRAME45 2 // 45Hz
#define ILI9328_FRAME48 3 // 48Hz
#define ILI9328_FRAME51 4 // 51Hz
#define ILI9328_FRAME55 5 // 55Hz
#define ILI9328_FRAME59 6 // 59Hz
#define ILI9328_FRAME64 7 // 64Hz
#define ILI9328_FRAME70 8 // 70Hz
#define ILI9328_FRAME77 9 // 77Hz
#define ILI9328_FRAME85 10 // 85Hz
#define ILI9328_FRAME96 11 // 96Hz
#define ILI9328_FRAME110 12 // 110Hz
#define ILI9328_FRAME128 13 // 128Hz

// Default value for reverse_x
#define ILI9328_DEFAULT_REVX ILI9328_REVX_NORM // No horizontal reverse
// Default value for reverse_y
#define ILI9328_DEFAULT_REVY ILI9328_REVY_NORM // No vertical reverse
// Default value for cl_bits_order (color bits writing order to display RAM)
#define ILI9328_DEFAULT_CL_BITS ILI9328_CL_BITS_RGB // write in RGB order
// Power control 1 BT0..BT2 step-up factor of the step-up circuit
// DDVDH=Vci1*2, VCL=-Vci1, VGH=Vci1*6, VGL=-Vci1*3
#define ILI9328_DEFAULT_STEPUP_FACTOR 2
// Power control 1 AP0..AP2 adjusts the amount of current
// from the constant current source in the
// internal op. amplifier circuit
#define ILI9328_DEFAULT_CRT_SOURCE 2
// Power control 2 DC00..DC02 step-up circuit 1 frequency
#define ILI9328_DEFAULT_STEPUP1_FREQ ILI9328_STEPUP1_FOSC4
// Power control 2 DC10..DC12 step-up circuit 2 frequency
#define ILI9328_DEFAULT_STEPUP2_FREQ ILI9328_STEPUP2_FOSC128
// Default value for VREG1OUT voltage
#define ILI9328_DEFAULT_VREG1OUT ILI9328_VREG1OUT_4V000
// Default value for Vcom alternating drive voltage
#define ILI9328_DEFAULT_VCOM ILI9328_VCOM_1_08
// Default value for VcomH voltage
// VcomH=VREG1OUT*0.815
#define ILI9328_DEFAULT_VCOMH ILI9328_VCOMH(815)
// Default value for LCD frame frequency
#define ILI9328_DEFAULT_FRAME_FREQ ILI9328_FRAME96

// Default initialization values for the gamma control register bits
#define ILI9328_DEFAULT_KP00 7 // KP00..KP02 positive gamma micro adj.
#define ILI9328_DEFAULT_KP10 7 // KP10..KP12 positive gamma micro adj.
#define ILI9328_DEFAULT_KP20 4 // KP20..KP22 positive gamma micro adj.
#define ILI9328_DEFAULT_KP30 2 // KP30..KP32 positive gamma micro adj.
#define ILI9328_DEFAULT_KP40 4 // KP40..KP42 positive gamma micro adj.
#define ILI9328_DEFAULT_KP50 2 // KP50..KP52 positive gamma micro adj.
#define ILI9328_DEFAULT_RP00 2 // RP00..RP02 positive gamma gradient adj.
#define ILI9328_DEFAULT_RP10 5 // RP10..RP12 positive gamma gradient adj.
#define ILI9328_DEFAULT_VRP00 2 // VRP00..VRP03 positive gamma amplification adj.
#define ILI9328_DEFAULT_VRP10 3 // VRP10..VRP14 positive gamma amplification adj.
#define ILI9328_DEFAULT_KN00 7 // KN00..KN02 negative gamma micro adj.
#define ILI9328_DEFAULT_KN10 5 // KN10..KN12 negative gamma micro adj.
#define ILI9328_DEFAULT_KN20 4 // KN20..KN22 positive gamma micro adj.
#define ILI9328_DEFAULT_KN30 2 // KN30..KN32 positive gamma micro adj.
#define ILI9328_DEFAULT_KN40 4 // KN40..KN42 negative gamma micro adj.
#define ILI9328_DEFAULT_KN50 2 // KN50..KN52 negative gamma micro adj.
#define ILI9328_DEFAULT_RN00 2 // RN00..RN02 negative gamma gradient adj.
#define ILI9328_DEFAULT_RN10 5 // RN10..RN12 negative gamma gradient adj.
#define ILI9328_DEFAULT_VRN00 2 // VRN00..VRN03 negative gamma amplification adj.
#define ILI9328_DEFAULT_VRN10 3 // VRN10..VRN14 negative gamma amplification adj.

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

// Writes a command to the ILI9328 controller.
void ili9328_wrcmd(unsigned char cmd);
// Writes data to the ILI9328 controller.
void ili9328_wrdata(unsigned short data);
// Reads a data word from the ILI9328 controller.
unsigned short ili9328_rddata(void);
// Writes a word to a register of the ILI9328 controller.
void ili9328_wrreg(unsigned char index, unsigned short data);
// Reads a word from a register of the ILI9328 controller.
unsigned short ili9328_rdreg(unsigned char index);

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

#pragma library glcd_ili9328.lib

#endif




