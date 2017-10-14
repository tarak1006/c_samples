/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdio.h>
int findSingleOccurenceNumber(int *arr, int len) {
	if (arr == NULL|| len <= 0)
		return -1;
	int ones = 0, twos = 0;

	int common_bit_mask;
	for (int i = 0; i< len; i++)
	{
		
		twos = twos | (ones & arr[i]);


			ones = ones ^ arr[i];


		common_bit_mask = ~(ones & twos);


		ones &= common_bit_mask;


		twos &= common_bit_mask;

		
	}

	return ones;
}
