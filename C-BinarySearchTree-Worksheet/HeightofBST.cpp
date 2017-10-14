/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int max(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}
int get_hei(struct node *root){
	int sum1, sum2;
	if (root == NULL)
		return 0;
	else{
		sum1 = get_hei(root->left);
		sum2 = get_hei(root->right);
		return max(sum1, sum2) + 1;
	}

}
int get_height(struct node *root){

	if (root == NULL)
		return 0;
	else{
		return get_hei(root);
	}
}
int get_sum_left(struct node *root)
	{
		if (root == NULL)
			return 0;
		else
			 return root->data + get_sum_left(root->left) + get_sum_left(root->right);

}

int get_left_subtree_sum(struct node *root){
	if (root == NULL)
		return -1;
	if (root->left == NULL)
		return 0;
	return get_sum_left(root->left);
	
}

int get_right_subtree_sum(struct node *root){
	if (root == NULL)
		return -1;
	if (root->right == NULL)
		return 0;
	return get_sum_left(root->right);
	
}

