/*
 * main.c
 *
 *  Created on: Mar 4, 2024
 *      Author: amir
 */

#include <stdio.h>
int main() {

	int num1 = 0, num2 = 0, result = 0;
	char sym = 0;
	scanf(" %d %c %d", &num1, &sym, &num2);
	switch (sym) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	default:
		break;
	}
	printf("Result= %d", result);
	return 0;
}
