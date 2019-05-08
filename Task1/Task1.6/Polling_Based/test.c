#include <avr/io.h>
#include <util/delay.h>

#include <stdlib.h>

#define delay 500
#define delay1 1000

#define BAUD 9600    
#include <util/setbaud.h>
                       // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)    // set baudrate value for UBRR
#ifndef F_CPU
#define F_CPU 16000000UL                    // set the CPU clock
#endif
  
#include <util/setbaud.h>

void uart_init(void)
 {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */
}
  
void uart_putchar(char c) 
{
    loop_until_bit_is_set(UCSR0A, UDRE0); /* Wait until data register empty. */
    UDR0 = c;
}

char uart_getchar(void) 
{
    loop_until_bit_is_set(UCSR0A, RXC0); /* Wait until data exists. */
    return UDR0;
}
 
void initPortB()
{
  DDRB=0x3F;   //B0-B5 = 0011 1111
  PORTB=0x00;
}

void initPortD()
{
  DDRD=0xFC; //D2-D7 = 1111 1100
  PORTD=0x00;
}

void initPorts_B_D()
{
  initPortB();
  initPortD();
}





void main()
{
        
	initPorts_B_D();
    	uart_init();

	unsigned char a;
	int DL;
    
	
        //inifinte loop
	
		while(1)
		{      
			a=uart_getchar();
			
			if(a == 'o' || a == 'O')
			{	
				ON_B5_to_B0(DL);
               
              		  	ON_D7_to_D2(DL);
				
				OFF_D7_to_D2(DL);
		
               			OFF_B5_to_B0(DL);
			}
		
		} 
}