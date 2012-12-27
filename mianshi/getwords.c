#include <stdio.h>

int getwords(const char *str);

int main(int argc, char argv[])
{
	const char * str = "hello world welcom to our world and you are going to be greate persion";
	int ret;

	ret = getwords(str);
	printf("this sentence is %d words.\n", ret);

	return 0;
}

int getwords(const char * str)
{
	int ret = 1;
	const char * src = str;

	if (NULL == src)
		ret = 0;

	while (*src) {
		if (*src == ' ')
			ret++;

		src++;
	}

	return ret;
}
