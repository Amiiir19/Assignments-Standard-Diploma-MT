/*
 ============================================================================
 Name        : Linked_List_Size.c
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
void insertatfirst(int data) {
	node *link = (node*) malloc(sizeof(node)); // Create New Node
	link->next = head;
	head = link;
	link->data = data;
}
int sizeofLinkedList() {
	int counter = 0;
	node *ptr = head;
	if (head == NULL) {
		return 0;
	}
	while (ptr != NULL) {
		counter++;
		ptr = ptr->next;
	}
	return counter;
}

int main(void) {

	insertatfirst(1);
	insertatfirst(2);
	insertatfirst(3);
	insertatfirst(4);
	insertatfirst(5);
	int x = sizeofLinkedList();
	printf("Size = %d ", x);
	return EXIT_SUCCESS;
}
