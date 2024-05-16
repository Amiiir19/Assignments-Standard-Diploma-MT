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

//functions

void timer0_init(timer_mode mode, prescalar prescalar_t,
		interrupt_enable interrupt_state, unsigned int ctc_value);

#endif /* TIMER_H_ */
