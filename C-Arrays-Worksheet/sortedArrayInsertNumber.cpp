/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i, j;
	int *Arr1;
	if (len <= 0 || Arr == NULL)
		return NULL;
	Arr1 = (int *)malloc(sizeof(int)*(len + 1));
	for (i = 0; i < len; i++){
		Arr1[i] = Arr[i];
	}
	for (i = 0; i < len; i++){
		if (Arr1[i]>num)
			break;
	}
	for (j = len; j > i; j--)
		Arr1[j] = Arr1[j - 1];
	Arr1[i] = num;
	return Arr1;
}