/*
 * interrupt.c
 *
 *  Created on: May 8, 2024
 *      Author: amir
 */
#include "interrupt.h"
void INTERRUPT_INIT(unsigned char INT_NUM, INTERRUPT_MODE MODE, INPUT_MODE INP) {
	switch (INT_NUM) {
	case INT0:
		DIO_INIT(D, 2, INPUT, INP);
		switch (MODE) {
		case FALLING_EDGE:
			SET_BIT(MCUCR, ISC01);
			CLR_BIT(MCUCR, ISC00);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, ISC01);
			SET_BIT(MCUCR, ISC00);
			break;
		}
		SET_BIT(GICR, 6);
		break;
	case INT1:
		DIO_INIT(D, 3, INPUT, INP);
		switch (MODE) {
		case FALLING_EDGE:
			SET_BIT(MCUCR, ISC11);
			CLR_BIT(MCUCR, ISC10);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR, ISC11);
			SET_BIT(MCUCR, ISC10);
			break;
		}
		SET_BIT(GICR, 7);

		break;
	case INT2:
		DIO_INIT(B, 2, INPUT, INP);
		SET_BIT(MCUCSR, ISC2);
		switch (MODE) {
		case FALLING_EDGE:
			CLR_BIT(MCUCSR, ISC2);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCSR, ISC2);
			break;
		}
		SET_BIT(GICR, 5);
		break;
	}
}
