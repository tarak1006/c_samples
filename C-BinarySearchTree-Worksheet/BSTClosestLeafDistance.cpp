/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int get_hei2(struct node *root){
	int sum1, sum2;
	if (root == NULL)
		return 0;
	else{
		sum1 = get_hei2(root->left);
		sum2 = get_hei2(root->right);
		if (sum2 == 0)
			return sum1+1;
		if (sum1 == 0)
			return sum2+1;
		if ( sum1 < sum2)
			return sum1 + 1;
		else
		   return sum2 + 1;
 
	}

}
int get_height2(struct node *root){

	if (root == NULL)
		return 0;
	else{
		return get_hei2(root);
	}
}


int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int k1, k2;
	k1=get_height2(temp)-1;
	k2 = get_height2(root->left)  + (get_height2(root->right) - k1);
	if (k1 < k2)
		return k1;
	else
		return k2;

}