/*
 ============================================================================
 Name        : search_for_item_in_linked_list.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct {
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

void update(int index,int num) {

	int count = 0;
	node *ptr = head;
	if (head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	while ( count != index) {
		ptr = ptr->next;
		count++;
	}
	ptr->data=num;
	return;
}
void print() {
	node *ptr2 = head;
	while (ptr2 != NULL) {
		printf("[%d] ---> ", ptr2->data);
		ptr2 = ptr2->next;
	}
	printf("[NULL]");
}
int main(void) {

	insertatfirst(1);
	insertatfirst(2);
	insertatfirst(3);
	insertatfirst(4);
	insertatfirst(5);
	update(3,7);
	print();

	return EXIT_SUCCESS;
}
