/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for
octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.


INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]
*/

int pow(int a, int b)
{
	int m = 1;
	while (b > 0)
	{
		m = m*a;
		b--;
	}
	return m;

}
int octalToHexadecimal(long int num)
{
	int OCTALVALUES[] = { 0, 1, 10, 11, 100, 101, 110, 111 };
	if (num == 0 || num == -1)
		return 0;

	long long octal,  binary, place, i = 0;
	int sum = 0;
	int rem;

	place = 1;
	binary = 0;

	/*
	* Reads octal number from user
	*/

	/*
	* Finds binary value of octal number
	*/
	while (num != 0)
	{
		rem = num % 10;
		binary = (OCTALVALUES[rem] * place) + binary;
		num /= 10;

		place *= 1000;
	}

	/*
	* Finds hexadecimal of binary value converted in above step
	*/
	while (binary != 0)
	{
		rem = binary % 10000;
		switch (rem)
		{
		case 0:
			sum = sum + 0;
			break;
		case 1:
			sum = sum + 1 * pow(10.0, i);
			break;
		case 10:
			sum = sum + 2 * pow(10.0, i);
			break;
		case 11:
			sum = sum + 3 * pow(10.0, i);
			break;
		case 100:
			sum = sum + 4 * pow(10.0, i);
			break;
		case 101:
			sum = sum + 5 * pow(10.0, i);
			break;
		case 110:
			sum = sum + 6 * pow(10.0, i);
			break;
		case 111:
			sum = sum + 7 * pow(10.0, i);
			break;
		case 1000:
			sum = sum + 8 * pow(10.0, i);
			break;
		case 1001:
			sum = sum + 9 * pow(10.0, i);
			break;

		}

		binary /= 10000;
		i++;
	}


	return sum;
}
