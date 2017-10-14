/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci()
nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{

	long int i, x, y, temp;
	if (n <= 0)
		return -1;
	if (n == 1){
		return 0;
	}
	else if (n == 2)
		return 1;
	else{
		x = 0;
		y = 1;
		for (i = 2; i < n; i++){
			temp = y;
			y = x + y;
			x = temp;
		}
		return y;
	}

}

int nthPrime(int num)
{
	long int i = 0, j, c, n, p = 0;
	if (num <= 0)
		return -1;
	for (i = 2; i < 1000; i++){
		c = 0;
		for (j = 1; j <= i; j++){
			if (i%j == 0){
				c++;
			}
		}
		if (c == 2){
			p++;
			n = i;
		}
		if (p == num)
			break;
	}
	return i;
}