/********************************************
 *
 *  Name: Javier Jesus Macossay-Hernandez
 *  Section: 2:30 pm - 3:50 pm
 *  Assignment: Final Project - Speed Trap
 *
 ********************************************/
 #include <avr/io.h>
 #include <util/delay.h>
 #include <stdio.h>
 #include "serial.h"
 #include "speedtrap.h"

 //Find the value to go in UBRR0
 #define FOSC 16000000             //Clock frequency
 #define BAUD 9600 	               //Baud rate used
 #define MYUBRR (FOSC/16/BAUD-1)   //Value for UBRR0

 //void serial(void){}
 void enable_buffer(void){
 	//Set Pxx in D2 - PD2

 	//Output
 	DDRD |= (1<<PD2);

 	//Make Pxx a zero to let
 	//Rx get data from MAX232
 	PORTD &= ~(1<<PD2);
 }

 //Store MYUBBR in UBRR0
 //and enable Rx and Tx
 void enable_communications(void){
 	UBRR0 = MYUBRR;
 	UCSR0B |= ((1<<TXEN0)|(1<<RXEN0));	//Enable RX and TX
	UCSR0C = (3<<UCSZ00);				//Async., no parity,
										//1 stop bit, 8 data bits
	UCSR0B |= (1<<RXCIE0);				//Enable Rx interrupts
 }

//Rx routine
char rx_char(){
	//Wait for receive complete flag to go high
	while(!(UCSR0A &(1<<RXC0))){}
	return UDR0;
} 

//Tx routine
void tx_char(char ch){
	//Wait for transmitter data register empty
	while((UCSR0A & (1<<UDRE0))==0){}
	UDR0 = ch;
}

//Send data function
void send(unsigned int speedInMillimeters){
	//Convert speedInMillimeteres into a char array
	char sentData[16];
	snprintf(sentData, 16, "%d", speedInMillimeters);

	//Transmit the data
	tx_char('@');
	int i = 0;
	while(sentData[i] != NULL){
		tx_char(sentData[i]);
		i++;
	}
	tx_char('$');
}