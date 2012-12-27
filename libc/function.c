#include "libc.h"

size_t _strlen(const char * str)
{
	int len = 0;
	const char * p = str;

	while (*p) {
		len++;
		p++;
	}

	return len;
}

char *_strcpy(char *dest, const char * src)
{
	char *p = dest;
	while (*src) {
		*p++ =  *src++;
	}

	*p = '\0';

	return dest;
}

int swap(type *a, type *b)
{
	type tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

	return 0;
}

unsigned int do_dup(int a[], int b[], int h[], unsigned int m, unsigned int n)
{
	int i = 0, j = 0, k = 0;

	while (i < m && j < n) {
		if (a[i] <= b[j]) {
			h[k] = a[i];
			i++;
		} else {
			h[k] = b[j];
			j++;
		}

		k++;
	}

	while (i < m) {
		h[k] = a[i];
		i++;
		k++;
	}

	while (j < n) {
		h[k] = b[j];
		j++;
		k++;
	}

	return 0;
}

int is_increase(int array[10])
{
	return 0;
}

int max(int n, ...)
{
	int tmp = n;
	int num = 0;
	unsigned long *p = (unsigned long *)&n;

	while (tmp--) {
		if (*p > mnum) {
			num = *p;
			p++;
		}
	}

	return num;
}
