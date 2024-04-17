/*
 * main.c
 *
 *  Created on: Mar 7, 2024
 *      Author: amir
 */

#include <stdio.h>
#include <string.h>

int main() {
	int num = 0, count = 0;
	scanf("%d", &num);
	while ((num != 0) || (0 == count)) {
		//to handle case >> input is just zero
		if (count == 0 && num == 0) {
			count = 1;
			break;
		}
		count++;
		num /= 10;
	}
	printf("%d\n", count);
	return 0;
}
