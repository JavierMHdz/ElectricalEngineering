/********************************************
*
*  Name: Javier Jesús Macossay-Hernández
*  Lab section: 2:30 pm - 3:50 pm
*  Assignment:  Lab 4 - ADC
*
********************************************/

#include <avr/io.h>
#include <util/delay.h>

void variable_delay_us(int);

unsigned short period[13] =     // Periods in microseconds for 13 tones
{ 7634, 6803, 6061, 5405, 4808, 4292, 3817, 3401, 3030, 2703, 2410, 2146, 1912 };

int main(void)
{
    // Initialize appropriate DDR and PORT registers
	
	// Set up the output
	DDRB |= (1<<PB4);

    // Initialize the ADC    
	// First, set the ADMUX Register to 0
	ADMUX = 0;
	
	// Set the high voltage selection to AVCC
	ADMUX |= (1<<REFS0);
	
	// Set to use 8 bit results
	ADMUX |= (1<<ADLAR);
	
	// Select the input channel to be used (A3)
	ADMUX |= ((1<<MUX1)|(1<<MUX0));
	
	// First, set the ADCSRA Register to 0
    ADCSRA = 0;
    
    // Configure ADPS to select the clock prescaler value
    ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
    
    // Enable the ADC Module
	ADCSRA |= (1<<ADEN);	

    while (1) {                 // Loop forever
		// Start an ADC conversion
		ADCSRA |= (1<<ADSC);
	
		while((ADCSRA & (1<<ADSC)) != 0){
			// Incomplete. This is avoiding to save unnecessary data
		}
		
		// Read the result from ADCH
		unsigned char x = ADCH;

		// Determine which tone (0-12) to play
		unsigned char range = x/20;
		
		// Calculating the value that I will pass in variable_delay_us();
		int passedValue = period[range]/2;
		
		// Generate 10 periods of the output tone
		unsigned char numPeriod = 10;
		
		while(numPeriod > 0){
			// Turn PB4 on
			PORTB |= (1<<PB4);
			variable_delay_us(passedValue);
			
			// Turn PB4 off
			PORTB &= ~(1<<PB4);
			variable_delay_us(passedValue);
			
			// Keep track of the counter
			numPeriod--;
			
		}
		// Delay for 200 ms to make the buzzer "chirp"
		_delay_ms(200);

    }

    return 0;   /* never reached */
}

/*
  variable_delay_us - Delay a variable number of microseconds
*/
void variable_delay_us(int delay)
{
    int i = (delay + 5) / 10;
    
    while (i--)
	_delay_us(10);
}
