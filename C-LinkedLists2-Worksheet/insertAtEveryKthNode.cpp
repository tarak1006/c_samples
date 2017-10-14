/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL)
		return NULL;
	if (K <= 0)
		return NULL;
	int i = 0,len=0;
	struct node* temp,*prev,*newnode;
	temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	if (K > len)
		return head;
	temp = head;
	while (temp != NULL){
		i = 0;
		while (temp!=NULL && i < K)
		{
			prev = temp;
			temp = temp->next;
			i++;
		}
		if (i == K){
			newnode = createNodeDummy(K);
			prev->next = newnode;
			newnode->next = temp;
		}
		
	}


	return head;
}
