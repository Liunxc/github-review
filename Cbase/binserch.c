#include <stdio.h>
//在有序数组array中查找x 这个数， n 为数组的长度
int binserch(int x, int array[], int n)
{
	int low = 0;
	int height = n - 1;
	int mid = (low + height) / 2;

	while (low <= height && x != array[mid]) {
		if (array[mid] < x) {
			low = mid + 1;
			mid = (low + height) / 2;
		} else {
			height = mid - 1;
			mid = (low + height) / 2;
		}
	}

	if (x == array[mid])
		return mid;
	else
		return -1;
}

int main(int srgc, char *argv[])
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int ret;

	ret = binserch(5, array, 10);
	printf("%d\n", ret);

	return 0;
}
