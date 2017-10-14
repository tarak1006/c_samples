/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int funcn(char *date, char *date2){
	int j = 0;
	int  year1, mon1, dat1, dat2, mon2, year2;
	dat1 = (date[0] - '0') * 10 + (date[1] - '0');
	mon1 = (date[3] - '0') * 10 + (date[4] - '0');
	year1 = (date[6] - '0')*pow(10, 3) + (date[7] - '0')*pow(10, 2) + (date[8] - '0') * 10 + (date[9] - '0');

	dat2 = (date2[0] - '0') * 10 + (date2[1] - '0');
	mon2 = (date2[3] - '0') * 10 + (date2[4] - '0');
	year2 = (date2[6] - '0')*pow(10, 3) + (date2[7] - '0')*pow(10, 2) + (date2[8] - '0') * 10 + (date2[9] - '0');

	if (year1 < year2)
		return 1;
	else if (year1 == year2)
	{
		if (mon1 < mon2)
			return 1;
		else if (mon1 == mon2)
		{
			if (dat1 < dat2)
				return 1;
			else
				return 0;

		}
		else
			return 0;

	}
	else
		return 0;



}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i1 = 0, i2 = 0,k=0;
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;
	struct transaction* C = (struct transaction*)malloc((ALen+BLen)*sizeof(struct transaction));
	while (i1 < ALen&&i2 < BLen){
		if (funcn(A[i1].date, B[i2].date)){
			C[k] = A[i1];
			i1++;
			k++;
		}
		else{
			C[k] = B[i2];
			i2++;
			k++;

		}
	}
	while(i1 < ALen){
		C[k] = A[i1];
		k++;
		i1++;
	}
	while(i2 < BLen){
		C[k] = B[i2];
		k++;
		i2++;
	}
	
	
	return C;
}