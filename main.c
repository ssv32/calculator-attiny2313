#define F_CPU 4000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0xFF;
	DDRB=0b00000000;
	
	PORTD=0b11111111;
	_delay_ms(100);	
	PORTD=0b00000000;
    int NButton=0;  //number button
	// 0  1  2  3    4    5    6    7
	// +  -  *  /  enter  Up  Down  clear
	int TimerButton=0; //TimerButton
		
		
    while(1)
    {
	PORTD=0b00000000;
		if (PINB==0b00000010) {
			NButton=1;
			TimerButton++;
			if(TimerButton>10){
				PORTD=0b00000010;
				TimerButton=0;
			}
		} else if (NButton==1) TimerButton=0;
		
		if (PINB==0b00000001) {
			NButton=2;
			TimerButton++;
			if(TimerButton>10){
				PORTD=0b00000001;
				TimerButton=0;
			}
		} else if (NButton==2) TimerButton=0;
		
		
        //TODO:: Please write your application code 
    }
	return 0;
}
