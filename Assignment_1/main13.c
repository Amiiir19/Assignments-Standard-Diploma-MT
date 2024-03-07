/*
 * main.c
 *
 *  Created on: Mar 7, 2024
 *      Author: amir
 */

#include <stdio.h>
int main() {
	int num = 0, trials = 0;
	scanf(" %d", &num);
	for (int i = 2; i <= 9; i++) {
		if (((num % i) == 0 && i < num) || num == 1) {
			printf("It is NOT Prime \n");
			break;
		} else if (i == 9) {
			printf("It is Prime \n");
		}
	}

	return 0;
}
