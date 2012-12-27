#include <stdio.h>

typedef int type;

type max(int n, ...)
{
	int i;
	type maxnum;
	long *p = (long *)&n;
	maxnum = (type) *++p;

	for (i = 1; i < n; i++) {
		p++;
		if (*p > maxnum) {
			maxnum = (type)(*p);
		}
	}

	return maxnum;
}

int main(int argc, char * argv[])
{
	type maxnum;

	maxnum = max(5, 1, 2, 3, 9);
	printf("%d\n", maxnum);

	return 0;
}
