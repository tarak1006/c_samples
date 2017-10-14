/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>
int isalphabet(char c){
	if (c >= 'a' && c <= 'z' || c >= 'A'&& c <= 'Z')
		return 1;
	return 0;
}

void count_vowels_and_consonants(char *str, int *consonants, int *vowels){
	int i = 0,c=0,v=0;
	if (str !=NULL){
		for (i = 0; str[i] != '\0'; i++){
			if (isalphabet(str[i])){
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'U' || str[i] == 'O')
					v++;
				else
					c++;
			}
		}
	}
	*consonants = c;
	*vowels = v;
}
