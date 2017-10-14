/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int noofnodes(struct node *root,int c){
	if (root == NULL)
		return 0;
	else{
		c += noofnodes(root->left,c);
		c += noofnodes(root->right,c);
		return c;
	}
}
int get_height3(struct node *root){
	int sum1, sum2;
	if (root == NULL)
		return 0;
	else{
		sum1 = get_height3(root->left);
		sum2 = get_height3(root->right);
		if (sum1>sum2)
			return sum1 + 1;
		else
			return sum2 + 1;
	}

}
void getrows(struct node *root, int k,int *arr,int *i){
	if (root == NULL)
		return;
	if (k == 1)
		arr[(*i)++] = root->data;
	else
	{
		getrows(root->right, k - 1,arr,i);
		getrows(root->left, k - 1,arr,i);

	}




}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int i, j = 0, c = 1, k;
	int n = noofnodes(root, c);
	int *a = (int *)malloc(n*sizeof(int));


	k = get_height3(root);
	for (i = 1; i <= k; i++){
		getrows(root, i, a, &j);
	}
	return a;
}