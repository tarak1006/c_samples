/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * numberToLinkedList(int numE) {
	if (numE < 0)
		numE *= -1;
	struct node *head = createNode(numE % 10);
	numE /= 10;
	while (numE) {
		struct node *newNode = createNode(numE % 10);
		newNode->next = head;
		head = newNode;
		numE /= 10;
	}
	return head;
}