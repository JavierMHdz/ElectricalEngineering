/********************************************
*
*  Name: Javier Jesús Macossay-Hernández
*  Lab section: 2:30 pm - 3:50 pm
*  Assignment: Lab 3
*
********************************************/

#include <avr/io.h>
#include <util/delay.h>

#define DOT_LENGTH  250         /* Define the length of a "dot" time in msec */

void dot(void);
void dash(void);
void makeOutput(char);
char checkInput(char);

int main(void)
{

    // Initialize appropriate DDR and PORT registers
	// Set DDRB as output
	
	DDRB |= (1 << DDB0);
	
	// Set DDRD as input
	
	DDRD &= ~((1<<DDD2)|(1<<DDD3)|(1<<DDD4));
	
	// Enable pull-up resistors
	
	PORTD |= ((1 << PD2) | (1 << PD3) | (1 << PD4));
	
    while (1) {                 // Loop forever
    	
    	//	Check if Button 1 is pressed for 'U'
    	char resultU = checkInput(PIND2);
		if (resultU == 0){
			// 	1 will be on and 0 off
			makeOutput(1);
			dot();
			makeOutput(0);
			dot();
			makeOutput(1);
			dot();
			makeOutput(0);
			dot();
			makeOutput(1);
			dash();
			makeOutput(0);
			dash();
		}
		
		// Check if Button 2 is pressed for 'S'
		char resultS = checkInput(PIND3);
		if (resultS == 0){
			makeOutput(1);
			dot();
			makeOutput(0);
			dot();
			makeOutput(1);
			dot();
			makeOutput(0);
			dot();
			makeOutput(1);
			dot();
			makeOutput(0);
			dash();
		}
		
		// Check if Button 3 is pressed for 'C'
		char resultC = checkInput(PIND4);
		if (resultC == 0){
			makeOutput(1);
			dash();
			makeOutput(0);
			dot();
			makeOutput(1);
			dot();
			makeOutput(0);
			dot();
			makeOutput(1);
			dash();
			makeOutput(0);
			dot();
			makeOutput(1);
			dot();
			makeOutput(0);
			dash();
		}
    
    }

    return 0;   /* never reached */
}

/*
  dot() - Makes the output LED blink a "dot".
*/
void dot()
{
	_delay_ms(DOT_LENGTH);
}

/*
  dash() - Makes the output LED blink a "dash".
*/
void dash()
{	
	// multiplying by three to get three times the length
	_delay_ms(3*DOT_LENGTH);
}

/*
  makeOutput() - Changes the output bit to either a zero or one.
  If the argument is zero, the bit is cleared to zero,
  otherwise it is set to a one.
*/
void makeOutput(char value)
{
    if (value == 0)
        PORTB &= ~(1 << PB0);
    else
        PORTB |= (1 << PB0);
}

/*
  checkInput(bit) - Checks the state of the input bit given as
  the argument (0-7), and returns either 0 or 1 depending on its state.
*/
char checkInput(char bit)
{
    if ((PIND & (1 << bit)) != 0)
        return(1);
    else
        return(0);
}
