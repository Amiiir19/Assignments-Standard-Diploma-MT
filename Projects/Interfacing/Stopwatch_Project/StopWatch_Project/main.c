/*
 *               *  StopWatch Project   *
 *
 *      Created on: May 13, 2024
 *      Author: Abdelrahman Mohamed Amir
 *      Frequency : 1MHZ
 *      Timer1 on CTC Mode
 *      six Common Anode 7-segments
 *      one 7447 decoder.
 *      External Interrupt INT0 with falling edge   "RESET"
 *      External Interrupt INT1 with rising edge   "PAUSED"
 *      External Interrupt INT2 with falling edge   "RESUMED"
 */

#include "app.h"

/*   Variables for the seconds, minutes, hours on 2 digits for each */
unsigned char sec = 0;
unsigned char min = 0;
unsigned char hour = 0;
unsigned char sec2 = 0;
unsigned char min2 = 0;
unsigned char hour2 = 0;

/*   Flag that made on by the ISR of timer to indicates that 1 second pass  */
unsigned char INCREMENT_FLAG = 0;
ISR(INT0_vect) {
	/* Inside The Reset Button We need to make the timers units by zeros and stop the increment */
	// turn off the timer interrupt
	TIMSK &= ~(1 << OCIE1A);
	TCCR1B &= ~(1 << CS10) & ~(1 << CS12); // no clock source
	TCNT1 = 0; // Reset Timer1 count value
	sec = 0;
	min = 0;
	hour = 0;
	sec2 = 0;
	min2 = 0;
	hour2 = 0;
}
ISR(INT1_vect) {
	/* Inside The Stop Button We only need to disable interrupt of the timer1 and disable clock to stop increment of time */
	// turn off the timer interrupt
	TCCR1B &= ~(1 << CS10) & ~(1 << CS12); // no clock source
	TIMSK &= ~(1 << OCIE1A);

}
ISR(INT2_vect) {
	/* Inside The Start Button We only need to enable timer1 interrupt and set clock to allow increment of time */
	//Enable the Interrupt of the timer1
	TCCR1B |= (1 << CS12) | (1 << CS10); // enable 1024 pre scalar
	TIMSK |= (1 << OCIE1A);
}

ISR(TIMER1_COMPA_vect) {

	/*Timer ISR That happens every one second so we allow increment flag to make timer increment by 1 sec*/
	INCREMENT_FLAG = 1;
}
int main() {
	/*Interrupt Initialization*/
	INTERRUPT_INIT(INT0, FALLING_EDGE, PULL_UP);
	INTERRUPT_INIT(INT1, RISING_EDGE, PULL_DOWN);
	INTERRUPT_INIT(INT2, FALLING_EDGE, PULL_UP);
	/* Initialize the 7 segment  */
	segment_init();
	/* Initialize the timer1  */
	timer1_init();
	/*  Allow the General Interrupt Bit */
	SET_BIT(SREG, 7);

	while (1) {
		/* Display Function that make the time displays without any delay  */
		Display();

		/*
		 *  If Condition to check if the Timer CTC Mode happens or not
		 * so when it means a second passed and now we need to increment the timer
		 * so we enter to the function that increment the timer by 1 second
		 * (TCNT1) value matches the Output Compare Register A (OCR1A)
		 * and clear flag again till a second passed and ISR of timer1 set it
		 */
		if (INCREMENT_FLAG) {
			INCREMENT_TIME_LOGIC();
			INCREMENT_FLAG = 0;
		}
	}
}
