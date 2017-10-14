/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int funcn2(char *date, char *date2){
	int j = 0;
	int  year1, mon1, dat1, dat2, mon2, year2;
	dat1 = (date[0] - '0') * 10 + (date[1] - '0');
	mon1 = (date[3] - '0') * 10 + (date[4] - '0');
	year1 = (date[6] - '0')*pow(10, 3) + (date[7] - '0')*pow(10, 2) + (date[8] - '0') * 10 + (date[9] - '0');

	dat2 = (date2[0] - '0') * 10 + (date2[1] - '0');
	mon2 = (date2[3] - '0') * 10 + (date2[4] - '0');
	year2 = (date2[6] - '0')*pow(10, 3) + (date2[7] - '0')*pow(10, 2) + (date2[8] - '0') * 10 + (date2[9] - '0');

	if (year1 < year2)
		return 0;
	else if (year1 == year2)
	{
		if (mon1 < mon2)
			return 0;
		else if (mon1 == mon2)
		{
			if (dat1 < dat2)
				return 0;
			else if (dat1 == dat2)
				return 1;
			else
				return 2;

		}
		else
			return 2;

	}
	else
		return 2;



}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i1 = 0, i2 = 0, k = 0,l;
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
		return NULL;
	if (ALen < BLen)
		l = ALen;
	else
		l = BLen;
	struct transaction* C = (struct transaction*)malloc(l*sizeof(struct transaction));
	while (i1 < ALen&&i2 < BLen){
		if (funcn2(A[i1].date, B[i2].date)){
			C[k] = A[i1];
			i1++;
			k++;
		}
		else if (funcn2(A[i1].date, B[i2].date) == 0)
			i1++;
		else
			i2++;
			

		
	}
	if (k == 0)
		return NULL;
	return C;





}