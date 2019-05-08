#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "uart.h"
#include "init.h"
#include "led.h"

#define defaultDelay 300

ISR(USART_RX_vect)
{
			PORTB=0x00;
			PORTD=0x00;
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
}

void main()
{
	      
	initPorts_B_D();
    	uart_init();
	sei();
	
        //inifinte loop
	PORTB=0x20;
		
		while(1)
		{      
			blinkLEDs(defaultDelay);
		} 
}





