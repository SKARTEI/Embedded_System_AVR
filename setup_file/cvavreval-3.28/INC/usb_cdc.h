//*****************************************************************************
// USB Communication Device Class library
// (C) 2014 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.13+
// Version: 1.01
//
// 1.01 05062014_2 Added support for Xmega devices
//      09072014_1 Modified usb_serial_available to return unsigned char
//      15072014_1 Added the usb_serial_select function
//      23072014_1 Added the usb_serial_getbuf, usb_serial_putbuf,
//                 usb_serial_putbuff, usb_serial_putbufe functions
//*****************************************************************************

#ifndef _USB_CDC_INCLUDED_
#define _USB_CDC_INCLUDED_

#include <usb_device.h>

#ifdef _ATXMEGA_DEVICE_ // 05062014_2
// Xmega devices support 2 virtual serial ports
#define USB_CDC_MAX_SERIAL_PORTS 2
#else
#define USB_CDC_MAX_SERIAL_PORTS 1
#endif

// CDC Virtual Serial Port specific requests
#define USB_REQ_CDC_SET_LINE_CODING 0x20
#define USB_REQ_CDC_GET_LINE_CODING 0x21
#define USB_REQ_CDC_SET_CTRL_LINE_STATE 0x22
#define USB_REQ_CDC_SEND_BREAK 0x23

// CDC Notifications
#define USB_NOTIF_CDC_SERIAL_STATE 0x20

// bcdCDC value
#define USB_CDC_SPEC 0x0110 // The CDC 1.10 specification is supported

// bDescriptorType values
#define USB_DESCRIPTOR_TYPE_CS_INTERFACE 0x24 // CS interface
#define USB_DESCRIPTOR_TYPE_CS_ENDPOINT 0x25 // CS endpoint

// bInterfaceProtocol
#define USB_PROTOCOL_CDC_AT 0x01 // AT command protocol

// bDescriptorSubType values
#define CDC_DST_HEADER           0x00 // Header functional descriptor
#define CDC_DST_CALL_MANAGEMENT  0x01 // Call Management functional descriptor
#define CDC_DST_ACM              0x02 // Abstract Control Model functional descriptor
#define CDC_DST_DIRECT_LINE      0x03 // Direct Line functional descriptor
#define CDC_DST_TEL_RINGER       0x04 // Telephone Ringer functional descriptor
#define CDC_DST_TEL_CALL         0x05 // Telephone Call functional descriptor
#define CDC_DST_UNION            0x06 // Union functional descriptor
#define CDC_DST_COUNTRY_SEL      0x07 // Country Selection functional descriptor
#define CDC_DST_TEL_OP_MODES     0x08 // Telephone Operation Modes functional descriptor
#define CDC_DST_USB_TERMINAL     0x09 // USB Terminal functional descriptor
#define CDC_DST_NETWORK_CH       0x0A // Network Channel functional descriptor
#define CDC_DST_PROTOCOL_UNIT    0x0B // Protocol Unit functional descriptor
#define CDC_DST_EXT_UNIT         0x0C // Extension Unit functional descriptor
#define CDC_DST_MULTI_CH         0x0D // Multi-Channel Management functional descriptor
#define CDC_DST_CAPI             0x0E // Common ISDN API functional descriptor
#define CDC_DST_ETHERNET         0x0F // Ethernet functional descriptor
#define CDC_DST_ATM              0x10 // Asynchronous Transfer Mode functional descriptor

// CDC Header Functional Descriptor
typedef struct
{
unsigned char bFunctionLength; // Descriptor size in bytes = 5
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_CS_INTERFACE = 0x24
unsigned char bDescriptorSubtype; // CDC class specific interface descriptor subtypes
unsigned short bcdCDC; // CDC specification release number in BCD format = 0x0110
} USB_CDC_HEADER_FUNC_DESCRIPTOR_t;

// Call Management Functional Descriptor
typedef struct
{
unsigned char bFunctionLength; // Descriptor size in bytes = 5
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_CS_INTERFACE = 0x24
unsigned char bDescriptorSubtype; // CDC class specific interface descriptor subtypes
unsigned char bmCapabilities; // bit 1: =0 - Device sends/receives call
                              //             management information only over
                              //             the Communication Class interface
                              //        =1 - Device can send/receive call management
                              //             information over a Data Class interface
                              // bit 0: =0 - Device does not handle call management itself
                              //        =1 - Device handles call management itself
unsigned char bDataInterface; // Interface number of Data Class interface,
                              // optionally used for call management (0 based index)
} USB_CDC_CALL_MAN_FUNC_DESCRIPTOR_t;

// Call Management Functional Descriptor bmCapabilities flags
#define CDC_CALL_MAN_COMMUNICATION 0x00 // Device sends/receives call
                                        // management information only over
                                        // the Communication Class interface
#define CDC_CALL_MAN_DATA 0x02          // Device sends/receives call
                                        // management information only over
                                        // a Data Class interface
#define CDC_CALL_MAN_NOT_ITSELF 0x00    // Device does not handle call management itself
#define CDC_CALL_MAN_ITSELF 0x01        // Device does handles call management itself

// Abstract Control Management Functional Descriptor
typedef struct
{
unsigned char bFunctionLength; // Descriptor size in bytes = 4
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_CS_INTERFACE = 0x24
unsigned char bDescriptorSubtype; // CDC class specific interface descriptor subtypes
unsigned char bmCapabilities; // bit 3: =1 - Device supports the notification
                              //             Network_Connection
                              // bit 2: =1 - Device supports the request Send_Break
                              // bit 1: =1 - Device supports the request
                              //             combination of Set_Line_Coding,
                              //             Set_Control_Line_State, Get_Line_Coding and
                              //             the notification Serial_State
                              // bit 0: =1 - Device supports the request
                              //             combination of Set_Comm_Feature,
                              //             Clear_Comm_Feature and Get_Comm_Feature
} USB_CDC_ACM_FUNC_DESCRIPTOR_t;

// Abstract Control Management Functional Descriptor bmCapabilities flags
#define CDC_ACM_NET_CONNECTION 0x08 // Device supports the notification Network_Connection
#define CDC_ACM_SEND_BREAK 0x04 // Device supports the request Send_Break
#define CDC_ACM_LC_CLS_SS 0x02  // Device supports the request combination of Set_Line_Coding,
                                // Set_Control_Line_State, Get_Line_Coding and
                                // the notification Serial_State
#define CDC_ACM_COMM_FEATURE 0x01 // Device supports the request combination of Set_Comm_Feature,
                                  // Clear_Comm_Feature and Get_Comm_Feature

// Union Functional Descriptor
typedef struct
{
unsigned char bFunctionLength; // Descriptor size in bytes = 5
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_CS_INTERFACE = 0x24
unsigned char bDescriptorSubtype; // CDC class specific interface descriptor subtypes
unsigned char bMasterInterface; // Interface number of the CDC Control interface
unsigned char bSlaveInterface0; // Interface number of the CDC Data interface
} USB_CDC_UNION_FUNC_DESCRIPTOR_t;

// CDC Virtual Serial Port Line Coding settings
typedef struct
{
unsigned long baud_rate; // Baud rate [bps]
unsigned char stop_bits; // Number of stop bits
unsigned char parity;    // Parity bit type
unsigned char data_bits; // Number of data bits
} USB_CDC_LINE_CODING_t;

// Stop_bits values
#define CDC_SERIAL_STOP_BITS1 0   // 1 stop bit
#define CDC_SERIAL_STOP_BITS1_5 1 // 1.5 stop bits
#define CDC_SERIAL_STOP_BITS2 2   // 2 stop bits

// Parity values
#define CDC_SERIAL_PARITY_NONE  0 // No parity bit
#define CDC_SERIAL_PARITY_ODD   1 // Odd parity bit
#define CDC_SERIAL_PARITY_EVEN  2 // Even parity bit
#define CDC_SERIAL_PARITY_MARK  3 // Mark parity bit
#define CDC_SERIAL_PARITY_SPACE 4 // Space parity bit

// CDC Virtual Serial Port communication parameters and control signals
typedef struct
{
USB_CDC_LINE_CODING_t parameters; // Communication parameters
union
    {
    struct
         {
         unsigned char dtr:1; // DTR signal state
         unsigned char rts:1; // RTS signal state
         };
    unsigned char signals;
    } control; // RS-232 control signals
} USB_CDC_SERIAL_CONFIG_t;

typedef union
{
struct
     {
     unsigned char dcd:1;   // DCD signal state
     unsigned char dsr:1;   // DSR signal state
     unsigned char break:1; // Break detected
     unsigned char ri:1;    // RI signal state
     unsigned char frame_error:1;   // Frame error detected
     unsigned char parity_error:1;  // Parity error detected
     unsigned char overrun_error:1; // Overrun error detected
     };
unsigned char signals;
} USB_CDC_SERIAL_STATUS_t; // RS-232 signals and error status

// Store CDC Virtual Serial Port communication parameters and control signals
#if USB_CDC_MAX_SERIAL_PORTS>=2 // 05062014_2
extern USB_CDC_SERIAL_CONFIG_t usb_cdc_serial[USB_CDC_MAX_SERIAL_PORTS];
#else
extern USB_CDC_SERIAL_CONFIG_t usb_cdc_serial;
#endif

#if USB_CDC_MAX_SERIAL_PORTS>=2
// Selects the CDC Virtual Serial Port to be used for communication
void usb_serial_select(unsigned char port); // 15072014_1
#else
// Dummy function when only 1 serial port is available
#define usb_serial_select(port)
#endif

// Sends RS-232 signals and error status of the
// currently selected CDC Virtual Serial Port to the host.
unsigned char usb_serial_sendstatus(USB_CDC_SERIAL_STATUS_t status);
// Transmits a byte to the host using the currently selected CDC Virtual Serial Port.
unsigned char usb_serial_putchar(char c);
// Transmits to the host the contents of a buffer, located in RAM,
// using the currently selected CDC Virtual Serial Port.
unsigned char usb_serial_putbuf(void *buffer, unsigned short length); // 23072014_1
// Transmits to the host the contents of a buffer, located in FLASH,
// using the currently selected CDC Virtual Serial Port.
unsigned char usb_serial_putbuff(flash void *buffer, unsigned short length); // 23072014_1
// Transmits to the host the contents of a buffer, located in EEPROM,
// using the currently selected CDC Virtual Serial Port.
unsigned char usb_serial_putbufe(eeprom void *buffer, unsigned short length); // 23072014_1
// Transmits to the host the contents of a NULL terminated literal char string,
// located in RAM, using the currently selected CDC Virtual Serial Port.
unsigned char usb_serial_putstr(char *str);
// Transmits to the host the contents of a NULL terminated literal char string,
// located in FLASH, using the currently selected CDC Virtual Serial Port.
unsigned char usb_serial_putstrf(flash char *str);
// Immediately transmit to the host any buffered output for
// the currently selected CDC Virtual Serial Port.
unsigned char usb_serial_txflush(void);
// Clears the receive buffer of the currently selected
// CDC Virtual Serial Port.
unsigned char usb_serial_rxclear(void);
// Waits to receive a byte from the currently selected
// CDC Virtual Serial Port.
short usb_serial_getchar(void);
// Receives, without waiting, a byte from the currently selected
// CDC Virtual Serial Port.
short usb_serial_getcharnw(void);
// Returns the # of bytes available in the currently selected
// CDC Virtual Serial Port's receive buffer
unsigned char usb_serial_available(void); // 09072014_1
// Receives data from the host using the currently selected
// CDC Virtual Serial Port and stores into a buffer.
unsigned char usb_serial_getbuf(void *buffer, unsigned short *length); // 23072014_1

#pragma library usb_cdc.lib

#endif
