#include <avr/io.h>

#ifdef _SIMULATE_

#include "simAVRHeader.h"

#endif

enum States {Start, next, nextwait, wait} state;

	

unsigned char count = 0;

void main(){

state = Start;

DDRA = 0x00; PORTA = 0xFF; //DDRA is input

DDRC = 0xFF; PORTC = 0x00; //DDRB is output

while(1) {

Tick();

}

}


void Tick(){

	unsigned char A0 = ~PINA & 0x01; //A0 is 1 if button is pressed

	//unsigned char A1 = ~PINA & 0x02; //A1 is 1 if button is pressed

	switch(state){ //Transitions

		case(Start): 

			state = wait; break;

		case(wait):

			 if(A0)
				state = next;
			else
				state = wait;
			break;

		case(next):
			state = nextwait; 
			break;

		case(nextwait):

			if (!A0)
				state = wait;

			break;

		default:

			break;

	}

	switch(state){ //Action

		case(Start):

			//count = 0;

			break;

		case(wait):

			break;

		case(next):
			if(count < 0xFF)
				count = count + 0x07; 
			else
				count = 0x00;
			break;

		case(nextwait):

			break;

		default:

			break;

	}

	//set PORT

	PORTC = count;

 }

