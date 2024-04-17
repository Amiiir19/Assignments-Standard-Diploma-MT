/*
 * main.c
 *
 *  Created on: Mar 4, 2024
 *      Author: amir
 */

#include <stdio.h>
int main() {
	int result = 0;
	for (int i = 1; i <= 100; i++) {
		result += i;
	}
	printf("Result  = %d\n",result);
	return 0;
}
