/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

#include <string.h>
#include<math.h>

int isOlder(char *dob1, char *dob2) {

	int i, len = 9, j = 0;
	double sum1 = 0, sum2 = 0, n1 = 0, n2 = 0, year1, year2, mon1, mon2, dat1, dat2;
	for (i = 0; i <= len; i++){
		if ((dob1[i] >= 'a' && dob1[i] <= 'z') || (dob1[i] >= 'A' && dob1[i] <= 'Z'))
		{
			return -1;
		}
	}
	if (strlen(dob1) < 9 || strlen(dob2) < 9)
		return -1;
	len = 9;
	i = len;
	while (dob1[i] != '-')
	{
		n1 = dob1[i] - '0';
		n2 = dob2[i] - '0';
		sum1 = sum1 + n1*pow(10.0, j);
		sum2 = sum2 + n2*pow(10.0, j);
		i--;
		j++;
	}
	year1 = sum1;
	year2 = sum2;
	sum1 = 0;
	sum2 = 0;
	i--;
	j = 0;
	while (dob1[i] != '-')
	{
		n1 = dob1[i] - '0';
		n2 = dob2[i] - '0';
		sum1 = sum1 + n1*pow(10.0, j);
		sum2 = sum2 + n2*pow(10.0, j);
		i--;
		j++;
	}
	mon1 = sum1;
	mon2 = sum2;
	sum1 = 0;
	sum2 = 0;
	j = 0;
	i--;
	while (i >= 0){
		n1 = dob1[i] - '0';
		n2 = dob2[i] - '0';
		sum1 = sum1 + n1*pow(10.0, j);
		sum2 = sum2 + n2*pow(10.0, j);
		i--;
		j++;
	}
	dat1 = sum1;
	dat2 = sum2;
	if (mon1 > 12 || mon2 > 12)
		return -1;
	if (mon1 == 2 && dat1 > 28 && (int)year1 % 4 != 0)
		return -1;
	if (mon2 == 2 && dat2 > 28 && (int)year2 % 4 != 0)
		return -1;
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
			else if (dat1 == dat2)
				return 0;
			else
				return 2;
		}
		else
			return 2;

	}
	else
		return 2;
}
