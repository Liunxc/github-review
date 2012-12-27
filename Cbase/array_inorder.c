#include <stdio.h>
int array_inorder(int array[], int n)
{
	int i, j;
	int flagh = 0, flagl = 0;

	for (i = 0, j = i + 1; i < n - 1; i++, j++) {
		if (array[i] <= array[j]) {
			flagl++;
		} else {
			flagh++;
		}
	}

	if (flagl == n - 1)
		printf("the array is order and inorder\n");
	else if (flagh == n - 1)
		printf("the array is order and revsrse\n");
	else
		printf("the array is not inorder\n");

	return 0;
}

int main(int argc, char *argv[])
{
	int array[10] = {1, 2, 3, 2, 5, 6, 7, 8, 9, 10};
	array_inorder(array, 10);

	return 0;
}
