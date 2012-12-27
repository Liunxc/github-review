#include <stdio.h>

int main(int argc, char *argv[])
{
	char a[4][3][2] = {
		{{'a', 'b'}, {'c', 'd'}, {'e', 'f'}},
		{{'g', 'h'}, {'i', 'j'}, {'k', 'l'}},
		{{'m', 'n'}, {'o', 'p'}, {'q', 'r'}},
		{{'s', 't'}, {'u', 'v'}, {'w', 'x'}},
	};

	char (*pa)[2] = &a[1][0];
	char (*paa)[3][2] = &a[1];

	printf("%c %p\n", *(*(pa + 5) + 1), pa);

	printf("%c %p\n", *(*(*(paa + 1) + 2) + 1), paa);

	return 0;
}
