/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: amir
 */
#include <stdio.h>

int main() {
	float tempC = 0, tempF = 0;
	scanf(" %f", &tempC);
	tempF = ((tempC * 9) / 5) + 32;
	printf("Result = %0.2f  \n", tempF);

	return 0;
}

