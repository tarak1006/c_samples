/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
int pow(int a, int b);
int days(int d1, int m1, int y1, int d2, int m2, int y2);

struct node{
	int data;
	struct node *next;
};
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}

void addNode(struct node **head, int data){
	struct node * cur = createNode(data);
	if (*head == NULL){
		*head = cur;
	}
	else{
		struct node *temp = *head;
		cur->next = temp;
		*head = cur;
	}
}
int greaterDate(int dat1, int mon1, int year1, int dat2, int mon2, int year2){
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

int pow(int a, int b){
	int k = 1;
	while (b > 0){
		k = k*a;
		b--;
	}
	return k;
}

int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	struct node *temp1, *temp2;
	int mon1, dat1, year1, mon2, dat2, year2, c = 0, sum = 0, j,k, diffy, minm, miny, mind, maxy, maxd, maxm;
	temp1 = date1head;
	temp2 = date2head;
	if (temp1 != NULL)
	{
		j = 1;
		while (c < 2){
			sum = sum + (temp1->data)*pow(10, j);
			temp1 = temp1->next;
			c++;
			j--;

		}
		dat1 = sum;
		j = 1;
		c = 0;
		sum = 0;
		while (c < 2){
			sum = sum + (temp1->data)*pow(10, j);
			temp1 = temp1->next;
			c++;
			j--;
		}
		mon1 = sum;
		j = 3;
		c = 0;
		sum = 0;
		while (c < 4){
			sum = sum + (temp1->data)*pow(10, j);
			temp1 = temp1->next;
			c++;
			j--;
		}
		year1 = sum;

	}

	if (temp2 != NULL)
	{
		j = 1;
		c = 0;
		sum = 0;
		while (c < 2){
			sum = sum + (temp2->data)*pow(10, j);
			temp2 = temp2->next;
			c++;
			j--;

		}
		dat2 = sum;
		j = 1;
		c = 0;
		sum = 0;
		while (c < 2){
			sum = sum + (temp2->data)*pow(10, j);
			temp2 = temp2->next;
			c++;
			j--;
		}
		mon2 = sum;
		j = 3;
		c = 0;
		sum = 0;
		while (c < 4){
			sum = sum + (temp2->data)*pow(10, j);
			temp2 = temp2->next;
			c++;
			j--;

		}
		year2 = sum;

	}
	if (greaterDate(dat1, mon1, year1, dat2, mon2, year2) == 0){
		return 0;
	}
	else if (greaterDate(dat1, mon1, year1, dat2, mon2, year2) == 1){
		
		k = days(dat1, mon1, year1, dat2, mon2, year2);
		
	}
	else{
		
		
		
		k = days(dat2, mon2, year2, dat1, mon1, year1);
		


	}
	return k-1;
}

const int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };

int countLeapYears(int y,int m)
{
	int years = y;

	// Check if the current year needs to be considered
	// for the count of leap years or not
	if (m <= 2)
		years--;

	// An year is a leap year if it is a multiple of 4,
	// multiple of 400 and not a multiple of 100.
	return years / 4 - years / 100 + years / 400;
}

// This function returns number of days between two given
// dates
int days(int d1,int m1,int y1,int d2, int m2, int y2)
{
	// COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'

	// initialize count using years and day
	long int n1 = y1 * 365 + d1;

	// Add days for months in given date
	for (int i = 0; i<m1 - 1; i++)
		n1 += monthDays[i];

	// Since every leap year is of 366 days,
	// Add a day for every leap year
	n1 += countLeapYears(y1,m1);

	// SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

	long int n2 = y2 * 365 + d2;
	for (int i = 0; i<m2 - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(y2,m2);

	// return difference between two counts
	return (n2 - n1);
}