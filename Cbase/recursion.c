#include <stdio.h>

int recursion(int n)
{
	int f;
	if (n == 0 || n == 1)
		f = 1;
	else
		f = n * recursion(n - 1);

	return f;
}

int main(int argc, char * argv[])
{
	int ret;

	ret = recursion(5);
	printf("%d\n", ret);

	return 0;
}
