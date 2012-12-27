#include <stdio.h>

int itoa(int num, char *str);

int main(int argc, char *argv[])
{
	int num  = 123456;
	char str[10];

	itoa(num, str);

	printf("%s\n", str);

	return 0;
}

int itoa(int num, char *str)
{
	int len = 0;
	int tmp = num;

	while (tmp) {
		len++;
		tmp /= 10;
	}

	tmp = num;
	str[len] = '\0';

	while (len >=0) {
		str[--len] = tmp % 10 + '0';
		tmp = tmp / 10;
	}

	return 0;
}
