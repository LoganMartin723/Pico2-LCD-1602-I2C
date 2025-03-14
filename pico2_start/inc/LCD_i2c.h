#ifndef LCD_I2C_H_INCLUDED
#define LCD_I2C_H_INCLUDED

#include "custom_types.h"
#include "LCD_Font.h"
#include "hardware/i2c.h"

//I2C adapter chip is PCF8574A
#define LCD_I2C_ADDR 0x27

/**
 * I2C_NUM could be any of the following:
 * i2c0 or i2c1
 */
#define I2C i2c0 //(__CONCAT(i2c,0))

/**
 * SDA could be any of the following gpio pins (GP4 is the default):
 * I2C0 (GPx, x being the first value):
 * 0(pin 1), 4(pin 6), 8(pin 11), 12(pin 16), 20(pin 26), 16(pin 21)
 * 
 * I2C1:
 * 2(pin 4), 6(pin 9), 10(pin 14), 14(pin 19), 26(pin 31), 18(pin 24)
 */
#define SDA 4

/**
 * SCL could be any of the following gpio pins (GP_4 is the default):
 * I2C0 (GPx, x being the first value):
 * 1(pin 2), 5(pin 7), 9(pin 12), 13(pin 17), 21(pin 27), 17(pin 22)
 * 
 * I2C1:
 * 3(pin 5), 7(pin 10), 11(pin 15), 15(pin 20), 27(pin 32), 19(pin 25)
 */
#define SCL 5

#define BAUD 100000
//DDRAM (Display Data Random Access Memory)
//DDRAM is set in the AC (address control) register
//Addr range 0x00 - 0x67

void i2c_scan();


#define INIT_SEQ 0x30
//Instruction Macros (4-bit interface P7-P4 to DB7-DB4) (Initialization process)
#define INIT_FUNCTION_SET 0x28
#define FUNCTION_SET 0x20                  //0b N F 1 0:: N = 1: 2-line, F = 0: 5 x 8 font
#define DISPLAY_ON_NO_CURSOR 0x0C          //0b 1 D C B:: D = 1: display on, C = 0: Cursor off, B = 0: Blinking cursor off
#define DISPLAY_ON_CURSOR_NO_BLINK 0x0E    //0b 1 D C B:: D = 1: display on, C = 0: Cursor off, B = 0: Blinking cursor off
#define DISPLAY_ON_CURSOR_BLINK 0x0F       //0b 1 D C B:: D = 1: display on, C = 0: Cursor off, B = 0: Blinking cursor off
#define DISPLAY_OFF 0x08                   //0b 1 D C B:: D = 0: display off, C = 0: Cursor off, B = 0: Blinking cursor off
#define CLEAR_DISPLAY 0x01 
#define ENTRY_MODE_SET 0x06                //0b 0 1 I/D S:: I/D = 1: increment, S = 0: Accompanies display shift

#define DDRAM_ADDR 0x80

#define LINE_1_START 0x00
#define LINE_1_END 0x13

#define LINE_2_START 0x40
#define LINE_2_END 0x53

#define LINE_3_START 0x14
#define LINE_3_END 0x27

#define LINE_4_START 0x54
#define LINE_4_END 0x67

/**
 * The i2c module "PCF8574T" only has 8 pins for writing data to a peripheral (P0,P1,P2,P3,P4,P5,P6,P7)
 * I2C module to LCD pins:
 * -P0: RS
 * -P1: R/W
 * -P2: E
 * -P3: Backlight
 * -P4: DB4
 * -P5: DB5
 * -P6: DB6
 * -P7: DB7
 * To interface with LCD it will need to be in 4-bit mode
 */
typedef struct
{
    u8 RS; //P0
    u8 RW; //P1
    u8 E; //P2
    u8 BL; //P3
    u8 cmd; //P4-P7 for commands not writing chars
}LCD;



void i2c_scan();

void init_LCD(LCD* lcd);

void send_command(LCD lcd);

void send_character(LCD lcd);

void write_char(LCD* lcd, i8 charac);

void write_string(LCD* lcd, i8* chars);

void set_LCD_params(LCD* lcd,u8 RS, u8 RW, u8 cmd);

void set_cursor(LCD* lcd, u8 col, u8 row);


#endif