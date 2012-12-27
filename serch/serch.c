#include "serch.h"
/***************************binSerch***********************************************/
/*****
 * binSerch 称为二分查找
 * 在一个有序数组中查找给定的一个数，如果存在就返回该数值在数组中的下标
 * 方法是：定义low high mid 三个变量，然后用下标为mid 的数与给定的数比较，
 * 如果相等就返回mid
 * 如果不等就更新mid low high
 * *******/
int binSerch(int array[], int n, int key)
{
	int low, high, mid;
	low = 0, high = n - 1;

	while (low <= high && low >= 0) {
		mid = (low + high) / 2;

		if (array[mid] ==  key) {
			return mid;
		} else if (array[mid] > key) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}

/*****************************indexSerch*****************************************/
/**************
 * indexSerch 名称为直接查找（线性查找）
 * 方法：就直接查找就行了。
 * ***********************/
int indexSerch(int array[], int n, int key)
{
	int i;

	for (i = 0; i < n; i++) {
		if (array[i] == key) {
			return i;
		}
	}

	return -1;
}
