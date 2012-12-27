#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int a[N];

void gen_random(int upper_bound)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % 10;
}

void print_random()
{
	int i;
	for (i = 0; i < N; i++) {
		printf("%d ", a[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	gen_random(10);
	print_random();

	return 0;
}
