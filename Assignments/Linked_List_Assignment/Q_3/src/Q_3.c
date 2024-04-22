/*
 ============================================================================
 Name        : Q_3.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function that returns the data inside the 5th element
 from the end of linked list and in case the linked list contains only
 one node return the data inside this node.
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
int fifthelement();
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
	insertatfirst(70);
	print();
	insertatfirst(44);
	print();
	insertatfirst(33);
	print();
	insertatfirst(22);
	print();
	insertatfirst(11);
	print();
	int x = fifthelement();
	printf("fifth element = %d \n", x);
	return 0;
}

int fifthelement() {
	if (head == NULL) {
		return -1;
	} else if (head->next == NULL) {
		return head->data;
	}
	//get size
	int size = 0;
	node *getsize = head;
	while (getsize != NULL) {
		getsize = getsize->next;
		size++;
	}

	node *ptr = head;
	if (size >= 5) {
		while (ptr->next->next->next->next->next != NULL) {
			ptr = ptr->next;
		}
		return ptr->data;
	} else {
		printf("it is less than 5 elements");
	}
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

