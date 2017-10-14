/*
OVERVIEW: Given a string, Return the substring of the main string from i index to j index
Indexes start from 0,ith letter and jth letter are included
E.g.: Input: "get_sub_string("abcdefgh",2,5) , Output: "cdef"

INPUTS: A string.

OUTPUT: return substring from [i,j]

INPUT2: I will Code for Mission RnD , 2,10
OUTPUT2:will Code

NOTES: Check Null Strings ,Include stddef for NULL if needed.Create a New string and return it ,dont modfiy
original String
*/

#include <stddef.h>
#include <stdlib.h>

char * get_sub_string(char *str, int k1, int k2){
	int i = 0,l=0;
	if (str == NULL || k1 < 0 || k2 < 0||k2<k1)
		return NULL;
	char* c = (char *)malloc((k2 - k1)*sizeof(char));
	i = k1;
	while (i != k2)
	{
		c[l] = str[i];
		l++; i++;
	}
	c[l] = str[i];


    return c;
}
