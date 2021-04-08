/*-----------------------------------------------------------------------
/  Low level disk interface module include file  R0.05   (C)ChaN, 2007
/-----------------------------------------------------------------------*/

/**************************************************************************
Modified and optimized for the CodeVisionAVR V3.09+ C Compiler
by Pavel Haiduc, HP InfoTech s.r.l. (C) 2009-2014

V1.0 - 1/07/2009, Initial release
V1.1 - 16/09/2009, Added ATxmega support
V1.2 - 25012010_1: Added the possibility to use slower SPI clock
       for better compatibility with poor designs
     - 16022010_1: Added the possibility to use an active low WP signal
V1.3 - 01062010_1: Modified the ATxmega initialization so that the MISO
       pin will use Pull-Up on input
V1.4 - 02022012_2: Modified to allow SD card sockets without a CD signal
       to be used
     - 02022012_3: Added the sdcard_present function to check if a
       card is inserted when the CD card socket signal is not used
     - 02022012_4: Added verification of the CRC of CSD and CID when
       calling the disk_ioctl function with MMC_GET_CSD and MMC_GET_CID
       commands
V1.5 - 03062012_1: Modified to allow any polarity for the WP and CD signals
       and also disabling their usage if needed
       05062012_1: Fixed a bug in the sdcard_present function that
       prevented detecting the presence of some SD cards when the
       /CD signal was not used
V1.6 - 07012014_1: Fixed, not working with ATxmega E5 chips.
**************************************************************************/

#ifndef __SDCARD_INCLUDED__
#define __SDCARD_INCLUDED__

#include <stdbool.h>

/* Status of Disk Functions */
typedef unsigned char DSTATUS;

/* Results of Disk Functions */
typedef enum
        {
        RES_OK = 0,		/* 0: Successful */
	    RES_ERROR,		/* 1: R/W Error */
	    RES_WRPRT,		/* 2: Write Protected */
	    RES_NOTRDY,		/* 3: Not Ready */
	    RES_PARERR		/* 4: Invalid Parameter */
        } DRESULT;

/*---------------------------------------*/
/* Prototypes for disk control functions */

DSTATUS disk_initialize (unsigned char drv);
DSTATUS disk_status (unsigned char drv);
DRESULT disk_read (unsigned char drv, unsigned char* buff, unsigned long sector, unsigned char count);
DRESULT disk_write (unsigned char drv, unsigned char* buff, unsigned long sector, unsigned char count);
DRESULT disk_ioctl (unsigned char drv, unsigned char ctrl, void* buff);
void disk_timerproc (void);
/* Checks if a card is inserted in the socket, 02022012_3 */
bool sdcard_present(void);

/* Disk Status Flag Bits (DSTATUS) */
#define STA_NOINIT		0x01	/* Drive not initialized */
#define STA_NODISK		0x02	/* No medium in the drive */
#define STA_PROTECT		0x04	/* Write protected */

/* Command codes for disk_ioctrl() */
/* Generic commands */
#define CTRL_SYNC			0	/* Mandatory for write functions */
#define GET_SECTOR_COUNT	1	/* Mandatory only for f_mkfs() */
#define GET_SECTOR_SIZE		2
#define GET_BLOCK_SIZE		3	/* Mandatory only for f_mkfs() */

/* MMC/SDC commands */
#define MMC_GET_TYPE		10
#define MMC_GET_CSD			11
#define MMC_GET_CID			12
#define MMC_GET_OCR			13
#define MMC_GET_SDSTAT		14

/* Card type flags (CardType) */
#define CT_MMC				0x01
#define CT_SD1				0x02
#define CT_SD2				0x04
#define CT_SDC				(CT_SD1|CT_SD2)
#define CT_BLOCK			0x08

#pragma library sdcard.lib

#endif
