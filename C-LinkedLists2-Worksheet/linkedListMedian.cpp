/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int i = 1, n, c = 0;
	if (head == NULL)
		return -1;
	struct node* temp,*temp1;
	temp = head;
	while (temp != NULL){
		c++;
		temp = temp->next;
	}
	if (c % 2 == 0)
	{
		n = c / 2;
		temp = head;
		while (i < n){
			temp = temp->next;
			i++;
		}
		temp1 = temp->next;
		return (temp->num + (temp1->num)) / 2;

	}
	else{
		n = c / 2;
		temp = head;
		while (i <=n){
			temp = temp->next;
			i++;

		}
		return temp ->num;
	}


}
