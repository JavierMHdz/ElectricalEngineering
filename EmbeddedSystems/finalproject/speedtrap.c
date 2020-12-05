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

 //I might delete this line later
 #include <avr/interrupt.h>

 //Using the header files I created
 #include "speedtrap.h"
 #include "lcd.h"
 #include "encoder.h"
 #include "serial.h"

 //prototype for initializing sensors
 void sensors(void);

 //prototype for initializing interrupts in sensors
 void interrupts(void);

 //prototype for intializing timer1
 void init_timer1(unsigned short);

 //prototype for LCD if it exceeds max speed
 void speed_above_max(unsigned int, unsigned int);

 //prototype for buzzer
 void buzzer(void);

 //get function to get millisecond variable
 unsigned int get_time(void);

 //get function to get globalSpeedBeforeDecimal
 unsigned int get_speedbd(void);

 //get function to get globalSpeedAfterDecimal
 unsigned int get_speedad(void);

 //get function to get globalReceivedSpeedBeforeDecimal;
 unsigned int get_receivedSpeedbd(void);

 //get function to get globalReceivedSpeedAfterDecimal;
 unsigned int get_receivedSpeedad(void);

 //Define the distance between sensors as constant
 //40 holes, 0.1 inches apart each one, 4 inches
 //4 inches = 10.16 cm

 //Declare global volatile variables
 //to allow the main program and the ISR access them
 volatile unsigned char sensorOne, sensorTwo, timer;

 volatile unsigned int millisecond;

 //Global variable to act as a data started flag
 //'@' has been received
 volatile unsigned char startedFlag;

 //Global 5 byte buffer for storing the data
 //from the remote sensor
 volatile char buffer[5];

 //Global variable that tells how many data characters
 //have been received so far
 volatile unsigned int characterNum;

 //Global variable to act as a data valid flag
 //'$' has been received
 volatile unsigned char doneFlag;

 //Global variable to store received speed
 volatile unsigned int receivedSpeed;

 //Global variables to show on the LCD when rotary
 //encoder changes
 volatile unsigned int globalSpeedBeforeDecimal;
 volatile unsigned int globalSpeedAfterDecimal;

 //Global variable for received speed
 volatile unsigned int globalReceivedSpeedBeforeDecimal;
 volatile unsigned int globalReceivedSpeedAfterDecimal;

 int main(void){

 	//Initialize both sensors to ON (ON = 1)
 	sensorOne = 1;
 	sensorTwo = 1;

 	//Initialize timer
 	timer = 0;

 	//I will initialize the LCD
 	init_lcd();

 	//Give a welcome message
 	writecommand(0x01);
 	stringout("Speed Trap");

 	//Splash screen
 	_delay_ms(3000);

 	//Clear the screen
 	writecommand(0x01);

 	//Initialize sensors and LED
 	sensors();

 	//Initialize interrupts
 	interrupts();

 	//Initializing Timer 1
 	init_timer1(250);

 	//Initialize the rotary encoder
 	encoder();
 	
 	//Initialize buzzer
 	buzzer();

 	//Enable buffer
 	enable_buffer();

 	//Enable Rx and Tx
 	enable_communications();

 	//Enable global interrupts
 	sei();

 	//Loop forever, this is where I will check for the ISR
 	while(1){
 		if(doneFlag == 1){
 			//Convert buffer ASCII values into an unsigned int
 			sscanf(buffer,"%d",&receivedSpeed);

 			unsigned int receivedSpeedBeforeDecimal = receivedSpeed/10;
 			unsigned int receivedSpeedAfterDecimal = receivedSpeed%10;

 			//Save receivedSpeedBeforeDecimal and receivedSpeedAfterDecimal
 			//in the global variables
 			globalReceivedSpeedBeforeDecimal = receivedSpeedBeforeDecimal;
 			globalReceivedSpeedAfterDecimal = receivedSpeedAfterDecimal;

 			//Print it out received speed in the LCD screen
 			moveto(1,12);
 			char displayBuffer[16];
 			snprintf(displayBuffer, 16, "%d.%d",receivedSpeedBeforeDecimal,receivedSpeedAfterDecimal);
 			stringout(displayBuffer);

 			//The received speed value is the one being compared
 			//with the maximum speed set by the rotary encored
 			speed_above_max(receivedSpeedBeforeDecimal, receivedSpeedAfterDecimal);

 			doneFlag = 0;

 		}

 	}

 	return 0; /* never reached */
 }
 void sensors(void){
 	//Sensor 1, Sensor 2, and LED are connected to PORT C
 	//Sensor 1 is connected to A1 - PC1
 	DDRC &= ~(1<<PC1);
 	PORTC |= (1<<PC1);

 	//Sensor 2 is connected to A2 - PC2
 	DDRC &= ~(1<<PC2);
 	PORTC |= (1<<PC2);

 	//LED is connected to A3 - PC3
 	DDRC |= (1<<PC3);
 	PORTC &= ~(1<<PC3);
 }
 void interrupts(void){
 	//Set the PCIE1 bit in th PCICR register to enable PCINT1
 	PCICR |= (1<<PCIE1);

 	//Set the bits in the PCMSK1 to enable interrupts for PC1 Aand PC2
 	//These bits are PCINT9 and PCINT10
 	PCMSK1 |= ((1<<PCINT9)|(1<<PCINT10));

 }
 ISR(PCINT1_vect){
 	//I will get the value of both sensors
 	//to know which one was blocked (blocked = 0)
 	sensorOne = ((PINC)&(1<<PC1));
 	sensorTwo = ((PINC)&(1<<PC2));

 	//Check if Sensor 1 is blocked (blocked = 0)
 	//and timer is not counting
 	if((sensorOne == 0)&&(timer == 0)){
 		//Start timer
 		timer = 1;

 		//Set prescalar = 64
		//and start counter
		TCCR1B &= ~(1 << CS12);
		TCCR1B |= ((1 << CS11)|(1 << CS10));

 		//Set millisecond equal to 0
 		millisecond = 0;

 		//Set LED ON
 		PORTC |= (1<<PC3);

 	}
 	//Check if Sensor 2 is blocked (blocked = 0)
 	//and timer is counting
 	if((sensorTwo == 0)&&(timer == 1)){
 		//Stop timer variable
 		timer = 0;

 		//Stop the actual timer
		TCCR1B &= ~((1<< CS12)|(1 << CS11)|(1 << CS10));

 		//Set LED OFF
 		PORTC &= ~(1<<PC3);

 		//Calculate speed
 		char buf[16];
 		//Distance is 10.16 cm
 		unsigned int speedInMillimeters = 101600/millisecond;
 		//I calculate speed in Millimeters because I will
 		//Send that information to the other arduino
 		unsigned int speedBeforeDecimal = speedInMillimeters/10;
 		unsigned int speedAfterDecimal = speedInMillimeters%10;

 		//Clear the screen
 		writecommand(1);

 		//Print time out on the LCD
 		moveto(0,1);
 		char timebuf[16];
 		snprintf(timebuf, 16, "%d ms",millisecond);
 		stringout(timebuf);

 		//Print it out my speed on the LCD screen
 		moveto(0,12);
 		snprintf(buf, 16, "%d.%d",speedBeforeDecimal,speedAfterDecimal);
 		stringout(buf);

 		//Save speedBeforeDecimal and speedAfterDecimal into the global variables
 		globalSpeedBeforeDecimal = speedBeforeDecimal;
 		globalSpeedAfterDecimal = speedAfterDecimal;

 		//Print out format
 		moveto(0,9);
 		stringout("=");
 		
 		//Print out max speed on the screen
 		moveto(1,0);
 		unsigned int encoderSpeed = get_maxSpeed();
 		char speedBuffer[16];
 		snprintf(speedBuffer,16, "Max=%d",encoderSpeed);
 		stringout(speedBuffer);

 		//Send information via Tx
 		send(speedInMillimeters);

 	}
 }
void speed_above_max(unsigned int comparedSpeedBeforeDecimal, unsigned int comparedSpeedAfterDecimal){
 	
 	//Flag to check if max speed is exceeded
 	unsigned int flag = 0;
	unsigned int maxSpeed = get_maxSpeed();

	if((comparedSpeedBeforeDecimal == maxSpeed) && (comparedSpeedAfterDecimal>0)){
		flag = 1;
	}

	if(comparedSpeedBeforeDecimal > maxSpeed){
		flag = 1;
	}
		
	if(flag == 1){

		//Make the buzzer sound
		unsigned int buzzerSound = 0;
		while(buzzerSound < 100){

			// Turn PC4 on
			PORTC |= (1<<PC4);
			_delay_us(1515);
			
			// Turn PC4 off
			PORTC &= ~(1<<PC4);
			_delay_us(1515);
			buzzerSound++;
		}
	}
 	
}
void buzzer(void){
	//buzzer is in PORTC A4-PC4

	//Output
	DDRC |= (1<<PC4);

}
void init_timer1(unsigned short m){
	//Set to CTC mode
	TCCR1B |= (1 << WGM12);
	
	//Enable Timer Interrupt
	TIMSK1 |= (1 << OCIE1A);
	
	//Load the MAX Count
	//Assuming prescalar = 64
	//counting to 250 =
	//0.001s (1 millisecond) w/ 16 MHz clock
	OCR1A = m;
	
}
ISR(TIMER1_COMPA_vect){
	//increment the value of the millisecond
	millisecond++;
}
ISR(USART_RX_vect){

	char data = UDR0;

	if(data == '@'){
		//Indicate in the main program
		//that the '@' has been received
		startedFlag = 1;
		characterNum = 0;

		//Indicate that I have incomplete
		//data in the buffer
		doneFlag = 0;
	}
	//Check if the sequence has started and it is not done
	else if(startedFlag == 1){
		//Check if the data is within the range
		if((data >= '0') && (data <= '9')){
			//the size of the buffer is 5.
			//Therefore, characterNum should be
			//from 0 to 4
			if(characterNum < 5){
				//store the data
				buffer[characterNum] = data;
				characterNum++;
			}
			else{
				//Data tries to overrun the length
				//of the buffer. Therefore, I should
				//set the data started flag back to zero
				startedFlag = 0;
			}

		}
		//Check if data is '$' to finalize transmission
		else if(data == '$'){
			if(characterNum > 0){
				//Complete data in the buffer
				//Done receiving data
				doneFlag = 1;
			}

			//Clear flag that we are receiving data
			startedFlag = 0;
		}
		//If after the start of a sequence something
		//other than the number 0 through 9 or the end
		//of transmission marker '$' is received
		//reset the data started flag to zero to discard
		//what we have received so far
		else{
			startedFlag = 0;
		}

	}


}
//get functions
//get function to get millisecond variable
 unsigned int get_time(void){
 	return millisecond;
 }

 //get function to get globalSpeedBeforeDecimal
 unsigned int get_speedbd(void){
 	return globalSpeedBeforeDecimal;
 }

 //get function to get globalSpeedAfterDecimal
 unsigned int get_speedad(void){
 	return globalSpeedAfterDecimal;
 }

 //get function to get globalReceivedSpeedBeforeDecimal;
 unsigned int get_receivedSpeedbd(void){
 	return globalReceivedSpeedBeforeDecimal;
 }

 //get function to get globalReceivedSpeedAfterDecimal;
 unsigned int get_receivedSpeedad(void){
 	return globalReceivedSpeedAfterDecimal;
 }