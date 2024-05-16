/*
 * main.h
 *
 *  Created on: May 13, 2024
 *      Author: amir
 */

#ifndef APP_H_
#define APP_H_
#define F_CPU 1000000UL // 1MHz Clock frequency
#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupts.h"
#include <util/delay.h>
#define SET_BIT(NUM,BIT) NUM |=(1<<BIT)
#define CLR_BIT(NUM,BIT) NUM &=~(1<<BIT)
#define TOGGLE_BIT(NUM,BIT) NUM ^=(1<<BIT)
#define TOGGLE_BIT(NUM,BIT) NUM ^=(1<<BIT)

extern unsigned char sec;
extern unsigned char min;
extern unsigned char hour;
extern unsigned char sec2;
extern unsigned char min2;
extern unsigned char hour2;
extern unsigned char INCREMENT_FLAG;
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
void INCREMENT_TIME_LOGIC(void);
/* Timer 1 init Function */
void timer1_init(void);
/* 7 Segment   init Function */
void segment_init(void);
/*Continous Display Function */
void Display(void);
#endif /* APP_H_ */
