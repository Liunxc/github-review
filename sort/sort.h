#ifndef SORT_H_
#define SORT_H_

/*************************sort infomation*******************************************/
#define SWAP(a, b) do {\
	(a) = (a) + (b);	\
	(b) = (a) - (b);	\
	(a) = (a) - (b);	\
} while (0)

#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))
typedef void (*fp)(int array[], int size);

/*************************sort function*******************************************/
int createArray(int array[], int n);
int bubbleSort(int array[], int n);
int quickSort(int array[], int n);
int insertSort(int array[], int n);
int stringinsert(int array[], int n);
int merge(int array[], int array1[], int size1, int array2[], int size2);
int mergeSort(int array[], int n);
int binserch(int array[], int n);
int showSort(int array[], int n);
#endif

