/*
OVERVIEW:
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]
*/
#include<math.h>
int decimalToOctal(int num)
{
	int s, i = 0;
	double sum = 0;
	while (num > 0){
		s = num % 8;
		sum = sum + s*pow(10.0, i);
		num = num / 8;
		i++;
	}
	return sum;
}

float decimalToOctalFraction(float num)
{
	return 0.00;
}
