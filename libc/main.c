#include "libc.h"

int main(int argc, char *argv[])
{
	const char *src = "hello maxwiter!";
	int a[2] = {1, 5};
	int b[4] = {3, 4, 6, 9};
	int h [6];
	int i = 0;

	do_dup(a, b, h, 2, 4);

	while (i < 6) {
		printf("%d ", h[i]);
		i++;
	}

	printf("\n");

	return 0;
}
