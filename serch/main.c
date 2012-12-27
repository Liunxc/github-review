#include <stdio.h>
#include "serch.h"

int main(int argc, char *argv[])
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int ret, key = 10;

	ret = binSerch(array, 10, key);
	if (ret < 0) {
		printf("the array is not include %d nmber!\n", key);
	} else {
		printf("the number`s index is %d.\n", ret);
	}

	return 0;
}
