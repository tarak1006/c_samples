/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char *begin, char *end)
{
	char temp;
	while (begin < end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

void str_words_in_rev(char *input, int len){
	char *word_begin = input;
	char *tempe = input; /* temp is for word boundry */

	/*STEP 1 of the above algorithm */
	while (*tempe)
	{
		tempe++;
		if (*tempe == '\0')
		{
			reverse(word_begin, tempe - 1);
		}
		else if (*tempe == ' ')
		{
			reverse(word_begin, tempe - 1);
			word_begin = tempe + 1;
		}
	} /* End of while */

	/*STEP 2 of the above algorithm */
	reverse(input, tempe - 1);
}
