/********************************************
*
*  Name: Javier Jesus Macossay-Hernandez
*  Section: 2:30 pm - 3:50 pm
*  Assignment: Lab 7 - Digital Stopwatch
*
********************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

#include "lcd.h"

void init_adc(void);
void init_timer1(unsigned short);

//Global variable char array to hold the time
volatile int time[] = {0,0,0};

//Global variable to hold the state information
//Stopped = 0
//Started = 1
//Lapped = 2
unsigned char state = 0;

int main(void) {
	
	/*Initializing the ADC*/
	init_adc();
	
    /*Initializing the LCD*/
	init_lcd();
	
	//Show a Splash Screen
	//Give the welcome message
	writecommand(0x01);
	char buf[16];
	snprintf(buf, 16, "Macossay");
	stringout(buf);
	
	//Splash screen
	_delay_ms(3000);
	
	//Clear the screen
	writecommand(0x01);
	
	//Display the decimal point
	moveto(0,2);
	stringout(".");
	moveto(0,0);
	writedata(time[0] + '0');
	moveto(0,1);
	writedata(time[1] + '0');
	moveto(0,3);
	writedata(time[2] + '0');
	
	/*Initializing Timer 1*/
	init_timer1(6250);
	
	//Enable interrupts
	sei();
	
	while(1){
		//Start an ADC conversion
			ADCSRA |= (1<<ADSC);
	
		while((ADCSRA & (1<<ADSC)) != 0){
			// Incomplete. This is avoiding to save unnecessary data
		}
		
		//Read the result from ADCH
		unsigned char adcresult = ADCH;
		
		//Up
		if((adcresult > 47)&&(adcresult < 55)){
			if(state != 2){
				//Toggling the state of the stopwatch
				if (state == 0){
					state = 1;
				}
				else{
					state = 0;
					
				}
			}
			else{
				//Go from state 2 to state 1
				state = 1;
			}
		}
		
		//Down
		if((adcresult > 98)&&(adcresult < 106)){
			if(state == 1){
				//Lap feature
				state = 2;
			}
			else if(state == 2){
				//Toggle back to the running display
				state = 1;
			}
			else{
				//Reset feature
				state = 0;
				time[0] = 0;
				time[1] = 0;
				time[2] = 0;
				moveto(0,0);
				writedata(time[0] + '0');
				moveto(0,1);
				writedata(time[1] + '0');
				moveto(0,3);
				writedata(time[2] + '0');
			}
		}
		
		//Add a delay just so the loop does not run fast
		_delay_ms(250);
	}
    return 0;   /* never reached */
}
void init_adc()
{
	// Initialize the ADC    
	// First, set the ADMUX Register to 0
	ADMUX = 0;
	
	// Set the high voltage selection to AVCC
	ADMUX |= (1<<REFS0);
	
	// Set to use 8 bit results
	ADMUX |= (1<<ADLAR);
		
	// First, set the ADCSRA Register to 0
    ADCSRA = 0;
    
    // Configure ADPS to select the clock prescaler value
    ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
    
    // Enable the ADC Module
	ADCSRA |= (1<<ADEN);

}
void init_timer1(unsigned short m){
	//Set to CTC mode
	TCCR1B |= (1 << WGM12);
	
	//Enable Timer Interrupt
	TIMSK1 |= (1 << OCIE1A);
	
	//Load the MAX Count
	//Assuming prescalar = 256
	//counting to 6250 =
	//0.1s w/ 16 MHz clock
	OCR1A = m;
	
	//Set prescalar = 256
	//and start counter
	TCCR1B |= (1 << CS12);	
}
ISR(TIMER1_COMPA_vect){
	//Increments every 0.1s
	
	//this two variables are to keep track of the changed time
	unsigned char tenthsChanged = 0;
	unsigned char secondsChanged = 0;
	
	if(state != 0){
		if(time[2] != 9){
			time[2]++;
		}
		else{
			time[2] = 0;
			tenthsChanged = 1;
		}
	
		if(tenthsChanged == 1){
			if(time[1] != 9){
				time[1]++;
			}
			else{
				time[1] = 0;
				secondsChanged = 1;
			}
		}
	
		if(secondsChanged == 1){
			if(time[0] != 5){
				time[0]++;
			}
			else{
				//Restarting the stopwatch screen to 00.0
				time[0] = 0;
			}
		}
	}
	
	//The ISR should update the LCD display
	if(state == 1){
		moveto(0,0);
		writedata(time[0] + '0');
		moveto(0,1);
		writedata(time[1] + '0');
		moveto(0,3);
		writedata(time[2] + '0');
	}
}