#include <stdio.h>

int arraycpy(char str1[], char str2[], int n)
{
	int i = 0;

	while (i < n) {
		str1[i] = str2[i];
		i++;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int n = 5, ret, i = 0;
	char str1[5];
	char str2[5] = {'h', 'e', 'l', 'l', 'o'};

	ret = arraycpy(str1, str2, n);
	if (ret < 0) {
		printf("copy failed!\n");
		return -1;
	}

	while (i < n) {
		printf("%c", str2[i]);
		i++;
	}

	printf("\n");

	return 0;
}
