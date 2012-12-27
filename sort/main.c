#include <stdio.h>
#include <time.h>
#include "sort.h"

int main(int argc, char *argv[])
{
	srandom(time(NULL));
	int array[10];
	createArray(array, 10);
	showArray(array, 10);
	//bubbleSort(array, 10);
	//showArray(array, 10);
	//quickSort(array, 10);
	//showArray(array, 10);
	//insertSort(array, 10);
	mergeSort(array, 10);
	showArray(array, 10);
	return 0;
}
