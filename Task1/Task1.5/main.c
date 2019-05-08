#include <avr/io.h>
#include <util/delay.h>
#include "init.h"
#include "led.h"

#define delay 500



void main()
{
        
	initPorts_B_D();
	
        //inifinte loop
	while(1)
	{      
	  blinkLEDs(delay);	
	} 
}