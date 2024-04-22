/*
 ============================================================================
 Name        : Q_5.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function that returns the maximum data value in the
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
int max();
int main(void) {
	print();
	insertatfirst(5);
	print();
	insertatfirst(4);
	print();
	insertatfirst(3);
	print();
	insertatfirst(22);
	print();

	int x = max();
	printf("max = %d \n", x);
	return 0;
}

int max() {
	if (head == NULL) {
		return 0;
	}
	int max = 0;
	node *ptr = head;
	max=ptr->data;
	while (ptr != NULL) {
		if(max<ptr->data){
			max=ptr->data;
		}
		ptr = ptr->next;
	}
	return max;

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

