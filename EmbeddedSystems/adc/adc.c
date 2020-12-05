#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char adc_result;

    // Initialize appropriate DDR register for LED output
    DDRB |= (1 << PB5);         // Set PORTB,5 for output

    // Initialize the ADC
	ADMUX |= (1<<REFS0);	// Set for AVCC reference
	ADMUX |= (1<<MUX2);		// Set for channel 5
	ADMUX |= (1<<MUX0);
	ADMUX |= (1<<ADLAR); 	//8-bit conversion
	
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	ADCSRA |= (1<<ADEN);	// enable ADC
	
    while (1) {                 // Loop forever
        // Start a conversion, wait for it to complete, read the ADC result,
        ADCSRA |= (1<< ADSC);	// start conversion
        while (ADCSRA & (1<<ADSC)); // Loop waiting for ADSC -> 0
		adc_result = ADCH;	// get results
		
	// Fiddle with the LED
	/*if (adc_result >= 102 && adc_result <= 153)
		PORTB |= (1<<PB5); 	// Turn on LED
	else
		PORTB &= ~(1<<PB5);	// Turn off LED*/
	
	PORTB |= (1<<PB5);
	unsigned char i = 0;
	while (i < adc_result){
		_delay_ms(2);
		i++;
	}
	PORTB &=  ~(1<<PB5);
	while (i <255){
		_delay_ms(2);
		i++;
	}
    }

    return 0;   /* never reached */
}
