#include <stdio.h>
//for while do while goto
int for_sum(int n)
{
	int i, sum = 0;
	for (i = 1; i <= n; i++)
		sum = sum + i;

	return sum;
}


int while_sum(int n)
{
	int i = 1, sum = 0;
	while (i <= n) {
		sum = sum + i;
		i++;
	}

	return sum;
}

int do_while_sum(int n)
{
	int i = 1, sum = 0;

	do {
		sum = sum + i;
		i++;
	} while (i <= n);

	return sum;
}

int goto_sum(int n)
{
	int i = 1, sum = 0;
lab:
		sum = sum + i;
		i++;
		if (i <= n)
	goto lab;

	return sum;
}

int main(int argc, char * argv[])
{
	int n = 100;
	int sum;

	sum = for_sum(n);
	printf("%d\n", sum);
	sum = while_sum(n);
	printf("%d\n", sum);
	sum = do_while_sum(n);
	printf("%d\n", sum);
	sum = goto_sum(n);
	printf("%d\n", sum);

	return 0;
}
