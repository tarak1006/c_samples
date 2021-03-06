/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void funcn(struct node *root, int *arr,int *i)
{
	if (root != NULL){
		funcn(root->left, arr,i);
		arr[*i] = root->data;
		(*i)++;
		funcn(root->right, arr,i);
	}
}
void inorder(struct node *root, int *arr){
	int i = 0;
	if (root != NULL && arr!=NULL){
	
		funcn(root, arr,&i);
	}
}
	void preorde(struct node *root, int *arr,int *i){
		if (root != NULL){
			arr[*i] = root->data;
			(*i)++;
			preorde(root->left, arr,i);
			preorde(root->right, arr,i);
		}
	}
	void preorder(struct node *root, int *arr){
		int i = 0;
		if (root != NULL && arr != NULL){
			preorde(root, arr,&i);
		}
	}
	
	void postorde(struct node *root, int *arr,int *i){
		
		if (root != NULL){
			postorde(root->left, arr,i);
			postorde(root->right, arr,i);

			arr[*i] = root->data;
			(*i)++;
		}

	}

	void postorder(struct node *root, int *arr){
		int i=0;
		if (root != NULL && arr != NULL){
			postorde(root, arr,&i);
		}
	}




