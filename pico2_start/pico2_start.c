#include <stdio.h>
#include <string.h>
//Custom includes
#include "inc/custom_types.h"
#include "inc/LCD_Font.h"
#include "inc/LCD_i2c.h"

//Pico 2 includes
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"

#define LED 25

int main()
{
    stdio_init_all();
    
    uart_init(uart0,115200);
    gpio_set_function(0, UART_FUNCSEL_NUM(uart0,0));
    gpio_set_function(1, UART_FUNCSEL_NUM(uart0,1));

    u8 rxBuffer[20];
    u8 position[2];
    u8* words;

    LCD display;
    init_LCD(&display);
    //82 00 01 08 04 02 01 00

    while (1) 
    {
        scanf("%20s",rxBuffer);

        if(strcmp(rxBuffer,"SC01") == 0)
        {
            set_cursor(&display,0,1);
        }

        else if(strcmp(rxBuffer,"SC02") == 0)
        {
            set_cursor(&display,0,2);
        }

        else if(strcmp(rxBuffer,"SC03") == 0)
        {
            set_cursor(&display,0,3);
        }

        else if(strcmp(rxBuffer,"SC04") == 0)
        {
            set_cursor(&display,0,4);
        }

        else
            write_string(&display,rxBuffer);

    }
}
