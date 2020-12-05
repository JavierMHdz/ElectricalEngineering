/********************************************
*
*  Name: Javier Jesus Macossay-Hernandez
*  Section: 2:30 pm - 3:50 pm
*  Assignment: Lab 5 - Up/Down counter on LCD display
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

int main(void) {

    /* Main program goes here */
	init_lcd();

	//Current count value
	unsigned char counter = 0;
	
	//Store counting direction, 1 = up, 0 = down
	unsigned char direction = 1;
	
	//Making the counter responsive the buttons presses
	unsigned char time = 0;
	
    while (1) {               // Loop forever
		
		//PC2 is up
		if((PINC & (1<<PC2)) == 0){
			direction = 1;
		}
		//PC4 is down
		else if((PINC & (1 << PC4)) == 0){
			direction = 0;
		}
		
		if(time == 50){
				
			//Add 1 to move up or subtract 1 to move down
			if(direction == 1){
				counter += 1;
			}
			else if(direction == 0){
				//Check if we need to jump from 0 to 9
				if(counter == 0){
					counter = 9;
				}
				else{
					counter -= 1;
				}
			}
		
			//Check if we need to jump from 9 to 0
			if(counter > 9){
				counter = 0;
			}

			//Clear the screen and move to row 1, column 1
			writecommand(1);
		
			//write the count value '0'=48=0x30
			writedata(counter+48);
			
			//reset time counter
			time = 0;
		}
		else{
			time++;
		}
		_delay_ms(10);	
    }

    return 0;   /* never reached */
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
  moveto - Move the cursor to the row (1 to 2) and column (1 to 16) specified
*/
void moveto(unsigned char row, unsigned char col)
{
    /* Don't need this routine for Lab 5 */
}

/*
  stringout - Write the string pointed to by "str" at the current position
*/
void stringout(char *str)
{
    /* Don't need this routine for Lab 5 */
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
