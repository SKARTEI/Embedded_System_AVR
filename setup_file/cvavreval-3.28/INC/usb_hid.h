//*****************************************************************************
// USB Human Interface Device Class library
// (C) 2014 Pavel Haiduc, HP InfoTech s.r.l., All rights reserved
//
// Compiler: CodeVisionAVR V3.11+
// Version: 1.00
//*****************************************************************************

#ifndef _USB_HID_INCLUDED_
#define _USB_HID_INCLUDED_

#include <usb_device.h>

// HID specific requests
#define USB_REQ_HID_GET_REPORT 0x01   // The host requests an Input or
                                      // Feature report from a HID using
                                      // a control transfer
#define USB_REQ_HID_GET_IDLE 0x02     // The host reads the current Idle Rate from a HID
#define USB_REQ_HID_GET_PROTOCOL 0x03 // The host learns if the boot or
                                      // report protocol is currently active
                                      // in the HID
                                      // Required for HIDs that support a boot protocol
#define USB_REQ_HID_SET_REPORT 0x09   // The host sends an Output or Feature
                                      // report to a HID
#define USB_REQ_HID_SET_IDLE 0x0A     // Limits the reporting frequency of
                                      // an interrupt IN endpoint when the data
                                      // has not changed since the last report
                                      // Required for keyboards that support a boot protocol
#define USB_REQ_HID_SET_PROTOCOL 0x0B // The host specifies whether the HID should use
                                      // the boot or report protocol
                                      // Required for HIDs that support a boot protocol

// bcdHID value
#define USB_HID_SPEC 0x0111 // HID 1.11 specification is supported

// USB HID Interface Descriptor
typedef struct
{
unsigned char bLength; // Descriptor size in bytes = 9
unsigned char bDescriptorType; // The constant USB_DESCRIPTOR_TYPE_HID_INTERFACE = 0x21
unsigned short bcdHID; // HID specification release number = 0x0111
unsigned char bCountryCode; // Country code of the localized hardware
                            // See HID spec. 1.11 page 23
unsigned char bNumDescriptors; // Number of class descriptors, >= 1
unsigned char bReportDescriptorType; // Constant name identifying the type of class descriptor
unsigned short wDescriptorLength; // Total size of the Report descriptor
} USB_HID_INTERFACE_DESCRIPTOR_t;

#define HID_RD_TYPE_MAIN 0x00
#define HID_RD_TYPE_GLOBAL 0x04
#define HID_RD_TYPE_LOCAL 0x08

#define HID_RD_DATA_BITS0 0x00
#define HID_RD_DATA_BITS8 0x01
#define HID_RD_DATA_BITS16 0x02
#define HID_RD_DATA_BITS32 0x03

#define HID_RD_ITEM_DATA0(n)
#define HID_RD_ITEM_DATA8(n) ,(n) & 0xFF
#define HID_RD_ITEM_DATA16(n) ,(n) & 0xFF,((n)>>8) & 0xFF
#define HID_RD_ITEM_DATA32(n) ,(n) & 0xFF,((n)>>8) & 0xFF,((n)>>16) & 0xFF,((n)>>24) & 0xFF

#define HID_RD_ITEM(type,tag,nbits,data) ((type) | (tag) | (HID_RD_DATA_BITS ## nbits)) HID_RD_ITEM_DATA ## nbits(data)

// HID Report Descriptor item macros

// Unsigned integer specifying the current Usage Page.
#define HID_RD_USAGE_PAGE(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x00,nbits,data)
// Usage index for an item usage.
// Represents a suggested usage for the item or collection.
#define HID_RD_USAGE(nbits,data) HID_RD_ITEM(HID_RD_TYPE_LOCAL,0x00,nbits,data)
// Defines the starting usage associated with an array or bitmap.
#define HID_RD_USAGE_MIN(nbits,data) HID_RD_ITEM(HID_RD_TYPE_LOCAL,0x10,nbits,data)
// Defines the ending usage associated with an array or bitmap.
#define HID_RD_USAGE_MAX(nbits,data) HID_RD_ITEM(HID_RD_TYPE_LOCAL,0x20,nbits,data)
// Extent value in logical units.
// This is the minimum value that a variable or array item will report.
#define HID_RD_LOGICAL_MIN(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x10,nbits,data)
// Extent value in logical units.
// This is the maximum value that a variable or array item will report.
#define HID_RD_LOGICAL_MAX(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x20,nbits,data)
// Minimum value for the physical extent of a variable item.
// This represents the Logical Minimum with units applied to it.
#define HID_RD_PHYSICAL_MIN(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x30,nbits,data)
// Maximum value for the physical extent of a variable item.
#define HID_RD_PHYSICAL_MAX(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x40,nbits,data)
// Value of the unit exponent in base 10.
#define HID_RD_UNIT_EXPONENT(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x50,nbits,data)
// Unit values.
#define HID_RD_UNIT(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x60,nbits,data)
// Unsigned integer specifying the size of the report fields in bits.
#define HID_RD_REPORT_SIZE(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x70,nbits,data)
// Unsigned integer value that specifies the Report ID.
#define HID_RD_REPORT_ID(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x80,nbits,data)
// Unsigned integer specifying the number of data fields for the item.
// Determines how many fields are included in the report for this particular item
// (and consequently how many bits are added to the report).
#define HID_RD_REPORT_COUNT(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0x90,nbits,data)
// Places a copy of the global item state table on the stack.
#define HID_RD_PUSH(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0xA0,nbits,data)
// Replaces the item state table with the top structure from the stack.
#define HID_RD_POP(nbits,data) HID_RD_ITEM(HID_RD_TYPE_GLOBAL,0xB0,nbits,data)
#define HID_RD_INPUT(nbits,data) HID_RD_ITEM(HID_RD_TYPE_MAIN,0x80,nbits,data)
#define HID_RD_OUTPUT(nbits,data) HID_RD_ITEM(HID_RD_TYPE_MAIN,0x90,nbits,data)
#define HID_RD_FEATURE(nbits,data) HID_RD_ITEM(HID_RD_TYPE_MAIN,0xB0,nbits,data)
// Identifies a relationship between two or more data (Input, Output or Feature).
#define HID_RD_COLLECTION(nbits,data) HID_RD_ITEM(HID_RD_TYPE_MAIN,0xA0,nbits,data)
// Closes an item collection.
#define HID_RD_END_COLLECTION(nbits) (HID_RD_TYPE_MAIN | 0xC0)

// HID Input, Output and Feature Report Descriptor item flags

// Indicates whether the item is device data,
// that can be modified by the host,
// or a constant read-only value.
#define HID_RD_DATA_F (0<<0)
#define HID_RD_CONSTANT_F (1<<0)

// Indicates whether the item creates variable or array data fields in reports.
// In variable fields, each field represents data from a physical control.
// The number of bits reserved for each field is
// determined by preceding Report Size/Report Count items.
// An array provides an alternate means for
// describing the data returned from a group of buttons.
// Rather than returning a single bit for each button in the group,
// an array returns an index in each field that corresponds to the pressed
// button.
#define HID_RD_ARRAY_F (0<<1)
#define HID_RD_VARIABLE_F (1<<1)

// Indicates whether the data is absolute (based on a
// fixed origin) or relative (indicating the change in
// value from the last report).
// Mouse devices usually provide relative data,
// while tablets usually provide absolute data.
#define HID_RD_ABSOLUTE_F (0<<2)
#define HID_RD_RELATIVE_F (1<<2)

// Indicates whether the data "rolls over" when
// reaching either the extreme high or low value.
#define HID_RD_NO_WRAP_F (0<<3)
#define HID_RD_WRAP_F (1<<3)

// Indicates whether the raw data from the device has
// been processed in some way, and no longer
// represents a linear relationship between what is
// measured and the data that is reported.
#define HID_RD_LINEAR_F (0<<4)
#define HID_RD_NON_LINEAR_F (1<<4)

// Indicates whether the control has a preferred state
// to which it will return when the user is not
// physically interacting with the control.
#define HID_RD_PREFERRED_STATE_F (0<<5)
#define HID_RD_NO_PREFERRED_STATE_F (1<<5)

// Indicates whether the control has a state in which it
// is not sending meaningful data.
#define HID_RD_NO_NULL_POSITION_F (0<<6)
#define HID_RD_NULLSTATE_F (1<<6)

// Indicates whether the Feature or Output control's
// value should be changed by the host or not.
#define HID_RD_NON_VOLATILE_F (0<<7)
#define HID_RD_VOLATILE_F (1<<7)

// Indicates if the control emits a fixed-size stream
// of bytes or not.
#define HID_RD_BITFIELD_F (0<<8)
#define HID_RD_BUFFERED_BYTES_F (1<<8)

// HID Report Descriptor Collection
#define HID_RD_COLLECTION_PHYSICAL 0x00
#define HID_RD_COLLECTION_APPLICATION 0x01
#define HID_RD_COLLECTION_LOGICAL 0x02
#define HID_RD_COLLECTION_REPORT 0x03
#define HID_RD_COLLECTION_NAMED_ARRAY 0x04
#define HID_RD_COLLECTION_USAGE_SWITCH 0x05
#define HID_RD_COLLECTION_USAGE_MODIFIER 0x06

#ifdef _USE_USB_HID_KEYBOARD_

// CTRL, SHIFT, ALT, GUI key modifier flags
typedef unsigned char USB_KEYBOARD_MODIFIER_t;
// Key modifier bit masks
#define KM_LEFT_CTRL 0x01 // Signal that the Left Ctrl key is pressed
#define KM_LEFT_SHIFT 0x02 // Signal that the Left Shift key is pressed
#define KM_LEFT_ALT 0x04 // Signal that the Left Alt key is pressed
#define KM_LEFT_GUI 0x08 // Signal that the Left GUI key is pressed
#define KM_RIGHT_CTRL 0x10 // Signal that the Right Ctrl key is pressed
#define KM_RIGHT_SHIFT 0x20 // Signal that the Right Shift key is pressed
#define KM_RIGHT_ALT 0x40 // Signal that the Right Alt key is pressed
#define KM_RIGHT_GUI 0x80 // Signal that the Right GUI key is pressed

// Keyboard HID report key scan codes
#define KS_ERROR_ROLLOVER 0x01
#define KS_POST_FAILED 0x02
#define KS_ERROR_UNDEFINED 0x03
#define KS_A 0x04
#define KS_B 0x05
#define KS_C 0x06
#define KS_D 0x07
#define KS_E 0x08
#define KS_F 0x09
#define KS_G 0x0A
#define KS_H 0x0B
#define KS_I 0x0C
#define KS_J 0x0D
#define KS_K 0x0E
#define KS_L 0x0F
#define KS_M 0x10
#define KS_N 0x11
#define KS_O 0x12
#define KS_P 0x13
#define KS_Q 0x14
#define KS_R 0x15
#define KS_S 0x16
#define KS_T 0x17
#define KS_U 0x18
#define KS_V 0x19
#define KS_W 0x1A
#define KS_X 0x1B
#define KS_Y 0x1C
#define KS_Z 0x1D
#define KS_1_EXCLAMATION 0x1E
#define KS_2_AT 0x1F
#define KS_3_HASHMARK 0x20
#define KS_4_DOLLAR 0x21
#define KS_5_PERCENTAGE 0x22
#define KS_6_CARET 0x23
#define KS_7_AMPERSAND 0x24
#define KS_8_ASTERISK 0x25
#define KS_9_OPENING_PARENS 0x26
#define KS_0_CLOSING_PARENS 0x27
#define KS_ENTER 0x28
#define KS_ESC 0x29
#define KS_BACKSPACE 0x2A
#define KS_TAB 0x2B
#define KS_SPACE 0x2C
#define KS_MINUS_UNDERSCORE 0x2D
#define KS_EQUAL_PLUS 0x2E
#define KS_OPENING_BRACKET_BRACE 0x2F
#define KS_CLOSING_BRACKET_BRACE 0x30
#define KS_BACKSLASH_PIPE 0x31
#define KS_NON_US_HASHMARK_TILDE 0x32
#define KS_SEMICOLON_COLON 0x33
#define KS_APOSTROPHE_QUOTE 0x34
#define KS_GRAVE_ACCENT_TILDE 0x35
#define KS_COMMA_LESS_THAN 0x36
#define KS_DOT_GREATER_THAN 0x37
#define KS_SLASH_QUESTION_MARK 0x38
#define KS_CAPS_LOCK 0x39
#define KS_F1 0x3A
#define KS_F2 0x3B
#define KS_F3 0x3C
#define KS_F4 0x3D
#define KS_F5 0x3E
#define KS_F6 0x3F
#define KS_F7 0x40
#define KS_F8 0x41
#define KS_F9 0x42
#define KS_F10 0x43
#define KS_F11 0x44
#define KS_F12 0x45
#define KS_PRINT_SCREEN 0x46
#define KS_SCROLL_LOCK 0x47
#define KS_PAUSE 0x48
#define KS_INSERT 0x49
#define KS_HOME 0x4A
#define KS_PAGE_UP 0x4B
#define KS_DELETE 0x4C
#define KS_END 0x4D
#define KS_PAGE_DOWN 0x4E
#define KS_RIGHT_ARROW 0x4F
#define KS_LEFT_ARROW 0x50
#define KS_DOWN_ARROW 0x51
#define KS_UP_ARROW 0x52
#define KS_NUM_LOCK 0x53
#define KS_KEYPAD_SLASH 0x54
#define KS_KEYPAD_ASTERISK 0x55
#define KS_KEYPAD_MINUS 0x56
#define KS_KEYPAD_PLUS 0x57
#define KS_KEYPAD_ENTER 0x58
#define KS_KEYPAD_1_END 0x59
#define KS_KEYPAD_2_DOWN_ARROW 0x5A
#define KS_KEYPAD_3_PAGE_DOWN 0x5B
#define KS_KEYPAD_4_LEFT_ARROW 0x5C
#define KS_KEYPAD_5 0x5D
#define KS_KEYPAD_6_RIGHT_ARROW 0x5E
#define KS_KEYPAD_7_HOME 0x5F
#define KS_KEYPAD_8_UP_ARROW 0x60
#define KS_KEYPAD_9_PAGE_UP 0x61
#define KS_KEYPAD_0_INSERT 0x62
#define KS_KEYPAD_DOT_DELETE 0x63
#define KS_NON_US_BACKSLASH_PIPE 0x64
#define KS_APPLICATION 0x65
#define KS_POWER 0x66
#define KS_KEYPAD_EQUAL 0x67
#define KS_F13 0x68
#define KS_F14 0x69
#define KS_F15 0x6A
#define KS_F16 0x6B
#define KS_F17 0x6C
#define KS_F18 0x6D
#define KS_F19 0x6E
#define KS_F20 0x6F
#define KS_F21 0x70
#define KS_F22 0x71
#define KS_F23 0x72
#define KS_F24 0x73
#define KS_EXECUTE 0x74
#define KS_HELP 0x75
#define KS_MANU 0x76
#define KS_SELECT 0x77
#define KS_STOP 0x78
#define KS_AGAIN 0x79
#define KS_UNDO 0x7A
#define KS_CUT 0x7B
#define KS_COPY 0x7C
#define KS_PASTE 0x7D
#define KS_FIND 0x7E
#define KS_MUTE 0x7F
#define KS_VOLUME_UP 0x80
#define KS_VOLUME_DOWN 0x81
#define KS_LOCKING_CAPS_LOCK 0x82
#define KS_LOCKING_NUM_LOCK 0x83
#define KS_LOCKING_SCROLL_LOCK 0x84
#define KS_KEYPAD_COMMA 0x85
#define KS_KEYPAD_EQUAL_AS400 0x86
#define KS_INTERNATIONAL1 0x87
#define KS_INTERNATIONAL2 0x88
#define KS_INTERNATIONAL3 0x89
#define KS_INTERNATIONAL4 0x8A
#define KS_INTERNATIONAL5 0x8B
#define KS_INTERNATIONAL6 0x8C
#define KS_INTERNATIONAL7 0x8D
#define KS_INTERNATIONAL8 0x8E
#define KS_INTERNATIONAL9 0x8F
#define KS_LANG1 0x90
#define KS_LANG2 0x91
#define KS_LANG3 0x92
#define KS_LANG4 0x93
#define KS_LANG5 0x94
#define KS_LANG6 0x95
#define KS_LANG7 0x96
#define KS_LANG8 0x97
#define KS_LANG9 0x98
#define KS_ALTERNATE_ERASE 0x99
#define KS_SISREQ 0x9A
#define KS_CANCEL 0x9B
#define KS_CLEAR 0x9C
#define KS_PRIOR 0x9D
#define KS_RETURN 0x9E
#define KS_SEPARATOR 0x9F
#define KS_OUT 0xA0
#define KS_OPER 0xA1
#define KS_CLEAR_AGAIN 0xA2
#define KS_CRSEL_ANDPROPS 0xA3
#define KS_EXSEL 0xA4
#define KS_KEYPAD_00 0xB0
#define KS_KEYPAD_000 0xB1
#define KS_THOUSANDS_SEP 0xB2
#define KS_DECIMAL_SEP 0xB3
#define KS_CURRENCY_UNIT 0xB4
#define KS_CURRENCY_SUB_UNIT 0xB5
#define KS_KEYPAD_OPENING_PARENS 0xB6
#define KS_KEYPAD_CLOSING_PARENS 0xB7
#define KS_KEYPAD_OPENING_BRACE 0xB8
#define KS_KEYPAD_CLOSING_BRACE 0xB9
#define KS_KEYPAD_TAB 0xBA
#define KS_KEYPAD_BACKSPACE 0xBB
#define KS_KEYPAD_A 0xBC
#define KS_KEYPAD_B 0xBD
#define KS_KEYPAD_C 0xBE
#define KS_KEYPAD_D 0xBF
#define KS_KEYPAD_E 0xC0
#define KS_KEYPAD_F 0xC1
#define KS_KEYPAD_XOR 0xC2
#define KS_KEYPAD_CARET 0xC3
#define KS_KEYPAD_PERCENTAGE 0xC4
#define KS_KEYPAD_LESS_THAN 0xC5
#define KS_KEYPAD_GREATER_THAN 0xC6
#define KS_KEYPAD_AMP 0xC7
#define KS_KEYPAD_AMP_AMP 0xC8
#define KS_KEYPAD_PIPE 0xC9
#define KS_KEYPAD_PIPE_PIPE 0xCA
#define KS_KEYPAD_COLON 0xCB
#define KS_KEYPAD_HASHMARK 0xCC
#define KS_KEYPAD_SPACE 0xCD
#define KS_KEYPAD_AT 0xCE
#define KS_KEYPAD_EXCLAMATION 0xCF
#define KS_KEYPAD_MEMORY_STORE 0xD0
#define KS_KEYPAD_MEMORY_RECALL 0xD1
#define KS_KEYPAD_MEMORY_CLEAR 0xD2
#define KS_KEYPAD_MEMORY_ADD 0xD3
#define KS_KEYPAD_MEMORY_SUB 0xD4
#define KS_KEYPAD_MEMORY_MULT 0xD5
#define KS_KEYPAD_MEMORY_DIV 0xD6
#define KS_KEYPAD_PLUS_MINUS 0xD7
#define KS_KEYPAD_CLEAR 0xD8
#define KS_KEYPAD_CLEAR_ENTRY 0xD9
#define KS_KEYPAD_BINARY 0xDA
#define KS_KEYPAD_OCTAL 0xDB
#define KS_KEYPAD_DECIMAL 0xDC
#define KS_KEYPAD_HEX 0xDD
#define KS_LEFT_CTRL 0xE0
#define KS_LEFT_SHIFT 0xE1
#define KS_LEFT_ALT 0xE2
#define KS_LEFT_GUI 0xE3
#define KS_RIGHT_CTRL 0xE4
#define KS_RIGHT_SHIFT 0xE5
#define KS_RIGHT_ALT 0xE6
#define KS_RIGHT_GUI 0xE7

// Structure that holds the currently pressed keyboard keys
// and key modifiers
typedef struct
{
// Signal which modifier keys are pressed
USB_KEYBOARD_MODIFIER_t modifier_keys;
unsigned char reserved;
// Contains the key scan codes for the currently pressed keys,
// up to 6 keys at the same time
unsigned char keys[6];
} USB_KEYBOARD_t;

// Keyboard LEDs state
typedef unsigned char USB_KEYBOARD_LEDS_t;
// LEDs bit masks
#define USB_KEYBOARD_LED_NUM_LOCK (1<<0)  // Signal that Num Lock mode is currently set
#define USB_KEYBOARD_LED_CAPS_LOCK (1<<1) // Signal that Caps Lock mode is currently set
#define USB_KEYBOARD_LED_SCROLL_LOCK (1<<2) // Signal that Scroll Lock mode is currently set
#define USB_KEYBOARD_LED_COMPOSE (1<<3) // Signal that Compose mode is currently set
#define USB_KEYBOARD_LED_KANA (1<<4) // Signal that KANA mode is currently set

// Keyboard pressed key & key modifier buffer
extern USB_KEYBOARD_t usb_keyboard;
// Keyboard LEDs state, updated by the host
extern USB_KEYBOARD_LEDS_t usb_keyboard_leds;

// Sends the state of the currently pressed keys from usb_keyboard to the host.
unsigned char usb_keyboard_sendkeys(void);
// Send a single keypress to the host.
unsigned char usb_keyboard_keypress(unsigned char key_scan, USB_KEYBOARD_MODIFIER_t modifier);
#endif

#ifdef _USE_USB_HID_MOUSE_
// Mouse buttons state
typedef unsigned char USB_MOUSE_BUTTONS_t;
// Mouse button state flags
#define USB_MOUSE_BTN_LEFT (1<<0)
#define USB_MOUSE_BTN_RIGHT (1<<1)
#define USB_MOUSE_BTN_MIDDLE (1<<2)

// Structure that contains the mouse state
typedef struct
{
USB_MOUSE_BUTTONS_t buttons; // Which buttons are currently pressed
signed char x;
signed char y;
signed char wheel;
} USB_MOUSE_t;

// Current mouse state
extern USB_MOUSE_t usb_mouse;

// Moves the mouse.
// x, y and wheel range is -127 to 127.
// 0 specifies for no movement.
unsigned char usb_mouse_move(signed char x, signed char y, signed char wheel);
// Sends the mouse buttons state to the host.
unsigned char usb_mouse_buttons(USB_MOUSE_BUTTONS_t buttons);
// Sends a mouse click to the host.
unsigned char usb_mouse_click(USB_MOUSE_BUTTONS_t buttons);
#endif

#ifdef _USE_USB_HID_JOYSTICK_
// Joystick buttons state
typedef unsigned char USB_JOYSTICK_BUTTONS_t;
// Joystick button state flags
#define USB_JOYSTICK_BTN1 (1<<0) // Button 1 is pressed
#define USB_JOYSTICK_BTN2 (1<<1) // Button 2 is pressed

// Structure that contains the joystick state
typedef struct
{
signed char x; // Current joystick absolute X position [-100,100]
signed char y; // Current joystick absolute Y position [-100,100]
signed char z; // Current joystick absolute Z position [-100,100]
USB_JOYSTICK_BUTTONS_t buttons; // Which buttons are currently pressed
} USB_JOYSTICK_t;

// Current joystick state
extern USB_JOYSTICK_t usb_joystick;

// Sends joystick movement and button state to the host.
unsigned char usb_joystick_move(USB_JOYSTICK_t *joystick_state);
#endif

#pragma library usb_hid.lib

#endif
