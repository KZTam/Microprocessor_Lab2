/*
 * Lab2Exp1.c
 *
 * Created: 19/11/2024 8:52:14 AM
 * Author : tamka
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 10000000

//if want 800ms delay, just call this function 4 times
void Delay200msUsingTimer0(void){
	TCNT0 = 255 - 194;	//timer count = 194 if 200ms delay
	TCCR0 = (1<<CS02)|(1<<CS00);	//PSC =1024, mode = normal
	
	volatile uint8_t TIFRdata;
	do{
		TIFRdata = TIFR & (1<<TOV0);
	}while(!TIFRdata);
	
	TIFR |= TIFRdata;
}

void Timer0Delay(int num){
	Delay200msUsingTimer0();
	Delay200msUsingTimer0();
	if(num == 8){
		Delay200msUsingTimer0();
		Delay200msUsingTimer0();
	}
}

/*
uint8_t Get_Timer_Count(int ms, int psc){
	float period, count;
	
	period = (float) psc/ F_CPU;
	count = (float) ms/ period - 1;
	
	return (uint8_t) count;
}

void DelayTimer0(int ms){
	
}
*/

void seven_seg(char character){
	/*
	* display bit format = dp, g, f, e, d, c, b, a
	*/
	uint8_t display;
	switch (character)
	{
	case 'A':
		display = 0b10001000;
		break;
	case 'B':
		display = 0b10000011;
		break;
	case 'C':
		display = 0b11000110;
		break;
	case 'D':
		display = 0b10100001;
		break;
	case 'E':
		display = 0b10000110;
		break;
	case 'F':
		display = 0b10001110;
		break;
	case 'G':
		display = 0b10010000;	//9
		break;
	case 'H':
		display = 0b10001001;
		break;	
	case 'I':
		display = 0b11001111;
		break;
	case 'J':
		display = 0b11100001;
		break;
	case 'K':
		display = 0b10001001;	//H
		break;
	case 'L':
		display = 0b11000111;	//L
		break;
	case 'M':
		display = 0b11101010;
		break;
	case 'N':
		display = 0b10101011;
		break;
	case 'O':
		display = 0b11000000;	//0
		break;
	case 'P':
		display = 0b10001100;
		break;	//here
	case 'Q':
		display = 0b10011000;
		break;
	case 'R':
		display = 0b10101111;	//r
		break;
	case 'S':
		display = 0b10010010;
		break;
	case 'T':
		display = 0b10000111;	//t
		break;
	case 'U':
		display = 0b11000001;
		break;
	case 'V':
		display = 0b11100011;	//v
		break;
	case 'W':
		display = 0b11010101;	//
		break;
	case 'X':
		display = 0b10001001;	//H
		break;
	case 'Y':
		display = 0b10010001;
		break;
	case 'Z':
		display = 0b10100100;	//2
		break;
	case '0':
		display = 0b11000000;	//O
		break;
	case '1':
		display = 0b10000110;	
		break;
	case '2':
		display = 0b10100100;	//Z
		break;
	case '3':
		display = 0b10110000;
		break;
	case '4':
		display = 0b10011001;	//4
		break;
	case '5':
		display = 0b10010010;	//S
		break;
	case '6':
		display = 0b10000010;
		break;
	case '7':
		display = 0b11111000;
		break;
	case '8':
		display = 0b10000000;	
		break;
	case '9':
		display = 0b10010000;	//9
		break;	
	default:
		display = 0b10111111;	//-
		break;	
	}
	
	PORTB = display;	//if all inverted, just put a NOT in front of display variable. Change port can configure here.
}

void SKEE3732_304(){	//Year 3 alr still using blocking delay haiyaaaaaa
	seven_seg('S');
	Timer0Delay(8);
	seven_seg('K');
	Timer0Delay(8);
	seven_seg('E');
	Timer0Delay(8);
	seven_seg('E');
	Timer0Delay(8);
	seven_seg('3');
	Timer0Delay(8);
	seven_seg('7');
	Timer0Delay(8);
	seven_seg('3');
	Timer0Delay(8);
	seven_seg('2');
	Timer0Delay(8);
	seven_seg('-');
	Timer0Delay(8);
	seven_seg('3');
	Timer0Delay(8);
	seven_seg('0');
	Timer0Delay(8);
	seven_seg('4');
	Timer0Delay(8);
}

void Custom(){	//Year 3 alr still using blocking delay haiyaaaaaa
	seven_seg('I');
	Timer0Delay(8);
	seven_seg('-');
	Timer0Delay(8);
	seven_seg('L');
	Timer0Delay(8);
	seven_seg('O');
	Timer0Delay(8);
	seven_seg('V');
	Timer0Delay(8);
	seven_seg('E');
	Timer0Delay(8);
	seven_seg('-');
	Timer0Delay(8);

	seven_seg('C');
	Timer0Delay(8);
	seven_seg('H');
	Timer0Delay(8);
	seven_seg('E');
	Timer0Delay(8);
	seven_seg('W');
	Timer0Delay(8);
		
	seven_seg('J');
	Timer0Delay(8);
	seven_seg('I');
	Timer0Delay(8);
	seven_seg('N');
	Timer0Delay(8);	
	seven_seg('G');
	Timer0Delay(8);
	
	seven_seg('W');
	Timer0Delay(8);
	seven_seg('E');
	Timer0Delay(8);
	seven_seg('N');
	Timer0Delay(8);
/*	
	seven_seg('K');
	Timer0Delay(8);
	seven_seg('E');
	Timer0Delay(8);
	seven_seg('K');
	Timer0Delay(8);
	seven_seg('E');
	Timer0Delay(8);
*/	
} 

void SW2_code(){	//active low LED
	PORTA = 0b00110011;
	Timer0Delay(4);
	PORTA = 0b11001100;
	Timer0Delay(4);
}

void SW3_code(){
	PORTA = 0b11100111;
	Timer0Delay(4);
	PORTA = 0b11011011;
	Timer0Delay(4);
	PORTA = 0b10111101;
	Timer0Delay(4);
	PORTA = 0b01111110;
	Timer0Delay(4);
	PORTA = 0b10111101;
	Timer0Delay(4);
	PORTA = 0b11011011;
	Timer0Delay(4);
	PORTA = 0b11100111;
	Timer0Delay(4);
}

void SubExperiment5(){
	if(PIND == 0b11111011){
		SW2_code();
	}else if(PIND == 0b11110111){
		SW3_code();
	}else{
		SKEE3732_304();
		//Custom();
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRD = 0;
	PORTD = 0xFF;
	PORTA = 0xFF;
	PORTB = 0xFF;
	
	while(PIND == 0b11111111);	//before start, press any button
	
    while (1) 
    {
		/*
		if(PIND == 0b11111110){
			PORTA = 0xFE;
			_delay_ms(1000);
			PORTA = 0xFF;
			_delay_ms(1000);
		}
		else if(PIND == 0b11111101){
			PORTA = 0xF0;
			_delay_ms(1000);
			PORTA = 0xFF;
			_delay_ms(1000);			
		}
		else{
			PORTA = 0xFF;
			PORTB = 0x92;
			_delay_ms(1000);
			PORTB = 0x89;
			_delay_ms(1000);
			PORTB = 0x86;
			_delay_ms(1000);
			PORTB = 0xFF;
			_delay_ms(1000);			
		}
		*/
		SubExperiment5();
    }
}

