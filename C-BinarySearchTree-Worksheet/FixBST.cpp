/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void funcn(struct node *root, struct node **first, struct node **second, struct node **third, struct node **previous)
{
	if (root != NULL){
		funcn(root->left, first, second, third, previous);

		if (*previous && root->data < (*previous)->data){
			if (*first == NULL){
				*first = *previous;
				*second = root;
			}
			else{
				*third = root;

			}

		}
		*previous = root;



		funcn(root->right, first, second, third, previous);

	}


}


void swap_nodes(struct node *a, struct node *b){
	int temp;
	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void fix_bst(struct node *root){

	if (root != NULL){
		

	struct node *first = NULL, *second = NULL;
	struct node *third = NULL;
	struct node *previous = NULL;
	funcn(root, &first, &second, &third, &previous);

	if (first && third)
		swap(&(first->data), &(third->data));
	else
		swap(&(first->data), &(second->data));
	}



}