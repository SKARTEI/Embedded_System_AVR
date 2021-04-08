//*****************************************************************************
// USB Device mode library
// (C) 2014 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.13+
// Version: 1.02
//
// 1.00 - Initial release
// 1.01 - 02062014_2, Fixed: "chip not supported..."" error message for the
//        Atmega16U4/32U4 chips
//      - 02062014_3, Fixed: USB_ENDPOINT interrupt vector names for the
//        ATmega U2, U4, AT90USB82/162 chips
// 1.02 - 05062014_2, Added Xmega AU, B, C support
//        21062014_3, usb_getconfig returns also USB_RES_DEVICE_SUSPENDED
//        for device suspended state
//*****************************************************************************

#ifndef _USB_INCLUDED_
#define _USB_INCLUDED_

#include <io.h>
#include <stdbool.h>
#include <string.h>

// Maximum number of interfaces
#ifdef _ATXMEGA_DEVICE_ // 05062014_1
// Xmega devices can use up to 4 interfaces
#define MAX_INTERFACES 4
#else
// non-Xmega devices can use up to 2 interfaces
#define MAX_INTERFACES 2
#endif

// Maximum number of endpoints that are used,
// besides the control endpoint 0
#define MAX_ENDPOINTS 4

// USB functions' result codes
#define USB_RES_OK 0x00 // No error
#define USB_RES_CONFIG_ERROR 0x80 // Configuration error
#define USB_RES_DEVICE_NOT_ENUM 0x81 // Device not enumerated
#define USB_RES_NO_DATA 0x82 // No data available
#define USB_RES_TIMEOUT 0x83 // Communication timeout
#define USB_RES_DEVICE_SUSPENDED 0x84 // The device is in suspended state, 21062014_3
#define USB_RES_ERROR_MASK 0x80 // Bit 7=1 signals an error

// bDescriptorType values
#define USB_DESCRIPTOR_TYPE_DEVICE 0x01 // Device
#define USB_DESCRIPTOR_TYPE_CONFIGURATION 0x02 // Configuration
#define USB_DESCRIPTOR_TYPE_STRING 0x03 // String
#define USB_DESCRIPTOR_TYPE_INTERFACE 0x04 // Interface
#define USB_DESCRIPTOR_TYPE_ENDPOINT 0x05 // Endpoint
#define USB_DESCRIPTOR_TYPE_DEV_QUALIFIER 0x06 // Device Qualifier
#define USB_DESCRIPTOR_TYPE_OTHER_SPEED_CFG 0x07 // Other Speed Configuration
#define USB_DESCRIPTOR_TYPE_INTERFACE_PWR 0x08 // Interface Power
#define USB_DESCRIPTOR_TYPE_OTG 0x09 // On The Go devices
#define USB_DESCRIPTOR_TYPE_DEBUG 0x0A // Debug
#define USB_DESCRIPTOR_TYPE_INTERFACE_ASSOC 0x0B // Interface Association
#define USB_DESCRIPTOR_TYPE_HID_INTERFACE 0x21 // HID Interface
#define USB_DESCRIPTOR_TYPE_REPORT 0x22 // Report
#define USB_DESCRIPTOR_TYPE_PHYSICAL 0x23 // Physical

// bcdUSB value
#define USB_SPEC 0x0200 // USB 2.0 specification supported

// bMaxPacketSize0 value
// Buffer size of Endpoint 0
#define USB_ENDPOINT0_SIZE 32

// bmAttributes values
#define USB_ATTR_COMPAT1 0x80 // for compatibility with USB 1.0
#define USB_ATTR_BUS_POWERED 0x00  // the device is bus powered
#define USB_ATTR_SELF_POWERED 0x40 // the device is self powered
#define USB_ATTR_REMOTE_WAKEUP 0x20 // the device supports remote wakeup feature

// bDeviceClass
#define USB_CLASS_IF_DESCRIPTOR 0x00 // the Interface Descriptor specifies the class
                                     // and the function doesn't use an Interface Association
                                     // Descriptor

// bDeviceSubClass
#define USB_SUBCLASS_NONE 0x00 // No subclass

// bDeviceProtocol, bInterfaceProtocol
#define USB_PROTOCOL_NONE 0x00 // No protocol

// bAlternateSetting
#define USB_ALTERNATE_SETTING_NONE 0x00 // No alternate settings descriptor

// bInterfaceClass (bDeviceClass) values
#define USB_CLASS_NONE 0x00 // No bDeviceClass, class will be specified at Interface level
#define USB_CLASS_AUDIO 0x01 // Audio
#define USB_CLASS_COMM_DEV_COMM 0x02 // Communication Device Class: communication interface
                                     // (also for bDeviceClass)
// bDeviceSubClass
#define USB_SUBCLASS_ACM 0x02 // Abstract Control Management subclass

#define USB_CLASS_HID 0x03 // Human Interface Device:
// bDeviceSubClass
#define USB_SUBCLASS_HID_BOOT 0x01 // HID requires BIOS support
// bInterfaceProtocol
#define USB_PROTOCOL_KEYBOARD 0x01 // Keyboard
#define USB_PROTOCOL_MOUSE 0x02 // Mouse

#define USB_CLASS_PHYSICAL 0x05 // Physical
#define USB_CLASS_IMAGE 0x06 // Image
#define USB_CLASS_PRINTER 0x07 // Printer
#define USB_CLASS_MASS_STORAGE 0x08 // Mass Storage
#define USB_CLASS_HUB 0x09 // Hub (also for bDeviceClass)
#define USB_CLASS_COMM_DEV_DATA 0x0A // Communication Device Class: data interface
#define USB_CLASS_SMART_CARD 0x0B // Smart Card
#define USB_CLASS_CONTENT_SECURITY 0x0D // Content Security
#define USB_CLASS_VIDEO 0x0E // Video
#define USB_CLASS_PERSONAL_HEALTHCARE 0x0F // Personal Healthcare (also for bDeviceClass)

#define USB_CLASS_DIAG_DEVICE 0xDC // Diagnostic Device (also for bDeviceClass):
// bInterfaceSubclass (bDeviceSubClass):
#define USB_SUBCLASS_DIAG_DEVICE 0x01 // Diagnostic Device subclass
// bInterfaceProtocol (bDeviceProtocol):
#define USB_PROTOCOL_USB2_COMPLIANCE_DEVICE 0x01 // USB2 Compliance Device

#define USB_CLASS_WIRELESS 0xE0 // Wireless controller (also for bDeviceClass):
// bInterfaceSubclass (bDeviceSubClass):
#define USB_SUBCLASS_WIRELESS1 0x01
// bInterfaceProtocol (bDeviceProtocol):
#define USB_PROTOCOL_BLUETOOTH 0x01 // Bluetooth programming device (also for bDeviceProtocol)
#define USB_PROTOCOL_UWB 0x02 // Wireless USB Radio control
#define USB_PROTOCOL_REMOTE_NDIS 0x03 // Remote NDIS
// bInterfaceSubclass (bDeviceSubClass):
#define USB_SUBCLASS_WIRELESS2 0x02 // Wireless USB host and device wire addapters

#define USB_CLASS_INTERFACE_ASSOC_DESCRIPTOR 0xEF // Interface Association Descriptor (also for bDeviceClass):
// bInterfaceSubclass (bDeviceSubClass):
#define USB_SUBCLASS_INTERFACE_ASSOC_DESCRIPTOR 0x02 // Interface Association Descriptor subclass
// bInterfaceProtocol (bDeviceProtocol):
#define USB_PROTOCOL_INTERFACE_ASSOC_DESCRIPTOR 0x01 // Interface Association Descriptor protocol

// bInterfaceSubclass (bDeviceSubClass):
#define USB_SUBCLASS_CABLE_ASSOC_FW 0x03 // Wireless USB
                                         // Cable based Association Framework

#define USB_CLASS_APP_SPECIFIC 0xFE // Application Specific (also for bDeviceClass):
// bInterfaceSubclass (bDeviceSubClass):
#define USB_SUBCLASS_FW_UPGRADE 0x01 // Device Firmware Upgrade
#define USB_SUBCLASS_IRDA_BRIDGE 0x02 // IrDA Bridge
#define USB_SUBCLASS_TEST_MEASUREMENT 0x03 // Test and Measurement

#define USB_CLASS_VENDOR_SPECIFIC 0xFF // Vendor Specific (also for bDeviceClass)

// No string descriptor
#define USB_STRING_NONE 0x00

// bmRequestType format:
// bit 7 Data phase transfer direction =0 host -> device, =1 device -> host
#define USB_ENDPOINT_DIR_IN 0x80  // Endpoint direction IN: device->host
#define USB_ENDPOINT_DIR_OUT 0x00 // Endpoint direction OUT: host->device
// bits5..6 Type: =0 - Standard
//                =1 - Class
//                =2 - Vendor
#define USB_REQ_TYPE_STD 0x00
#define USB_REQ_TYPE_CLASS 0x20
#define USB_REQ_TYPE_VENDOR 0x40
// bits0..4 Recipient: =0 - Device
//                     =1 - Interface
//                     =2 - Endpoint
//                     =3 - Other
#define USB_REQ_RECIPIENT_DEVICE 0x00
#define USB_REQ_RECIPIENT_INTERFACE 0x01
#define USB_REQ_RECIPIENT_EP 0x02
#define USB_REQ_RECIPIENT_OTHER 0x03

// bmAttributes
#define USB_TRANSFER_CONTROL 0x00 // Endpoint transfer type: control
#define USB_TRANSFER_ISOCHRONOUS 0x01 // Endpoint transfer type: isochronous
#define USB_TRANSFER_BULK 0x02 // Endpoint transfer type: bulk
#define USB_TRANSFER_INTERRUPT 0x03 // Endpoint transfer type: interrupt

#define USB_EP_ATTR_NO_SYNC 0x00 // Endpoint is asynchronous
#define USB_EP_ATTR_ASYNC 0x04 // Endpoint is synchronous
#define USB_EP_ATTR_ADAPTIVE 0x08 // Endpoint is adaptive
#define USB_EP_ATTR_SYNC 0x0C // Endpoint is synchronized

#define USB_EP_USAGE_DATA 0x00 // Endpoint is used for data transfer
#define USB_EP_USAGE_FEEDBACK 0x10 // Endpoint is used for feedback
#define USB_EP_USAGE_IMPLICIT_FEEDBACK 0x20 // Endpoint is used for implicit feedback

// wLangID
#define USB_LANG_ID_US_ENGLISH 0x0409

// bRequest
// Control transfer requests
#define USB_REQ_GET_STATUS 0x00 // The host requests the status of the features
                                // of a device, interface or endpoint
#define USB_REQ_CLEAR_FEATURE 0x01
#define USB_REQ_SET_FEATURE 0x03
#define USB_REQ_SET_ADDRESS 0x05
#define USB_REQ_GET_DESCRIPTOR 0x06
#define USB_REQ_GET_CONFIGURATION 0x08
#define USB_REQ_SET_CONFIGURATION 0x09
#define USB_REQ_GET_INTERFACE 0x0A
#define USB_REQ_SET_INTERFACE 0x0B

// USB Device Descriptor
typedef struct
{
unsigned char bLength; // Descriptor size in bytes = 0x12
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_DEVICE = 0x01
unsigned short bcdUSB; // USB specification release number in BCD format = 0x0200
unsigned char bDeviceClass; // Class code
unsigned char bDeviceSubClass; // Subclass code, specifies additional features
                               // for a class
unsigned char bDeviceProtocol; // Protocol code for the selected class and subclass
unsigned char bMaxPacketSize0; // Maximum packet size for endpoint 0
unsigned short idVendor; // Vendor ID
unsigned short idProduct; // Product ID
unsigned short bcdDevice; // Device release number in BCD format
unsigned char iManufacturer; // Index in the descriptor list of string descriptor for the manufacturer
                             // Use 0 for no manufacturer descriptor
unsigned char iProduct;      // Index in the descriptor list of string descriptor for the product
                             // Use 0 for no product descriptor
unsigned char iSerialNumber; // Index in the descriptor list of string descriptor for the serial number
                             // Use 0 for no serial number
unsigned char bNumConfigurations; // Number of possible configurations supported by the
                                  // device at the current operating speed
} USB_DEVICE_DESCRIPTOR_t;

// USB Configuration Descriptor
typedef struct
{
unsigned char bLength; // Descriptor size in bytes = 9
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_CONFIGURATION = 0x02
unsigned short wTotalLength;   // The number of bytes in the configuration
                               // descriptor and all of its subordinate descriptors
unsigned char bNumInterfaces;  // The number of interfaces in the configuration
                               // Must be >= 1
unsigned char bConfigurationValue; // Identifier for Set Configuration and
                                   // Get Configuration requests
                                   // Must be >= 1
unsigned char iConfiguration; // Index of string descriptor for the configuration
                              // Use 0 for no string descriptor
unsigned char bmAttributes;   // Self/bus power and remote wakeup settings
                              // bit 7: =1 for compatibility with USB 1.0
                              // bit 6: =0 the device is bus powered
                              //        =1 the device is self powered
                              // bit 5: =1 the device supports remote
                              //           wakeup feature
                              // bits 0..4 must be 0
unsigned char bMaxPower;      // Bus power required in multiples of 2 mA
} USB_CONFIG_DESCRIPTOR_t;

// USB Other Speed Configuration Descriptor
typedef struct
{
unsigned char bLength; // Descriptor size in bytes = 9
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_OTHER_SPEED_CFG = 0x07
unsigned short wTotalLength;   // The number of bytes in the configuration
                               // descriptor and all of its subordinate descriptors
unsigned char bNumInterfaces;  // The number of interfaces in the configuration
                               // Must be >= 1
unsigned char bConfigurationValue; // Identifier for Set Configuration and
                                   // Get Configuration requests
                                   // Must be >= 1
unsigned char iConfiguration; // Index of string descriptor for the configuration
                              // Use 0 for no string descriptor
unsigned char bmAttributes;   // Self/bus power and remote wakeup settings
                              // bit 7: =1 for compatibility with USB 1.0
                              // bit 6: =0 the device is bus powered
                              //        =1 the device is self powered
                              // bit 5: =1 the device supports remote
                              //           wakeup feature
                              // bits 0..4 must be 0
unsigned char bMaxPower;      // Bus power required in multiples of 2 mA
} USB_OTHER_SPEED_CONFIG_DESCRIPTOR_t;

// USB Interface Association Descriptor
typedef struct
{
unsigned char bLength; // Descriptor size in bytes = 8
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_INTERFACE_ASSOC = 0x0B
unsigned char bFirstInterface; // Number identifying the first interface associated
                               // with a function
unsigned char bInterfaceCount; // The number of contigous interfaces associated
                               // with the function
unsigned char bFunctionClass;  // Class code
unsigned char bFunctionSubClass; // Subclass code, specifies additional features
                                 // for a class
unsigned char bFunctionProtocol; // Protocol code for the selected class and subclass
unsigned char iFunction;         // Index of string descriptor associated with the function
                                 // Use 0 for no string descriptor
} USB_INTERFACE_ASSOC_DESCRIPTOR_t;

// USB Interface Descriptor
typedef struct
{
unsigned char bLength; // Descriptor size in bytes = 9
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_INTERFACE = 0x04
unsigned char bInterfaceNumber; // Number identifying this interface
unsigned char bAlternateSetting; // Number that identifies a descriptor with
                                 // alternate settings for this bInterfaceNumber
unsigned char bNumEndpoints; // Number of supported endpoints, not counting
                             // endpoint 0
unsigned char bInterfaceClass;    // Class code
unsigned char bInterfaceSubClass; // Subclass code, specifies additional features
                                  // for a class
unsigned char bInterfaceProtocol; // Protocol code for the selected class and subclass
unsigned char iInterface;         // Index of string descriptor associated with the interface
                                  // Use 0 for no string descriptor
} USB_INTERFACE_DESCRIPTOR_t;

// USB Endpoint Descriptor
typedef struct
{
unsigned char bLength; // Descriptor size in bytes = 7
unsigned char bDescriptorType;  // The constant USB_DESCRIPTOR_TYPE_ENDPOINT = 0x05
unsigned char bEndpointAddress; // Endpoint number and direction
                                // bit 7: =0 OUT, =1 IN
                                // bits 0..3: endpoint number
unsigned char bmAttributes;     // Transfer type and additional information
unsigned short wMaxPacketSize;  // Maximum supported packet size
unsigned char bInterval;        // Service interval or NAK rate
                                // Low-speed interrupt ep: 10..255 [ms]
                                // Full-speed interrupt ep: 1..255 [ms]
                                // Full-speed isochronous ep: 1..16, interval = 2^(bInterval-1) [ms]
                                // High-speed ep: 1..16, interval = 2^(bInterval-1)*125 [us]
} USB_ENDPOINT_DESCRIPTOR_t;

// USB Descriptors List
typedef struct
{
unsigned char bDescriptorIndex; // Descriptor index, to specify which descriptor to return if
                                // there are several descriptors of the same type
unsigned char bDescriptorType; // Descriptor type
unsigned short wIndex; // =0 or Language ID for string descriptors
flash void *pDescriptor; // FLASH storage address of descriptor data
unsigned char bLength;   // Descriptor data length
} USB_DESCRIPTOR_LIST_t;

// Endpoint type:
#define EP_TYPE_CONTROL 0x00 // Endpoint type: control
#define EP_TYPE_ISOCHRONOUS 0x01 // Endpoint type: isochronous
#define EP_TYPE_BULK 0x02 // Endpoint type: bulk
#define EP_TYPE_INTERRUPT 0x03 // Endpoint type: interrupt

// Endpoint configuration
typedef struct
{
unsigned char ep:4;   // Endpoint number
unsigned char type:2; // Endpoint type:
                      // 0 - Control, 1 - Isochronous, 2 - Bulk, 3 - Interrupt
unsigned char size;   // Endpoint size: 8..64 [bytes], set 0 if endpoint is not used
} USB_ENDPOINT_t;

// USB Interface configuration
typedef struct
{
unsigned char bInterfaceClass; // Class code, set 0 if not used
unsigned char bInterfaceProtocol; // Protocol code for the selected class and subclass
void *report_data; // Pointer to a variable that contains the data to be
                   // sent to the host for a report request
unsigned char report_size; // Size of the report to be sent to the host
                           // for a report request
USB_ENDPOINT_t in;  // IN endpoint configuration
USB_ENDPOINT_t out; // OUT endpoint configuration
} USB_INTERFACE_t;

// USB Communication Timeouts
typedef struct
{
unsigned char tx; // Transmission timeout period [ms], 0 value corresponds to 256 ms
unsigned char rx; // Reception timeout period [ms], 0 value corresponds to 256 ms
} USB_TIMEOUT_t;

// Transmission and reception timeouts
extern USB_TIMEOUT_t usb_timeout;

#ifdef _ATXMEGA_DEVICE_ // 05062014_2
// USB controller's clock source
typedef enum
{
USB_CLOCK_RC32M_SOF=0, // The USB is clocked by the 32 MHz RC oscillator adjusted
                       // and calibrated to 48 MHz using the DFLL and USB Start Of Frame
USB_CLOCK_PLL_48M,     // The USB is clocked by the PLL running at 48 MHz
USB_CLOCK_PLL_96M      // The USB is clocked by the PLL running at 96 MHz
} USB_CLOCK_SOURCE_t;
#endif

// USB Device Configuration used by the usb_device_init function
typedef struct
{
USB_INTERFACE_t interface[MAX_INTERFACES]; // Interfaces configuration
flash USB_DESCRIPTOR_LIST_t *pdescriptor_list; // Pointer to the USB_DESCRIPTOR_LIST_t array
unsigned char descriptor_list_items; // # of elements in the USB_DESCRIPTOR_LIST_t array
USB_TIMEOUT_t timeout; // Timeout periods

#ifdef _ATXMEGA_DEVICE_ // 05062014_2
USB_CLOCK_SOURCE_t usb_clock;       // USB controller's clock source:
                                    // USB_CLOCK_RC32M_SOF - 32 MHz RC oscillator adjusted
                                    // and calibrated to 48 MHz using the DFLL and
                                    // USB Start Of Frame
                                    // USB_CLOCK_PLL_48M - PLL running at 48 MHz
                                    // USB_CLOCK_PLL_96M - PLL running at 96 MHz
USB_INTLVL_t int_level;             // Interrupt priority for the USB controller:
                                    // USB_INTLVL_LO_gc  - Low level
                                    // USB_INTLVL_MED_gc - Medium level
                                    // USB_INTLVL_HI_gc  - High level
void (*usb_suspend_handler) (void); // Pointer to the power management function
                                    // to be called when the device on the USB bus
                                    // is suspended
void (*usb_resume_handler) (void);  // Pointer to the power management function
                                    // to be called when the device on the USB bus
                                    // exits the suspended state
#endif
} USB_CONFIG_t;

// Stores the number of the USB configuration used by the USB device
// !=0  -> the device mode is enumerated
extern unsigned char usb_enumerated;
// The number of the currently active interface used for USB communication
#if MAX_INTERFACES==2
extern bit usb_current_interface;
#else
extern unsigned char usb_current_interface;
#endif

// Initialize the USB controller in Device mode.
bool usb_init_device(flash USB_CONFIG_t *cfg);
// Returns the current configuration or status of the USB interface.
unsigned char usb_getconfig(void);
// Transmits a byte to the host using the currently active USB interface.
unsigned char usb_putchar(char c);
// Transmits to the host the contents of a buffer, located in RAM,
// using the currently active USB interface.
unsigned char usb_putbuf(void *buffer, unsigned short length);
// Transmits to the host the contents of a buffer, located in FLASH,
// using the currently active USB interface.
unsigned char usb_putbuff(flash void *buffer, unsigned short length);
// Transmits to the host the contents of a buffer, located in EEPROM,
// using the currently active USB interface.
unsigned char usb_putbufe(eeprom void *buffer, unsigned short length);
// Transmits to the host the contents of a NULL terminated literal char string,
// located in RAM, using the currently active USB interface.
unsigned char usb_putstr(char *str);
// Transmits to the host the contents of a NULL terminated literal char string,
// located in FLASH, using the currently active USB interface.
unsigned char usb_putstrf(flash char *str);
// Immediately transmit to the host any buffered output for
// the currently active USB interface.
unsigned char usb_txflush(void);
// Clears the receive buffer for the currently active USB interface.
unsigned char usb_rxclear(void);
// Receives a byte from the OUT endpoint of the currently active USB interface.
short usb_rxbyte(bool wait);
// Waits to receive a byte from the OUT endpoint of the currently
// active USB interface.
short usb_getchar(void);
// Receives, without waiting, a byte from the OUT endpoint of the
// currently active USB interface.
short usb_getcharnw(void);
// Returns the # of bytes available in the receive buffer of the OUT
// endpoint of the currently active USB interface.
unsigned char usb_rxavailable(void);
// Receives data from the host and stores into a buffer.
unsigned char usb_getbuf(void *buffer, unsigned short *length);

#ifdef _ATXMEGA_DEVICE_ // 05062014_2
#pragma library usb_devicex.lib
#else
#pragma library usb_device.lib
#endif

#endif
