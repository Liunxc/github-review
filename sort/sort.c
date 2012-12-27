#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*************************create array*********************************************************/
int createArray(int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		array[i] = random() % 100;

	return 0;
}

/**************************show array********************************************************/
void showArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%3d ", array[i]);

	printf("\n");
}

/**********************bubble sort************************************************************/
/*bubbleSort 称为冒泡排序
 * 算法简介：
 * 每一次对相邻的两个元素比较
 * 总共比较n - 1 趟
 * 每日趟比较n - 1 - i 次
 * */
int bubbleSort(int array[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (array[j] > array[j + 1])
				SWAP(array[j + 1], array[j]);
		}
	}
	return 0;
}

/*********************quick sort*************************************************************/
/* quickSort 称为快速排序
 * 算法描述为：
 * 数组首位两数据下标置为i，j，然后对下标为i，j的元素进行比较如果前者比后者大，
 * 就交换数据的值，然后就j--，如果没交换就i++；直到i = j；
 * 这样就把数组分为了两段，然后再把这两段用同样的方法进行排序。
 * 最终的回退条件是数组长度为1.
 * */
int quickSort(int array[], int n)
{
	int i = 0;
	int j =  n - 1;
	int flags = 0;
	if (n <= 1)
		return 0;

	while (i < j) {
		if (array[i] > array[j]) {
			SWAP(array[i], array[j]);
			flags = 1 - flags;
		}

		if (flags == 1)
			j--;
		else
			i++;

	}

	quickSort(array, i);
	quickSort(array + i, n - i);

	return 0;
}

/****************************insert sort******************************************************/
/* insertsort 称为插入排序
 * 次算法描述为：
 * 数组元素一部分有序的情况下，即下标为j 以前的数组元素是有顺序的，
 * 用下标为j的数组元素依次与下标为j - 1的数组元素开始比较，直到下标为0，
 * 只要有一个下标为i的数组元素比下标为j的元素大，然后就从i下标处的数组元素开始，
 * 一次向后移动一格。
 * 在把下标为j的数组元素填写到下标为i处。
 * */
int insertSort(int array[], int n)
{
	int i, j;
	int key;

	for (j = 1; j < n; j++) {
		key = array[j];
		i = j - 1;

		while (array[i] > key && i >= 0) {
			array[i + 1] = array[i];
			i--;
		}

		array[i + 1] = key;
	}

	return 0;
}
/******************************merge**********************************************************************/
/* merge function
 * it can make two arrays merge one array.
 * but, the two arrays must be inorder.*/
int merge(int array[], int array1[], int size1, int array2[], int size2)
{
	int i = 0, j = 0, k = 0;
	int len = size1 + size2;
	int tmp[len];

	while (i < size1 && j < size2) {
		if (array1[i] > array2[j]) {
			tmp[k] = array2[j];
			j++;
		} else {
			tmp[k] = array1[i];
			i++;
		}

		k++;
	}

	while (i < size1) {
		tmp[k] = array1[i];
		i++;
		k++;
	}

	while (j < size2) {
		tmp[k] = array2[j];
		j++;
		k++;
	}

	k = 0;
	while (k < len) {
		array[k] = tmp[k];
		k++;
	}

	return 0;
}

/********************************mergeSort*********************************************************************/
/*
 * mergeSot 名称为归并排序
 * 把一个数组分为2个数组，这样依次递归下去
 * 直到数组长度为一时，就结束该函数
 * */
int mergeSort(int array[], int n)
{
	int mide;

	if (n <= 1)
		return 0;

	mide = n / 2;
	mergeSort(array, mide);
	mergeSort(array + mide, n - mide);
	merge(array, array, mide, array + mide, n - mide);

	return 0;
}


