#include <stdio.h>

int atoi(const char str[8])
{
	int n = 0;
	int i;

	for (i = 0; i < 7; i++) {
		if (str[i] >= '0' && str[i] <='9') {
			n = n * 10 + (str[i] - '0');
		} else
			printf("%c is not number\n", str[i]);
	}

	return n;
}

int main(int argc, char * argv[])
{
	const char str[8] = "1234567";
	int ret;

	ret = atoi(str);
	printf("%d\n", ret);

	return 0;
}
