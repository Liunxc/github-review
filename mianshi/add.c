#include <stdio.h>

int add(int a, int b, int *c)
{
	*c = a + b;
	//return 0;
	return (a > 0 && b > 0 && (*c < a || *c < b) || (a < 0 && b < 0 && (*c > a|| *c > b)));
}

int main()
{
	int a, b, *c;
	int d;
	a = (1 << 31) - 1;
	b = 1 << 30;
	d = a + b;
	add(a, b, c);
	printf("c = %d a = %d b =  %d\n", *c, a, b);

	return 0;
}
