/*
 * timer.c
 *
 *  Created on: May 3, 2024
 *      Author: amir
 */
#include "timer.h"

void timer0_init(timer_mode mode, prescalar prescalar_t,
		interrupt_enable interrupt_state , unsigned int ctc_value) {

	switch (mode) {
	case OVERFLOW:
		TCNT0 = 6;
		if (interrupt_state)
			TIMSK |= (1 << TOIE0);
		break;
	case CTC:
		TCNT0 = 0;    // Set Timer initial value to 0
		OCR0=ctc_value;     //SET COMPARE VALUE VERY IMPORTANT
		if (interrupt_state)
			TIMSK |= (1 << OCIE0);
		TCCR0 |= (1 << WGM01);
		TCCR0 &= ~(1 << WGM00);
		break;
	case PWM:
		TCCR0 |= (1 << WGM00);
		TCCR0 &= ~(1 << WGM01);
		break;
	case FAST_PWM:
		TCCR0 |= (1 << WGM00) | (1 << WGM01);
		break;
	}

	switch (prescalar_t) {
	case NO_PRESCALAR:
		break;
	case prescalar0:
		TCCR0 |= (1 << CS00);
		break;
	case prescalar8:
		TCCR0 |= (1 << CS01);
		break;
	case prescalar64:
		TCCR0 |= (1 << CS01) | (1 << CS00);
		break;
	case prescalar256:
		TCCR0 |= (1 << CS02);
		break;
	case prescalar1024:
		TCCR0 |= (1 << FOC0) | (1 << CS02) | (1 << CS00);
		break;
	}

}
