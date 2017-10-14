/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	
	int i = 0, l = 0, k1, k2, l1 = 0, flag = 0;
	if (str[i] == '\0')
		return str;
	while (str[i] != '\0'){
		if (str[i] == ' '){
			flag++;
		}
		i++;
	}
	if (flag == i){

		char* d = (char *)malloc(1 * sizeof(char));
		d[0] = '\0';
		return d;
	}
	i--;
	while (str[i] == ' '){
		i--;

	}
	k2 = i;
	while (str[i] != ' '){
		i--;
		if (i < 0)
		{
			return str;
		}

	}

	i++;
	k1 = i;
	l1 = k2 - k1 + 1;
	char* c = (char *)malloc(l1*sizeof(char));
	while (k1 <= k2)
	{
		c[l] = str[k1];
		l++;
		k1++;

	}
	c[l] = '\0';
	return c;




}
