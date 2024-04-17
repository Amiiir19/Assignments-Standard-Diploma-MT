/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: amir
 */
#include <stdio.h>
int main() {
	int num1 = 0, num2 = 0, num3 = 0;
	scanf(" %d %d %d", &num1, &num2, &num3);
	if (num1 < num2) {
		if (num1 < num3) {
			printf("%d is the smallest", num1);
		} else {
			printf("%d is the smallest", num3);
		}
	} else {
		if (num2 < num3) {
			printf("%d is the smallest", num2);
		} else {
			printf("%d is the smallest", num3);
		}

	}

	return 0;
}

