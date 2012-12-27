#include <stdio.h>

int fibonacci(int n)
{
	int fib;
	if (n == 0 || n == 1)
		fib = 1;
	else
		fib = fibonacci(n - 1) + fibonacci(n - 2);

	return fib;
}

int main(int argc, char *argv[])
{
	int n = 5;
	int ret;

	ret = fibonacci(n);
	printf("%d\n", ret);

	return 0;
}
