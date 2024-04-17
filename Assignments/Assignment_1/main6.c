/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: amir
 */
#include <stdio.h>
int main() {
	int num1 = 0, num2 = 0;
	scanf(" %d %d", &num1, &num2);
	if (num1 == num2) {
		printf("Equal Numbers\n", num1, num2);
	} else if (num1 > num2) {
		printf("%d is Greater Than %d \n", num1, num2);
	} else {
		printf("%d is Smaller Than %d\n", num1, num2);
	}

	return 0;
}

