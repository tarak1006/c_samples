/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int count_word_in_str_way_1(char *str, char *word){
	int i = 0,j=0,k,c,len,maincount=0;

	while (word[j] != '\0'){
		j++;
	}
	len = j ;
	while (str[i] != '\0'){
		j = 0;
		if (str[i] == word[j]){
			k = i + 1;
			j++;
			c = 1; 
			
			while (str[k] == word[j]&&str[k]!='\0'&& word[j]!='\0'){
				k++;
				j++; c++;
				if (c == len)
					break;
			}
			if (c == len)
				maincount++;

		}
			i++;
	}
	return maincount;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

