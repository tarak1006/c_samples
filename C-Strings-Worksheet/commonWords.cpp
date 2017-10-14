/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL && str2 == NULL)
		return NULL;

	char a[SIZE][SIZE];
	char **res=NULL;
	char *temp = (char *)malloc(31 * sizeof(char));
	int j = 0, k, c1 = 0, c2 = 0, i = 0, flag, wordnum = 0, l;

	while (i < strlen(str1))
	{
		j = 0;
		flag = 0;
		while (str1[i] != ' '&&i < strlen(str1))
		{
			temp[j] = str1[i];
			i++;
			j++;
		}
		temp[j] = '\0';

		if (wordnum != 0){
			for (k = 0; k < wordnum; k++)
			{
				if (strcmp(a[k], temp) == 0)
					flag = 1;

			}
		}

		if (flag != 1){
			for (l = 0; temp[l] != '\0'; l++){
				a[wordnum][l] = temp[l];
			}
			a[wordnum][l] = '\0';
			wordnum++;
		}
		i++;
	}

	wordnum--;







	i = 0;
	while (i < strlen(str2))
	{
		j = 0;
		while (str2[i] != ' ' && i < strlen(str2))
		{
			temp[j] = str2[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		for (k = 0; k < wordnum; k++)
		{
			if (strcmp(a[k], temp) == 0)
			{
				c2++;
				res = (char**)realloc(res, c2 * sizeof(char*));
				res[c2 - 1] = &a[k][0];
			}
		}
		i++;
	}
	return res;

}
	




