/*
 ============================================================================
 Name        : Question_17.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Given two integers: L and R, Find the maximal value of A xor B where
 A and B satisfy the condition L =< A <= B <= R Constrains: 1 <= L <= R <=
 1000
 Input format: the input contains two lines first line contains L and next
 line contains R.
 Output format: The maximum value of A xor B
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int maxXOR(int num1, int num2);
int main(void) {

	int num1 = 0, num2 = 0, result = 0;
	scanf(" %d %d", &num1, &num2);
	result = maxXOR(num1, num2);
	printf("result = %d", result);
	return EXIT_SUCCESS;
}
int maxXOR(int num1, int num2) {
	int hold = 0, max = 0;
	for (int i = num1; i <= num2; i++) {
		for (int j = num1; j <= num2; j++) {
			hold = i ^ j;
			if (hold > max) {
				max = hold;
			}
		}
	}
	return max;
}
