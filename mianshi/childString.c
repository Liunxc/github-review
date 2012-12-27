#include <stdio.h>

int childString(char *str)
{
	int maxlen = 0, i = 0;
	char *p1, *p2, *pre;
	char *p = p1 = str;

	while (*p) {
		pre = p;
		p++;

		if (*p != *pre) {
			i = p - p1;

			if (maxlen < i) {
				p2 = p1;
				maxlen = i;
				i = 0;
			}

			p1 = p;
		}
	}

	return maxlen;
}

int main(int argc, char *argv[])
{
	char *str = "asdfhsfhddddoqewqthrqqqqqqqqqprtgqieriherirrrrrwwwwww";
	int ret;

	ret = childString(str);
	printf("%d\n", ret);

	return 0;
}
