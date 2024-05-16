/*
 * interrupts.h
 *
 *  Created on: May 12, 2024
 *      Author: amir
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include <avr/interrupt.h>
#define SET_BIT(NUM,BIT) NUM |=(1<<BIT)
#define CLR_BIT(NUM,BIT) NUM &=~(1<<BIT)
#define TOGGLE_BIT(NUM,BIT) NUM ^=(1<<BIT)
/*Mode of Operations of Interrupt*/
typedef enum INTERRUPT_MODE {
	FALLING_EDGE, RISING_EDGE
} INTERRUPT_MODE;
/*Input Connection*/
typedef enum PULLMODE {
	PULL_DOWN, PULL_UP
} PULLMODE;

void INTERRUPT_INIT(unsigned char INT_NUM, INTERRUPT_MODE MODE,
		PULLMODE PULLMOD);

#endif /* INTERRUPT_H_ */
