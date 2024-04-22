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

void insertatlast(int data) {
	// NEW NODE
	node *link = (node*) malloc(sizeof(node)); // Create New Node
	/*
	 *   Head
	 *    |
	 * [node ] -> [node]-> [NULL]     [new Node]
	 */
	link->next = NULL;
	/*
	 *   Head
	 *    |
	 * [node ] -> [node]-> [NULL]     [new Node] -> [NULL]
	 */

	/*
	 * Beware this check is a mandatory
	 * Because if head is null  there will not be ->next  .. so code will crash
	 * */
	if (head == NULL) {
		head = link;
		link->data = data;

		return;
	}

	node *ptr = head;

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	ptr->next = link;
	/*
	 *   Head
	 *    |              NEW LINK
	 * [node ] -> [node]  ---->  [new Node] -> [NULL]
	 */

	link->data = data;
}
void print() {
	//PTR POINTS TO THE FIRST ELEMENT
	node *ptr2 = head;
	/*
	 * Very Important
	 * ptr not ptr->next .. to  print the last element
	 */
	while (ptr2 != NULL) {
		printf("[%d] ---> ", ptr2->data);
		ptr2 = ptr2->next;
	}
	printf("[NULL]");
}
int main(void) {

	insertatlast(1);
	insertatlast(2);
	insertatlast(3);
	insertatlast(4);
	insertatlast(5);
	//Display
	print();
	return 0;
}

