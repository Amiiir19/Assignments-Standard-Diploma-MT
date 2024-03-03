/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: amir
 */
#include <stdio.h>

int main() {
	int x = 0, y = 0, result = 0;

	scanf(" %d %d", &x, &y);
	result = ((x + y) * 3) - 10;
	printf("Result = %d  \n", result);

	return 0;
}

