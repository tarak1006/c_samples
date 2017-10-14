/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
}*temp1,*temp2,*prev;


struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	temp1 = head1; temp2 = head2;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else
	{   
		if (temp1->num < temp2->num){
			prev = temp1;
			temp1=temp1->next;
		}
		else{
			head1 = head2;
			prev = temp2;
			temp2=temp2->next;
		}
		while (temp1 != NULL&&temp2 != NULL){
			if (temp1->num > temp2->num)
			{
				
				prev->next = temp2;
				prev = temp2;
				temp2 = temp2->next;


			}
			else
			{
				prev->next = temp1;
				prev = temp1;
				temp1 = temp1->next;


			}

		}
		if (temp2 != NULL)
		{
			temp1 = prev;
			while (temp2 != NULL){
				temp1->next = temp2;
				temp2 = temp2->next;
				temp1 = temp1->next;
			}

		}
		else{
			if (temp1 != NULL)
			{
				temp2 = prev;
				while (temp1 != NULL){
					temp2->next = temp1;
					temp2 = temp2->next;
					temp1 = temp1->next;
				}

			}
		}


		return head1;

	}
}
