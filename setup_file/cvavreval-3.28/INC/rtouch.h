//*****************************************************************************
// Library functions for resistive touchscreen controllers
// (C) 2012-2013 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.05+
// Version: 1.00
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00
// 31082012_1 - Initial release.
//*****************************************************************************

#ifndef _RTOUCH_INCLUDED_
#define _RTOUCH_INCLUDED_

#include <stdbool.h>

// Resistive touchscreen controller connection modes for rt_init
#define RTOUCH_MODE_DIFFERENTIAL false
#define RTOUCH_MODE_SINGLE_ENDED true

typedef struct
{ 
unsigned short x;
unsigned short y;
} RTPOINT_t;

// Calibration points coordinates
typedef struct
{
RTPOINT_t left_top; // screen horizontal left-vertical top point
RTPOINT_t right_center; // screen horizontal right-vertical center point
RTPOINT_t center_bottom; // screen horizontal center-vertical bottom point
} RTCALP_t;

// Signal that the screen was touched and the coordinates
// can be read using the rt_getxy function 
extern bit rt_touched;

// Initialize the resistive touchscreen controller
bool rt_init(bool single_ended);
// Function that needs to be called every 10ms by a timer interrupt
// in order to sense the state of the /PENIRQ output of the touch screen controller
void rt_timerproc(void);
// Calibrate the resistive touchscreen controller
// touchscreen - points to the structure that holds the values read by the
//               toouchscreen controller for the display coordinates
//               stored in the structure pointed by display
// display     - points to the structure that holds the coordinates of
//               the calibration points to be displayed
bool rt_calibrate(RTCALP_t *touchscreen, flash RTCALP_t *display);
// Waits for the screen to be touched and returns the xt, yt touchscreen values
// read from the controller
void rt_readctrl(unsigned short *xt, unsigned short *yt);
// Waits for the screen to be touched and returns the xd, yd display coordinates
// calculated using the calibration data
bool rt_getxy(unsigned short *xd, unsigned short *yd);

#ifdef _RT_CTRL_ADS7846_
// Reads the temperature in °C using the ADS7846 controller
short rt_readtemp(void);
// Reads the battery voltage [mV] on Vbat input of the ADS7846 controller
unsigned short rt_readvbat(void);
#endif

#pragma library rtouch.lib

#endif
