/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{

	int i = 0, j = len - 1, temp;
	if (Arr == NULL || len <= 0)
		return NULL;
	while (Arr[i] < Arr[i + 1]){
		i++;
		if (i == len - 1)
			break;

	}

	while (Arr[j] > Arr[j - 1]){

		j = j - 1;
		if (j == 0)
			break;
	}
	if (Arr[i] > Arr[j]){


		temp = Arr[j];
		Arr[j] = Arr[i];
		Arr[i] = temp;
	}

	return Arr;
}