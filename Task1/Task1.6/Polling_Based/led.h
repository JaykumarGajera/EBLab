void delayInms(int delayms)
{
int i;
for(i=0 ; i < delayms; i++)
_delay_ms(1);
		
}

void ON_B5_to_B0(int delay)
{
	PORTB=0x20;
	delayInms(delay);
	
	int i;	
	for(i=1 ; i < 6; i++)
	{	
		PORTB = PORTB | (PORTB >> 1);
 		delayInms(delay);
	}
}

void ON_D7_to_D2(int delay)
{
	PORTD=0x80;
	delayInms(delay);

	int i;
	for(i=1 ; i < 6; i++)
	{	
		PORTD = PORTD | (PORTD >> 1);
               delayInms(delay);
	}
}

void OFF_D7_to_D2(int delay)
{
	int i;
	for(i=0 ; i < 6; i++)
	{	
		PORTD = PORTD & (PORTD << 1);
                delayInms(delay);
	}
}

void OFF_B5_to_B0(int delay)
{
	int i;
	for(i=0 ; i < 6; i++)
	{	
		PORTB = PORTB & (PORTB << 1);
               delayInms(delay);
	}
}

void blinkLEDs(int delay)
{
		ON_B5_to_B0(delay);
               
                ON_D7_to_D2(delay);
		
                OFF_D7_to_D2(delay);
		
               	OFF_B5_to_B0(delay);
}