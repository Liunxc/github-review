#include <stdio.h>

int atoid(const char *str);
int atoio(const char *str);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("usage %s <give a charactor: 12345>\n", argv[0]);
		return -1;
	}

	const char *str = (const char *)argv[1];
	int num;
	int flag = 0;

	while (*str) {
		if ((*str >= 'a' && *str <= 'f') || (*str <= 'F' && *str >= 'A'))
			flag++;
		str++;
	}

	const char * str2 = argv[1];
	if (flag == 0)
		num = atoid(str2);
	else
		num = atoio(str2);

	printf("%d\n", num);

	return 0;
}

int atoid(const char *str)
{
	const char * p = str;
	int num = 0;

	while (*p) {
		num = num * 10 + *p - '0';
		p++;
	}

	return num;
}

int atoio(const char * str)
{
	int num = 0;
	const char *p = str;

	while (*p) {
		if (*p <= '9' && *p >= '0') {
			num = num * 16 + *p - '0';
			p++;
		} else if (*p >= 'A' && *p <= 'F') {
			num  = num * 16 + *p - 'A' + 10;
			p++;
		} else if (*p >= 'a' && *p <= 'f') {
			num = num * 16 + *p - 'a' + 10;
			p++;
		}
	}

	return num;
}
