#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "uart.h"
#include "init.h"
#include "led.h"

void main()
{
        
	initPorts_B_D();
    	uart_init();

	
        //inifinte loop
	PORTB=0x20;
		
		while(1)
		{      
			char input = uart_getchar();
			uart_putchar(input);
			if(input == 'a')
			{
				blinkLEDs(100);
                  	}
			else if(input == 'b')
			{
				blinkLEDs(1000);
			}
			
			else 
			{
				blinkLEDs(500);
			}	

		} 
}