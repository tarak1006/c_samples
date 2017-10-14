/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char removeSpaces(char *str) {
	char* i = str;	
	char* j = str;
	if (str != "" && str != NULL){
		while (*j != 0)
		{
			*i = *j++;
			if (*i != ' ')
				i++;
		}
		*i = 0;
	}

	return '\0';
}