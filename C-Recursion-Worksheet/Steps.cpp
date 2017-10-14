/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"


int noofsteps(int s)
{
	if (s==0 ||s==1)
		return 1;
	return (noofsteps(s - 1) + noofsteps(s - 2));

}


int get_steps(int s)
{
	if (s <= 0)
		return 0;
	else
		return noofsteps(s);
}
