#include <stdio.h>
#include "../inc/custom_types.h"
#include "../inc/LCD_i2c.h"

//Pico 2 includes
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"


//Reserved addresses from 000 (0xxx) to 111 (1xxx)
bool reserved_addr(u8 addr)
{
    return (((addr & 0x78) == 0) || ((addr & 0x78) == 0x78));
}

void i2c_scan()
{
    //i2c instance, baudrate in Hz, 100000 = 100 kHz
    i2c_init(I2C,100000);
    gpio_set_function(SDA,GPIO_FUNC_I2C); //GP_4 
    gpio_set_function(SCL,GPIO_FUNC_I2C); //GP_5
    gpio_pull_up(SDA);
    gpio_pull_up(SCL);

    //makes i2c pins available to picotool
    bi_decl(bi_2pins_with_func(SDA,SCL,GPIO_FUNC_I2C));

    printf("\nI2C Bus Scan\n");
    printf("   0 1 2 3 4 5 6 7 8 9 A B C D E F\n");

    for(u32 addr = 0; addr < (1 << 7); ++addr)
    {
        if(addr % 16 == 0)
        {
            printf("%02x ", addr);
        }

        i32 ret;
        u8 rx_data;
        if(reserved_addr(addr))
            ret = PICO_ERROR_GENERIC;
        else
            ret = i2c_read_blocking(I2C, addr, &rx_data, 1, false);
        printf(ret < 0 ? "." : "@");
        printf(addr % 16 == 15 ? "\n" : " ");
    }

    printf("Done.\n");
    return;
}

void set_LCD_params(LCD* lcd,u8 RS, u8 RW, u8 cmd)
{
    lcd->RS = RS;
    lcd->RW = RW;
    lcd->cmd = cmd;
    return;
}

//Follows datasheet suggested initialization
void init_LCD(LCD* lcd)
{
    i2c_init(I2C,BAUD);
    gpio_set_function(SDA,GPIO_FUNC_I2C);
    gpio_set_function(SCL,GPIO_FUNC_I2C);
    gpio_pull_up(SDA);
    gpio_pull_up(SCL);

    sleep_ms(50); //wait 50 ms for initialization of display

    //You have to initialize the display by sending a redundant signal
    //After this you need to break your commands the way I did

    lcd->BL = 1;
    set_LCD_params(lcd,0,0,INIT_SEQ);
    send_command(*lcd);
    sleep_ms(5);

    set_LCD_params(lcd,0,0,INIT_SEQ);
    send_command(*lcd);
    sleep_us(200);

    set_LCD_params(lcd,0,0,INIT_SEQ);
    send_command(*lcd);

    set_LCD_params(lcd,0,0,FUNCTION_SET);
    send_command(*lcd);
    sleep_ms(1);

    set_LCD_params(lcd,0,0,INIT_FUNCTION_SET);
    send_command(*lcd);
    sleep_ms(1);


    set_LCD_params(lcd,0,0,DISPLAY_ON_CURSOR_NO_BLINK);
    send_command(*lcd);
    sleep_ms(1);


    set_LCD_params(lcd,0,0,CLEAR_DISPLAY);
    send_command(*lcd);
    sleep_ms(3);


    set_LCD_params(lcd,0,0,ENTRY_MODE_SET);
    send_command(*lcd);
    sleep_ms(1);

    return;
}

void send_command(LCD lcd)
{
    u8 command = 0x00; //0b 0 0 0 0 0 0 0 0
    //    P7     P6       P5      P4        P3      P2  P1  P0
    //0b cmd3   cmd2     cmd1    cmd0   backlight   E   RW  RS

    u8 upper = 0;
    u8 lower = 0;

    nibble_split(&upper,&lower,lcd.cmd);

    command = (upper) | (lcd.BL << 3) |  (1 << 2);
    i2c_write_blocking(I2C,LCD_I2C_ADDR,&command, 1, false);
    command = (upper) | (lcd.BL << 3) |  (0 << 2);
    i2c_write_blocking(I2C,LCD_I2C_ADDR,&command, 1, false);

    command = (lower) | (lcd.BL << 3) |  (1 << 2);
    i2c_write_blocking(I2C,LCD_I2C_ADDR,&command, 1, false);
    command = (lower) | (lcd.BL << 3) |  (0 << 2);
    i2c_write_blocking(I2C,LCD_I2C_ADDR,&command, 1, false);

    return;
}

void send_character(LCD lcd)
{
    u8 character = 0x00; //0b 0 0 0 0 0 0 0 0
    //    P7     P6       P5      P4        P3      P2  P1  P0
    //0b cmd3   cmd2     cmd1    cmd0   backlight   E   RW  RS

    u8 upper = 0;
    u8 lower = 0;

    nibble_split(&upper,&lower,lcd.cmd);

    character = (upper) | (lcd.BL << 3) |  (1 << 2) | (lcd.RS);
    i2c_write_blocking(I2C,LCD_I2C_ADDR,&character, 1, false);
    character = (upper) | (lcd.BL << 3) |  (0 << 2) | (lcd.RS);
    i2c_write_blocking(I2C,LCD_I2C_ADDR,&character, 1, false);

    character = (lower) | (lcd.BL << 3) |  (1 << 2) | (lcd.RS);
    i2c_write_blocking(I2C,LCD_I2C_ADDR,&character, 1, false);
    character = (lower) | (lcd.BL << 3) |  (0 << 2) | (lcd.RS);
    i2c_write_blocking(I2C,LCD_I2C_ADDR,&character, 1, false);

    return;
}

void write_string(LCD* lcd, i8* chars)
{
    //Since the string is open ended none of the values will be 0 or null and if it is then the loop went beyond the ptr length
    while(*chars) 
    {
        write_char(lcd,*chars);
        chars++;
    }
    return;
}

void write_char(LCD* lcd, i8 charac)
{
    set_LCD_params(lcd,1,0,0);
    u32 pos[1];

    u8 upper = 0;
    u8 lower = 0;

    LCD_char_send(&charac,1,pos);

    u8 character = LCD_font[pos[0]];
    lcd->cmd = character;
    send_character(*lcd);
    sleep_ms(1);

    return;
}

void set_cursor(LCD* lcd,u8 col, u8 row)
{
    //col is from column 0 - 19
    //row is from 1 to 4

    if (col < 0 || col > 19 || row < 1 || row > 4)
    {
        return;
    }

    u8 position = 0;
    
    if(row == 1) {position = LINE_1_START;}

    else if(row == 2) {position = LINE_2_START;}
    
    else if(row == 3) {position = LINE_3_START;}

    else if(row == 4) {position = LINE_4_START;}

    position += col;

    position |= DDRAM_ADDR;

    lcd->cmd = position;

    send_command(*lcd);
    sleep_ms(1);
    return;
}

