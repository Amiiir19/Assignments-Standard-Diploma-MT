/*
 ============================================================================
 Name        : Q_9.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Given a string, create a new string made up of its last
 two letters, reversed and separated by a space, the word
 is “bat”. Return string contains ”t a”
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char str[10];
	char str2[2];
	scanf(" %s", str);
	int len = strlen(str);
	char *ptr = str;
	for (int i = 0; i < 2; i++) {
		str2[i] = *(ptr + len-1 - i);
	}
	for(int i=0;i<2;i++){
		printf("%c ",str2[i]);
	}
	return 0;
}
