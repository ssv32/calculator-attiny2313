#define F_CPU 4000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0xFF;
	DDRB=0b00000000;
	
	PORTD=0b11111111;
	_delay_ms(500);	
  PORTD=0b00000000;
	
    while(1)
    {
		
		if (PINB==0b00001000)   {	
			a=a-200;
			if (a<0) a=1000;
		}
		PORTD=0b11111111;
		_delay_ms(a);
		PORTD=0b00000000;
		_delay_ms(a);
		
        //TODO:: Please write your application code 
    }
    
	return 0;
}
