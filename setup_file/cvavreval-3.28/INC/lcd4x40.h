/*
  LCD driver routines for 4x40 alphanumeric LCD 

  CodeVisionAVR C Compiler
  (C) 1998-2016 Pavel Haiduc, HP InfoTech S.R.L.

  CONNECTIONS:
  
  [LCD]            [AVR Port]
  RS  (pin 11) --- bit 0
  RD  (pin 10) --- bit 1
  EN1 (pin 9) ---- bit 2
  EN2 (pin 15) --- bit 3
  DB4 (pin 4) ---- bit 4
  DB5 (pin 3) ---- bit 5
  DB6 (pin 2) ---- bit 6
  DB7 (pin 1) ---- bit 7

  BEFORE #include -ING THIS FILE YOU
  MUST DECLARE THE I/O ADDRESS OF THE
  DATA REGISTER OF THE PORT AT WHICH
  THE LCD IS CONNECTED!

  EXAMPLE FOR PORTB:

    #asm
        .equ __lcd_port=0x18
    #endasm
    #include <lcd.h>

*/

#ifndef _LCD4X40_INCLUDED_
#define _LCD4X40_INCLUDED_

#define LCD_EN1 4
#define LCD_EN2 8

#pragma used+

extern unsigned char _en1_msk;

void _lcd_ready(void);
void _lcd_write_data(unsigned char data);
// write a byte to the LCD character generator or display RAM
void lcd_write_byte(unsigned char addr, unsigned char data);
// read a byte from the LCD character generator or display RAM
unsigned char lcd_read_byte(unsigned char addr);
// set the LCD display position  x=0..39 y=0..3
void lcd_gotoxy(unsigned char x, unsigned char y);
// clear the LCD
void lcd_clear(void);
void lcd_putchar(char c);
// write the string str located in SRAM to the LCD
void lcd_puts(char *str);
// write the string str located in FLASH to the LCD
void lcd_putsf(char flash *str);
// displays formatted output
int lcd_printf(flash char *fmtstr,...);
// displays formatted output at the specified x, y coordinates
int lcd_printfxy(unsigned char x, unsigned char y, flash char *fmtstr,...);
// initialize the LCD controller
unsigned char lcd_init(void);

#pragma used-
#pragma library lcd4x40.lib

#endif

