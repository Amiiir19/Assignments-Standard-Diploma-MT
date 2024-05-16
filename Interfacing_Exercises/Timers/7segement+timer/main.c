/*
 * main.c
 *
 *  Created on: May 3, 2024
 *      Author: amir
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "seven_segment.h"
#include "timer.h"
int step = 0;
int counter = 0;
ISR(TIMER0_OVF_vect) {
	TCNT0 = 6;
	step++;
	if (step == 31) {
		if (counter == 9) {
			SevenSegment_Display(counter);
			counter = 0;
		} else {
			SevenSegment_Display(counter);
			counter++;
		}
		step = 0;
	}
}
ISR(TIMER0_COMP_vect) {
	step++;
	if (step == 32) {
		if (counter == 9) {
			SevenSegment_Display(counter);
			counter = 0;
		} else {
			SevenSegment_Display(counter);
			counter++;
		}
		step = 0;
	}
}
int main() {
	segment_init();
	DDRC |= (1 << 0);
	SREG |= (1 << 7);
	timer0_init(CTC, prescalar1024, ENABLE_INT, 250);

	while (1) {

	}
}
