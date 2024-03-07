/*
 * main.c
 *
 *  Created on: Mar 7, 2024
 *      Author: amir
 */

#include <stdio.h>
#include <string.h>

int main() {
	char num[100];
	scanf("%s", num);
	printf("%s\n", num);

	int len = strlen(num);
	char temps ;
	int end = len-1;
	for (int i = 0; i < len-1; i++) {
		if(i!=end){
		temps = num[i];
		num[i] = num[end];
		num[end] = temps;
		end--;
		}
		else{
			break;
		}
	}
	printf("%s\n", num);
	return 0;
}
