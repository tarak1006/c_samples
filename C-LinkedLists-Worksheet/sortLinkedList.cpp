/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

void swa(node *p1, node*p2)
{
	int temp = p1->num;
	p1->num = p2->num;
	p2->num = temp;
}

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
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
			if (min->num > trav->num)
			{
				min = trav;
			}

			trav = trav->next;
		}
		swa(start, min);			// Put minimum element on starting location
		start = start->next;
	}
	return head;
}