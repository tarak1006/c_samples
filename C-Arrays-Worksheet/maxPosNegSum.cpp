
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input, int length)
{
	int j, temp,i,p=0,n=0;
	if (length <= 0)
		return 0;
	for (i = 0; i < length; i++){
		if (input[i]>=0)
			p++;
		else
			n++;
	}
	for (i = 0; i < length; i++){

		for (j = i + 1; j < length ; j++){
			if (input[j] < input[i]){
				temp = input[i];
				input[i] = input[j];
				input[j]=temp;
			}
		}
	}
	if (p == 0 || n == 0)
		return 0;
	return (input[n-1] + input[length - 1]);
		}