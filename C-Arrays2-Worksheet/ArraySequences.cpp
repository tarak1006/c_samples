/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int* find_sequences(int *arr, int len){
	int* a;
	int i, j;
	if (arr == NULL || len == 0)
		return NULL;
	
	a = (int *)malloc(sizeof(int) * 6);
	for (i = 0; i < len; i++){
		if (arr[i + 1] - arr[i] == arr[i + 2] - arr[i + 1]){
			a[0] = i;
			i = i + 1;
			while (arr[i + 1] - arr[i] == arr[i] - arr[i - 1])
			{
				i = i + 1;
			}
			a[1] = i;
			goto x;
		}
	}
	x:
		for (j = i; j < len; j++){
			if (arr[j + 1] - arr[j] == arr[j + 2] - arr[j + 1]){
				a[2] = j;
				j = j + 1;
				while (arr[j + 1] - arr[j] == arr[j] - arr[j - 1])
				{
					j = j + 1;
				}
				a[3] = j;
				goto y;

		}
	}
	y:
		for (i = 0; i < len-2; i++){
	if(arr[i]>arr[i+1]){
		
		if (arr[i] != 0 && arr[i + 1] != 0 && arr[i + 2] != 0 && arr[i] % arr[i + 1] == 0 && arr[i + 1] % arr[i + 2] == 0 && arr[i + 1] / arr[i] == arr[i + 2] / arr[i + 1]){
			a[4] = i;
			printf("\n%d", a[4]);
			i = i + 1;
			while (arr[i - 1] != 0 && arr[i] != 0 && arr[i + 1] != 0 && arr[i] % arr[i + 1] == 0 && arr[i - 1] % arr[i] == 0 && i < len - 1 && arr[i + 1] / arr[i] == arr[i] / arr[i - 1])
				i++;

			a[5] = i;
			printf("\n%d", a[5]);
			goto z;

		}
	}
	else{
		if (arr[i] != 0 && arr[i + 1] != 0 && arr[i + 2] != 0 && arr[i + 1] % arr[i] == 0 && arr[i + 2] % arr[i + 1] == 0 && arr[i + 1] / arr[i] == arr[i + 2] / arr[i + 1]){
			a[4] = i;
			i = i + 1;
			while (arr[i - 1] != 0 && arr[i] != 0 && arr[i + 1] != 0 && i < len - 1 && arr[i + 1] % arr[i] == 0 && arr[i] % arr[i - 1] == 0 && arr[i + 1] / arr[i] == arr[i] / arr[i - 1])
				i++;



			a[5] = i;
			goto z;
		}
		}
		
	}
				
				



	z:
		return a;
}