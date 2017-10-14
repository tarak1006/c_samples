/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <math.h>
#include <string.h>


// reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

// Converts a given integer x to string str[].  d is the number
// of digits required in output. If d is more than the number
// of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}
int power(int a, int b)
{
	int p = 1;
	while (b > 0){
		p = p*a;
		b--;
	}
	return p;
}

void number_to_str(float number, char *str, int afterdecimal){
	int x = 0;
	if (number < 0)
	{
		x = 1;
		number = number*-1;
	}
	// Extract integer part
	int ipart = (int)number;

	// Extract floating part
	float fpart = number - (float)ipart;

	// convert integer part to string
	int i = intToStr(ipart, str, 0);

	// check for display option after point
	if (afterdecimal != 0)
	{
		str[i] = '.';  // add dot

		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter is needed
		// to handle cases like 233.007
		fpart = (float)(fpart * power(10, afterdecimal));

		intToStr((int)fpart, str + i + 1, afterdecimal);
	}
	if (x == 1){
		strrev(str);
		strcat(str, "-");
		strrev(str);
	}
}
