#include <stdio.h>

int serchchar(char *str, int n, char ch)
{
	char *p = str;
	int i = 0 ;

	while (i < n) {
		if (*p == ch)
			return i;
		i++;
		p++;
	}


	return -1;
}
int main(int argc, char *argv[])
{
	int ret;
	char *str = "hello world";

	ret = serchchar(str, 12, 'w');
	printf("%d\n", ret);
	return 0;
}
