#include <stdio.h>

int itoa(int n, char dest[])
{
	int len = 0;
	int tmp = n;

	do {
		len++;
		tmp = tmp / 10;
	} while (tmp != 0);
printf("%d\n", len);
	tmp = n;
	do {
		len--;
		dest[len] = '0' + tmp % 10;
		tmp = tmp / 10;
	} while (len >=0);

	return 0;
}

int main(int argc, char *argv[])
{
	int n = 1234567;
	char dest[20];
	itoa(n, dest);
	printf("%s\n", dest);

	return 0;
}
