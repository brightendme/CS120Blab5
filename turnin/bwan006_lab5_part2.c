#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum States {Start, inc, dec, reset, incwait, decwait, wait} state;
	
unsigned char count = 7;
	
void Tick(){
	unsigned char A0 = ~PINA & 0x01; //A0 is 1 if button is pressed
	unsigned char A1 = ~PINA & 0x02; //A1 is 1 if button is pressed
	switch(state){ //Transitions
		case(Start): 
			state = wait; break;
		case(wait):
			if(A0 && A1)
				state = reset;
			else if(A0)
				state = inc;
			else if(A1)
				state = dec;
			break;
		case(reset):
			state = wait; break;
		case(inc):
				state = incwait; 
			break;
		case(dec):
				state = decwait; 
			break;
		case(incwait):
			if (!A0)
				state = wait;
			break;
		case(decwait):
			if (!A1)
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
		case(inc):
			if (count < 9)
				count++; 
			break;
		case(dec):
			if (count > 0)
				count--; 
			break;
		case(reset):
			count = 0x00;
		       	break;
		case(incwait):
			break;
		case(decwait):
			break;
		default:
			break;
	}
	//set PORT
	PORTC = count;
 }

int main(){
	//initialize the state machine and start state
	//B = 0x00;
	state = Start;
	//Program start
	DDRA = 0x00; PORTA = 0xFF; //DDRA is input
	DDRC = 0xFF; PORTC = 0x00; //DDRB is output
	while(1) {Tick();}
}
