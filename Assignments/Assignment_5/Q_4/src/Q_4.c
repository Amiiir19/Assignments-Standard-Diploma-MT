/*
 ============================================================================
 Name        : Q_4.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C Function to calculate the difference between two
 time periods using structures.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct time {
	int hour;
	int min;
} time;

time timeDiff(time *time1, time *time2);
int main(void) {

	time time1 = { 5, 30 };
	time time2 = { 9, 30 };
	time timesum = timeDiff(&time1, &time2);
	printf("Difference in time is : %d  Hours and %d Mins \n", timesum.hour,
			timesum.min);
	return 0;
}
time timeDiff(time *time1, time *time2) {
	time timesum;
		timesum.hour = time2->hour - time1->hour;

	timesum.min = time1->min - time2->min;
}
