#include <stdio.h>
/*
 * 递归
 * 1.base case
 * 2.调用自己本身*/
int gcdrecurse(int a, int b)
{
	int gcd;

	if (a % b == 0)
		gcd = b;
	else {
		b = a % b;
		gcd = gcdrecurse(a, b);
	}
	//printf("%d\n", gcd);
	return gcd;
}

int main(int argc, char *argv[])
{	int a = 32;
	int b = 16;
	int gcd;

	gcd = gcdrecurse(a, b);
	printf("%d\n", gcd);

	return 0;
}
