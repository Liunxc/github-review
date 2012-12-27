#include <stdio.h>

int iteration(int n);

int main(int argc, char *argv[])
{
	int ret;

	ret = iteration(5);
	printf("%d\n", ret);

	return 0;
}

int iteration(int n)
{
	int result = 1;

	while (n > 0) {
		result = result * n;
		n--;
	}

	return result;
}
