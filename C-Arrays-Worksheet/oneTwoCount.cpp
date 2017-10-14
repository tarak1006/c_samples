
/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2]
output: [3,4]
where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/

#include <stdio.h>
#include<stdlib.h>
int* oneTwoCount(int* input, int length)
{
	if (length <= 0 || input == 0 || input == NULL)
		return NULL;
	else{

		int *p, i, k = 0;
		int c = 0;
		p = (int *)malloc(sizeof(int) * 2);

		for (i = 0; i < length; i++)
		{
			if (input[i] == 1)
				k++;
			else
				c++;

		}
		*(p + 0) = k;
		*(p + 1) = c;

		return p;

	}



}