#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "lcd.h"

int main(){
	init_lcd();
	int x = 5;
	char buf[16];
	snprintf(buf,16, "%d", x);
	writecommand(1);
	stringout(buf);
	moveto(1,0);
	
	int i = 0;
	while(buf[i] != NULL){
		if(buf[i] == '5'){
			stringout("works");
		}
		i++;
	}
	
	while(1){
		
	}
	return 0;
}