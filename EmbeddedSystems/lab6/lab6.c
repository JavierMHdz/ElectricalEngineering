/********************************************
*
*  Name: Javier Jesus Macossay-Hernandez
*  Section: 2:30 pm - 3:50 pm
*  Assignment: Lab 6 - Writing Strings to the LCD Display
*
********************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void init_lcd(void);
void moveto(unsigned char, unsigned char);
void stringout(char *);
void writecommand(unsigned char);
void writedata(unsigned char);
void writenibble(unsigned char);
void init_adc(void);

int main(void) {
	/*Initializing the ADC*/
	init_adc();
	
    /* Main program goes here */
	init_lcd();
	
	/*Give the welcome message*/
	writecommand(0x01);
	stringout("Javier");
	
	//Write my birthday
	moveto(1,0);
	char date[30];
	unsigned char month, day, year;
	month = 2;
	day = 3;
	year = 94;
	snprintf(date, 30, "Birthday is %d/%d/%d",month,day,year);
	stringout(date);
	
	//Splash screen
	_delay_ms(2000);
	
	//Clear the screen
	writecommand(0x01);
	
	//Define playing field
	char row0[] = "  ##      ##    ";
	char row1[] = "     ## #     #F";
	stringout(row0);
	moveto(1,0);
	stringout(row1);
	
	//Initialized the variables for the player's position
	moveto(0,0);
	stringout("*");
	//track number of moves
	unsigned char moves = 0;
	
	//set position of rows and cols
	char positionRow = 0;
	char positionCol = 0;
	char previousRow = 0;
	char previousCol = 0;
	
	//get out of the game loop when finish equals 1
	unsigned char finished = 0;
	
	//check if the user won
	unsigned char won = 0;
	
	//Game Loop
    while (finished != 1) {
    		
		// Start an ADC conversion
		ADCSRA |= (1<<ADSC);
	
		while((ADCSRA & (1<<ADSC)) != 0){
			// Incomplete. This is avoiding to save unnecessary data
		}
		
		// Read the result from ADCH
		unsigned char adcresult = ADCH;
		
		if(adcresult != 255){
			//save the previous location
			previousRow = positionRow;
			previousCol = positionCol;
		
			//Move to left
			if((adcresult > 152) && (adcresult < 160)){
					positionCol--;
					moves++;
			}
		
			//Move to right
			else if(adcresult == 0){
					positionCol++;
					moves++;
			}
		
			//Move up
			else if((adcresult > 47)&&(adcresult < 55)){
					positionRow--;
					moves++;
			}
		
			//Move down
			else if((adcresult > 98)&&(adcresult < 106)){
					positionRow++;
					moves++;
			}

			//player won
			if((positionRow == 1)&(positionCol == 15)){
				finished = 1;
				won = 1;
			}
			else{
				//player out of bound
				if((positionRow < 0)||(positionRow > 1)){
					finished = 1;
				}
				if((positionCol < 0)||(positionCol > 15)){
					finished = 1;
				}
			
				//move the player to another position
				if((positionRow == 0)&&(row0[positionCol]== ' ')){
					moveto(previousRow, previousCol);
					stringout(" ");
					moveto(positionRow, positionCol);
					stringout("*");
				}
				else if((positionRow == 1)&&(row1[positionCol]== ' ')){
					moveto(previousRow, previousCol);
					stringout(" ");
					moveto(positionRow, positionCol);
					stringout("*");
				}
				else{
					finished = 1;
				}
			}
			
			_delay_ms(250);

		}
			
	}
	
	//Clear the screen
	writecommand(0x01);
	if(won == 1){
		stringout("You Win!");
	}
	else{
		stringout("You Lose!");
	}
	moveto(1,0);
	char buf[10];
	snprintf(buf,10, "Moves: %d",moves);
	stringout(buf);
	
	while(1){
		//waiting to be reset
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

/*
  init_lcd - Configure the I/O ports and send the initialization commands
*/
void init_lcd()
{
    /* ??? */                   // Set the DDR register bits for ports B and D
	DDRB |= ((1<<PB0)|(1<<PB1));
	DDRD |= ((1<<PD7)|(1<<PD6)|(1<<PD5)|(1<<PD4));
	
	//Configure the two Port C input lines
	DDRC &= ~((1<<PC2)|(1<<PC4));
	
	//Enable the pull-up resistors
	PORTC |= ((1<<PC2)|(1<<PC4));
	
    _delay_ms(15);              // Delay at least 15ms

	//2)Use writenibble to send 0011
    unsigned char sendInfo = 0x30;
    writenibble(sendInfo);
    
    _delay_ms(5);               // Delay at least 4msec

    //3)Use writenibble to send 0011
    writenibble(sendInfo);
    _delay_us(120);             // Delay at least 100usec

    //4)Use writenibble to send 0011, no delay needed
	writenibble(sendInfo);
	
    //5)Use writenibble to send 0010
    unsigned char sendInfo2 = 0x20;
    writenibble(sendInfo2);
    
    _delay_ms(2);               // Delay at least 2ms
    
    writecommand(0x28);         // Function Set: 4-bit interface, 2 lines
	_delay_ms(2);
	
    writecommand(0x0f);         // Display and cursor on
    _delay_ms(2);

}

/*
  moveto - Move the cursor to the row (0 to 1) and column (0 to 15) specified
*/
void moveto(unsigned char row, unsigned char col)
{
    /* Don't need this routine for Lab 5 */
    
    //Variable that describes the address
    unsigned char address;
    
    //Set the value of the row
    if(row == 0){
    	address = 0x00;
    }
    else{
    	address = 0x40;
    }
    
    //Set the value of the columns
    address += col;
    
    writecommand(0x80+address);
}

/*
  stringout - Write the string pointed to by "str" at the current position
*/
void stringout(char *str)
{
    /* Don't need this routine for Lab 5 */
    //check individual characters
    unsigned char position = 0;
    while(str[position] != 0x00){
    	writedata(str[position]);
    	position++;
    }
}

/*
  writecommand - Send the 8-bit byte "cmd" to the LCD command register
*/
void writecommand(unsigned char cmd)
{
	//1)Configure the Register Select
	PORTB &= ~(1<<PB0);
	
	//2)Call the writenibble for the upper four bits of data
	writenibble(cmd);
	
	//3)Move the lower 4 bits, I saved it in another variable
	unsigned char lowerCMD = (cmd<<4);
	
	//4)Call the writtenibble for the last bits
	writenibble(lowerCMD);
	
	//5)Wait 2msec
	_delay_ms(2);
}

/*
  writedata - Send the 8-bit byte "dat" to the LCD data register
*/
void writedata(unsigned char dat)
{
	//1)Configure the Register Select
	PORTB |= (1<<PB0);
	
	//2)Call the writenibble for the upper four bits of data
	writenibble(dat);
	
	//3)Move the lower 4 bits, I saved it in another variable
	unsigned char lowerDAT = (dat<<4);
	
	//4)Call the writtenibble for the last bits
	writenibble(lowerDAT);
	
	//5)Wait 2msec
	_delay_ms(2);
}

/*
  writenibble - Send four bits of the byte "lcdbits" to the LCD
*/
void writenibble(unsigned char lcdbits)
{
	unsigned char maskbits = 0xF0;
	
	//Clearing the four upper bits to 0
	PORTD &= ~(maskbits);
	
	//Copying the information
	PORTD |= (maskbits & lcdbits);
	
	//Set E to 1
	PORTB |= (1<<PB1);
	
	//Make E longer
	PORTB |= (1<<PB1);
		
	//Set E to 0
	PORTB &= ~(1<<PB1);
}
