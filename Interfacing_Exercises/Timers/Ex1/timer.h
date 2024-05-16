/*
 * timer.h
 *
 *  Created on: May 3, 2024
 *      Author: amir
 */
#include <avr/io.h>

#ifndef TIMER_H_
#define TIMER_H_
typedef enum timer_mode {
	OVERFLOW, PWM, CTC, FAST_PWM
} timer_mode;
typedef enum timer_num {
	TIMER0, TIMER1, TIMER2
} timer_num;
typedef enum prescalar {
	NO_PRESCALAR,
	prescalar0,
	prescalar8,
	prescalar64,
	prescalar256,
	prescalar1024
} prescalar;
typedef enum interrupt_enable {
	DISABLE_INT, ENABLE_INT
} interrupt_enable;
void timer0_init(timer_mode mode, prescalar prescalar_t,
		interrupt_enable interrupt_state) {
	TCNT0 = 6;
	switch (mode) {
	case OVERFLOW:
		if (interrupt_state)
			TIMSK |= (1 << TOIE0);
		break;
	case CTC:
		TCCR0 &= ~(1 << WGM00);
		break;
	case PWM:
		TCCR0 &= ~(1 << WGM00);
		break;
	case FAST_PWM:
		TCCR0 &= ~(1 << WGM00);
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

#endif /* TIMER_H_ */
