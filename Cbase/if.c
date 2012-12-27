#include <stdio.h>
int max(int a, int b, int c)
{
	if (a > b)
		if (b > c)
			printf("%d > %d > %d", a, b, c);
		else if (a < c)
			printf("%d > %d > %d", c, a, b);
		else
			printf("%d > %d > %d", a, c, b);
	else if (b < c)
			printf("%d > %d > %d", c, b, a);
		else if (a > c)
			printf("%d > %d > %d", b, a, c);
		else
			printf("%d > %d > %d", b, c, a);
}
int main (int argc, char *argv[])
{
	max(1, 3, 6);
	return 0;
}
