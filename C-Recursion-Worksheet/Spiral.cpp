/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void recspiral(int *a, int i1, int i2, int j1, int j2, int **matrix, int *k){
	int i;
	//traverse left
	if (i1 <= i2 && j1 <= j2){
		for (i = j1; i<j2; i++){
			a[(*k)++] = matrix[i1][i];
	


		}
		j2--;
		for (i = i1; i <= i2; i++){
			a[(*k)++] = matrix[i][j2 + 1];
		
		}
		i2--;
		if (i1 <= i2){
			for (i = j2; i >= j1; i--){
				a[(*k)++] = matrix[i2 + 1][i];
		
			}
			j1++;
		}
		if (j1 <= j2){
			for (i = i2; i>i1; i--){
				a[(*k)++] = matrix[i][j1 - 1];
				
			}
			i1++;
		}
		recspiral(a, i1, i2, j1, j2, matrix, k);
	}
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows<0 || columns <0 || (rows==0 && columns==0))
		return NULL;
	int *a = (int *)malloc(rows*columns *sizeof(int));
	int k = 0;
	recspiral(a, 0, rows - 1, 0, columns - 1, input_array, &k);
	return a;
}

