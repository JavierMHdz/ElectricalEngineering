 #include "lcd.h"
 #include <stdio.h>
 #include <avr/eeprom.h>
 #include <avr/interrupt.h>
 #include <util/delay.h>

 //Constants for max and minimum speed
 #define MAX_SPEED 99
 #define MIN_SPEED 1

 //Declare global volatile variables
 //to allow the main program and the ISR access them
 volatile unsigned char bits, a, b;
 volatile unsigned char new_state, old_state;

 //speed variable
 volatile unsigned int speed;
 volatile unsigned int previousSpeed;

 //prototype of getter
 //unsigned int get_maxSpeed(void);
 void encoder(void);

 int main(void){
 	init_lcd();
 	encoder();
 	sei();
 	while(1){

 	}
 	return 0;
 }

 void encoder(void){
	//Input: PORTB 3 and 4 (PB3 - D11; PB4 - D12)
 	DDRB &= ~((1<<PB3)|(1<<PB4));

 	//Enable pull-up resistors
 	PORTB |= ((1<<PB3)|(1<<PB4));

 	//Enable PORTB for interrupts
 	PCICR |= (1<<PCIE0);

 	//Enable PB3 and PB4 for interrupts
 	PCMSK0 |= ((1<<PCINT3)|(1<<PCINT4));

 	//Determine the initial state
 	bits = PINB;
    a = bits & (1 << PB3);
    b = bits & (1 << PB4);

    if (!b && !a)
	old_state = 0;
    else if (!b && a)
	old_state = 1;
    else if (b && !a)
	old_state = 2;
    else
	old_state = 3;

    new_state = old_state;

    //Get previous value from memory
    unsigned int x = eeprom_read_byte((void*)200);
    writecommand(1);
    stringout("Hola");
    moveto(1,0);
    char buf[16];
    snprintf(buf,"%d",5);
    stringout(buf);
    
    //Check the speed is a valid value
    //within the range
    if((x>0) && (x<100)){
		speed = x;
    }
	else{
		speed = 50;
	}

 }

 //Conditin of the ISR will be when
 //vector PCINT0 is created
 ISR(PCINT0_vect){
 	//Read the two encoder input at the same time
 	bits = PINB;
    a = bits & (1 << PB3);
    b = bits & (1 << PB4);
    new_state = old_state;
    previousSpeed = speed;

    	// State transitions
	if (old_state == 0) {
	    if (a) {
		new_state = 1;
		speed++;
	    }
	    else if (b) {
		new_state = 2;
		speed--;
	    }
	}
	else if (old_state == 1) {
	    if (!a) {
		new_state = 0;
		speed--;
	    }
	    else if (b) {
		new_state = 3;
		speed++;
	    }
	}
	else if (old_state == 2) {
	    if (a) {
		new_state = 3;
		speed--;
	    }
	    else if (!b) {
		new_state = 0;
		speed++;
	    }
	}
	else {   // old_state = 3
	    if (!a) {
		new_state = 2;
		speed++;
	    }
	    else if (!b) {
		new_state = 1;
		speed--;
	    }
	}

	if(speed < MIN_SPEED){
		speed = MIN_SPEED;
	}

	if(speed > MAX_SPEED){
		speed = MAX_SPEED;
	}

	//Store the speed value to EEPROM
	//in address 200 only when speed changed
	if(previousSpeed != speed){
		eeprom_update_byte((void*)200,speed);
	}

	//just check if the speed changed in the LCD
	//writecommand(1);
	//char check[16];
	//snprintf(check, "%d",speed);
	//stringout(check);
	//stringout("Hola");

 }

/* unsigned int get_maxSpeed(void){
	return speed;
 }*/
