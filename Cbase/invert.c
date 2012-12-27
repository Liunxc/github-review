#include <stdio.h>
//将x从第p位开始的n位取反。
int invert(int x, int p, int n)
{
	return ((((1 << n) - 1) << p) ^ x);
}

int main(int argc, char *argv[])
{
	int ret;

	ret = invert(127, 0, 3);
	printf("%d\n", ret);

	return 0;
}
