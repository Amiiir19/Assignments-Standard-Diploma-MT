/*
 ============================================================================
 Name        : Question_4.c
 Author      : Amir
 Version     :
 Copyright   :
 Description :
 Write a C Function that return the addition or subtraction or
 multiplication or division for two numbers. The function should take the
 required operation and two numbers as arguments. It also should check
 that the input operation is one of those operation that mentioned before
 and if not it should return error. The function should be implemented
 using switch case.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//Global Variable to get Error and Ask you user to enter a valid op
int flag = 0;
int operFunc(int num1, char op, int num2);
int main(void) {

	int num1 = 0, num2 = 0, result = 0;
	char op;
	scanf(" %d", &num1);
	scanf(" %c", &op);
	scanf(" %d", &num2);
	result = operFunc(num1, op, num2);
	while (flag == 1) {
		printf("Wrong Operation Please Enter a valid one : ");
		scanf(" %c", &op);
		result = operFunc(num1, op, num2);
	}
	printf("result = %d", result);

	return EXIT_SUCCESS;
}
int operFunc(int num1, char op, int num2) {

	switch (op) {
	case '+':
		flag = 0;
		return num1 + num2;
		break;
	case '-':
		flag = 0;
		return num1 - num2;
		break;
	case '*':
		flag = 0;
		return num1 * num2;
		break;
	case '/':
		flag = 0;
		return num1 / num2;
		break;
	default:
		printf("Error\n");
		flag = 1;
		//return 0;
		break;
	}

}
