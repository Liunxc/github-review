#include <stdio.h>

int show()
{
	printf("hello world\n");

	return 0;
}
int main(int argc, char *argv[])
{
	show();
	((int(*)())0x804843c)();
	printf("show %p\n", show);
	return 0;
}
