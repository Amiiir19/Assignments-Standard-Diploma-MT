/*
 * 7segment.c
 *
 *  Created on: May 3, 2024
 *      Author: amir
 */

#include "seven_segment.h"
void segment_init() {
	DDRC = 0xFE;
	SevenSegment_Display(0);
}
void SevenSegment_Display(unsigned char value) {
	switch (value) {
	case 0:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		CLR_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		SET_BIT(PORTC, 7);
		break;
	case 1:
		SET_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SET_BIT(PORTC, 6);
		SET_BIT(PORTC, 7);
		break;
	case 2:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		SET_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		CLR_BIT(PORTC, 5);
		SET_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 3:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SET_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 4:
		SET_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 5:
		CLR_BIT(PORTC, 1);
		SET_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 6:
		CLR_BIT(PORTC, 1);
		SET_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		CLR_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 7:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		SET_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		SET_BIT(PORTC, 6);
		SET_BIT(PORTC, 7);
		break;
	case 8:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		CLR_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	case 9:
		CLR_BIT(PORTC, 1);
		CLR_BIT(PORTC, 2);
		CLR_BIT(PORTC, 3);
		CLR_BIT(PORTC, 4);
		SET_BIT(PORTC, 5);
		CLR_BIT(PORTC, 6);
		CLR_BIT(PORTC, 7);
		break;
	}
}
