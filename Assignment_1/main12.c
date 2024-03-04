/*
 * main.c
 *
 *  Created on: Mar 4, 2024
 *      Author: amir
 */

#include <stdio.h>
int main() {
	int result = 1;
	int num=0;
	scanf ("%d", &num);
	for (int i = 1; i <= num; i++) {
		result *= i;
	}
	printf("Result  = %d\n",result);
	return 0;
}
