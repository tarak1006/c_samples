/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>


struct node {
	int data;
	struct node *next;
};

void swap(node *p1, node*p2)
{
	int temp = p1->data;
	p1->data = p2->data;
	p2->data = temp;
}

void sll_012_sort(struct node *head){
	node *start = head;
	node *trav;
	node *min;

	while (start->next)
	{
		min = start;
		trav = start->next;

		while (trav)
		{
			/* Find minimum element from array */
			if (min->data > trav->data)
			{
				min = trav;
			}

			trav = trav->next;
		}
		swap(start, min);			// Put minimum element on starting location
		start = start->next;
	}
}