/*
 * main.c
 *
 *  Created on: May 3, 2024
 *      Author: amir
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//#include "timer.h"
#define SET_BIT(PORT,PIN) (PORT |=(1<<PIN))
#define CLR_BIT(PORT,PIN) (PORT &=~(1<<PIN))

void Eta32mini_SevenSegment_Display(unsigned char value) {
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
int main() {
	DDRC |= (1 << 0);        // configure pin 6 in PORTC as output pin

	// Set pin 6 in PORTC with value 1 to enable the BJT NPN transistor to connect the first 7-segment common to the ground(common cathode)
	PORTC |= (1 << 0);
	DDRC = 0xFF;
	PORTC = 0;
	while (1) {
		for (int i = 0; i <= 9; i++) {
			Eta32mini_SevenSegment_Display(i);
			_delay_ms(1000);
		}
	}

}
