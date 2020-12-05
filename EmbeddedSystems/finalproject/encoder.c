/********************************************
 *
 *  Name: Javier Jesus Macossay-Hernandez
 *  Section: 2:30 pm - 3:50 pm
 *  Assignment: Final Project - Speed Trap
 *
 ********************************************/

 #include "encoder.h"
 #include "speedtrap.h"
 #include "lcd.h"
 #include <stdio.h>
 #include <avr/eeprom.h>
 #include <avr/interrupt.h>
 #include <util/delay.h>
 #include <avr/io.h>

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
    old_state = new_state;
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

		//Print change on the LCD
		unsigned int totalTime = get_time();
		unsigned int speedBeforeDecimal = get_speedbd();
		unsigned int speedAfterDecimal = get_speedad();
		unsigned int receivedSpeedBeforeDecimal = get_receivedSpeedbd();
		unsigned int receivedSpeedAfterDecimal = get_receivedSpeedad();

		//Clear the screen
 		writecommand(1);

 		//Print time out on the LCD
 		moveto(0,1);
 		char timeBuffer[16];
 		snprintf(timeBuffer, 16, "%d ms",totalTime);
 		stringout(timeBuffer);

 		//Print it out my speed on the LCD screen
 		moveto(0,12);
 		char buf[16];
 		snprintf(buf, 16, "%d.%d",speedBeforeDecimal,speedAfterDecimal);
 		stringout(buf);

 		//Print out format
 		moveto(0,9);
 		stringout("=");
 		
 		//Print out max speed on the screen
 		moveto(1,0);
 		char speedBuffer[16];
 		snprintf(speedBuffer,16, "Max=%d",speed);
 		stringout(speedBuffer);

 		//Print it out received speed in the LCD screen
 		moveto(1,12);
 		char displayBuffer[16];
 		snprintf(displayBuffer, 16, "%d.%d",receivedSpeedBeforeDecimal,receivedSpeedAfterDecimal);
 		stringout(displayBuffer);
	}
	

 }

 unsigned int get_maxSpeed(void){
	return speed;
 }
