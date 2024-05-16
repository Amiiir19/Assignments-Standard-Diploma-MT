/*
 * IO.H
 *
 *  Created on: May 8, 2024
 *      Author: amir
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#ifndef IO_H_
#define IO_H_

#define SET_BIT(NUM,BIT) NUM |=(1<<BIT)
#define CLR_BIT(NUM,BIT) NUM &=~(1<<BIT)
#define TOGGLE_BIT(NUM,BIT) NUM ^=(1<<BIT)

typedef enum DIRECTION {
	OUTPUT, INPUT
} DIRECTION;
typedef enum PORT_T {
	A, B, C, D
} PORT_T;

typedef enum INPUT_MODE {
	NONE, PULL_UP, PULL_DOWN
} INPUT_MODE;

typedef enum STATE {
	LOW, HIGH
} STATE;

void DIO_INIT(PORT_T PORT, unsigned char PIN, DIRECTION DIR, INPUT_MODE MODE);
void DIO_WRITE(PORT_T PORT, unsigned char PIN, STATE state_t) ;
STATE DIO_READ(PORT_T PORT, unsigned char PIN);

#endif /* IO_H_ */
