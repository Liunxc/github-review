#include <stdio.h>

struct link_node
{
	char data;
	struct link_node * next;
};

int checkcircle(struct link_node * head);

int main(int argc, char *argv[])
{
	return 0;
}

int checkcircle(struct link_node * head)
{
	struct link_node * p, *q;

	p = q = head;
	while (p -> next && q->next) {
		p = p->next;
		q = p->next->next;

		if (NULL == (p == q))
			return 0;
		else if (p == q)
			return 1;
	}

	return 0;
}
