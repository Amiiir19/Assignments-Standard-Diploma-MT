/*
 ============================================================================
 Name        : Question_10.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : You are designing a poster which prints out numbers with a unique
 style applied to each of them. The styling is based on the number of
 closed paths or holes present in a giver number. The number of holes
 that each of the digits from 0 to 9 have are equal to the number of closed
 paths in the digit. Their values are:
 • 1, 2, 3, 5 and 7 = 0 holes.
 • 0, 4, 6, and 9 = 1 hole.
 • 8 = 2 holes.
 Given a number, you must determine the sum of the number of holes for
 all of its digits. For example, the number 819 has 3 holes.
 Function Description
 Complete the function countHoles. The function must return an integer
 denoting the total number of holes in num.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countHoles(char *num);
int main(void) {
	char num1[100];
	int result;
	scanf(" %s", num1);
	result = countHoles(num1);
	printf("Holes = %d", result);
	return EXIT_SUCCESS;
}
int countHoles(char *num) {
	char check = 0;
	int final_count = 0;
	int len = strlen(num);
	for (int i = 0; i < len; i++) {
		check = num[i];
		switch (check) {
		case '4':
		case '6':
		case '9':
		case '0':
			final_count++;
			break;
		case '8':
			final_count += 2;
			break;
		}
	}
	return final_count;
}
