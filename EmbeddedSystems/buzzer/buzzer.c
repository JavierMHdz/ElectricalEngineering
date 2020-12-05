#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "lcd.h"

//prototype
void variable_delay_us(int);
void init_timer1(unsigned short);
void init_buzzer(void);

volatile int millisecond = 0;

int main(void)
{
	init_lcd();
	//Initilizing timer
	init_timer1(250);

	//Initializing buzzer
	init_buzzer();

	//enable global interrupts
	sei();
	/*
	while(millisecond < 1000){
		// Turn PC4 on
		PORTC |= (1<<PC4);
		//variable_delay_us(1515);
		_delay_us(1515);
			
		// Turn PC4 off
		PORTC &= ~(1<<PC4);
		//variable_delay_us(1515);
		_delay_us(1515);*/
			
		writecommand(1);
		char buf[16];
		snprintf(buf,16, "%d", millisecond);
		stringout(buf);
	//	}
	

    return 0;   /* never reached */
}
void init_buzzer(void){
	//buzzer is in PORTC A4 - PC4
	//Output
	DDRC |= (1<<PC4);
/*
	while(millisecond < 1000){
		// Turn PC4 on
		PORTC |= (1<<PC4);
		//variable_delay_us(1515);
		_delay_us(1515);
			
		// Turn PC4 off
		PORTC &= ~(1<<PC4);
		//variable_delay_us(1515);
		_delay_us(1515);
			
		writecommand(1);
		char buf[16];
		snprintf(buf,16, "%d", millisecond);
		stringout(buf);
	}*/
}
/*
  variable_delay_us - Delay a variable number of microseconds
*//*
void variable_delay_us(int delay){
    int i = (delay + 5) / 10;
    
    while (i--)
	_delay_us(10);
}*/
void init_timer1(unsigned short m){
	//Set to CTC mode
	TCCR1B |= (1 << WGM12);
	
	//Enable Timer Interrupt
	TIMSK1 |= (1 << OCIE1A);
	
	//Load the MAX Count
	//Assuming prescalar = 64
	//counting to 250 =
	//0.001s (1 millisecond) w/ 16 MHz clock
	OCR1A = m;
	
	//Set prescalar = 64
	//and start counter
	TCCR1B &= ~(1 << CS12);
	TCCR1B |= ((1 << CS11)|(1 << CS10));
}
ISR(TIMER1_COMPA_vect){
	//increment the value of the millisecond
	millisecond++;

}