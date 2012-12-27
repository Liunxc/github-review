#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * getmemory(char *p)
{
	p = (char *)malloc(100);
	printf("p = %p\n", p);
	return p;
}

char *getmemory1(void)
{
	char p[] = "hello world\n";
	return p;
}

void getmemory2(char **p)
{
	*p = (char *)malloc(100);
	printf("*p = %p", *p);
	//strcpy(*p, "hello world\n");
}

int main()
{
	char *str = NULL;
	//char *pp;
	getmemory2(&str);
	printf("str = %p\n", str);
	//printf("pp = %p\n", pp);
	strcpy(str, "hello world\n");
	printf("%s", str);
	free(str);

	return 0;
}
