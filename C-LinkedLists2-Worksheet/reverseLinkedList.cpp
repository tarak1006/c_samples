/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
}*temp,*head2;

void reverse(struct node* curr, struct node* prev)
{
	if (curr != NULL){
		reverse(curr->next, curr);
		curr->next = prev;
	}
	else{
		head2 = prev;

	}
}
struct node * reverseLinkedList(struct node *head) {
	if (head == NULL){
		return NULL;
	}
	else{
	
		reverse(head, NULL);
	}
	return head2;


}
