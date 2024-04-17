/*
 * main.c
 *
 *  Created on: Mar 7, 2024
 *      Author: amir
 */

#include <stdio.h>
int main() {
	int num = 0, power = 0, result=1;
	scanf(" %d %d", &num, &power);
	for (int i = 0; i < power; i++) {
		result *= num;
	}
	printf("%d\n", result);
	return 0;
}
