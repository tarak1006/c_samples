/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List.
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char* funcn(int i, int k, int **a, char *arr1, char* b,int *cost);
int maximum(int a, int b){
	if (a > b)
		return 1;
	else
		return 2;
}
char * find_common_route(char * hacklist, char *codelist, int *cost){
	int m, n, i = 0, j, max = 0, res = 0;
	if (hacklist == NULL  &&codelist == NULL||hacklist=="" && codelist==""){
	
		*cost = res;
		return NULL;

	}
	
	char *ARR = NULL;
	while (hacklist[i] != '\0')
		i++;
	m = i;
	i = 0;
	while (codelist[i] != '\0')
		i++;
	n = i;
	int **a = (int **)malloc((m + 1)* sizeof(int *));
	for (i = 0; i<m + 1; i++)
		a[i] = (int *)malloc((n + 1) * sizeof(int));
	for (i = 0; i < m + 1; i++){
		for (j = 0; j < n + 1; j++){
			if (i == 0 || j == 0)
				a[i][j] = 0;
			else if (hacklist[i - 1] == codelist[j - 1]){
				a[i][j] = a[i - 1][j - 1] + 1;
				if (maximum(a[i][j], max) == 1){
					max = a[i][j];
				}

			}
			else
				a[i][j] = 0;


		}
	}
	if (max == 0){
		res = 0;
		*cost = res;
		return NULL;
	}

	

	for (i = 1; i<m + 1; i++)
	{
		for (j = 1; j<n + 1; j++){
			if (a[i][j] == max)
			{
				ARR = funcn(i, j, a, ARR, codelist,cost);
			}

		}

	}
	return ARR;
}

int sumofchars(char *str){
	int sum = 0;
	int i = 0;
	while (str[i] != '\0'){
		sum += str[i] - 64;
		i++;
	}
	return sum;
}
char  *compare(char *a, char *b,int *cost){
	int k;
	if (sumofchars(a)  < sumofchars(b)){
		k= sumofchars(a);
		*cost = k;
		return a;
	}
	else if (sumofchars(a) == sumofchars(b)){
		k= sumofchars(a);
		*cost = k;
		if (strcmp(a, b) > 0)
			return b;
		else
			return a;
		
	}
	else{
		k=sumofchars(b);
		*cost = k;
		return b;
	}

}



char* funcn(int i, int k, int **a, char *arr1, char* b,int *cost)
{
	int len;

	if (arr1 == NULL){
		int j = k;

		while (a[i][j] != 1)
		{

			i--;
			j--;
		}
		len = k - j + 1;
		arr1 = (char *)malloc(len + 1 * sizeof(char));
		for (i = 0; i<len; i++)
		{
			arr1[i] = b[j - 1];
			j++;
		}
		arr1[i] = '\0';
		*cost = sumofchars(arr1);
		return arr1;

	}
	else{

		int j = k;
		while (a[i][j] != 1)
		{

			i--;
			j--;
		}
		len = k - j + 1;
		char *arr2 = (char *)malloc(len + 1 * sizeof(char));
		for (i = 0; i<len; i++)
		{
			arr2[i] = b[j - 1];
			j++;
		}
		arr2[i] = '\0';
		arr1 = compare(arr1, arr2,cost);
		*cost = sumofchars(arr1);
		return arr1;

	}
}