#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum States{Start, ADD, SUB, WAIT,RESET} state;
//unsigned char tempC = 0x07;
void Tick();
int main(void) {
    /* Insert DDR and PORT initializations */
 	DDRA = 0x00;  PORTA = 0xFF;
	DDRC = 0xFF;  PORTC = 0x07;
	state = Start;	
    /* Insert your solution below */
    while (1) {
	Tick();
    }
    return 1;
}
void Tick(){
	switch(state){ //Transitions
		case Start:
		state =WAIT;
		break;
		
		case WAIT:
		if((~PINA & 0x03) == 0x01)
		{
			state = ADD;
			 break;
		}
		else if((~PINA & 0x03) == 0x02)
		{
			state = SUB; 
			break;
		}
		else if((~PINA & 0x03) == 0x03)
		{
			state = RESET; 
			break;
		}
		else
		{
			state = WAIT; 
			break;
		}
		
		case ADD:
		if((~PINA & 0x03) == 0x00){
		state = WAIT;
		break;
		}

		break;

		case SUB:
		if((~PINA & 0x03) == 0x00){
		state = WAIT;
		break;
		}
		break;

		case RESET:
		state = WAIT;
		break;
		
		default:
		state = WAIT;
		break;
	}
	switch(state){ //State actions
		case Start:
		//PORTC  = 0x05;
		//tempC = 0x07;
		break;
		
		case WAIT:
		break;
		
		case ADD:
		if(PORTC != 0x09){
			//tempC = tempC + 0x01;
			PORTC = PORTC + 0x01;
			//break;
		}
		break;
		
		
		case SUB:
		if(PORTC != 0x00){
			PORTC = PORTC - 0x01;
		        break;	
		}
		break;
		
		case RESET:
		PORTC = 0x00;
		break;
		
		default:
		break;
	}
}
