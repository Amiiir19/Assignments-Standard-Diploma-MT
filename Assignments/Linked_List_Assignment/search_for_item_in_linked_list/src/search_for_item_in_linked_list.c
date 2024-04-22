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

void search(int num) {

	int count = 0;
	node *ptr = head;
	if (head == NULL) {
		printf("Linked List is empty\n");
		return;
	}

	while (ptr != NULL) {
		if(ptr->data==num){
			printf("Index = %d \n", count);
			return ;
		}
		ptr = ptr->next;
		count++;
	}
	printf("Not Exist\n");

	return;
}
int main(void) {

	insertatfirst(1);
	insertatfirst(2);
	insertatfirst(3);
	insertatfirst(4);
	insertatfirst(5);
	search(5);
	search(1);
	search(6);

	return EXIT_SUCCESS;
}
