/*
 * IO.C
 *
 *  Created on: May 8, 2024
 *      Author: amir
 */

#include "IO.h"

void DIO_INIT(PORT_T PORT, unsigned char PIN, DIRECTION DIR, INPUT_MODE MODE) {
	if (DIR == OUTPUT) {
		switch (PORT) {
		case A:
			SET_BIT(DDRA, PIN);
			CLR_BIT(PORTA, PIN);
			break;
		case B:
			SET_BIT(DDRB, PIN);
			CLR_BIT(PORTB, PIN);

			break;
		case C:
			SET_BIT(DDRC, PIN);
			CLR_BIT(PORTC, PIN);

			break;
		case D:
			SET_BIT(DDRD, PIN);
			CLR_BIT(PORTD, PIN);
			break;
		}

	} else if (DIR == INPUT) {
		switch (PORT) {
		case A:
			CLR_BIT(DDRD, PIN);
			if (MODE == PULL_DOWN) {
				CLR_BIT(PORTD, PIN);
			} else if (MODE == PULL_UP) {
				SET_BIT(PORTD, PIN);
			}
			break;
		case B:
			CLR_BIT(DDRD, PIN);
			if (MODE == PULL_DOWN) {
				CLR_BIT(PORTD, PIN);
			} else if (MODE == PULL_UP) {
				SET_BIT(PORTD, PIN);
			}
			break;
		case C:
			CLR_BIT(DDRD, PIN);
			if (MODE == PULL_DOWN) {
				CLR_BIT(PORTD, PIN);
			} else if (MODE == PULL_UP) {
				SET_BIT(PORTD, PIN);
			}
			break;
		case D:
			CLR_BIT(DDRD, PIN);
			if (MODE == PULL_DOWN) {
				CLR_BIT(PORTD, PIN);
			} else if (MODE == PULL_UP) {
				SET_BIT(PORTD, PIN);
			}
			break;
		}
	}

}
void DIO_WRITE(PORT_T PORT, unsigned char PIN, STATE state_t) {
	switch (PORT) {
	case A:
		if (state_t == HIGH) {
			SET_BIT(PORTA, PIN);
		} else if (state_t == LOW) {
			CLR_BIT(PORTA, PIN);
		}

		break;
	case B:
		if (state_t == HIGH) {
			SET_BIT(PORTB, PIN);
		} else if (state_t == LOW) {
			CLR_BIT(PORTB, PIN);
		}
		break;
	case C:
		if (state_t == HIGH) {
			SET_BIT(PORTC, PIN);
		} else if (state_t == LOW) {
			CLR_BIT(PORTC, PIN);
		}
		break;
	case D:
		if (state_t == HIGH) {
			SET_BIT(PORTD, PIN);
		} else if (state_t == LOW) {
			CLR_BIT(PORTD, PIN);
		}
		break;
	}
}

STATE DIO_READ(PORT_T PORT, unsigned char PIN) {
	switch (PORT) {
	case A:
		if (PINA & (1 << PIN)) {
			return HIGH;
		} else {
			return LOW;
		}
		break;
	case B:
		if (PINB & (1 << PIN)) {
			return HIGH;
		} else {
			return LOW;
		}
		break;
	case C:
		if (PINC & (1 << PIN)) {
			return HIGH;
		} else {
			return LOW;
		}
		break;
	case D:
		if (PIND & (1 << PIN)) {
			return HIGH;
		} else {
			return LOW;
		}
		break;
	}
	return -1;
}
