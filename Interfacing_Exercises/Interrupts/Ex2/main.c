/*
 * main.c
 *
 *  Created on: May 8, 2024
 *      Author: amir
 *      Control 3 led from External Interrupt INT1
 *      16MHZ
 *      LED ON Pin 0 1 2 in PORTC
 *      Postive Logic
 *      normal every 0.5 sec rolling between them
 *      Interrupt make them blink 5 times in 5 second
 */
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
ISR(INT1_vect) {
	int i = 0;
	PORTC |= (1 << 0) | (1 << 1) | (1 << 2);
	_delay_ms(1000);
	for (i = 0; i < 4; i++) {
		PORTC ^= (1 << 0) ^ (1 << 1) ^ (1 << 2);
		_delay_ms(1000);
	}
	PORTC &= ~(1 << 0) & ~(1 << 1) & ~(1 << 2);

}

void interrupt_init() {
	DDRD &= (1 << 3);
	//PULL DOWN DONT ACTIVATE PULL UP
	PORTD &= ~(1 << 3);
	//RISING EDGE
	MCUCR |= (1 << ISC11)		;
	MCUCR &= ~(1<<ISC10);
	//ENABLE INTERRUPT 0
	GICR |= (1 << INT1);
}

int main() {

	interrupt_init();
	//Enable INTERRUPT BIT FROM GENERAL BIT 7
	SREG = (1 << 7);

	//led init
	DDRC |= (1 << 0) | (1 << 1) | (1 << 2);
	/*   AS IT IS POSTIVE LOGIC    */
	PORTC &= ~(1 << 0) & (~(1 << 1)) & (~(1 << 2));
	for (;;) {
		PORTC &= ~(1 << 2);
		PORTC |= (1 << 0);
		_delay_ms(500);

		PORTC &= ~(1 << 0);
		PORTC |= (1 << 1);
		_delay_ms(500);

		PORTC &= ~(1 << 1);
		PORTC |= (1 << 2);
		_delay_ms(500);

	}
}

