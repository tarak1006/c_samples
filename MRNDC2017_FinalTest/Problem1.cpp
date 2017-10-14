/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a4e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int isDigit(char letter){
	if (letter >= '0'&&letter <= '9')
		return 1;
	return 0;
}

int isLetter(char letter){
	if (letter >= 'a'&&letter <= 'z')
		return 1;
	return 0;
}
int getLength(char *str){
	int len = 0, i = 0, n;
	while (str[i] != '\0'){
		if (isDigit(str[i]) && isDigit(str[i + 1])){
			n = str[i] - '0';
			n = n * 10 + (str[i + 1] - '0');
			len = len + n;
			i = i + 2;
		}
		else if (isDigit(str[i])){
			len = len + (str[i] - '0');
			i = i + 1;
		}
		else{
			len = len + 1;
			i++;
		}
	}
	return len;
}


int isSTRMatched(char *str1, char *str2){
	int i = 0, i2 = 0, k = 0, k2 = 0, n;
	if (str1 == NULL || str2 == NULL)
		return -1;
	if (getLength(str1) != getLength(str2))
		return 0;
	if (getLength(str1) > 10000)
		return -1;
	if (getLength(str2) > 10000)
		return -1;

	char* a = (char*)malloc(sizeof(char)*getLength(str1));
	char* b = (char*)malloc(sizeof(char)*getLength(str2));
	while (str1[i] != '\0'){
		if (isLetter(str1[i])){
			a[k] = str1[i];
			k++;
		}
		else{
			n = str1[i] - '0';
			if (n > 999)
				return -1;
			while (n > 0)
			{
				a[k] = '1';
				k++;
				n--;
			}
		}
		i++;
	}
	while (str2[i2] != '\0'){
		if (isLetter(str2[i2])){
			b[k2] = str2[i2];
			k2++;
		}
		else{
			n = str2[i2] - '0';
			if (n > 999)
				return -1;

			while (n > 0)
			{
				b[k2] = '1';
				k2++;
				n--;
			}
		}
		i2++;

	}
	for (i = 0; i < getLength(str1); i++){
		if (a[i] != b[i] && a[i] != '1' && b[i] != '1')
			return 0;

	}



	return 1;
}
