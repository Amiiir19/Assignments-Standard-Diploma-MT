/*
 ============================================================================
 Name        : Question_11.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function that returns 1 if the input number
                is a power of 2
                and return 0 if the input number is not power of 2.
 For example: 1, 2 and 16 are power of 2.
 0, 10 and 30 are not power of 2.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int checkPower(unsigned int num);
int main(void) {
	unsigned int num = 0;
	scanf(" %d", &num);
	if (checkPower(num)) {
		printf("Is Power");
	} else {
		printf("Is not Power");
	}
	return EXIT_SUCCESS;
}
int checkPower(unsigned int num) {
	int check = 0;

	unsigned int mask = 1;
	mask <<= ((sizeof(int) * 8) - 1);
	//1000 0000 0000 0000 >> mask to check the bit
	for (int i = 0; i <( sizeof(int) * 8)-1; i++) {
		if (mask & num << i) {
			check++;
		}
		/*
		 *    1000 0000 0000 0000
		 *  &   pushing the bits of num to check it bit by bit
		 *  each bit equal 1 will return 1 when it anding with mask
		 *
		 *
		 * */

	}
	//if the count of ones is more than 1 it means this number is not from
	// 1 , 2 4 8 16 32 64 and so on
	if (check > 1) {
		return 0;
	} else {
		return 1;
	}
}
