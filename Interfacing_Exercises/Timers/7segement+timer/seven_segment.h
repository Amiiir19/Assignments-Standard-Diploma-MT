/*
 * 7segment.h
 *
 *  Created on: May 3, 2024
 *      Author: amir
 */

#include <avr/io.h>
#ifndef SEGMENT_H_
#define SEGMENT_H_
#define SET_BIT(PORT,PIN) (PORT |=(1<<PIN))
#define CLR_BIT(PORT,PIN) (PORT &=~(1<<PIN))
void SevenSegment_Display(unsigned char value);
void segment_init(void);

#endif /* 7SEGMENT_H_ */
