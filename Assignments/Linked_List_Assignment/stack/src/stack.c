/*
 ============================================================================
 Name        : stack.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} node;

node *top = NULL;

void push(int num);
void pop(void);
int peek(void);
void print();

int main(void) {

	push(5);
	print();
	push(4);
	print();
	push(3);
	print();
	push(2);
	print();
	push(1);
	print();

	pop();
	print();
	pop();
	print();
	int x = peek();
	printf("top = %d\n", x);
	print();

	return 0;
}
void push(int num) {
	node *link = (node*) malloc(sizeof(struct node));
	link->data = num;
	if (top == NULL) {
		top = link;
		link->next = NULL;
	return;
	}
	
	link->next = top;
	top = link;
	
}
void pop(void) {
	if (top == NULL) {
		printf("EMPTY \n");
		return;
	}
	node *ptr = top;
	top = ptr->next;
	free(ptr);
}
int peek(void) {
	return top->data;
}
void print() {

	if (top == NULL) {
		printf("EMPTY \n");
		return;
	}
	node *ptr = top;
	while (ptr != NULL)
	{
		printf("[%d] ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

