/*
 * main.c
 *  Created on: Mar 29, 2024
 *      Author: amir
 *      Description :Write a C function that calculates the required heater activation time
 according to the input temperature of water.
 - if input temperature is from 0 to 30, then required heating time
 = 7mins.
 - if input temperature is from 30 to 60, then required heating time
 = 5 mins.
 - if input temperature is from 60 to 90, then required heating time =
 3 mins.
 - if input temperature is more than 90, then required heating time =
 1 mins.
 - if temperature is invalid (more than 100), return 0
 */

#include <stdio.h>

int myfunc(int giventemp);

int main() {
	int giventemp = 0, result = 0;
	scanf("%d", &giventemp);

	result = myfunc(giventemp);
	printf("%d\n", result);
}
int myfunc(int giventemp) {
	if (giventemp < 0) {
		return -1;
	} else if (giventemp <= 30) {
		return 7;
	} else if (giventemp <= 60) {
		return 5;
	} else if (giventemp <= 90) {
		return 3;
	} else if (giventemp <= 100) {
		return 1;
	} else {
		return 0;
	}
}
