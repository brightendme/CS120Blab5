/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *	https://drive.google.com/file/d/15StLrAoK_-dkqoLgL2YF-J3lhVAh4OJE/view?usp=sharing
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;  PORTA = 0xFF;
	DDRC = 0xFF;  PORTC = 0x00;
	unsigned char tempC = 0x00;
		unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char light = 0x00;   
/* Insert your solution below */
    while (1) {
	tempA = ~PINA;
	tempC = ~PINA;
	tempB = 0x00;
	light = 0x00;
	tempA = tempA & 0x0F;
	if(tempA == 0x00){
		light = 0x40;
	}
	if((tempA == 0x01) || (tempA == 0x02)){
		light = 0x60;
	}
	if((tempA == 0x03) || (tempA == 0x04)){
		light = 0x70;
	}
	if((tempA == 0x05) || (tempA == 0x06)){
		light = 0x38;
	}
	if((tempA == 0x07) || (tempA == 0x08) || (tempA == 0x09)){
		light = 0x3C;
	}
	if((tempA == 0x0A) || (tempA == 0x0B) || (tempA == 0x0C)){
		light = 0x3E;
	}
	if((tempA == 0x0D) || (tempA == 0x0E) || (tempA == 0x0F)){
		light = 0x3F;
	}
	if((tempC & 0x70) == (0x30)){
		tempB = 0x80;
	}
 	light = light | tempB;
	PORTC = light;
    }	
    return 1;
}


