/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int pow(int b, int k){
	int sum = 1;
	while (k> 0){
		sum = sum*b;
		k--;


	}
	return sum;
}
int countGreaterNumbers(struct transaction *dob1, int len, char *date) {

	int i, j=0, k;
	int sum1=0, year1, mon1, dat1, n1,dat2,mon2,year2;
	dat2 =( date[0] - '0' )* 10 + (date[1] - '0');
	mon2 = (date[3] - '0' )* 10 +( date[4] - '0');
	year2 = (date[6] - '0')*pow(10, 3) + (date[7] - '0')*pow(10, 2) +( date[8] - '0')*10 + (date[9] - '0');
		for (k = 0; k < len; k++){
			i = 9;
			j = 0;
			sum1 = 0;
			while (dob1[k].date[i] != '-')
			{
				n1 = dob1[k].date[i] - '0';
				sum1 = sum1 + n1*pow(10, j);
				i--;
				j++;
			}
			year1 = sum1;
			sum1 = 0;
			i--;
			j = 0;
			while (dob1[k].date[i] != '-')
			{
				n1 = dob1[k].date[i] - '0';
				sum1 = sum1 + n1*pow(10, j);
				i--;
				j++;
			}
			mon1 = sum1;
			sum1 = 0;
			j = 0;
			i--;
			while (i >= 0){
				n1 = dob1[k].date[i] - '0';
				sum1 = sum1 + n1*pow(10, j);
				i--;
				j++;
			}
			dat1 = sum1;


			if (year1 > year2)
				goto x;
			else if (year1 == year2){
				if (mon1 > mon2)
					goto x;
				else if (mon1 == mon2){
					if (dat1 > dat2)
						goto x;
				}
			}



		}

		return 0;

	x:
		return len - k;
}
