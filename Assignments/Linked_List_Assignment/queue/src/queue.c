/*
 ============================================================================
 Name        : queue.c
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
node *head = NULL;

void dequeue(void);
void enqueue(int num);
void print(void);
int peek(void);

int main(void) {
	print();
	enqueue(1);
	print();
	enqueue(2);
	print();
	enqueue(3);
	print();
	enqueue(4);
	print();
	enqueue(5);
	print();
	dequeue();
	print();
	dequeue();
	print();
	int x = peek();
	printf("peek = %d \n", x);
	print();
	return 0;
}

void enqueue(int num) {
	node *link = (node*) malloc(sizeof(struct node));
	link->data = num;
	if (head == NULL) {
		link->next = NULL;
		head = link;
		return;
	}
	link->next = head;
	head = link;
}
void dequeue(void) {
	if (head == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	node *ptr = head;
	node *prev = head;
	while (ptr->next != NULL) {
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = NULL;
	free(ptr);
}

void print(void) {
	if (head == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	node *ptr = head;
	while (ptr != NULL) {
		printf("[%d]", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
int peek(void) {
	if (head == NULL) {
		printf("Queue is Empty\n");
		return -1;
	}
	node *ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	return ptr->data;
}

