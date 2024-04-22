/*
 ============================================================================
 Name        : Q_4.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function that returns the sum of all the nodes in
 linked list.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *next;
} node;

node *head = NULL;
void insertatfirst(int data);
void print(void);
int sum();
int main(void) {
	print();
	insertatfirst(5);
	print();
	insertatfirst(4);
	print();
	insertatfirst(3);
	print();
	insertatfirst(2);
	print();

	int x = sum();
	printf("sum = %d \n", x);
	return 0;
}

int sum() {
	if (head == NULL) {
		return 0;
	}
	int sum = 0;
	node *ptr = head;
	while (ptr != NULL) {
		sum += ptr->data;
		ptr = ptr->next;
	}
	return sum;

}
void insertatfirst(int data) {
	node *link = (node*) malloc(sizeof(struct node));
	link->data = data;
	if (head == NULL) {
		link->next = NULL;
		head = link;
		return;
	}
	link->next = head;
	head = link;
}
void print(void) {
	if (head == NULL) {
		printf("Empty\n");
		return;
	}
	node *ptr = head;
	while (ptr != NULL) {
		printf("[%d]", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

