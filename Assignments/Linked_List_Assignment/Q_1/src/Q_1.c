/*
 ============================================================================
 Name        : Q_1.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function that insert linked list node at any
 position. The function takes the data of the node and the
 node position as inputs.
 For example if we have a linked list contains the following
 data nodes: 11 3 10 50 23 5 60
 If you asked the function to insert a new node has data equals to
 15 at position 3 the linked list should be: 11 3 10 15 50 23 5 60
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *next;
} node;

node *head = NULL;

void insert_anywhere_function(int index, int data);
void insertatfirst(int data);
void print(void);

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
	insertatfirst(1);
	print();
	insert_anywhere_function(3,22);
	print();

	return 0;
}

void insert_anywhere_function(int index, int data) {

	node *link = (node*) malloc(sizeof(struct node));
	link->data = data;
	if (head == NULL) {
		link->next = NULL;
		head = link;
		return;
	}
	node *ptr = head;
	int position = 0;
	while ((index - 1 != position)&&(ptr->next !=NULL)) {
		ptr = ptr->next;
		position++;
	}
	link->next = ptr->next;
	ptr->next = link;

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

