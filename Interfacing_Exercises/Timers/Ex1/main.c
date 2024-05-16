/*
 * main.c
 *
 *  Created on: May 3, 2024
 *      Author: amir
 *      Write Embedded C Code to control led using timer0
 *      on    1 MHz ClocK  " Internal "
 *      Led on PORTC pin 0
 *      F_CPU/1024
 *      Toggle every half second
 *      Use Interrupt Technique
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
int step = 0;

ISR(TIMER0_OVF_vect) {
	TCNT0=6;
	step++;
	if (step == 62) {
		PORTC ^= (1 << 0);
		step = 0;
	}
}

int main() {

	DDRC |= (1 << 0);
	PORTC &= ~(1 << 0);
	SREG  |= (1<<7);
	timer0_init(OVERFLOW, prescalar1024, ENABLE_INT);

	while (1) {

	}

}

