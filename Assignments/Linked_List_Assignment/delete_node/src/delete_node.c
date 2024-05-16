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
void delete();
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
	delete(2);
	print();

	return 0;
}

void delete(int index) {
	if (head == NULL) {
		return ;
	}
	node *ptr = head;
	int pos=0;
	while (pos == index-1) {
		ptr = ptr->next;
		pos++;
	}
node* delete=ptr->next;
	ptr->next=ptr->next->next;
free(delete);
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

