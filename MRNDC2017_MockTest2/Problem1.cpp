/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>
#define size 31
#define size2 64
#include<ctype.h>
int valid(char c){
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '@' || c == '.'|| c =='-' || c =='_')
		return 1;
	return 0;




}


int isValid(char *email)
{
	int i, pos1, pos2, c1 = 0, c2 = 0;
	i = 0;
	while (email[i] != '\0'){
		if (valid(email[i]) != 1)
			return 0;

		if (email[i] == '@')
		{
			c1++;
			pos1 = i;
		}
		if (email[i] == '.')
		{
			c2++;
			pos2 = i;

		}
		i++;
	}
	if (c1 != 1 || c2 == 0 || (pos2 - pos1 <= 1))
		return 0;

	return 1;
}

int isValidEmail(char * email){
	int namelen, i, j, k, pos, count1 = 0, count2 = 0;
	char a[size], b[size2];
	i = 0;
	while (email[i] != ' ')
	{
		a[i] = tolower(email[i]);
		i++;
	}
	namelen = i;
	a[i] = '\0';


	while (email[i] == ' ')
		i++;
	j = 0;
	while (email[i] != '\0')
	{
		b[j++] = email[i++];

	}
	b[j] = '\0';



	k = isValid(b);
	if (k == 0)
		return 0;
	else{
		i = 0;
		while (b[i] != '\0'){

			if (b[i] == '@'){
				pos = i;
				break;
			}
			i++;

		}
		i = 0;
		if (a[i] == tolower(b[i])){
			while (a[i] == tolower(b[i]) && i<namelen){
				i++;
				count1++;
			}
		}
		k = pos - 1;
		i = namelen - 1;
		if (a[i] == tolower(b[k])){
			while (a[i] == tolower(b[k]) && i >= 0 && k >= 0)
			{
				i--; k--;
				count2++;
			}
		}
		if (count1 == namelen || count2 == namelen)
			return 2;
		else
			return 1;





	}


}
