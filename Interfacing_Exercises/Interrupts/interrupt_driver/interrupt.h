/*
 * interrupt.h
 *
 *  Created on: May 8, 2024
 *      Author: amir
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include <avr/io.h>
#include <avr/interrupt.h>

typedef enum INTERRUPT_MODE {
	ANY_LOW, ANY_CHANGE, FALLING_EDGE, RISING_EDGE
} INTERRUPT_MODE;
void INTERRUPT_INIT(unsigned char INT_NUM, INTERRUPT_MODE MODE, INPUT_MODE INP);

#endif /* INTERRUPT_H_ */
