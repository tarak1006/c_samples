/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<string.h>
void matchstrings(char *str1, char *str2){
	
	int l1, l2, i, j;
	char *str;
	l2 = strlen(str2);
	l1 = strlen(str1);
	str = (char *)malloc(l2*sizeof(char));
	for (i = 0; i < l2 - l1; i++)
		str[i] = '0';
	for (j = 0; j<l1; j++){
		str[i] = str1[j];
		i++;
	}
	for (i = 0; i<l2; i++){
		str1[i] = str[i];
	}

	str1[i] = '\0';





}

char *performOperation(char *str1, char *str2, char *operation){
	if (str1 == NULL || str2 == NULL)
		return NULL;
	char *sum = NULL, c;
	int l, i, a, b;
	if (strlen(str1)<strlen(str2)){
		l = strlen(str2);

		matchstrings(str1, str2);

	}
	else if (strlen(str1)>strlen(str2)){
		l = strlen(str1);
		matchstrings(str2, str1);
	}
	else
		l = strlen(str1);
	sum = (char *)malloc(l*sizeof(char));

	if (strcmp(operation, "AND") == 0)
	{
		for (i = 0; i<l; i++)
		{
			a = str1[i] - '0';
			b = str2[i] - '0';
			c = (a&b) + '0';;
			sum[i] = c;

		}

	}
	else if (strcmp(operation, "OR") == 0)
	{
		for (i = 0; i<l; i++)
		{
			a = str1[i] - '0';
			b = str2[i] - '0';
			c = (a | b) + '0';;
			sum[i] = c;

		}

	}
	else if (strcmp(operation, "XOR") == 0)
	{
		for (i = 0; i<l; i++)
		{
			a = str1[i] - '0';
			b = str2[i] - '0';
			c = (a^b) + '0';;
			sum[i] = c;

		}

	}
	else if (strcmp(operation, "NOR") == 0)
	{
		for (i = 0; i < l; i++)
		{
			a = str1[i] - '0';
			b = str2[i] - '0';
			c = (a | b) + '0';
			if (c == '1')
				c = '0';
			else
				c = '1';
			sum[i] = c;

		}

	}
	else
		return NULL;

	sum[i] = '\0';

	return sum;
}












