#include <stdio.h>

#define	STACK_SIZE 512
#define	CHILD_SIZE 512

int strreverse(const char * parent, char * child)
{
	char stack[STACK_SIZE];
	const char *src = parent;
	int sp = 0;
	char *p = child;

	while (*src) {
		stack[sp] = *src;
		sp++;
		src++;
	}

	while (sp > 0) {
		sp--;
		*p = stack[sp];
		p++;
	}

	*p = '\0';

	return 0;
}

int main(int argc, char * argv[])
{
	const char * parent = "hello world";
	char child[CHILD_SIZE] = {};

	printf("parent: %s\n", parent);
	strreverse(parent, child);
	printf("child: %s\n", child);

	return 0;
}
