/*
 * app.c
 *
 *  Created on: May 13, 2024
 *      Author: amir
 */
#include "app.h"
/*
 * Function That increment the time by 1 second when it calls and handle
 * the rest
 * so if it is 60 seconds it increment minutes by 1 and make seconds=0
 * and if it is 60 min it increment hours by 1 and make minutes =0
 * in this Function i make each unit of seconds or minutes or hours
 * in individual variable and make the logic that handle the relation between them
 * so if second unit one reach 9 , unit 2 in seconds increment and unit 1 = 0
 * and if  if second unit two reach 6 , unit 1 in minutes increment and unit 2 in sec = 0
 *
 * & so on
 *
 * */
void INCREMENT_TIME_LOGIC(void) {
//increment Seconds
	sec++;
	if (sec > 9) {
		sec = 0;
		sec2++;
	}
	if (sec2 > 5) {
		sec2 = 0;
		min++;
	}
	if (min > 9) {
		min = 0;
		min2++;
	}
	if (min2 > 5) {
		min2 = 0;
		hour++;
	}
	if (hour > 9) {
		hour = 0;
		hour2++;
	}
	if (hour2 > 9) {
		hour2 = 9;
	}
}
void timer1_init(void) {
	TCNT1 = 0;
	/*Set the Compare Value*/
	OCR1A = 978U;
	/* NON PWM MODE*/
	TCCR1A |= (1 << FOC1A);
	/*   Set prescalar 1024 ON CTC Mode with TOP OCR1A*/
	TCCR1B |= (1 << CS12) | (1 << CS10) | (1 << WGM12);
	//Enable the Interrupt of the timer1
	TIMSK |= (1 << OCIE1A);
}
void Display(void) {
	/*Enable The The First Segment Only*/
	PORTA = (PORTA & 0xc0) | (1 << 0);
	/*Set the value of seconds first unit now */
	PORTC = (PORTC & 0Xf0) | (sec & 0x0f);
	_delay_ms(4);
	/*Enable The The Second Segment Only*/
	PORTA = (PORTA & 0xc0) | (1 << 1);
	/*Set the value of seconds 2nd unit now */
	PORTC = (PORTC & 0Xf0) | (sec2 & 0x0f);
	_delay_ms(4);
	/*Enable The The third Segment Only*/
	PORTA = (PORTA & 0xc0) | (1 << 2);
	/*Set the value of minutes first unit now */
	PORTC = (PORTC & 0Xf0) | (min & 0x0f);
	_delay_ms(4);
	/*Enable The The fourth Segment Only*/
	PORTA = (PORTA & 0xc0) | (1 << 3);
	/*Set the value of minutes 2nd unit now */
	PORTC = (PORTC & 0Xf0) | (min2 & 0x0f);
	_delay_ms(4);
	/*Enable The The fifth Segment Only*/
	PORTA = (PORTA & 0xc0) | (1 << 4);
	/*Set the value of hours first unit now */
	PORTC = (PORTC & 0Xf0) | (hour & 0x0f);
	_delay_ms(4);
	/*Enable The The Sixth Segment Only*/
	PORTA = (PORTA & 0xc0) | (1 << 5);
	/*Set the value of hours 2nd unit now */
	PORTC = (PORTC & 0Xf0) | (hour2 & 0x0f);
	_delay_ms(4);
}
void segment_init() {
	/*Set Pins Connected to the 7447 driver direction Output*/
	DDRC |= 0X0F; // 0000 1111
	/*Clear the Pins connected 7447 driver Low as initial value */
	PORTC &= 0X0F; //0000 1111
	/*Set Enable Pins Connected to 7 segments direction Output*/
	DDRA |= 0X3F; //0011 1111
	/*Clear the Enable  Pins connected 7 segments  Low as initial value */
	PORTA &= 0XC0; //1100 0000
}
