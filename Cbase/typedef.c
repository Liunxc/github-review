#include <stdio.h>

#define SECOND_ONE_YEAR(year, second) do {     \
	int leap;                                  \
                                               \
	if (year % 4 == 0) {                       \
		if (year % 100 == 0) {                 \
			if (year % 400 == 0) {             \
				leap = 1;                      \
			} else {                           \
				leap = 0;                      \
			}                                  \
		} else {                               \
			leap = 1;                          \
		}                                      \
	} else {                                   \
		leap = 0;                              \
	}                                          \
                                               \
	if (leap == 1) {                           \
		second = 366 * 24 * 60 * 60;           \
	} else {                                   \
		second = 365 * 24 * 60 * 60;           \
	}                                          \
											   \
} while(0)


int main(int argc, char *argv[])
{
	int year = 2000;
	unsigned long second;

	SECOND_ONE_YEAR(year, second);

	printf("%d the year is %ld second\n", year, second);

	return 0;
}

