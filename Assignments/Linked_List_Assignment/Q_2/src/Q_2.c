/*
 ============================================================================
 Name        : Q_2.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description :
 Write a C Function that returns the data of the middle node in
 a linked list and in case the linked list contains only one node
 return the data inside this node.
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
int middleElement(void);

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
	int x = middleElement();
	printf("middle elemnt is %d", x);

	return 0;
}

int middleElement(void) {
	int step = 0;
	if (head == NULL) {
		printf("Empty \n");
		return -1;
	} else if (head->next == NULL) {
		return head->data;
	}

	node *ptr1 = head;
	node *ptr2 = head;
	while (ptr1->next != NULL) {
		ptr1 = ptr1->next;
		step++;
		if (!(step % 2)) {
			ptr2 = ptr2->next;
		}
	}
	return ptr2->data;

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
