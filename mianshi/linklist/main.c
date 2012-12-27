#include <stdio.h>
#include "link_list.h"

int main(int argc, char * argv[])
{
	struct link_node * head;
	int ret;

	srandom(time(NULL));
	head = createLink(3);
	showLink(head);
	insertNode(head, 34);
	showLink(head);
	invertListout(head);
	showLink(head);

	return 0;
}
