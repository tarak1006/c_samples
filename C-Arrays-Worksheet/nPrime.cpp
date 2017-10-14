
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int* nPrime(int N)
{
	int  c, b = 1;
	int j, i;

	int* ptr;
	if (N <= 0)
		return NULL;
	ptr = (int *)malloc(sizeof(int) * 30);
	for (i = 2; i < N; i++){
		c = 0;
		for (j = 2; j <= (i / 2); j++){

			if (i %j == 0)
				c++;
		}
		if (c == 0)
		{
			*(ptr + (b - 1)) = i;
			b++;



		}
	}


	return ptr;
}