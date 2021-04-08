//*****************************************************************************
// Library functions for the FocalTech Systems FT5206, FT5306 and FT5406 
// capacitive touchscreen controllers
// (C) 2012-2015 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.20+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00
// 09032015_1 - Initial release.
//*****************************************************************************

/******************************************************************************
  FOR NON-XMEGA CHIPS THE TWI PERIPHERAL, USED FOR COMMUNICATION 
  WITH THE FT5206, FT5306, FT5406 CAPACITIVE CONTROLLERS, 
  MUST BE FIRST INITIALIZED AS IN THE EXAMPLE BELOW
  FOR THE ATmega2560 CHIP:
  
  #include <io.h>
  #include <iobits.h>
  #include <ft5x06.h>
  
  // TWI clock rate [bps]
  #define TWI_CLK_RATE 100000

  // Interrupt service routine called by the
  // falling edge of the /INT signal connected
  // to the INT4 external interrupt input (PORTE Pin 4)
  interrupt [EXT_INT4] void ext_int4_isr(void)
  {
  // Process the touchscreen controller's /INT signal interrupt
  ct_inthandler();
  }

  void main(void)
  {
  // Code to initialize the graphic display controller
  ...

  // Initialize the TWI in master mode
  twi_master_init(TWI_CLK_RATE/1000);
  
  // Code to initialize the external interrupt INT4 input
  // used to detect the falling edge of the
  // touchscreen controller's /INT signal

  // Ensure PORTE Pin 4 is an input
  CLRBIT(DDRE,4); 
  
  // INT4 Mode: Falling Edge
  EICRB=(1<<ISC41) | (0<<ISC40);
  EIMSK=(1<<INT4);
  // Clear the INT4 interrupt flag
  EIFR=(1<<INTF4); 

  // Enable interrupts
  #asm("sei")

  // Initialize the capacitive touchscreen controller
  ct_init();
  
  // Follows the rest of the program
  ...
  }
******************************************************************************/

/******************************************************************************
  FOR XMEGA CHIPS THE TWI PERIPHERAL, USED FOR COMMUNICATION 
  WITH THE FT5206, FT5306, FT5406 CAPACITIVE CONTROLLERS, 
  MUST BE FIRST INITIALIZED AS IN THE EXAMPLE BELOW:
  
  #include <io.h>
  #include <iobits.h>
  #include <ft5x06.h>
  
  // TWI clock rate [bps]
  #define TWI_CLK_RATE 100000

  // Structure that holds information used by the 
  // TWIC master peripheral for performing a TWI 
  // bus transaction
  TWI_MASTER_INFO_t twic_master;
  
  // Interrupt sevice routine for the TWIC peripheral in master mode
  interrupt [TWIC_TWIM_vect] void twic_master_isr(void)
  {
  twi_master_int_handler(&twic_master);
  }

  // PORTC interrupt 0 service routine
  interrupt [PORTC_INT0_vect] void portc_int0_isr(void)
  {
  // Process the touchscreen controller's /INT signal interrupt
  ct_inthandler();
  }

  void main(void)
  {
  unsigned char n;
  
  // Code to initialize the graphic display controller
  ...

  // General TWIC initialization:
  // no external driver interface
  // no SDA hold time
  twi_init(&TWIC,false,false);

  // Initialize the TWIC master
  // Uses the Low priority level interrupt 
  twi_master_init(&twic_master,&TWIC,TWI_MASTER_INTLVL_LO_gc,TWI_BAUD_REG(_MCU_CLOCK_FREQUENCY_,TWI_CLK_RATE));
  
  // Code to initialize the I/O PORTC interrupt,
  // used to detect the falling edge of the
  // touchscreen controller's /INT signal, 
  // connected to Pin 2
  
  // Set Pin2 as input
  CLRBIT(PORTC.DIR,2);
  // Pin2 Input/Sense configuration: Sense falling edge
  PORTC.PIN2CTRL=PORT_ISC_FALLING_gc;
  // Interrupt 0 level: Low
  // Interrupt 1 level: Disabled
  PORTC.INTCTRL=PORT_INT1LVL_OFF_gc | PORT_INT0LVL_LO_gc;
  // Pin2 Pin Change interrupt 0: On
  PORTC.INT0MASK=(1<<2);

  // Enable the Low priority level interrupt
  n=PMIC_LOLVLEN_bm;
  CCP=CCP_IOREG_gc;
  PMIC.CTRL=n;
    
  // Enable interrupts
  #asm("sei")

  // Initialize the capacitive touchscreen controller
  ct_init(&twic_master);
  
  // Follows the rest of the program
  ...
  }
******************************************************************************/

#ifndef _FT5X06_INCLUDED_
#define _FT5X06_INCLUDED_

#include <stdbool.h>

// TWI functions
#ifdef _ATXMEGA_DEVICE_
#include <twix.h>
#else
#include <twi.h>
#endif

// FT5X06 registers definitions for normal operating mode
#define CT_DEVICE_MODE 0x00
#define CT_GEST_ID 0x01   // Gesture ID
#define CT_TD_STATUS 0x02 // # of touch points

#define CT_TOUCH1_XH 0x03 // Bit[7]=1st event flag, Bits[3:0]=1st touch X position [11:8] 
#define CT_TOUCH1_XL 0x04 // 1st touch X position [7:0] 
#define CT_TOUCH1_YH 0x05 // Bits[4:7]=1st touch ID [3:0], Bits[3:0]=1st touch Y position [11:8] 
#define CT_TOUCH1_YL 0x06 // 1st touch Y position [7:0] 

#define CT_TOUCH2_XH 0x09 // Bit[7]=2nd event flag, Bits[3:0]=2nd touch X position [11:8] 
#define CT_TOUCH2_XL 0x0A // 2nd touch X position [7:0] 
#define CT_TOUCH2_YH 0x0B // Bits[4:7]=2nd touch ID [3:0], Bits[3:0]=2nd touch Y position [11:8] 
#define CT_TOUCH2_YL 0x0C // 2nd touch Y position [7:0] 

#define CT_TOUCH3_XH 0x0F // Bit[7]=3rd event flag, Bits[3:0]=3rd touch X position [11:8] 
#define CT_TOUCH3_XL 0x10 // 3rd touch X position [7:0] 
#define CT_TOUCH3_YH 0x11 // Bits[4:7]=3rd touch ID [3:0], Bits[3:0]=3rd touch Y position [11:8] 
#define CT_TOUCH3_YL 0x12 // 3rd touch Y position [7:0] 

#define CT_TOUCH4_XH 0x15 // Bit[7]=4th event flag, Bits[3:0]=4th touch X position [11:8] 
#define CT_TOUCH4_XL 0x16 // 4th touch X position [7:0] 
#define CT_TOUCH4_YH 0x17 // Bits[4:7]=4th touch ID [3:0], Bits[3:0]=4th touch Y position [11:8] 
#define CT_TOUCH4_YL 0x18 // 4th touch Y position [7:0] 

#define CT_TOUCH5_XH 0x1B // Bit[7]=5th event flag, Bits[3:0]=5th touch X position [11:8] 
#define CT_TOUCH5_XL 0x1C // 5th touch X position [7:0] 
#define CT_TOUCH5_YH 0x1D // Bits[4:7]=5th touch ID [3:0], Bits[3:0]=5th touch Y position [11:8] 
#define CT_TOUCH5_YL 0x1E // 5th touch Y position [7:0] 

#define CT_ID_G_THGROUP 0x80 // Valid touching detect threshold
#define CT_ID_G_THPEAK 0x81  // Valid touching peak detect threshold
#define CT_ID_G_THCAL 0x82   // Threshold when calculating the focus of touching
#define CT_ID_G_THWATER 0x83 // Threshold when there's surface water
#define CT_ID_G_THTEMP 0x84  // Threshold of temperature compensation
#define CT_ID_G_THDIFF 0x85  // Threshold whether the coordinate is different from the original
#define CT_ID_G_CTRL 0x86    // Power control mode [1:0]
#define CT_ID_G_TIME_ENTER_MONITOR 0x87 // Timer of entering monitor status
#define CT_ID_G_PERIOD_ACTIVE 0x88  // Active Period [3:0]
#define CT_ID_G_PERIOD_MONITOR 0x89 // Timer of entering idle while in monitor status

#define CT_ID_G_AUTO_CLB_MODE 0xA0  // Auto calibration mode
#define CT_ID_G_LIB_VERSION_H 0xA1  // Firmware version high byte
#define CT_ID_G_LIB_VERSION_L 0xA2  // Firmware version low byte
#define CT_ID_G_CIPHER 0xA3    // Chip vendor ID
#define CT_ID_G_MODE 0xA4      // Interrupt status to host
#define CT_ID_G_PMODE 0xA5     // Power consuming mode
#define CT_ID_G_FIRMID 0xA6    // Firmware ID
#define CT_ID_G_STATE 0xA7     // Running state
#define CT_ID_G_FT5201ID 0xA8  // CTPM Vendor ID
#define CT_ID_G_ERR 0xA9       // Error code
#define CT_ID_G_CLB 0xAA       // Configure TP during calibration in test mode

#define CT_ID_G_B_AREA_TH 0xAE // Threshold of large area

#define CT_LOG_MSG_CNT 0xFE    // Log message count
#define CT_LOG_CUR_CHA 0xFF    // Current character of log message 
                               // After one char. is read, will point to the next char.

// Codes for touchscreen gestures detected by the controller
#define CT_GESTURE_NONE 0x00
#define CT_GESTURE_MOVE_UP 0x10
#define CT_GESTURE_MOVE_DOWN 0x18
#define CT_GESTURE_MOVE_LEFT 0x14
#define CT_GESTURE_MOVE_RIGHT 0x1C
#define CT_GESTURE_ZOOM_IN 0x48
#define CT_GESTURE_ZOOM_OUT 0x49

// Return code for capacitive touchscreen controller functions
#define CT_RESULT_NO_INIT -1 // The controller was not initilized

// Structure that holds the display screen coordinates of a touched point
typedef struct
{ 
unsigned short x;
unsigned short y;
} CTPOINT_t;

// Structure that holds the touched point data read from the controller
typedef struct
{
unsigned char touched_points:3; // number of simultaneously touched points 
                                // stored in the point buffer
unsigned char new_touch:1; // signal that a new touch occured
                           // since the last read from the point buffer
CTPOINT_t point[5]; // buffer with touched point display coordinates 
} CTSTATUS_t;

extern CTSTATUS_t ct_status;

// Writes a byte of data to the capacitive controller register
void ct_wrreg(unsigned char reg, unsigned char data);
// Reads a byte of data from the capacitive controller register
unsigned char ct_rdreg(unsigned char reg);
// Function to be called when the capacitive touchscreen 
// controller's /INT signal becomes active (high to low transition)
void ct_inthandler(void);
// Initialize the capacitive touchscreen controller
#ifdef _ATXMEGA_DEVICE_
bool ct_init(TWI_MASTER_INFO_t *twi_master);
#else
bool ct_init(void);
#endif
// Waits for the screen to be touched and returns the 
// xd, yd display coordinates of the first point
signed char ct_getxy(unsigned short *xd, unsigned short *yd);
// Check if the screen was touched and returns the 
// xd, yd display coordinates of the first point
signed char ct_getxynw(unsigned short *xd, unsigned short *yd);
// Waits for the screen to be touched and returns the 
// display coordinates of the touched points
signed char ct_getpoints(CTPOINT_t *points);
// Check if the screen was touched and returns the 
// display coordinates of the touched points
signed char ct_getpointsnw(CTPOINT_t *points);

#pragma library ft5x06.lib

#endif
