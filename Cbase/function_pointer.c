#include <stdio.h>

typedef int (*func)(int n);

int show(int n)
{
	printf("%d\n", n);

	return 0;
}

int main(int argc, char *argv[])
{
	int n = 6;
	func handle = show;
	handle(n);

	return 0;
}
