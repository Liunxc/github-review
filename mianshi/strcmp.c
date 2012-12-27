#include <stdio.h>

int _strcmp(const char * str1, const char * str2);

int main(int argc, char * argv[])
{
	const char *str1 = "hello world";
	const char *str2 = "hello world\n";
	int ret;

	ret = _strcmp(str1, str2);
	if (!ret)
		printf("the two strings are equal\n");

	return 0;
}

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 == *str2) {
			str1++;
			str2++;
		} else
			break;
	}

	return *str1 - *str2;
}
