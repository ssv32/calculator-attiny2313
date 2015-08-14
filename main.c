/*
 * GccApplication5.c
 *
 * Created: 02.08.2015 11:01:02
 *  Author: ssv
 */ 

#define F_CPU 4000000L
#include <avr/io.h>
#include <util/delay.h>

int a=0; //number1 and result
int b=0; //number2
int NOperation=0;
// operation
// 0  1  2  3  4
//    +  -  *  /
int PrintStatus(int numd){
	PORTD=0b00000001<<numd;
	return 0;
}
int GetNumber(int up, int StepProg){
	if (StepProg==1) {
		if (up==0) a++;
		if (up==1) a--;
		PrintStatus(a);
	}
	if (StepProg==2) {
		if (up==0) b++;
		if (up==1) b--;
		PrintStatus(b);
	}
	return 0;
}

int Operation(int NOp, int StepProg){
	if (StepProg==3) {
	NOperation=NOp;
	PORTD=0b10000000>>NOp;
	_delay_ms(100);
	}
	return 0;
}

int GetStatus(int StepProg){
	if (StepProg<=2) {
		StepProg++;
		PORTD=0b01000000;// please input
	}
 	if (StepProg==3)  {
		if (NOperation==1) a=a+b;
		if (NOperation==2) a=a-b;
		PrintStatus(a); 
	} 
	return StepProg;
}

int main(void)
{
	DDRD=0xFF;
	DDRB=0b00000000;
	
	PORTD=0b11111111;
	_delay_ms(100);	
	PORTD=0b01000000; // please input
    int NButton=0;  //number button
	//  0     1  2  3    4    5    6    7
	//  +     -  *  /  enter  Up  Down  clear
	//repeat
	int TimerButton=0; //TimerButton
	int StepProgram=0;	
	
		
    while(1)
    {
		//PORTD=0b01000000; // please input
		
		if (PINB==0b00000001) {  //+
			NButton=1;
			TimerButton++;
			if(TimerButton>10){
				//PORTD=0b00000001;
				Operation(1,StepProgram);
				TimerButton=0;
			}
		} else if (NButton==1) TimerButton=0;
		
		if (PINB==0b00000010) {  //-
			NButton=2;
			TimerButton++;
			if(TimerButton>10){
				//PORTD=0b00000010;
				Operation(2,StepProgram);
				TimerButton=0;
			}
		} else if (NButton==2) TimerButton=0;
		
		if (PINB==0b00010000) {  //  Enter
			NButton=4;
			TimerButton++;
			if(TimerButton>10){
				StepProgram=GetStatus(StepProgram);
				//PORTD=0b00000000;
				TimerButton=0;
			}
		} else if (NButton==4) TimerButton=0;
		
		if (PINB==0b00100000) {  //  Up
			NButton=5;
			TimerButton++;
			if(TimerButton>10){
				//PORTD=0b00000010;
				GetNumber(0,StepProgram);
				TimerButton=0;
			}
		} else if (NButton==5) TimerButton=0;
			
		if (PINB==0b01000000) {  //  Down
			NButton=6;
			TimerButton++;
			if(TimerButton>10){
				//PORTD=0b00000010;
				GetNumber(1,StepProgram);
				TimerButton=0;
			}
		} else if (NButton==6) TimerButton=0;
				
		if (PINB==0b10000000) {  //  Clear
			NButton=7;
			TimerButton++;
			if(TimerButton>10){
				//PORTD=0b00000010;
				TimerButton=0;
			}
		} else if (NButton==7) TimerButton=0;
        //TODO:: Please write your application code 
    }
	return 0;
}
