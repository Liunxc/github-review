#include <stdio.h>
#include "two_link_list.h"

int main(int argc, char * argv[])
{
	struct link_node * head;
	int ret;

	srandom(time(NULL));
	head = createLink(3);
	showLink(head);
	insertNode(head, 34);
	showLink(head);
	ret = deleteNode(head, 34);
	if (ret == 0){
		printf("the node does not exsit!\n");
	}

	showLink(head);

	return 0;
}
