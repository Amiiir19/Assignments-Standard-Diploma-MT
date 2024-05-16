/*
 * main.c
 *
 *  Created on: May 8, 2024
 *      Author: amir
 *      Control led from External Interrupt INT0
 *      1MHZ
 *      LED ON Pin 0 in PORTC
 *      Negative logic
 *      Pull down at INT0 PD2
 */

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {
	PORTC ^= (1 << 0);
}

void interrupt_init() {
	DDRD &= (1 << 2);
	//PULL DOWN DONT ACTIVATE PULL UP
	PORTD &= ~(1 << 2);
	//RISING EDGE
	MCUCR |= (1 << ISC00) | (1 << ISC01);
	//ENABLE INTERRUPT 0
	GICR |= (1 << INT0);
}

int main() {

	interrupt_init();
	//Enable INTERRUPT BIT FROM GENERAL BIT 7
	SREG = (1 << 7);

	//led init
	DDRC |= (1 << 0);
	/*   AS IT IS NEGATIVE LOGIC    */
	PORTC |= (1 << 0); /* MAKE IT OFF */

	for (;;) {
	}
}

