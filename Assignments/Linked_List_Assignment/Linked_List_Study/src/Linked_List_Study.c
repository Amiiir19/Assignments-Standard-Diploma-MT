/*
 ============================================================================
 Name        : Linked_List_Study.c
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

//CREATE THE HEAD HERE
 node *head = NULL;

void insertatfirst(int data) {
	// NEW NODE
	node *link = (node*) malloc(sizeof(node)); // Create New Node
	// Connect it to the Node that will be beside it
	/*
	 *                  Head
	 *                   |
	 * [new node ] ->  [node]
	 */
	link->next = head;
	//assign the head to the new node
	/*
	 *     Head
	 *      |
	 * [new node ] ->  [node] -> NULL
	 */
	head = link;

	link->data = data;
}
void print() {
	//PTR POINTS TO THE FIRST ELEMENT
	node *ptr = head;
	/*
	 * Very Important
	 * ptr not ptr->next .. to  print the last element
	 */
	while (ptr != NULL) {
		printf("[%d] ---> ", ptr->data);
		ptr = ptr->next;
	}
	printf("[NULL]");
}
int main(void) {

	insertatfirst(1);
	insertatfirst(2);
	insertatfirst(3);
	insertatfirst(4);
	insertatfirst(5);
	//Display
	print();
	return 0;
}

