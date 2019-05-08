#include <avr/io.h>

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

