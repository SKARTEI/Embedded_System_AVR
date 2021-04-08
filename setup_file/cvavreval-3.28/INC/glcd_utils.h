//*****************************************************************************
// Utility library functions for graphic LCDs
// (C) 2010-2011 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V2.05.3+
// Version: 1.01
//*****************************************************************************

//*****************************************************************************
// Revision history:
// 
// V1.00      Initial release.
// 
// V1.01
// 06072011_2 Added GLCD_CLEARBLOCK and GLCD_SETBLOCK modes to the 
//            glcd_mappixcolor1bit function.
//            These are required by the modified glcd_putchar and glcd_block
//            functions.
//*****************************************************************************

#ifndef _GLCD_UTILS_INCLUDED_
#define _GLCD_UTILS_INCLUDED_

#include <glcd_types.h>

// Holds the bit masks for pixel lengths: 0..8
extern flash unsigned char _glcd_mask[9];

// Returns the byte mask needed to select a line of pixels.
unsigned char glcd_getmask(unsigned char offset, unsigned char length);
// Helper function for GLCD_PUTCHAR, GLCD_PUTFILL, GLCD_CLEARBLOCK and 
// GLCD_SETBLOCK modes for 1bit/pixel displays.
// Returns the color of a group of 8 vertical pixels based on the color
// settings of a specific block display mode.
unsigned char glcd_mappixcolor1bit(unsigned char data, GLCDBLOCKMODE_t mode);
// Reads a byte from a specified memory type.
unsigned char glcd_readmem(GLCDMEM_t memt, unsigned long addr);
// Writes a byte to a specified memory type.
void glcd_writemem(GLCDMEM_t memt, GLCDMEMADDR_t addr, unsigned char data);
// Returns data with bits in reversed order.
unsigned char glcd_revbits(unsigned char data);

#pragma library glcd_utils.lib

#endif
