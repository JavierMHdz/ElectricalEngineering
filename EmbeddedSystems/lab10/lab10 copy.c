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

void init_pwm(void);

char ostr[20];

// Declare global volatile variables
// to allow the main program and the ISR access them

volatile unsigned char bits, a, b;
volatile unsigned char new_state, old_state;

// Variable modified by the encoder
volatile int count = 128;

int main(void) {
	
	// Input: PORTC 4 and 5
	DDRC &= ~((1<<PC4)|(1<<PC5));
		
	// Enable pull-ups on PC4, PC5
    PORTC |= (1 << PC5 | 1 << PC4);
    
    // PWM pulse output
    DDRD |= (1 << PD6);
    
	// Set Interrupt PORTC 4 and 5
	PCICR |= (1 << PCIE1);
	
	// This line will allow enable the interrupts in the program
	PCMSK1 |= ((1<<PCINT12)|(1<<PCINT13));
    
    // Enable the interrupts
    sei();
    
    // Initialize Counter/Timer0
    init_pwm();

    // Determine the intial state
    bits = PINC;
    a = bits & (1 << PC4);
    b = bits & (1 << PC5);

    if (!b && !a)
	old_state = 0;
    else if (!b && a)
	old_state = 1;
    else if (b && !a)
	old_state = 2;
    else
	old_state = 3;

    new_state = old_state;
	
	// Loop forever
    while (1) {
	// Check for state (and count) change
        if (new_state != old_state) { // Did state change?
            //snprintf(ostr, 5, "%4d", count);
            old_state = new_state;
        }
    }
}

// Condition of the ISR will be when
// vector PCINT1 is created
ISR(PCINT1_vect){
	bits = PINC;		// Read the two encoder input at the same time
	a = bits & (1 << PC4);
	b = bits & (1 << PC5);
	old_state = new_state;
	
	// State transitions
	if (old_state == 0) {
	    if (a) {
		new_state = 1;
		count++;
	    }
	    else if (b) {
		new_state = 2;
		count--;
	    }
	}
	else if (old_state == 1) {
	    if (!a) {
		new_state = 0;
		count--;
	    }
	    else if (b) {
		new_state = 3;
		count++;
	    }
	}
	else if (old_state == 2) {
	    if (a) {
		new_state = 3;
		count--;
	    }
	    else if (!b) {
		new_state = 0;
		count++;
	    }
	}
	else {   // old_state = 3
	    if (!a) {
		new_state = 2;
		count++;
	    }
	    else if (!b) {
		new_state = 1;
		count--;
	    }
	}
	
	// Limit the count value to stay between 0 and 255
	if(count < 0){
		count = 0;
	}
	
	if(count > 255){
		count = 255;
	}
	
	// The new value is copied into the OCR0A register
	OCR0A = count;
	
}
void init_pwm(){
	// Fast PWM mode, modulus = 256
	TCCR0A |= (0b11 << WGM00);
	
	// Turn D6 on at 0x00 and off at OCR0A
	TCCR0A |= (0b10 << COM0A0);
	
	// Initial pulse duty cycle of 50%
	OCR0A = 128;
	
	// Prescaler = 1024 for 16 ms period
	TCCR0B |= (0b101 << CS00);
}