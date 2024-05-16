/*
 * interrupts.c
 *
 *  Created on: May 12, 2024
 *      Author: amir
 */

#include "interrupts.h"
/*
 * Function initialize any interrupt depend on the arguments
 * This Function Takes 3 Arguments  :
 * 1- Interrupt Number
 * 2- Interrupt Mode of Operation
 * 3- Pull Up OR Pull Down
 *
 *  */
void INTERRUPT_INIT(unsigned char INT_NUM, INTERRUPT_MODE MODE,
		PULLMODE PULLMOD) {
	switch (INT_NUM) {
	case INT0:
		/*Make Pin 3 on Portd as INPUT*/
		CLR_BIT(DDRD, 2);
		/*Check For Argument if it is PULL UP OR DOWN*/
		if (PULLMOD == PULL_UP) {
			SET_BIT(PORTD, 2);
		} else if (PULLMOD == PULL_DOWN) {
			CLR_BIT(PORTD, 2);
		}
		/*   Mode of Operating Falling Edge or rising edge   */
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
		/*Enable Interrupt 0 */
		SET_BIT(GICR, 6);
		break;
	case INT1:
		CLR_BIT(DDRD, 3);
		if (PULLMOD == PULL_UP) {
			SET_BIT(PORTD, 3);
		} else if (PULLMOD == PULL_DOWN) {
			CLR_BIT(PORTD, 3);
		}
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
		CLR_BIT(DDRB, 2);
		if (PULLMOD == PULL_UP) {
			SET_BIT(PORTB, 2);
		} else if (PULLMOD == PULL_DOWN) {
			CLR_BIT(PORTB, 2);
		}
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
