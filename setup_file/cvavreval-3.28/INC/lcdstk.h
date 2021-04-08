/* Alphanumeric LCD driver routines for the
   Kanda Systems STK200/300 development boards
   
   CodeVisionAVR C Compiler
   (C) 1998-2016 Pavel Haiduc, HP InfoTech S.R.L.

   The LCD is connected in memory mapped mode
   This driver can be used only for AVR chips
   that allow external RAM accessing
*/

#ifndef _LCDSTK_INCLUDED_
#define _LCDSTK_INCLUDED_

#define _LCD_RS0 *(unsigned char *) 0x8000
#define _LCD_RS1 *(unsigned char *) 0xc000

#pragma used+

void _lcd_ready(void);
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
unsigned char lcd_init(unsigned char lcd_columns);

#pragma used-
#pragma library lcdstk.lib

#endif

