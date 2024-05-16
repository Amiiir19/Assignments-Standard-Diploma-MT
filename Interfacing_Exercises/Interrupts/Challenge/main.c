/*
 * main.c
 *
 *  Created on: May 8, 2024
 *      Author: amir
 *      Control 7segment from External Interrupt INT2
 *      1MHZ
 *      LED ON Pin 0 1 2 in PORTC
 *      Postive Logic
 *      normal every 0.5 sec rolling between them
 *      Interrupt make them blink 5 times in 5 second
 */
#define F_CPU 8000000UL
#define SET_BIT(PORT,PIN) (PORT |=(1<<PIN))
#define CLR_BIT(PORT,PIN) (PORT &=~(1<<PIN))
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int count = 0;
ISR(INT2_vect) {
	SREG &= ~(1 << 7);
	_delay_ms(100);
	if (PINB & 0X04) {
		count++;
		if (count > 9) {
			SevenSegment_Display(0);
			count = 0;
		} else {
			SevenSegment_Display(count);
		}
	}
	SREG |= (1 << 7);
}

void interrupt_init() {
	DDRB &= (1 << 2);
	//PULL DOWN DONT ACTIVATE PULL UP
	PORTB &= ~(1 << 2);
	//RISING EDGE
	MCUCSR |= (1 << ISC2);
	//ENABLE INTERRUPT 0
	GICR |= (1 << INT2);
}
void seven_segment_init() {
	//led init
	DDRC |= (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6)
			| (1 << 7);
	/*   AS IT IS POSTIVE LOGIC    */
	PORTC |= (1 << 7) | ((1 << 1)) | ((1 << 2)) | ((1 << 3)) | ((1 << 4))
			| ((1 << 5)) | ((1 << 6));
	SevenSegment_Display(0);
}
void SevenSegment_Display(unsigned char value) {
	switch (value) {
	case 0:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		CLR_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		SET_BIT(PORTC, 7);
		break;
	case 1:
		SET_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SET_BIT(PORTC, 6);
		SET_BIT(PORTC, 7);
		break;
	case 2:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		SET_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		CLR_BIT(PORTC, 5);
		SET_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 3:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SET_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 4:
		SET_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 5:
		CLR_BIT(PORTC, 1);
		SET_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 6:
		CLR_BIT(PORTC, 1);
		SET_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		CLR_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 7:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SET_BIT(PORTC, 6);
		SET_BIT(PORTC, 7);
		break;
	case 8:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		CLR_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 9:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	}
}
int main() {

	interrupt_init();
	//Enable INTERRUPT BIT FROM GENERAL BIT 7
	SREG = (1 << 7);

	seven_segment_init();
	for (;;) {

	}
}

