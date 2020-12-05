/********************************************
*
*  Name: Javier Jesus Macossay-Hernandez
*  Section: 2:30 pm - 3:50 pm
*  Assignment: Lab 7 - Digital Stopwatch
*
********************************************/

#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"

void writenibble(unsigned char);

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
