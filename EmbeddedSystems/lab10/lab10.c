/********************************************
 *
 *  Name: Javier Jesus Macossay-Hernandez
 *  Section: 2:30 pm - 3:50 pm
 *  Assignment: Lab 10 - Pulse Width Modulation
 *
 ********************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>

// Values that will go in OCR1B
// Delay of 0.75 msec
#define PW_MIN 188 //187.5
// Delay of 2.25 msec
#define PW_MAX 563 //562.5

// Declare global volatile variables
// to allow the main program and the ISR access them

volatile unsigned char bits, a, b;
volatile unsigned char new_state, old_state;

// Variable modified by the encoder
volatile int count = 375;

void init_timer1(unsigned short m){
	//Set Waveform Generation Mode (Setting WGM13 - WGM10 to 1111)
	TCCR1B |= ((1 << WGM13)|(1 << WGM12));
	TCCR1A |= ((1 << WGM11)|(1 << WGM10));
	
	//Make D10 (PORTB, bit 2) serve as the pulse output
	TCCR1A |= (1 << COM1B1);
	
	//counting to 5,000 =
	//0.02s w/ 16 MHz clock
	OCR1A = m;
	
	//I will use a value halfway between two limits (1.5 msec)
	OCR1B = 375;

	//Set prescalar = 64
	//and start counter
	TCCR1B |= ((1 << CS11)|(1 << CS10));	
}
int main(void) {
	
	// Input: PORTC 4 and 5
	DDRC &= ~((1<<PC4)|(1<<PC5));
		
	// Enable pull-ups on PC4, PC5
    PORTC |= (1 << PC5 | 1 << PC4);
    
    // Pulse output
    DDRB |= (1 << PB2);
    
	// Set Interrupt PORTC 4 and 5
	PCICR |= (1 << PCIE1);
	
	// This line will allow enable the interrupts in the program
	PCMSK1 |= ((1<<PCINT12)|(1<<PCINT13));
    
    /*Initializing Timer 1*/
	init_timer1(5000);
	
	// Enable the interrupts
    sei();

    // Determine the intial state
    bits = PINC;
    a = bits & (1 << PC4);
    b = bits & (1 << PC5);

    if (!b && !a){
		old_state = 0;
	}
    else if (!b && a){
		old_state = 1;
	}
    else if (b && !a){
		old_state = 2;
	}
    else{
		old_state = 3;
	}

    new_state = old_state;
	
	// Loop forever
    while (1) {
       
    }
}

// Condition of the ISR will be when
// vector PCINT1 is created
ISR(PCINT1_vect){
	// Read the two encoder input at the same time
	bits = PINC;
	a = bits & (1 << PC4);
	b = bits & (1 << PC5);
	
	
	// State transitions
	if (old_state == 0) {
	    if (a) {
			new_state = 1;
			count+= 10;
	    }
	    else if (b) {
			new_state = 2;
			count-= 10;
	    }
	}
	else if (old_state == 1) {
	    if (!a) {
			new_state = 0;
			count-= 10;
	    }
	    else if (b) {
			new_state = 3;
			count+= 10;
	    }
	}
	else if (old_state == 2) {
	    if (a) {
			new_state = 3;
			count-= 10;
	    }
	    else if (!b) {
			new_state = 0;
			count+= 10;
	    }
	}
	else {
	    if (!a) {
			new_state = 2;
			count+= 10;
	    }
	    else if (!b) {
			new_state = 1;
			count-= 10;
	    }
	}
	
	// Limit the count value to stay between 0 and 255
	if(count < PW_MIN){
		count = PW_MIN;
	}
	
	if(count > PW_MAX){
		count = PW_MAX;
	}
	
	// The new value is copied into the OCR0A register
	OCR1B = count;
	old_state = new_state;
	
}