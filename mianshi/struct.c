#include <stdio.h>
struct A {
	int a:8;
	int b:2;
	int c:6;
};

int main()
{
	struct A x;
	x.a = 127;
	x.b = 5;
	x.c = 32;
	printf("%d %d %d %d\n", sizeof(struct A), x.a, x.b, x.c);
	return 0;
}
